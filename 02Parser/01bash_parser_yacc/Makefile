
all: kleinerParser

kleinerParser: lex.yy.c y.tab.c
	 cc -o $@ lex.yy.c y.tab.c -ll -lm

y.tab.c: bash2sql.y
	yacc -d $^

lex.yy.c: bash2sql.lex
	lex $^
