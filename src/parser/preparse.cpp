#include <parser/tokens.hpp>
#include <loader/context.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>
#include <semantics/semantics.hpp>

void TokenFile::preParse(){
	Context::push(FileContext("", Members::toQualifiedName(&namespc.name, "")));
	namespc.preParse();
	foreach(it, imports.imports) (*it).preParse();
	foreach(it, typeDecs) if(*it) (*it)->preParse();
}

void TokenStatement::preParse(){
	println("Statement prePArse");
}

void TokenNamespace::preParse(){}

void TokenImport::preParse(){
	ClassLoader::importClass(name.paths);
}

void TokenDeclaration::preParse(){}

void TokenTypeDec::preParse(){
	if(!Members::typeExists(id.str)){
		// Create the qualified name of this type
		QualifiedName name = Context::getNamespace();
		name.add(id.str);
		Members::addAndEnterType(new Type(mods, name, getType()));
	}else{
		Error::semanticError("Type already exists (" + id.str + ")");
		errored = true;
	}
}

EnumType::type TokenTypeDec::getType(){
	return EnumType::CLASS;
}

void ClassBlock::preParse(){
	foreach(it, funcDecs) if(*it) (*it)->preParse();
	foreach(it, varDecs) if(*it) (*it)->preParse();
}

void TokenClassDec::preParse(){
	TokenTypeDec::preParse();
	if(TokenTypeDec::errored) return;
	block.preParse();
	//TODO: Add supers to Type generated by TokenTypeDec::preParse()
}

EnumType::type TokenClassDec::getType(){
	return EnumType::CLASS;
}

void TokenProtocolDec::preParse(){
	TokenTypeDec::preParse();
	if(TokenTypeDec::errored) return;
	block.preParse();
	//TODO: Add supers to Type generated by TokenTypeDec::preParse()
}

EnumType::type TokenProtocolDec::getType(){
	return EnumType::PROTOCOL;
}

void TokenEnumDec::preParse(){
	TokenTypeDec::preParse();
}

EnumType::type TokenEnumDec::getType(){
	return EnumType::ENUM;
}

void TokenFuncDec::preParse(){
	QualifiedName name = Members::getCurrentTypeQualifiedName();
	// Form a qualified name to this function
	name.add(id.str);
	FuncSignature* signature = new FuncSignature(name, &args, mods);
	if(!Members::funcExistsInCurrentType(*signature)) Members::addFunction(signature);
	else Error::semanticError("Function with identical signature already exists (" + name.shortName + ")");
}

void TokenVarDec::preParse(){
	if(Context::inType()){
		if(!Context::inFunc()){
			// Ensure the variable doesn't exist already, if it doesn't then push a new field to the current type
			if(!Semantics::checkVarNotExistsInCurrentType(id.str)) errored = true;
			else{
				QualifiedName name = Members::getCurrentTypeQualifiedName();
				name.add(id.str);
				Members::addField(new Field(mods, name));
			}
		}
	}
}
