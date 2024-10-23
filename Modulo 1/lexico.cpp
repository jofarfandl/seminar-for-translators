#include "lexico.h"

Lexico::Lexico(string fuente){
     ind= 0;   
     this->fuente= fuente;
}      

Lexico::Lexico(){
     ind= 0;                  
}      

string Lexico::tipoAcad(int tipo){//aqui
     string cad= "";

     switch (tipo){
          case TipoSimbolo::IDENTIFICADOR: cad= "Identificador";
               break;

          case TipoSimbolo::ENTERO: cad= "Entero";
               break;
          
          case TipoSimbolo::REAL: cad= "Real";
               break;

          case TipoSimbolo::OPADIC: cad= "Op. Adicion";
               break;

          case TipoSimbolo::OPMULT: cad= "Op. Multiplicacion";
               break;    

          case TipoSimbolo::OPASIGNACION: cad= "Op. Asignacion";
               break;        

          case TipoSimbolo::OPRELAC: cad= "Op. Relacional";
               break;

          case TipoSimbolo::OPAND: cad= "Op. And";
               break;
          
          case TipoSimbolo::OPOR: cad= "Op. Or";
               break;

          case TipoSimbolo::OPNOT: cad= "Op. Not";
               break;
          
          case TipoSimbolo::COMA: cad= "Coma";
               break;
          
          case TipoSimbolo::PUNTOYCOMA: cad= "Punto y coma";
               break;
          
          case TipoSimbolo::PARABI: cad= "Parentesis abierto";
               break;

          case TipoSimbolo::PARCERR: cad= "Parentesis cerrado";
               break;

          case TipoSimbolo::CORCHABI: cad= "Corchete abierto";
               break;

          case TipoSimbolo::CORCHCERR: cad= "Corchete cerrado";
               break;
          
          //palabras reservadas
          case TipoSimbolo::IF: cad= "If";
               break;

          case TipoSimbolo::WHILE: cad= "While";
               break;

          case TipoSimbolo::RETURN: cad= "Return";
               break;

          case TipoSimbolo::ELSE: cad= "Else";
               break;

          case TipoSimbolo::CADENA: cad= "Cadena";
               break;

          case TipoSimbolo::TIPO: cad= "Tipo";
               break;
          
          case TipoSimbolo::PESOS: cad= "Fin de la Entrada";//fin de las palabras
               break;  
     }
     return cad;
}

void Lexico::entrada(string fuente){
     ind= 0;                  
     this->fuente= fuente;
}

