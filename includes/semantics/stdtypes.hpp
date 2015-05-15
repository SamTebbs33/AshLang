#ifndef STDTYPES_H
#define STDTYPES_H

#include <loader/member.hpp>
#include <semantics/semantics.hpp>

struct EnumPrimitiveType{
    enum type{
        NONE = 0,
        BOOL = 1,
        FLOAT64 = 2,
        FLOAT = 4,
        UINT64 = 8,
        UINT = 16,
        UINT16 = 32,
        UINT8 = 64,
        INT64 = 128,
        INT = 256,
        INT16 = 512,
        INT8 = 1024,
        CHAR = 2048,
        NUM_TYPES = 4096
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
