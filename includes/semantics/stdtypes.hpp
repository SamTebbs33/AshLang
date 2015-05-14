#ifndef STDTYPES_H
#define STDTYPES_H

#include <loader/member.hpp>

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
    bool isPrimitiveType(std::string typeName);
    QualifiedName getStringQualifiedName();
}

#endif /* end of include guard: STDTYPES_H */
