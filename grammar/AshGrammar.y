%{
	#include <string>
	#include <stdio.h>
	#include "tokens.h"
	#define YYERROR_VERBOSE
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
	TokenQualifiedName* qualifiedName;
}

%token <str> ID PUBLIC PRIVATE PROTECTED FINAL REQUIRED NATIVE OVERRIDE STANDARD STATIC
%token <str> STR
%token <ch> CHAR
%token <int32> INT
%token <int64> LONG
%token <float32> FLOAT
%token <float64> FLOAT64
%token <token> BOOL_TRUE BOOL_FALSE
%token <token> NAMESPACE PROTOCOL CLASS IMPORT ENUM VAR FUNC
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
%type <typedec> type_dec class_dec protocol_dec enum_dec
%type <mod> type_mod class_func_mod class_var_mod func_var_mod
%type <mods> type_mods class_func_mods class_var_mods func_var_mods
%type <funcDec> class_func_dec protocol_func_dec
%type <arg> arg
%type <args> args
%type <type> type
%type <types> type_supers
%type <block> class_block protocol_block enum_block 
%type <stmt> class_stmt protocol_stmt enum_stmt
%type <varDec> var_dec_explicit_assign var_dec_explicit var_dec_implicit class_var_dec protcol_var_dec func_var_dec
%type <expr> expr
%type <qualifiedName> qualified_name

%start file

%%

file: namespace_dec imports type_decs ;

imports: import | imports import | ;
import: IMPORT qualified_name ;
qualified_name: ID | qualified_name DOT ID ;
namespace_dec: NAMESPACE qualified_name | ;

type_decs: type_dec | type_decs type_dec;
type_dec: class_dec | protocol_dec | enum_dec ;
class_dec: type_mods CLASS ID type_args type_supers BRACE_LEFT class_block BRACE_RIGHT ; 
protocol_dec: type_mods PROTOCOL ID type_args type_supers BRACE_LEFT protocol_block BRACE_RIGHT ;
enum_dec: ENUM ID type_args BRACE_LEFT enum_instances enum_block BRACE_RIGHT ;

type_mods: type_mod | type_mods type_mod | ;
type_mod: PUBLIC | PRIVATE | PROTECTED | FINAL ;
class_func_mod: PUBLIC | PRIVATE | PROTECTED | FINAL | NATIVE | REQUIRED | STANDARD | STATIC | OVERRIDE ;
class_func_mods: class_func_mod | class_func_mods class_func_mod | ;
class_var_mod: PUBLIC | PRIVATE | PROTECTED | FINAL ;
class_var_mods: class_var_mod | class_var_mods class_var_mod | ;
func_var_mod: FINAL ;
func_var_mods: func_var_mod | func_var_mods func_var_mod | ;

type_args: PAREN_LEFT args PAREN_RIGHT | ;
type: ID | type BRACKET_LEFT BRACKET_RIGHT
args: arg | args COMMA arg | ;
arg: ID COLON type ;

func_type: COLON type | ; 
type_supers: func_type | type_supers COMMA type ;
throws: ARROW type | ;

class_block: class_stmt | class_block class_stmt | ;
class_stmt: class_func_dec | class_var_dec ;
func_dec_block: func_stmt | func_dec_block func_stmt | ;
func_stmt: func_var_dec ;
enum_instances: ID | enum_instances COMMA ID | ;
enum_block: enum_stmt | enum_block enum_stmt | ;
enum_stmt: class_stmt ;
protocol_block: protocol_stmt | protocol_block protocol_stmt | ;
protocol_stmt: protocol_var_dec | protocol_func_dec ;

func_dec: FUNC ID PAREN_LEFT args PAREN_RIGHT func_type throws ;
class_func_dec: class_func_mods func_dec BRACE_LEFT func_dec_block BRACE_RIGHT ;
protocol_func_dec: class_func_mods func_dec ;
var_dec_body: VAR ID ;
var_dec_explicit: var_dec_body func_type ;
var_dec_explicit_assign: var_dec_explicit OP_ASSIGN expr ;
var_dec_implicit: var_dec_body OP_ASSIGN expr ;
var_dec: var_dec_explicit | var_dec_explicit_assign | var_dec_implicit ;
class_var_dec: class_var_mods var_dec ;
func_var_dec: func_var_mods var_dec ;
protocol_var_dec: class_var_mods var_dec_explicit ;

expr: expr op_infix expr
	| op_prefix expr 
	| expr op_postfix
	| INT
	| STR
	| CHAR
	| BOOL_TRUE
	| BOOL_FALSE
	| FLOAT
	| LONG
	| expr QUESTION_MARK expr COLON expr
	| PAREN_LEFT expr PAREN_RIGHT
	;
op_infix: OP_XOR | OP_AND | OP_OR | OP_XNOR | OP_NAND | OP_NOR | OP_EQUAL | OP_NEQUAL | OP_LESS | OP_LESS_EQ | OP_GREATER | OP_GREATER_EQ | OP_PLUS | OP_MINUS | OP_MUL | OP_DIV | OP_POW | OP_MOD | OP_LSHIFT | OP_RSHIFT ;

op_prefix: OP_NOT | OP_INC | OP_DEC | OP_COMPLEMENT  ;
op_postfix: OP_INC | OP_DEC  ;

%%
