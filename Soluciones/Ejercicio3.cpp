#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define INITIAL_VERTICES 5
#define INF 999

 struct Grafo {
    int** adjacencyMatrix;
    unsigned int vertices;
 };


void createMatrix (Grafo* &graph, int count){

  int** dist = new int*[count];
  for (unsigned int i = 0; i < count; i++) {
    dist[i] = new int[count];
    for (unsigned int k = 0; k < count; k++) {
        dist[i][k] = INF;
    }
  }
   graph->adjacencyMatrix = dist;
}

void addEdge (Grafo* &graph, int v1, int v2, int weight){
  graph->adjacencyMatrix[v1-1][v2-1]= weight;
}

void deleteVertex (Grafo* &graph, int v1){
  for(unsigned int i=0; i<graph->vertices; i++){
        graph->adjacencyMatrix[i][v1-1] = 0;
        graph->adjacencyMatrix[v1-1][i] = 0;
    }
}

 int main(){
  //cargo matriz 
  unsigned int count;
  cin >> count;
  Grafo *graph = new Grafo();
  graph->vertices = count;
  createMatrix(graph, count);

  unsigned int edgeCount;
  cin >> edgeCount;

  for(unsigned int i=0; i<edgeCount; i++){
    int v1;
    int v2;
    int w;
    cin >> v1;
    cin >> v2;
    cin >> w;
    addEdge(graph,v1,v2,w);
  }
    // elimino fila y col de losV
    int verticeIgnorado;
    for (int i = 0; i < graph->vertices; i++) { 
      cin >> verticeIgnorado;
      deleteVertex(graph,verticeIgnorado);
    }
    //aplico arbol de cubrimiento minimo  Kruskal's 
  ColaPrioridadExtendida* cp = crearHeap(edgeCount);
  Nodo* l = new Nodo();
    l->vertice=origen;
    l->costo=0;
}

/*
