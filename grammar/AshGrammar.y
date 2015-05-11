%{
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

}

%token <id> ID PRIMITIVE
%token <varDecKeyW> CONST VAR
%token <mod> PUBLIC PRIVATE PROTECTED FINAL REQUIRED NATIVE OVERRIDE STANDARD STATIC
%token <str> STR
%token <ch> CHAR
%token <int32> INT
%token <int64> LONG
%token <float32> FLOAT
%token <float64> FLOAT64
%token <token> BOOL_TRUE BOOL_FALSE
%token <token> NAMESPACE PROTOCOL CLASS IMPORT ENUM FUNC RETURN
%token <token> BRACE_LEFT BRACE_RIGHT PAREN_LEFT PAREN_RIGHT COLON COMMA BRACKET_RIGHT BRACKET_LEFT QUESTION_MARK DOT ARROW
%token <op> OP_EQUAL OP_NEQUAL OP_LESS OP_LESS_EQ OP_GREATER OP_GREATER_EQ
%token <op> OP_ASSIGN OP_TYPE OP_ARROW OP_ASSIGN_PLUS OP_ASSIGN_MINUS OP_ASSIGN_MUL OP_ASSIGN_DIV OP_ASSIGN_MOD OP_ASSIGN_POW OP_ASSIGN_XOR OP_ASSIGN_AND OP_ASSIGN_OR OP_ASSIGN_LSHIFT OP_ASSIGN_RSHIFT OP_INC OP_DEC
%token <op> OP_PLUS OP_MINUS OP_MUL OP_DIV OP_MOD OP_POW
%token <op> OP_XOR OP_AND OP_OR OP_NOT OP_XNOR OP_NAND OP_NOR
%token <op> OP_LSHIFT OP_RSHIFT OP_COMPLEMENT

%type <op> op_infix op_prefix op_postfix op_assign
%type <namesp> namespace_dec
%type <import> import
%type <imports> imports
%type <typeDecVec> type_decs
%type <typeDec> type_dec class_dec protocol_dec enum_dec
%type <mod> mod
%type <mods> mods
%type <funcDec> class_func_dec protocol_func_dec func_dec
%type <arg> arg
%type <args> args type_args
%type <type> type func_type throws
%type <types> type_supers
%type <block> enum_block func_dec_block class_block protocol_block
%type <stmt> class_stmt protocol_stmt enum_stmt func_stmt var_assign
%type <varDec> var_dec_body var_dec_explicit_assign var_dec_implicit class_var_dec protocol_var_dec var_dec
%type <varDecE> var_dec_explicit
%type <expr> expr
%type <var> var
%type <qualifiedName> qualified_name
%type <enumInstances> enum_instances
%type <exprVec> func_call_args
%type <funcCall> func_call
%type <prefix> prefix
%type <varDecKeyW> var_dec_keyw

%debug
%error-verbose
%start file

%%

file: namespace_dec imports type_decs {file = TokenFile(*$1, *$2, *$3); DEL($1) DEL($2) DEL($3)} ;

imports: import {$$ = new Imports(*$1); DEL($1)} | imports import {$1->imports.push_back(*$2); DEL($2)} | {$$ = new Imports();};
import: IMPORT qualified_name {$$ = new TokenImport(*$2); DEL($2)} ;
qualified_name: ID {$$ = new TokenQualifiedName(*$1); DEL($1)} | qualified_name DOT ID {$1->paths.push_back(*$3->str); DEL($3)};
namespace_dec: NAMESPACE qualified_name {$$ = new TokenNamespace(*$2); DEL($2)} | {$$ = new TokenNamespace();} ;

