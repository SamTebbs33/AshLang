#include <semantics/semantics.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>
#include <util/util.hpp>
#include <semantics/stdtypes.hpp>
#include <parser/tokens.hpp>

TypeI::TypeI(std::string t) : TypeI(t, 0, 0){}
TypeI::TypeI(std::string t, int dims) : TypeI(t, dims, 0){}
TypeI::TypeI(std::string t, int dims, int enumPrimitive) : typeShortName(t), arrDims(dims), enumPrimitive(enumPrimitive){}

std::string TypeI::toString(){
    std::string result = typeShortName;
    for(int i = 0; i < arrDims; i++) result += "[]";
    return result;
}

bool TypeI::operator==(TypeI t){
    return t.typeShortName == typeShortName && t.arrDims == arrDims && t.enumPrimitive == enumPrimitive;
}

bool Semantics::checkTypeExists(std::string shortName){
    if(StdTypes::isPrimitiveType(shortName)) return true;
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

bool Semantics::checkSuperIsNotPrimitive(std::string shortName){
    if(StdTypes::isPrimitiveType(shortName)){
        Error::semanticError("A type cannot extend a primitive (" + shortName + ")");
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
    return false;
}

bool Semantics::checkForNoDuplicates(Args* args, TokenArg* arg){
    bool hasDupes = false;
    foreach(it2, args->args){
        if(arg->id == (*it2).id){
            Error::semanticError("Duplicate argument identifiers (" + arg->id.str +")");
            hasDupes = true;
        }
    }
    return !hasDupes;
}

TypeI Semantics::getPrecedentType(TypeI t1, TypeI t2){
    // If either type is not a primitive.
    // No support yet for operations between objects
    if(t1.enumPrimitive == 0 || t1.enumPrimitive == 0) return TypeI("");

    // No support yet for oeprations between arrays
    if(t1.arrDims != 0 || t1.arrDims != 0) return TypeI("");

    // If the types aren't arrays or objects, then return either if they are the same type
    if(t1 == t2) return t1;

    // This loop relies on the fact that the EnumPrimitiveTypes are ordered by precedence
    for(int i = 1; i < EnumPrimitiveType::NUM_TYPES; i++){
        if((t1.enumPrimitive | i) || (t2.enumPrimitive | i)) return StdTypes::getAsTypeI((EnumPrimitiveType::type)i);
    }
    return t1;
}

TypeI Semantics::getPrecedentTypeOrCommonSuper(TypeI t1, TypeI t2){
    //TODO: Actually do what it's supposed to do
    return t1;
}
