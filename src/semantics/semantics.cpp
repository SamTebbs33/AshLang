#include <semantics/semantics.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>
#include <util/util.hpp>

bool Semantics::checkTypeExists(std::string shortName){
    if(!Members::typeExists(shortName)){
        Error::semanticError("Type doesn't exist or isn't visible from the current context (" + shortName + ")");
        return false;
    }
    return true;
}

bool Semantics::checkSuperIsNotCurrentType(std::string shortName){
    if(Members::getCurrentTypeQualifiedName().shortName == shortName){
        Error::semanticError("A type cannot extend itself (" + shortName + ")");
        return false;
    }
    return true;
}

bool Semantics::checkVarNotExistsInType(std::string varShortName, std::string typeShortName){
    if(!Members::varExistsInType(typeShortName, varShortName)){
        return true;
    }
    Error::semanticError("Variable already exists (" + varShortName + ")");
    return false;
}

bool Semantics::checkVarExistsInType(std::string varShortName, std::string typeShortName){
    if(!Members::varExistsInType(typeShortName, varShortName)){
        Error::semanticError("Variable doesn't exist or isn't visible from the current context (" + varShortName + ")");
        return false;
    }
    return true;
}

bool Semantics::checkVarNotExistsInCurrentType(std::string varShortName){
    if(!Members::varExistsInCurrentType(varShortName)){
        return true;
    }
    Error::semanticError("Variable already exists (" + varShortName + ")");
    return false;
}

bool Semantics::checkVarExistsInCurrentType(std::string varShortName){
    if(!Members::varExistsInCurrentType(varShortName)){
        Error::semanticError("Variable doesn't exist or isn't visible from the current context (" + varShortName + ")");
        return false;
    }
    return true;
}

bool Semantics::checkFuncThrowsExtendsThrowable(std::string throwsShortName){
    Type* type = Members::getType(throwsShortName);
    if(type){
        //TODO: Check for supers
    }
}

bool Semantics::checkForNoDuplicates(Args args, TokenArg arg){
    bool hasDupes = false;
    foreach(it2, args.args){
        if(arg.id == (*it2).id){
            Error::semanticError("Duplicate argument identifiers (" + arg.id.str +")");
            hasDupes = true;
        }
    }
    return !hasDupes;
}
