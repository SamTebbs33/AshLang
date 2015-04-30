%{

	#include <string>
	#include <cstdlib>
	#include "tokens.h"
	#include "parser.hpp"

	#define SAVE_LINE yylval.line = lineNo;
	#define SAVE_STR yylval.str = new std::string(yytext, yyleng); SAVE_LINE;
	#define SAVE_INT(b) yylval.int32 = atoi(yytext); SAVE_LINE;
	#define SAVE_FLOAT64 yylval.float64 = atof(yytext); SAVE_LINE;
	#define SAVE_FLOAT yylval.float32 = (float)atof(yytext); SAVE_LINE;
	#define SAVE_TOKEN(t) yylval.token = t; SAVE_LINE;
	#define SAVE_CHAR yylval.ch = yytext[1]; SAVE_LINE;
	#define SAVE_OP yylval.op = new Operator(new std::string(yytext));

	extern "C" int yywrap(){return 1;}
	extern int lineNo;

%}

%option yylineno

Identifier ([a-zA-Z]([a-zA-Z]|[0-9])*)
Digit ([0-9])
DigitNonZero ([1-9])
HexDigit ([a-fA-F0-9])
OctalDigit ([0-7])
BinaryDigit ([0|1])


%%

0x({HexDigit})+				SAVE_INT(16); return INT;
0o({OctalDigit})+				SAVE_INT(8); return INT;
0b({BinaryDigit})+				SAVE_INT(2); return INT;
-?{DigitNonZero}({Digit})*		SAVE_INT(10); return INT;
0					SAVE_INT(10); return INT;
-?[0-9]+\.[0-9]+	SAVE_FLOAT64; return FLOAT64;
-?[0-9]+\.[0-9]+f	SAVE_FLOAT; return FLOAT;
[\'][^\\'][\']		SAVE_CHAR; return CHAR;
[\"][^\\"]*[\"]		SAVE_STR; return STR;
"true"				return BOOL_TRUE;
"false"				return BOOL_FALSE;
[\n]				lineNo++;
"/*"((\*+[^/*])|([^*]))*\**"*/"	;
[ \t\n]+			;
<<EOF>>				lineNo = 0; return EOF;

"public"			SAVE_STR; return PUBLIC;
"private"			SAVE_STR; return PRIVATE;
"protected"			SAVE_STR; return PROTECTED;
"final"				SAVE_STR; return FINAL;
"required"			SAVE_STR; return REQUIRED;
"native"			SAVE_STR; return NATIVE;
"override"			SAVE_STR; return OVERRIDE;
"standard"			SAVE_STR; return STANDARD;
"static"			SAVE_STR; return STATIC;

"var"				return VAR;
"func"				return FUNC;
"class"				return CLASS;
"enum"				return ENUM;
"protocol"			return PROTOCOL;
"import"			return IMPORT;
"namespace"			return NAMESPACE;

{Identifier}		SAVE_STR; return ID;

"="					SAVE_OP; return OP_ASSIGN;
":"					return COLON;
"++"				SAVE_OP; return OP_INC;
"--"				SAVE_OP; return OP_DEC;
"-="				SAVE_OP; return OP_ASSIGN_MINUS;
"+="				SAVE_OP; return OP_ASSIGN_PLUS;
"*="				SAVE_OP; return OP_ASSIGN_MUL;
"/="				SAVE_OP; return OP_ASSIGN_DIV;
"%="				SAVE_OP; return OP_ASSIGN_MOD;
"**="				SAVE_OP; return OP_ASSIGN_POW;
"^="				SAVE_OP; return OP_ASSIGN_XOR;
"&="				SAVE_OP; return OP_ASSIGN_AND;
"|="				SAVE_OP; return OP_ASSIGN_OR;
"<<="				SAVE_OP; return OP_ASSIGN_LSHIFT;
">>="				SAVE_OP; return OP_ASSIGN_RSHIFT;

"+"					SAVE_OP; return OP_PLUS;
"-"					SAVE_OP; return OP_MINUS;
"*"					SAVE_OP; return OP_MUL;
"/"					SAVE_OP; return OP_DIV;
"%"					SAVE_OP; return OP_MOD;
"**"				SAVE_OP; return OP_POW;

"^^"				SAVE_OP; return OP_XOR;
"&&"				SAVE_OP; return OP_AND;
"||"				SAVE_OP; return OP_OR;

"^"					SAVE_OP; return OP_XOR;
"&"					SAVE_OP; return OP_AND;	
"|"					SAVE_OP; return OP_OR; 
"<<" 				SAVE_OP; return OP_LSHIFT;
">>" 				SAVE_OP; return OP_RSHIFT;
"~" 				SAVE_OP; return OP_COMPLEMENT;
"==" 				SAVE_OP; return OP_EQUAL;
"!=" 				SAVE_OP; return OP_NEQUAL;
"<" 				SAVE_OP; return OP_LESS;
">" 				SAVE_OP; return OP_GREATER;
"<=" 				SAVE_OP; return OP_LESS_EQ;
">=" 				SAVE_OP; return OP_GREATER_EQ;

"{"					return BRACE_LEFT;
"}"				    return BRACE_RIGHT;
"("					return PAREN_LEFT;
")"					return PAREN_RIGHT;
"["					return BRACKET_LEFT;
"]"					return BRACKET_RIGHT;
"."					return DOT;
","					return COMMA;
"?"					return QUESTION_MARK;
.				    { printf("Error:%d:%s\n", lineNo, yytext);  }	

%%
