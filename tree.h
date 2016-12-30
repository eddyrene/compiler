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
        tree();
        tree(node *n);
        void set_root(node *n);
        void print_tree_to_file(node *n);
        void print_tree_dot();
        bool is_terminal_token(token tk);
        void insert_terminal_tokens();
};








#endif // TREE_H
