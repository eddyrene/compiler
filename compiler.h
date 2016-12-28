#ifndef COMPILER_H
#define COMPILER_H

#include "lexer.h"
#include "parser.h"

class compiler{
    public:
        lexer _lexer; /* contiene el bufer de tokens  */
        parser _parser;

    private:
        string source_code;

    public:
        compiler();
        compiler(string code);
        string get_source_code();
        void set_source_code(string code);
        void run();

    public: /* functions utilities */
        //print .. etc


};

#endif // COMPILER_H
