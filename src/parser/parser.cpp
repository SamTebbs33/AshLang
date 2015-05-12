/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar/AshGrammar.y" /* yacc.c:339  */

	#include <string>
	#include <locale>
	#include <parser/tokens.h>
	#include <error/errors.h>

	#define YYERROR_VERBOSE
	#define DEL(a) delete a;

	extern int yylex();
	extern int yylineno;
	extern const char* yytext;
	void yyerror(const char* s){
		Error::parserError(s, yylineno);
	}
	int lineNo = 0;
	TokenFile file;

#line 85 "src/parser/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_SRC_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    PRIMITIVE = 259,
    CONST = 260,
    VAR = 261,
    PUBLIC = 262,
    PRIVATE = 263,
    PROTECTED = 264,
    FINAL = 265,
    REQUIRED = 266,
    NATIVE = 267,
    OVERRIDE = 268,
    STANDARD = 269,
    STATIC = 270,
    STR = 271,
    CHAR = 272,
    INT = 273,
    LONG = 274,
    FLOAT = 275,
    FLOAT64 = 276,
    BOOL_TRUE = 277,
    BOOL_FALSE = 278,
    NAMESPACE = 279,
    PROTOCOL = 280,
    CLASS = 281,
    IMPORT = 282,
    ENUM = 283,
    FUNC = 284,
    RETURN = 285,
    BRACE_LEFT = 286,
    BRACE_RIGHT = 287,
    PAREN_LEFT = 288,
    PAREN_RIGHT = 289,
    COLON = 290,
    COMMA = 291,
    BRACKET_RIGHT = 292,
    BRACKET_LEFT = 293,
    QUESTION_MARK = 294,
    DOT = 295,
    ARROW = 296,
    OP_EQUAL = 297,
    OP_NEQUAL = 298,
    OP_LESS = 299,
    OP_LESS_EQ = 300,
    OP_GREATER = 301,
    OP_GREATER_EQ = 302,
    OP_ASSIGN = 303,
    OP_TYPE = 304,
    OP_ARROW = 305,
    OP_ASSIGN_PLUS = 306,
    OP_ASSIGN_MINUS = 307,
    OP_ASSIGN_MUL = 308,
    OP_ASSIGN_DIV = 309,
    OP_ASSIGN_MOD = 310,
    OP_ASSIGN_POW = 311,
    OP_ASSIGN_XOR = 312,
    OP_ASSIGN_AND = 313,
    OP_ASSIGN_OR = 314,
    OP_ASSIGN_LSHIFT = 315,
    OP_ASSIGN_RSHIFT = 316,
    OP_INC = 317,
    OP_DEC = 318,
    OP_PLUS = 319,
    OP_MINUS = 320,
    OP_MUL = 321,
    OP_DIV = 322,
    OP_MOD = 323,
    OP_POW = 324,
    OP_XOR = 325,
    OP_AND = 326,
    OP_OR = 327,
    OP_NOT = 328,
    OP_XNOR = 329,
    OP_NAND = 330,
    OP_NOR = 331,
    OP_LSHIFT = 332,
    OP_RSHIFT = 333,
    OP_COMPLEMENT = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "grammar/AshGrammar.y" /* yacc.c:355  */

	std::string* str;
	int line;
	int token;
	int int32;
	long long int64;
	float float32;
	char ch;
	double float64;
	EnumVarDecKeyword::type varDecKeyW;
	EnumModifier::type mod;
	Operator* op;
	TokenIdentifier* id;
	TokenNamespace* namesp;
	TokenImport* import;
	Imports* imports;
	TokenTypeDec* typeDec;
	ModifiersInt mods;
	TokenFuncDec* funcDec;
	TokenArg* arg;
	Args* args;
	TokenType* type;
	Types* types;
	TokenBlock* block;
	ClassBlock* classBlock;
	TokenStatement* stmt;
	TokenVarDec* varDec;
	TokenVarDecExplicit* varDecE;
	TokenExpression* expr;
	std::vector<TokenTypeDec*>* typeDecVec;
	TokenQualifiedName* qualifiedName;
	std::vector<TokenIdentifier>* enumInstances;
	TokenVariable* var;
	std::vector<TokenExpression>* exprVec;
	TokenFuncCall* funcCall;
	TokenPrefix* prefix;


