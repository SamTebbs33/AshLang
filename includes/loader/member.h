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
};

struct Field : Member {

};

struct Type : Member {
    std::vector<FuncSignature*> constructors;
    // Map this type's functions to their signature (args and ID)
    // std::map<FuncSignature*, Function*>* funcs;
    std::vector<FuncSignature*> funcs;
    std::vector<Field*> fields;
    std::vector<Type*> supers;
    Type(ModifiersInt m, QualifiedName n);
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
} /* Members */

#endif /* end of include guard: TYPES_H */
