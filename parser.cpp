#include "parser.h"
using namespace std;
parser::parser(){
    fill_parser_table();
    fill_table_reduction();
}


void parser::parse(){

    s_state.push(0); //0 1 2
    //s_token Id coma
    //q_input_tokens; // |Id| |coma| |Integer| |$|
    state_token st;
    action_state as;
    v_token vt;
/*
    print_s_state();
    print_s_token();
    print_q_input_tokens();

    */
    while( true ){
        st = make_pair( s_state.top(), q_input_tokens.front() );
        as =parser_table[st];
        if( as.first ){
            if( as.first =='d' ){ // desplazamiento
                s_token.push( q_input_tokens.front() );
                q_input_tokens.pop();
                s_state.push(as.second);
            }
            if( as.first == 'r' ){// reduccion
                vt= t_reduction[as.second];
                for (int i = vt.size()-1; i >0  ; --i) {
                    if( s_token.top() == vt[i] ){
                        s_token.pop();
                        s_state.pop();
                    }else{
                        cout<<"error: reduccion "<<endl;
                        break;
                    }
                }
                s_token.push(vt[0]);//S
                //rescatar ultimo estado
                st = make_pair(s_state.top(), s_token.top() );
                action_state ass = parser_table[st];
                s_state.push(ass.second);
            }
            if( as.first == 'a' ){// aceptacion
                cout<<"cadena aceptada"<<endl;
                break;
            }
        }else{
            cout<<"error: cadena no aceptada "<<endl;
            print_s_state();
            print_s_token();
            print_q_input_tokens();
            break;

        }
    }

}






/*
while(!q_input_tokens.empty() ){
    cout<<q_input_tokens.front()<<" | ";
    q_input_tokens.pop();
}cout<<endl;*/


/*
llena en una cola los tokens obtenidos el lexer
*/
void parser::set_vector_tokens(vector<token> v_token){
    while( !q_input_tokens.empty() ){
        q_input_tokens.pop();
    }
    for( auto i: v_token){
        q_input_tokens.push(i);
    }
    q_input_tokens.push("$");
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
a aceptar
*/
void parser::fill_parser_table(){
    add_on_parse_table(0,"bracket_open",'d',2);
    add_on_parse_table(0,"Id",'d',3);
    add_on_parse_table(0,"S",'m',1);

    add_on_parse_table(1,"$",'a',-1);//acepted

    add_on_parse_table(2,"bracket_open",'d',6);
    add_on_parse_table(2,"Id",'d',7);
    add_on_parse_table(2,"S",'m',5);
    add_on_parse_table(2,"L",'m',4);

    add_on_parse_table(3,"$",'r',3);

    add_on_parse_table(4,"coma",'d',9);
    add_on_parse_table(4,"bracket_close",'d',8);

    add_on_parse_table(5,"coma",'r',4);
    add_on_parse_table(5,"bracket_close",'r',4);

    add_on_parse_table(6,"bracket_open",'d',6);
    add_on_parse_table(6,"Id",'d',7);
    add_on_parse_table(6,"S",'m',5);
    add_on_parse_table(6,"L",'m',10);

    add_on_parse_table(7,"bracket_close",'r',3);

    add_on_parse_table(8,"$",'r',2);

    add_on_parse_table(9,"bracket_open",'d',12);
    add_on_parse_table(9,"Id",'d',13);
    add_on_parse_table(9,"S",'m',11);

    add_on_parse_table(10,"coma",'d',9);
    add_on_parse_table(10,"bracket_close",'d',14);

    add_on_parse_table(11,"coma",'r',5);
    add_on_parse_table(11,"bracket_close",'r',5);

    add_on_parse_table(12,"bracket_open",'d',6);
    add_on_parse_table(12,"Id",'d',7);
    add_on_parse_table(12,"S",'m',5);
    add_on_parse_table(12,"L",'m',15);

    add_on_parse_table(13,"coma",'r',3);
    add_on_parse_table(13,"bracket_close",'r',3);

    add_on_parse_table(14,"bracket_close",'r',2);

    add_on_parse_table(15,"coma",'d',9);
    add_on_parse_table(15,"bracket_close",'d',16);

    add_on_parse_table(16,"coma",'r',2);
    add_on_parse_table(16,"bracket_close",'r',2);
}


/*
S'--> S
S --> Id S Integer
S --> coma

[S', S]
[S, Id, S, Integer]
[S, coma]

*/
void parser::fill_table_reduction(){
    vector<token> vt;
    //r1
    vt.push_back("S");
    t_reduction[1]=vt;
    //r2
    vt.clear();
    vt.push_back("S");
    vt.push_back("bracket_open");
    vt.push_back("L");
    vt.push_back("bracket_close");
    t_reduction[2]=vt;
    //r3
    vt.clear();
    vt.push_back("S");
    vt.push_back("Id");
    t_reduction[3]=vt;
    //r4
    vt.clear();
    vt.push_back("L");
    vt.push_back("S");
    t_reduction[4]=vt;
    //r5
    vt.clear();
    vt.push_back("L");
    vt.push_back("L");
    vt.push_back("coma");
    vt.push_back("S");
    t_reduction[5]=vt;
}

/* gramtica test 2
1)	S' --> S
2)	S --> bracket_open  L  bracket_close
3)	S --> Id
4)	L --> S
5)	L --> L  coma  S







*/







































/*

S'--> S
S --> Id S Integer
S --> coma

        add_on_parse_table(0,"Id",'d',2);
        add_on_parse_table(0,"coma",'d',3);
        add_on_parse_table(0,"S",'m',1);

        add_on_parse_table(1,"$",'a',-1);//acepted

        add_on_parse_table(2,"Id",'d',5);
        add_on_parse_table(2,"coma",'d',6);
        add_on_parse_table(2,"S",'m',4);

        add_on_parse_table(3,"$",'r',3);

        add_on_parse_table(4,"Integer",'d',7);

        add_on_parse_table(5,"Id",'d',5);
        add_on_parse_table(5,"coma",'d',6);
        add_on_parse_table(5,"S",'m',8);

        add_on_parse_table(6,"Integer",'r',3);
        add_on_parse_table(7,"$",'r',2);
        add_on_parse_table(8,"Integer",'d',9);
        add_on_parse_table(9,"Integer",'r',2);
*/




