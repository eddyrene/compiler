#ifndef SEMANTIC_H
#define SEMANTIC_H
#include "utilities.h"
#include "tree.h"

class semantic{
    private:
        node *root;//puntero a la raiz del arbol
        //map< string,  >
    public:
        semantic( node *n );
        void set_semantic_rules();
};

#endif // SEMANTIC_H