int Lexico::sigSimbolo(){//aqui

     estado=0;
     continua= true;
     bool entero = true;
     bool reales = true;
     bool cadena = false;
     bool negativo = true;//
     simbolo= "";

     //Inicio del Automata
     while (continua){
          c = sigCaracter();//guardamos la palabra
          int tamanio = c.length();//verificamos el tamaño del arreglo
          switch (estado){//comparamos la palabra con los valores que tenemos
               case 0:
                    if ( c == "+" || c=="-"){
                         aceptacion(2);
                         break;
                    }
                    else
                    if ( c == "*" || c=="/"){ 
                         aceptacion(5);
                         break;
                    }
                    else
                    if ( c == "<" || c=="<=" || c == ">" || c==">="){ 
                         aceptacion(7);
                         break;
                    }
                    else
                    if ( c == "||"){
                         aceptacion(8);
                         break;
                    }
                    else
                    if ( c == "&&"){ 
                         aceptacion(9);
                         break;
                    }
                    else
                    if ( c == "!"){ 
                         aceptacion(10);
                         break;
                    }
                    else
                    if ( c == "!=" || c == "=="){ 
                         aceptacion(11);
                         break;
                    }
                    else
                    if ( c == ";"){ 
                         aceptacion(12);
                         break;
                    }
                    else
                    if ( c == ","){ 
                         aceptacion(13);
                         break;
                    }
                    else
                    if ( c == "("){ 
                         aceptacion(14);
                         break;
                    }
                    else
                    if ( c == ")"){ 
                         aceptacion(15);
                         break;
                    }
                    else
                    if ( c == "{"){ 
                         aceptacion(16);
                         break;
                    }
                    else
                    if ( c == "}"){ 
                         aceptacion(17);
                         break;
                    }
                    else
                    if ( c == "="){ 
                         aceptacion(18);
                         break;
                    }
                    else
                    if ( c == "if" ){ 
                         aceptacion(19);
                         break;
                    }
                    else
                    if ( c == "while" ){
                         aceptacion(20);
                         break;
                    }
                    else
                    if ( c == "return" ){ 
                         aceptacion(21);
                         break;
                    }
                    else
                    if ( c == "else" ){
                         aceptacion(22);
                         break;
                    }
                    else
                    if ( c == "int" || c=="float" || c == "void" || c=="char"){ 
                         aceptacion(24);
                         break;
                    }
                    else
                    if ( c == "$" ){ 
                         aceptacion(3);
                         break;
                    }
                    for (int i=0; i < tamanio ; i++){
                         bool x = isdigit(c[i]);
                         if(x == 0)entero = false;
                         if(x == 0 && c[i] != '.')reales = false;
                         if(x == 0 && c[i] != '-')negativo = false;//
                         if(x == 0 && c[i] == '\"')cadena = true;
                    }
                    if (entero == true || negativo == true){ 
                         aceptacion(4);
                         break;
                    }
                    else
                    if (reales == true){ 
                         aceptacion(6);
                         break;
                    }

                    else
                    if (cadena == true){
                         aceptacion(23);
                         break;
                    }
                    else{
                         aceptacion(1);
                         break;
                    }
               break;                       
          }  
     }    
    //Fin del Automata
     switch (estado){
          case 1: tipo = TipoSimbolo::IDENTIFICADOR;
               break;

          case 2: tipo = TipoSimbolo::OPADIC;
               
               break; 
          case 3: tipo = TipoSimbolo::PESOS;
               
               break; 
          case 4: tipo = TipoSimbolo::ENTERO;
               break;
               
          case 5: tipo = TipoSimbolo::OPMULT;
               break;

          case 6: tipo = TipoSimbolo::REAL;
               break;

          case 7: tipo = TipoSimbolo::OPRELAC;
               break;

          case 8: tipo = TipoSimbolo::OPOR;
               break;

          case 9: tipo = TipoSimbolo::OPAND;
               break;

          case 10: tipo = TipoSimbolo::OPNOT;
               break;

          case 11: tipo = TipoSimbolo::OPASIGNACION;
               break;

          case 12: tipo = TipoSimbolo::PUNTOYCOMA;
               break;

          case 13: tipo = TipoSimbolo::COMA;
               break;

          case 14: tipo = TipoSimbolo::PARABI;
               break;

          case 15: tipo = TipoSimbolo::PARCERR;
               break;

          case 16: tipo = TipoSimbolo::CORCHABI;
               break;

          case 17: tipo = TipoSimbolo::CORCHCERR;
               break;

          case 18: tipo = TipoSimbolo::OPASIGNACION;
               break;

          case 19: tipo = TipoSimbolo::IF;
               break;

          case 20: tipo = TipoSimbolo::WHILE;
               break;

          case 21: tipo = TipoSimbolo::RETURN;
               break;

          case 22: tipo = TipoSimbolo::ELSE;
               break;

          case 23: tipo = TipoSimbolo::CADENA;
               break;

          case 24: tipo = TipoSimbolo::TIPO;
               break;

          default:                 
               tipo = TipoSimbolo::ERROR;
     }
	return tipo;
}

string Lexico::sigCaracter(){
     string palabra;
     if (terminado() || fuente[ind] == '$') return "$";
     else{
          while(fuente[ind] != ' '){
               palabra += fuente[ind];
               ind++;
          }
          if(fuente[ind] == ' '){
               ind++;
          }
          return palabra;
     }//*********************
}

void Lexico::sigEstado(int estado){
     this->estado = estado;
     simbolo += c;
}

void Lexico::aceptacion(int estado){
     sigEstado(estado);
     continua= false;
}

bool Lexico::terminado(){//fin de cadena
     return ind >= fuente.length();
}

bool Lexico::esLetra(char c){
     return isalpha(c) || c=='_';
}
     
bool Lexico::esDigito(char c){
     return isdigit(c);
}
   
bool Lexico::esEspacio(char c){
     return c== ' ' || c== '\t';        
}

/*           
void Lexico::retroceso(){
     if ( c != '$') ind--; 
          continua= false;
}*/