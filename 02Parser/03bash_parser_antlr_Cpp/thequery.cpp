#include "thequery.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*replaces each appearance of oldStr with newStr in str*/
void replace_inline(std::string& str, const std::string& oldStr, const std::string& newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
    str.replace(pos, oldStr.length(), newStr);
    pos += newStr.length();
  }
}

Tabref::Tabref(string name)
{
	tablename=name;
	srcquery=NULL;
}

Tabref::Tabref(TheQuery* mysrc)
{
	tablename;
	srcquery=mysrc;
}

void Tabref::print()
{
	if(!srcquery)
		std::cout << tablename;

	if(srcquery){
		std::cout << "(";
		srcquery->print();
		std::cout << ")";
	}
}

ExprList::ExprList()
{
}

ExprList::~ExprList()
{
}

void ExprList::add(std::string value)
{
	felder.push_back(value);
}


void ExprList::add(std::vector<int> values)
{
	/*copies values into felder*/
	for (std::vector<int>::iterator it = values.begin();
		it!=values.end(); it++){
		std::stringstream stmp;
		stmp << "$" << *it;
		felder.push_back(stmp.str());
	}
}

void ExprList::add(std::vector<string> values)
{
	/*copies values into felder*/
	for (std::vector<string>::iterator it = values.begin();
		it!=values.end(); it++){
		felder.push_back(*it);
	}
}

void ExprList::replace_dollars(std::vector<std::string> fieldnames)
{
	/*nothing to do?*/
	if(fieldnames.size()<=0)
		return;
	/*for every field, look for $1, $2, ...*/
	for(int i=0; i<felder.size(); i++)
		for(int j=fieldnames.size()-1; j>=0; j--)
			replace_inline(felder[i],
				"$"+std::to_string(j+1),fieldnames[j]);
}

Orderby::Orderby()
{
	desc=false;
}

void Orderby::setDesc(){
	desc=true;
}

void Orderby::print()
{
	std::vector<std::string>::iterator it = felder.begin();
	/*begin with first, so at the end no comma will appear*/
	if(it!=felder.end())
		std::cout << " ORDER BY " << *it++;
	if(desc)
		std::cout << "DESC " << *it++;

	while(it != felder.end()){
		std::cout << "," << *it++;
		if(desc)
			std::cout << "DESC " << *it++;
	}
}

void Groupby::print()
{
	std::vector<std::string>::iterator it = felder.begin();
	/*begin with first, so at the end no comma will appear*/
	if(it!=felder.end())
		std::cout << " GROUP BY " << *it++;
	while(it != felder.end())
		std::cout << "," << *it++;
}

Where::Where()
{
}

Where::~Where()
{
}

void Where::add(std::string name)
{
	felder.push_back(name);
}

void Where::replace_dollars(std::vector<std::string> fieldnames)
{
	/*nothing to do?*/
	if(fieldnames.size()<=0)
		return;
	/*for every fields for every name,
	start replacing with the highest to $1, so $10 comes before $1*/
	for(int i=0; i<felder.size(); i++)
		for(int j=fieldnames.size()-1; j>=0; j--)
			replace_inline(felder[i],
				"$"+std::to_string(j+1),fieldnames[j]);
}

void Where::print()
{
	if(felder.size()>0)
		std::cout << " WHERE (" << felder[0];
	/* link with AND*/
	for(int i=1; i<felder.size(); i++)
		std::cout << ") AND (" << felder[i];
	if(felder.size()>0)
		std:cout << ") ";
}

Select::Select()
{
	distinct=false;
	felder.clear();
}

Select::~Select()
{
}

void Select::addSelect(std::vector<int> feldnr)
{
	fnr=feldnr;
	/*copies values into felder*/
	for (std::vector<int>::iterator it = fnr.begin();
		it!=fnr.end(); it++){
		std::stringstream stmp;
		stmp << "$" << *it;
		felder.push_back(stmp.str());
	}
}

void Select::addSelect(std::string name)
{
	felder.push_back(name);
}

/* deletes a certain field, specified by nr, starting with 1  */
void Select::deleteSelect(int nr)
{
	if(felder.size()>=nr)
		felder.erase(felder.begin()+nr-1);
}

void Select::setDistinct()
{
	distinct=true;
}

int Select::getColumnsCount()
{
	if(felder.size()>0)
		return felder.size();
	else
		return MAXFIELDS;
}


/**replaces the dollar values in a select
	$1 is for the first column name, so start with $1*/
void Select::replace_dollars(std::vector<std::string> fieldnames)
{
	/*nothing to do?*/
	if(fieldnames.size()<=0)
		return;
	/*for every fields for every name, start replace with $1*/
	for(int i=0; i<felder.size(); i++)
		for(int j=fieldnames.size()-1; j>=0; j--)
			replace_inline(felder[i],
				"$"+std::to_string(j+1),fieldnames[j]);
}

std::vector<std::string> Select::getColumns()
{
	return felder;
}

