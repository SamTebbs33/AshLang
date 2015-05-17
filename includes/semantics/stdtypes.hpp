#ifndef STDTYPES_H
#define STDTYPES_H

#include <loader/member.hpp>
#include <semantics/semantics.hpp>

struct EnumPrimitiveType{
    enum type{
        NONE,
        BOOL,
        FLOAT64,
        FLOAT,
        UINT64,
        UINT,
        UINT16,
        UINT8,
        INT64,
        INT,
        INT16,
        INT8,
        CHAR,
        NUM_TYPES
    };
};

namespace StdTypes{
    bool isPrimitiveType(TypeI typeName);
    bool isStandardType(TypeI typeShortName);
    int getPrimitive(std::string str);
    QualifiedName getStringQualifiedName();
    std::string getShortName(EnumPrimitiveType::type primitive);
    std::string getStringShortName();
    TypeI getAsTypeI(EnumPrimitiveType::type primtive);
    std::string getJavaName(int primitive);
}

#endif /* end of include guard: STDTYPES_H */
