grammar SimpleBashSQL;
 
options
{
    language=C;
}
 
tokens
{
    PIPE = '|';
}

@lexer::header
{
/* ein Fix wenn Zustand _empty nicht deklariert*/
#define _empty NULL
}

@header
{
#ifndef MYHEAD
#define MYHEAD
 
 #include <assert.h>
 #include "SimpleBashSQLLexer.h"
 #define MAXFIELDS 5
 #define DELIMIT ','

 typedef struct myquery{
	char select[10], from[30],
	where[200], groupby[5],
	orderby[5], as[20];
	/*numerische Repraesentation der Felder*/
	char felder[MAXFIELDS], groups[MAXFIELDS], orders[MAXFIELDS];
	/*sprechende Namen */
	char *fname[MAXFIELDS];
	/* findet join statt? felder 1, felder2, tabelle1, tabelle2 */
	char join, f1,f2,t2[20];
	/* findet union statt?  */
	char sqlunion,sort,group,nrfields;
	struct myquery *src, *src2;
  } query;


#endif
}

@members
{
	query *lastquery=NULL;
	char tobeprint=1;
/*------------------------------------------------------------------
 * Methoden fuer die SQL-Abfrage
 *------------------------------------------------------------------*/
	/*str_split fuer die lookup der Spaltenbezeichner*/
	char** str_split(char* a_str, const char a_delim)
	{
	    char** result    = 0;
	    size_t count     = 0;
	    char* tmp        = a_str;
	    char* last_comma = 0;
	    char delim[2];
	    delim[0] = a_delim;
	    delim[1] = 0;

	    /* Count how many elements will be extracted. */
	    while (*tmp)
	    {
		if (a_delim == *tmp)
		{
		    count++;
		    last_comma = tmp;
		}
		tmp++;
	    }

	    /* Add space for trailing token. */
	    count += last_comma < (a_str + strlen(a_str) - 1);

	    /* Add space for terminating null string so caller
	       knows where the list of returned strings ends. */
	    count++;

	    result = malloc(sizeof(char*) * count);

	    if (result)
	    {
		size_t idx  = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
		    assert(idx < count);
		    *(result + idx++) = strdup(token);
		    token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	    }

	    return result;
	}
		
	/*nimmt die erste Zeile einer Datei als Spaltenbezeichner
	  gibt Feld mit Strings der Namen zurueck*/
	int lookup(char* filename, char delimit,query *q)
	{
		FILE *f;
		char * line = NULL;
		size_t len = 0;
		ssize_t read;
		char **ptr, **forfree;
		/* beginne mit den neuen Feldern */
		char i=q->nrfields;
		
		f=fopen(filename,"r");
		if(!f)
			return -1;
		if( read = getline(&line, &len, f) == -1 )
			return -1;
		fclose(f);

		ptr=str_split(line,delimit);
		forfree=ptr;
		while(*ptr && i<MAXFIELDS)
			q->fname[i++]=*ptr++;
		
		q->nrfields=i;
		free(forfree);
		return 1;
	}

	/** setzt die Abfrage auf Standardwerte */
	int reset(query* abfrage){
		int i;
		if(!abfrage)
			return -1;

		if(abfrage->src!=NULL){
			/*wenn Felder durch SRC festgelegt sind*/
			for(i=0; i<MAXFIELDS;i++){
				abfrage->felder[i]=abfrage->src->felder[i];
				abfrage->orders[i]=abfrage->src->felder[i];
				abfrage->groups[i]=abfrage->src->felder[i];
				if(abfrage->src->felder[i]>=0)
					abfrage->fname[i]=
						abfrage->src->fname[abfrage->src->felder[i]];
			}
			abfrage->nrfields=abfrage->src->nrfields;
		}else{
			/*sonst*/
			abfrage->nrfields=0;
			for(i=0; i<MAXFIELDS;i++){
				abfrage->felder[i]=i;
				abfrage->orders[i]=i;
				abfrage->groups[i]=i;
				abfrage->fname[i]=(char*)malloc(4*sizeof(char));
				sprintf(abfrage->fname[i],"$\%d",i);
			}
		}
		strcpy(abfrage->select,"");
		strcpy(abfrage->from,"");
		strcpy(abfrage->where,"");
		strcpy(abfrage->groupby,"");
		strcpy(abfrage->orderby,"");
		strcpy(abfrage->as,"");
		abfrage->join=0;
		abfrage->f1=1;
		abfrage->f2=1;
		abfrage->sqlunion=0;
		abfrage->sort=0;
		abfrage->group=0;
	}
	
	/*gibt den Speicher wieder frei*/
	int deletequeries(query* q)
	{
		if(q->src)
			deletequeries(q->src);
		if(q->src2)
			deletequeries(q->src);
		free(q);
	}

	/** gibt die Abfrage in SQL aus */
	int ausgeben(query* e)
	{
		int i=0;
		if (e==NULL)
			return -1;

		if(strlen(e->as))
			printf("WITH \%s AS (",e->as);

		/*##### SELECT #####*/
		printf("SELECT \%s",e->select);
		/* select relevanten felder, wenn kein * in select */
		if(!strchr(e->select,'*')){
			while(e->felder[i+1]!=-1 && i+1<MAXFIELDS)
				printf("\%s,",e->fname[e->felder[i++]]);
			printf("\%s ",e->fname[e->felder[i]]);
		}
		
		/*##### FROM #####*/
		printf("FROM \%s ",e->from);
		/* bei Join und union: Quelle2 abfragen */
		if(e->src2!=NULL){
			printf("(\n\t");
			ausgeben(e->src2);
			printf(") ");
		}
		/*findet ein join oder eine union statt?*/
		if(e->join)
			printf("AS a JOIN \%s ",e->t2);
		if(e->sqlunion)
			printf("UNION ");
		
		/* rekursiv alle Unterabfragen */
		if(e->src!=NULL){
			printf("(\n\t");
			ausgeben(e->src);
			printf(") ");
		}
		printf("AS b");
		
		/*nur bei join, Joinbedingung*/
		if(e->join)
			printf(" on a.$\%d = b.$\%d",e->f1,e->f2);

		/*##### REST, bei Bedarf #####*/
		if(strlen(e->where)!=0)
			printf(" WHERE \%s",
				e-> where);
		
		if(e->group){
			i=0;
			printf(" GROUP BY \%s",e->groupby);
			while(e->groups[i+1]!=-1 && i+1<MAXFIELDS)
				printf("$\%d,",e->groups[i++]);
			printf("$\%d ",e->groups[i]);
		}

		if(e->sort){
			i=0;
			printf(" ORDER BY ");
			while(e->orders[i+1]!=-1 && i+1<MAXFIELDS)
				printf("$\%d,",e->orders[i++]);
			printf("$\%d \%s",e->orders[i],e->orderby);
		}
		
		if(strlen(e->as))
			printf(")");
		
		printf("\n");
		
		return 1;
	}
 
/*------------------------------------------------------------------
 * Methoden zu den Bash-Kommandos
 *------------------------------------------------------------------*/
	/* vereint zwei Tabellen */
	query *makeunion(char* eingabe, query* q)
	{
		query* neu;
		/* erstes Argument? => gleich rein */
		if(strlen(q->from)==0 && q->src==NULL){
			strcpy(q->from,eingabe);
			lookup(eingabe,DELIMIT,q);
			return q;
		}
		/* sonst: mache union*/
		neu=(query*)malloc(sizeof(query));
		neu->src=q;
		reset(neu);
		neu->sqlunion=1;
		strcpy(neu->from,eingabe);
		return neu;
	}
	/* vereint zwei Tabellen, SQL-Anfrage als Eingabe */
	query *makeunion_query(query* eingabe, query* q)
	{
		query* neu;
		/* erstes Argument? => gleich rein */
		if(strlen(q->from)==0 && q->src==NULL){
			q->src=eingabe;
			return q;
		}
		/* sonst: mache union*/
		neu=(query*)malloc(sizeof(query));
		neu->src=q;
		reset(neu);
		neu->sqlunion=1;
		neu->src2=eingabe;
		return neu;
	}

	/** zu grep: parse pattern fuer grep*/
	int zugrep(char* pattern, query* abfrage )
	{
		int i=0; char buffer[3];
		strcat(abfrage-> where, "(");
		while(abfrage->felder[i]!=-1 && i<MAXFIELDS){
			 sprintf(buffer,"$\%d",abfrage->felder[i++]);
			 strcat(abfrage->where,buffer);
			 strcat(abfrage->where," like \'\%");
			 strcat(abfrage->where,pattern);
			 strcat(abfrage->where,"\%\' or ");
		}
		strcat(abfrage-> where, "false)");
	}
	
	/** parst eine in Optionen angegebene Liste wie d1,2,4-6
		in ein Feld zu 1,2,4,5,6 */
	int parseListe(char*e, char* feld)
	{
		int crtf=0;
		int a,b,ret;
		do{
			e++;
			ret=sscanf(e,"\%d-\%d",&a,&b);
			/* felder beginnen bei 0*/
			a--; b--;
			if(ret==0)/*error*/
				return -1;
			/* von - bis  */
			else if(ret==2){
				for(;a<=b;a++)
				   feld[crtf++]=feld[a];
			}/*einzelne Auswahl */else{
				feld[crtf++]=feld[a];
			}
			while((*e>='0' && *e<='9')||*e=='-')
				e++;
		}while(*e==',');
		feld[crtf]=-1;
		return 1;
	}

	/* zu sort */
	int optssort(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'k':
				parseListe(e,q->orders);
				break;
			case 'u':
				strcat(q->select,"distinct");
				break;
			case 'r':
				strcat(q->orderby,"desc");
				break;
			}
		}
		return 1;
	}
	
	/* zu cut */
	int optscut(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'f':
				parseListe(e,q->felder);
				break;
			}
		}
		return 1;
	}

	/* zu grep */
	int optsgrep(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'v':
				strcat(q->where, "NOT ");
				break;
			case 'c':
				strcpy(q->select, "count(*)");
				break;
			}
		}
		return 1;
	}

	/* zu join */
	int optsjoin(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'f':
				parseListe(e,q->felder);
				break;
			}
		}
		return 1;
	}

	/* zu uniq */
	int optsuniq(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'c':
				strcat(q->select,"count(*)");
				break;
			}
		}
		return 1;
	}

	/* zu cut */
	int optswc(char* e, query* q){
		/*bis Ende erreicht*/
		while(*++e!=0){
			switch (*e){
			case 'l':
				break;
			}
		}
		return 1;
	}

