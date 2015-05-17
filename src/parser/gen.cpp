#include <parser/tokens.hpp>
#include <codegen/codegen.hpp>
#include <util/util.hpp>
#include <semantics/stdtypes.hpp>

void TokenStatement::gen(){

}

void TokenIdentifier::gen(){
    CodeGen::write("%s", str.c_str());
}

void TokenQualifiedName::gen(){
    for (size_t c  = 0; c < paths.size()-1; c++) {
        CodeGen::write("%s.", paths.at(c).c_str());
    }
    CodeGen::write("%s", paths.at(paths.size()-1).c_str());
}

void TokenArg::gen(){
    type.gen();
    CodeGen::write(" ");
    id.gen();
}

void TokenBlock::gen(){
    foreach(it, stmts){
        if(*it) (*it)->gen();
        CodeGen::write(";");
        CodeGen::newLine();
    }
}

void TokenExpression::gen(){

}

void TokenDeclaration::gen(){

}

void TokenVarDec::gen(){
    CodeGen::genMods(mods);
    if(decKeyword == EnumVarDecKeyword::CONST) CodeGen::write("final ");
}

void TokenVarDecExplicit::gen(){
    TokenVarDec::gen();
    type.gen();
    id.gen();
}

void TokenVarDecExplicitAssign::gen(){
    TokenVarDecExplicit::gen();
    CodeGen::write(" = ");
    expr->gen();
}

void TokenVarDecImplicit::gen(){
    //TODO:
}

void TokenFuncDec::gen(){
    CodeGen::genMods(mods);
    if(type.id.str == "") CodeGen::write("void");
    else type.gen();
    CodeGen::write(" ");
    id.gen();
    args.gen();
    CodeGen::write(" ");
    if(throws.id.str != ""){
        CodeGen::write("throws ");
        throws.gen();
        CodeGen::write(" ");
    }
    CodeGen::write("{");
    CodeGen::newLine();
    CodeGen::indent();
    block.gen();
    CodeGen::newLine();
    CodeGen::unindent();
    CodeGen::write("}");
    CodeGen::newLine();
}

void ClassBlock::gen(){
    foreach(it, varDecs){
        if(*it){
            (*it)->gen();
            CodeGen::newLine();
        }
    }
    foreach(it, funcDecs){
        if(*it){
            (*it)->gen();
            CodeGen::newLine();
        }
    }
}

void TokenReturn::gen(){
    CodeGen::write("return");
    if(expr){
        CodeGen::write(" ");
        expr->gen();
    }
}

void TokenExprInfix::gen(){
    expr1->gen();
    CodeGen::write(" %s ", op.opStr);
    expr2->gen();
}

void TokenExprPrefix::gen(){
    CodeGen::write("%s", op.opStr);
    expr->gen();
}

void TokenExprPostfix::gen(){
    expr->gen();
    CodeGen::write("%s", op.opStr);
}

void TokenExprInt::gen(){
    CodeGen::write("%d", val);
}

void TokenExprStr::gen(){
    CodeGen::write("\"%s\"", (*str).c_str());
}

void TokenExprChar::gen(){
    CodeGen::write("\'%c\'", ch);
}

void TokenExprBool::gen(){
    if(val) CodeGen::write("true");
    else CodeGen::write("false");
}

void TokenExprFloat::gen(){
    CodeGen::write("%ff", val);
}

void TokenExprFloat64::gen(){
    CodeGen::write("%f", val);
}

void TokenExprLong::gen(){
    CodeGen::write("%lL", val);
}

void TokenExprTernary::gen(){
    exprBool->gen();
    CodeGen::write(" ? ");
    expr1->gen();
    CodeGen::write(" : ");
    expr2->gen();
}

void TokenVarAssign::gen(){
    var.gen();
    CodeGen::write(" %s ", op->opStr);
    expr->gen();
}

void TokenFuncCall::gen(){
    if(prefix){
        prefix->gen();
        CodeGen::write(".");
    }
    id.gen();
    CodeGen::write("(");
    for(int i = 0; i < args.size(); i++){
        args.at(i)->gen();
        if(i < args.size() - 1);
        CodeGen::write(", ");
    }
    CodeGen::write(")");
}

void TokenVariable::gen(){
    if(prefix){
        prefix->gen();
        CodeGen::write(".");
    }
    id.gen();
    foreach(it, arrExprs){
        if(*it){
            CodeGen::write("[");
            (*it)->gen();
            CodeGen::write("]");
        }
    }
}

void TokenFile::gen(){
    namespc.gen();
    CodeGen::newLine();
    CodeGen::newLine();
    foreach(it, imports.imports){
        (*it).gen();
        CodeGen::newLine();
    }
    foreach(it, typeDecs){
        if(*it) (*it)->gen();
        CodeGen::newLine();
        CodeGen::newLine();
    }
}

void TokenNamespace::gen(){
    if(name.paths.size() > 0){
        CodeGen::write("package ");
        name.gen();
        CodeGen::write(";");
    }
}

void TokenImport::gen(){
    CodeGen::write("import ");
    name.gen();
    CodeGen::write(";");
}

void TokenTypeDec::gen(){

}

void TokenClassDec::gen(){
    CodeGen::genMods(mods);
    CodeGen::write("class ");
    id.gen();
    CodeGen::write(" ");
    //args.gen();
    if(supers.types.size() > 0){
        CodeGen::write("extends ");
        supers.types.at(0).gen();
        if(supers.types.size() > 1){
            CodeGen::write("implements ");
            for (size_t c = 1; c < supers.types.size(); c++) {
                supers.types.at(c).gen();
                if(c < supers.types.size() - 1) CodeGen::write(", ");
            }
        }
    }
    CodeGen::write("{\n");
    CodeGen::newLine();
    CodeGen::indent();
    block.gen();
    CodeGen::unindent();
    CodeGen::write("}");
    CodeGen::newLine();
    CodeGen::unindent();
}

void TokenProtocolDec::gen(){
    CodeGen::genMods(mods);
    CodeGen::write("interface ");
    id.gen();
    args.gen();
    if(supers.types.size() > 0){
        CodeGen::write("implements ");
        for (size_t c = 0; c < supers.types.size(); c++) {
            supers.types.at(c).gen();
            if(c < supers.types.size() - 1) CodeGen::write(", ");
        }
    }
    CodeGen::write("{");
    CodeGen::newLine();
    CodeGen::indent();
    block.gen();
    CodeGen::newLine();
    CodeGen::unindent();
    CodeGen::write("}");
    CodeGen::newLine();
}

void TokenEnumDec::gen(){

}

void TokenType::gen(){
    // If it's a primitive type, translate it to it's java name
    if(StdTypes::isPrimitiveType(id.str)) CodeGen::write("%s", StdTypes::getJavaName(StdTypes::getPrimitive(id.str)).c_str());
    else CodeGen::write("%s", id.str.c_str());
    for(int i = 0; i < arrDims; i++) CodeGen::write("[]");
}

void Args::gen(){
    if(args.size() > 0){
        CodeGen::write("(");
        for(int i = 0; i < args.size(); i++){
            args.at(i).gen();
            if(i < args.size() - 1) CodeGen::write(", ");
        }
        CodeGen::write(")");
    }
}
