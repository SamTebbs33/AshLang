%{

	#include <string>
	#include <cstdlib>
	#include "parser/tokens.h"
	#include "parser/parser.hpp"

	#define SAVE_LINE yylval.line = lineNo;
	#define RET(a) SAVE_LINE; return a;
	#define SAVE_STR yylval.str = new std::string(yytext, yyleng);
	#define SAVE_INT(b) yylval.int32 = strtol(yytext, NULL, b);
	#define SAVE_FLOAT64 yylval.float64 = atof(yytext);
	#define SAVE_FLOAT yylval.float32 = (float)atof(yytext);
	#define SAVE_TOKEN(t) yylval.token = t;
	#define SAVE_CHAR yylval.ch = yytext[1];
	#define SAVE_OP yylval.op = new Operator(new std::string(yytext));
	#define SAVE_ID yylval.id = new TokenIdentifier(new std::string(yytext));
	#define SAVE_MOD yylval.mod = new TokenModifier(std::string(yytext));

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

0x({HexDigit})+					SAVE_INT(16); RET(INT);
0o({OctalDigit})+				SAVE_INT(8); RET(INT);
0b({BinaryDigit})+				SAVE_INT(2); RET(INT);
-?{DigitNonZero}({Digit})*		SAVE_INT(10); RET(INT);
0								SAVE_INT(10); RET(INT);
-?[0-9]+\.[0-9]+				SAVE_FLOAT64; RET(FLOAT64);
-?[0-9]+\.[0-9]+f				SAVE_FLOAT; RET(FLOAT);
-?[0-9]+\.[0-9]+e-?[0-9]+		SAVE_FLOAT64; RET(FLOAT64);
[\'][^\\'][\']					SAVE_CHAR; RET(CHAR);
[\"][^\\"]*[\"]					SAVE_STR; RET(STR);
"true"							RET(BOOL_TRUE);
"false"							RET(BOOL_FALSE);

[\n]							lineNo++;
"//"+.*							; // Single-line comment
"/*"((\*+[^/*])|([^*]))*\**"*/"	; // Multi-line comment
[ \t\n]+						;
<<EOF>>							lineNo = 0; return EOF;

("int"|"bool"|"int8"|"int16"|"int64"|"uint"|"uint8"|"uint16"|"uint64"|"float"|"float64"|"char")			SAVE_ID; return PRIMITIVE;

"public"						SAVE_MOD; RET(PUBLIC);
"private"						SAVE_MOD; RET(PRIVATE);
"protected"						SAVE_MOD; RET(PROTECTED);
"final"							SAVE_MOD; RET(FINAL);
"required"						SAVE_MOD; RET(REQUIRED);
"native"						SAVE_MOD; RET(NATIVE);
"override"						SAVE_MOD; RET(OVERRIDE);
"standard"						SAVE_MOD; RET(STANDARD);
"static"						SAVE_MOD; RET(STATIC);

"var"							RET(VAR);
"const"							RET(CONST);
"func"							RET(FUNC);
"class"							RET(CLASS);
"enum"							RET(ENUM);
"protocol"						RET(PROTOCOL);
"import"						RET(IMPORT);
"namespace"						RET(NAMESPACE);
"return"						RET(RETURN);

{Identifier}					SAVE_ID; return ID;

"="								SAVE_OP; return OP_ASSIGN;
":"								RET(COLON);
"++"							SAVE_OP; return OP_INC;
"--"							SAVE_OP; return OP_DEC;
"-="							SAVE_OP; return OP_ASSIGN_MINUS;
"+="							SAVE_OP; return OP_ASSIGN_PLUS;
"*="							SAVE_OP; return OP_ASSIGN_MUL;
"/="							SAVE_OP; return OP_ASSIGN_DIV;
"%="							SAVE_OP; return OP_ASSIGN_MOD;
"**="							SAVE_OP; return OP_ASSIGN_POW;
"^="							SAVE_OP; return OP_ASSIGN_XOR;
"&="							SAVE_OP; return OP_ASSIGN_AND;
"|="							SAVE_OP; return OP_ASSIGN_OR;
"<<="							SAVE_OP; return OP_ASSIGN_LSHIFT;
">>="							SAVE_OP; return OP_ASSIGN_RSHIFT;

"+"								SAVE_OP; return OP_PLUS;
"-"								SAVE_OP; return OP_MINUS;
"*"								SAVE_OP; return OP_MUL;
"/"								SAVE_OP; return OP_DIV;
"%"								SAVE_OP; return OP_MOD;
"**"							SAVE_OP; return OP_POW;

"^^"							SAVE_OP; return OP_XOR;
"&&"							SAVE_OP; return OP_AND;
"||"							SAVE_OP; return OP_OR;

"^"								SAVE_OP; return OP_XOR;
"&"								SAVE_OP; return OP_AND;
"|"								SAVE_OP; return OP_OR;
"<<" 							SAVE_OP; return OP_LSHIFT;
">>" 							SAVE_OP; return OP_RSHIFT;
"~" 							SAVE_OP; return OP_COMPLEMENT;
"==" 							SAVE_OP; return OP_EQUAL;
"!=" 							SAVE_OP; return OP_NEQUAL;
"<" 							SAVE_OP; return OP_LESS;
">" 							SAVE_OP; return OP_GREATER;
"<=" 							SAVE_OP; return OP_LESS_EQ;
">=" 							SAVE_OP; return OP_GREATER_EQ;

"=>"							RET(ARROW);
"{"								RET(BRACE_LEFT);
"}"				    			RET(BRACE_RIGHT);
"("								RET(PAREN_LEFT);
")"								RET(PAREN_RIGHT);
"["								RET(BRACKET_LEFT);
"]"								RET(BRACKET_RIGHT);
"."								RET(DOT);
","								RET(COMMA);
"?"								RET(QUESTION_MARK);
.				    			{ printf("Error:%d: Unexpected token %s\n", lineNo, yytext);  }

%%
