#ifndef SYMBOLS_TABLE_H
#define SYMBOLS_TABLE_H

#include<unordered_map>
#include <fstream>
#include <string>
#include <iostream>
#include "automata.h"


using namespace std;
typedef unordered_map<string,string> my_hash;

class symbols_table
{

private:
    my_hash * table; // Estructura de almenamiento
    automata * au; // automata , identifadores o numeros(enteros)
private:
     string evaluar( string cadena ); // Evaluar el en el automata
public:
    symbols_table();
    void read(); // Llena la tabla
    void print_table(); // Mostrar tabla
    my_hash* get_table();
    string get_token(string p);
    bool is(string p); // está en la tabla ?
};

#endif // SYMBOLS_TABLE_H
