#include "parser.h"
using namespace std;
parser::parser(){
    fill_parser_table();





}





void parser::set_vector_tokens(vector<token> v_token){
    for( auto i: v_token){
        q_input_tokens.push(i);
    }
}

void parser::add_on_parse_table(state s, token t, action a, state ss){
    state_token  _state_token;
    action_state _action_state;
    _state_token  = make_pair( s, t );
    _action_state = make_pair( a, ss );
    parser_table[_state_token] = _action_state;
}

/*
estado,token, accion, estado
0 "a" -> 'd' 3 (d3)

d desplazamiento
r reducir
m mover...
*/
void parser::fill_parser_table(){
    add_on_parse_table(0,"a",'d',2);
    add_on_parse_table(0,"c",'d',3);
    add_on_parse_table(0,"S",'m',1);
    add_on_parse_table(1,"$",'a',-1);//acepted
    add_on_parse_table(2,"a",'d',5);
    add_on_parse_table(2,"c",'d',6);
    add_on_parse_table(2,"S",'m',4);
    add_on_parse_table(3,"$",'r',3);
    add_on_parse_table(4,"b",'d',7);
    add_on_parse_table(5,"a",'d',5);
    add_on_parse_table(5,"c",'d',6);
    add_on_parse_table(5,"$",'m',8);
    add_on_parse_table(6,"b",'r',3);
    add_on_parse_table(7,"$",'r',2);
    add_on_parse_table(8,"b",'d',9);
    add_on_parse_table(9,"b",'r',2);
}
