/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 21 "parser.y"

#include "config.h"

#include "bashtypes.h"
#include "bashansi.h"

#include "filecntl.h"

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif

#if defined (HAVE_LOCALE_H)
#  include <locale.h>
#endif

#include <stdio.h>
#include "chartypes.h"
#include <signal.h>

#include "memalloc.h"

#include "shell.h"
#include "trap.h"
#include "flags.h"
#include "parser.h"
#include "mailcheck.h"
#include "test.h"
#include "builtins/common.h"
#include "builtins/builtext.h"

#if defined (READLINE)
#  include "bashline.h"
#  include <readline/readline.h>
#endif /* READLINE */

#if defined (HISTORY)
#  include "bashhist.h"
#  include <readline/history.h>
#endif /* HISTORY */

#if defined (JOB_CONTROL)
#  include "jobs.h"
#endif /* JOB_CONTROL */

#if defined (ALIAS)
#  include "alias.h"
#endif /* ALIAS */

#if defined (PROMPT_STRING_DECODE)
#  ifndef _MINIX
#    include <sys/param.h>
#  endif
#  include <time.h>
#  include "maxpath.h"
#endif /* PROMPT_STRING_DECODE */

#define RE_READ_TOKEN	-99
#define NO_EXPANSION	-100

#define YYDEBUG 0

#if defined (EXTENDED_GLOB)
extern int extended_glob;
#endif

extern int eof_encountered;
extern int no_line_editing, running_under_emacs;
extern int current_command_number;
extern int sourcelevel;
extern int posixly_correct;
extern int last_command_exit_value;
extern int interrupt_immediately;
extern char *shell_name, *current_host_name;
extern char *dist_version;
extern int patch_level;
extern int dump_translatable_strings, dump_po_strings;
extern sh_builtin_func_t *last_shell_builtin, *this_shell_builtin;
#if defined (BUFFERED_INPUT)
extern int bash_input_fd_changed;
#endif

extern int errno;
/* **************************************************************** */
/*								    */
/*		    "Forward" declarations			    */
/*								    */
/* **************************************************************** */

#ifdef DEBUG
static void debug_parser __P((int));
#endif

static int yy_getc __P((void));
static int yy_ungetc __P((int));

#if defined (READLINE)
static int yy_readline_get __P((void));
static int yy_readline_unget __P((int));
#endif

static int yy_string_get __P((void));
static int yy_string_unget __P((int));
static int yy_stream_get __P((void));
static int yy_stream_unget __P((int));

static int shell_getc __P((int));
static void shell_ungetc __P((int));
static void discard_until __P((int));

#if defined (ALIAS) || defined (DPAREN_ARITHMETIC)
static void push_string __P((char *, int, alias_t *));
static void pop_string __P((void));
static void free_string_list __P((void));
#endif

static char *read_a_line __P((int));

static char *ansiexpand __P((char *, int, int, int *));
static char *mk_msgstr __P((char *, int *));
static char *localeexpand __P((char *, int, int, int, int *));
static int reserved_word_acceptable __P((int));
static int yylex __P((void));
static int alias_expand_token __P((char *));
static int time_command_acceptable __P((void));
static int special_case_tokens __P((char *));
static int read_token __P((int));
static char *parse_matched_pair __P((int, int, int, int *, int));
#if defined (DPAREN_ARITHMETIC) || defined (ARITH_FOR_COMMAND)
static int parse_arith_cmd __P((char **));
#endif
#if defined (COND_COMMAND)
static COND_COM *cond_expr __P((void));
static COND_COM *cond_or __P((void));
static COND_COM *cond_and __P((void));
static COND_COM *cond_term __P((void));
static int cond_skip_newlines __P((void));
static COMMAND *parse_cond_command __P((void));
#endif
static int read_token_word __P((int));
static void discard_parser_constructs __P((int));

static void report_syntax_error __P((char *));
static void handle_eof_input_unit __P((void));
static void prompt_again __P((void));
#if 0
static void reset_readline_prompt __P((void));
#endif
static void print_prompt __P((void));

#if defined (HISTORY)
char *history_delimiting_chars __P((void));
#endif

extern int yyerror __P((const char *));

/* Default prompt strings */
char *primary_prompt = PPROMPT;
char *secondary_prompt = SPROMPT;

/* PROMPT_STRING_POINTER points to one of these, never to an actual string. */
char *ps1_prompt, *ps2_prompt;

/* Handle on the current prompt string.  Indirectly points through
   ps1_ or ps2_prompt. */
char **prompt_string_pointer = (char **)NULL;
char *current_prompt_string;

/* Non-zero means we expand aliases in commands. */
int expand_aliases = 0;

/* If non-zero, the decoded prompt string undergoes parameter and
   variable substitution, command substitution, arithmetic substitution,
   string expansion, process substitution, and quote removal in
   decode_prompt_string. */
int promptvars = 1;

/* The decoded prompt string.  Used if READLINE is not defined or if
   editing is turned off.  Analogous to current_readline_prompt. */
static char *current_decoded_prompt;

/* The number of lines read from input while creating the current command. */
int current_command_line_count;

/* Variables to manage the task of reading here documents, because we need to
   defer the reading until after a complete command has been collected. */
static REDIRECT *redir_stack[10];
int need_here_doc;

/* Where shell input comes from.  History expansion is performed on each
   line when the shell is interactive. */
static char *shell_input_line = (char *)NULL;
static int shell_input_line_index;
static int shell_input_line_size;	/* Amount allocated for shell_input_line. */
static int shell_input_line_len;	/* strlen (shell_input_line) */

/* Either zero or EOF. */
static int shell_input_line_terminator;

/* The line number in a script on which a function definition starts. */
static int function_dstart;

/* The line number in a script on which a function body starts. */
static int function_bstart;

/* The line number in a script at which an arithmetic for command starts. */
static int arith_for_lineno;

static REDIRECTEE redir;


/* Line 268 of yacc.c  */
#line 283 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     ELIF = 261,
     FI = 262,
     CASE = 263,
     ESAC = 264,
     FOR = 265,
     SELECT = 266,
     WHILE = 267,
     UNTIL = 268,
     DO = 269,
     DONE = 270,
     FUNCTION = 271,
     COND_START = 272,
     COND_END = 273,
     COND_ERROR = 274,
     IN = 275,
     BANG = 276,
     TIME = 277,
     TIMEOPT = 278,
     WORD = 279,
     ASSIGNMENT_WORD = 280,
     NUMBER = 281,
     ARITH_CMD = 282,
     ARITH_FOR_EXPRS = 283,
     COND_CMD = 284,
     AND_AND = 285,
     OR_OR = 286,
     GREATER_GREATER = 287,
     LESS_LESS = 288,
     LESS_AND = 289,
     GREATER_AND = 290,
     SEMI_SEMI = 291,
     LESS_LESS_MINUS = 292,
     AND_GREATER = 293,
     LESS_GREATER = 294,
     GREATER_BAR = 295,
     yacc_EOF = 296
   };
#endif
/* Tokens.  */
#define IF 258
#define THEN 259
#define ELSE 260
#define ELIF 261
#define FI 262
#define CASE 263
#define ESAC 264
#define FOR 265
#define SELECT 266
#define WHILE 267
#define UNTIL 268
#define DO 269
#define DONE 270
#define FUNCTION 271
#define COND_START 272
#define COND_END 273
#define COND_ERROR 274
#define IN 275
#define BANG 276
#define TIME 277
#define TIMEOPT 278
#define WORD 279
#define ASSIGNMENT_WORD 280
#define NUMBER 281
#define ARITH_CMD 282
#define ARITH_FOR_EXPRS 283
#define COND_CMD 284
#define AND_AND 285
#define OR_OR 286
#define GREATER_GREATER 287
#define LESS_LESS 288
#define LESS_AND 289
#define GREATER_AND 290
#define SEMI_SEMI 291
#define LESS_LESS_MINUS 292
#define AND_GREATER 293
#define LESS_GREATER 294
#define GREATER_BAR 295
#define yacc_EOF 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 232 "parser.y"

  WORD_DESC *word;		/* the word that we read. */
  int number;			/* the number that we read. */
  WORD_LIST *word_list;
  COMMAND *command;
  REDIRECT *redirect;
  ELEMENT element;
  PATTERN_LIST *pattern;



