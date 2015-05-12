#include <loader/member.hpp>

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

bool QualifiedName::operator==(QualifiedName n){
    return n.fullName == fullName;
}

Member::Member(ModifiersInt m, QualifiedName n) : name(n), mods(m){

}

void Member::print(){
    printf("\t- Name: %s\n", name.fullName.c_str());
    printf("\t- Mods: %d\n", mods);
}


FuncSignature::FuncSignature(QualifiedName n, Args* a, ModifiersInt m) : Member(m, n), args(a){

}

void FuncSignature::print(){
    Member::print();
    //TODO: Print args
}

bool FuncSignature::operator==(FuncSignature f){
    return *f.args == *args && f.name == name;
}


Type::Type(ModifiersInt m, QualifiedName n, EnumType::type t) : Member(m, n), type(t){

}

void Type::print(){
    println(typeStrs[type]);
    Member::print();
    println("\t- Constructors");
    foreach(it, constructors) if(*it) (*it)->print();
    println("\t- Functions");
    foreach(it, funcs) if(*it) (*it)->print();
    println("\t- Fields");
    foreach(it, fields) if(*it) (*it)->print();
}


void Members::addAndEnterType(Type* t){
    currentType = t;
    types.insert(std::map<std::string, Type*>::value_type(t->name.shortName, t));
}

bool Members::typeExists(std::string shortName){
    return types.find(shortName) != types.end();
}

bool Members::funcExistsInType(std::string typeShortName, FuncSignature signature){
    //printf("Looking for %s in %s\n", signature.name.shortName.c_str(), typeShortName.c_str());
    auto type = types.find(typeShortName);
    // If the type exists in the map
    if(type != types.end()){
        std::vector<FuncSignature*>* funcs = &(*type).second->funcs;
        // Iterate over the type's functions
        foreachp(it, funcs){
            if(*it){
                if(signature == **it){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Members::funcExistsInCurrentType(FuncSignature signature){
    return funcExistsInType(Members::getCurrentTypeQualifiedName().shortName, signature);
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
