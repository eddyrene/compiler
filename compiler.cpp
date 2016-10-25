/*
 * clase principal q administra analisis y sintesis
 * la clase 'main' interaccionan solo con esta clase
 * ...
 *
*/
#include "compiler.h"


compiler::compiler(){
}

compiler::compiler(string code){
    source_code=code;
}

/*
 * compilacion
 * paso 1 lexer
 * paso 2 ..
 * paso 3 ..
*/
void compiler::run(){
    _lexer.tokenizer(source_code);
    _lexer.print_buffer_tokens(); /*  */
    _parser.set_vector_tokens( _lexer.get_buffer_tokens() );




}


string compiler::get_source_code(){
    return source_code;
}

void compiler::set_source_code(string code){
    source_code = code;
}