/* Line 293 of yacc.c  */
#line 413 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 425 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  92
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   582

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      51,    52,     2,     2,     2,    48,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      47,     2,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    45,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    18,    21,
      24,    28,    32,    35,    39,    42,    46,    49,    53,    56,
      60,    63,    67,    70,    74,    77,    81,    84,    88,    91,
      95,    98,   102,   105,   108,   112,   114,   116,   118,   120,
     123,   125,   128,   130,   132,   135,   137,   139,   141,   147,
     153,   155,   157,   159,   161,   163,   165,   167,   174,   181,
     189,   197,   208,   219,   229,   239,   247,   255,   261,   267,
     274,   281,   289,   297,   308,   319,   326,   334,   341,   347,
     354,   359,   361,   364,   368,   374,   382,   389,   393,   395,
     399,   404,   411,   417,   419,   422,   427,   432,   438,   444,
     447,   451,   453,   457,   460,   462,   465,   469,   473,   477,
     482,   487,   492,   497,   502,   504,   506,   508,   510,   511,
     514,   516,   519,   522,   527,   532,   536,   540,   542,   544,
     547,   550,   554,   558,   563,   565,   567
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    84,    43,    -1,    43,    -1,     1,    43,
      -1,    44,    -1,    24,    -1,    55,    24,    -1,    46,    24,
      -1,    47,    24,    -1,    26,    46,    24,    -1,    26,    47,
      24,    -1,    32,    24,    -1,    26,    32,    24,    -1,    33,
      24,    -1,    26,    33,    24,    -1,    34,    26,    -1,    26,
      34,    26,    -1,    35,    26,    -1,    26,    35,    26,    -1,
      34,    24,    -1,    26,    34,    24,    -1,    35,    24,    -1,
      26,    35,    24,    -1,    37,    24,    -1,    26,    37,    24,
      -1,    35,    48,    -1,    26,    35,    48,    -1,    34,    48,
      -1,    26,    34,    48,    -1,    38,    24,    -1,    26,    39,
      24,    -1,    39,    24,    -1,    40,    24,    -1,    26,    40,
      24,    -1,    24,    -1,    25,    -1,    56,    -1,    56,    -1,
      58,    56,    -1,    57,    -1,    59,    57,    -1,    59,    -1,
      61,    -1,    61,    58,    -1,    66,    -1,    62,    -1,    65,
      -1,    12,    79,    14,    79,    15,    -1,    13,    79,    14,
      79,    15,    -1,    64,    -1,    69,    -1,    68,    -1,    70,
      -1,    71,    -1,    72,    -1,    63,    -1,    10,    24,    83,
      14,    79,    15,    -1,    10,    24,    83,    49,    79,    50,
      -1,    10,    24,    42,    83,    14,    79,    15,    -1,    10,
      24,    42,    83,    49,    79,    50,    -1,    10,    24,    83,
      20,    55,    82,    83,    14,    79,    15,    -1,    10,    24,
      83,    20,    55,    82,    83,    49,    79,    50,    -1,    10,
      24,    83,    20,    82,    83,    14,    79,    15,    -1,    10,
      24,    83,    20,    82,    83,    49,    79,    50,    -1,    10,
      28,    82,    83,    14,    79,    15,    -1,    10,    28,    82,
      83,    49,    79,    50,    -1,    10,    28,    14,    79,    15,
      -1,    10,    28,    49,    79,    50,    -1,    11,    24,    83,
      14,    78,    15,    -1,    11,    24,    83,    49,    78,    50,
      -1,    11,    24,    42,    83,    14,    78,    15,    -1,    11,
      24,    42,    83,    49,    78,    50,    -1,    11,    24,    83,
      20,    55,    82,    83,    14,    78,    15,    -1,    11,    24,
      83,    20,    55,    82,    83,    49,    78,    50,    -1,     8,
      24,    83,    20,    83,     9,    -1,     8,    24,    83,    20,
      76,    83,     9,    -1,     8,    24,    83,    20,    74,     9,
      -1,    24,    51,    52,    83,    67,    -1,    16,    24,    51,
      52,    83,    67,    -1,    16,    24,    83,    67,    -1,    61,
      -1,    61,    58,    -1,    51,    79,    52,    -1,     3,    79,
       4,    79,     7,    -1,     3,    79,     4,    79,     5,    79,
       7,    -1,     3,    79,     4,    79,    73,     7,    -1,    49,
      79,    50,    -1,    27,    -1,    17,    29,    18,    -1,     6,
      79,     4,    79,    -1,     6,    79,     4,    79,     5,    79,
      -1,     6,    79,     4,    79,    73,    -1,    75,    -1,    76,
      75,    -1,    83,    77,    52,    79,    -1,    83,    77,    52,
      83,    -1,    83,    51,    77,    52,    79,    -1,    83,    51,
      77,    52,    83,    -1,    75,    36,    -1,    76,    75,    36,
      -1,    24,    -1,    77,    45,    24,    -1,    83,    80,    -1,
      78,    -1,    83,    81,    -1,    81,    43,    83,    -1,    81,
      41,    83,    -1,    81,    42,    83,    -1,    81,    30,    83,
      81,    -1,    81,    31,    83,    81,    -1,    81,    41,    83,
      81,    -1,    81,    42,    83,    81,    -1,    81,    43,    83,
      81,    -1,    86,    -1,    43,    -1,    42,    -1,    44,    -1,
      -1,    83,    43,    -1,    85,    -1,    85,    41,    -1,    85,
      42,    -1,    85,    30,    83,    85,    -1,    85,    31,    83,
      85,    -1,    85,    41,    85,    -1,    85,    42,    85,    -1,
      86,    -1,    87,    -1,    21,    87,    -1,    88,    87,    -1,
      88,    21,    87,    -1,    21,    88,    87,    -1,    87,    45,
      83,    87,    -1,    60,    -1,    22,    -1,    22,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   282,   282,   291,   298,   313,   323,   325,   329,   334,
     339,   344,   349,   354,   359,   365,   371,   376,   381,   386,
     391,   396,   401,   406,   411,   418,   425,   430,   435,   440,
     445,   450,   455,   460,   465,   472,   474,   476,   480,   484,
     495,   497,   501,   503,   505,   521,   525,   527,   529,   531,
     533,   535,   537,   539,   541,   543,   545,   549,   551,   553,
     555,   557,   559,   561,   563,   567,   569,   571,   573,   577,
     581,   585,   589,   593,   597,   603,   605,   607,   611,   614,
     617,   622,   624,   655,   662,   664,   666,   671,   675,   679,
     683,   685,   687,   691,   692,   696,   698,   700,   702,   706,
     707,   711,   713,   722,   730,   731,   737,   738,   745,   749,
     751,   753,   760,   762,   764,   768,   769,   770,   773,   774,
     783,   789,   798,   806,   808,   810,   817,   820,   824,   826,
     831,   836,   841,   849,   851,   855,   857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "ELIF", "FI",
  "CASE", "ESAC", "FOR", "SELECT", "WHILE", "UNTIL", "DO", "DONE",
  "FUNCTION", "COND_START", "COND_END", "COND_ERROR", "IN", "BANG", "TIME",
  "TIMEOPT", "WORD", "ASSIGNMENT_WORD", "NUMBER", "ARITH_CMD",
  "ARITH_FOR_EXPRS", "COND_CMD", "AND_AND", "OR_OR", "GREATER_GREATER",
  "LESS_LESS", "LESS_AND", "GREATER_AND", "SEMI_SEMI", "LESS_LESS_MINUS",
  "AND_GREATER", "LESS_GREATER", "GREATER_BAR", "'&'", "';'", "'\\n'",
  "yacc_EOF", "'|'", "'>'", "'<'", "'-'", "'{'", "'}'", "'('", "')'",
  "$accept", "inputunit", "word_list", "redirection",
  "simple_command_element", "redirection_list", "simple_command",
  "command", "shell_command", "for_command", "arith_for_command",
  "select_command", "case_command", "function_def", "function_body",
  "subshell", "if_command", "group_command", "arith_command",
  "cond_command", "elif_clause", "case_clause", "pattern_list",
  "case_clause_sequence", "pattern", "list", "compound_list", "list0",
  "list1", "list_terminator", "newline_list", "simple_list",
  "simple_list1", "pipeline_command", "pipeline", "timespec", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    38,    59,    10,   296,   124,    62,    60,    45,   123,
     125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    67,    67,    68,    69,    69,    69,    70,    71,    72,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     2,     2,     2,
       3,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     2,     3,     1,     1,     1,     1,     2,
       1,     2,     1,     1,     2,     1,     1,     1,     5,     5,
       1,     1,     1,     1,     1,     1,     1,     6,     6,     7,
       7,    10,    10,     9,     9,     7,     7,     5,     5,     6,
       6,     7,     7,    10,    10,     6,     7,     6,     5,     6,
       4,     1,     2,     3,     5,     7,     6,     3,     1,     3,
       4,     6,     5,     1,     2,     4,     4,     5,     5,     2,
       3,     1,     3,     2,     1,     2,     3,     3,     3,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     0,     2,
       1,     2,     2,     4,     4,     3,     3,     1,     1,     2,
       2,     3,     3,     4,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   118,     0,     0,     0,   118,   118,     0,     0,
       0,   135,    35,    36,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     5,     0,     0,   118,   118,
       0,    37,    40,    42,   134,    43,    46,    56,    50,    47,
      45,    52,    51,    53,    54,    55,     0,   120,   127,   128,
       0,     4,   104,     0,     0,   118,   118,     0,   118,     0,
       0,   118,     0,   129,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    14,    20,    16,
      28,    22,    18,    26,    24,    30,    32,    33,     8,     9,
       0,     0,     1,    35,    41,    38,    44,     2,   118,   118,
     121,   122,   118,     0,   130,   118,   119,   103,   105,   114,
       0,   118,     0,   118,   116,   115,   117,   118,   118,   118,
       0,   118,   118,     0,     0,    89,   132,   118,    13,    15,
      21,    17,    29,    23,    19,    27,    25,    31,    34,    10,
      11,    87,    83,    39,     0,     0,   125,   126,     0,   131,
       0,   118,   118,   118,   118,   118,   118,     0,   118,     0,
     118,     0,     0,     0,     0,   118,     0,   118,     0,     0,
     118,    81,    80,     0,   123,   124,   133,   118,   118,    84,
       0,     0,     0,   107,   108,   106,     0,    93,   118,     0,
     118,   118,     0,     6,     0,   118,     0,    67,    68,   118,
     118,   118,   118,     0,     0,     0,     0,    48,    49,     0,
      82,    78,     0,     0,    86,   109,   110,   111,   112,   113,
      77,    99,    94,     0,    75,   101,     0,     0,     0,     0,
      57,     7,   118,     0,    58,     0,     0,     0,     0,    69,
       0,   118,    70,    79,    85,   118,   100,    76,     0,     0,
     118,    59,    60,     0,   118,   118,    65,    66,    71,    72,
       0,    90,   118,   102,    95,    96,   118,   118,     0,     0,
     118,   118,   118,    92,    97,    98,     0,     0,    63,    64,
       0,     0,    91,    61,    62,    73,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,   194,    31,    32,    96,    33,    34,    35,    36,
      37,    38,    39,    40,   172,    41,    42,    43,    44,    45,
     180,   186,   187,   188,   227,    52,    53,   107,   108,   118,
      54,    46,    47,   109,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
     261,   -35,  -163,     5,    68,    11,  -163,  -163,    13,    36,
     387,    17,    24,  -163,   189,  -163,    97,   100,    96,   108,
     101,   117,   123,   129,  -163,  -163,   134,   135,  -163,  -163,
     137,  -163,  -163,   163,  -163,   535,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,   124,   120,  -163,   141,
     429,  -163,  -163,   178,   303,  -163,   148,    18,   149,   169,
     185,   153,   174,   141,   513,  -163,   154,   181,   184,   109,
     112,   193,   194,   195,   196,   203,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
     180,   179,  -163,  -163,  -163,  -163,   535,  -163,  -163,  -163,
     345,   345,  -163,   513,   141,  -163,  -163,  -163,   138,  -163,
      -4,  -163,    35,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
      65,  -163,  -163,   186,     7,  -163,   141,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,   303,   303,    51,    51,   471,   141,
      84,  -163,  -163,  -163,  -163,  -163,  -163,    -1,  -163,   122,
    -163,   217,   183,    14,    52,  -163,   216,  -163,   226,   227,
    -163,   535,  -163,     7,  -163,  -163,   141,  -163,  -163,  -163,
     236,   303,   303,   303,   303,   303,   238,   214,  -163,     3,
    -163,  -163,   237,  -163,   131,  -163,   201,  -163,  -163,  -163,
    -163,  -163,  -163,   239,   303,   131,   205,  -163,  -163,     7,
     535,  -163,   246,   253,  -163,  -163,  -163,    79,    79,    79,
    -163,  -163,   222,    29,  -163,  -163,   235,   -31,   248,   215,
    -163,  -163,  -163,    54,  -163,   252,   218,   255,   225,  -163,
     138,  -163,  -163,  -163,  -163,  -163,  -163,  -163,    31,   256,
    -163,  -163,  -163,    57,  -163,  -163,  -163,  -163,  -163,  -163,
      74,   113,  -163,  -163,  -163,   303,  -163,  -163,   264,   231,
    -163,  -163,  -163,  -163,  -163,   303,   269,   240,  -163,  -163,
     274,   241,  -163,  -163,  -163,  -163,  -163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   110,   -32,   259,   126,  -163,  -163,  -122,  -163,
    -163,  -163,  -163,  -163,  -162,  -163,  -163,  -163,  -163,  -163,
      41,  -163,   115,  -163,    83,  -158,    -6,  -163,    30,  -153,
     -25,  -163,   -75,     4,    -5,   307
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      59,    60,   171,    95,    48,    63,   195,   203,    51,   206,
       2,   211,   224,   190,   249,     3,   156,     4,     5,     6,
       7,   250,    90,    91,     9,   146,   147,   225,   199,    55,
     110,   112,   113,   120,    15,    58,   124,    61,   247,   106,
      65,   232,   106,   237,   238,   104,   106,   243,   191,   158,
     106,   171,   241,   225,   226,   159,    28,   106,    29,   126,
     114,   115,   116,   200,   143,    62,   201,   117,   254,   174,
     175,   266,   106,   144,   145,    66,   249,   148,   106,   165,
     226,    98,    99,   262,   160,   166,   157,   171,   270,   177,
     178,   179,    56,   163,   164,   106,    57,   106,   149,   150,
     106,   202,   173,   255,    48,    48,   267,   161,   106,   151,
     152,   162,   280,   281,   167,   168,   169,   106,   272,   178,
      78,    76,    79,   271,    77,    84,   181,   182,   183,   184,
     185,   189,    81,   130,    82,   131,   133,    92,   134,    95,
     204,    85,   204,   176,    80,   209,   193,    86,    48,    48,
      98,    99,   192,    87,   196,   231,    83,   132,    88,    89,
     135,   100,   101,   223,   114,   115,   116,    97,   151,   152,
     233,   212,   213,   114,   115,   116,   204,   204,   143,   153,
     154,   155,   105,   121,   228,   229,   102,    93,    13,    14,
     111,   119,   125,   235,   236,    16,    17,    18,    19,   122,
      20,    21,    22,    23,   123,   128,   127,   253,   129,    26,
      27,   215,   216,   217,   218,   219,   260,   136,   137,   138,
     139,    67,    68,    69,    70,   265,    71,   140,    72,    73,
     141,   142,   197,   198,   240,    74,    75,   275,   170,   261,
     193,   207,   208,   214,   264,   204,   204,   220,   268,   269,
     221,   234,   230,   244,   239,   242,   274,   245,   246,   225,
     276,   277,     1,   251,     2,   252,   282,   256,   257,     3,
     258,     4,     5,     6,     7,   259,   205,     8,     9,   278,
     263,   279,    10,    11,   283,    12,    13,    14,    15,   285,
     284,   286,    94,    16,    17,    18,    19,   210,    20,    21,
      22,    23,   273,   222,    24,    25,     2,    26,    27,   248,
      28,     3,    29,     4,     5,     6,     7,    64,     0,     8,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
      15,     0,     0,     0,     0,    16,    17,    18,    19,     0,
      20,    21,    22,    23,     0,     0,   106,     0,     2,    26,
      27,     0,    28,     3,    29,     4,     5,     6,     7,     0,
       0,     8,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,     0,     0,     0,     0,    16,    17,    18,
      19,     0,    20,    21,    22,    23,     0,     0,     0,     0,
       2,    26,    27,     0,    28,     3,    29,     4,     5,     6,
       7,     0,     0,     8,     9,     0,     0,     0,     0,    11,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,    18,    19,     0,    20,    21,    22,    23,     0,     0,
       0,     0,     2,    26,    27,     0,    28,     3,    29,     4,
       5,     6,     7,     0,     0,     8,     9,     0,     0,     0,
     103,     0,     0,    12,    13,    14,    15,     0,     0,     0,
       0,    16,    17,    18,    19,     0,    20,    21,    22,    23,
       0,     0,     0,     0,     2,    26,    27,     0,    28,     3,
      29,     4,     5,     6,     7,     0,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    15,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,    21,
      22,    23,     0,     0,   106,     0,     2,    26,    27,     0,
      28,     3,    29,     4,     5,     6,     7,     0,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    12,    13,    14,
      15,     0,     0,     0,     0,    16,    17,    18,    19,     0,
      20,    21,    22,    23,     0,     0,     0,     0,     0,    26,
      27,    14,    28,     0,    29,     0,     0,    16,    17,    18,
      19,     0,    20,    21,    22,    23,     0,     0,     0,     0,
       0,    26,    27
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-163))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,     7,   124,    35,     0,    10,   159,   165,    43,   167,
       3,   173,     9,    14,    45,     8,    20,    10,    11,    12,
      13,    52,    28,    29,    17,   100,   101,    24,    14,    24,
      55,    56,    14,    58,    27,    24,    61,    24,     9,    43,
      23,   194,    43,   201,   202,    50,    43,   209,    49,    14,
      43,   173,   205,    24,    51,    20,    49,    43,    51,    64,
      42,    43,    44,    49,    96,    29,    14,    49,    14,   144,
     145,    14,    43,    98,    99,    51,    45,   102,    43,    14,
      51,    30,    31,    52,    49,    20,   111,   209,    14,     5,
       6,     7,    24,   118,   119,    43,    28,    43,   103,   105,
      43,    49,   127,    49,   100,   101,    49,   113,    43,    30,
      31,   117,   270,   271,    49,   121,   122,    43,     5,     6,
      24,    24,    26,    49,    24,    24,   151,   152,   153,   154,
     155,   156,    24,    24,    26,    26,    24,     0,    26,   171,
     165,    24,   167,   148,    48,   170,    24,    24,   144,   145,
      30,    31,   158,    24,   160,    24,    48,    48,    24,    24,
      48,    41,    42,   188,    42,    43,    44,    43,    30,    31,
     195,   177,   178,    42,    43,    44,   201,   202,   210,    41,
      42,    43,     4,    14,   190,   191,    45,    24,    25,    26,
      42,    42,    18,   199,   200,    32,    33,    34,    35,    14,
      37,    38,    39,    40,    51,    24,    52,   232,    24,    46,
      47,   181,   182,   183,   184,   185,   241,    24,    24,    24,
      24,    32,    33,    34,    35,   250,    37,    24,    39,    40,
      50,    52,    15,    50,   204,    46,    47,   262,    52,   245,
      24,    15,    15,     7,   250,   270,   271,     9,   254,   255,
      36,    50,    15,     7,    15,    50,   262,     4,    36,    24,
     266,   267,     1,    15,     3,    50,   272,    15,    50,     8,
      15,    10,    11,    12,    13,    50,   166,    16,    17,    15,
      24,    50,    21,    22,    15,    24,    25,    26,    27,    15,
      50,    50,    33,    32,    33,    34,    35,   171,    37,    38,
      39,    40,   261,   188,    43,    44,     3,    46,    47,   226,
      49,     8,    51,    10,    11,    12,    13,    10,    -1,    16,
      17,    -1,    -1,    -1,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    43,    -1,     3,    46,
      47,    -1,    49,     8,    51,    10,    11,    12,    13,    -1,
      -1,    16,    17,    -1,    -1,    -1,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
       3,    46,    47,    -1,    49,     8,    51,    10,    11,    12,
      13,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,     3,    46,    47,    -1,    49,     8,    51,    10,
      11,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    -1,
      21,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,     3,    46,    47,    -1,    49,     8,
      51,    10,    11,    12,    13,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    43,    -1,     3,    46,    47,    -1,
      49,     8,    51,    10,    11,    12,    13,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    26,    49,    -1,    51,    -1,    -1,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     8,    10,    11,    12,    13,    16,    17,
      21,    22,    24,    25,    26,    27,    32,    33,    34,    35,
      37,    38,    39,    40,    43,    44,    46,    47,    49,    51,
      54,    56,    57,    59,    60,    61,    62,    63,    64,    65,
      66,    68,    69,    70,    71,    72,    84,    85,    86,    87,
      88,    43,    78,    79,    83,    24,    24,    28,    24,    79,
      79,    24,    29,    87,    88,    23,    51,    32,    33,    34,
      35,    37,    39,    40,    46,    47,    24,    24,    24,    26,
      48,    24,    26,    48,    24,    24,    24,    24,    24,    24,
      79,    79,     0,    24,    57,    56,    58,    43,    30,    31,
      41,    42,    45,    21,    87,     4,    43,    80,    81,    86,
      83,    42,    83,    14,    42,    43,    44,    49,    82,    42,
      83,    14,    14,    51,    83,    18,    87,    52,    24,    24,
      24,    26,    48,    24,    26,    48,    24,    24,    24,    24,
      24,    50,    52,    56,    83,    83,    85,    85,    83,    87,
      79,    30,    31,    41,    42,    43,    20,    83,    14,    20,
      49,    79,    79,    83,    83,    14,    20,    49,    79,    79,
      52,    61,    67,    83,    85,    85,    87,     5,     6,     7,
      73,    83,    83,    83,    83,    83,    74,    75,    76,    83,
      14,    49,    79,    24,    55,    82,    79,    15,    50,    14,
      49,    14,    49,    78,    83,    55,    78,    15,    15,    83,
      58,    67,    79,    79,     7,    81,    81,    81,    81,    81,
       9,    36,    75,    83,     9,    24,    51,    77,    79,    79,
      15,    24,    82,    83,    50,    79,    79,    78,    78,    15,
      81,    82,    50,    67,     7,     4,    36,     9,    77,    45,
      52,    15,    50,    83,    14,    49,    15,    50,    15,    50,
      83,    79,    52,    24,    79,    83,    14,    49,    79,    79,
      14,    49,     5,    73,    79,    83,    79,    79,    15,    50,
      78,    78,    79,    15,    50,    15,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 283 "parser.y"
    {
			  /* Case of regular command.  Discard the error
			     safety net,and return the command just parsed. */
			  global_command = (yyvsp[(1) - (2)].command);
			  eof_encountered = 0;
			  discard_parser_constructs (0);
			  YYACCEPT;
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 292 "parser.y"
    {
			  /* Case of regular command, but not a very
			     interesting one.  Return a NULL command. */
			  global_command = (COMMAND *)NULL;
			  YYACCEPT;
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 299 "parser.y"
    {
			  /* Error during parsing.  Return NULL command. */
			  global_command = (COMMAND *)NULL;
			  eof_encountered = 0;
			  discard_parser_constructs (1);
			  if (interactive)
			    {
			      YYACCEPT;
			    }
			  else
			    {
			      YYABORT;
			    }
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 314 "parser.y"
    {
			  /* Case of EOF seen by itself.  Do ignoreeof or
			     not. */
			  global_command = (COMMAND *)NULL;
			  handle_eof_input_unit ();
			  YYACCEPT;
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 324 "parser.y"
    { (yyval.word_list) = make_word_list ((yyvsp[(1) - (1)].word), (WORD_LIST *)NULL); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 326 "parser.y"
    { (yyval.word_list) = make_word_list ((yyvsp[(2) - (2)].word), (yyvsp[(1) - (2)].word_list)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 330 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (1, r_output_direction, redir);
			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 335 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (0, r_input_direction, redir);
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 340 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_output_direction, redir);
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 345 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_input_direction, redir);
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 350 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (1, r_appending_to, redir);
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 355 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_appending_to, redir);
			}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 360 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (0, r_reading_until, redir);
			  redir_stack[need_here_doc++] = (yyval.redirect);
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_reading_until, redir);
			  redir_stack[need_here_doc++] = (yyval.redirect);
			}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 372 "parser.y"
    {
			  redir.dest = (yyvsp[(2) - (2)].number);
			  (yyval.redirect) = make_redirection (0, r_duplicating_input, redir);
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 377 "parser.y"
    {
			  redir.dest = (yyvsp[(3) - (3)].number);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_duplicating_input, redir);
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 382 "parser.y"
    {
			  redir.dest = (yyvsp[(2) - (2)].number);
			  (yyval.redirect) = make_redirection (1, r_duplicating_output, redir);
			}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 387 "parser.y"
    {
			  redir.dest = (yyvsp[(3) - (3)].number);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_duplicating_output, redir);
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 392 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (0, r_duplicating_input_word, redir);
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 397 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_duplicating_input_word, redir);
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 402 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (1, r_duplicating_output_word, redir);
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 407 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_duplicating_output_word, redir);
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 412 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection
			    (0, r_deblank_reading_until, redir);
			  redir_stack[need_here_doc++] = (yyval.redirect);
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 419 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection
			    ((yyvsp[(1) - (3)].number), r_deblank_reading_until, redir);
			  redir_stack[need_here_doc++] = (yyval.redirect);
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 426 "parser.y"
    {
			  redir.dest = 0;
			  (yyval.redirect) = make_redirection (1, r_close_this, redir);
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 431 "parser.y"
    {
			  redir.dest = 0;
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_close_this, redir);
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 436 "parser.y"
    {
			  redir.dest = 0;
			  (yyval.redirect) = make_redirection (0, r_close_this, redir);
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 441 "parser.y"
    {
			  redir.dest = 0;
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_close_this, redir);
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 446 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (1, r_err_and_out, redir);
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 451 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_input_output, redir);
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 456 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (0, r_input_output, redir);
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 461 "parser.y"
    {
			  redir.filename = (yyvsp[(2) - (2)].word);
			  (yyval.redirect) = make_redirection (1, r_output_force, redir);
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 466 "parser.y"
    {
			  redir.filename = (yyvsp[(3) - (3)].word);
			  (yyval.redirect) = make_redirection ((yyvsp[(1) - (3)].number), r_output_force, redir);
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 473 "parser.y"
    { (yyval.element).word = (yyvsp[(1) - (1)].word); (yyval.element).redirect = 0; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 475 "parser.y"
    { (yyval.element).word = (yyvsp[(1) - (1)].word); (yyval.element).redirect = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 477 "parser.y"
    { (yyval.element).redirect = (yyvsp[(1) - (1)].redirect); (yyval.element).word = 0; }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 481 "parser.y"
    {
			  (yyval.redirect) = (yyvsp[(1) - (1)].redirect);
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 485 "parser.y"
    {
			  register REDIRECT *t;

			  for (t = (yyvsp[(1) - (2)].redirect); t->next; t = t->next)
			    ;
			  t->next = (yyvsp[(2) - (2)].redirect);
			  (yyval.redirect) = (yyvsp[(1) - (2)].redirect);
			}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 496 "parser.y"
    { (yyval.command) = make_simple_command ((yyvsp[(1) - (1)].element), (COMMAND *)NULL); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 498 "parser.y"
    { (yyval.command) = make_simple_command ((yyvsp[(2) - (2)].element), (yyvsp[(1) - (2)].command)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 502 "parser.y"
    { (yyval.command) = clean_simple_command ((yyvsp[(1) - (1)].command)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 504 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 506 "parser.y"
    {
			  COMMAND *tc;

			  tc = (yyvsp[(1) - (2)].command);
			  if (tc->redirects)
			    {
			      register REDIRECT *t;
			      for (t = tc->redirects; t->next; t = t->next)
				;
			      t->next = (yyvsp[(2) - (2)].redirect);
			    }
			  else
			    tc->redirects = (yyvsp[(2) - (2)].redirect);
			  (yyval.command) = (yyvsp[(1) - (2)].command);
			}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 522 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 526 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 528 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 530 "parser.y"
    { (yyval.command) = make_while_command ((yyvsp[(2) - (5)].command), (yyvsp[(4) - (5)].command)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 532 "parser.y"
    { (yyval.command) = make_until_command ((yyvsp[(2) - (5)].command), (yyvsp[(4) - (5)].command)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 534 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 536 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 538 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 540 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 542 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 544 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 546 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 550 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (6)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(5) - (6)].command)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 552 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (6)].word), add_string_to_list ("$@", (WORD_LIST *)NULL), (yyvsp[(5) - (6)].command)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 554 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (7)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(6) - (7)].command)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 556 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (7)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(6) - (7)].command)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 558 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (10)].word), REVERSE_LIST ((yyvsp[(5) - (10)].word_list), WORD_LIST *), (yyvsp[(9) - (10)].command)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 560 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (10)].word), REVERSE_LIST ((yyvsp[(5) - (10)].word_list), WORD_LIST *), (yyvsp[(9) - (10)].command)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 562 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (9)].word), (WORD_LIST *)NULL, (yyvsp[(8) - (9)].command)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 564 "parser.y"
    { (yyval.command) = make_for_command ((yyvsp[(2) - (9)].word), (WORD_LIST *)NULL, (yyvsp[(8) - (9)].command)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 568 "parser.y"
    { (yyval.command) = make_arith_for_command ((yyvsp[(2) - (7)].word_list), (yyvsp[(6) - (7)].command), arith_for_lineno); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 570 "parser.y"
    { (yyval.command) = make_arith_for_command ((yyvsp[(2) - (7)].word_list), (yyvsp[(6) - (7)].command), arith_for_lineno); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 572 "parser.y"
    { (yyval.command) = make_arith_for_command ((yyvsp[(2) - (5)].word_list), (yyvsp[(4) - (5)].command), arith_for_lineno); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 574 "parser.y"
    { (yyval.command) = make_arith_for_command ((yyvsp[(2) - (5)].word_list), (yyvsp[(4) - (5)].command), arith_for_lineno); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 578 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (6)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(5) - (6)].command));
			}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 582 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (6)].word), add_string_to_list ("$@", (WORD_LIST *)NULL), (yyvsp[(5) - (6)].command));
			}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 586 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (7)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(6) - (7)].command));
			}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 590 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (7)].word), add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), (yyvsp[(6) - (7)].command));
			}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 594 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (10)].word), (WORD_LIST *)reverse_list ((yyvsp[(5) - (10)].word_list)), (yyvsp[(9) - (10)].command));
			}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 598 "parser.y"
    {
			  (yyval.command) = make_select_command ((yyvsp[(2) - (10)].word), (WORD_LIST *)reverse_list ((yyvsp[(5) - (10)].word_list)), (yyvsp[(9) - (10)].command));
			}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 604 "parser.y"
    { (yyval.command) = make_case_command ((yyvsp[(2) - (6)].word), (PATTERN_LIST *)NULL); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 606 "parser.y"
    { (yyval.command) = make_case_command ((yyvsp[(2) - (7)].word), (yyvsp[(5) - (7)].pattern)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 608 "parser.y"
    { (yyval.command) = make_case_command ((yyvsp[(2) - (6)].word), (yyvsp[(5) - (6)].pattern)); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 612 "parser.y"
    { (yyval.command) = make_function_def ((yyvsp[(1) - (5)].word), (yyvsp[(5) - (5)].command), function_dstart, function_bstart); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 615 "parser.y"
    { (yyval.command) = make_function_def ((yyvsp[(2) - (6)].word), (yyvsp[(6) - (6)].command), function_dstart, function_bstart); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 618 "parser.y"
    { (yyval.command) = make_function_def ((yyvsp[(2) - (4)].word), (yyvsp[(4) - (4)].command), function_dstart, function_bstart); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 623 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 625 "parser.y"
    {
			  COMMAND *tc;

			  tc = (yyvsp[(1) - (2)].command);
			  /* According to Posix.2 3.9.5, redirections
			     specified after the body of a function should
			     be attached to the function and performed when
			     the function is executed, not as part of the
			     function definition command. */
			  /* XXX - I don't think it matters, but we might
			     want to change this in the future to avoid
			     problems differentiating between a function
			     definition with a redirection and a function
			     definition containing a single command with a
			     redirection.  The two are semantically equivalent,
			     though -- the only difference is in how the
			     command printing code displays the redirections. */
			  if (tc->redirects)
			    {
			      register REDIRECT *t;
			      for (t = tc->redirects; t->next; t = t->next)
				;
			      t->next = (yyvsp[(2) - (2)].redirect);
			    }
			  else
			    tc->redirects = (yyvsp[(2) - (2)].redirect);
			  (yyval.command) = (yyvsp[(1) - (2)].command);
			}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 656 "parser.y"
    {
			  (yyval.command) = make_subshell_command ((yyvsp[(2) - (3)].command));
			  (yyval.command)->flags |= CMD_WANT_SUBSHELL;
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 663 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (5)].command), (yyvsp[(4) - (5)].command), (COMMAND *)NULL); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 665 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (7)].command), (yyvsp[(4) - (7)].command), (yyvsp[(6) - (7)].command)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 667 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(5) - (6)].command)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 672 "parser.y"
    { (yyval.command) = make_group_command ((yyvsp[(2) - (3)].command)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 676 "parser.y"
    { (yyval.command) = make_arith_command ((yyvsp[(1) - (1)].word_list)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 680 "parser.y"
    { (yyval.command) = (yyvsp[(2) - (3)].command); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 684 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (4)].command), (yyvsp[(4) - (4)].command), (COMMAND *)NULL); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 686 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(6) - (6)].command)); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 688 "parser.y"
    { (yyval.command) = make_if_command ((yyvsp[(2) - (5)].command), (yyvsp[(4) - (5)].command), (yyvsp[(5) - (5)].command)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 693 "parser.y"
    { (yyvsp[(2) - (2)].pattern)->next = (yyvsp[(1) - (2)].pattern); (yyval.pattern) = (yyvsp[(2) - (2)].pattern); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 697 "parser.y"
    { (yyval.pattern) = make_pattern_list ((yyvsp[(2) - (4)].word_list), (yyvsp[(4) - (4)].command)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 699 "parser.y"
    { (yyval.pattern) = make_pattern_list ((yyvsp[(2) - (4)].word_list), (COMMAND *)NULL); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 701 "parser.y"
    { (yyval.pattern) = make_pattern_list ((yyvsp[(3) - (5)].word_list), (yyvsp[(5) - (5)].command)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 703 "parser.y"
    { (yyval.pattern) = make_pattern_list ((yyvsp[(3) - (5)].word_list), (COMMAND *)NULL); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 708 "parser.y"
    { (yyvsp[(2) - (3)].pattern)->next = (yyvsp[(1) - (3)].pattern); (yyval.pattern) = (yyvsp[(2) - (3)].pattern); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 712 "parser.y"
    { (yyval.word_list) = make_word_list ((yyvsp[(1) - (1)].word), (WORD_LIST *)NULL); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 714 "parser.y"
    { (yyval.word_list) = make_word_list ((yyvsp[(3) - (3)].word), (yyvsp[(1) - (3)].word_list)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 723 "parser.y"
    {
			  (yyval.command) = (yyvsp[(2) - (2)].command);
			  if (need_here_doc)
			    gather_here_documents ();
			 }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 732 "parser.y"
    {
			  (yyval.command) = (yyvsp[(2) - (2)].command);
			}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 739 "parser.y"
    {
			  if ((yyvsp[(1) - (3)].command)->type == cm_connection)
			    (yyval.command) = connect_async_list ((yyvsp[(1) - (3)].command), (COMMAND *)NULL, '&');
			  else
			    (yyval.command) = command_connect ((yyvsp[(1) - (3)].command), (COMMAND *)NULL, '&');
			}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 750 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), AND_AND); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 752 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), OR_OR); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 754 "parser.y"
    {
			  if ((yyvsp[(1) - (4)].command)->type == cm_connection)
			    (yyval.command) = connect_async_list ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), '&');
			  else
			    (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), '&');
			}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 761 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), ';'); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 763 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), ';'); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 765 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 784 "parser.y"
    {
			  (yyval.command) = (yyvsp[(1) - (1)].command);
			  if (need_here_doc)
			    gather_here_documents ();
			}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 790 "parser.y"
    {
			  if ((yyvsp[(1) - (2)].command)->type == cm_connection)
			    (yyval.command) = connect_async_list ((yyvsp[(1) - (2)].command), (COMMAND *)NULL, '&');
			  else
			    (yyval.command) = command_connect ((yyvsp[(1) - (2)].command), (COMMAND *)NULL, '&');
			  if (need_here_doc)
			    gather_here_documents ();
			}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 799 "parser.y"
    {
			  (yyval.command) = (yyvsp[(1) - (2)].command);
			  if (need_here_doc)
			    gather_here_documents ();
			}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 807 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), AND_AND); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 809 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), OR_OR); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 811 "parser.y"
    {
			  if ((yyvsp[(1) - (3)].command)->type == cm_connection)
			    (yyval.command) = connect_async_list ((yyvsp[(1) - (3)].command), (yyvsp[(3) - (3)].command), '&');
			  else
			    (yyval.command) = command_connect ((yyvsp[(1) - (3)].command), (yyvsp[(3) - (3)].command), '&');
			}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 818 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (3)].command), (yyvsp[(3) - (3)].command), ';'); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 821 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 825 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 827 "parser.y"
    {
			  (yyvsp[(2) - (2)].command)->flags |= CMD_INVERT_RETURN;
			  (yyval.command) = (yyvsp[(2) - (2)].command);
			}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 832 "parser.y"
    {
			  (yyvsp[(2) - (2)].command)->flags |= (yyvsp[(1) - (2)].number);
			  (yyval.command) = (yyvsp[(2) - (2)].command);
			}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 837 "parser.y"
    {
			  (yyvsp[(3) - (3)].command)->flags |= (yyvsp[(1) - (3)].number)|CMD_INVERT_RETURN;
			  (yyval.command) = (yyvsp[(3) - (3)].command);
			}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 842 "parser.y"
    {
			  (yyvsp[(3) - (3)].command)->flags |= (yyvsp[(2) - (3)].number)|CMD_INVERT_RETURN;
			  (yyval.command) = (yyvsp[(3) - (3)].command);
			}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 850 "parser.y"
    { (yyval.command) = command_connect ((yyvsp[(1) - (4)].command), (yyvsp[(4) - (4)].command), '|'); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 852 "parser.y"
    { (yyval.command) = (yyvsp[(1) - (1)].command); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 856 "parser.y"
    { (yyval.number) = CMD_TIME_PIPELINE; }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 858 "parser.y"
    { (yyval.number) = CMD_TIME_PIPELINE|CMD_TIME_POSIX; }
    break;



/* Line 1806 of yacc.c  */
#line 3078 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 860 "parser.y"


/* Possible states for the parser that require it to do special things. */
#define PST_CASEPAT	0x001		/* in a case pattern list */
#define PST_ALEXPNEXT	0x002		/* expand next word for aliases */
#define PST_ALLOWOPNBRC	0x004		/* allow open brace for function def */
#define PST_NEEDCLOSBRC	0x008		/* need close brace */
#define PST_DBLPAREN	0x010		/* double-paren parsing */
#define PST_SUBSHELL	0x020		/* ( ... ) subshell */
#define PST_CMDSUBST	0x040		/* $( ... ) command substitution */
#define PST_CASESTMT	0x080		/* parsing a case statement */
#define PST_CONDCMD	0x100		/* parsing a [[...]] command */
#define PST_CONDEXPR	0x200		/* parsing the guts of [[...]] */
#define PST_ARITHFOR	0x400		/* parsing an arithmetic for command */

/* Initial size to allocate for tokens, and the
   amount to grow them by. */
#define TOKEN_DEFAULT_INITIAL_SIZE 496
#define TOKEN_DEFAULT_GROW_SIZE 512

/* The token currently being read. */
static int current_token;

/* The last read token, or NULL.  read_token () uses this for context
   checking. */
static int last_read_token;

/* The token read prior to last_read_token. */
static int token_before_that;

/* The token read prior to token_before_that. */
static int two_tokens_ago;

/* If non-zero, it is the token that we want read_token to return
   regardless of what text is (or isn't) present to be read.  This
   is reset by read_token.  If token_to_read == WORD or
   ASSIGNMENT_WORD, yylval.word should be set to word_desc_to_read. */
static int token_to_read;
static WORD_DESC *word_desc_to_read;

/* The current parser state. */
static int parser_state;

/* Global var is non-zero when end of file has been reached. */
int EOF_Reached = 0;

#ifdef DEBUG
static void
debug_parser (i)
     int i;
{
#if YYDEBUG != 0
  yydebug = i;
#endif
}
#endif

/* yy_getc () returns the next available character from input or EOF.
   yy_ungetc (c) makes `c' the next character to read.
   init_yy_io (get, unget, type, location) makes the function GET the
   installed function for getting the next character, makes UNGET the
   installed function for un-getting a character, sets the type of stream
   (either string or file) from TYPE, and makes LOCATION point to where
   the input is coming from. */

/* Unconditionally returns end-of-file. */
int
return_EOF ()
{
  return (EOF);
}

/* Variable containing the current get and unget functions.
   See ./input.h for a clearer description. */
BASH_INPUT bash_input;

/* Set all of the fields in BASH_INPUT to NULL.  Free bash_input.name if it
   is non-null, avoiding a memory leak. */
void
initialize_bash_input ()
{
  bash_input.type = st_none;
  FREE (bash_input.name);
  bash_input.name = (char *)NULL;
  bash_input.location.file = (FILE *)NULL;
  bash_input.location.string = (char *)NULL;
  bash_input.getter = (sh_cget_func_t *)NULL;
  bash_input.ungetter = (sh_cunget_func_t *)NULL;
}

/* Set the contents of the current bash input stream from
   GET, UNGET, TYPE, NAME, and LOCATION. */
void
init_yy_io (get, unget, type, name, location)
     sh_cget_func_t *get;
     sh_cunget_func_t *unget;
     enum stream_type type;
     const char *name;
     INPUT_STREAM location;
{
  bash_input.type = type;
  FREE (bash_input.name);
  bash_input.name = name ? savestring (name) : (char *)NULL;

  /* XXX */
#if defined (CRAY)
  memcpy((char *)&bash_input.location.string, (char *)&location.string, sizeof(location));
#else
  bash_input.location = location;
#endif
  bash_input.getter = get;
  bash_input.ungetter = unget;
}

/* Call this to get the next character of input. */
static int
yy_getc ()
{
  return (*(bash_input.getter)) ();
}

/* Call this to unget C.  That is, to make C the next character
   to be read. */
static int
yy_ungetc (c)
     int c;
{
  return (*(bash_input.ungetter)) (c);
}

#if defined (BUFFERED_INPUT)
#ifdef INCLUDE_UNUSED
int
input_file_descriptor ()
{
  switch (bash_input.type)
    {
    case st_stream:
      return (fileno (bash_input.location.file));
    case st_bstream:
      return (bash_input.location.buffered_fd);
    case st_stdin:
    default:
      return (fileno (stdin));
    }
}
#endif
#endif /* BUFFERED_INPUT */

/* **************************************************************** */
/*								    */
/*		  Let input be read from readline ().		    */
/*								    */
/* **************************************************************** */

#if defined (READLINE)
char *current_readline_prompt = (char *)NULL;
char *current_readline_line = (char *)NULL;
int current_readline_line_index = 0;

static int
yy_readline_get ()
{
  SigHandler *old_sigint;
  int line_len;
  unsigned char c;

  if (!current_readline_line)
    {
      if (!bash_readline_initialized)
	initialize_readline ();

#if defined (JOB_CONTROL)
      if (job_control)
	give_terminal_to (shell_pgrp, 0);
#endif /* JOB_CONTROL */

      old_sigint = (SigHandler *)NULL;
      if (signal_is_ignored (SIGINT) == 0)
	{
	  old_sigint = (SigHandler *)set_signal_handler (SIGINT, sigint_sighandler);
	  interrupt_immediately++;
	}

      current_readline_line = readline (current_readline_prompt ?
      					  current_readline_prompt : "");

      if (signal_is_ignored (SIGINT) == 0 && old_sigint)
	{
	  interrupt_immediately--;
	  set_signal_handler (SIGINT, old_sigint);
	}

#if 0
      /* Reset the prompt to the decoded value of prompt_string_pointer. */
      reset_readline_prompt ();
#endif

      if (current_readline_line == 0)
	return (EOF);

      current_readline_line_index = 0;
      line_len = strlen (current_readline_line);

      current_readline_line = (char *)xrealloc (current_readline_line, 2 + line_len);
      current_readline_line[line_len++] = '\n';
      current_readline_line[line_len] = '\0';
    }

  if (current_readline_line[current_readline_line_index] == 0)
    {
      free (current_readline_line);
      current_readline_line = (char *)NULL;
      return (yy_readline_get ());
    }
  else
    {
      c = current_readline_line[current_readline_line_index++];
      return (c);
    }
}

static int
yy_readline_unget (c)
     int c;
{
  if (current_readline_line_index && current_readline_line)
    current_readline_line[--current_readline_line_index] = c;
  return (c);
}

void
with_input_from_stdin ()
{
  INPUT_STREAM location;

  if (bash_input.type != st_stdin && stream_on_stack (st_stdin) == 0)
    {
      location.string = current_readline_line;
      init_yy_io (yy_readline_get, yy_readline_unget,
		  st_stdin, "readline stdin", location);
    }
}

#else  /* !READLINE */

void
with_input_from_stdin ()
{
  with_input_from_stream (stdin, "stdin");
}
#endif	/* !READLINE */

/* **************************************************************** */
/*								    */
/*   Let input come from STRING.  STRING is zero terminated.	    */
/*								    */
/* **************************************************************** */

static int
yy_string_get ()
{
  register char *string;
  register unsigned char c;

  string = bash_input.location.string;

  /* If the string doesn't exist, or is empty, EOF found. */
  if (string && *string)
    {
      c = *string++;
      bash_input.location.string = string;
      return (c);
    }
  else
    return (EOF);
}

static int
yy_string_unget (c)
     int c;
{
  *(--bash_input.location.string) = c;
  return (c);
}

void
with_input_from_string (string, name)
     char *string;
     const char *name;
{
  INPUT_STREAM location;

  location.string = string;
  init_yy_io (yy_string_get, yy_string_unget, st_string, name, location);
}

/* **************************************************************** */
/*								    */
/*		     Let input come from STREAM.		    */
/*								    */
/* **************************************************************** */

/* These two functions used to test the value of the HAVE_RESTARTABLE_SYSCALLS
   define, and just use getc/ungetc if it was defined, but since bash
   installs its signal handlers without the SA_RESTART flag, some signals
   (like SIGCHLD, SIGWINCH, etc.) received during a read(2) will not cause
   the read to be restarted.  We need to restart it ourselves. */

static int
yy_stream_get ()
{
  int result;

  result = EOF;
  if (bash_input.location.file)
    result = getc_with_restart (bash_input.location.file);

  return (result);
}

static int
yy_stream_unget (c)
     int c;
{
  return (ungetc_with_restart (c, bash_input.location.file));
}

void
with_input_from_stream (stream, name)
     FILE *stream;
     const char *name;
{
  INPUT_STREAM location;

  location.file = stream;
  init_yy_io (yy_stream_get, yy_stream_unget, st_stream, name, location);
}

typedef struct stream_saver {
  struct stream_saver *next;
  BASH_INPUT bash_input;
  int line;
#if defined (BUFFERED_INPUT)
  BUFFERED_STREAM *bstream;
#endif /* BUFFERED_INPUT */
} STREAM_SAVER;

/* The globally known line number. */
int line_number = 0;

#if defined (COND_COMMAND)
static int cond_lineno;
static int cond_token;
#endif

STREAM_SAVER *stream_list = (STREAM_SAVER *)NULL;

void
push_stream (reset_lineno)
     int reset_lineno;
{
  STREAM_SAVER *saver = (STREAM_SAVER *)xmalloc (sizeof (STREAM_SAVER));

  xbcopy ((char *)&bash_input, (char *)&(saver->bash_input), sizeof (BASH_INPUT));

#if defined (BUFFERED_INPUT)
  saver->bstream = (BUFFERED_STREAM *)NULL;
  /* If we have a buffered stream, clear out buffers[fd]. */
  if (bash_input.type == st_bstream && bash_input.location.buffered_fd >= 0)
    saver->bstream = set_buffered_stream (bash_input.location.buffered_fd,
    					  (BUFFERED_STREAM *)NULL);
#endif /* BUFFERED_INPUT */

  saver->line = line_number;
  bash_input.name = (char *)NULL;
  saver->next = stream_list;
  stream_list = saver;
  EOF_Reached = 0;
  if (reset_lineno)
    line_number = 0;
}

void
pop_stream ()
{
  if (!stream_list)
    EOF_Reached = 1;
  else
    {
      STREAM_SAVER *saver = stream_list;

      EOF_Reached = 0;
      stream_list = stream_list->next;

      init_yy_io (saver->bash_input.getter,
		  saver->bash_input.ungetter,
		  saver->bash_input.type,
		  saver->bash_input.name,
		  saver->bash_input.location);

#if defined (BUFFERED_INPUT)
      /* If we have a buffered stream, restore buffers[fd]. */
      /* If the input file descriptor was changed while this was on the
	 save stack, update the buffered fd to the new file descriptor and
	 re-establish the buffer <-> bash_input fd correspondence. */
      if (bash_input.type == st_bstream && bash_input.location.buffered_fd >= 0)
	{
	  if (bash_input_fd_changed)
	    {
	      bash_input_fd_changed = 0;
	      if (default_buffered_input >= 0)
		{
		  bash_input.location.buffered_fd = default_buffered_input;
		  saver->bstream->b_fd = default_buffered_input;
		  SET_CLOSE_ON_EXEC (default_buffered_input);
		}
	    }
	  /* XXX could free buffered stream returned as result here. */
	  set_buffered_stream (bash_input.location.buffered_fd, saver->bstream);
	}
#endif /* BUFFERED_INPUT */

      line_number = saver->line;

      FREE (saver->bash_input.name);
      free (saver);
    }
}

/* Return 1 if a stream of type TYPE is saved on the stack. */
int
stream_on_stack (type)
     enum stream_type type;
{
  register STREAM_SAVER *s;

  for (s = stream_list; s; s = s->next)
    if (s->bash_input.type == type)
      return 1;
  return 0;
}

/* Save the current token state and return it in a malloced array. */
int *
save_token_state ()
{
  int *ret;

  ret = (int *)xmalloc (3 * sizeof (int));
  ret[0] = last_read_token;
  ret[1] = token_before_that;
  ret[2] = two_tokens_ago;
  return ret;
}

void
restore_token_state (ts)
     int *ts;
{
  if (ts == 0)
    return;
  last_read_token = ts[0];
  token_before_that = ts[1];
  two_tokens_ago = ts[2];
}

/*
 * This is used to inhibit alias expansion and reserved word recognition
 * inside case statement pattern lists.  A `case statement pattern list' is:
 *
 *	everything between the `in' in a `case word in' and the next ')'
 *	or `esac'
 *	everything between a `;;' and the next `)' or `esac'
 */

#if defined (ALIAS) || defined (DPAREN_ARITHMETIC)

#if !defined (ALIAS)
typedef void *alias_t;
#endif

#define END_OF_ALIAS 0

/*
 * Pseudo-global variables used in implementing token-wise alias expansion.
 */

/*
 * Pushing and popping strings.  This works together with shell_getc to
 * implement alias expansion on a per-token basis.
 */

typedef struct string_saver {
  struct string_saver *next;
  int expand_alias;  /* Value to set expand_alias to when string is popped. */
  char *saved_line;
#if defined (ALIAS)
  alias_t *expander;   /* alias that caused this line to be pushed. */
#endif
  int saved_line_size, saved_line_index, saved_line_terminator;
} STRING_SAVER;

STRING_SAVER *pushed_string_list = (STRING_SAVER *)NULL;

/*
 * Push the current shell_input_line onto a stack of such lines and make S
 * the current input.  Used when expanding aliases.  EXPAND is used to set
 * the value of expand_next_token when the string is popped, so that the
 * word after the alias in the original line is handled correctly when the
 * alias expands to multiple words.  TOKEN is the token that was expanded
 * into S; it is saved and used to prevent infinite recursive expansion.
 */
static void
push_string (s, expand, ap)
     char *s;
     int expand;
     alias_t *ap;
{
  STRING_SAVER *temp = (STRING_SAVER *)xmalloc (sizeof (STRING_SAVER));

  temp->expand_alias = expand;
  temp->saved_line = shell_input_line;
  temp->saved_line_size = shell_input_line_size;
  temp->saved_line_index = shell_input_line_index;
  temp->saved_line_terminator = shell_input_line_terminator;
#if defined (ALIAS)
  temp->expander = ap;
#endif
  temp->next = pushed_string_list;
  pushed_string_list = temp;

#if defined (ALIAS)
  if (ap)
    ap->flags |= AL_BEINGEXPANDED;
#endif

  shell_input_line = s;
  shell_input_line_size = strlen (s);
  shell_input_line_index = 0;
  shell_input_line_terminator = '\0';
  parser_state &= ~PST_ALEXPNEXT;
}

/*
 * Make the top of the pushed_string stack be the current shell input.
 * Only called when there is something on the stack.  Called from shell_getc
 * when it thinks it has consumed the string generated by an alias expansion
 * and needs to return to the original input line.
 */
static void
pop_string ()
{
  STRING_SAVER *t;

  FREE (shell_input_line);
  shell_input_line = pushed_string_list->saved_line;
  shell_input_line_index = pushed_string_list->saved_line_index;
  shell_input_line_size = pushed_string_list->saved_line_size;
  shell_input_line_terminator = pushed_string_list->saved_line_terminator;

  if (pushed_string_list->expand_alias)
    parser_state |= PST_ALEXPNEXT;
  else
    parser_state &= ~PST_ALEXPNEXT;

  t = pushed_string_list;
  pushed_string_list = pushed_string_list->next;

#if defined (ALIAS)
  if (t->expander)
    t->expander->flags &= ~AL_BEINGEXPANDED;
#endif

  free ((char *)t);
}

static void
free_string_list ()
{
  register STRING_SAVER *t, *t1;

  for (t = pushed_string_list; t; )
    {
      t1 = t->next;
      FREE (t->saved_line);
#if defined (ALIAS)
      if (t->expander)
	t->expander->flags &= ~AL_BEINGEXPANDED;
#endif
      free ((char *)t);
      t = t1;
    }
  pushed_string_list = (STRING_SAVER *)NULL;
}

#endif /* ALIAS || DPAREN_ARITHMETIC */

/* Return a line of text, taken from wherever yylex () reads input.
   If there is no more input, then we return NULL.  If REMOVE_QUOTED_NEWLINE
   is non-zero, we remove unquoted \<newline> pairs.  This is used by
   read_secondary_line to read here documents. */
static char *
read_a_line (remove_quoted_newline)
     int remove_quoted_newline;
{
  static char *line_buffer = (char *)NULL;
  static int buffer_size = 0;
  int indx = 0, c, peekc, pass_next;

#if defined (READLINE)
  if (interactive && bash_input.type != st_string && no_line_editing)
#else
  if (interactive && bash_input.type != st_string)
#endif
    print_prompt ();

  pass_next = 0;
  while (1)
    {
      c = yy_getc ();

      /* Allow immediate exit if interrupted during input. */
      QUIT;

      /* Ignore null bytes in input. */
      if (c == 0)
	{
#if 0
	  internal_warning ("read_a_line: ignored null byte in input");
#endif
	  continue;
	}

      /* If there is no more input, then we return NULL. */
      if (c == EOF)
	{
	  if (interactive && bash_input.type == st_stream)
	    clearerr (stdin);
	  if (indx == 0)
	    return ((char *)NULL);
	  c = '\n';
	}

      /* `+2' in case the final character in the buffer is a newline. */
      RESIZE_MALLOCED_BUFFER (line_buffer, indx, 2, buffer_size, 128);

      /* IF REMOVE_QUOTED_NEWLINES is non-zero, we are reading a
	 here document with an unquoted delimiter.  In this case,
	 the line will be expanded as if it were in double quotes.
	 We allow a backslash to escape the next character, but we
	 need to treat the backslash specially only if a backslash
	 quoting a backslash-newline pair appears in the line. */
      if (pass_next)
	{
	  line_buffer[indx++] = c;
	  pass_next = 0;
	}
      else if (c == '\\' && remove_quoted_newline)
	{
	  peekc = yy_getc ();
	  if (peekc == '\n')
	    continue;	/* Make the unquoted \<newline> pair disappear. */
	  else
	    {
	      yy_ungetc (peekc);
	      pass_next = 1;
	      line_buffer[indx++] = c;		/* Preserve the backslash. */
	    }
	}
      else
	line_buffer[indx++] = c;

      if (c == '\n')
	{
	  line_buffer[indx] = '\0';
	  return (line_buffer);
	}
    }
}

/* Return a line as in read_a_line (), but insure that the prompt is
   the secondary prompt.  This is used to read the lines of a here
   document.  REMOVE_QUOTED_NEWLINE is non-zero if we should remove
   newlines quoted with backslashes while reading the line.  It is
   non-zero unless the delimiter of the here document was quoted. */
char *
read_secondary_line (remove_quoted_newline)
     int remove_quoted_newline;
{
  prompt_string_pointer = &ps2_prompt;
  prompt_again ();
  return (read_a_line (remove_quoted_newline));
}

/* **************************************************************** */
/*								    */
/*				YYLEX ()			    */
/*								    */
/* **************************************************************** */

/* Reserved words.  These are only recognized as the first word of a
   command. */
STRING_INT_ALIST word_token_alist[] = {
  { "if", IF },
  { "then", THEN },
  { "else", ELSE },
  { "elif", ELIF },
  { "fi", FI },
  { "case", CASE },
  { "esac", ESAC },
  { "for", FOR },
#if defined (SELECT_COMMAND)
  { "select", SELECT },
#endif
  { "while", WHILE },
  { "until", UNTIL },
  { "do", DO },
  { "done", DONE },
  { "in", IN },
  { "function", FUNCTION },
#if defined (COMMAND_TIMING)
  { "time", TIME },
#endif
  { "{", '{' },
  { "}", '}' },
  { "!", BANG },
#if defined (COND_COMMAND)
  { "[[", COND_START },
  { "]]", COND_END },
#endif
  { (char *)NULL, 0}
};

/* XXX - we should also have an alist with strings for other tokens, so we
	 can give more descriptive error messages.  Look at y.tab.h for the
	 other tokens. */

/* These are used by read_token_word, but appear up here so that shell_getc
   can use them to decide when to add otherwise blank lines to the history. */

/* The primary delimiter stack. */
struct dstack dstack = {  (char *)NULL, 0, 0 };

/* A temporary delimiter stack to be used when decoding prompt strings.
   This is needed because command substitutions in prompt strings (e.g., PS2)
   can screw up the parser's quoting state. */
static struct dstack temp_dstack = { (char *)NULL, 0, 0 };

/* Macro for accessing the top delimiter on the stack.  Returns the
   delimiter or zero if none. */
#define current_delimiter(ds) \
  (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)

#define push_delimiter(ds, character) \
  do \
    { \
      if (ds.delimiter_depth + 2 > ds.delimiter_space) \
	ds.delimiters = (char *)xrealloc \
	  (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
      ds.delimiters[ds.delimiter_depth] = character; \
      ds.delimiter_depth++; \
    } \
  while (0)

#define pop_delimiter(ds)	ds.delimiter_depth--

/* Return the next shell input character.  This always reads characters
   from shell_input_line; when that line is exhausted, it is time to
   read the next line.  This is called by read_token when the shell is
   processing normal command input. */

/* This implements one-character lookahead/lookbehind across physical input
   lines, to avoid something being lost because it's pushed back with
   shell_ungetc when we're at the start of a line. */
static int eol_ungetc_lookahead = 0;

static int
shell_getc (remove_quoted_newline)
     int remove_quoted_newline;
{
  register int i;
  int c;
  unsigned char uc;
  static int mustpop = 0;

  QUIT;

  if (eol_ungetc_lookahead)
    {
      c = eol_ungetc_lookahead;
      eol_ungetc_lookahead = 0;
      return (c);
    }

#if defined (ALIAS) || defined (DPAREN_ARITHMETIC)
  /* If shell_input_line[shell_input_line_index] == 0, but there is
     something on the pushed list of strings, then we don't want to go
     off and get another line.  We let the code down below handle it. */

  if (!shell_input_line || ((!shell_input_line[shell_input_line_index]) &&
			    (pushed_string_list == (STRING_SAVER *)NULL)))
#else /* !ALIAS && !DPAREN_ARITHMETIC */
  if (!shell_input_line || !shell_input_line[shell_input_line_index])
#endif /* !ALIAS && !DPAREN_ARITHMETIC */
    {
      line_number++;

    restart_read:

      /* Allow immediate exit if interrupted during input. */
      QUIT;

      i = 0;
      shell_input_line_terminator = 0;

#if defined (JOB_CONTROL)
      /* This can cause a problem when reading a command as the result
	 of a trap, when the trap is called from flush_child.  This call
	 had better not cause jobs to disappear from the job table in
	 that case, or we will have big trouble. */
      notify_and_cleanup ();
#else /* !JOB_CONTROL */
      cleanup_dead_jobs ();
#endif /* !JOB_CONTROL */

#if defined (READLINE)
      if (interactive && bash_input.type != st_string && no_line_editing)
#else
      if (interactive && bash_input.type != st_string)
#endif
	print_prompt ();

      if (bash_input.type == st_stream)
	clearerr (stdin);

      while (1)
	{
	  c = yy_getc ();

	  /* Allow immediate exit if interrupted during input. */
	  QUIT;

	  if (c == '\0')
	    {
#if 0
	      internal_warning ("shell_getc: ignored null byte in input");
#endif
	      continue;
	    }

	  RESIZE_MALLOCED_BUFFER (shell_input_line, i, 2, shell_input_line_size, 256);

	  if (c == EOF)
	    {
	      if (bash_input.type == st_stream)
		clearerr (stdin);

	      if (i == 0)
		shell_input_line_terminator = EOF;

	      shell_input_line[i] = '\0';
	      break;
	    }

	  shell_input_line[i++] = c;

	  if (c == '\n')
	    {
	      shell_input_line[--i] = '\0';
	      current_command_line_count++;
	      break;
	    }
	}

      shell_input_line_index = 0;
      shell_input_line_len = i;		/* == strlen (shell_input_line) */

#if defined (HISTORY)
      if (remember_on_history && shell_input_line && shell_input_line[0])
	{
	  char *expansions;
#  if defined (BANG_HISTORY)
	  int old_hist;

	  /* If the current delimiter is a single quote, we should not be
	     performing history expansion, even if we're on a different
	     line from the original single quote. */
	  old_hist = history_expansion_inhibited;
	  if (current_delimiter (dstack) == '\'')
	    history_expansion_inhibited = 1;
#  endif
	  expansions = pre_process_line (shell_input_line, 1, 1);
#  if defined (BANG_HISTORY)
	  history_expansion_inhibited = old_hist;
#  endif
	  if (expansions != shell_input_line)
	    {
	      free (shell_input_line);
	      shell_input_line = expansions;
	      shell_input_line_len = shell_input_line ?
					strlen (shell_input_line) : 0;
	      if (!shell_input_line_len)
		current_command_line_count--;

	      /* We have to force the xrealloc below because we don't know
		 the true allocated size of shell_input_line anymore. */
	      shell_input_line_size = shell_input_line_len;
	    }
	}
      /* Try to do something intelligent with blank lines encountered while
	 entering multi-line commands.  XXX - this is grotesque */
      else if (remember_on_history && shell_input_line &&
	       shell_input_line[0] == '\0' &&
	       current_command_line_count > 1)
	{
	  if (current_delimiter (dstack))
	    /* We know shell_input_line[0] == 0 and we're reading some sort of
	       quoted string.  This means we've got a line consisting of only
	       a newline in a quoted string.  We want to make sure this line
	       gets added to the history. */
	    maybe_add_history (shell_input_line);
	  else
	    {
	      char *hdcs;
	      hdcs = history_delimiting_chars ();
	      if (hdcs && hdcs[0] == ';')
		maybe_add_history (shell_input_line);
	    }
	}

#endif /* HISTORY */

      if (shell_input_line)
	{
	  /* Lines that signify the end of the shell's input should not be
	     echoed. */
	  if (echo_input_at_read && (shell_input_line[0] ||
				     shell_input_line_terminator != EOF))
	    fprintf (stderr, "%s\n", shell_input_line);
	}
      else
	{
	  shell_input_line_size = 0;
	  prompt_string_pointer = &current_prompt_string;
	  prompt_again ();
	  goto restart_read;
	}

      /* Add the newline to the end of this string, iff the string does
	 not already end in an EOF character.  */
      if (shell_input_line_terminator != EOF)
	{
	  if (shell_input_line_len + 3 > shell_input_line_size)
	    shell_input_line = (char *)xrealloc (shell_input_line,
					1 + (shell_input_line_size += 2));

	  shell_input_line[shell_input_line_len] = '\n';
	  shell_input_line[shell_input_line_len + 1] = '\0';
	}
    }

  uc = shell_input_line[shell_input_line_index];

  if (uc)
    shell_input_line_index++;

  if (uc == '\\' && remove_quoted_newline &&
      shell_input_line[shell_input_line_index] == '\n')
    {
	prompt_again ();
	line_number++;
	goto restart_read;
    }

#if defined (ALIAS) || defined (DPAREN_ARITHMETIC)
  /* If UC is NULL, we have reached the end of the current input string.  If
     pushed_string_list is non-empty, it's time to pop to the previous string
     because we have fully consumed the result of the last alias expansion.
     Do it transparently; just return the next character of the string popped
     to. */
  if (!uc && (pushed_string_list != (STRING_SAVER *)NULL))
    {
      if (mustpop)
	{
	  pop_string ();
	  uc = shell_input_line[shell_input_line_index];
	  if (uc)
	    shell_input_line_index++;
	  mustpop--;
	}
      else
	{
	  mustpop++;
	  uc = ' ';
	}
    }
#endif /* ALIAS || DPAREN_ARITHMETIC */

  if (!uc && shell_input_line_terminator == EOF)
    return ((shell_input_line_index != 0) ? '\n' : EOF);

  return (uc);
}

/* Put C back into the input for the shell. */
static void
shell_ungetc (c)
     int c;
{
  if (shell_input_line && shell_input_line_index)
    shell_input_line[--shell_input_line_index] = c;
  else
    eol_ungetc_lookahead = c;
}

#ifdef INCLUDE_UNUSED
/* Back the input pointer up by one, effectively `ungetting' a character. */
static void
shell_ungetchar ()
{
  if (shell_input_line && shell_input_line_index)
    shell_input_line_index--;
}
#endif

/* Discard input until CHARACTER is seen, then push that character back
   onto the input stream. */
static void
discard_until (character)
     int character;
{
  int c;

  while ((c = shell_getc (0)) != EOF && c != character)
    ;

  if (c != EOF)
    shell_ungetc (c);
}

void
execute_prompt_command (command)
     char *command;
{
  sh_builtin_func_t *temp_last, *temp_this;
  char *last_lastarg;
  int temp_exit_value, temp_eof_encountered;

  temp_last = last_shell_builtin;
  temp_this = this_shell_builtin;
  temp_exit_value = last_command_exit_value;
  temp_eof_encountered = eof_encountered;
  last_lastarg = get_string_value ("_");
  if (last_lastarg)
    last_lastarg = savestring (last_lastarg);

  parse_and_execute (savestring (command), "PROMPT_COMMAND", SEVAL_NONINT|SEVAL_NOHIST);

  last_shell_builtin = temp_last;
  this_shell_builtin = temp_this;
  last_command_exit_value = temp_exit_value;
  eof_encountered = temp_eof_encountered;

  bind_variable ("_", last_lastarg);
  FREE (last_lastarg);

  if (token_to_read == '\n')	/* reset_parser was called */
    token_to_read = 0;
}

/* Place to remember the token.  We try to keep the buffer
   at a reasonable size, but it can grow. */
static char *token = (char *)NULL;

/* Current size of the token buffer. */
static int token_buffer_size;

/* Command to read_token () explaining what we want it to do. */
#define READ 0
#define RESET 1
#define prompt_is_ps1 \
      (!prompt_string_pointer || prompt_string_pointer == &ps1_prompt)

/* Function for yyparse to call.  yylex keeps track of
   the last two tokens read, and calls read_token.  */
static int
yylex ()
{
  if (interactive && (current_token == 0 || current_token == '\n'))
    {
      /* Before we print a prompt, we might have to check mailboxes.
	 We do this only if it is time to do so. Notice that only here
	 is the mail alarm reset; nothing takes place in check_mail ()
	 except the checking of mail.  Please don't change this. */
      if (prompt_is_ps1 && time_to_check_mail ())
	{
	  check_mail ();
	  reset_mail_timer ();
	}

      /* Avoid printing a prompt if we're not going to read anything, e.g.
	 after resetting the parser with read_token (RESET). */
      if (token_to_read == 0 && interactive)
	prompt_again ();
    }

  two_tokens_ago = token_before_that;
  token_before_that = last_read_token;
  last_read_token = current_token;
  current_token = read_token (READ);
  return (current_token);
}

/* When non-zero, we have read the required tokens
   which allow ESAC to be the next one read. */
static int esacs_needed_count;

void
gather_here_documents ()
{
  int r = 0;
  while (need_here_doc)
    {
      make_here_document (redir_stack[r++]);
      need_here_doc--;
    }
}

/* When non-zero, an open-brace used to create a group is awaiting a close
   brace partner. */
static int open_brace_count;

#define command_token_position(token) \
  (((token) == ASSIGNMENT_WORD) || \
   ((token) != SEMI_SEMI && reserved_word_acceptable(token)))

#define assignment_acceptable(token) command_token_position(token) && \
					((parser_state & PST_CASEPAT) == 0)

/* Check to see if TOKEN is a reserved word and return the token
   value if it is. */
#define CHECK_FOR_RESERVED_WORD(tok) \
  do { \
    if (!dollar_present && !quoted && \
	reserved_word_acceptable (last_read_token)) \
      { \
	int i; \
	for (i = 0; word_token_alist[i].word != (char *)NULL; i++) \
	  if (STREQ (tok, word_token_alist[i].word)) \
	    { \
	      if ((parser_state & PST_CASEPAT) && (word_token_alist[i].token != ESAC)) \
		break; \
	      if (word_token_alist[i].token == TIME) \
		break; \
	      if (word_token_alist[i].token == ESAC) \
		parser_state &= ~(PST_CASEPAT|PST_CASESTMT); \
	      else if (word_token_alist[i].token == CASE) \
		parser_state |= PST_CASESTMT; \
	      else if (word_token_alist[i].token == COND_END) \
		parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
	      else if (word_token_alist[i].token == COND_START) \
		parser_state |= PST_CONDCMD; \
	      else if (word_token_alist[i].token == '{') \
		open_brace_count++; \
	      else if (word_token_alist[i].token == '}' && open_brace_count) \
		open_brace_count--; \
	      return (word_token_alist[i].token); \
	    } \
      } \
  } while (0)

#if defined (ALIAS)

    /* OK, we have a token.  Let's try to alias expand it, if (and only if)
       it's eligible.

       It is eligible for expansion if the shell is in interactive mode, and
       the token is unquoted and the last token read was a command
       separator (or expand_next_token is set), and we are currently
       processing an alias (pushed_string_list is non-empty) and this
       token is not the same as the current or any previously
       processed alias.

       Special cases that disqualify:
	 In a pattern list in a case statement (parser_state & PST_CASEPAT). */
static int
alias_expand_token (tokstr)
     char *tokstr;
{
  char *expanded;
  alias_t *ap;

  if (((parser_state & PST_ALEXPNEXT) || command_token_position (last_read_token)) &&
	(parser_state & PST_CASEPAT) == 0)
    {
      ap = find_alias (tokstr);

      /* Currently expanding this token. */
      if (ap && (ap->flags & AL_BEINGEXPANDED))
	return (NO_EXPANSION);

      expanded = ap ? savestring (ap->value) : (char *)NULL;
      if (expanded)
	{
	  push_string (expanded, ap->flags & AL_EXPANDNEXT, ap);
	  return (RE_READ_TOKEN);
	}
      else
	/* This is an eligible token that does not have an expansion. */
	return (NO_EXPANSION);
    }
  return (NO_EXPANSION);
}
#endif /* ALIAS */

static int
time_command_acceptable ()
{
#if defined (COMMAND_TIMING)
  switch (last_read_token)
    {
    case 0:
    case ';':
    case '\n':
    case AND_AND:
    case OR_OR:
    case '&':
    case DO:
    case THEN:
    case ELSE:
    case '{':		/* } */
    case '(':		/* ) */
      return 1;
    default:
      return 0;
    }
#else
  return 0;
#endif /* COMMAND_TIMING */
}

/* Handle special cases of token recognition:
	IN is recognized if the last token was WORD and the token
	before that was FOR or CASE or SELECT.

	DO is recognized if the last token was WORD and the token
	before that was FOR or SELECT.

	ESAC is recognized if the last token caused `esacs_needed_count'
	to be set

	`{' is recognized if the last token as WORD and the token
	before that was FUNCTION, or if we just parsed an arithmetic
	`for' command.

	`}' is recognized if there is an unclosed `{' present.

	`-p' is returned as TIMEOPT if the last read token was TIME.

	']]' is returned as COND_END if the parser is currently parsing
	a conditional expression ((parser_state & PST_CONDEXPR) != 0)

	`time' is returned as TIME if and only if it is immediately
	preceded by one of `;', `\n', `||', `&&', or `&'.
*/

static int
special_case_tokens (tokstr)
     char *tokstr;
{
  if ((last_read_token == WORD) &&
#if defined (SELECT_COMMAND)
      ((token_before_that == FOR) || (token_before_that == CASE) || (token_before_that == SELECT)) &&
#else
      ((token_before_that == FOR) || (token_before_that == CASE)) &&
#endif
      (tokstr[0] == 'i' && tokstr[1] == 'n' && tokstr[2] == 0))
    {
      if (token_before_that == CASE)
	{
	  parser_state |= PST_CASEPAT;
	  esacs_needed_count++;
	}
      return (IN);
    }

  if (last_read_token == WORD &&
#if defined (SELECT_COMMAND)
      (token_before_that == FOR || token_before_that == SELECT) &&
#else
      (token_before_that == FOR) &&
#endif
      (tokstr[0] == 'd' && tokstr[1] == 'o' && tokstr[2] == '\0'))
    return (DO);

  /* Ditto for ESAC in the CASE case.
     Specifically, this handles "case word in esac", which is a legal
     construct, certainly because someone will pass an empty arg to the
     case construct, and we don't want it to barf.  Of course, we should
     insist that the case construct has at least one pattern in it, but
     the designers disagree. */
  if (esacs_needed_count)
    {
      esacs_needed_count--;
      if (STREQ (tokstr, "esac"))
	{
	  parser_state &= ~PST_CASEPAT;
	  return (ESAC);
	}
    }

  /* The start of a shell function definition. */
  if (parser_state & PST_ALLOWOPNBRC)
    {
      parser_state &= ~PST_ALLOWOPNBRC;
      if (tokstr[0] == '{' && tokstr[1] == '\0')		/* } */
	{
	  open_brace_count++;
	  function_bstart = line_number;
	  return ('{');					/* } */
	}
    }

  /* We allow a `do' after a for ((...)) without an intervening
     list_terminator */
  if (last_read_token == ARITH_FOR_EXPRS && tokstr[0] == 'd' && tokstr[1] == 'o' && !tokstr[2])
    return (DO);
  if (last_read_token == ARITH_FOR_EXPRS && tokstr[0] == '{' && tokstr[1] == '\0')	/* } */
    {
      open_brace_count++;
      return ('{');			/* } */
    }

  if (open_brace_count && reserved_word_acceptable (last_read_token) && tokstr[0] == '}' && !tokstr[1])
    {
      open_brace_count--;		/* { */
      return ('}');
    }

#if defined (COMMAND_TIMING)
  /* Handle -p after `time'. */
  if (last_read_token == TIME && tokstr[0] == '-' && tokstr[1] == 'p' && !tokstr[2])
    return (TIMEOPT);
#endif

#if defined (COMMAND_TIMING)
  if (STREQ (token, "time") && ((parser_state & PST_CASEPAT) == 0) && time_command_acceptable ())
    return (TIME);
#endif /* COMMAND_TIMING */

#if defined (COND_COMMAND) /* [[ */
  if ((parser_state & PST_CONDEXPR) && tokstr[0] == ']' && tokstr[1] == ']' && tokstr[2] == '\0')
    return (COND_END);
#endif

  return (-1);
}

/* Called from shell.c when Control-C is typed at top level.  Or
   by the error rule at top level. */
void
reset_parser ()
{
  dstack.delimiter_depth = 0;	/* No delimiters found so far. */
  open_brace_count = 0;

  parser_state = 0;

#if defined (ALIAS) || defined (DPAREN_ARITHMETIC)
  if (pushed_string_list)
    free_string_list ();
#endif /* ALIAS || DPAREN_ARITHMETIC */

  if (shell_input_line)
    {
      free (shell_input_line);
      shell_input_line = (char *)NULL;
      shell_input_line_size = shell_input_line_index = 0;
    }

  FREE (word_desc_to_read);
  word_desc_to_read = (WORD_DESC *)NULL;

  last_read_token = '\n';
  token_to_read = '\n';
}

/* Read the next token.  Command can be READ (normal operation) or
   RESET (to normalize state). */
static int
read_token (command)
     int command;
{
  int character;		/* Current character. */
  int peek_char;		/* Temporary look-ahead character. */
  int result;			/* The thing to return. */

  if (command == RESET)
    {
      reset_parser ();
      return ('\n');
    }

  if (token_to_read)
    {
      result = token_to_read;
      if (token_to_read == WORD || token_to_read == ASSIGNMENT_WORD)
	{
	  yylval.word = word_desc_to_read;
	  word_desc_to_read = (WORD_DESC *)NULL;
	}
      token_to_read = 0;
      return (result);
    }

#if defined (COND_COMMAND)
  if ((parser_state & (PST_CONDCMD|PST_CONDEXPR)) == PST_CONDCMD)
    {
      cond_lineno = line_number;
      parser_state |= PST_CONDEXPR;
      yylval.command = parse_cond_command ();
      if (cond_token != COND_END)
	{
	  if (EOF_Reached && cond_token != COND_ERROR)		/* [[ */
	    parser_error (cond_lineno, "unexpected EOF while looking for `]]'");
	  else if (cond_token != COND_ERROR)
	    parser_error (cond_lineno, "syntax error in conditional expression");
	  return (-1);
	}
      token_to_read = COND_END;
      parser_state &= ~(PST_CONDEXPR|PST_CONDCMD);
      return (COND_CMD);
    }
#endif

#if defined (ALIAS)
  /* This is a place to jump back to once we have successfully expanded a
     token with an alias and pushed the string with push_string () */
 re_read_token:
#endif /* ALIAS */

  /* Read a single word from input.  Start by skipping blanks. */
  while ((character = shell_getc (1)) != EOF && whitespace (character))
    ;

  if (character == EOF)
    {
      EOF_Reached = 1;
      return (yacc_EOF);
    }

  if (character == '#' && (!interactive || interactive_comments))
    {
      /* A comment.  Discard until EOL or EOF, and then return a newline. */
      discard_until ('\n');
      shell_getc (0);
      character = '\n';	/* this will take the next if statement and return. */
    }

  if (character == '\n')
    {
      /* If we're about to return an unquoted newline, we can go and collect
	 the text of any pending here document. */
      if (need_here_doc)
	gather_here_documents ();

#if defined (ALIAS)
      parser_state &= ~PST_ALEXPNEXT;
#endif /* ALIAS */

      return (character);
    }

  /* Shell meta-characters. */
  if (shellmeta (character) && ((parser_state & PST_DBLPAREN) == 0))
    {
#if defined (ALIAS)
      /* Turn off alias tokenization iff this character sequence would
	 not leave us ready to read a command. */
      if (character == '<' || character == '>')
	parser_state &= ~PST_ALEXPNEXT;
#endif /* ALIAS */

      peek_char = shell_getc (1);
      if (character == peek_char)
	{
	  switch (character)
	    {
	    case '<':
	      /* If '<' then we could be at "<<" or at "<<-".  We have to
		 look ahead one more character. */
	      peek_char = shell_getc (1);
	      if (peek_char == '-')
		return (LESS_LESS_MINUS);
	      else
		{
		  shell_ungetc (peek_char);
		  return (LESS_LESS);
		}

	    case '>':
	      return (GREATER_GREATER);

	    case ';':
	      parser_state |= PST_CASEPAT;
#if defined (ALIAS)
	      parser_state &= ~PST_ALEXPNEXT;
#endif /* ALIAS */
	      return (SEMI_SEMI);

	    case '&':
	      return (AND_AND);

	    case '|':
	      return (OR_OR);

#if defined (DPAREN_ARITHMETIC) || defined (ARITH_FOR_COMMAND)
	    case '(':		/* ) */
#  if defined (ARITH_FOR_COMMAND)
	      if (last_read_token == FOR)
		{
		  int cmdtyp, len;
		  char *wval, *wv2;
		  WORD_DESC *wd;

		  arith_for_lineno = line_number;
		  cmdtyp = parse_arith_cmd (&wval);
		  if (cmdtyp == 1)
		    {
		      /* parse_arith_cmd adds quotes at the beginning and end
			 of the string it returns; we need to take those out. */
		      len = strlen (wval);
		      wv2 = (char *)xmalloc (len);
		      strncpy (wv2, wval + 1, len - 2);
		      wv2[len - 2] = '\0';
		      wd = make_word (wv2);
		      yylval.word_list = make_word_list (wd, (WORD_LIST *)NULL);
		      free (wval);
		      free (wv2);
		      return (ARITH_FOR_EXPRS);
		    }
		  else
		    return -1;		/* ERROR */
		}
#  endif
#  if defined (DPAREN_ARITHMETIC)
	      if (reserved_word_acceptable (last_read_token))
		{
		  int cmdtyp, sline;
		  char *wval;
		  WORD_DESC *wd;

		  sline = line_number;
		  cmdtyp = parse_arith_cmd (&wval);
		  if (cmdtyp == 1)	/* arithmetic command */
		    {
		      wd = make_word (wval);
		      wd->flags = W_QUOTED;
		      yylval.word_list = make_word_list (wd, (WORD_LIST *)NULL);
		      free (wval);	/* make_word copies it */
		      return (ARITH_CMD);
		    }
		  else if (cmdtyp == 0)	/* nested subshell */
		    {
		      push_string (wval, 0, (alias_t *)NULL);
		      if ((parser_state & PST_CASEPAT) == 0)
			parser_state |= PST_SUBSHELL;
		      return (character);
		    }
		  else			/* ERROR */
		    return -1;
		}
	      break;
#  endif
#endif
	    }
	}
      else if (character == '<' && peek_char == '&')
	return (LESS_AND);
      else if (character == '>' && peek_char == '&')
	return (GREATER_AND);
      else if (character == '<' && peek_char == '>')
	return (LESS_GREATER);
      else if (character == '>' && peek_char == '|')
	return (GREATER_BAR);
      else if (peek_char == '>' && character == '&')
	return (AND_GREATER);

      shell_ungetc (peek_char);

      /* If we look like we are reading the start of a function
	 definition, then let the reader know about it so that
	 we will do the right thing with `{'. */
      if (character == ')' && last_read_token == '(' && token_before_that == WORD)
	{
	  parser_state |= PST_ALLOWOPNBRC;
#if defined (ALIAS)
	  parser_state &= ~PST_ALEXPNEXT;
#endif /* ALIAS */
	  function_dstart = line_number;
	}

      /* case pattern lists may be preceded by an optional left paren.  If
	 we're not trying to parse a case pattern list, the left paren
	 indicates a subshell. */
      if (character == '(' && (parser_state & PST_CASEPAT) == 0) /* ) */
	parser_state |= PST_SUBSHELL;
      /*(*/
      else if ((parser_state & PST_CASEPAT) && character == ')')
	parser_state &= ~PST_CASEPAT;
      /*(*/
      else if ((parser_state & PST_SUBSHELL) && character == ')')
	parser_state &= ~PST_SUBSHELL;

#if defined (PROCESS_SUBSTITUTION)
      /* Check for the constructs which introduce process substitution.
	 Shells running in `posix mode' don't do process substitution. */
      if (posixly_correct ||
	  ((character != '>' && character != '<') || peek_char != '('))
#endif /* PROCESS_SUBSTITUTION */
	return (character);
    }

  /* Hack <&- (close stdin) case. */
  if (character == '-' && (last_read_token == LESS_AND || last_read_token == GREATER_AND))
    return (character);

  /* Okay, if we got this far, we have to read a word.  Read one,
     and then check it against the known ones. */
  result = read_token_word (character);
#if defined (ALIAS)
  if (result == RE_READ_TOKEN)
    goto re_read_token;
#endif
  return result;
}

/* Match a $(...) or other grouping construct.  This has to handle embedded
   quoted strings ('', ``, "") and nested constructs.  It also must handle
   reprompting the user, if necessary, after reading a newline, and returning
   correct error values if it reads EOF. */

#define P_FIRSTCLOSE	0x01
#define P_ALLOWESC	0x02

static char matched_pair_error;
static char *
parse_matched_pair (qc, open, close, lenp, flags)
     int qc;	/* `"' if this construct is within double quotes */
     int open, close;
     int *lenp, flags;
{
  int count, ch, was_dollar;
  int pass_next_character, nestlen, ttranslen, start_lineno;
  char *ret, *nestret, *ttrans;
  int retind, retsize;

  count = 1;
  pass_next_character = was_dollar = 0;

  ret = (char *)xmalloc (retsize = 64);
  retind = 0;

  start_lineno = line_number;
  while (count)
    {
      ch = shell_getc ((qc != '\'' || (flags & P_ALLOWESC)) && pass_next_character == 0);
      if (ch == EOF)
	{
	  free (ret);
	  parser_error (start_lineno, "unexpected EOF while looking for matching `%c'", close);
	  EOF_Reached = 1;	/* XXX */
	  return (&matched_pair_error);
	}

      /* Possible reprompting. */
      if (ch == '\n' && interactive &&
	    (bash_input.type == st_stdin || bash_input.type == st_stream))
	prompt_again ();

      if (pass_next_character)		/* last char was backslash */
	{
	  pass_next_character = 0;
	  if (qc != '\'' && ch == '\n')	/* double-quoted \<newline> disappears. */
	    {
	      if (retind > 0) retind--;	/* swallow previously-added backslash */
	      continue;
	    }

	  RESIZE_MALLOCED_BUFFER (ret, retind, 2, retsize, 64);
	  if (ch == CTLESC || ch == CTLNUL)
	    ret[retind++] = CTLESC;
	  ret[retind++] = ch;
	  continue;
	}
      else if (ch == CTLESC || ch == CTLNUL)	/* special shell escapes */
	{
	  RESIZE_MALLOCED_BUFFER (ret, retind, 2, retsize, 64);
	  ret[retind++] = CTLESC;
	  ret[retind++] = ch;
	  continue;
	}
      else if (ch == close)		/* ending delimiter */
	count--;
#if 1
      /* handle nested ${...} specially. */
      else if (open != close && was_dollar && open == '{' && ch == open) /* } */
	count++;
#endif
      else if (((flags & P_FIRSTCLOSE) == 0) && ch == open)		/* nested begin */
	count++;

      /* Add this character. */
      RESIZE_MALLOCED_BUFFER (ret, retind, 1, retsize, 64);
      ret[retind++] = ch;

      if (open == '\'')			/* '' inside grouping construct */
	{
	  if ((flags & P_ALLOWESC) && ch == '\\')
	    pass_next_character++;
	  continue;
	}

      if (ch == '\\')			/* backslashes */
	pass_next_character++;

      if (open != close)		/* a grouping construct */
	{
	  if (shellquote (ch))
	    {
	      /* '', ``, or "" inside $(...) or other grouping construct. */
	      push_delimiter (dstack, ch);
	      if (was_dollar && ch == '\'')	/* $'...' inside group */
		nestret = parse_matched_pair (ch, ch, ch, &nestlen, P_ALLOWESC);
	      else
		nestret = parse_matched_pair (ch, ch, ch, &nestlen, 0);
	      pop_delimiter (dstack);
	      if (nestret == &matched_pair_error)
		{
		  free (ret);
		  return &matched_pair_error;
		}
	      if (was_dollar && ch == '\'')
		{
		  /* Translate $'...' here. */
		  ttrans = ansiexpand (nestret, 0, nestlen - 1, &ttranslen);
		  xfree (nestret);
		  nestret = sh_single_quote (ttrans);
		  free (ttrans);
		  nestlen = strlen (nestret);
		  retind -= 2;		/* back up before the $' */
		}
	      else if (was_dollar && ch == '"')
		{
		  /* Locale expand $"..." here. */
		  ttrans = localeexpand (nestret, 0, nestlen - 1, start_lineno, &ttranslen);
		  xfree (nestret);
		  nestret = (char *)xmalloc (ttranslen + 3);
		  nestret[0] = '"';
		  strcpy (nestret + 1, ttrans);
		  nestret[ttranslen + 1] = '"';
		  nestret[ttranslen += 2] = '\0';
		  free (ttrans);
		  nestlen = ttranslen;
		  retind -= 2;		/* back up before the $" */
		}
	      if (nestlen)
		{
		  RESIZE_MALLOCED_BUFFER (ret, retind, nestlen, retsize, 64);
		  strcpy (ret + retind, nestret);
		  retind += nestlen;
		}
	      FREE (nestret);
	    }
	}
      /* Parse an old-style command substitution within double quotes as a
	 single word. */
      /* XXX - sh and ksh93 don't do this - XXX */
      else if (open == '"' && ch == '`')
	{
	  nestret = parse_matched_pair (0, '`', '`', &nestlen, 0);
	  if (nestret == &matched_pair_error)
	    {
	      free (ret);
	      return &matched_pair_error;
	    }
	  if (nestlen)
	    {
	      RESIZE_MALLOCED_BUFFER (ret, retind, nestlen, retsize, 64);
	      strcpy (ret + retind, nestret);
	      retind += nestlen;
	    }
	  FREE (nestret);
	}
      else if (was_dollar && (ch == '(' || ch == '{' || ch == '['))	/* ) } ] */
	/* check for $(), $[], or ${} inside quoted string. */
	{
	  if (open == ch)	/* undo previous increment */
	    count--;
	  if (ch == '(')		/* ) */
	    nestret = parse_matched_pair (0, '(', ')', &nestlen, 0);
	  else if (ch == '{')		/* } */
	    nestret = parse_matched_pair (0, '{', '}', &nestlen, P_FIRSTCLOSE);
	  else if (ch == '[')		/* ] */
	    nestret = parse_matched_pair (0, '[', ']', &nestlen, 0);
	  if (nestret == &matched_pair_error)
	    {
	      free (ret);
	      return &matched_pair_error;
	    }
	  if (nestlen)
	    {
	      RESIZE_MALLOCED_BUFFER (ret, retind, nestlen, retsize, 64);
	      strcpy (ret + retind, nestret);
	      retind += nestlen;
	    }
	  FREE (nestret);
	}
      was_dollar = (ch == '$');
    }

  ret[retind] = '\0';
  if (lenp)
    *lenp = retind;
  return ret;
}

#if defined (DPAREN_ARITHMETIC) || defined (ARITH_FOR_COMMAND)
/* We've seen a `(('.  Look for the matching `))'.  If we get it, return 1.
   If not, assume it's a nested subshell for backwards compatibility and
   return 0.  In any case, put the characters we've consumed into a locally-
   allocated buffer and make *ep point to that buffer.  Return -1 on an
   error, for example EOF. */
static int
parse_arith_cmd (ep)
     char **ep;
{
  int exp_lineno, rval, c;
  char *ttok, *tokstr;
  int ttoklen;

  exp_lineno = line_number;
  ttok = parse_matched_pair (0, '(', ')', &ttoklen, 0);
  rval = 1;
  if (ttok == &matched_pair_error)
    return -1;
  /* Check that the next character is the closing right paren.  If
     not, this is a syntax error. ( */
  if ((c = shell_getc (0)) != ')')
    rval = 0;

  tokstr = (char *)xmalloc (ttoklen + 4);

  /* (( ... )) -> "..." */
  tokstr[0] = (rval == 1) ? '"' : '(';
  strncpy (tokstr + 1, ttok, ttoklen - 1);	/* don't copy the final `)' */
  if (rval == 1)
    {
      tokstr[ttoklen] = '"';
      tokstr[ttoklen+1] = '\0';
    }
  else
    {
      tokstr[ttoklen] = ')';
      tokstr[ttoklen+1] = c;
      tokstr[ttoklen+2] = '\0';
    }
  *ep = tokstr;
  FREE (ttok);
  return rval;
}
#endif /* DPAREN_ARITHMETIC || ARITH_FOR_COMMAND */

#if defined (COND_COMMAND)
static COND_COM *
cond_expr ()
{
  return (cond_or ());  
}

static COND_COM *
cond_or ()
{
  COND_COM *l, *r;

  l = cond_and ();
  if (cond_token == OR_OR)
    {
      r = cond_or ();
      l = make_cond_node (COND_OR, (WORD_DESC *)NULL, l, r);
    }
  return l;
}

static COND_COM *
cond_and ()
{
  COND_COM *l, *r;

  l = cond_term ();
  if (cond_token == AND_AND)
    {
      r = cond_and ();
      l = make_cond_node (COND_AND, (WORD_DESC *)NULL, l, r);
    }
  return l;
}

static int
cond_skip_newlines ()
{
  while ((cond_token = read_token (READ)) == '\n')
    {
      if (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
	prompt_again ();
    }
  return (cond_token);
}

#define COND_RETURN_ERROR() \
  do { cond_token = COND_ERROR; return ((COND_COM *)NULL); } while (0)

static COND_COM *
cond_term ()
{
  WORD_DESC *op;
  COND_COM *term, *tleft, *tright;
  int tok, lineno;

  /* Read a token.  It can be a left paren, a `!', a unary operator, or a
     word that should be the first argument of a binary operator.  Start by
     skipping newlines, since this is a compound command. */
  tok = cond_skip_newlines ();
  lineno = line_number;
  if (tok == COND_END)
    {
      COND_RETURN_ERROR ();
    }
  else if (tok == '(')
    {
      term = cond_expr ();
      if (cond_token != ')')
	{
	  if (term)
	    dispose_cond_node (term);		/* ( */
	  parser_error (lineno, "expected `)'");
	  COND_RETURN_ERROR ();
	}
      term = make_cond_node (COND_EXPR, (WORD_DESC *)NULL, term, (COND_COM *)NULL);
      (void)cond_skip_newlines ();
    }
  else if (tok == BANG || (tok == WORD && (yylval.word->word[0] == '!' && yylval.word->word[1] == '\0')))
    {
      if (tok == WORD)
	dispose_word (yylval.word);	/* not needed */
      term = cond_term ();
      if (term)
	term->flags |= CMD_INVERT_RETURN;
    }
  else if (tok == WORD && test_unop (yylval.word->word))
    {
      op = yylval.word;
      tok = read_token (READ);
      if (tok == WORD)
	{
	  tleft = make_cond_node (COND_TERM, yylval.word, (COND_COM *)NULL, (COND_COM *)NULL);
	  term = make_cond_node (COND_UNARY, op, tleft, (COND_COM *)NULL);
	}
      else
	{
	  dispose_word (op);
	  parser_error (line_number, "unexpected argument to conditional unary operator");
	  COND_RETURN_ERROR ();
	}

      (void)cond_skip_newlines ();
    }
  else if (tok == WORD)		/* left argument to binary operator */
    {
      /* lhs */
      tleft = make_cond_node (COND_TERM, yylval.word, (COND_COM *)NULL, (COND_COM *)NULL);

      /* binop */
      tok = read_token (READ);
      if (tok == WORD && test_binop (yylval.word->word))
	op = yylval.word;
      else if (tok == '<' || tok == '>')
	op = make_word_from_token (tok);  /* ( */
      /* There should be a check before blindly accepting the `)' that we have
	 seen the opening `('. */
      else if (tok == COND_END || tok == AND_AND || tok == OR_OR || tok == ')')
	{
	  /* Special case.  [[ x ]] is equivalent to [[ -n x ]], just like
	     the test command.  Similarly for [[ x && expr ]] or
	     [[ x || expr ]] or [[ (x) ]]. */
	  op = make_word ("-n");
	  term = make_cond_node (COND_UNARY, op, tleft, (COND_COM *)NULL);
	  cond_token = tok;
	  return (term);
	}
      else
	{
	  parser_error (line_number, "conditional binary operator expected");
	  dispose_cond_node (tleft);
	  COND_RETURN_ERROR ();
	}

      /* rhs */
      tok = read_token (READ);
      if (tok == WORD)
	{
	  tright = make_cond_node (COND_TERM, yylval.word, (COND_COM *)NULL, (COND_COM *)NULL);
	  term = make_cond_node (COND_BINARY, op, tleft, tright);
	}
      else
	{
	  parser_error (line_number, "unexpected argument to conditional binary operator");
	  dispose_cond_node (tleft);
	  dispose_word (op);
	  COND_RETURN_ERROR ();
	}

      (void)cond_skip_newlines ();
    }
  else
    {
      if (tok < 256)
	parser_error (line_number, "unexpected token `%c' in conditional command", tok);
      else
	parser_error (line_number, "unexpected token %d in conditional command", tok);
      COND_RETURN_ERROR ();
    }
  return (term);
}      

/* This is kind of bogus -- we slip a mini recursive-descent parser in
   here to handle the conditional statement syntax. */
static COMMAND *
parse_cond_command ()
{
  COND_COM *cexp;

  cexp = cond_expr ();
  return (make_cond_command (cexp));
}
#endif

static int
read_token_word (character)
     int character;
{
  /* The value for YYLVAL when a WORD is read. */
  WORD_DESC *the_word;

  /* Index into the token that we are building. */
  int token_index;

  /* ALL_DIGITS becomes zero when we see a non-digit. */
  int all_digit_token;

  /* DOLLAR_PRESENT becomes non-zero if we see a `$'. */
  int dollar_present;

  /* QUOTED becomes non-zero if we see one of ("), ('), (`), or (\). */
  int quoted;

  /* Non-zero means to ignore the value of the next character, and just
     to add it no matter what. */
 int pass_next_character;

  /* The current delimiting character. */
  int cd;
  int result, peek_char;
  char *ttok, *ttrans;
  int ttoklen, ttranslen;
  long lvalue;

  if (token_buffer_size < TOKEN_DEFAULT_INITIAL_SIZE)
    token = (char *)xrealloc (token, token_buffer_size = TOKEN_DEFAULT_INITIAL_SIZE);

  token_index = 0;
  all_digit_token = DIGIT (character);
  dollar_present = quoted = pass_next_character = 0;

  for (;;)
    {
      if (character == EOF)
	goto got_token;

      if (pass_next_character)
	{
	  pass_next_character = 0;
	  goto got_character;
	}

      cd = current_delimiter (dstack);

      /* Handle backslashes.  Quote lots of things when not inside of
	 double-quotes, quote some things inside of double-quotes. */
      if (character == '\\')
	{
	  peek_char = shell_getc (0);

	  /* Backslash-newline is ignored in all cases except
	     when quoted with single quotes. */
	  if (peek_char == '\n')
	    {
	      character = '\n';
	      goto next_character;
	    }
	  else
	    {
	      shell_ungetc (peek_char);

	      /* If the next character is to be quoted, note it now. */
	      if (cd == 0 || cd == '`' ||
		  (cd == '"' && peek_char >= 0 && (sh_syntaxtab[peek_char] & CBSDQUOTE)))
		pass_next_character++;

	      quoted = 1;
	      goto got_character;
	    }
	}

      /* Parse a matched pair of quote characters. */
      if (shellquote (character))
	{
	  push_delimiter (dstack, character);
	  ttok = parse_matched_pair (character, character, character, &ttoklen, 0);
	  pop_delimiter (dstack);
	  if (ttok == &matched_pair_error)
	    return -1;		/* Bail immediately. */
	  RESIZE_MALLOCED_BUFFER (token, token_index, ttoklen + 2,
				  token_buffer_size, TOKEN_DEFAULT_GROW_SIZE);
	  token[token_index++] = character;
	  strcpy (token + token_index, ttok);
	  token_index += ttoklen;
	  all_digit_token = 0;
	  quoted = 1;
	  dollar_present |= (character == '"' && strchr (ttok, '$') != 0);
	  FREE (ttok);
	  goto next_character;
	}

#ifdef EXTENDED_GLOB
      /* Parse a ksh-style extended pattern matching specification. */
      if (extended_glob && PATTERN_CHAR (character))
	{
	  peek_char = shell_getc (1);
	  if (peek_char == '(')		/* ) */
	    {
	      push_delimiter (dstack, peek_char);
	      ttok = parse_matched_pair (cd, '(', ')', &ttoklen, 0);
	      pop_delimiter (dstack);
	      if (ttok == &matched_pair_error)
		return -1;		/* Bail immediately. */
	      RESIZE_MALLOCED_BUFFER (token, token_index, ttoklen + 2,
				      token_buffer_size,
				      TOKEN_DEFAULT_GROW_SIZE);
	      token[token_index++] = character;
	      token[token_index++] = peek_char;
	      strcpy (token + token_index, ttok);
	      token_index += ttoklen;
	      FREE (ttok);
	      dollar_present = all_digit_token = 0;
	      goto next_character;
	    }
	  else
	    shell_ungetc (peek_char);
	}
#endif /* EXTENDED_GLOB */

      /* If the delimiter character is not single quote, parse some of
	 the shell expansions that must be read as a single word. */
      if (shellexp (character))
	{
	  peek_char = shell_getc (1);
	  /* $(...), <(...), >(...), $((...)), ${...}, and $[...] constructs */
	  if (peek_char == '(' ||
		((peek_char == '{' || peek_char == '[') && character == '$'))	/* ) ] } */
	    {
	      if (peek_char == '{')		/* } */
		ttok = parse_matched_pair (cd, '{', '}', &ttoklen, P_FIRSTCLOSE);
	      else if (peek_char == '(')		/* ) */
		{
		  /* XXX - push and pop the `(' as a delimiter for use by
		     the command-oriented-history code.  This way newlines
		     appearing in the $(...) string get added to the
		     history literally rather than causing a possibly-
		     incorrect `;' to be added. ) */
		  push_delimiter (dstack, peek_char);
		  ttok = parse_matched_pair (cd, '(', ')', &ttoklen, 0);
		  pop_delimiter (dstack);
		}
	      else
		ttok = parse_matched_pair (cd, '[', ']', &ttoklen, 0);
	      if (ttok == &matched_pair_error)
		return -1;		/* Bail immediately. */
	      RESIZE_MALLOCED_BUFFER (token, token_index, ttoklen + 2,
				      token_buffer_size,
				      TOKEN_DEFAULT_GROW_SIZE);
	      token[token_index++] = character;
	      token[token_index++] = peek_char;
	      strcpy (token + token_index, ttok);
	      token_index += ttoklen;
	      FREE (ttok);
	      dollar_present = 1;
	      all_digit_token = 0;
	      goto next_character;
	    }
	  /* This handles $'...' and $"..." new-style quoted strings. */
	  else if (character == '$' && (peek_char == '\'' || peek_char == '"'))
	    {
	      int first_line;

	      first_line = line_number;
	      push_delimiter (dstack, peek_char);
	      ttok = parse_matched_pair (peek_char, peek_char, peek_char,
					 &ttoklen,
					 (peek_char == '\'') ? P_ALLOWESC : 0);
	      pop_delimiter (dstack);
	      if (ttok == &matched_pair_error)
		return -1;
	      if (peek_char == '\'')
		{
		  ttrans = ansiexpand (ttok, 0, ttoklen - 1, &ttranslen);
		  free (ttok);
		  /* Insert the single quotes and correctly quote any
		     embedded single quotes (allowed because P_ALLOWESC was
		     passed to parse_matched_pair). */
		  ttok = sh_single_quote (ttrans);
		  free (ttrans);
		  ttrans = ttok;
		  ttranslen = strlen (ttrans);
		}
	      else
		{
		  /* Try to locale-expand the converted string. */
		  ttrans = localeexpand (ttok, 0, ttoklen - 1, first_line, &ttranslen);
		  free (ttok);

		  /* Add the double quotes back */
		  ttok = (char *)xmalloc (ttranslen + 3);
		  ttok[0] = '"';
		  strcpy (ttok + 1, ttrans);
		  ttok[ttranslen + 1] = '"';
		  ttok[ttranslen += 2] = '\0';
		  free (ttrans);
		  ttrans = ttok;
		}

	      RESIZE_MALLOCED_BUFFER (token, token_index, ttranslen + 2,
				      token_buffer_size,
				      TOKEN_DEFAULT_GROW_SIZE);
	      strcpy (token + token_index, ttrans);
	      token_index += ttranslen;
	      FREE (ttrans);
	      quoted = 1;
	      all_digit_token = 0;
	      goto next_character;
	    }
	  /* This could eventually be extended to recognize all of the
	     shell's single-character parameter expansions, and set flags.*/
	  else if (character == '$' && peek_char == '$')
	    {
	      ttok = (char *)xmalloc (3);
	      ttok[0] = ttok[1] = '$';
	      ttok[2] = '\0';
	      RESIZE_MALLOCED_BUFFER (token, token_index, 3,
				      token_buffer_size,
				      TOKEN_DEFAULT_GROW_SIZE);
	      strcpy (token + token_index, ttok);
	      token_index += 2;
	      dollar_present = 1;
	      all_digit_token = 0;
	      FREE (ttok);
	      goto next_character;
	    }
	  else
	    shell_ungetc (peek_char);
	}

#if defined (ARRAY_VARS)
      /* Identify possible compound array variable assignment. */
      else if (character == '=' && token_index > 0)
	{
	  peek_char = shell_getc (1);
	  if (peek_char == '(')		/* ) */
	    {
	      ttok = parse_matched_pair (cd, '(', ')', &ttoklen, 0);
	      if (ttok == &matched_pair_error)
		return -1;		/* Bail immediately. */
	      if (ttok[0] == '(')	/* ) */
		{
		  FREE (ttok);
		  return -1;
		}
	      RESIZE_MALLOCED_BUFFER (token, token_index, ttoklen + 2,
				      token_buffer_size,
				      TOKEN_DEFAULT_GROW_SIZE);
	      token[token_index++] = character;
	      token[token_index++] = peek_char;
	      strcpy (token + token_index, ttok);
	      token_index += ttoklen;
	      FREE (ttok);
	      all_digit_token = 0;
	      goto next_character;
	    }
	  else
	    shell_ungetc (peek_char);
	}
#endif

      /* When not parsing a multi-character word construct, shell meta-
	 characters break words. */
      if (shellbreak (character))
	{
	  shell_ungetc (character);
	  goto got_token;
	}

    got_character:

      all_digit_token &= DIGIT (character);
      dollar_present |= character == '$';

      if (character == CTLESC || character == CTLNUL)
	token[token_index++] = CTLESC;

      token[token_index++] = character;

      RESIZE_MALLOCED_BUFFER (token, token_index, 1, token_buffer_size,
			      TOKEN_DEFAULT_GROW_SIZE);

    next_character:
      if (character == '\n' && interactive &&
	(bash_input.type == st_stdin || bash_input.type == st_stream))
	prompt_again ();

      /* We want to remove quoted newlines (that is, a \<newline> pair)
	 unless we are within single quotes or pass_next_character is
	 set (the shell equivalent of literal-next). */
      cd = current_delimiter (dstack);
      character = shell_getc (cd != '\'' && pass_next_character == 0);
    }	/* end for (;;) */

got_token:

  token[token_index] = '\0';

  /* Check to see what thing we should return.  If the last_read_token
     is a `<', or a `&', or the character which ended this token is
     a '>' or '<', then, and ONLY then, is this input token a NUMBER.
     Otherwise, it is just a word, and should be returned as such. */
  if (all_digit_token && (character == '<' || character == '>' ||
		    last_read_token == LESS_AND ||
		    last_read_token == GREATER_AND))
      {
	if (legal_number (token, &lvalue) && (int)lvalue == lvalue)
	  yylval.number = lvalue;
	else
	  yylval.number = -1;
	return (NUMBER);
      }

  /* Check for special case tokens. */
  result = special_case_tokens (token);
  if (result >= 0)
    return result;

#if defined (ALIAS)
  /* Posix.2 does not allow reserved words to be aliased, so check for all
     of them, including special cases, before expanding the current token
     as an alias. */
  if (posixly_correct)
    CHECK_FOR_RESERVED_WORD (token);

  /* Aliases are expanded iff EXPAND_ALIASES is non-zero, and quoting
     inhibits alias expansion. */
  if (expand_aliases && quoted == 0)
    {
      result = alias_expand_token (token);
      if (result == RE_READ_TOKEN)
	return (RE_READ_TOKEN);
      else if (result == NO_EXPANSION)
	parser_state &= ~PST_ALEXPNEXT;
    }

  /* If not in Posix.2 mode, check for reserved words after alias
     expansion. */
  if (posixly_correct == 0)
#endif
    CHECK_FOR_RESERVED_WORD (token);

  the_word = (WORD_DESC *)xmalloc (sizeof (WORD_DESC));
  the_word->word = (char *)xmalloc (1 + token_index);
  the_word->flags = 0;
  strcpy (the_word->word, token);
  if (dollar_present)
    the_word->flags |= W_HASDOLLAR;
  if (quoted)
    the_word->flags |= W_QUOTED;
  /* A word is an assignment if it appears at the beginning of a
     simple command, or after another assignment word.  This is
     context-dependent, so it cannot be handled in the grammar. */
  if (assignment (token))
    {
      the_word->flags |= W_ASSIGNMENT;
      /* Don't perform word splitting on assignment statements. */
      if (assignment_acceptable (last_read_token))
	the_word->flags |= W_NOSPLIT;
    }

  yylval.word = the_word;

  result = ((the_word->flags & (W_ASSIGNMENT|W_NOSPLIT)) == (W_ASSIGNMENT|W_NOSPLIT))
		? ASSIGNMENT_WORD : WORD;

  if (last_read_token == FUNCTION)
    {
      parser_state |= PST_ALLOWOPNBRC;
      function_dstart = line_number;
    }

  return (result);
}

/* $'...' ANSI-C expand the portion of STRING between START and END and
   return the result.  The result cannot be longer than the input string. */
static char *
ansiexpand (string, start, end, lenp)
     char *string;
     int start, end, *lenp;
{
  char *temp, *t;
  int len, tlen;

  temp = (char *)xmalloc (end - start + 1);
  for (tlen = 0, len = start; len < end; )
    temp[tlen++] = string[len++];
  temp[tlen] = '\0';

  if (*temp)
    {
      t = ansicstr (temp, tlen, 0, (int *)NULL, lenp);
      free (temp);
      return (t);
    }
  else
    {
      if (lenp)
	*lenp = 0;
      return (temp);
    }
}

/* Change a bash string into a string suitable for inclusion in a `po' file.
   This backslash-escapes `"' and `\' and changes newlines into \\\n"\n". */
static char *
mk_msgstr (string, foundnlp)
     char *string;
     int *foundnlp;
{
  register int c, len;
  char *result, *r, *s;

  for (len = 0, s = string; s && *s; s++)
    {
      len++;
      if (*s == '"' || *s == '\\')
	len++;
      else if (*s == '\n')
	len += 5;
    }
  
  r = result = (char *)xmalloc (len + 3);
  *r++ = '"';

  for (s = string; s && (c = *s); s++)
    {
      if (c == '\n')	/* <NL> -> \n"<NL>" */
	{
	  *r++ = '\\';
	  *r++ = 'n';
	  *r++ = '"';
	  *r++ = '\n';
	  *r++ = '"';
	  if (foundnlp)
	    *foundnlp = 1;
	  continue;
	}
      if (c == '"' || c == '\\')
	*r++ = '\\';
      *r++ = c;
    }

  *r++ = '"';
  *r++ = '\0';

  return result;
}

/* $"..." -- Translate the portion of STRING between START and END
   according to current locale using gettext (if available) and return
   the result.  The caller will take care of leaving the quotes intact.
   The string will be left without the leading `$' by the caller.
   If translation is performed, the translated string will be double-quoted
   by the caller.  The length of the translated string is returned in LENP,
   if non-null. */
static char *
localeexpand (string, start, end, lineno, lenp)
     char *string;
     int start, end, lineno, *lenp;
{
  int len, tlen, foundnl;
  char *temp, *t, *t2;

  temp = (char *)xmalloc (end - start + 1);
  for (tlen = 0, len = start; len < end; )
    temp[tlen++] = string[len++];
  temp[tlen] = '\0';

  /* If we're just dumping translatable strings, don't do anything with the
     string itself, but if we're dumping in `po' file format, convert it into a form more palatable to gettext(3)
     and friends by quoting `"' and `\' with backslashes and converting <NL>
     into `\n"<NL>"'.  If we find a newline in TEMP, we first output a
     `msgid ""' line and then the translated string; otherwise we output the
     `msgid' and translated string all on one line. */
  if (dump_translatable_strings)
    {
      if (dump_po_strings)
	{
	  foundnl = 0;
	  t = mk_msgstr (temp, &foundnl);
	  t2 = foundnl ? "\"\"\n" : "";

	  printf ("#: %s:%d\nmsgid %s%s\nmsgstr \"\"\n",
		  (bash_input.name ? bash_input.name : "stdin"), lineno, t2, t);
	  free (t);
	}
      else
	printf ("\"%s\"\n", temp);

      if (lenp)
	*lenp = tlen;
      return (temp);
    }
  else if (*temp)
    {
      t = localetrans (temp, tlen, &len);
      free (temp);
      if (lenp)
	*lenp = len;
      return (t);
    }
  else
    {
      if (lenp)
	*lenp = 0;
      return (temp);
    }
}

/* Return 1 if TOKSYM is a token that after being read would allow
   a reserved word to be seen, else 0. */
static int
reserved_word_acceptable (toksym)
     int toksym;
{
  if (toksym == '\n' || toksym == ';' || toksym == '(' || toksym == ')' ||
      toksym == '|' || toksym == '&' || toksym == '{' ||
      toksym == '}' ||			/* XXX */
      toksym == AND_AND ||
      toksym == BANG ||
      toksym == TIME || toksym == TIMEOPT ||
      toksym == DO ||
      toksym == ELIF ||
      toksym == ELSE ||
      toksym == FI ||
      toksym == IF ||
      toksym == OR_OR ||
      toksym == SEMI_SEMI ||
      toksym == THEN ||
      toksym == UNTIL ||
      toksym == WHILE ||
      toksym == DONE ||		/* XXX these two are experimental */
      toksym == ESAC ||
      toksym == 0)
    return (1);
  else
    return (0);
}

/* Return the index of TOKEN in the alist of reserved words, or -1 if
   TOKEN is not a shell reserved word. */
int
find_reserved_word (tokstr)
     char *tokstr;
{
  int i;
  for (i = 0; word_token_alist[i].word; i++)
    if (STREQ (tokstr, word_token_alist[i].word))
      return i;
  return -1;
}

#if 0
#if defined (READLINE)
/* Called after each time readline is called.  This insures that whatever
   the new prompt string is gets propagated to readline's local prompt
   variable. */
static void
reset_readline_prompt ()
{
  char *temp_prompt;

  if (prompt_string_pointer)
    {
      temp_prompt = (*prompt_string_pointer)
			? decode_prompt_string (*prompt_string_pointer)
			: (char *)NULL;

      if (temp_prompt == 0)
	{
	  temp_prompt = (char *)xmalloc (1);
	  temp_prompt[0] = '\0';
	}

      FREE (current_readline_prompt);
      current_readline_prompt = temp_prompt;
    }
}
#endif /* READLINE */
#endif /* 0 */

#if defined (HISTORY)
/* A list of tokens which can be followed by newlines, but not by
   semi-colons.  When concatenating multiple lines of history, the
   newline separator for such tokens is replaced with a space. */
static int no_semi_successors[] = {
  '\n', '{', '(', ')', ';', '&', '|',
  CASE, DO, ELSE, IF, SEMI_SEMI, THEN, UNTIL, WHILE, AND_AND, OR_OR, IN,
  0
};

/* If we are not within a delimited expression, try to be smart
   about which separators can be semi-colons and which must be
   newlines.  Returns the string that should be added into the
   history entry. */
char *
history_delimiting_chars ()
{
  register int i;

  if (dstack.delimiter_depth != 0)
    return ("\n");
    
  /* First, handle some special cases. */
  /*(*/
  /* If we just read `()', assume it's a function definition, and don't
     add a semicolon.  If the token before the `)' was not `(', and we're
     not in the midst of parsing a case statement, assume it's a
     parenthesized command and add the semicolon. */
  /*)(*/
  if (token_before_that == ')')
    {
      if (two_tokens_ago == '(')	/*)*/	/* function def */
	return " ";
      /* This does not work for subshells inside case statement
	 command lists.  It's a suboptimal solution. */
      else if (parser_state & PST_CASESTMT)	/* case statement pattern */
	return " ";
      else	
	return "; ";				/* (...) subshell */
    }
  else if (token_before_that == WORD && two_tokens_ago == FUNCTION)
    return " ";		/* function def using `function name' without `()' */

  else if (token_before_that == WORD && two_tokens_ago == FOR)
    {
      /* Tricky.  `for i\nin ...' should not have a semicolon, but
	 `for i\ndo ...' should.  We do what we can. */
      for (i = shell_input_line_index; whitespace(shell_input_line[i]); i++)
	;
      if (shell_input_line[i] && shell_input_line[i] == 'i' && shell_input_line[i+1] == 'n')
	return " ";
      return ";";
    }

  for (i = 0; no_semi_successors[i]; i++)
    {
      if (token_before_that == no_semi_successors[i])
	return (" ");
    }

  return ("; ");
}
#endif /* HISTORY */

/* Issue a prompt, or prepare to issue a prompt when the next character
   is read. */
static void
prompt_again ()
{
  char *temp_prompt;

  if (!interactive)	/* XXX */
    return;

  ps1_prompt = get_string_value ("PS1");
  ps2_prompt = get_string_value ("PS2");

  if (!prompt_string_pointer)
    prompt_string_pointer = &ps1_prompt;

  temp_prompt = *prompt_string_pointer
			? decode_prompt_string (*prompt_string_pointer)
			: (char *)NULL;

  if (temp_prompt == 0)
    {
      temp_prompt = (char *)xmalloc (1);
      temp_prompt[0] = '\0';
    }

  current_prompt_string = *prompt_string_pointer;
  prompt_string_pointer = &ps2_prompt;

#if defined (READLINE)
  if (!no_line_editing)
    {
      FREE (current_readline_prompt);
      current_readline_prompt = temp_prompt;
    }
  else
#endif	/* READLINE */
    {
      FREE (current_decoded_prompt);
      current_decoded_prompt = temp_prompt;
    }
}

int
get_current_prompt_level ()
{
  return ((current_prompt_string && current_prompt_string == ps2_prompt) ? 2 : 1);
}

void
set_current_prompt_level (x)
     int x;
{
  prompt_string_pointer = (x == 2) ? &ps2_prompt : &ps1_prompt;
  current_prompt_string = *prompt_string_pointer;
}
      
static void
print_prompt ()
{
  fprintf (stderr, "%s", current_decoded_prompt);
  fflush (stderr);
}

/* Return a string which will be printed as a prompt.  The string
   may contain special characters which are decoded as follows:

	\a	bell (ascii 07)
	\e	escape (ascii 033)
	\d	the date in Day Mon Date format
	\h	the hostname up to the first `.'
	\H	the hostname
	\j	the number of active jobs
	\l	the basename of the shell's tty device name
	\n	CRLF
	\s	the name of the shell
	\t	the time in 24-hour hh:mm:ss format
	\T	the time in 12-hour hh:mm:ss format
	\@	the time in 12-hour am/pm format
	\v	the version of bash (e.g., 2.00)
	\V	the release of bash, version + patchlevel (e.g., 2.00.0)
	\w	the current working directory
	\W	the last element of $PWD
	\u	your username
	\#	the command number of this command
	\!	the history number of this command
	\$	a $ or a # if you are root
	\nnn	character code nnn in octal
	\\	a backslash
	\[	begin a sequence of non-printing chars
	\]	end a sequence of non-printing chars
*/
#define PROMPT_GROWTH 48
char *
decode_prompt_string (string)
     char *string;
{
  WORD_LIST *list;
  char *result, *t;
  struct dstack save_dstack;
  int last_exit_value;
#if defined (PROMPT_STRING_DECODE)
  int result_size, result_index;
  int c, n;
  char *temp, octal_string[4];
  time_t the_time;

  result = (char *)xmalloc (result_size = PROMPT_GROWTH);
  result[result_index = 0] = 0;
  temp = (char *)NULL;

  while (c = *string++)
    {
      if (posixly_correct && c == '!')
	{
	  if (*string == '!')
	    {
	      temp = savestring ("!");
	      goto add_string;
	    }
	  else
	    {
#if !defined (HISTORY)
		temp = savestring ("1");
#else /* HISTORY */
		temp = itos (history_number ());
#endif /* HISTORY */
		string--;	/* add_string increments string again. */
		goto add_string;
	    }
	}
      if (c == '\\')
	{
	  c = *string;

	  switch (c)
	    {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	      strncpy (octal_string, string, 3);
	      octal_string[3] = '\0';

	      n = read_octal (octal_string);
	      temp = (char *)xmalloc (3);

	      if (n == CTLESC || n == CTLNUL)
		{
		  temp[0] = CTLESC;
		  temp[1] = n;
		  temp[2] = '\0';
		}
	      else if (n == -1)
		{
		  temp[0] = '\\';
		  temp[1] = '\0';
		}
	      else
		{
		  temp[0] = n;
		  temp[1] = '\0';
		}

	      for (c = 0; n != -1 && c < 3 && ISOCTAL (*string); c++)
		string++;

	      c = 0;
	      goto add_string;

	    case 't':
	    case 'd':
	    case 'T':
	    case '@':
	    case 'A':
	      /* Make the current time/date into a string. */
	      the_time = time (0);
	      temp = ctime (&the_time);

	      temp = (c != 'd') ? savestring (temp + 11) : savestring (temp);
	      temp[(c != 'd') ? 8 : 10] = '\0';
	      temp[(c != 'A') ? 10 : 5] = '\0';

	      /* quick and dirty conversion to 12-hour time */
	      if (c == 'T' || c == '@')
		{
		  if (c == '@')
		    {
		      temp[5] = 'a';	/* am/pm format */
		      temp[6] = 'm';
		      temp[7] = '\0';
		    }
		  c = temp[2];
		  temp[2] = '\0';
		  n = atoi (temp);
		  temp[2] = c;
		  n -= 12;
		  if (n > 0)
		    {
		      temp[0] = (n / 10) + '0';
		      temp[1] = (n % 10) + '0';
		    }
		  if (n >= 0 && temp[5] == 'a')
		    temp[5] = 'p';
		}
	      goto add_string;

	    case 'r':
	      temp = (char *)xmalloc (2);
	      temp[0] = '\r';
	      temp[1] = '\0';
	      goto add_string;

	    case 'n':
	      temp = (char *)xmalloc (3);
	      temp[0] = no_line_editing ? '\n' : '\r';
	      temp[1] = no_line_editing ? '\0' : '\n';
	      temp[2] = '\0';
	      goto add_string;

	    case 's':
	      temp = base_pathname (shell_name);
	      temp = savestring (temp);
	      goto add_string;

	    case 'v':
	    case 'V':
	      temp = (char *)xmalloc (8);
	      if (c == 'v')
		strcpy (temp, dist_version);
	      else
		sprintf (temp, "%s.%d", dist_version, patch_level);
	      goto add_string;

	    case 'w':
	    case 'W':
	      {
		/* Use the value of PWD because it is much more efficient. */
		char t_string[PATH_MAX];
		int tlen;

		temp = get_string_value ("PWD");

		if (temp == 0)
		  {
		    if (getcwd (t_string, sizeof(t_string)) == 0)
		      {
			t_string[0] = '.';
			tlen = 1;
		      }
		    else
		      tlen = strlen (t_string);
		  }
		else
		  {
		    tlen = sizeof (t_string) - 1;
		    strncpy (t_string, temp, tlen);
		  }
		t_string[tlen] = '\0';

#define ROOT_PATH(x)	((x)[0] == '/' && (x)[1] == 0)
#define DOUBLE_SLASH_ROOT(x)	((x)[0] == '/' && (x)[1] == '/' && (x)[2] == 0)
		if (c == 'W')
		  {
		    if (ROOT_PATH (t_string) == 0 && DOUBLE_SLASH_ROOT (t_string) == 0)
		      {
			t = strrchr (t_string, '/');
			if (t)
			  strcpy (t_string, t + 1);
		      }
		  }
#undef ROOT_PATH
#undef DOUBLE_SLASH_ROOT
		else
		  /* polite_directory_format is guaranteed to return a string
		     no longer than PATH_MAX - 1 characters. */
		  strcpy (t_string, polite_directory_format (t_string));

		/* If we're going to be expanding the prompt string later,
		   quote the directory name. */
		if (promptvars || posixly_correct)
		  /* Make sure that expand_prompt_string is called with a
		     second argument of Q_DOUBLE_QUOTE if we use this
		     function here. */
		  temp = sh_backslash_quote_for_double_quotes (t_string);
		else
		  temp = savestring (t_string);

		goto add_string;
	      }

	    case 'u':
	      if (current_user.user_name == 0)
		get_current_user_info ();
	      temp = savestring (current_user.user_name);
	      goto add_string;

	    case 'h':
	    case 'H':
	      temp = savestring (current_host_name);
	      if (c == 'h' && (t = (char *)strchr (temp, '.')))
		*t = '\0';
	      goto add_string;

	    case '#':
	      temp = itos (current_command_number);
	      goto add_string;

	    case '!':
#if !defined (HISTORY)
	      temp = savestring ("1");
#else /* HISTORY */
	      temp = itos (history_number ());
#endif /* HISTORY */
	      goto add_string;

	    case '$':
	      t = temp = (char *)xmalloc (3);
	      if ((promptvars || posixly_correct) && (current_user.euid != 0))
		*t++ = '\\';
	      *t++ = current_user.euid == 0 ? '#' : '$';
	      *t = '\0';
	      goto add_string;

	    case 'j':
	      temp = itos (count_all_jobs ());
	      goto add_string;

	    case 'l':
#if defined (HAVE_TTYNAME)
	      temp = (char *)ttyname (fileno (stdin));
	      t = temp ? base_pathname (temp) : "tty";
	      temp = savestring (t);
#else
	      temp = savestring ("tty");
#endif /* !HAVE_TTYNAME */
	      goto add_string;

#if defined (READLINE)
	    case '[':
	    case ']':
	      temp = (char *)xmalloc (3);
	      temp[0] = '\001';
	      temp[1] = (c == '[') ? RL_PROMPT_START_IGNORE : RL_PROMPT_END_IGNORE;
	      temp[2] = '\0';
	      goto add_string;
#endif /* READLINE */

	    case '\\':
	      temp = (char *)xmalloc (2);
	      temp[0] = c;
	      temp[1] = '\0';
	      goto add_string;

	    case 'a':
	    case 'e':
	      temp = (char *)xmalloc (2);
	      temp[0] = (c == 'a') ? '\07' : '\033';
	      temp[1] = '\0';
	      goto add_string;

	    default:
	      temp = (char *)xmalloc (3);
	      temp[0] = '\\';
	      temp[1] = c;
	      temp[2] = '\0';

	    add_string:
	      if (c)
		string++;
	      result =
		sub_append_string (temp, result, &result_index, &result_size);
	      temp = (char *)NULL; /* Freed in sub_append_string (). */
	      result[result_index] = '\0';
	      break;
	    }
	}
      else
	{
	  RESIZE_MALLOCED_BUFFER (result, result_index, 3, result_size, PROMPT_GROWTH);
	  result[result_index++] = c;
	  result[result_index] = '\0';
	}
    }
#else /* !PROMPT_STRING_DECODE */
  result = savestring (string);
#endif /* !PROMPT_STRING_DECODE */

  /* Save the delimiter stack and point `dstack' to temp space so any
     command substitutions in the prompt string won't result in screwing
     up the parser's quoting state. */
  save_dstack = dstack;
  dstack = temp_dstack;
  dstack.delimiter_depth = 0;

  /* Perform variable and parameter expansion and command substitution on
     the prompt string. */
  if (promptvars || posixly_correct)
    {
      last_exit_value = last_command_exit_value;
      list = expand_prompt_string (result, Q_DOUBLE_QUOTES);
      free (result);
      result = string_list (list);
      dispose_words (list);
      last_command_exit_value = last_exit_value;
    }
  else
    {
      t = dequote_string (result);
      free (result);
      result = t;
    }

  dstack = save_dstack;

  return (result);
}

/* Report a syntax error, and restart the parser.  Call here for fatal
   errors. */
int
yyerror (msg)
     const char *msg;
{
  report_syntax_error ((char *)NULL);
  reset_parser ();
  return (0);
}

/* Report a syntax error with line numbers, etc.
   Call here for recoverable errors.  If you have a message to print,
   then place it in MESSAGE, otherwise pass NULL and this will figure
   out an appropriate message for you. */
static void
report_syntax_error (message)
     char *message;
{
  char *msg, *t;
  int token_end, i;
  char msg2[2];

  if (message)
    {
      parser_error (line_number, "%s", message);
      if (interactive && EOF_Reached)
	EOF_Reached = 0;
      last_command_exit_value = EX_USAGE;
      return;
    }

  /* If the line of input we're reading is not null, try to find the
     objectionable token. */
  if (shell_input_line && *shell_input_line)
    {
      t = shell_input_line;
      i = shell_input_line_index;
      token_end = 0;

      if (i && t[i] == '\0')
	i--;

      while (i && (whitespace (t[i]) || t[i] == '\n'))
	i--;

      if (i)
	token_end = i + 1;

      while (i && (member (t[i], " \n\t;|&") == 0))
	i--;

      while (i != token_end && (whitespace (t[i]) || t[i] == '\n'))
	i++;

      /* Print the offending token. */
      if (token_end || (i == 0 && token_end == 0))
	{
	  if (token_end)
	    msg = substring (t, i, token_end);
	  else	/* one-character token */
	    {
	      msg2[0] = t[i];
	      msg2[1] = '\0';
	      msg = msg2;
	    }

	  parser_error (line_number, "syntax error near unexpected token `%s'", msg);

	  if (msg != msg2)
	    free (msg);
	}

      /* If not interactive, print the line containing the error. */
      if (interactive == 0)
	{
	  msg = savestring (shell_input_line);
	  token_end = strlen (msg);
	  while (token_end && msg[token_end - 1] == '\n')
	    msg[--token_end] = '\0';

	  parser_error (line_number, "`%s'", msg);
	  free (msg);
	}
    }
  else
    {
      msg = EOF_Reached ? "syntax error: unexpected end of file" : "syntax error";
      parser_error (line_number, "%s", msg);
      /* When the shell is interactive, this file uses EOF_Reached
	 only for error reporting.  Other mechanisms are used to
	 decide whether or not to exit. */
      if (interactive && EOF_Reached)
	EOF_Reached = 0;
    }
  last_command_exit_value = EX_USAGE;
}

/* ??? Needed function. ??? We have to be able to discard the constructs
   created during parsing.  In the case of error, we want to return
   allocated objects to the memory pool.  In the case of no error, we want
   to throw away the information about where the allocated objects live.
   (dispose_command () will actually free the command. */
static void
discard_parser_constructs (error_p)
     int error_p;
{
}

/* Do that silly `type "bye" to exit' stuff.  You know, "ignoreeof". */

/* A flag denoting whether or not ignoreeof is set. */
int ignoreeof = 0;

/* The number of times that we have encountered an EOF character without
   another character intervening.  When this gets above the limit, the
   shell terminates. */
int eof_encountered = 0;

/* The limit for eof_encountered. */
int eof_encountered_limit = 10;

/* If we have EOF as the only input unit, this user wants to leave
   the shell.  If the shell is not interactive, then just leave.
   Otherwise, if ignoreeof is set, and we haven't done this the
   required number of times in a row, print a message. */
static void
handle_eof_input_unit ()
{
  if (interactive)
    {
      /* shell.c may use this to decide whether or not to write out the
	 history, among other things.  We use it only for error reporting
	 in this file. */
      if (EOF_Reached)
	EOF_Reached = 0;

      /* If the user wants to "ignore" eof, then let her do so, kind of. */
      if (ignoreeof)
	{
	  if (eof_encountered < eof_encountered_limit)
	    {
	      fprintf (stderr, "Use \"%s\" to leave the shell.\n",
		       login_shell ? "logout" : "exit");
	      eof_encountered++;
	      /* Reset the prompt string to be $PS1. */
	      prompt_string_pointer = (char **)NULL;
	      prompt_again ();
	      last_read_token = current_token = '\n';
	      return;
	    }
	}

      /* In this case EOF should exit the shell.  Do it now. */
      reset_parser ();
      exit_builtin ((WORD_LIST *)NULL);
    }
  else
    {
      /* We don't write history files, etc., for non-interactive shells. */
      EOF_Reached = 1;
    }
}

static WORD_LIST parse_string_error;

/* Take a string and run it through the shell parser, returning the
   resultant word list.  Used by compound array assignment. */
WORD_LIST *
parse_string_to_word_list (s, whom)
     char *s;
     const char *whom;
{
  WORD_LIST *wl;
  int tok, orig_line_number, orig_input_terminator;
  int orig_line_count;
#if defined (HISTORY)
  int old_remember_on_history, old_history_expansion_inhibited;
#endif

#if defined (HISTORY)
  old_remember_on_history = remember_on_history;
#  if defined (BANG_HISTORY)
  old_history_expansion_inhibited = history_expansion_inhibited;
#  endif
  bash_history_disable ();
#endif

  orig_line_number = line_number;
  orig_line_count = current_command_line_count;
  orig_input_terminator = shell_input_line_terminator;

  push_stream (1);
  last_read_token = '\n';
  current_command_line_count = 0;

  with_input_from_string (s, whom);
  wl = (WORD_LIST *)NULL;
  while ((tok = read_token (READ)) != yacc_EOF)
    {
      if (tok == '\n' && *bash_input.location.string == '\0')
	break;
      if (tok == '\n')		/* Allow newlines in compound assignments */
	continue;
      if (tok != WORD && tok != ASSIGNMENT_WORD)
	{
	  line_number = orig_line_number + line_number - 1;
	  yyerror ((char *)NULL);	/* does the right thing */
	  if (wl)
	    dispose_words (wl);
	  wl = &parse_string_error;
	  break;
	}
      wl = make_word_list (yylval.word, wl);
    }
  
  last_read_token = '\n';
  pop_stream ();

#if defined (HISTORY)
  remember_on_history = old_remember_on_history;
#  if defined (BANG_HISTORY)
  history_expansion_inhibited = old_history_expansion_inhibited;
#  endif /* BANG_HISTORY */
#endif /* HISTORY */

  current_command_line_count = orig_line_count;
  shell_input_line_terminator = orig_input_terminator;

  if (wl == &parse_string_error)
    {
      last_command_exit_value = EXECUTION_FAILURE;
      if (interactive_shell == 0 && posixly_correct)
	jump_to_top_level (FORCE_EOF);
      else
	jump_to_top_level (DISCARD);
    }

  return (REVERSE_LIST (wl, WORD_LIST *));
}

