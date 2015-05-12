#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <string>
#include <semantics/semantics.hpp>

namespace Semantics{
    bool checkTypeExists(std::string shortName);
    bool checkSuperIsNotCurrentType(std::string shortName);
    bool checkVarExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarNotExistsInType(std::string varShortName, std::string typeShortName);
    bool checkVarExistsInCurrentType(std::string varShortName);
    bool checkVarNotExistsInCurrentType(std::string varShortName);
}

#endif /* end of include guard: SEMANTICS_H */
