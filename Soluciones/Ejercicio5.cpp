#include "GrafoDirSinPon.cpp"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
// vertice y aristas
int main(){

    int vertices;
    cin >> vertices;

    Grafo* graf = crearGrafo(vertices);
    int cantAr;
    cin >> cantAr;
    int vDesde;
    int vHasta;
    for(int i=0; i<cantAr ; i++){
    cin >> vDesde;
    cin >> vHasta;
    agregarArista( graf, vDesde, vHasta);
    }
    int* cantInc = devolverCantInci(graf);
    
    for(int i=0;i<cantAr ; i++){
        cout << i;
        cout << cantInc[i] << endl;
    }
      
}

