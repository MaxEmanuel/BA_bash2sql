OBJ = SimpleBashSQL
CFLAGS=-I/home/maximilian/Downloads/antlr3-master/runtime/Cpp/include 
all: simplebashsql

simplebashsql: theparser thequery.o
	g++ -std=c++11 -g -o $@ $(CFLAGS) -lantlr3c $(OBJ)Parser.cpp $(OBJ)Lexer.cpp thequery.o
	rm thequery.o

theparser: $(OBJ).g
	java org.antlr.Tool $<

thequery.o: thequery.cpp thequery.hpp
	g++ -std=c++11 -g -c -o $@ $(CFLAGS) thequery.cpp

clean: 
	rm -f $(OBJ:=Lexer.cpp) $(OBJ:=Lexer.hpp) $(OBJ:=Parser.cpp) $(OBJ:=Parser.hpp) simplebashsql

.PHONY: clean all
