#include <semantics/stdtypes.hpp>

QualifiedName stringQualifiedName = QualifiedName().addThis("ash").addThis("lang").addThis("String");
const char* primitiveTypeStrs[EnumPrimitiveType::NUM_TYPES] = {"bool", "char", "int8", "int16", "int", "int64", "uint8", "uint16", "uint", "uint64", "float", "float64"};

bool StdTypes::isPrimitiveType(std::string typeShortName){
    for(int i = 0; i < EnumPrimitiveType::NUM_TYPES; i++) if(typeShortName == primitiveTypeStrs[i]) return true;
    return false;
}

QualifiedName StdTypes::getStringQualifiedName(){
    return stringQualifiedName;
}
