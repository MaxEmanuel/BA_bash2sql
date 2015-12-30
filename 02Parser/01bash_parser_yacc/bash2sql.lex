%{
#include "y.tab.h"
extern YYSTYPE yylval;
#include <stdio.h>
#include <stdlib.h>

%}

white		[ \t]+

digit		[0-9]
integer 	{digit}+
exponant	[eE][+-]?{integer}

real		{integer}("."{integer})?{exponant}?

letter		[a-zA-Z0-9\.\,\|]+

options		-[a-zA-Z0-9\-\,]+\ 
ende		[^\\];
%%

" - "		return FSTDIN;

{white} 	{ /* We ignore white characters */ }

{real}		{
		  yylval.int4=atoi(yytext);
		  return(NUMBER);
		}


">"		return(REDIR);

"|"		return(PIPE);
"cat"		return(CAT);
"cut"		return(CUT);
"grep"		return(GREP);
"sort"		return(SORT);
"join"		return(JOIN);
"d"		return(OPT_D);
"+"		return(PLUS);
"-"		return(MINUS);
"*"		return(TIMES);
"/"		return(DIVIDE);

"^"		return(POWER);

"("		return(LEFT_PARENTHESIS);
")"		return(RIGHT_PARENTHESIS);

"\n"		return(END);


{letter}   	{ 
			yylval.str=strdup(yytext); 
			return WORD;
		}
