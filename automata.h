#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <ctype.h>
#include <cstdio>
#include <algorithm>
//#define length(x) (sizeof(x)/sizeof(x[0])) // obtenemos size de un array
using namespace std;

typedef vector< vector<int > > matriz;

class automata
{
private:
   matriz *mat;
   vector<bool> s_accepted;
   vector<string> f_names;
public:
    automata();
    void fill_matriz();
    void print_matriz();
    int is_alpha(char c, int a);
    int is_minus(char c, int a);
    int is_subindent(char c, int a);
    int is_digit(char c, int a);
    int eval(char c, int a);
    string executar(string a);

    void (automata::*f0[4])(char,int) const; // vector de punteros a funciones

};

#endif // AUTOMATA_H
