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
    ID = 258,
    PRIMITIVE = 259,
    PUBLIC = 260,
    PRIVATE = 261,
    PROTECTED = 262,
    FINAL = 263,
    REQUIRED = 264,
    NATIVE = 265,
    OVERRIDE = 266,
    STANDARD = 267,
    STATIC = 268,
    STR = 269,
    CHAR = 270,
    INT = 271,
    LONG = 272,
    FLOAT = 273,
    FLOAT64 = 274,
    BOOL_TRUE = 275,
    BOOL_FALSE = 276,
    NAMESPACE = 277,
    PROTOCOL = 278,
    CLASS = 279,
    IMPORT = 280,
    ENUM = 281,
    VAR = 282,
    FUNC = 283,
    CONST = 284,
    BRACE_LEFT = 285,
    BRACE_RIGHT = 286,
    PAREN_LEFT = 287,
    PAREN_RIGHT = 288,
    COLON = 289,
    COMMA = 290,
    BRACKET_RIGHT = 291,
    BRACKET_LEFT = 292,
    QUESTION_MARK = 293,
    DOT = 294,
    ARROW = 295,
    OP_EQUAL = 296,
    OP_NEQUAL = 297,
    OP_LESS = 298,
    OP_LESS_EQ = 299,
    OP_GREATER = 300,
    OP_GREATER_EQ = 301,
    OP_ASSIGN = 302,
    OP_TYPE = 303,
    OP_ARROW = 304,
    OP_ASSIGN_PLUS = 305,
    OP_ASSIGN_MINUS = 306,
    OP_ASSIGN_MUL = 307,
    OP_ASSIGN_DIV = 308,
    OP_ASSIGN_MOD = 309,
    OP_ASSIGN_POW = 310,
    OP_ASSIGN_XOR = 311,
    OP_ASSIGN_AND = 312,
    OP_ASSIGN_OR = 313,
    OP_ASSIGN_LSHIFT = 314,
    OP_ASSIGN_RSHIFT = 315,
    OP_INC = 316,
    OP_DEC = 317,
    OP_PLUS = 318,
    OP_MINUS = 319,
    OP_MUL = 320,
    OP_DIV = 321,
    OP_MOD = 322,
    OP_POW = 323,
    OP_XOR = 324,
    OP_AND = 325,
    OP_OR = 326,
    OP_NOT = 327,
    OP_XNOR = 328,
    OP_NAND = 329,
    OP_NOR = 330,
    OP_LSHIFT = 331,
    OP_RSHIFT = 332,
    OP_COMPLEMENT = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "grammar/AshGrammar.y" /* yacc.c:1915  */

	std::string* str;
	int line;
	int token;
	int int32;
	long long int64;
	float float32;
	char ch;
	double float64;
	Operator* op;
	TokenIdentifier* id;
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
	TokenVarDecExplicit* varDecE;
	TokenExpression* expr;
	std::vector<TokenTypeDec*>* typeDecVec;
	TokenQualifiedName* qualifiedName;
	std::vector<TokenIdentifier*>* enumInstances;

#line 166 "grammar/parser.hpp" /* yacc.c:1915  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_PARSER_HPP_INCLUDED  */
