#include "lexer.h"

lexer::lexer(){
}

lexer::lexer(string source_code){
    tokenizer(source_code);
}


void  lexer::tokenizer(string cad){
    buffer_tokens.clear();/*limpiar buffer de tokens*/
    string buffer="";
    string cc="";
    int len = cad.length();
    for (int i = 0; i <= len; ++i) {
        if(cad[i] ==' ' || i==len || st.is(cc+cad[i]) ){
            if( st.is(cc+cad[i]) ){/*si // == <= >= + -*/
                set_token_into_buffer( buffer );/*insertar en buffer*/
                buffer="";
                if( i<(len-1) ){ /*si == //acceder solo hasta el ultimo caracter*/
                    if( !st.is(cc+cad[i-1]+cad[i]) && !st.is(cc+cad[i]+cad[i+1]) ){
                       set_token_into_buffer(cc+cad[i]);/*insertar en buffer*/
                    }
                    /*simbolos unarios y dobles*/
                    if( st.is(cc+cad[i]+cad[i+1])){
                       if( (cad[i]=='/' &&  cad[i+1]=='/') || (cad[i]=='/' &&  cad[i+1]=='*') || (cad[i]=='*' &&  cad[i+1]=='/') ){
                       }else{/*token de dos simbolos: ++ -- <= >= */
                            cout<<"lol "<<cc+cad[i]+cad[i+1]  <<endl;
                            set_token_into_buffer( cc+cad[i]+cad[i+1] );/*insertar en buffer*/
                            i++;
                       }
                    }
                    if( cad[i]=='/' && cad[i+1]=='/' ){/*comentarios de una linea*/
                        while(true){
                            if( int(cad[i])==10 ){
                                break;
                            }else{
                                i++;
                            }
                        }
                    }
                    if( cad[i]=='/' && cad[i+1]=='*' ){/*comentarios grandes*/
                        while(true){
                            if( i<(len-1) && cad[i]=='*' && cad[i+1]=='/' ){/*aviso: quisa violacion de memoria*/
                                i++;
                                break;
                            }else{
                                i++;
                            }
                        }
                    }
                }else{
                    set_token_into_buffer( cc+cad[i] );/*insertar en buffer*/
                }
            }
            else{ /* poner en buffer de tokens */
                set_token_into_buffer( buffer );/*insertar en buffer*/
                buffer ="";
            }

        }else{/*altos de linea y llenado de buffer*/
            if( int(cad[i])==10 || int(cad[i])==9 ){
                set_token_into_buffer( buffer );/*insertar en buffer*/
                buffer="";
            }
            else{
                buffer= buffer+cad[i];
            }
        }
    }
}




/*
se inserta  token no vacio
*/
void lexer::set_token_into_buffer(token _token){
    if( _token == ""){
        return;
    }
    else{
        //cout<<"|"<<token<<"|"<<endl;
        buffer_tokens.push_back( st.get_token(_token) );
    }
}


void lexer::print_buffer_tokens(){
    for(auto i:buffer_tokens){
        cout<<"|"<<i<<"|"<<endl;
    }
}



vector<token> lexer::get_buffer_tokens(){
    return buffer_tokens;
}

