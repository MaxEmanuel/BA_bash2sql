%{
#define YYSTYPE double
extern YYSTYPE yylval;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

%}

%token	NUMBER
%token	PLUS	MINUS	TIMES	DIVIDE	POWER
%token	LEFT_PARENTHESIS	RIGHT_PARENTHESIS
%token	END

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
	| Expression END		{ printf("Result: %f\n",$1); }
	;

Expression:
	  NUMBER			{ $$=$1; }
	| Expression PLUS Expression	{ $$=$1+$3; }
	| Expression MINUS Expression	{ $$=$1-$3; }
	| Expression TIMES Expression	{ $$=$1*$3; }
	| Expression DIVIDE Expression	{ $$=$1/$3; }
	| Expression POWER Expression	{ $$=pow($1,$3); }
	| MINUS Expression %prec NEG	{ $$=-$2; }
	| LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS	{ $$=$2; }
	;

%%

int yyerror(char *s) {
  printf("%s\n",s);
}

int main(void) {
  yyparse();
}
