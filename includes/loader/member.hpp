#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include <map>
#include <semantics/semantics.hpp>

using ModifiersInt = unsigned short;

struct Args;

struct QualifiedName {
    std::vector<std::string> paths;
    std::string shortName;
    std::string fullName;
    QualifiedName();
    void add(std::string path);
    QualifiedName addThis(std::string path);
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
    TypeI type;
    FuncSignature(QualifiedName i, Args* a, ModifiersInt m, TypeI type);
    void print();
    bool operator==(FuncSignature f);
};

struct Field : Member {
    Field(ModifiersInt m, QualifiedName n);
};

struct Type : Member {
    std::vector<FuncSignature*> constructors;
    std::vector<FuncSignature*> funcs;
    std::vector<Field*> fields;
    std::vector<Type*> supers;
    int type;
    Type(ModifiersInt m, QualifiedName n, int enumType);
    void print();
    FuncSignature* getFunc(std::string id, Args* args);
    bool hasSuper(std::string superName);
};

namespace Members {
    void addAndEnterType(Type* t);
    void addFunction(FuncSignature* f);
    void addConstructor(FuncSignature* f);
    void addField(Field* f);
    QualifiedName toQualifiedName(std::vector<std::string> n);
    QualifiedName toQualifiedName(std::vector<std::string> n, std::string s);
    Type* getCurrentType();
    Type* getType(std::string typeShortName);
    QualifiedName getCurrentTypeQualifiedName();
    void printTypes();
    bool typeExists(std::string shortName);
    bool funcExistsInType(std::string typeShortName, FuncSignature funcSignature);
    bool funcExistsInCurrentType(FuncSignature funcSignature);
    bool varExistsInType(std::string typeShortName, std::string varShortName);
    bool varExistsInCurrentType(std::string varShortName);
} /* Members */

#endif /* end of include guard: TYPES_H */
