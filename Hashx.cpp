
#include "Nodo.cpp"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;



struct Hash
{
    NodoStrInt** arr;
    int cantElem;
    int largoArr;
};

Hash* crearHash(int largoArr){
    Hash* ret = new Hash;
    ret->largoArr = largoArr;
    ret->cantElem = 0;
    ret->arr = new NodoStrInt*[largoArr];
    for (int i = 0; i < largoArr; i++)
    {
        ret->arr[i] =NULL;
    }
    return ret;
}

int funcionDeHash(string clave,int largoArr){
    int sumaC=0;
    
	for (int i = 0;i<clave.length(); i++) {
		sumaC= 37*sumaC + clave.at(i);
	}
    return sumaC%largoArr;
}

bool existe(Hash* &h, string dato, int cubeta){
    NodoStrInt* l = h->arr[cubeta];
    while(l!=NULL){
        if(l->dato.compare(dato)==0){
            return true;
        }
        l = l->sig;
    }
    return false;
}

void insertar(Hash*& h,string dato){
    int cubeta = funcionDeHash(dato,h->largoArr);
    bool b = existe(h,dato,cubeta);
    if(!b){
        h->cantElem++;
        NodoStrInt* n = new NodoStrInt;
        n->dato = dato;
        n->sig = h->arr[cubeta];
        h->arr[cubeta] = n;
    }
    

}





