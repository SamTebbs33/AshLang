#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <string>

struct Args;
struct TokenArg;

struct TypeI {
    std::string typeShortName;
    int arrDims;
    TypeI(std::string name);
    TypeI(std::string name, int dims);
    std::string toString();
};

namespace Semantics{
    bool checkTypeExists(std::string shortName);
    bool checkSuperIsNotPrimitive(std::string shortName);
    bool checkSuperIsNotCurrentType(std::string shortName);
    bool checkVarExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarNotExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarExistsInCurrentType(std::string varShortName);
    bool checkVarNotExistsInCurrentType(std::string varShortName);
    bool checkFuncThrowsExtendsThrowable(std::string throwsShortName);
    bool checkForNoDuplicates(Args* args, TokenArg* arg);
    TypeI getPrecedentType(TypeI t1, TypeI t2);
    TypeI getPrecedentTypeOrCommonSuper(TypeI t1, TypeI t2);
}

#endif /* end of include guard: SEMANTICS_H */
