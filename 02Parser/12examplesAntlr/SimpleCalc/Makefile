#!/bin/bash

all: myprogram

myprogram: 
	export CLASSPATH=~/Downloads/antlr-3.5.2-complete.jar:$CLASSPATH
	java org.antlr.Tool SimpleCalc.g
	gcc -g -o myprogram -I/usr/local/include/ -L/usr/local/lib/ -lantlr3c *Parser.c *Lexer.c

