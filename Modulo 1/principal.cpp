#include <cstdlib>
#include <iostream>
#include <string>
#include "lexico.h"
#include "lexico.cpp"
#include "pila.h"
#include "pila.cpp"

using namespace std;

int tablaLR[3][3]{
    2,0,1,
    0,-1,0,
    0,-2,0
};

int main(int argc, char *argv[]){
    Pila pila;//creamos el objeto pila
    int fila, columna, accion;
    bool aceptacion = false;

    Lexico lexico("a");

    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    //El primer paso del analisis es encontrar la accion a realizar eso se consigue con:
    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    //Finalmente mostraremos el contenido de la pila, la entrada actual y la accion que se va a realizar
    pila.muestra();
    cout <<"entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;
    
    /*Dado que el valor de la accuon es un numero positivo (3)
        entonces se debe realizar un desplazamiento. Lo que implica
        meter el simbolo actual a la pila, ademas del numero 3 y pedir un siguiente simbolo*/

    pila.push(lexico.tipo);
    pila.push(accion);
    lexico.sigSimbolo();

    /*Ahora volvemos a calcular la siguiente accion utilizando el tope de la pila y la entrada ,
    como fila y columna respectivamente*/
    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " <<lexico.simbolo << endl;
    cout << "accion: " <<accion << endl; 
    return 0;
}
