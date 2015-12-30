%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXFIELDS 20

struct myquery{
	char select[80];
	char from[80];
	char where[800];
	char groupby[20];
	char orderby[20];
	char as[20];
	int felder[MAXFIELDS];

	struct myquery *next;
} queries[10];
typedef struct myquery query;

int crtq=0;


int reset(struct myquery* abfrage){
	int i;
	for(i=0; i<20;i++)
		abfrage->felder[i]=i+1;
}

int zugrep(struct myquery* abfrage, char* pattern){
	int i=0; char buffer[3];
	strcat(abfrage-> where, "(");
	while(abfrage->felder[i]!=-1 && i<MAXFIELDS){
		 sprintf(buffer,"$%d",abfrage->felder[i++]);
		 strcat(abfrage->where,buffer);
		 strcat(abfrage->where," like \'\%");
		 strcat(abfrage->where,pattern);
		 strcat(abfrage->where,"\%\' or ");
	}
	
	strcat(abfrage-> where, "false)");
		
}

int ausgeben(struct myquery* e)
{
	int i=0; char buffer[3];
	while(e->felder[i]!=-1 && i<MAXFIELDS){
	   sprintf(buffer,"$%d,",e->felder[i++]);
	   strcat(e->select,buffer);
	}
	return 
	printf("SELECT %s FROM %s WHERE %s GROUP BY %s ORDER BY %s AS %s\n",
		e->select, e->from, e-> where, e->groupby, e->orderby, e->as);

}

int optionZuListe(char* e, int* feld){
        int crtf=0;
        int a,b,ret;
        do{
                e++;
                ret=sscanf(e,"%d-%d",&a,&b);
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

%}

%union {
	long int4;              /* Constant integer value */
	int int2;
	float fp;               /* Constant floating point value */
	char *str;              /* Ptr to constant string (strings are malloc'd) */
};

%type <str> WORD
%type <int4> NUMBER
%type <str> OPT

%token 	REDIR;
%token	NUMBER ALNUM WORD OPT FSTDIN
%token	PLUS	MINUS	TIMES	DIVIDE	POWER
%token  OPT_D	
%token  CAT CUT GREP SORT JOIN 
%token  PIPE
%token	LEFT_PARENTHESIS	RIGHT_PARENTHESIS
%token	END

%left  PIPE
%left	PLUS	MINUS
%left	TIMES	DIVIDE
%left	NEG
%right	POWER


%start Input
%%

Input:
	  /* Empty */
	| Input Line
	;

Line:
	  END
	| Command END			{ /*printf("fertig\n");*/
						ausgeben(&queries[crtq++]); reset(&queries[crtq]);}
	| Command PIPE Line		{ /*printf("pipe\n");*/ }
	| Command REDIR WORD END	{ strcpy(queries[crtq].as,$3);
					ausgeben(&queries[crtq++]);
					reset(&queries[crtq]);}
	;

Command:
	  CAT				
	| CAT WORD			{ reset(&queries[crtq]);
					  strcpy(queries[crtq].from,$2);} 
	| CUT OptionsCut WORD		{ strcpy(queries[crtq].from,$3);}
			
	| CUT OptionsCut	
	| GREP WORD		{ zugrep(&queries[crtq],$2); }
	| GREP WORD WORD	{ strcpy(queries[crtq].from,$3);
					zugrep(&queries[crtq],$2); }
	| SORT OptionsSort 
	;

OptionsSort:
	;

OptionsCut:
	  OptionsCut OptionsCut
	| MINUS WORD  {	char* e;
			for(e=$2; *e!=0; e++){
			  switch(*e){
			    case 'f':
				optionZuListe(e,queries[crtq].felder);
			    break;
			  }
				/*printf("erkannt :%c:voila\n",*e);*/
			}
		}
	;
%%

int yyerror(char *s) {
  printf("%s\n",s);
}

int main() {
  reset(queries);
  yyparse();
}
