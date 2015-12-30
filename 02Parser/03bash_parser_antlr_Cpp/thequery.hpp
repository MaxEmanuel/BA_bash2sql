#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define DELIMIT ','
#define MAXFIELDS 9

class TheQuery;

/* references for a table, the used kinds of tables*/
class Tabref
{
  public:
	Tabref(std::string);
	Tabref(TheQuery*);
	void print();

  private:
	std::string tablename;
	TheQuery* srcquery;
};

/* container for Expressions*/
class ExprList
{
  public:
	ExprList();
	~ExprList();
	void add(std::string);
	void add(std::vector<int>);
	void add(std::vector<std::string>);
	void replace_dollars(std::vector<std::string>);

  protected:
	std::vector<std::string>felder;
};

class Groupby: public ExprList
{
  public:
	void print();
};

class Orderby: public ExprList
{
  public:
  	Orderby();
	void print();
	void setDesc();
  private:
  	bool desc;
};

/*where conditions, concatenated using AND*/
class Where
{
  public:                
	Where();          
	~Where();
	void add(std::string);
	void print();
	void replace_dollars(std::vector<std::string>);
  private:               
	/* conditions for the where-stm, linked with and  */
	std::vector<std::string> felder;
};

/* container for select statements*/
class Select
{
  public:                
	Select();          
	~Select();         
	void print();
	void print(std::string);

	void addSelect(std::vector<int>);
	void addSelect(std::string);
	void deleteSelect(int);
	void setDistinct();
	void replace_dollars(std::vector<std::string>);

	int getColumnsCount();
	std::vector<std::string> getColumns();
	std::string getColumn(int);
  private:               
	std::vector<std::string> felder;
	std::vector<int> fnr;
	bool distinct;
};

/*a full select stm*/
class Subselect
{
  public:                
	Subselect();          
	Subselect(std::string);
	Subselect(TheQuery*);
	~Subselect();   

	void print();
	void print(int);
	void addSelect(std::vector<int>);
	void addSelect(std::string);
	void deleteSelect(int);
	void addTable(std::string);
	void addTable(TheQuery*);
	void addCondition(std::string);
	void addGroup(std::vector<int>);
	void addOrder(std::vector<int>);
	void addGroup(std::vector<std::string>);
	void addOrder(std::vector<std::string>);
	void setDesc();
	void setDistinct();
	
	bool notable();
	void replace_dollars(std::vector<std::string>);
	
	int getColumnsCount();
	std::vector<std::string> getColumns();
	std::string getColumn(int);

  private:               
	Select select;
	std::vector<Tabref*> from;
	Where where;
	Groupby groupby; 
	Orderby orderby;
};

/*the fullselect stm, also using union (or except...) */
class TheQuery
{
  public:                
	TheQuery();
	TheQuery(TheQuery*); 
	TheQuery(std::string); 
	~TheQuery();
	void makeUnion(std::string);
	void makeUnion(TheQuery*);
	void makeCross(std::string);
	void makeCross(TheQuery*);
	void makeJoin();
	void addSelect(std::vector<int>);
	void addSelect(std::string);
	void deleteSelect(int);
	/*add table should be makeCross (cross join)*/
	void addCondition(std::string);
	void addGroup(std::vector<int>);
	void addOrder(std::vector<int>);
	void addGroup(std::vector<std::string>);
	void addOrder(std::vector<std::string>);
	void setDistinct();
	void setDesc();

	int getColumnsCount();
	std::vector<std::string> getColumns();
	std::string getColumn(int);
	
	std::vector<std::string> lookup(std::string, char);
	std::vector<std::string> str_split(char*, const char);
	void getnamesfromfile(std::string, char);

	void print();
  private:
	/* when union more queries */
	std::vector<Subselect*> queries;
	std::vector<std::string> fieldnames;
};