#line 244 "src/parser/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "src/parser/parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   112,   112,   112,   113,   114,   114,   115,
     115,   117,   117,   118,   118,   118,   119,   120,   121,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     124,   126,   126,   127,   127,   127,   128,   128,   128,   129,
     131,   131,   132,   132,   133,   133,   135,   135,   135,   135,
     135,   136,   136,   136,   137,   137,   137,   137,   138,   138,
     138,   139,   139,   139,   140,   141,   141,   141,   141,   141,
     143,   144,   145,   146,   146,   147,   148,   149,   150,   151,
     151,   151,   152,   153,   155,   155,   156,   156,   156,   157,
     157,   158,   158,   158,   159,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   181,   181,   181,   181,   182,   182
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "PRIMITIVE", "CONST", "VAR",
  "PUBLIC", "PRIVATE", "PROTECTED", "FINAL", "REQUIRED", "NATIVE",
  "OVERRIDE", "STANDARD", "STATIC", "STR", "CHAR", "INT", "LONG", "FLOAT",
  "FLOAT64", "BOOL_TRUE", "BOOL_FALSE", "NAMESPACE", "PROTOCOL", "CLASS",
  "IMPORT", "ENUM", "FUNC", "RETURN", "BRACE_LEFT", "BRACE_RIGHT",
  "PAREN_LEFT", "PAREN_RIGHT", "COLON", "COMMA", "BRACKET_RIGHT",
  "BRACKET_LEFT", "QUESTION_MARK", "DOT", "ARROW", "OP_EQUAL", "OP_NEQUAL",
  "OP_LESS", "OP_LESS_EQ", "OP_GREATER", "OP_GREATER_EQ", "OP_ASSIGN",
  "OP_TYPE", "OP_ARROW", "OP_ASSIGN_PLUS", "OP_ASSIGN_MINUS",
  "OP_ASSIGN_MUL", "OP_ASSIGN_DIV", "OP_ASSIGN_MOD", "OP_ASSIGN_POW",
  "OP_ASSIGN_XOR", "OP_ASSIGN_AND", "OP_ASSIGN_OR", "OP_ASSIGN_LSHIFT",
  "OP_ASSIGN_RSHIFT", "OP_INC", "OP_DEC", "OP_PLUS", "OP_MINUS", "OP_MUL",
  "OP_DIV", "OP_MOD", "OP_POW", "OP_XOR", "OP_AND", "OP_OR", "OP_NOT",
  "OP_XNOR", "OP_NAND", "OP_NOR", "OP_LSHIFT", "OP_RSHIFT",
  "OP_COMPLEMENT", "$accept", "file", "imports", "import",
  "qualified_name", "namespace_dec", "type_decs", "type_dec", "class_dec",
  "protocol_dec", "enum_dec", "mod", "mods", "type_args", "type", "args",
  "arg", "func_type", "type_supers", "throws", "class_block",
  "func_dec_block", "func_stmt", "enum_instances", "enum_block",
  "enum_stmt", "protocol_block", "func_dec", "class_func_dec",
  "protocol_func_dec", "var_dec_keyw", "var_dec_body", "var_dec_explicit",
  "var_dec_explicit_assign", "var_dec_implicit", "var_dec",
  "class_var_dec", "protocol_var_dec", "prefix", "func_call_args",
  "func_call", "var", "var_assign", "expr", "op_assign", "op_infix",
  "op_prefix", "op_postfix", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    22,    29,    20,  -111,    12,  -111,    22,   389,  -111,
      66,    12,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    74,  -111,   316,  -111,  -111,  -111,  -111,  -111,   400,
    -111,    52,  -111,    91,   100,  -111,   101,    71,    52,    52,
      70,    38,  -111,   103,    72,    72,     9,  -111,   101,  -111,
     268,     9,  -111,    14,    15,  -111,  -111,    73,  -111,   105,
     377,   184,  -111,    78,  -111,    73,   224,     9,   325,    75,
    -111,   110,  -111,  -111,    51,   366,   338,  -111,  -111,    72,
    -111,  -111,    73,   351,  -111,   -30,    67,  -111,  -111,  -111,
    -111,  -111,    81,    94,    16,   144,   259,  -111,  -111,    95,
    -111,   254,  -111,  -111,  -111,   131,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,    16,    16,   101,    16,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,    16,  -111,  -111,  -111,  -111,
      96,   -12,   183,    16,  -111,  -111,   134,    16,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
      16,  -111,   183,   183,    39,    50,   183,    54,    16,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    16,  -111,   183,    96,   -12,    99,   183,    72,  -111,
      16,  -111,   143,   183,  -111,    98,   183,    16,     9,  -111,
     183,    73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,     0,     5,     7,     9,     1,     0,    30,     3,
       0,     6,    19,    20,    21,    22,    24,    23,    27,    25,
      26,     0,     4,    30,    11,    13,    14,    15,    28,     0,
       8,    32,    12,     0,     0,    29,    38,     0,    32,    32,
       0,     0,    36,    60,    41,    41,     0,    31,     0,    58,
      30,     0,    42,     0,     0,    33,    34,    39,    37,     0,
       0,    30,    61,     0,    64,    40,    30,     0,    30,     0,
      59,     0,    18,    62,    30,     0,    30,    72,    65,    41,
      83,    67,    43,    30,    46,    41,    79,    80,    81,    82,
      48,    35,     0,    91,    56,     0,    30,    51,    55,     0,
      85,    84,    54,    73,    74,     0,    17,    66,    68,    76,
      16,    47,    49,     0,     0,    38,    88,    99,   100,    98,
     105,   103,   104,   101,   102,     0,   143,   144,   142,   145,
     109,   108,    57,     0,    71,    52,     0,     0,   110,   112,
     111,   113,   114,   115,   118,   119,   117,   116,   120,   121,
       0,    75,    78,    77,     0,     0,    86,     0,     0,   128,
     129,   130,   131,   132,   133,   146,   147,   134,   135,   136,
     137,   139,   138,   122,   123,   124,   125,   126,   127,   140,
     141,     0,    97,    96,    90,    93,     0,    94,    41,    89,
       0,   107,     0,    95,    92,    45,    87,     0,     0,    70,
     106,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   132,   141,  -111,  -111,   137,  -111,  -111,
    -111,   -19,    -6,    53,   -51,    57,   133,   -78,   135,  -111,
    -111,  -111,    83,  -111,  -111,   122,  -111,   -52,   -57,   108,
    -111,   -23,    -9,  -111,  -111,   -65,   117,   125,  -111,  -111,
     -66,   -54,  -111,  -110,  -111,  -111,  -111,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     5,     3,    23,    24,    25,    26,
      27,    28,    75,    37,    57,    41,    42,    52,    53,   199,
      83,    96,    97,    50,    61,    62,    76,    63,    64,    78,
     105,    85,    86,    87,    88,    89,    90,    81,    99,   155,
     130,   131,   102,   132,   150,   181,   133,   182
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,   109,    29,   152,   153,    51,   156,   109,   100,    98,
      35,    84,    55,    56,    77,   157,    82,    29,   113,    93,
     101,   137,     1,   183,    77,     4,   111,   186,   -84,     6,
     100,    98,   117,   118,   119,   120,   121,   122,   123,   124,
     187,    35,   101,    79,    60,    66,    68,     7,   192,   125,
      67,    67,    10,    79,    93,    60,    35,    80,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    80,    95,    30,
     184,   193,    47,   188,    48,    48,    35,    31,   126,   127,
     196,    94,   185,   -53,   189,    36,   190,   200,   191,   128,
      95,    44,    45,   158,    38,   129,   159,   160,   161,   162,
     163,   164,    43,    39,    40,    46,    49,    51,    70,    74,
     195,    69,    91,    92,   115,   114,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   116,   176,   177,
     178,   179,   180,   194,   151,   136,   -85,    93,   158,   198,
      22,   159,   160,   161,   162,   163,   164,   201,    11,   103,
     104,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      32,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   154,   176,   177,   178,   179,   180,   197,   135,
      54,    58,   158,    73,   107,   159,   160,   161,   162,   163,
     164,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     112,   108,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    72,   176,   177,   178,
     179,   180,   158,     0,     0,   159,   160,   161,   162,   163,
     164,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   -69,   176,   177,   178,
     179,   180,    93,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,   137,     0,    94,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
     -63,     0,   138,     0,    59,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -2,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,    21,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,   -50,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
     106,   103,   104,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   110,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    71,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    71,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     7,    21,     0,     0,
       0,     0,     0,     0,     0,    33,    34
};

