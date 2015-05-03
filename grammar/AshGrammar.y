%{
	#include <string>
	#include <stdio.h>
	#include <locale>
	#include "tokens.h"
	#define YYERROR_VERBOSE

	char* toLower(char* str){
		char* original = str;
		while(*str){
			*str = tolower(*str);
			str++;
		}
		return original;
	}

	extern int yylex();
	extern int yylineno;
	extern const char* yytext;
	void yyerror(const char* s){printf("Error:%d: %s\n", yylineno, s);}
	int lineNo = 0;
%}

%union{
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
}

%token <id> ID PRIMITIVE
%token <mod> PUBLIC PRIVATE PROTECTED FINAL REQUIRED NATIVE OVERRIDE STANDARD STATIC 
%token <str> STR
%token <ch> CHAR
%token <int32> INT
%token <int64> LONG
%token <float32> FLOAT
%token <float64> FLOAT64
%token <token> BOOL_TRUE BOOL_FALSE
%token <token> NAMESPACE PROTOCOL CLASS IMPORT ENUM VAR FUNC CONST
%token <token> BRACE_LEFT BRACE_RIGHT PAREN_LEFT PAREN_RIGHT COLON COMMA BRACKET_RIGHT BRACKET_LEFT QUESTION_MARK DOT ARROW
%token <op> OP_EQUAL OP_NEQUAL OP_LESS OP_LESS_EQ OP_GREATER OP_GREATER_EQ
%token <op> OP_ASSIGN OP_TYPE OP_ARROW OP_ASSIGN_PLUS OP_ASSIGN_MINUS OP_ASSIGN_MUL OP_ASSIGN_DIV OP_ASSIGN_MOD OP_ASSIGN_POW OP_ASSIGN_XOR OP_ASSIGN_AND OP_ASSIGN_OR OP_ASSIGN_LSHIFT OP_ASSIGN_RSHIFT OP_INC OP_DEC
%token <op> OP_PLUS OP_MINUS OP_MUL OP_DIV OP_MOD OP_POW
%token <op> OP_XOR OP_AND OP_OR OP_NOT OP_XNOR OP_NAND OP_NOR
%token <op> OP_LSHIFT OP_RSHIFT OP_COMPLEMENT

%type <op> op_infix op_prefix op_postfix
%type <file> file
%type <namesp> namespace_dec
%type <import> import
%type <imports> imports
%type <typeDecVec> type_decs
%type <typeDec> type_dec class_dec protocol_dec enum_dec
%type <mod> type_mod class_func_mod class_var_mod func_var_mod
%type <mods> type_mods class_func_mods class_var_mods func_var_mods
%type <funcDec> class_func_dec protocol_func_dec func_dec
%type <arg> arg
%type <args> args type_args
%type <type> type func_type throws
%type <types> type_supers
%type <block> class_block protocol_block enum_block func_dec_block
%type <stmt> class_stmt protocol_stmt enum_stmt func_stmt
%type <varDec> var_dec_body var_dec_explicit_assign var_dec_implicit class_var_dec protcol_var_dec func_var_dec var_dec
%type <varDecE> var_dec_explicit
%type <expr> expr
%type <qualifiedName> qualified_name
%type <enumInstances> enum_instances

%start file

%%

file: namespace_dec imports type_decs {$$ = new TokenFile($1, $2, $3);} ;

imports: import {$$ = new Imports($1);} | imports import {$1->imports->push_back($2);} | {$$ = new Imports();};
import: IMPORT qualified_name {$$ = new TokenImport($2);} ;
qualified_name: ID {$$ = new TokenQualifiedName($1);} | qualified_name DOT ID {$1->paths->push_back($3->str);};
namespace_dec: NAMESPACE qualified_name {$$ = new TokenNamespace($2);} | {$$ = new TokenNamespace();} ;

type_decs: type_dec  {$$ = new std::vector<TokenTypeDec*>(); $$->push_back($1);} | type_decs type_dec {$$->push_back($2);} ;
type_dec: class_dec | protocol_dec | enum_dec ;
class_dec: type_mods CLASS ID type_args type_supers BRACE_LEFT class_block BRACE_RIGHT {$$ = new TokenClassDec($4, $3, $1, $7, $5);} ; 
protocol_dec: type_mods PROTOCOL ID type_args type_supers BRACE_LEFT protocol_block BRACE_RIGHT {$$ = new TokenProtocolDec($4, $3, $1, $7, $5);} ;
enum_dec: ENUM ID type_args BRACE_LEFT enum_instances enum_block BRACE_RIGHT {$$ = new TokenEnumDec($3, $2, $5, $6);} ;

type_mods: type_mod {$$ = new Modifiers($1);}  | type_mods type_mod {$1->mods->push_back($2);} | {$$ = new Modifiers();} ;
type_mod: PUBLIC | PRIVATE | PROTECTED | FINAL ;
class_func_mod: PUBLIC | PRIVATE | PROTECTED | FINAL | NATIVE | REQUIRED | STANDARD | STATIC | OVERRIDE ;
class_func_mods: class_func_mod {$$ = new Modifiers($1);}  | class_func_mods class_func_mod {$1->mods->push_back($2);}  | {$$ = new Modifiers();} ;
class_var_mod: PUBLIC | PRIVATE | PROTECTED ;
class_var_mods: class_var_mod {$$ = new Modifiers($1);} | class_var_mods class_var_mod {$1->mods->push_back($2);} | {$$ = new Modifiers();} ;

