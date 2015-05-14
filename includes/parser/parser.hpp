/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "grammar/AshGrammar.y" /* yacc.c:1915  */

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


#line 173 "src/parser/parser.hpp" /* yacc.c:1915  */
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
