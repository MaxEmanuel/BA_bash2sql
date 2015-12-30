%{
#define YYSTYPE double
extern YYSTYPE yylval;
#include "y.tab.h"

#include <stdlib.h>

%}

white		[ \t]+

digit		[0-9]
integer 	{digit}+
exponant	[eE][+-]?{integer}

real		{integer}("."{integer})?{exponant}?

%%

{white} 	{ /* We ignore white characters */ }

{real}		{
		  yylval=atof(yytext);
		  return(NUMBER);
		}

"+"		return(PLUS);
"-"		return(MINUS);

"*"		return(TIMES);
"/"		return(DIVIDE);

"^"		return(POWER);

"("		return(LEFT_PARENTHESIS);
")"		return(RIGHT_PARENTHESIS);

"\n"	return(END);