/** return Column starting by 1 so c in (1,...,n) */
std::string Select::getColumn(int c)
{
	if (felder.size()<c)
		return "*";
	return felder.at(c-1);
}

void Select::print()
{
	std::cout << "SELECT ";
	if(distinct==true)
		std::cout << "DISTINCT ";
	std::vector<string>::iterator it = felder.begin();
	/*begin print select-stm with first, at the end no comma will appear*/
	if(it!=felder.end())
		std::cout << *it++;
	/*if no field selected, select "*" */
	else
		std::cout << "*";
		
	while(it != felder.end()){
		std::cout << ',' << *it++;
	}
}
/*print it, but use the tablename before*/
void Select::print(std::string name)
{
	std::cout << "SELECT ";
	if(distinct==true)
		std::cout << "DISTINCT ";
	std::vector<string>::iterator it = felder.begin();
	/*begin print select-stm with first, at the end no comma will appear*/
	if(it!=felder.end())
		std::cout << name << "." <<*it++;
	/*if no field selected, select "*" */
	else
		std::cout << name << ".*";
		
	while(it != felder.end()){
		std::cout << ','<< name << "."  << *it++;
	}
}

Subselect::Subselect()
{
	from.clear();
}

Subselect::Subselect(string src)
{
	from.push_back(new Tabref(src));
}

Subselect::Subselect(TheQuery* src)
{
	from.push_back(new Tabref(src));
}

void Subselect::addSelect(std::vector<int> feldnr)
{
	select.addSelect(feldnr);

}

void Subselect::addSelect(std::string name)
{
	select.addSelect(name);

}

void Subselect::deleteSelect(int nr)
{
	select.deleteSelect(nr);

}

void Subselect::addTable(std::string name)
{
	from.push_back(new Tabref(name));
}

void Subselect::addTable(TheQuery* src)
{
	from.push_back(new Tabref(src));
}

void Subselect::addCondition(std::string name)
{
	where.add(name);
}

void Subselect::addGroup(std::vector<int> groups)
{
	groupby.add(groups);
}

void Subselect::addOrder(std::vector<int> orders)
{
	orderby.add(orders);
}
void Subselect::addGroup(std::vector<string> groups)
{
	groupby.add(groups);
}

void Subselect::addOrder(std::vector<string> orders)
{
	orderby.add(orders);
}

/*is table empty?*/
bool Subselect::notable()
{
	return from.size()==0;
}

int Subselect::getColumnsCount()
{
	return select.getColumnsCount();
}

void Subselect::setDistinct()
{
	select.setDistinct();
}

void Subselect::setDesc()
{
	orderby.setDesc();
}

void Subselect::replace_dollars(std::vector<std::string> fieldnames)
{
	select.replace_dollars(fieldnames);
	where.replace_dollars(fieldnames);
	groupby.replace_dollars(fieldnames);
	orderby.replace_dollars(fieldnames);
}

std::vector<std::string> Subselect::getColumns()
{
	return select.getColumns();
}

std::string Subselect::getColumn(int c)
{
	return select.getColumn(c);
}

void Subselect::print()
{
	select.print();

	int i;
	std::cout << " FROM ";
	if(0<from.size())
		from[0]->print();
	for(i=1; i<from.size(); i++){
		std::cout << " as t" << i << ", ";
		from[i]->print();
	}
	std::cout << " as t" << i << " ";

	where.print();
	groupby.print();
	orderby.print();
}
/** print with an extra identifier*/
void Subselect::print(int uid)
{
	select.print();

	int i;
	std::cout << " FROM ";
	if(0<from.size())
		from[0]->print();
	for(i=1; i<from.size(); i++){
		std::cout << " as t" << i << "union" << uid << ", ";
		from[i]->print();
	}
	std::cout << " as t" << i << "union" << uid << " ";

	where.print();
	groupby.print();
	orderby.print();
}
TheQuery::TheQuery()
{
	queries.push_back(new Subselect());
}

TheQuery::TheQuery(TheQuery* src)
{
	queries.push_back(new Subselect());

	if(src!=NULL)
		makeUnion(src);
}

TheQuery::TheQuery(string src)
{
	queries.push_back(new Subselect());
	makeUnion(src);
}

TheQuery::~TheQuery()
{

}
/*union more queries*/
void TheQuery::makeUnion(string src)
{
	/* table already defined? */
	if(queries[0]->notable())
		queries[0]->addTable(src);
	else
		queries.push_back(new Subselect(src));

	/*add column names*/
	getnamesfromfile(src,DELIMIT);
}

void TheQuery::makeUnion(TheQuery* src)
{
	if(src==NULL)
		return;
	/* table already defined? */
	if(queries[0]->notable())
		queries[0]->addTable(src);
	else
		queries.push_back(new Subselect(src));
	/*get columnnames from file*/	
	if(fieldnames.size()==0)
		fieldnames=src->getColumns();
}
/* add one more table*/
void TheQuery::makeCross(string src)
{
	queries[0]->addTable(src);
	/*concatenate the current vector of fields with the one from the table
	column names read with lookup
	  only if already names exist*/
	std::vector<std::string> tmp = lookup(src,DELIMIT);
	if(fieldnames.size()<=0)
		fieldnames=tmp;
	else
		fieldnames.insert(fieldnames.end(),
			tmp.begin(), tmp.end());
}

