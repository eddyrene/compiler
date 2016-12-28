#include "symbols_table.h"
#
symbols_table::symbols_table()
{
    table= new my_hash;
    this->read();
    au = new automata();
    au->fill_matriz();
}

/*
 * Carga los datos en memoria-> tabla hash
 */
void symbols_table::read()
{
    table->insert({"import","import"});
    table->insert({"new","new"});
    table->insert({"if","if"});
    table->insert({"else","else"});
    table->insert({"for","for"});
    table->insert({"switch","switch"});
    table->insert({"case","case"});
    table->insert({"while","while"});
    table->insert({"break","break"});
    table->insert({"return","return"});
    table->insert({".","."});
    table->insert({":",":"});
    table->insert({",",","});
    table->insert({";",";"});
    table->insert({"(","("});
    table->insert({")",")"});
    table->insert({"{","{"});
    table->insert({"}","}"});
    table->insert({"//","slcomment"});
    table->insert({"/*","mlcomment_open"});
    table->insert({"*/","mlcomment_close"});
    table->insert({"#define","header"});
    table->insert({"#include","header"});
    table->insert({"=","="});
    table->insert({"+","op"});
    table->insert({"-","op"});
    table->insert({"*","*"});
    table->insert({"/","division_op"});
    table->insert({"%","modulo_op"});
    table->insert({"==","op_bool"});
    table->insert({"!=","op_bool"});
    table->insert({"!","op_bool_not"});
    table->insert({"<","op_bool"});
    table->insert({">","op_bool"});
    table->insert({"<=","op_bool"});
    table->insert({">=","op_bool"});
    table->insert({"&&","op_bool_cd"});
    table->insert({"||","op_bool_cd"});
    table->insert({"true","value"});
    table->insert({"false","value"});
    table->insert({"int","dt"});
    table->insert({"char","dt"});
    table->insert({"void","dt"});
    table->insert({"bool","dt"});
    table->insert({"++","increment_op"});
    table->insert({"--","decrement_op"});

}

void symbols_table::print_table()
{
    for (auto & x:*table)
        cout << x.first << ": " << x.second << endl;
    cout<< "total:"<<table->size()<<endl;
}
/*
 * permite obtener la tabla como un metodo
 */
my_hash* symbols_table::get_table()
{
    return table;
}
string symbols_table::get_token(string p){
    string rpta;
    auto it = table->find(p);
    if(it==table->end())
        rpta=au->executar(p);// evalua el automata;
    else
        rpta=it->second;
    return rpta;
}
/*
 * busca en la tabla de simbolos
 */
bool symbols_table::is(string p)
{
    auto it = table->find(p);
    if(it==table->end())
        return false;
    return true;
}
string symbols_table::evaluar( string cadena ){
        au->executar(cadena);
}





