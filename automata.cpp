#include "automata.h"

automata::automata()
{
    mat= new matriz(4);
    s_accepted.push_back(false);
    s_accepted.push_back(true);
    s_accepted.push_back(true);
    s_accepted.push_back(false);

    f_names.push_back("-");
    f_names.push_back("Id");
    f_names.push_back("Integer");
    f_names.push_back("Noterminal");
}

void automata::fill_matriz()
{
        mat->at(0).push_back(1);
        mat->at(0).push_back(1);
        mat->at(0).push_back(2);
        mat->at(0).push_back(3);
        mat->at(1).push_back(1);
        mat->at(1).push_back(1);
        mat->at(1).push_back(1);
        mat->at(1).push_back(-1);
        mat->at(2).push_back(-1);
        mat->at(2).push_back(-1);
        mat->at(2).push_back(2);
        mat->at(2).push_back(-1);
        mat->at(3).push_back(-1);
        mat->at(3).push_back(-1);
        mat->at(3).push_back(2);
        mat->at(3).push_back(-1);
}

void automata::print_matriz()
{
    for(int i=0; i<4;i++)
    {
            for(int j=0;j<4;j++)
                cout<<mat->at(i)[j]<<" ";
            cout<<endl;
    }
}

string automata::executar(string a)
{
    int i=0;
    int e=0; //estado inicial
    int tmp=-1;
    while(i <a.size())
    {
        tmp=eval(a[i], e);
        if(tmp<0)
        {
           return "token_desconocido";
        }
        else
        {
            e=tmp;
        }
        i++;
    }
    if(s_accepted[tmp])
    {
        return f_names[tmp];
    }
}

int automata::is_alpha(char c,int x)
{
    int e=-1;
    if(isalpha(c))
        e=0;
    return mat->at(x)[e];
}
int automata::is_subindent(char c,int x)
{
    int e=-1;
    if(c=='_') e=1;
        return mat->at(x)[e];
}
int automata::is_digit(char c,int x)
{
    int e=-1;
    if(isdigit(c)) e=2;
         return mat->at(x)[e];
}
int automata::is_minus(char c,int x)
{
    int e=-1;
    if(c=='-')
        e=3;
    return mat->at(x)[e];
}

int automata::eval(char c, int a)
{
    int (automata::*f0[])(char,int)={&automata::is_alpha,&automata::is_subindent,&automata::is_digit,&automata::is_minus};
    vector<int> next(4);
    for(auto r:f0)
    {
        int next_e= (this->*r)(c,a);
         if(next_e>0)
        {
            return next_e;
        }
    }
    return -1;
}
