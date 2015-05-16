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
	#include <parser/tokens.hpp>
	#include <error/errors.hpp>
	#include <parser/yyltype.hpp>

	#define YYERROR_VERBOSE
	#define DEL(a) delete a;

	extern int yylex();
	extern int yylineno;
	extern const char* yytext;
	extern YYLTYPE yylloc;
	void yyerror(const char* msg){
		Error::parserError(msg, &yylloc);
	}

	int lineNo = 0;
	TokenFile* file;

#line 87 "src/parser/parser.cpp" /* yacc.c:339  */

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
#line 22 "grammar/AshGrammar.y" /* yacc.c:355  */

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


#line 246 "src/parser/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "src/parser/parser.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

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
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   116,   117,   118,   120,   123,   124,   127,
     128,   131,   132,   135,   136,   137,   139,   141,   143,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   157,   158,
     159,   162,   163,   165,   168,   169,   170,   173,   174,   175,
     177,   179,   180,   183,   184,   185,   188,   189,   192,   193,
     194,   195,   196,   199,   200,   201,   204,   205,   206,   207,
     210,   211,   212,   215,   216,   217,   220,   221,   222,   223,
     224,   226,   228,   230,   234,   236,   238,   240,   243,   244,
     245,   248,   249,   252,   253,   254,   257,   258,   261,   262,
     263,   265,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   288,
     288,   288,   288,   289,   289
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
  "protocol_dec", "enum_dec", "mod", "mods", "type_args", "type_super",
  "type", "args", "arg", "func_type", "type_supers", "throws",
  "class_block", "func_dec_block", "func_stmt", "enum_instances",
  "enum_block", "protocol_block", "func_dec", "class_func_dec",
  "protocol_func_dec", "var_dec_body", "var_dec_explicit",
  "var_dec_explicit_assign", "var_dec_implicit", "var_dec", "prefix",
  "func_call_args", "func_call", "var", "var_assign", "expr", "op_assign",
  "op_infix", "op_prefix", "op_postfix", YY_NULL
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

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -83

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,    32,    42,    39,  -109,    31,  -109,    32,   383,  -109,
      69,    31,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,    72,  -109,   282,  -109,  -109,  -109,  -109,  -109,   392,
    -109,    58,  -109,    89,   100,  -109,   101,    74,    58,    58,
      71,     7,  -109,   105,    82,    82,    20,  -109,   101,  -109,
     266,   106,   -21,   -20,  -109,  -109,   103,  -109,   145,   360,
     153,   118,  -109,  -109,  -109,   195,   106,   235,   115,  -109,
     147,  -109,  -109,    50,   351,   304,  -109,  -109,   134,  -109,
    -109,   313,  -109,   -28,   122,  -109,  -109,  -109,  -109,   120,
     138,    11,   113,    86,  -109,  -109,   132,  -109,   295,  -109,
     170,  -109,  -109,  -109,    20,  -109,  -109,  -109,  -109,    11,
      11,   101,    11,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,    11,  -109,  -109,  -109,  -109,   152,    14,   194,    11,
    -109,  -109,   191,    11,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,    11,  -109,   103,   194,
     194,    47,    51,   194,    68,    11,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    11,  -109,
     194,   152,    14,   154,   194,   134,  -109,    11,  -109,   112,
     194,  -109,   171,   194,    11,   106,  -109,   194,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,     0,     5,     7,     9,     1,     0,    30,     3,
       0,     6,    19,    20,    21,    22,    24,    23,    27,    25,
      26,     0,     4,    30,    11,    13,    14,    15,    28,     0,
       8,    32,    12,     0,     0,    29,    39,     0,    32,    32,
       0,     0,    37,    62,    45,    45,     0,    31,     0,    60,
      30,     0,     0,     0,    34,    35,    40,    38,     0,     0,
      30,     0,    63,    33,    43,    30,     0,    30,     0,    61,
       0,    18,    64,    30,     0,    30,    73,    66,    42,    68,
      44,    30,    50,    42,    78,    79,    80,    48,    36,     0,
      88,    58,     0,    30,    53,    57,     0,    82,    81,    56,
       0,    17,    67,    69,     0,    75,    16,    51,    49,     0,
       0,    39,    85,    96,    97,    95,   102,   100,   101,    98,
      99,     0,   140,   141,   139,   142,   106,   105,    59,     0,
      72,    54,     0,     0,   107,   109,   108,   110,   111,   112,
     115,   116,   114,   113,   117,   118,     0,    74,    41,    77,
      76,     0,     0,    83,     0,     0,   125,   126,   127,   128,
     129,   130,   143,   144,   131,   132,   133,   134,   136,   135,
     119,   120,   121,   122,   123,   124,   137,   138,     0,    94,
      93,    87,    90,     0,    91,    42,    86,     0,   104,     0,
      92,    89,    47,    84,     0,     0,    71,   103,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,   187,   204,  -109,  -109,   190,  -109,  -109,
    -109,   -23,    -5,    10,   -66,   110,   104,   186,    66,   207,
    -109,  -109,  -109,   142,  -109,  -109,  -109,   -25,   -55,   178,
     -19,     2,  -109,  -109,   -59,  -109,  -109,   -56,   -54,  -109,
    -108,  -109,  -109,  -109,  -109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     5,     3,    23,    24,    25,    26,
      27,    28,    74,    37,    64,    56,    41,    42,   105,    52,
     196,    81,    93,    94,    50,    60,    75,    61,    62,    77,
      83,    84,    85,    86,    95,    96,   152,   126,   127,    99,
     128,   146,   178,   129,   179
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,   149,   150,    29,   153,    72,    35,   104,    87,     1,
      65,    67,    82,   154,    90,    66,    66,    97,    29,    98,
     109,   180,   108,    54,    55,   183,   107,   113,   114,   115,
     116,   117,   118,   119,   120,     4,    35,    97,   184,    98,
      76,    47,     6,    48,   121,    59,    78,   189,    44,    45,
      76,    35,   133,    90,   -81,    59,    78,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     7,    79,    92,    35,
     190,    10,    30,   122,   123,    31,   181,   103,   182,   193,
      91,   185,   -55,    48,   124,   186,   197,   187,    92,    90,
     125,    36,    38,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   188,    39,    40,    43,    46,   155,    49,    63,
     156,   157,   158,   159,   160,   161,    91,    51,   130,   100,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   198,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    68,   173,   174,   175,   176,   177,   194,    69,    73,
      89,   155,    88,   111,   156,   157,   158,   159,   160,   161,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   104,
     110,   112,   132,   147,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    71,   173,   174,   175,   176,
     177,   191,   -82,   155,    90,    22,   156,   157,   158,   159,
     160,   161,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    11,   195,    32,   148,   151,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   -70,   173,   174,
     175,   176,   177,   155,    57,   131,   156,   157,   158,   159,
     160,   161,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   192,    53,   102,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   -52,   173,   174,
     175,   176,   177,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -2,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   -65,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
      21,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,   133,     0,     0,   101,     0,     0,     0,
       0,     0,     0,   134,     0,   106,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   100,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       7,    21,     0,     0,     0,     0,     0,    33,    34
};

