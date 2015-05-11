#include <loader/member.h>

// Map which contains Type objects paired with unqualified names
std::map<std::string, Type*> types;
Type* currentType;

QualifiedName::QualifiedName(){

}

void QualifiedName::add(std::string s){
    if(s != ""){
        paths.push_back(s);
        shortName = s;
        if(paths.size() > 1) fullName += ".";
        fullName += s;
    }
}


Member::Member(ModifiersInt m, QualifiedName n) : name(n), mods(m){

}

void Member::print(){
    printf("- Name: %s\n", name.fullName.c_str());
    printf("- Mods: %d\n", mods);
}


FuncSignature::FuncSignature(QualifiedName n, Args* a, ModifiersInt m) : Member(m, n), args(a){

}

void FuncSignature::print(){
    Member::print();
    //TODO: Print args
}


Type::Type(ModifiersInt m, QualifiedName n) : Member(m, n){

}

void Type::print(){
    println("Type");
    Member::print();
    println("- Constructors");
    foreach(it, constructors) if(*it) (*it)->print();
    println("- Functions");
    foreach(it, funcs) if(*it) (*it)->print();
    println("- Fields");
    foreach(it, fields) if(*it) (*it)->print();
}


void Members::addAndEnterType(Type* t){
    currentType = t;
    types.insert(std::map<std::string, Type*>::value_type(t->name.shortName, t));
}

bool Members::typeExists(std::string shortName){
    return types.find(shortName) != types.end();
}

void Members::addFunction(FuncSignature* f){
    currentType->funcs.push_back(f);
}

QualifiedName Members::toQualifiedName(TokenQualifiedName* n, std::string shortName){
    QualifiedName name = toQualifiedName(n);
    name.add(shortName);
    return name;
}

QualifiedName Members::toQualifiedName(TokenQualifiedName* n){
    QualifiedName name;
    if(n){
        // Add paths and the short name. A class called Test in ash.lang gives a qualified name called ash.lang.Test
        for(auto it = n->paths.begin(); it != n->paths.end(); it++){
            name.add((*it));
        }
    }
    // Add short name to end. The short name is how the type or function is referred to in code.
    return name;
}

Type* Members::getCurrentType(){
    return currentType;
}

QualifiedName Members::getCurrentTypeQualifiedName(){
    return currentType->name;
}

void Members::printTypes(){
    foreach(it, types){
        Type* t = (*it).second;
        if(t){
            t->print();
        }
    }
}
