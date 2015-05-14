#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <string>
#include <semantics/semantics.hpp>
#include <parser/tokens.hpp>
#include <semantics/stdtypes.hpp>

namespace Semantics{
    bool checkTypeExists(std::string shortName);
    bool checkSuperIsNotCurrentType(std::string shortName);
    bool checkVarExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarNotExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarExistsInCurrentType(std::string varShortName);
    bool checkVarNotExistsInCurrentType(std::string varShortName);
    bool checkFuncThrowsExtendsThrowable(std::string throwsShortName);
    bool checkForNoDuplicates(Args args, TokenArg arg);
}

#endif /* end of include guard: SEMANTICS_H */
