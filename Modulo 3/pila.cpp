#include "pila.h"
#include <sstream>


void Pila::push(ElementoPila *x){
   lista.push_front(x);
}
       
ElementoPila*  Pila::pop(){
   ElementoPila* x= *lista.begin();
   lista.erase ( lista.begin() );
   return x;
}

int Pila::top(){
   int nuevo;
   ElementoPila *x = *lista.begin();
   nuevo = x->numero();
   return nuevo;     
}
  
void Pila::muestra(){
   list <ElementoPila*>::reverse_iterator  it;
   ElementoPila *x;
   cout << "Pila: ";   
   for (it= lista.rbegin(); it != lista.rend(); it++){
      x = *it;
      x->muestra2();
      //cout << (*it) << " ";         
   }
   cout << endl;
}