%{
extern YYSTYPE yylval;
%}

%%
[0-9]+  {yylval = atoi(yytext);
         return ZAHL;}
[  \t]+ ;
.       return(yytext[0]);
