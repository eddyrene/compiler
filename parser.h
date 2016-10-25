#ifndef PARSER_H
#define PARSER_H
#include "utilities.h"

typedef char action;
typedef pair<state,token> state_token;
typedef pair<action, state> action_state;


class parser{
    private:
        /*pila*/
        stack<token> s_token;
        stack<state> s_stado;


        /*vector de tokens de lexer a pila en parser*/
        queue<token> q_input_tokens;

        /*tabla de accion, ir-a*/
        map< state_token , action_state > parser_table;

        /*tabla de reduccion*/
        vector<token> t_reduction;
    public:
        parser();
        void set_vector_tokens( vector<token> v_token);
        void fill_parser_table();
        void add_on_parse_table(state s, token t, action a, state ss);





};

#endif // PARSER_H
