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

#ifndef YY_YY_GRAMMAR_PARSER_HPP_INCLUDED
# define YY_YY_GRAMMAR_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    QUALIFIED_NAME = 258,
    ID = 259,
    PUBLIC = 260,
    PRIVATE = 261,
    PROTECTED = 262,
    FINAL = 263,
    REQUIRED = 264,
    NATIVE = 265,
    OVERRIDE = 266,
    STANDARD = 267,
    STR = 268,
    CHAR = 269,
    INT = 270,
    LONG = 271,
    FLOAT = 272,
    FLOAT64 = 273,
    BOOL_TRUE = 274,
    BOOL_FALSE = 275,
    NAMESPACE = 276,
    PROTOCOL = 277,
    CLASS = 278,
    IMPORT = 279,
    ENUM = 280,
    VAR = 281,
    FUNC = 282,
    BRACE_LEFT = 283,
    BRACE_RIGHT = 284,
    PAREN_LEFT = 285,
    PAREN_RIGHT = 286,
    COLON = 287,
    COMMA = 288,
    BRACKET_RIGHT = 289,
    BRACKET_LEFT = 290,
    QUESTION_MARK = 291,
    DOT = 292,
    OP_EQUAL = 293,
    OP_NEQUAL = 294,
    OP_LESS = 295,
    OP_LESS_EQ = 296,
    OP_GREATER = 297,
    OP_GREATER_EQ = 298,
    OP_ASSIGN = 299,
    OP_TYPE = 300,
    OP_THROWS = 301,
    OP_ASSIGN_PLUS = 302,
    OP_ASSIGN_MINUS = 303,
    OP_ASSIGN_MUL = 304,
    OP_ASSIGN_DIV = 305,
    OP_ASSIGN_MOD = 306,
    OP_ASSIGN_POW = 307,
    OP_ASSIGN_XOR = 308,
    OP_ASSIGN_AND = 309,
    OP_ASSIGN_OR = 310,
    OP_ASSIGN_LSHIFT = 311,
    OP_ASSIGN_RSHIFT = 312,
    OP_INC = 313,
    OP_DEC = 314,
    OP_PLUS = 315,
    OP_MINUS = 316,
    OP_MUL = 317,
    OP_DIV = 318,
    OP_MOD = 319,
    OP_POW = 320,
    OP_XOR = 321,
    OP_AND = 322,
    OP_OR = 323,
    OP_NOT = 324,
    OP_XNOR = 325,
    OP_NAND = 326,
    OP_NOR = 327,
    OP_LSHIFT = 328,
    OP_RSHIFT = 329,
    OP_COMPLEMENT = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "grammar/AshGrammar.y" /* yacc.c:1915  */

	std::string* str;
	int line;
	int token;
	int int32;
	long long int64;
	float float32;
	char ch;
	double float64;
	Operator* op;
	TokenFile* file;
	TokenNamespace* namesp;
	TokenImport* import;
	Imports* imports;
	TokenTypeDec* typeDec;
	TokenModifier* mod;
	Modifiers* mods;
	TokenFuncDec* funcDec;
	TokenArg* arg;
	Args* args;
	TokenType* type;
	Types* types;
	TokenBlock* block;
	TokenStatement* stmt;
	TokenVarDec* varDec;
	TokenExpression* expr;
	std::vector<TokenTypeDec*>* typeDecVec;

#line 159 "grammar/parser.hpp" /* yacc.c:1915  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_PARSER_HPP_INCLUDED  */
