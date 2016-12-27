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
    _lexer.print_buffer_tokens();
    _parser.set_vector_tokens( _lexer.get_buffer_tokens() );
    _parser.parse();


//see("compilando....");

/*
node *n1 = new node("*");
    node *n2 = new node("(");
    node *n3 = new node("+");
    node *n4 = new node(")");
    node *n5 = new node("c");
    node *n6 = new node("a");
    node *n7 = new node("b");



    n1->add_branch(n2);
    n1->add_branch(n3);
    n1->add_branch(n4);
    n1->add_branch(n5);
    n3->add_branch(n6);
    n3->add_branch(n7);

    tree *t = new tree(n1);
    t->print_tree_dot();

*/



}


string compiler::get_source_code(){
    return source_code;
}

void compiler::set_source_code(string code){
    source_code = code;
}
