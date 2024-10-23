#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;

class ElementoPila{
   protected:
      int Valor;
   public:
      virtual void muestra(){}
      virtual void muestra2(){}
      virtual int numero(){}
};

class Terminal: public ElementoPila{
   protected:
      string literal;
   public:
      Terminal(int Valor, string literal){
         this->Valor= Valor;
         this->literal= literal;
      }  

      void muestra(){
         cout << "ElementoPila Terminal" << endl;
         cout << "Valor: " << Valor << endl;
         cout << "literal: " << literal << endl << endl;
      }
      void muestra2(){
         cout << "Ter-";
      }

      int numero(){
         return Valor;
      }
};

class NoTerminal: public ElementoPila{
   protected:
      string literal;
      //int creditos;
   public:
      NoTerminal(int Valor, string literal/*, int creditos*/){
         this->Valor= Valor;
         this->literal= literal;
         //this->creditos= creditos;
      }
      void muestra(){
         cout << "ElementoPila NoTerminal" << endl;
         cout << "Valor: " << Valor << endl;
         cout << "literal: " << literal << endl;
      }
      void muestra2(){
         cout << "NoTer-";
      }
      int numero(){
         return Valor;
      }
};

class Estado: public ElementoPila{
   public:
      Estado(int Valor){
         this->Valor = Valor;
      }
      void muestra(){
         cout << "Estado" << endl;
         cout << "Valor: " << Valor << endl;
      }
      void muestra2(){
         cout << "Est-";
      }
      int numero(){
         return Valor;
      }
};

class Pila{
   private:      
      list <ElementoPila*> lista;      
   public:      
      void push( ElementoPila* x);
      int top();
      ElementoPila* pop();
      void muestra();
};

#endif