static const yytype_int16 yycheck[] =
{
      51,    79,     8,   113,   114,    35,   116,    85,    74,    74,
      29,    68,     3,     4,    66,   125,    67,    23,    48,     3,
      74,    33,    24,   133,    76,     3,    83,   137,    40,     0,
      96,    96,    16,    17,    18,    19,    20,    21,    22,    23,
     150,    60,    96,    66,    50,    31,    31,    27,   158,    33,
      36,    36,    40,    76,     3,    61,    75,    66,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    76,    74,     3,
     136,   181,    34,    34,    36,    36,    95,     3,    62,    63,
     190,    30,   136,    32,    34,    33,    36,   197,    34,    73,
      96,    38,    39,    39,     3,    79,    42,    43,    44,    45,
      46,    47,    31,     3,     3,    35,     3,    35,     3,    31,
     188,    38,    37,     3,    33,    48,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    33,    74,    75,
      76,    77,    78,    34,     3,    40,    40,     3,    39,    41,
       8,    42,    43,    44,    45,    46,    47,   198,     7,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      23,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,   115,    74,    75,    76,    77,    78,    35,    96,
      45,    48,    39,    61,    76,    42,    43,    44,    45,    46,
      47,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      83,    76,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    32,    74,    75,    76,
      77,    78,    39,    -1,    -1,    42,    43,    44,    45,    46,
      47,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    32,    74,    75,    76,
      77,    78,     3,    -1,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    33,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    48,    -1,    36,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    28,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      32,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    81,    85,     3,    84,     0,    27,    82,    83,
      40,    84,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    28,    83,    86,    87,    88,    89,    90,    91,    92,
       3,     3,    87,    25,    26,    91,    33,    93,     3,     3,
       3,    95,    96,    31,    93,    93,    35,    34,    36,     3,
     103,    35,    97,    98,    98,     3,     4,    94,    96,    36,
      92,   104,   105,   107,   108,    94,    31,    36,    31,    38,
       3,    29,    32,   105,    31,    92,   106,   107,   109,   111,
     112,   117,    94,   100,   108,   111,   112,   113,   114,   115,
     116,    37,     3,     3,    30,    92,   101,   102,   115,   118,
     120,   121,   122,     5,     6,   110,    32,   109,   117,    97,
      32,   108,   116,    48,    48,    33,    33,    16,    17,    18,
      19,    20,    21,    22,    23,    33,    62,    63,    73,    79,
     120,   121,   123,   126,    32,   102,    40,    33,    48,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     124,     3,   123,   123,    95,   119,   123,   123,    39,    42,
      43,    44,    45,    46,    47,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      78,   125,   127,   123,   120,   121,   123,   123,    34,    34,
      36,    34,   123,   123,    34,    97,   123,    35,    41,    99,
     123,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    82,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    89,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    93,    93,    94,    94,    94,    95,    95,    95,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     103,   104,   104,   104,   105,   106,   106,   106,   106,   106,
     107,   108,   109,   110,   110,   111,   112,   113,   114,   115,
     115,   115,   116,   117,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   121,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   126,   127,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     0,     2,     1,     3,     2,
       0,     1,     2,     1,     1,     1,     8,     8,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     1,     1,     3,     1,     3,     0,     3,
       2,     0,     1,     3,     2,     0,     1,     2,     1,     2,
       0,     1,     2,     0,     1,     1,     1,     2,     1,     3,
       0,     1,     2,     0,     1,     1,     2,     1,     2,     0,
       8,     4,     1,     1,     1,     3,     2,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     4,
       3,     1,     4,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 110 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {file = TokenFile(*(yyvsp[-2].namesp), *(yyvsp[-1].imports), *(yyvsp[0].typeDecVec)); DEL((yyvsp[-2].namesp)) DEL((yyvsp[-1].imports)) DEL((yyvsp[0].typeDecVec))}
#line 1537 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 112 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.imports) = new Imports(*(yyvsp[0].import)); DEL((yyvsp[0].import))}
#line 1543 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 112 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].imports)->imports.push_back(*(yyvsp[0].import)); DEL((yyvsp[0].import))}
#line 1549 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 112 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.imports) = new Imports();}
#line 1555 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 113 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.import) = new TokenImport(*(yyvsp[0].qualifiedName)); DEL((yyvsp[0].qualifiedName))}
#line 1561 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 114 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.qualifiedName) = new TokenQualifiedName(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1567 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 114 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].qualifiedName)->paths.push_back(*(yyvsp[0].id)->str); DEL((yyvsp[0].id))}
#line 1573 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 115 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.namesp) = new TokenNamespace(*(yyvsp[0].qualifiedName)); DEL((yyvsp[0].qualifiedName))}
#line 1579 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 115 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.namesp) = new TokenNamespace();}
#line 1585 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 117 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDecVec) = new std::vector<TokenTypeDec*>(); (yyval.typeDecVec)->push_back((yyvsp[0].typeDec));}
#line 1591 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 117 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDecVec)->push_back((yyvsp[0].typeDec));}
#line 1597 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 119 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenClassDec(*(yyvsp[-4].args), *(yyvsp[-5].id), (yyvsp[-7].mods), *(yyvsp[-3].types), *(yyvsp[-1].classBlock)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-3].types)) DEL((yyvsp[-1].classBlock))}
#line 1603 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 120 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenProtocolDec(*(yyvsp[-4].args), *(yyvsp[-5].id), (yyvsp[-7].mods), *(yyvsp[-3].types), *(yyvsp[-1].classBlock)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-3].types)) DEL((yyvsp[-1].classBlock))}
#line 1609 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 121 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenEnumDec(*(yyvsp[-4].args), *(yyvsp[-5].id), *(yyvsp[-2].enumInstances)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-2].enumInstances))}
#line 1615 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 124 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) = (yyvsp[0].mod);}
#line 1621 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 124 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) |= (yyvsp[0].mod);}
#line 1627 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 124 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) = 0;}
#line 1633 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 126 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = (yyvsp[-1].args);}
#line 1639 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 126 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1645 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 127 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1651 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 127 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1657 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 127 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].type)->arrDims++;}
#line 1663 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 128 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1669 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 128 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].args)->args.push_back(*(yyvsp[0].arg)); DEL((yyvsp[0].arg))}
#line 1675 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 128 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1681 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 129 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.arg) = new TokenArg(*(yyvsp[-2].id), *(yyvsp[0].type)); DEL((yyvsp[0].type)) DEL((yyvsp[-2].id))}
#line 1687 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 131 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1693 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 131 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = NULL;}
#line 1699 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 132 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.types) = new Types((yyvsp[0].type) != NULL ? *(yyvsp[0].type) : TokenType()); DEL((yyvsp[0].type))}
#line 1705 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 132 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].types)->types.push_back(*(yyvsp[0].type)); DEL((yyvsp[0].type))}
#line 1711 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 133 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1717 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 133 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = NULL;}
#line 1723 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 135 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].funcDec));}
#line 1729 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 135 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].classBlock)->funcDecs.push_back((yyvsp[0].funcDec));}
#line 1735 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 135 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].varDec));}
#line 1741 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 135 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock)->varDecs.push_back((yyvsp[0].varDec));}
#line 1747 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 135 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock();}
#line 1753 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 136 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock((yyvsp[0].stmt));}
#line 1759 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 136 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].block)->stmts.push_back((yyvsp[0].stmt));}
#line 1765 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 136 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock();}
#line 1771 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 137 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenReturn();}
#line 1777 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 137 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenReturn(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 1783 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 138 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.enumInstances) = new std::vector<TokenIdentifier>(); (yyval.enumInstances)->push_back(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1789 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 138 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].enumInstances)->push_back(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1795 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 138 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.enumInstances) = new std::vector<TokenIdentifier>();}
#line 1801 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 139 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock((yyvsp[0].stmt));}
#line 1807 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 139 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].block)->stmts.push_back((yyvsp[0].stmt));}
#line 1813 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 139 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock();}
#line 1819 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].funcDec));}
#line 1825 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].classBlock)->funcDecs.push_back((yyvsp[0].funcDec));}
#line 1831 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].varDec));}
#line 1837 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock)->varDecs.push_back((yyvsp[0].varDec));}
#line 1843 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock();}
#line 1849 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 143 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.funcDec) = new TokenFuncDec((yyvsp[-7].mods), *(yyvsp[-5].id), *(yyvsp[-3].args), (yyvsp[-1].type) != NULL ? *(yyvsp[-1].type) : TokenType(), (yyvsp[0].type) != NULL ? *(yyvsp[0].type) : TokenType()); DEL((yyvsp[-5].id)) DEL((yyvsp[-3].args)) DEL((yyvsp[-1].type)) DEL((yyvsp[0].type))}
#line 1855 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 144 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-3].funcDec)->block = *(yyvsp[-1].block); DEL((yyvsp[-1].block))}
#line 1861 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 145 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {/*$1->block = TokenBlock();*/}
#line 1867 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 147 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDec((yyvsp[-2].mods), *(yyvsp[0].id), (yyvsp[-1].varDecKeyW)); DEL((yyvsp[0].id))}
#line 1873 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 148 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDecE) = new TokenVarDecExplicit((yyvsp[-1].varDec)->id, (yyvsp[-1].varDec)->decKeyword, *(yyvsp[0].type));  DEL((yyvsp[0].type))}
#line 1879 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 149 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDecExplicitAssign((yyvsp[-2].varDecE)->id, (yyvsp[-2].varDecE)->decKeyword, (yyvsp[-2].varDecE)->type, *(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 1885 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 150 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDecImplicit((yyvsp[-2].varDec)->id, (yyvsp[-2].varDec)->decKeyword, *(yyvsp[0].expr), (yyvsp[-2].varDec)->mods); DEL((yyvsp[0].expr))}
#line 1891 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 156 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.exprVec) = new std::vector<TokenExpression>(); (yyval.exprVec)->push_back(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 1897 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 156 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].exprVec)->push_back(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 1903 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 156 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.exprVec) = new std::vector<TokenExpression>();}
#line 1909 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 157 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.funcCall) = new TokenFuncCall(*(yyvsp[-3].id), *(yyvsp[-1].exprVec)); DEL((yyvsp[-1].exprVec)) DEL((yyvsp[-3].id))}
#line 1915 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 157 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[0].funcCall)->prefix = *(yyvsp[-2].prefix); DEL((yyvsp[-2].prefix))}
#line 1921 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 158 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.var) = new TokenVariable(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1927 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 158 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-3].var)->arrExprs.push_back(*(yyvsp[-1].expr)); DEL((yyvsp[-1].expr))}
#line 1933 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 158 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[0].var)->prefix = *(yyvsp[-2].prefix); DEL((yyvsp[-2].prefix))}
#line 1939 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 159 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenVarAssign(*(yyvsp[-2].var), (yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[-2].var)) DEL((yyvsp[0].expr))}
#line 1945 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 161 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprInfix(*(yyvsp[-2].expr), *(yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[-2].expr)) DEL((yyvsp[0].expr)) DEL((yyvsp[-1].op))}
#line 1951 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 162 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprPrefix(*(yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[0].expr)) DEL((yyvsp[-1].op))}
#line 1957 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 163 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprPostfix(*(yyvsp[-1].expr), *(yyvsp[0].op)); DEL((yyvsp[-1].expr)) DEL((yyvsp[0].op))}
#line 1963 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 164 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprInt((yyvsp[0].int32));}
#line 1969 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 165 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprStr((yyvsp[0].str));}
#line 1975 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 166 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprChar((yyvsp[0].ch));}
#line 1981 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 167 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprBool(true);}
#line 1987 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 168 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprBool(false);}
#line 1993 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 169 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprFloat((yyvsp[0].float32));}
#line 1999 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 170 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprFloat64((yyvsp[0].float64));}
#line 2005 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 171 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprLong((yyvsp[0].int64));}
#line 2011 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 172 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprTernary(*(yyvsp[-4].expr), *(yyvsp[-2].expr), *(yyvsp[0].expr)); DEL((yyvsp[-4].expr)) DEL((yyvsp[-2].expr)) DEL((yyvsp[0].expr))}
#line 2017 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 173 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 2023 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;


#line 2027 "src/parser/parser.cpp" /* yacc.c:1661  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 184 "grammar/AshGrammar.y" /* yacc.c:1906  */