void TheQuery::makeCross(TheQuery* src)
{
	queries[0]->addTable(src);
	/*concatenate the current vector of fields with the one from src
	  only if already names exist*/
	std::vector<std::string> tmp=src->getColumns();
	if(fieldnames.size()<=0)
		fieldnames=src->getColumns();
	else
		fieldnames.insert(fieldnames.end(),
			tmp.begin(), tmp.end());
}

void TheQuery::makeJoin()
{

}

void TheQuery::addSelect(std::vector<int> feldnr)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addSelect(feldnr);
}

void TheQuery::addSelect(std::string name)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addSelect(name);
}

void TheQuery::deleteSelect(int nr)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->deleteSelect(nr);
}

void TheQuery::addCondition(std::string name)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addCondition(name);
}

void TheQuery::addGroup(std::vector<int> groups)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addGroup(groups);
}

void TheQuery::addOrder(std::vector<int> orders)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addOrder(orders);
}

void TheQuery::addGroup(std::vector<string> groups)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addGroup(groups);
}

void TheQuery::addOrder(std::vector<string> orders)
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->addOrder(orders);
}

void TheQuery::setDistinct()
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->setDistinct();
}

void TheQuery::setDesc()
{
	for(int i=0; i<queries.size(); i++)
		queries[i]->setDesc();
}

int TheQuery::getColumnsCount()
{
	if(getColumns().size()<=0)
		return MAXFIELDS;
	return getColumns().size();
}

/** takes a c-string and a delimiting character, returns the list of strings*/
std::vector<std::string> TheQuery::str_split(char* a_str, const char a_delim)
{
    char delim[2];
    std::vector<std::string> r2;
    delim[0] = a_delim;
    delim[1] = 0;
    /* token is the first string detected  */
    char* token = strtok(a_str, delim);
    while (token)
    {
	   r2.push_back(std::string(token));
           token = strtok(0, delim);
    }
    return r2;
}

/** reads the first line of a file and takes it as header, columns separated by delimit, returns a vector of column names
the line should be terminated with the delimiting character */
std::vector<std::string> TheQuery::lookup(std::string filename, char delimit)
{
	FILE *f;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char** ptr;
	std::vector<std::string> tmp;
	f=fopen(filename.c_str(),"r");
	if(!f)
		return std::vector<std::string>();
	if( read = getline(&line, &len, f) ==-1)
		return std::vector<std::string>();
	fclose(f);
	
	tmp=str_split(line,delimit);
	/* header columns terminated with delimiter symbol */
	tmp.pop_back();
	return tmp;
}

void TheQuery::getnamesfromfile(std::string filename, char delimiter)
{
	std::vector<std::string> tmp;
	/*only replace the old one, when a newer exists*/
	if((tmp=lookup(filename, delimiter)).size()>0){
		fieldnames=tmp;
	}
}


/** returns the selected columns 
    all columns of each subselect should be named identically, queries[0].getColumns() == queries[x].getColumns()*/
std::vector<std::string> TheQuery::getColumns()
{
	for(int i; i<queries.size();i++)
		queries[i]->replace_dollars(fieldnames);
	/* if select *, all columns are needed */
	if(queries[0]->getColumns().size()!=0)
		return queries[0]->getColumns();
	else
		return fieldnames;
}
/**returns name of the column c, does not matter if from queries[0] or [1] */
std::string TheQuery::getColumn(int c)
{
	if(queries.size()>0)
		return queries[0]->getColumn(c);
}

void TheQuery::print()
{
	/*only when a query is defined, should always be the case*/
	if(queries.size()>0){
		queries[0]->replace_dollars(fieldnames);
		queries[0]->print();
	}
	/* union all queries */
	for(int i=1; i<queries.size(); i++){
		std::cout << " UNION ";
		queries[i]->replace_dollars(fieldnames);
		/*now all unions must have an unique id*/
		queries[i]->print(i);
	}
}
/*
int main()
{
	std::string s("muh");
	string ss = "exampletable";
	TheQuery* myq = new TheQuery();
	TheQuery* myq2 = new TheQuery();
	std::vector<int> mygroup(1,1);
	myq->makeUnion(ss);
	myq2->makeUnion(ss);
	TheQuery* myq3 = new TheQuery(myq2);
	myq2->addSelect(mygroup);
	myq2->print();
	std::cout <<  std::endl;
	myq3->print();
	std::cout << std::endl;
	myq2->addGroup(mygroup);
	myq2->addOrder(mygroup);
	myq2->addCondition("true");
	myq2->makeCross("table2");
	myq2->print();

	std::cout << endl;
	myq->getColumns();
	std::cout << myq2->getColumn(1) <<endl;
}*/
