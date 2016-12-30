#include "tree.h"

tree::tree(){
    root = NULL;
    insert_terminal_tokens();
}

tree::tree(node *n){
    root = n;
    insert_terminal_tokens();
}

void tree::set_root(node *n){
    root = n;
}



void tree::print_tree_to_file( node *n ){
    if( !n ){
        return;
    }
    int size_vector = n->branches.size();
    if( n->branches.size()>0  ){
        ofstream file;
        file.open(filename.c_str(),ios::app);
        file<<'"'<<  n <<'"'<<";"<<endl;
        file<<'"'<<  n <<'"'<<"[label="<<'"'+ n->label +'"'+"];"<<endl;
        for (int i =size_vector-1; i>=0; --i){
            file<<'"'<< n <<'"'<<" -> "<<'"'<< n->branches[i]<<'"'<<";"<<endl;
            file<<'"'<< n->branches[i]<<'"'<< "[label="<<'"'+ n->branches[i]->label +'"'+"];"<<endl;

        }
        file.close();
    }


    if(size_vector>0){
        for (int i = size_vector-1; i >=0 ; --i){
            print_tree_to_file( n->branches[i] );
        }
    }else{
        return;
    }



}

void tree::print_tree_dot( ){
    string run = "rm "+filename;
    system(run.c_str());

    ofstream file;
    file.open(filename.c_str(),ios::app);
    file<<"digraph G {"<<endl;
    file.close();

    print_tree_to_file(root);

    file.open(filename.c_str(),ios::app);
    file<<"}"<<endl;
    file.close();

    run = "dot -Tpng "+filename+" -o "+filename+".png\n";
    system(run.c_str());
}

bool tree::is_terminal_token(token tk){
    symbols_table st;
    if( st.is(tk) || m_terminal_nodes[tk] ){
        return true;
    }
    return false;
}

void tree::insert_terminal_tokens(){
        m_terminal_nodes["op"]=true;
        m_terminal_nodes["op_bool"]=true;
        m_terminal_nodes["dt"]=true;
        m_terminal_nodes["EPS"]=true;
        m_terminal_nodes["id"]=true;
        m_terminal_nodes["value"]=true;
        m_terminal_nodes["booleano"]=true;
}

