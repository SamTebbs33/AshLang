%{
	#include <string.h>
%}

%union{
	std::string str;
}

%token <str> NAMESPACE QUALIFIED_NAME

%%

file: namespace_dec ;
namespace_dec: NAMESPACE QUALIFIED_NAME | ;

%%
