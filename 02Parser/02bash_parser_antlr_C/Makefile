
OBJ = SimpleBashSQL

all: simplebashsql

simplebashsql: $(OBJ).g
	java org.antlr.Tool $^
	gcc -g -o $@ -I/usr/local/include/ -L/usr/local/lib/ -lantlr3c $(OBJ)Parser.c $(OBJ)Lexer.c

