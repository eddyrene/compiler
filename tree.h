#ifndef TREE_H
#define TREE_H
#include "utilities.h"
#include "symbols_table.h"

class node{
    public:
        string label;  // EXP, id
        /*agregar nuevos atrivutos*/
        vector< node* > branches;

    public:
        node(string l){
            label = l;
        }
        void add_branch(node *n){
            branches.push_back(n);
        }
};


class tree{
    private:
        node *root;

    public:
        string filename="tree.gv";
        stack< node* > s_buffer;/*almacena temporalmete los nodos*/
        map<token,bool> m_terminal_nodes;

    public:
        tree(){
            root = NULL;
            insert_terminal_tokens();
        }
        tree(node *n){
            root = n;
            insert_terminal_tokens();
        }
        void set_root(node *n){
            root = n;
            cout<<"root:"<<n->label<<endl;
        }

        void print_tree_to_file(node *n);
        void print_tree_dot();

        bool is_terminal_token(token tk){
            symbols_table st;
            if( st.is(tk) || m_terminal_nodes[tk] ){
                return true;
            }
            return false;
        }

        void insert_terminal_tokens(){
            m_terminal_nodes["op"]=true;
            m_terminal_nodes["op_bool"]=true;
            m_terminal_nodes["dt"]=true;
            m_terminal_nodes["EPS"]=true;
            m_terminal_nodes["id"]=true;
            m_terminal_nodes["value"]=true;
<<<<<<< HEAD
            m_terminal_nodes["booleano"]=true;

=======
>>>>>>> 3bcbd20e3444b623f0d59f46d1eb3e6cedfd5d93
        }


};








#endif // TREE_H
