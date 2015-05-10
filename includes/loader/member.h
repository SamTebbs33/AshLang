#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include <map>
#include <parser/tokens.h>

using ModifiersInt = unsigned short;

struct QualifiedName {
    std::vector<std::string> paths;
    std::string shortName;
    QualifiedName();
    void add(std::string path);
};

struct Member {
    ModifiersInt mods;
    QualifiedName name;
    Member(ModifiersInt m, QualifiedName n);
};

struct FuncSignature {
    std::string* id;
    Args* args;
    ModifiersInt mods;
    FuncSignature(std::string* i, Args* a, ModifiersInt m);
};

struct Function : Member {
    Args* args;
    Function(ModifiersInt m, QualifiedName n, Args* a);
};

struct Field : Member {

};

struct Type : Member {
    std::vector<FuncSignature*>* constructors;
    // Map this type's functions to their signature (args and ID)
    // std::map<FuncSignature*, Function*>* funcs;
    std::vector<FuncSignature*>* funcs;
    std::vector<Field*>* fields;
    std::vector<Type*>* supers;
    Type(ModifiersInt m, QualifiedName n);
};

namespace Members {
    void addAndEnterType(Type* t);
    void addFunction(FuncSignature* f);
    void addField(Field* f);
    QualifiedName toQualifiedName(TokenQualifiedName* n, std::string s);
    ModifiersInt toModifiersInt(Modifiers m);
    Type* getCurrentType();
} /* Members */

#endif /* end of include guard: TYPES_H */
