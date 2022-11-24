#include <iostream>
#include <assert.h>
using namespace std;
#include <string>

struct Nodo{
    int dato;
    int dato2;
    
};
typedef Nodo* nodo;

struct NodoLista{
    int dato;

    NodoLista* sig;
    NodoLista() : dato(0), sig(NULL) {}
    NodoLista(int dato) : dato(dato), sig(NULL) {}
    NodoLista(int dato, NodoLista* siguiente) : dato(dato), sig(siguiente) {}
};

struct Lista
{
    NodoLista* ppio;
    NodoLista* fin;
    

};

struct NodoStrInt
{
    string dato;
    NodoStrInt* sig;
};


void agregarNodo(Lista*& dato2,int e){
    NodoLista* nuevo = new NodoLista(e);
   
    if(dato2==NULL){
        dato2 = new Lista();
        dato2->ppio = nuevo;
        dato2->fin=nuevo;
        
    }else{
       dato2->fin->sig = nuevo;
       dato2->fin = dato2->fin->sig;
    }
        

}