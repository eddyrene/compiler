#include "tree.h"


/*
void print_tree( node *&n ){
    if( !n ){
        return;
    }
    int size_vector = n->branches.size();
    if( n->branches.size()>0  ){
        cout<<'"'<<  n <<'"'<<";"<<endl;
        cout<<'"'<<  n <<'"'<<"[label="<<'"'+ n->label +'"'+"];"<<endl;
        for (int i = 0; i < size_vector; ++i){
            cout<<'"'<< n <<'"'<<" -> "<<'"'<< n->branches[i]<<'"'<<";"<<endl;
            cout<<'"'<< n->branches[i]<<'"'<< "[label="<<'"'+ n->branches[i]->label +'"'+"];"<<endl;
        }
    }
    for (int i = 0; i < size_vector; ++i){
        print_tree( n->branches[i] );
    }
}*/

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
        //for (int i =0; i<size_vector; ++i){
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
    //string run = "dot -Tpng "+nameFile+" -o "+nameFile+".png\n";
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
