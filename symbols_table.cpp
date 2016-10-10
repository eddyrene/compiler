#include "symbols_table.h"
#
symbols_table::symbols_table()
{
    table= new my_hash;
    file_name="../compiler/resources/symbols_table.txt";
    this->read();
    au = new automata();
    au->fill_matriz();
}

/*
 * Carga los datos en memoria-> tabla hash
 */
void symbols_table::read()
{
    ifstream doc(file_name);
    if(!doc.is_open())
        cout<<"error al abrir el archivo"<<endl;
    string t,a,b;
    int i=0;
    getline(doc,t);
    getline(doc,t);

    while(!doc.eof())
    {
        doc>>a>>b;
        table->insert({a,b});
    }
}

void symbols_table::print_table()
{
    for (auto & x:*table)
        cout << x.first << ": " << x.second << endl;
    cout<< "total:"<<table->size()<<endl;
}
/*
 * permite obtener la tabla como un metodo
 */
my_hash* symbols_table::get_table()
{
    return table;
}

string symbols_table::get_token(string p)
{
    string rpta;
    auto it = table->find(p);
    if(it==table->end())
        rpta=au->executar(p);// evalua el automata;
    else
        rpta=it->second;
    return rpta;
}

bool symbols_table::is(string p)
{
    auto it = table->find(p);  // -_-
    if(it==table->end())
        return false;
    return true;
}


//temporal
bool symbols_table::entero( string cadena ){
    bool r= false;
    int q0,q1;
    q0=int(cadena[0]);
    if ( 49<=q0 && q0<=57){
        for (int i = 1; i < cadena.length(); ++i){
            q1=int(cadena[i]);
            if( !(48<=q1 && q1<=57) ){
                r=false;
                return r;
            }
        }
        r=true;
    }else{
        if( (cadena[0]=='0' && cadena.length()==1) ){
            r=true;
        }else{
            r=false;
        }
    }
    return r;
}


bool symbols_table::is_identifier( string cadena){
    bool r= false;
    int q0,q1;
    q0 = int(cadena[0]);
    if(  q0==95 || ( 65 <= q0 && q0<=90 )  ||  ( 97 <= q0 && q0<=122 ) ){
        for (int i = 1; i < cadena.length(); ++i){
            q1=int(cadena[i]);
            if( q1==95 || ( 65 <= q1 && q1<=90 )  ||  ( 97 <= q1 && q1<=122 ) || ( 48 <= q1 && q1<=57 )){
            }else{
                r=false;
                return r;
            }
        }
        r=true;
    }else{
        r= false;
    }
    return r;
}






string symbols_table::evaluar( string cadena ){
    /*if( entero(cadena)){
        return "entero";
    }
    if( is_identifier(cadena)){
        return "id";
    }
    return "error-sin-tipo";*/

    au->executar(cadena);
}