type_args: PAREN_LEFT args PAREN_RIGHT {$$ = $2;} | {$$ = new Args();} ;
type: ID {$$ = new TokenType($1);} | PRIMITIVE {$$ = new TokenType($1);} | type BRACKET_LEFT BRACKET_RIGHT {$1->arrDims++;} ;
args: arg {$$ = new Args();} | args COMMA arg {$1->args->push_back($3);} | {$$ = new Args();} ;
arg: ID COLON type {$$ = new TokenArg($1, $3);} ;

func_type: COLON type {$$ = $2;} | {$$ = NULL;} ; 
type_supers: func_type {$$ = new Types($1);} | type_supers COMMA type {$1->types->push_back($3);} ;
throws: ARROW type {$$ = $2;} | {$$ = NULL;} ;

class_block: class_stmt {$$ = new TokenBlock($1);} | class_block class_stmt {$1->stmts->push_back($2);} | {$$ = new TokenBlock();} ;
class_stmt: class_func_dec | class_var_dec ;
func_dec_block: func_stmt {$$ = new TokenBlock($1);} | func_dec_block func_stmt {$1->stmts->push_back($2);} | {$$ = new TokenBlock();} ;
func_stmt: var_dec ;
enum_instances: ID {$$ = new std::vector<TokenIdentifier*>(); $$->push_back($1);} | enum_instances COMMA ID {$1->push_back($3);} | {$$ = new std::vector<TokenIdentifier*>();} ;
enum_block: enum_stmt {$$ = new TokenBlock($1);} | enum_block enum_stmt {$1->stmts->push_back($2);} |  {$$ = new TokenBlock();} ;
enum_stmt: class_stmt ;
protocol_block: protocol_stmt {$$ = new TokenBlock($1);} | protocol_block protocol_stmt {$1->stmts->push_back($2);} | {$$ = new TokenBlock();} ;
protocol_stmt: protocol_var_dec | protocol_func_dec ;

func_dec: FUNC ID PAREN_LEFT args PAREN_RIGHT func_type throws {$$ = new TokenFuncDec($2, $4, $6, $7);} ;
class_func_dec: class_func_mods func_dec BRACE_LEFT func_dec_block BRACE_RIGHT {$2->mods = $1; $2->block = $4;} ;
protocol_func_dec: class_func_mods func_dec {$2->mods = $1; $2->block = new TokenBlock();} ;
var_dec_body: VAR ID {$$ = new TokenVarDec($2, EnumVarDecKeyword::VAR);} | CONST ID {$$ = new TokenVarDec($2, EnumVarDecKeyword::CONST);} ;
var_dec_explicit: var_dec_body func_type {$$ = new TokenVarDecExplicit($1->id, $1->decKeyword, $2);} ;
var_dec_explicit_assign: var_dec_explicit OP_ASSIGN expr {$$ = new TokenVarDecExplicitAssign($1->id, $1->decKeyword, $1->type, $3);} ;
var_dec_implicit: var_dec_body OP_ASSIGN expr {$$ = new TokenVarDecImplicit($1->id, $1->decKeyword, $3);} ;
var_dec: var_dec_explicit | var_dec_explicit_assign | var_dec_implicit ;
class_var_dec: class_var_mods var_dec {$2->mods = $1;} ;
protocol_var_dec: class_var_mods var_dec_explicit {$2->mods = $1;} ;

expr: expr op_infix expr {$$ = new TokenExprInfix($1, $2, $3);}
	| op_prefix expr {$$ = new TokenExprPrefix($1, $2);}
	| expr op_postfix {$$ = new TokenExprPostfix($1, $2);}
	| INT {$$ = new TokenExprInt($1);}
	| STR {$$ = new TokenExprStr($1);}
	| CHAR {$$ = new TokenExprChar($1);}
	| BOOL_TRUE {$$ = new TokenExprBool(true);}
	| BOOL_FALSE {$$ = new TokenExprBool(false);}
	| FLOAT {$$ = new TokenExprFloat($1);}
	| FLOAT64 {$$ = new TokenExprFloat64($1);}
	| LONG {$$ = new TokenExprLong($1);}
	| expr QUESTION_MARK expr COLON expr {$$ = new TokenExprTernary($1, $3, $5);}
	| PAREN_LEFT expr PAREN_RIGHT {$$ = $2;}
	;
op_infix: OP_XOR | OP_AND | OP_OR | OP_XNOR | OP_NAND | OP_NOR | OP_EQUAL | OP_NEQUAL | OP_LESS | OP_LESS_EQ | OP_GREATER | OP_GREATER_EQ | OP_PLUS | OP_MINUS | OP_MUL | OP_DIV | OP_POW | OP_MOD | OP_LSHIFT | OP_RSHIFT ;

op_prefix: OP_NOT | OP_INC | OP_DEC | OP_COMPLEMENT  ;
op_postfix: OP_INC | OP_DEC  ;

%%
