%{
	#include <string>
%}

%union{
	std::string str;
	int token;
	int int32;
	long long int64;
}

%token <str> QUALIFIED_NAME ID PUBLIC PRIVATE PROTECTED FINAL REQUIRED NATIVE OVERRIDE STANDARD
%token <str> STR
%token <int32> INT
%token <int64> LONG
%token <float32> FLOAT
%token <token> BOOL_TRUE BOOL_FALSE
%token <token> NAMESPACE PROTOCOL CLASS IMPORT ENUM
%token <token> BRACE_LEFT BRACE_RIGHT PAREN_LEFT PAREN_RIGHT COLON COMMA 

%%

file: namespace_dec imports type_decs ;

imports: import | imports import ;
import: IMPORT QUALIFIED_NAME ;
namespace_dec: NAMESPACE QUALIFIED_NAME | ;

type_decs: type_dec | type_decs type_dec;
type_dec: class_dec | protocol_dec | enum_dec ;
class_dec: type_mods CLASS ID type_args type_supers BRACE_LEFT class_block BRACE_RIGHT ; 
protocol_dec: type_mods PROTOCOL ID type_args type_supers protocol_block ;
enum_dec: ENUM ID type_args enum_block ;

type_mods: type_mod | type_mods type_mod ;
type_mod: PUBLIC | PRIVATE | PROTECTED | FINAL ;
class_func_mod: PUBLIC | PRIVATE | PROTECTED | FINAL | NATIVE | REQUIRED | STANDARD OVERRIDE ;
class_func_mods: class_func_mod | class_func_mods class_func_mod | ;
class_var_mod: PUBLIC | PRIVATE | PROTECTED | FINAL ;
class_var_mods: class_var_mod | class_var_mods class_var_mod | ;
func_var_mod: FINAL ;
func_var_mods: func_var_mod | func_var_mods func_var_mod | ;

type_args: PAREN_LEFT args PAREN_RIGHT | ;
args: arg | args arg ;
arg: ID COLON Type ;

func_type: COLON type | ; 
type_supers: func_type | type_supers COMMA type ;

class_block: class_stmt | class_block class_stmt ;
class_stmt: class_func_dec | class_var_dec ;
func_dec_block: func_stmt | func_dec_block func_stmt | ;
func_stmt: func_var_dec ;

func_dec: FUNC ID PAREN_LEFT args PAREN_RIGHT func_type ;
class_func_dec: class_func_mods func_dec BRACE_LEFT func_dec_block BRACE_RIGHT ;
var_dec_body: VAR ID ;
var_dec_explicit: var_dec_body func_type ;
var_dec_explicit_assign: var_dec_explicit ASSIGN expr ;
var_dec_implicit: var_dec_body ASSIGN expr ;
var_dec: var_dec_explicit | var_dec_explicit_assign | var_dec_implicit ;
class_var_dec: class_var_mods var_dec ;
func_var_dec: func_var_mods var_dec ;

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
op_infix: OP_XOR{$$ = new Operator(*$1);} | OP_AND{$$ = new Operator(*$1);} | OP_OR{$$ = new Operator(*$1);} | OP_XNOR{$$ = new Operator(*$1);} | OP_NAND{$$ = new Operator(*$1);} | OP_NOR{$$ = new Operator(*$1);} | OP_EQUAL{$$ = new Operator(*$1);} | OP_NEQUAL{$$ = new Operator(*$1);} | OP_LESS{$$ = new Operator(*$1);} | OP_LESS_EQ{$$ = new Operator(*$1);} | OP_GREATER{$$ = new Operator(*$1);} | OP_GREATER_EQ{$$ = new Operator(*$1);} | OP_PLUS{$$ = new Operator(*$1);} | OP_MINUS{$$ = new Operator(*$1);} | OP_MUL{$$ = new Operator(*$1);} | OP_DIV{$$ = new Operator(*$1);} | OP_POW{$$ = new Operator(*$1);} | OP_MOD{$$ = new Operator(*$1);} | OP_LSHIFT{$$ = new Operator(*$1);} | OP_RSHIFT{$$ = new Operator(*$1);} ;

op_prefix: OP_NOT{$$ = new Operator(*$1);} | OP_INC{$$ = new Operator(*$1);} | OP_DEC{$$ = new Operator(*$1);} | OP_COMPLEMENT {$$ = new Operator(*$1);} ;
op_postfix: OP_INC{$$ = new Operator(*$1);} | OP_DEC {$$ = new Operator(*$1);} ;

%%
