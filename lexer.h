/*
    	lexer.h
     recursos:
     tabla de simboslos,
     automatas,

     se creara:
     funciones de tratamiento de string

     resultados:
     bufer de tokens XD

     ...
*/
#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include "symbols_table.h"
using namespace std;

class lexer{
    private:
        symbols_table st;
        vector<string> buffer_tokens;
    private:
        void set_token_into_buffer(string token);

    public:
        lexer();
        lexer(string source_code);
        void tokenizer(string cad);
        vector<string> get_buffer_tokens();
        void print_buffer_tokens();
















};

#endif // LEXER_H
