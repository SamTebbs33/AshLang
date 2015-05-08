#include <loader/member.h>

// Map which contains Type objects paired with unqualified names
std::map<std::string*, Type*>* types = new std::map<std::string*, Type*>();
Type* currentType;

QualifiedName::QualifiedName(){
    paths = new std::vector<std::string*>();
}

void QualifiedName::add(std::string* s){
    paths->push_back(s);
}

Member::Member(ModifiersInt m, QualifiedName* n, std::string* s) : name(n), mods(m), shortName(s){
    // Append short name to end of the qualified name
    n->add(s);
}

Function::Function(ModifiersInt m, QualifiedName* n, std::string* s) : Member(m, n, s){

}

Type::Type(ModifiersInt m, QualifiedName* n, std::string* s) : Member(m, n, s){

}

void Members::addAndEnterType(Type* t){
    currentType = t;
    types->insert(std::map<std::string*, Type*>::value_type(t->shortName, t));
}

QualifiedName* Members::toQualifiedName(TokenQualifiedName* n){
    if (n != NULL) {
        QualifiedName* name = new QualifiedName();
        if(n->paths->size() > 0){
            for(auto it = n->paths->begin(); it != n->paths->end(); it++){
                name->paths->push_back((*it));
            }
        }
        return name;
    }
    return NULL;
}

ModifiersInt Members::toModifiersInt(Modifiers* m){
    ModifiersInt res = 0;
    if(m) foreachp(it, m->mods) res |= (*it)->mod;
    return res;
}

Type* Members::getCurrentType(){
    return currentType;
}
