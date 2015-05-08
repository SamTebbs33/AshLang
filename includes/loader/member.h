#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include <map>
#include <parser/tokens.h>

using ModifiersInt = unsigned short;

struct QualifiedName {
    std::vector<std::string*>* paths;
    QualifiedName();
    void add(std::string* path);
};

struct Member {
    ModifiersInt mods;
    QualifiedName* name;
    std::string* shortName;
    Member(ModifiersInt m, QualifiedName* n, std::string* s);
};

struct Function : Member {
    Args* args;
    Function(ModifiersInt m, QualifiedName* n, std::string* s);
};

struct Field : Member {

};

struct Type : Member {
    std::vector<Function*>* funcs;
    std::vector<Function*>* constructors;
    std::vector<Field*>* fields;
    std::vector<Type*>* supers;
    Type(ModifiersInt m, QualifiedName* n, std::string* s);
};

namespace Members {
    void addAndEnterType(Type* t);
    void addFunc(Function* f);
    void addField(Field* f);
    QualifiedName* toQualifiedName(TokenQualifiedName* n);
    ModifiersInt toModifiersInt(Modifiers* m);
    Type* getCurrentType();
} /* Members */

#endif /* end of include guard: TYPES_H */
