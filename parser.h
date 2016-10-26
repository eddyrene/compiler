#ifndef PARSER_H
#define PARSER_H
#include "utilities.h"

typedef char action;
typedef pair<state,token> state_token;
typedef pair<action, state> action_state;
typedef vector<token> v_token;

class parser{
    private:
        /*pila*/
        stack<token> s_token;
        stack<state> s_state;

        /*vector de tokens de lexer a pila en parser*/
        queue<token> q_input_tokens;

        /*tabla de accion, ir-a*/
        map< state_token , action_state > parser_table;

        /*tabla de reduccion*/
        map< state ,v_token > t_reduction;
    public:
        parser();
        void set_vector_tokens( vector<token> v_token);
        void fill_parser_table();
        void fill_table_reduction();
        void add_on_parse_table(state s, token t, action a, state ss);
        void parse();

        /*otras funciones */
        void print_s_token(){
            cout<<"\n------------tokens de stack tokens"<<endl;
            while( !s_token.empty() ){
                cout<<s_token.top()<<endl;
                s_token.pop();
            }
        }
        void print_s_state(){
            cout<<"\n-----------tokens de stack estados"<<endl;
            while( !s_state.empty() ){
                cout<<s_state.top()<<endl;
                s_state.pop();
            }
        }
        void print_q_input_tokens(){
            cout<<"\n----------tokens de entrada"<<endl;
            while( !q_input_tokens.empty() ){
                cout<<q_input_tokens.front()<<endl;
                q_input_tokens.pop();
            }
        }














};

#endif // PARSER_H
