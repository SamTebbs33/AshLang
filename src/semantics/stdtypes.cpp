#include <semantics/stdtypes.hpp>
#include <cmath>

QualifiedName stringQualifiedName = QualifiedName().addThis("ash").addThis("lang").addThis("String");
const char* primitiveTypeStrs[EnumPrimitiveType::NUM_TYPES] = {"none", "bool", "float64", "float", "uint64", "uint", "uint16", "uint8", "int64", "int", "int16", "int8", "char"};

bool StdTypes::isPrimitiveType(TypeI type){
    if(type.arrDims > 0) return false;
    // Start at 1, since the first EnumPrimitiveType (0) signifies that a type is not a primitive.
    for(int i = 1; i < EnumPrimitiveType::NUM_TYPES; i++) if(type.typeShortName == primitiveTypeStrs[i]) return true;
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
    return std::string(primitiveTypeStrs[(int)log2(primitive)]);
}

TypeI StdTypes::getAsTypeI(EnumPrimitiveType::type primitive){
    return TypeI(StdTypes::getShortName(primitive), 0, primitive);
}
