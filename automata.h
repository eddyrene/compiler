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
    void fill_matriz();//llenar la tabla de estados
    void print_matriz();// imprimir la tabla
    int is_alpha(char c, int a); /* Verifica si es un caracter del alfabeto */
    int is_minus(char c, int a); /* Verifica si es un subguion */
    int is_subindent(char c, int a);/*Verifica si es un digito */
    int is_digit(char c, int a);/*Verifica si es un digito */
    int eval(char c, int a);/*Evaluacion en el automata*/
    string executar(string a);/*Evaluacion en el automata*/

    void (automata::*f0[4])(char,int) const; // vector de punteros a funciones

};

#endif // AUTOMATA_H
