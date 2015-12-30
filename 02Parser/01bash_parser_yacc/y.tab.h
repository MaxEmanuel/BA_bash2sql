/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REDIR = 258,
     NUMBER = 259,
     ALNUM = 260,
     WORD = 261,
     OPT = 262,
     FSTDIN = 263,
     PLUS = 264,
     MINUS = 265,
     TIMES = 266,
     DIVIDE = 267,
     POWER = 268,
     OPT_D = 269,
     CAT = 270,
     CUT = 271,
     GREP = 272,
     SORT = 273,
     JOIN = 274,
     PIPE = 275,
     LEFT_PARENTHESIS = 276,
     RIGHT_PARENTHESIS = 277,
     END = 278,
     NEG = 279
   };
#endif
/* Tokens.  */
#define REDIR 258
#define NUMBER 259
#define ALNUM 260
#define WORD 261
#define OPT 262
#define FSTDIN 263
#define PLUS 264
#define MINUS 265
#define TIMES 266
#define DIVIDE 267
#define POWER 268
#define OPT_D 269
#define CAT 270
#define CUT 271
#define GREP 272
#define SORT 273
#define JOIN 274
#define PIPE 275
#define LEFT_PARENTHESIS 276
#define RIGHT_PARENTHESIS 277
#define END 278
#define NEG 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 86 "calc.y"

	long int4;              /* Constant integer value */
	int int2;
	float fp;               /* Constant floating point value */
	char *str;              /* Ptr to constant string (strings are malloc'd) */



/* Line 2068 of yacc.c  */
#line 107 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


