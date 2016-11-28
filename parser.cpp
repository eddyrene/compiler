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


    add_on_parse_table(0,"void",'r',5);
    add_on_parse_table(0,"bool",'r',5);
    add_on_parse_table(0,"int",'r',5);
    add_on_parse_table(0,"char",'r',5);
    add_on_parse_table(0,"id",'r',5);
    add_on_parse_table(0,"import",'d',5);
    add_on_parse_table(0,'$','r',5);

    //CASO ESPECIAL
    add_on_parse_table(1,'$','a',-1);

    add_on_parse_table(2,'$','r',2);

    add_on_parse_table(3,"void",'d',10);
    add_on_parse_table(3,"bool",'d',11);
    add_on_parse_table(3,"int",'d',12);
    add_on_parse_table(3,"char",'d',13);
    add_on_parse_table(3,"id",'d',9);
    add_on_parse_table(3,'$','r',12);


    add_on_parse_table(4,"void",'r',5);
    add_on_parse_table(4,"bool",'r',5);
    add_on_parse_table(4,"int",'r',5);
    add_on_parse_table(4,"char",'r',5);
    add_on_parse_table(4,"id",'r',5);
    add_on_parse_table(4,"import",'d',5);
    add_on_parse_table(4,'$','r',5);

    add_on_parse_table(5,"import",'d',15);

    /*add_on_parse_table(3,"void",'d',10);
    add_on_parse_table(3,"bool",'d',11);
    add_on_parse_table(3,"int",'d',12);
    add_on_parse_table(3,"char",'d',13);
    add_on_parse_table(3,"id",'d',9);*/

    add_on_parse_table(6,'$','r',3);

    add_on_parse_table(7,"void",'r',5);
    add_on_parse_table(7,"bool",'r',5);
    add_on_parse_table(7,"int",'r',5);
    add_on_parse_table(7,"char",'r',5);
    add_on_parse_table(7,"id",'r',5);
    add_on_parse_table(7,'$','r',12);

    add_on_parse_table(8,"import",'d',17);

    add_on_parse_table(10,"import",'r',64);
    add_on_parse_table(11,"import",'r',65);
    add_on_parse_table(12,"import",'r',66);
    add_on_parse_table(13,"import",'r',67);

    add_on_parse_table(14,"void",'r',4);
    add_on_parse_table(14,"bool",'r',4);
    add_on_parse_table(14,"int",'r',4);
    add_on_parse_table(14,"char",'r',4);
    add_on_parse_table(14,"id",'r',4);
    add_on_parse_table(14,'$','r',4);

    add_on_parse_table(16,'$','r',11);

    add_on_parse_table(18,"void",'r',14);
    add_on_parse_table(18,"bool",'r',14);
    add_on_parse_table(18,"int",'r',14);
    add_on_parse_table(18,"char",'r',14);
    add_on_parse_table(18,"id",'r',14);
    add_on_parse_table(18,"num",'r',14);
    add_on_parse_table(18,"character",'r',14);
    add_on_parse_table(18,"booleano",'r',14);
    add_on_parse_table(18,'$','r',14);


    add_on_parse_table(19,"id",'d',31);
    add_on_parse_table(19,"num",'d',32);
    add_on_parse_table(19,"character",'d',33);
    add_on_parse_table(19,"booleano",'d',34);

    add_on_parse_table(20,"void",'r',6);
    add_on_parse_table(20,"bool",'r',6);
    add_on_parse_table(20,"int",'r',6);
    add_on_parse_table(20,"char",'r',6);
    add_on_parse_table(20,"id",'r',6);
    add_on_parse_table(20,"import",'r',6);
    add_on_parse_table(20,'$','r',6);
