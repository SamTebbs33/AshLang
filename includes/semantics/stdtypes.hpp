#ifndef STDTYPES_H
#define STDTYPES_H

#include <loader/member.hpp>
#include <semantics/semantics.hpp>

struct EnumPrimitiveType{
    enum type{
        BOOL,
        CHAR,
        INT8,
        INT16,
        INT,
        INT64,
        UINT8,
        UINT16,
        UINT,
        UINT64,
        FLOAT,
        FLOAT64,
        NUM_TYPES
    };
};

namespace StdTypes{
    bool isPrimitiveType(TypeI typeName);
    bool isStandardType(TypeI typeShortName);
    QualifiedName getStringQualifiedName();
    std::string getShortName(EnumPrimitiveType::type primitive);
    std::string getStringShortName();
    TypeI getAsTypeI(EnumPrimitiveType::type primtive);
}

#endif /* end of include guard: STDTYPES_H */
