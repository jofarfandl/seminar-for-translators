#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

bool isNumber(char txt[]){
    bool ban = false;
    for(int i=0; i < strlen(txt); i++){
        if(!isdigit(txt[i]) && txt[i] != '-'){
            if (txt[i] != '.'){
                return false;
            }
            else{
                ban = true;
            }
        }
    }
    if(ban == true){
        cout << "\n" << txt << " Es un flotante" << endl;
        system("pause");
        return true;
    }
    cout << "\n" << txt << " Es un entero" << endl;
    system("pause");
    return true;
}

bool isString(char txt[]){
    for (int i=0; i< strlen(txt); i++){
        char actual = txt[i];
        if(actual == '"'){
            cout << "\n" << txt << " Es una cadena" << endl;
            system("pause");
            return true;
        }
    }
    cout << "\n" << txt << " Es un identificador" << endl;
    system("pause");
    return false;
}

int main(){
    char dato[15];
    bool band = true;
    while(band == true){
        system("cls");
        cout << "Escriba una cadena: "<<endl;
        cin >> dato;
        if(isNumber(dato)){
            band = true;
            continue;
        }

        if (strcmp(dato, "salir") == 0 ){
            cout << "\n" << dato << " Fin del programa" << endl;
            system("pause");
            band = false;
            continue;
        }
        
        else{
            isString(dato);
            continue;
        }

    }
    return 0;
}