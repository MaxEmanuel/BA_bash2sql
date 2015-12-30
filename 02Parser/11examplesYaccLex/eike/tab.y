%{
#include <ctype.h>
#include <stdio.h>
#define YYSTYPE double
%}
%token ZAHL
%left '+' '-' 
%left '*' '/'
%left NEG
%%
Eingabe  : /* leer */
         | Eingabe Zeile;
Zeile    : '\n'
         | Ausdruck '\n'         { printf("\t%.10g\n", $1);};
Ausdruck : ZAHL                  { $$ = $1;               }
         | Ausdruck '+' Ausdruck { $$ = $1 + $3;          }
         | Ausdruck '-' Ausdruck { $$ = $1 - $3;          }
         | Ausdruck '*' Ausdruck { $$ = $1 * $2;          }
         | Ausdruck '/' Ausdruck { $$ = $1 / $2;          }
         | '(' Ausdruck ')'      { $$ = $2;               };
%%
#include "lex.yy.c"
