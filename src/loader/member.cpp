#include <loader/member.h>

// Map which contains Type objects paired with unqualified names
std::map<std::string*, Type*>* types = new std::map<std::string*, Type*>();
Type* currentType;

QualifiedName::QualifiedName(){
    paths = new std::vector<std::string*>();
}

QualifiedName* QualifiedName::add(std::string* s){
    paths->push_back(s);
    return this;
}

std::string* QualifiedName::getShortName(){
    return paths->size() > 0 ? paths->at(paths->size()-1) : new std::string("");
}

Member::Member(ModifiersInt m, QualifiedName* n) : name(n), mods(m){

}

FuncSignature::FuncSignature(std::string* s, Args* a, ModifiersInt m) : id(s), args(a), mods(m){

}

Function::Function(ModifiersInt m, QualifiedName* n, Args* a) : Member(m, n), args(a){

}

Type::Type(ModifiersInt m, QualifiedName* n) : Member(m, n){
    funcs = new std::vector<FuncSignature*>();
    constructors = new std::vector<FuncSignature*>();
    fields = new std::vector<Field*>();
    supers = new std::vector<Type*>();
}

void Members::addAndEnterType(Type* t){
    currentType = t;
    types->insert(std::map<std::string*, Type*>::value_type(t->name->getShortName(), t));
}

void Members::addFunction(FuncSignature* f){
    currentType->funcs->push_back(f);
}

QualifiedName* Members::toQualifiedName(TokenQualifiedName* n, std::string* shortName){
    if (n != NULL) {
        QualifiedName* name = new QualifiedName();
        // Add paths and the short name. A class called Test in ash.lang gives a qualified name called ash.lang.Test
        for(auto it = n->paths->begin(); it != n->paths->end(); it++){
            name->add((*it));
        }
        // Add short name to end. The short name is how the type or function is referred to in code.
        name->add(shortName);
        return name;
    }
    return NULL;
}

ModifiersInt Members::toModifiersInt(Modifiers* m){
    ModifiersInt res = 0;
    // Add the modifier to the int
    if(m) foreachp(it, m->mods) res |= (*it)->mod;
    return res;
}

Type* Members::getCurrentType(){
    return currentType;
}