|
    add_on_parse_table(21,"id",'d',36);

    add_on_parse_table(22,"void",'r',8);
    add_on_parse_table(22,"bool",'r',8);
    add_on_parse_table(22,"int",'r',8);
    add_on_parse_table(22,"char",'r',8);
    add_on_parse_table(22,"id",'r',8);
    add_on_parse_table(22,"import",'r',8);
    add_on_parse_table(22,'$','r',8);

    add_on_parse_table(23,"void",'r',13);
    add_on_parse_table(23,"bool",'r',13);
    add_on_parse_table(23,"int",'r',13);
    add_on_parse_table(23,"char",'r',13);
    add_on_parse_table(23,"id",'r',13);
    add_on_parse_table(23,"num",'r',13);
    add_on_parse_table(23,"character",'r',13);
    add_on_parse_table(23,"booleano",'r',13);
    add_on_parse_table(23,'$','r',13);
    add_on_parse_table(23,"void",'r',15);

    add_on_parse_table(24,"bool",'r',15);
    add_on_parse_table(24,"int",'r',15);
    add_on_parse_table(24,"char",'r',15);
    add_on_parse_table(24,"id",'r',15);
    add_on_parse_table(24,"num",'r',15);
    add_on_parse_table(24,"character",'r',15);
    add_on_parse_table(24,"booleano",'r',15);
    add_on_parse_table(24,'$','r',15);


    add_on_parse_table(25,"id",'r',31);
    add_on_parse_table(25,"num",'r',32);
    add_on_parse_table(25,"character",'r',33);
    add_on_parse_table(25,"booleano",'r',34);


    add_on_parse_table(26,"void",'r',17);
    add_on_parse_table(26,"bool",'r',17);
    add_on_parse_table(26,"int",'r',17);
    add_on_parse_table(26,"char",'r',17);
    add_on_parse_table(26,"id",'r',17);
    add_on_parse_table(26,"num",'r',17);
    add_on_parse_table(26,"character",'r',17);
    add_on_parse_table(26,"booleano",'r',17);
    add_on_parse_table(26,'$','r',17);

    add_on_parse_table(27,"void",'d',10);
    add_on_parse_table(27,"bool",'d',11);
    add_on_parse_table(27,"int",'d',12);
    add_on_parse_table(27,"char",'d',13);

    add_on_parse_table(29,"void",'r',45);
    add_on_parse_table(29,"bool",'r',45);
    add_on_parse_table(29,"int",'r',45);
    add_on_parse_table(29,"char",'r',45);
    add_on_parse_table(29,"id",'r',45);
    add_on_parse_table(29,"num",'r',45);
    add_on_parse_table(29,"character",'r',45);
    add_on_parse_table(29,"booleano",'r',45);
    add_on_parse_table(29,'+','d',44);
    add_on_parse_table(29,'-','d',45);
    add_on_parse_table(29,'$','r',45);

    add_on_parse_table(30,':','r',47);
    add_on_parse_table(30,',','r',47);
    add_on_parse_table(30,'+','r',47);
    add_on_parse_table(30,'-','r',47);
    add_on_parse_table(30,'<','r',47);
    add_on_parse_table(30,'>','r',47);
    add_on_parse_table(30,'==','r',47);
    add_on_parse_table(30,'!=','r',47);

    add_on_parse_table(31,':','r',51);
    add_on_parse_table(31,',','r',51);
    add_on_parse_table(31,'+','r',51);
    add_on_parse_table(31,'-','r',51);
    add_on_parse_table(31,'<','r',51);
    add_on_parse_table(31,'>','r',51);
    add_on_parse_table(31,'==','r',51);
    add_on_parse_table(31,'!=','r',51);

    add_on_parse_table(32,':','r',68);
    add_on_parse_table(32,',','r',68);
    add_on_parse_table(32,'+','r',68);
    add_on_parse_table(32,'-','r',68);
    add_on_parse_table(32,'<','r',68);
    add_on_parse_table(32,'>','r',68);
    add_on_parse_table(32,'==','r',68);
    add_on_parse_table(32,'!=','r',68);

    add_on_parse_table(33,':','r',69);
    add_on_parse_table(33,',','r',69);
    add_on_parse_table(33,'+','r',69);
    add_on_parse_table(33,'-','r',69);
    add_on_parse_table(33,'<','r',69);
    add_on_parse_table(33,'>','r',69);
    add_on_parse_table(33,'==','r',69);
    add_on_parse_table(33,'!=','r',69);

    add_on_parse_table(34,':','r',70);
    add_on_parse_table(34,',','r',70);
    add_on_parse_table(34,'+','r',70);
    add_on_parse_table(34,'-','r',70);
    add_on_parse_table(34,'<','r',70);
    add_on_parse_table(34,'>','r',70);
    add_on_parse_table(34,'==','r',70);
    add_on_parse_table(34,'!=','r',70);

    add_on_parse_table(35,"void",'r',7);
    add_on_parse_table(35,"bool",'r',7);
    add_on_parse_table(35,"int",'r',7);
    add_on_parse_table(35,"char",'r',7);
    add_on_parse_table(35,"id",'r',7);
    add_on_parse_table(35,"import",'r',7);
    add_on_parse_table(35,'$','r',7);
    add_on_parse_table(35,"id",'d',53);

    add_on_parse_table(41,"void",'r',18);
    add_on_parse_table(41,"bool",'r',18);
    add_on_parse_table(41,"int",'r',18);
    add_on_parse_table(41,"char",'r',18);
    add_on_parse_table(41,"id",'r',18);
    add_on_parse_table(41,"num",'r',18);
    add_on_parse_table(41,"character",'r',18);
    add_on_parse_table(41,"booleano",'r',18);
    add_on_parse_table(41,'$','r',18);

    add_on_parse_table(42,"void",'r',43);
    add_on_parse_table(42,"bool",'r',43);
    add_on_parse_table(42,"int",'r',43);
    add_on_parse_table(42,"char",'r',43);
    add_on_parse_table(42,"id",'r',43);
    add_on_parse_table(42,"num",'r',43);
    add_on_parse_table(42,"character",'r',43);
    add_on_parse_table(42,"booleano",'r',43);
    add_on_parse_table(42,'$','r',43);

    add_on_parse_table(43,"id",'d',31);
    add_on_parse_table(43,"num",'d',32);
    add_on_parse_table(43,"character",'d',33);
    add_on_parse_table(43,"booleano",'d',34);


    add_on_parse_table(44,"id",'r',71);
    add_on_parse_table(44,"num",'r',71);
    add_on_parse_table(44,"character",'r',71);
    add_on_parse_table(44,"booleano",'r',71);

    add_on_parse_table(45,"id",'r',72);
    add_on_parse_table(45,"num",'r',72);
    add_on_parse_table(45,"character",'r',72);
    add_on_parse_table(45,"booleano",'r',72);

    add_on_parse_table(46,',','r',48);
    add_on_parse_table(46,'+','r',48);
    add_on_parse_table(46,'-','r',48);
    add_on_parse_table(46,'<','r',48);
    add_on_parse_table(46,'>','r',48);
    add_on_parse_table(46,'==','r',48);
    add_on_parse_table(46,'!=','r',48);

    add_on_parse_table(47,"id",'d',31);
    add_on_parse_table(47,"num",'d',32);
    add_on_parse_table(47,"character",'d',33);
    add_on_parse_table(47,"booleano",'d',34);


    add_on_parse_table(48,"id",'d',58);

    add_on_parse_table(49,"void",'r',9);
    add_on_parse_table(49,"bool",'r',9);
    add_on_parse_table(49,"int",'r',9);
    add_on_parse_table(49,"char",'r',9);
    add_on_parse_table(49,"id",'r',9);
    add_on_parse_table(49,"import",'r',9);
    add_on_parse_table(49,'$','r',9);

    add_on_parse_table(50,"void",'r',10);
    add_on_parse_table(50,"bool",'r',10);
    add_on_parse_table(50,"int",'r',10);
    add_on_parse_table(50,"char",'r',10);
    add_on_parse_table(50,"id",'r',10);
    add_on_parse_table(50,"import",'r',10);
    add_on_parse_table(50,'$','r',10);

    add_on_parse_table(51,"void",'r',16);
    add_on_parse_table(51,"bool",'r',16);
    add_on_parse_table(51,"int",'r',16);
    add_on_parse_table(51,"char",'r',16);
    add_on_parse_table(51,"id",'r',16);
    add_on_parse_table(51,"num",'r',16);
    add_on_parse_table(51,"character",'r',16);
    add_on_parse_table(51,"booleano",'r',16);
    add_on_parse_table(51,'$','r',16);

    add_on_parse_table(53,',','d',61);

    add_on_parse_table(54,"void",'r',44);
    add_on_parse_table(54,"bool",'r',44);
    add_on_parse_table(54,"int",'r',44);
    add_on_parse_table(54,"char",'r',44);
    add_on_parse_table(54,"id",'r',44);
    add_on_parse_table(54,"num",'r',44);
    add_on_parse_table(54,"character",'r',44);
    add_on_parse_table(54,"booleano",'r',44);
    add_on_parse_table(54,'$','r',44);

    add_on_parse_table(55,',','r',49);
    add_on_parse_table(55,'+','r',49);
    add_on_parse_table(55,'-','r',49);
    add_on_parse_table(55,'<','r',49);
    add_on_parse_table(55,'>','r',49);
    add_on_parse_table(55,'==','r',49);
    add_on_parse_table(55,'!=','r',49);

    add_on_parse_table(57,',','d',64);


    add_on_parse_table(59,"void",'d',10);
    add_on_parse_table(59,"bool",'d',11);
    add_on_parse_table(59,"int",'d',12);
    add_on_parse_table(59,"char",'d',13);
    add_on_parse_table(59,"id",'d',70);
    add_on_parse_table(59,"if",'d',75);
    add_on_parse_table(59,"switch",'d',76);
    add_on_parse_table(59,"while",'d',77);
    add_on_parse_table(59,"for",'d',78);

    add_on_parse_table(61,"void",'d',10);
    add_on_parse_table(61,"bool",'d',11);
    add_on_parse_table(61,"int",'d',12);
    add_on_parse_table(61,"char",'d',13);

    add_on_parse_table(62,',','r',53);
    add_on_parse_table(62,'+','r',53);
    add_on_parse_table(62,'-','r',53);
    add_on_parse_table(62,'<','r',53);
    add_on_parse_table(62,'>','r',53);
    add_on_parse_table(62,'==','r',53);
    add_on_parse_table(62,'!=','r',53);

    add_on_parse_table(64,"id",'d',31);
    add_on_parse_table(64,"num",'d',32);
    add_on_parse_table(64,"caracter",'d',33);
    add_on_parse_table(64,"booleano",'d',34);

    add_on_parse_table(65,',','r',50);
    add_on_parse_table(65,'+','r',50);
    add_on_parse_table(65,'-','r',50);
    add_on_parse_table(65,'<','r',50);
    add_on_parse_table(65,'>','r',50);
    add_on_parse_table(65,'==','r',50);
    add_on_parse_table(65,'!=','r',50);


    add_on_parse_table(66,"id",'d',31);
    add_on_parse_table(66,"num",'d',32);
    add_on_parse_table(66,"caracter",'d',33);
    add_on_parse_table(66,"booleano",'d',34);

    add_on_parse_table(68,"void",'d',10);
    add_on_parse_table(68,"bool",'d',11);
    add_on_parse_table(68,"int",'d',12);
    add_on_parse_table(68,"char",'d',13);
    add_on_parse_table(68,"id",'d',70);
    add_on_parse_table(68,"if",'d',75);
    add_on_parse_table(68,"switch",'d',76);
    add_on_parse_table(68,"while",'d',77);
    add_on_parse_table(68,"for",'d',78);

    add_on_parse_table(69,"id",'d',86);

    add_on_parse_table(71,"void",'r',24);
    add_on_parse_table(71,"bool",'r',24);
    add_on_parse_table(71,"int",'r',24);
    add_on_parse_table(71,"char",'r',24);
    add_on_parse_table(71,"id",'r',24);
    add_on_parse_table(71,"if",'r',24);
    add_on_parse_table(71,"switch",'r',24);
    add_on_parse_table(71,"while",'r',24);
    add_on_parse_table(71,"for",'r',24);

    add_on_parse_table(72,"void",'r',25);
    add_on_parse_table(72,"bool",'r',25);
    add_on_parse_table(72,"int",'r',25);
    add_on_parse_table(72,"char",'r',25);
    add_on_parse_table(72,"id",'r',25);
    add_on_parse_table(72,"if",'r',25);
    add_on_parse_table(72,"switch",'r',25);
    add_on_parse_table(72,"while",'r',25);
    add_on_parse_table(72,"for",'r',25);

    add_on_parse_table(73,"void",'r',26);
    add_on_parse_table(73,"bool",'r',26);
    add_on_parse_table(73,"int",'r',26);
    add_on_parse_table(73,"char",'r',26);
    add_on_parse_table(73,"id",'r',26);
    add_on_parse_table(73,"if",'r',26);
    add_on_parse_table(73,"switch",'r',26);
    add_on_parse_table(73,"while",'r',26);
    add_on_parse_table(73,"for",'r',26);

    add_on_parse_table(74,"void",'r',27);
    add_on_parse_table(74,"bool",'r',27);
    add_on_parse_table(74,"int",'r',27);
    add_on_parse_table(74,"char",'r',27);
    add_on_parse_table(74,"id",'r',27);
    add_on_parse_table(74,"if",'r',27);
    add_on_parse_table(74,"switch",'r',27);
    add_on_parse_table(74,"while",'r',27);
    add_on_parse_table(74,"for",'r',27);

    add_on_parse_table(80,"id",'d',94);

    add_on_parse_table(82,',','d',64);

    add_on_parse_table(83,',','r',52);
    add_on_parse_table(83,'+','r',52);
    add_on_parse_table(83,'-','r',52);
    add_on_parse_table(83,'<','r',52);
    add_on_parse_table(83,'>','r',52);
    add_on_parse_table(83,'==','r',52);
    add_on_parse_table(83,'!=','r',52);

    add_on_parse_table(84,"void",'r',19);
    add_on_parse_table(84,"bool",'r',19);
    add_on_parse_table(84,"int",'r',19);
    add_on_parse_table(84,"char",'r',19);
    add_on_parse_table(84,"id",'r',19);
    add_on_parse_table(84,'$','r',19);

    add_on_parse_table(87,"void",'r',23);
    add_on_parse_table(87,"bool",'r',23);
    add_on_parse_table(87,"int",'r',23);
    add_on_parse_table(87,"char",'r',23);
    add_on_parse_table(87,"id",'r',23);
    add_on_parse_table(87,"if",'r',23);
    add_on_parse_table(87,"switch",'r',23);
    add_on_parse_table(87,"while",'r',23);
    add_on_parse_table(87,"for",'r',23);

    add_on_parse_table(88,"id",'d',31);
    add_on_parse_table(88,"num",'d',32);
    add_on_parse_table(88,"caracter",'d',33);
    add_on_parse_table(88,"booleano",'d',34);

    add_on_parse_table(90,"id",'d',31);
    add_on_parse_table(90,"num",'d',32);
    add_on_parse_table(90,"caracter",'d',33);
    add_on_parse_table(90,"booleano",'d',34);

    add_on_parse_table(91,"booleano",'d',103);

    add_on_parse_table(92,"id",'d',31);
    add_on_parse_table(92,"num",'d',32);
    add_on_parse_table(92,"caracter",'d',33);
    add_on_parse_table(92,"booleano",'d',34);

    add_on_parse_table(93,"void",'d',10);
    add_on_parse_table(93,"bool",'d',11);
    add_on_parse_table(93,"int",'d',12);
    add_on_parse_table(93,"char",'d',13);
    add_on_parse_table(93,"id",'d',9);

    add_on_parse_table(94,',','d',61);

    add_on_parse_table(96,"void",'r',22);
    add_on_parse_table(96,"bool",'r',22);
    add_on_parse_table(96,"int",'r',22);
    add_on_parse_table(96,"char",'r',22);
    add_on_parse_table(96,"id",'r',22);
    add_on_parse_table(96,"if",'r',22);
    add_on_parse_table(96,"switch",'r',22);
    add_on_parse_table(96,"while",'r',22);
    add_on_parse_table(96,"for",'r',22);

    add_on_parse_table(97,"void",'r',28);
    add_on_parse_table(97,"bool",'r',28);
    add_on_parse_table(97,"int",'r',28);
    add_on_parse_table(97,"char",'r',28);
    add_on_parse_table(97,"id",'r',28);
    add_on_parse_table(97,"if",'r',28);
    add_on_parse_table(97,"switch",'r',28);
    add_on_parse_table(97,"while",'r',28);
    add_on_parse_table(97,"for",'r',28);

    add_on_parse_table(98,"id",'d',31);
    add_on_parse_table(98,"num",'d',32);
    add_on_parse_table(98,"caracter",'d',33);
    add_on_parse_table(98,"booleano",'d',34);


    add_on_parse_table(100,"void",'r',31);
    add_on_parse_table(100,"bool",'r',31);
    add_on_parse_table(100,"int",'r',31);
    add_on_parse_table(100,"char",'r',31);
    add_on_parse_table(100,"id",'r',31);
    add_on_parse_table(100,"if",'r',31);
    add_on_parse_table(100,"switch",'r',31);
    add_on_parse_table(100,"while",'r',31);
    add_on_parse_table(100,"for",'r',31);

    add_on_parse_table(102,'<','d',111);
    add_on_parse_table(102,'>','d',112);
    add_on_parse_table(102,'==','d',113);
    add_on_parse_table(102,'!=','d',114);

    add_on_parse_table(105,"id",'d',31);
    add_on_parse_table(105,"num",'d',32);
    add_on_parse_table(105,"caracter",'d',33);
    add_on_parse_table(105,"booleano",'d',34);

    add_on_parse_table(108,"void",'r',30);
    add_on_parse_table(108,"bool",'r',30);
    add_on_parse_table(108,"int",'r',30);
    add_on_parse_table(108,"char",'r',30);
    add_on_parse_table(108,"id",'r',30);
    add_on_parse_table(108,"if",'r',30);
    add_on_parse_table(108,"switch",'r',30);
    add_on_parse_table(108,"while",'r',30);
    add_on_parse_table(108,"for",'r',30);

    add_on_parse_table(110,"id",'d',31);
    add_on_parse_table(110,"num",'d',32);
    add_on_parse_table(110,"caracter",'d',33);
    add_on_parse_table(110,"booleano",'d',34);

    add_on_parse_table(111,"id",'r',73);
    add_on_parse_table(111,"num",'r',73);
    add_on_parse_table(111,"caracter",'r',73);
    add_on_parse_table(111,"booleano",'r',73);

    add_on_parse_table(112,"id",'r',74);
    add_on_parse_table(112,"num",'r',74);
    add_on_parse_table(112,"caracter",'r',74);
    add_on_parse_table(112,"booleano",'r',74);

    add_on_parse_table(113,"id",'r',75);
    add_on_parse_table(113,"num",'r',75);
    add_on_parse_table(113,"caracter",'r',75);
    add_on_parse_table(113,"booleano",'r',75);

    add_on_parse_table(114,"id",'r',76);
    add_on_parse_table(114,"num",'r',76);
    add_on_parse_table(114,"caracter",'r',76);
    add_on_parse_table(114,"booleano",'r',76);

    add_on_parse_table(118,"void",'r',29);
    add_on_parse_table(118,"bool",'r',29);
    add_on_parse_table(118,"int",'r',29);
    add_on_parse_table(118,"char",'r',29);
    add_on_parse_table(118,"id",'r',29);
    add_on_parse_table(118,"if",'r',29);
    add_on_parse_table(118,"switch",'r',29);
    add_on_parse_table(118,"while",'r',29);
    add_on_parse_table(118,"for",'r',29);


    add_on_parse_table(119,"void",'d',10);
    add_on_parse_table(119,"bool",'d',11);
    add_on_parse_table(119,"int",'d',12);
    add_on_parse_table(119,"char",'d',13);
    add_on_parse_table(119,"id",'d',70);
    add_on_parse_table(119,"if",'d',75);
    add_on_parse_table(119,"switch",'d',76);
    add_on_parse_table(119,"while",'d',77);
    add_on_parse_table(119,"for",'d',78);

    add_on_parse_table(121,"case",'d',127);


    add_on_parse_table(122,"void",'d',10);
    add_on_parse_table(122,"bool",'d',11);
    add_on_parse_table(122,"int",'d',12);
    add_on_parse_table(122,"char",'d',13);
    add_on_parse_table(122,"id",'d',70);
    add_on_parse_table(122,"if",'d',75);
    add_on_parse_table(122,"switch",'d',76);
    add_on_parse_table(122,"while",'d',77);
    add_on_parse_table(122,"for",'d',78);

    add_on_parse_table(123,"id",'d',129);

    add_on_parse_table(126,"case",'d',127);


    add_on_parse_table(127,"id",'d',31);
    add_on_parse_table(127,"num",'d',32);
    add_on_parse_table(127,"caracter",'d',33);
    add_on_parse_table(127,"booleano",'d',34);

    add_on_parse_table(130,"void",'r',34);
    add_on_parse_table(130,"bool",'r',34);
    add_on_parse_table(130,"int",'r',34);
    add_on_parse_table(130,"char",'r',34);
    add_on_parse_table(130,"id",'r',34);
    add_on_parse_table(130,"if",'r',34);
    add_on_parse_table(130,"else",'d',137);
    add_on_parse_table(130,"switch",'r',34);
    add_on_parse_table(130,"while",'r',34);
    add_on_parse_table(130,"for",'r',34);


    add_on_parse_table(131,"void",'r',35);
    add_on_parse_table(131,"bool",'r',35);
    add_on_parse_table(131,"int",'r',35);
    add_on_parse_table(131,"char",'r',35);
    add_on_parse_table(131,"id",'r',35);
    add_on_parse_table(131,"if",'r',35);
    add_on_parse_table(131,"switch",'r',35);
    add_on_parse_table(131,"while",'r',35);
    add_on_parse_table(131,"for",'r',35);

    add_on_parse_table(134,"void",'r',41);
    add_on_parse_table(134,"bool",'r',41);
    add_on_parse_table(134,"int",'r',41);
    add_on_parse_table(134,"char",'r',41);
    add_on_parse_table(134,"id",'r',41);
    add_on_parse_table(134,"if",'r',41);
    add_on_parse_table(134,"switch",'r',41);
    add_on_parse_table(134,"while",'r',41);
    add_on_parse_table(134,"for",'r',41);

    add_on_parse_table(135,"id",'d',31);
    add_on_parse_table(135,"num",'d',32);
    add_on_parse_table(135,"caracter",'d',33);
    add_on_parse_table(135,"booleano",'d',34);

    add_on_parse_table(136,"void",'r',32);
    add_on_parse_table(136,"bool",'r',32);
    add_on_parse_table(136,"int",'r',32);
    add_on_parse_table(136,"char",'r',32);
    add_on_parse_table(136,"id",'r',32);
    add_on_parse_table(136,"if",'r',32);
    add_on_parse_table(136,"switch",'r',32);
    add_on_parse_table(136,"while",'r',32);
    add_on_parse_table(136,"for",'r',32);

    add_on_parse_table(138,"id",'d',31);
    add_on_parse_table(138,"num",'d',32);
    add_on_parse_table(138,"caracter",'d',33);
    add_on_parse_table(138,"booleano",'d',34);


    add_on_parse_table(140,"void",'d',10);
    add_on_parse_table(140,"bool",'d',11);
    add_on_parse_table(140,"int",'d',12);
    add_on_parse_table(140,"char",'d',13);
    add_on_parse_table(140,"id",'d',70);
    add_on_parse_table(140,"if",'d',75);
    add_on_parse_table(140,"switch",'d',76);
    add_on_parse_table(140,"while",'d',77);
    add_on_parse_table(140,"for",'d',78);


    add_on_parse_table(145,"id",'d',31);
    add_on_parse_table(145,"num",'d',32);
    add_on_parse_table(145,"caracter",'d',33);
    add_on_parse_table(145,"booleano",'d',34);


    add_on_parse_table(146,"void",'d',10);
    add_on_parse_table(146,"bool",'d',11);
    add_on_parse_table(146,"int",'d',12);
    add_on_parse_table(146,"char",'d',13);
    add_on_parse_table(146,"id",'d',70);
    add_on_parse_table(146,"if",'d',75);
    add_on_parse_table(146,"switch",'d',76);
    add_on_parse_table(146,"while",'d',77);
    add_on_parse_table(146,"for",'d',78);


    add_on_parse_table(147,"void",'r',33);
    add_on_parse_table(147,"bool",'r',33);
    add_on_parse_table(147,"int",'r',33);
    add_on_parse_table(147,"char",'r',33);
    add_on_parse_table(147,"id",'r',33);
    add_on_parse_table(147,"if",'r',33);
    add_on_parse_table(147,"switch",'r',33);
    add_on_parse_table(147,"while",'r',33);
    add_on_parse_table(147,"for",'r',33);

    add_on_parse_table(148,"break",'d',151);

    add_on_parse_table(152,"void",'r',42);
    add_on_parse_table(152,"bool",'r',42);
    add_on_parse_table(152,"int",'r',42);
    add_on_parse_table(152,"char",'r',42);
    add_on_parse_table(152,"id",'r',42);
    add_on_parse_table(152,"if",'r',42);
    add_on_parse_table(152,"switch",'r',42);
    add_on_parse_table(152,"while",'r',42);
    add_on_parse_table(152,"for",'r',42);

    add_on_parse_table(153,"case",'r',38);






















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