type_decs: type_dec  {$$ = new std::vector<TokenTypeDec*>(); $$->push_back($1);} | type_decs type_dec {$$->push_back($2);} ;
type_dec: class_dec | protocol_dec | enum_dec ;
class_dec: mods CLASS ID type_args type_supers BRACE_LEFT class_block BRACE_RIGHT {$$ = new TokenClassDec(*$4, *$3, $1, *$7, *$5); DEL($3) DEL($4) DEL($5) DEL($7)} ;
protocol_dec: mods PROTOCOL ID type_args type_supers BRACE_LEFT protocol_block BRACE_RIGHT {$$ = new TokenProtocolDec(*$4, *$3, $1, *$7, *$5); DEL($3) DEL($4) DEL($5) DEL($7)} ;
enum_dec: ENUM ID type_args BRACE_LEFT enum_instances enum_block BRACE_RIGHT {$$ = new TokenEnumDec(*$3, *$2, *$5, *$6); DEL($2) DEL($3) DEL($5) DEL($6)} ;

mod: PUBLIC | PRIVATE | PROTECTED | FINAL | NATIVE | REQUIRED | STANDARD | STATIC | OVERRIDE ;
mods: mod {$$ = $1;} | mods mod {$$ |= $2;}  | {$$ = 0;} ;

type_args: PAREN_LEFT args PAREN_RIGHT {$$ = $2;} | {$$ = new Args();} ;
type: ID {$$ = new TokenType(*$1); DEL($1)} | PRIMITIVE {$$ = new TokenType(*$1); DEL($1)} | type BRACKET_LEFT BRACKET_RIGHT {$1->arrDims++;} ;
args: arg {$$ = new Args();} | args COMMA arg {$1->args.push_back(*$3); DEL($3)} | {$$ = new Args();} ;
arg: ID COLON type {$$ = new TokenArg(*$1, *$3); DEL($3) DEL($1)} ;

func_type: COLON type {$$ = $2;} | {$$ = NULL;} ;
type_supers: func_type {$$ = new Types($1 != NULL ? *$1 : TokenType()); DEL($1)} | type_supers COMMA type {$1->types.push_back(*$3); DEL($3)} ;
throws: ARROW type {$$ = $2;} | {$$ = NULL;} ;

class_block: class_stmt {$$ = new TokenBlock($1);} | class_block class_stmt {$1->stmts.push_back($2);} | {$$ = new TokenBlock();} ;
class_stmt: class_func_dec | class_var_dec ;
func_dec_block: func_stmt {$$ = new TokenBlock($1);} | func_dec_block func_stmt {$1->stmts.push_back($2);} | {$$ = new TokenBlock();} ;
func_stmt: var_assign | var_dec | RETURN {$$ = new TokenReturn();} | RETURN expr {$$ = new TokenReturn(*$2); DEL($2)} ;
enum_instances: ID {$$ = new std::vector<TokenIdentifier>(); $$->push_back(*$1); DEL($1)} | enum_instances COMMA ID {$1->push_back(*$3); DEL($3)} | {$$ = new std::vector<TokenIdentifier>();} ;
enum_block: enum_stmt {$$ = new TokenBlock($1);} | enum_block enum_stmt {$1->stmts.push_back($2);} |  {$$ = new TokenBlock();} ;
enum_stmt: class_stmt ;
protocol_block: protocol_stmt {$$ = new TokenBlock($1);} | protocol_block protocol_stmt {$1->stmts.push_back($2);} | {$$ = new TokenBlock();} ;
protocol_stmt: protocol_var_dec | protocol_func_dec ;

