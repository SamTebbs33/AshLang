#include <semantics/semantics.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>

bool Semantics::checkTypeExists(std::string shortName){
    if(!Members::typeExists(shortName)){
        Error::semanticError("Type doesn't exist or isn't visible from the current context (" + shortName + ")");
        return false;
    }
    return true;
}
