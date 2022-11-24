#include <iostream>
using namespace std;

struct NodoListaGrafo
{
    int vertice;
    NodoListaGrafo* sig;
};

struct Grafo
{
    NodoListaGrafo** listasDeAdyacencia;
    int cantVertices;
};

Grafo* crearGrafo(int cantVertices)
{
    Grafo* g = new Grafo;
    g->cantVertices = cantVertices;
    g->listasDeAdyacencia = new NodoListaGrafo*[cantVertices + 1];
    for (int v = 0; v <= cantVertices; v++)
    {
        g->listasDeAdyacencia[v] = NULL;
    }

    return g;
}

void agregarArista(Grafo* grafo, int origen, int destino)
{
    NodoListaGrafo* nuevo = new NodoListaGrafo;
    nuevo->vertice = destino;
    
    nuevo->sig = grafo->listasDeAdyacencia[origen];
    grafo->listasDeAdyacencia[origen] = nuevo;
}

int* devolverCantInci(Grafo* grafo){
    int* ret = new int[grafo->cantVertices+2];
    for(int j=0; j<grafo->cantVertices ; j++){
        for(int i=0; i<grafo->cantVertices ; i++){
            if(j!=i){
                while(grafo->listasDeAdyacencia[j]!=NULL){
                    if(grafo->listasDeAdyacencia[j]->vertice==i){
                    ret[i]=ret[i]+1;
                    grafo->listasDeAdyacencia[j]= grafo->listasDeAdyacencia[j]->sig;
                    }
                }
            }
        }
    }
    return ret;
}