static const yytype_int16 yycheck[] =
{
      66,   109,   110,     8,   112,    60,    29,    35,    67,    24,
      31,    31,    67,   121,     3,    36,    36,    73,    23,    73,
      48,   129,    81,     3,     4,   133,    81,    16,    17,    18,
      19,    20,    21,    22,    23,     3,    59,    93,   146,    93,
      65,    34,     0,    36,    33,    50,    65,   155,    38,    39,
      75,    74,    38,     3,    40,    60,    75,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    27,    65,    73,    92,
     178,    40,     3,    62,    63,     3,   132,    75,   132,   187,
      30,    34,    32,    36,    73,    34,   194,    36,    93,     3,
      79,    33,     3,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    34,     3,     3,    31,    35,    39,     3,     3,
      42,    43,    44,    45,    46,    47,    30,    35,    32,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   195,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    38,    74,    75,    76,    77,    78,    35,     3,    31,
       3,    39,    37,    33,    42,    43,    44,    45,    46,    47,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    35,
      48,    33,    40,     3,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    32,    74,    75,    76,    77,
      78,    37,    40,    39,     3,     8,    42,    43,    44,    45,
      46,    47,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     7,    41,    23,   104,   111,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    32,    74,    75,
      76,    77,    78,    39,    48,    93,    42,    43,    44,    45,
      46,    47,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   185,    45,    75,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    32,    74,    75,
      76,    77,    78,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    32,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    81,    85,     3,    84,     0,    27,    82,    83,
      40,    84,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    28,    83,    86,    87,    88,    89,    90,    91,    92,
       3,     3,    87,    25,    26,    91,    33,    93,     3,     3,
       3,    96,    97,    31,    93,    93,    35,    34,    36,     3,
     104,    35,    99,    99,     3,     4,    95,    97,    36,    92,
     105,   107,   108,     3,    94,    31,    36,    31,    38,     3,
      29,    32,   108,    31,    92,   106,   107,   109,   110,   111,
      94,   101,   108,   110,   111,   112,   113,   114,    37,     3,
       3,    30,    92,   102,   103,   114,   115,   117,   118,   119,
       6,    32,   109,   111,    35,    98,    32,   108,   114,    48,
      48,    33,    33,    16,    17,    18,    19,    20,    21,    22,
      23,    33,    62,    63,    73,    79,   117,   118,   120,   123,
      32,   103,    40,    38,    48,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   121,     3,    95,   120,
     120,    96,   116,   120,   120,    39,    42,    43,    44,    45,
      46,    47,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    74,    75,    76,    77,    78,   122,   124,
     120,   117,   118,   120,   120,    34,    34,    36,    34,   120,
     120,    37,    98,   120,    35,    41,   100,   120,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    82,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    89,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    93,    93,    94,    95,    95,    95,    96,    96,    96,
      97,    98,    98,    99,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   114,
     114,   115,   115,   116,   116,   116,   117,   117,   118,   118,
     118,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   124,   124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     0,     2,     1,     3,     2,
       0,     1,     2,     1,     1,     1,     8,     8,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     1,     1,     1,     3,     1,     3,     0,
       3,     2,     0,     2,     3,     0,     2,     0,     1,     2,
       1,     2,     0,     1,     2,     0,     1,     1,     1,     2,
       1,     3,     0,     1,     2,     0,     1,     2,     1,     2,
       0,     8,     4,     1,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     0,     4,     3,     1,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 113 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {file = new TokenFile(*(yyvsp[-2].namesp), *(yyvsp[-1].imports), *(yyvsp[0].typeDecVec)); DEL((yyvsp[-2].namesp)) DEL((yyvsp[-1].imports)) DEL((yyvsp[0].typeDecVec))}
#line 1642 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 116 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.imports) = new Imports(*(yyvsp[0].import)); DEL((yyvsp[0].import))}
#line 1648 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 117 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].imports)->imports.push_back(*(yyvsp[0].import)); DEL((yyvsp[0].import))}
#line 1654 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 118 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.imports) = new Imports();}
#line 1660 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 120 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.import) = new TokenImport(*(yyvsp[0].qualifiedName)); DEL((yyvsp[0].qualifiedName))}
#line 1666 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 123 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.qualifiedName) = new TokenQualifiedName(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1672 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 124 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].qualifiedName)->paths.push_back((yyvsp[0].id)->str); DEL((yyvsp[0].id))}
#line 1678 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 127 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.namesp) = new TokenNamespace(*(yyvsp[0].qualifiedName)); DEL((yyvsp[0].qualifiedName))}
#line 1684 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 128 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.namesp) = new TokenNamespace();}
#line 1690 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 131 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDecVec) = new std::vector<TokenTypeDec*>(); (yyval.typeDecVec)->push_back((yyvsp[0].typeDec));}
#line 1696 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 132 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDecVec)->push_back((yyvsp[0].typeDec));}
#line 1702 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 139 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenClassDec(*(yyvsp[-4].args), *(yyvsp[-5].id), (yyvsp[-7].mods), *(yyvsp[-3].types), *(yyvsp[-1].classBlock)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-3].types)) DEL((yyvsp[-1].classBlock))}
#line 1708 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 141 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenProtocolDec(*(yyvsp[-4].args), *(yyvsp[-5].id), (yyvsp[-7].mods), *(yyvsp[-3].types), *(yyvsp[-1].classBlock)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-3].types)) DEL((yyvsp[-1].classBlock))}
#line 1714 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 143 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.typeDec) = new TokenEnumDec(*(yyvsp[-4].args), *(yyvsp[-5].id), *(yyvsp[-2].enumInstances)); DEL((yyvsp[-5].id)) DEL((yyvsp[-4].args)) DEL((yyvsp[-2].enumInstances))}
#line 1720 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 157 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) = (yyvsp[0].mod);}
#line 1726 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 158 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) |= (yyvsp[0].mod);}
#line 1732 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 159 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.mods) = 0;}
#line 1738 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 162 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = (yyvsp[-1].args);}
#line 1744 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 163 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1750 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 165 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType(*(yyvsp[0].id));}
#line 1756 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 168 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1762 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 169 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1768 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 170 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].type)->arrDims++;}
#line 1774 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 173 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1780 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 174 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].args)->args.push_back(*(yyvsp[0].arg)); DEL((yyvsp[0].arg))}
#line 1786 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 175 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.args) = new Args();}
#line 1792 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 177 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.arg) = new TokenArg(*(yyvsp[-2].id), *(yyvsp[0].type)); DEL((yyvsp[0].type)) DEL((yyvsp[-2].id))}
#line 1798 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 179 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1804 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 180 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = new TokenType();}
#line 1810 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 183 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.types) = new Types(*(yyvsp[0].type)); DEL((yyvsp[0].type))}
#line 1816 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 184 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].types)->types.push_back(*(yyvsp[0].type)); DEL((yyvsp[0].type))}
#line 1822 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 185 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.types) = new Types();}
#line 1828 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 188 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1834 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 189 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.type) = NULL;}
#line 1840 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 192 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].varDec));}
#line 1846 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 193 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock)->varDecs.push_back((yyvsp[0].varDec));}
#line 1852 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 194 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].funcDec));}
#line 1858 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 195 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].classBlock)->funcDecs.push_back((yyvsp[0].funcDec));}
#line 1864 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 196 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock();}
#line 1870 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 199 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock((yyvsp[0].stmt));}
#line 1876 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 200 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].block)->stmts.push_back((yyvsp[0].stmt));}
#line 1882 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 201 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock();}
#line 1888 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 206 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenReturn();}
#line 1894 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 207 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenReturn(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 1900 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 210 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.enumInstances) = new std::vector<TokenIdentifier>(); (yyval.enumInstances)->push_back(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1906 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 211 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].enumInstances)->push_back(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 1912 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 212 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.enumInstances) = new std::vector<TokenIdentifier>();}
#line 1918 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 215 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock((yyvsp[0].funcDec));}
#line 1924 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 216 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].block)->stmts.push_back((yyvsp[0].funcDec));}
#line 1930 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 217 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.block) = new TokenBlock();}
#line 1936 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 220 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].funcDec));}
#line 1942 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 221 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-1].classBlock)->funcDecs.push_back((yyvsp[0].funcDec));}
#line 1948 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 222 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock((yyvsp[0].varDecE));}
#line 1954 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 223 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock)->varDecs.push_back((yyvsp[0].varDecE));}
#line 1960 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 224 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.classBlock) = new ClassBlock();}
#line 1966 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 226 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.funcDec) = new TokenFuncDec((yyvsp[-7].mods), *(yyvsp[-5].id), *(yyvsp[-3].args), (yyvsp[-1].type) != NULL ? *(yyvsp[-1].type) : TokenType(), (yyvsp[0].type) != NULL ? *(yyvsp[0].type) : TokenType()); DEL((yyvsp[-5].id)) DEL((yyvsp[-3].args)) DEL((yyvsp[-1].type)) DEL((yyvsp[0].type))}
#line 1972 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 228 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-3].funcDec)->block = *(yyvsp[-1].block); DEL((yyvsp[-1].block))}
#line 1978 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 230 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {/*$1->block = TokenBlock();*/}
#line 1984 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 234 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDec((yyvsp[-2].mods), *(yyvsp[0].id), (yyvsp[-1].varDecKeyW)); DEL((yyvsp[0].id))}
#line 1990 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 236 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDecE) = new TokenVarDecExplicit((yyvsp[-1].varDec)->id, (yyvsp[-1].varDec)->decKeyword, *(yyvsp[0].type));  DEL((yyvsp[0].type))}
#line 1996 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 238 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDecExplicitAssign((yyvsp[-2].varDecE)->id, (yyvsp[-2].varDecE)->decKeyword, (yyvsp[-2].varDecE)->type, (yyvsp[0].expr));}
#line 2002 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 240 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.varDec) = new TokenVarDecImplicit((yyvsp[-2].varDec)->id, (yyvsp[-2].varDec)->decKeyword, (yyvsp[0].expr), (yyvsp[-2].varDec)->mods);}
#line 2008 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 252 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.exprVec) = new std::vector<TokenExpression>(); (yyval.exprVec)->push_back(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 2014 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 253 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-2].exprVec)->push_back(*(yyvsp[0].expr)); DEL((yyvsp[0].expr))}
#line 2020 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 254 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.exprVec) = new std::vector<TokenExpression>();}
#line 2026 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 257 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.funcCall) = new TokenFuncCall(*(yyvsp[-3].id), *(yyvsp[-1].exprVec)); DEL((yyvsp[-1].exprVec)) DEL((yyvsp[-3].id))}
#line 2032 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 258 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[0].funcCall)->prefix = *(yyvsp[-2].prefix); DEL((yyvsp[-2].prefix))}
#line 2038 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 261 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.var) = new TokenVariable(*(yyvsp[0].id)); DEL((yyvsp[0].id))}
#line 2044 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 262 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[-3].var)->arrExprs.push_back(*(yyvsp[-1].expr)); DEL((yyvsp[-1].expr))}
#line 2050 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 263 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyvsp[0].var)->prefix = *(yyvsp[-2].prefix); DEL((yyvsp[-2].prefix))}
#line 2056 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 265 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.stmt) = new TokenVarAssign(*(yyvsp[-2].var), (yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[-2].var)) DEL((yyvsp[0].expr))}
#line 2062 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 268 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprInfix(*(yyvsp[-2].expr), *(yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[-2].expr)) DEL((yyvsp[0].expr)) DEL((yyvsp[-1].op))}
#line 2068 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 269 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprPrefix(*(yyvsp[-1].op), *(yyvsp[0].expr)); DEL((yyvsp[0].expr)) DEL((yyvsp[-1].op))}
#line 2074 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 270 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprPostfix(*(yyvsp[-1].expr), *(yyvsp[0].op)); DEL((yyvsp[-1].expr)) DEL((yyvsp[0].op))}
#line 2080 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 271 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprInt((yyvsp[0].int32));}
#line 2086 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 272 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprStr((yyvsp[0].str));}
#line 2092 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 273 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprChar((yyvsp[0].ch));}
#line 2098 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 274 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprBool(true);}
#line 2104 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 275 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprBool(false);}
#line 2110 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 276 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprFloat((yyvsp[0].float32));}
#line 2116 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 277 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprFloat64((yyvsp[0].float64));}
#line 2122 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 278 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprLong((yyvsp[0].int64));}
#line 2128 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 279 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = new TokenExprTernary(*(yyvsp[-4].expr), *(yyvsp[-2].expr), *(yyvsp[0].expr)); DEL((yyvsp[-4].expr)) DEL((yyvsp[-2].expr)) DEL((yyvsp[0].expr))}
#line 2134 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 280 "grammar/AshGrammar.y" /* yacc.c:1661  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 2140 "src/parser/parser.cpp" /* yacc.c:1661  */
    break;


#line 2144 "src/parser/parser.cpp" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 291 "grammar/AshGrammar.y" /* yacc.c:1906  */

