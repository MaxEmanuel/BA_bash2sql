
all: calc2

calc2: lex.yy.c y.tab.c
	 cc -o calc2 lex.yy.c y.tab.c -ll -lm

y.tab.c: calc.y
	yacc -d $^

lex.yy.c: calc.lex
	lex $^
