# proyecto compiladores
#codigos que acepta la gramatica:
#====codigo 1=====
import id;
import id.id;
import id.id.id.id.id;
import id.*;
import id.id.* ;

int a;
bool b=5;
char c=5+8;
int f= new person() ;
int d=10+person.age(2016-1995);
int e=fn();


#=====codigo 2======
import class.*;

int a=1;
int b=5;
void fun(){ 
	if ( a<d ) {
		int b = b ;
	}
	
	while ( 4 < a  ) {
		b = 4+3 ;
	}

	for ( int i = value ; i <10 ; i=i+1 ) {
		a = b;
	}

	a =3;
	switch ( a ) {
		case 3 :
			a = 0;
			break ;
		case 2 :
			fn(2,5);
			break ;
	}
}

#=======codigo 3==========

int pin3 =3;
int pin5 =5;
int pin6 =6;
int pin9 =9;
int estado;
int vel = 75;
void setup(){
  Serial.begin (9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void activar(int v){
    analogWrite(pin3, v); 
    analogWrite(pin5, v);
    analogWrite(pin6, v);
    analogWrite(pin9, v);
}
void parar(){
  analogWrite(pin3, 0);
  analogWrite(pin5, 0);
  analogWrite(pin6, 0);
  analogWrite(pin9, 0);
}
void adelante(int v){
    analogWrite(pin3, v); 
    analogWrite(pin5, 0);
    analogWrite(pin6, 0);
    analogWrite(pin9, v);
}
void atras(int v){
    analogWrite(pin3, 0); 
    analogWrite(pin5, v);
    analogWrite(pin6, v);
    analogWrite(pin9, 0);
  }
void derecha(int v){
    analogWrite(pin3, v); 
    analogWrite(pin5, 0);
    analogWrite(pin6, v);
    analogWrite(pin9, 0);
}


void izquierda(int v){
    analogWrite(pin3, 0); 
    analogWrite(pin5, v);
    analogWrite(pin6, 0);
    analogWrite(pin9, v);
}

 void loop() { 
if (Serial.available ()>0){
    estado = Serial.read();
    if (estado != 1){
      switch(estado){
          case 'w':
          adelante(vel); 
          break;
          case 's': // 
          atras(vel); 
          break;
          case 'a':
          izquierda(vel); 
          break;
          case 'd':
          derecha(vel); 
          break;
          case 'x':
          activar(vel); 
          break;
          case 'c':
          parar();
          break;          
      }
    }
  }
}
