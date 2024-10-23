#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "lexico.cpp"
#include "pila.h"
#include "pila.cpp"

using namespace std;

int tablaLR[5][4]={
    2, 0, 0, 1,
    0, 0, -1, 0,
    0, 3, -2, 0,
    2, 0, 0, 4,
    0, 0, -3, 0
};

int main(int argc, char *argv[]){
    Pila pila;//creamos el objeto pila
    int fila, columna, accion, contador=0;
    int E, id = 3;
    int idReglas[2] = {3,2}; 
    int IonReglas[2] = {3,0};
    bool aceptacion = false;

    ElementoPila *elemento;
    Lexico lexico("a + b + c + d + e + f");

    elemento = new Terminal(2, "$");
    pila.push(elemento);
    elemento = new Estado(0);
    pila.push(elemento);
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    cout << "fila : " << fila << endl;
    cout << "columna : " << columna << endl;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout <<"entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    while(accion != -1){//mientras la accion sea diferente de aceptacion repetimos el proceso
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
            cout << "fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl;
        }
        if(accion < 0){//Si la accion es menor a 0 hacemos una reduccion
            if (accion == -1){
                break;//si es -1 es aceptacion
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
            cout << "fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            elemento = new NoTerminal(3,"E");
            pila.push( elemento );
            cout << "entro " <<endl;
            elemento = new Estado(accion);
            pila.push( elemento );
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
        }
        
    }
    cout << "Automata terminado" << endl;
    aceptacion= accion == -1;
    if (aceptacion){
        cout << "aceptacion" << endl;
    }
    else {
        cout << "No aceptacion" << endl;
    }
}