/*------------------------------------------------------------------
 * Main
 *------------------------------------------------------------------*/
	int main(int argc, char * argv[])
 	{
		pANTLR3_INPUT_STREAM           input;
		pSimpleBashSQLLexer               lex;
		pANTLR3_COMMON_TOKEN_STREAM    tokens;
		pSimpleBashSQLParser              parser;
		
		if(argc!=2){
			printf("\%s: fehlender Operand\n",argv[0]);
			return 1;
		}
		
		input = antlr3FileStreamNew ((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);
		lex    = SimpleBashSQLLexerNew                (input);
		tokens = antlr3CommonTokenStreamSourceNew  (ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
		parser = SimpleBashSQLParserNew               (tokens);

		parser  ->file(parser);

		// Must manually clean up
		//
		parser ->free(parser);
		tokens ->free(tokens);
		lex    ->free(lex);
		input  ->close(input);

		return 0;
	}
 
}
 
/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/

/* BASH-Grammar */
file: newline*;

newline: ('\n')* simple_list ('\n' | ';' | '&')
	| comment {printf("\%s\n",$comment.text->chars);};

comment: '#' (NUMBER)* (ALCHAR)* (WORD)* ('\n');

simple_list 
@init{
lastquery=NULL;
}
	: ('!')? pipeline_cmd (('&&' | '||') pipeline_cmd)*;

pipeline_cmd	: c1=command
			{ 
			if(tobeprint && !lastquery && $c1.text->chars)
				printf("\%s",$c1.text->chars);
			}
		(PIPE c2=command
			{ 
			if(tobeprint && !lastquery)
		  		printf(" | \%s",$c2.text->chars);
			}
		)*
		{
		if(lastquery)
			ausgeben(lastquery);
		printf("\n");
		tobeprint=1;
		}
	;

command: cmd (to_redir | other_redir)* | shell_cmd (redirection)*;
subshell: '(' compound_list ')';

compound_list: simple_list ( ('\n' | ';' | '&') ('\n')* simple_list)*; 

redirection: to_redir | from_redir | other_redir ;

to_redir: ('>'|'>>') WORD {
		if(lastquery)
			strcpy(lastquery->as,$WORD.text->chars);
	};

from_redir returns[char* fname]
		: ('<'|'<<'|'<<<') WORD {fname=$WORD.text->chars;}
		| '<' subshell {fname=NULL;};

other_redir: 
                   NUMBER '>' WORD
                |  NUMBER '<' WORD
                |  NUMBER '>>' WORD
                |  NUMBER '<<' WORD
                |  '<&' NUMBER
                |  NUMBER '<&' NUMBER
                |  '>&' NUMBER
                |  NUMBER '>&' NUMBER
                |  '<&' WORD
                |  NUMBER '<&' WORD
                |  '>&' WORD
                |  NUMBER '>&' WORD
                |  '<<-' WORD
                |  NUMBER '<<-' WORD
                |  '>&' '-'
                |  NUMBER '>&' '-'
                |  '<&' '-'
                |  NUMBER '<&' '-'
                |  '&>' WORD
                |  NUMBER '<>' WORD
                |  '<>' WORD
                |  '>|' WORD
                |  NUMBER '>|' WORD
;

shell_cmd: 	for_command
                  |  case_command
                  |  'while' compound_list 'do' compound_list 'done'
                  |  'until' compound_list 'do' compound_list 'done'
                  |  if_command
                  |  subshell
                  |  group_command
                  |  function_def;

for_command:  for_header 
	{printf("\%s",$for_header.text->chars);}
	compound_list ('done' | '}' )
	{printf("done\n");tobeprint=0;}
;
for_header:  'for' WORD 'in' WORD* ALCHAR* ('\n'|';') ('do' | '{'); 

if_command: 'if' compound_list 'then' compound_list ('elif' compound_list)* 'else' compound_list 'fi';

group_command : '{' compound_list '}';

function_def :  ('function')* WORD '(' ')' ('\n' | ';')  group_command
		;
case_command:  'case' WORD ('\n' | ';') 'in' ('\n' | ';') case_clause* 'esac';

case_clause: pattern ')' compound_list ';;';

/* Regeln um Kommandos in SQL zu parsen */
cmd returns [query *r]
@init{
	/* neue Query r, vorherige Abfrage als FROM-Tabelle
		NULL, wenn erstes Kommando */
	char tmp=0; //zaehlt args
	r=(query*) malloc(sizeof(query));
	r->src=lastquery;
	reset(r);
}
@after{
	lastquery=r;
}
	:
	  'cut' 	( OPTS
	  			{ optscut($OPTS.text->chars,r); }
			| WORD
				{ r=makeunion($WORD.text->chars,r); }
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ' )+

	| 'cat' 	( OPTS
			| WORD 
				{ r=makeunion($WORD.text->chars,r); }
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ')*

	| 'grep' 	( o1=OPTS { optsgrep($o1.text->chars,r); } )*
			p=WORD	  { zugrep($p.text->chars,r); }
			( o2=OPTS { optsgrep($o2.text->chars,r);   } 
			| f=WORD  { r=makeunion($f.text->chars,r); }
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ' )*

	| 'sort'	( OPTS { optssort($OPTS.text->chars,r);}
			| WORD { r=makeunion($WORD.text->chars,r);}
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ' )* {r->sort=1;}
	| 'join' (('-1' n1=NUMBER	{r->f1=atoi($n1.text->chars);} )
		| ('-2' n2=NUMBER	{r->f2=atoi($n2.text->chars);} )
		| OPTS
		| WORD	{	if(tmp++==0) /* erstes Argument*/
					strcpy(r->from,$WORD.text->chars);
				else
					strcpy(r->t2,$WORD.text->chars);
				}
		| '- '	{	if (tmp++==0){ /*erstes Arg? => swap*/
					r->src2=r->src; r->src=NULL;
				}
			}
		| from_redir
			{/* fname!=NULL, wenn Dateiname */
			if ($from_redir.fname)
				r=makeunion($from_redir.fname,r);
			else /* sonst subshell */
				r=makeunion_query(lastquery,r);
			}
		)+ {r->join=1;}
	| 'uniq'	( OPTS
	  			{ optsuniq($OPTS.text->chars,r); }
			| WORD
				{ r=makeunion($WORD.text->chars,r); }
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ' )*
			{r->group=1;}
	| 'wc -l'	( OPTS
	  			{ optswc($OPTS.text->chars,r); }
			| WORD
				{ r=makeunion($WORD.text->chars,r); }
			| from_redir
				{/* fname!=NULL, wenn Dateiname */
				if ($from_redir.fname)
					r=makeunion($from_redir.fname,r);
				else /* sonst subshell */
					r=makeunion_query(lastquery,r);
				}
			| '- ' )*
			{strcpy(r->select,"count(*) ");}
	| 'awk' OPTS* '\'' awkbody[r] '\'' OPTS*
	| words {
			if(lastquery!=NULL)
				ausgeben(lastquery);
			r=NULL;
	}
	;

words: ALCHAR* WORD*;

assignment: (ALCHAR|WORD)'='(ALCHAR|WORD);

word	: '"' ALCHAR* '"'
	| '\'' ALCHAR* '\''
;

awkbody[query* r]: (pattern 
			{strcat(r->where, $pattern.text->chars);}
		)? 
		'{' ('print' NUMBER* (',' NUMBER)*)* WORD* NUMBER*
		'}'
	;
 
pattern: (WORD|NUMBER) ('<'|'>'|'=')('=')? (WORD|NUMBER)
	(('&&' | '||') 
	(WORD|NUMBER) ('<'|'>'|'=')('=')? (WORD|NUMBER)
	)*
	;


/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/

OPTS		: ('-'|'+') (LETTER|DIGIT|'-')+
		;

NUMBER		: (DIGIT)+
      		;

WORD		: (LETTER|DIGIT)+;

ALCHAR		: (LETTER|NUMBER|SONDER)+;

WHITESPACE  	: ( '\t' | ' ' | '\r' | '\u000C' | '\\' '\n' | '"')+
              	{
                	 $channel = HIDDEN;
              	}
            	;

fragment
DIGIT       	: '0'..'9';

fragment
LETTER		: ('A'..'Z'|'a'..'z'|'.'|'_'|','|'\|' | '\;'|'$');

fragment
SONDER		: ('{' | '}' | '%' | '\'' | '`' | '-' | '=' | '/' | '!' );

