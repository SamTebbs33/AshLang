#include <semantics/stdtypes.hpp>

QualifiedName stringQualifiedName = QualifiedName().addThis("ash").addThis("lang").addThis("String");
const char* primitiveTypeStrs[EnumPrimitiveType::NUM_TYPES] = {"bool", "char", "int8", "int16", "int", "int64", "uint8", "uint16", "uint", "uint64", "float", "float64"};

bool StdTypes::isPrimitiveType(TypeI type){
    if(type.arrDims > 0) return false;
    for(int i = 0; i < EnumPrimitiveType::NUM_TYPES; i++) if(type.typeShortName == primitiveTypeStrs[i]) return true;
    return false;
}

bool StdTypes::isStandardType(TypeI type){
    return StdTypes::isPrimitiveType(type) || (type.typeShortName == StdTypes::getStringShortName() && type.arrDims == 0);
}

QualifiedName StdTypes::getStringQualifiedName(){
    return stringQualifiedName;
}

std::string StdTypes::getStringShortName(){
    return stringQualifiedName.shortName;
}

std::string StdTypes::getShortName(EnumPrimitiveType::type primitive){
    return std::string(primitiveTypeStrs[primitive]);
}

TypeI StdTypes::getAsTypeI(EnumPrimitiveType::type primitive){
    return TypeI(StdTypes::getShortName(primitive));
}
