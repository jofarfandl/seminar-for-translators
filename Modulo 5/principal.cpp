#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iterator>

#include "lexico.h"
#include "lexico.cpp"
#include "pila.h"
#include "pila.cpp"

using namespace std;

using std::stringstream;

void lectura(string reglas[53],int tablaLR[95][46]){//leemos el archivo asi como guardamos la matris y las reglas
    int cont = 0;
    int fil = 0;
    ifstream archivo;
    string linea;
    archivo.open("compilador.lr.txt",ios::in);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,linea);
        if(cont <= 52){
            reglas[cont] = linea;//Guardamos la linea de la regla
        }
        if(cont >= 54){
            int col = 0;
            stringstream text_stream(linea);
            string item;
            while (std::getline(text_stream, item, ' ')) {
                tablaLR[fil][col] = stoi(item);
                col++;
            }
            fil++;
        }
        cont++;
    }
    archivo.close();
}


int main(int argc, char *argv[]){
    string reglas[53];
    int tablaLR[95][46];
    lectura(reglas,tablaLR);//lectura del archivo y sobreescritura de matriz y reglas

    Pila pila;//creamos el objeto pila
    ElementoPila *elemento;
    int fila, columna, accion, contador=0;
    int E, id = 3;
    int idReglas[2] = {3,2}; 
    int IonReglas[2] = {3,0};
    bool aceptacion = false;

    
    Lexico lexico("int vari ; ");

    elemento = new Terminal(2, "$");
    pila.push(elemento);
    elemento = new Estado(0);
    pila.push(elemento);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    cout << "Fila : " << fila << endl;
    cout << "Columna : " << columna << endl;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout <<"Entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;

    while(accion != -1){
        if(accion == 0){
            break;
        }
        if(accion > 0){//si la accion es mayor a 0 hacemos un desplazo
            if(accion != 4){
                elemento = new Terminal(lexico.tipo,lexico.c);
                pila.push( elemento );
                elemento = new Estado(accion);
                pila.push( elemento );
            }
            lexico.sigSimbolo();
            fila= pila.top();
            columna= lexico.tipo;
            cout << "Fila: " << fila << endl;
            cout << "Columna: " << columna << endl;
            accion= tablaLR[fila][columna];

            pila.muestra();
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl;
        }
        if(accion < 0){
            if (accion == -1){
                break;
            }
            if (accion == -3){
                contador = 0;
                E = idReglas[contador]  + IonReglas[contador];
            }
            if (accion == -2){
                contador = 1;
                E = idReglas[contador];
            }

            for(int i=0; i<E; i++){
                pila.pop();
            }

            pila.muestra();
            fila= pila.top();
            columna= 3;
            cout << "Fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            elemento = new NoTerminal(3,"E");
            pila.push( elemento );
            cout << "Entro " <<endl;
            elemento = new Estado(accion);
            pila.push( elemento );
            pila.muestra();
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl << endl;
        }
        
    }
    cout << "Automata terminado" << endl;
    aceptacion= accion == -1;
    if (aceptacion){
        cout << "ACEPTACION" << endl;
    }
    else {
        cout << "NO ACEPTACION" << endl;
    }
}