func_dec: mods FUNC ID PAREN_LEFT args PAREN_RIGHT func_type throws {$$ = new TokenFuncDec($1, *$3, *$5, $7 != NULL ? *$7 : TokenType(), $8 != NULL ? *$8 : TokenType()); DEL($3) DEL($5) DEL($7) DEL($8)} ;
class_func_dec: func_dec BRACE_LEFT func_dec_block BRACE_RIGHT {$1->block = *$3; DEL($3)} ;
protocol_func_dec: func_dec {/*$1->block = TokenBlock();*/} ;
var_dec_keyw: CONST | VAR ;
var_dec_body: mods var_dec_keyw ID {$$ = new TokenVarDec($1, *$3, $2); DEL($3)} ;
var_dec_explicit: var_dec_body func_type {$$ = new TokenVarDecExplicit($1->id, $1->decKeyword, *$2);  DEL($2)};
var_dec_explicit_assign: var_dec_explicit OP_ASSIGN expr {$$ = new TokenVarDecExplicitAssign($1->id, $1->decKeyword, $1->type, *$3); DEL($3)} ;
var_dec_implicit: var_dec_body OP_ASSIGN expr {$$ = new TokenVarDecImplicit($1->id, $1->decKeyword, *$3, $1->mods); DEL($3)} ;
var_dec: var_dec_explicit | var_dec_explicit_assign | var_dec_implicit ;
class_var_dec: var_dec ;
protocol_var_dec: var_dec_explicit ;

prefix: var | func_call ;
func_call_args: expr {$$ = new std::vector<TokenExpression>(); $$->push_back(*$1); DEL($1)} | func_call_args COMMA expr {$1->push_back(*$3); DEL($3)} | {$$ = new std::vector<TokenExpression>();} ;
func_call: ID PAREN_LEFT func_call_args PAREN_RIGHT {$$ = new TokenFuncCall(*$1, *$3); DEL($3) DEL($1)} | prefix DOT func_call {$3->prefix = *$1; DEL($1)} ;
var: ID {$$ = new TokenVariable(*$1); DEL($1)} | var PAREN_LEFT expr PAREN_RIGHT {$1->arrExprs.push_back(*$3); DEL($3)} | prefix DOT var {$3->prefix = *$1; DEL($1)} ;
var_assign: var op_assign expr {$$ = new TokenVarAssign(*$1, $2, *$3); DEL($1) DEL($3)} ;

expr: expr op_infix expr {$$ = new TokenExprInfix(*$1, *$2, *$3); DEL($1) DEL($3) DEL($2)}
	| op_prefix expr {$$ = new TokenExprPrefix(*$1, *$2); DEL($2) DEL($1)}
	| expr op_postfix {$$ = new TokenExprPostfix(*$1, *$2); DEL($1) DEL($2)}
	| INT {$$ = new TokenExprInt($1);}
	| STR {$$ = new TokenExprStr($1);}
	| CHAR {$$ = new TokenExprChar($1);}
	| BOOL_TRUE {$$ = new TokenExprBool(true);}
	| BOOL_FALSE {$$ = new TokenExprBool(false);}
	| FLOAT {$$ = new TokenExprFloat($1);}
	| FLOAT64 {$$ = new TokenExprFloat64($1);}
	| LONG {$$ = new TokenExprLong($1);}
	| expr QUESTION_MARK expr COLON expr {$$ = new TokenExprTernary(*$1, *$3, *$5); DEL($1) DEL($3) DEL($5)}
	| PAREN_LEFT expr PAREN_RIGHT {$$ = $2;}
	| var
	| func_call
	;

op_assign: OP_ASSIGN | OP_ASSIGN_MINUS | OP_ASSIGN_PLUS | OP_ASSIGN_MUL | OP_ASSIGN_DIV | OP_ASSIGN_MOD | OP_ASSIGN_OR | OP_ASSIGN_AND | OP_ASSIGN_POW | OP_ASSIGN_XOR | OP_ASSIGN_LSHIFT | OP_ASSIGN_RSHIFT ;
op_infix: OP_XOR | OP_AND | OP_OR | OP_XNOR | OP_NAND | OP_NOR | OP_EQUAL | OP_NEQUAL | OP_LESS | OP_LESS_EQ | OP_GREATER | OP_GREATER_EQ | OP_PLUS | OP_MINUS | OP_MUL | OP_DIV | OP_POW | OP_MOD | OP_LSHIFT | OP_RSHIFT ;

op_prefix: OP_NOT | OP_INC | OP_DEC | OP_COMPLEMENT  ;
op_postfix: OP_INC | OP_DEC  ;

%%
