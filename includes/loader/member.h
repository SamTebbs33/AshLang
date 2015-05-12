#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include <map>
#include <parser/tokens.h>

struct QualifiedName {
    std::vector<std::string> paths;
    std::string shortName;
    std::string fullName;
    QualifiedName();
    void add(std::string path);
    std::string toString();
    bool operator==(QualifiedName n);
};

struct Member {
    ModifiersInt mods;
    QualifiedName name;
    Member(ModifiersInt m, QualifiedName n);
    virtual void print();
};

struct FuncSignature : Member{
    Args* args;
    FuncSignature(QualifiedName i, Args* a, ModifiersInt m);
    void print();
    bool operator==(FuncSignature f);
};

struct Field : Member {

};

struct Type : Member {
    std::vector<FuncSignature*> constructors;
    std::vector<FuncSignature*> funcs;
    std::vector<Field*> fields;
    std::vector<Type*> supers;
    EnumType::type type;
    Type(ModifiersInt m, QualifiedName n, EnumType::type t);
    void print();
};

namespace Members {
    void addAndEnterType(Type* t);
    void addFunction(FuncSignature* f);
    void addField(Field* f);
    QualifiedName toQualifiedName(TokenQualifiedName* n);
    QualifiedName toQualifiedName(TokenQualifiedName* n, std::string s);
    Type* getCurrentType();
    QualifiedName getCurrentTypeQualifiedName();
    void printTypes();
    bool typeExists(std::string shortName);
    bool funcExistsInType(std::string typeShortName, FuncSignature funcSignature);
    bool funcExistsInCurrentType(FuncSignature funcSignature);
} /* Members */

#endif /* end of include guard: TYPES_H */
