#ifndef CODEGEN_H
#define CODEGEN_H

#include <parser/tokens.hpp>

namespace CodeGen {
    void gen(TokenFile* file, std::string currentFile);
    void genFile(TokenFile* f);
    void genMods(unsigned short mods);
    void write(const char* fmt, ...);
    void newLine();
    void indent();
    void unindent();
} /* CodeGen */

#endif /* end of include guard: CODEGEN_H */
