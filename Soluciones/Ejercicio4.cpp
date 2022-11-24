#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#define INF 9999
using namespace std;

class Grafo{

    public:
        Grafo(int tope){
            cantElementos = 0;
            largo = tope;           
            vertices = new int[tope];
            matAdy = new int*[tope];
            for (int i = 0; i < tope; i++){
                matAdy[i] = new int[tope];
                for (int j = 0; j < tope; j++)
                    matAdy[i][j] = 0;
            } 
            ExistenVertices = new bool[tope]; 
            for (int i = 0; i < tope; i++) ExistenVertices[i] = false;         
        }

        ~Grafo(){
            for (int i = 0; i < largo; i++){
                delete[] matAdy[i];
            }
            delete []matAdy;
            delete []ExistenVertices;
            delete []vertices;
        }

        void insertarVertice(int v){
            int i = 0;
            for(i; i < largo && ExistenVertices[i]; i++);
            vertices[i] = v;
            ExistenVertices[i] = true;
            cantElementos++;
        }

        void insertarArista(int o, int d){
            //validar que exista origen y destino
            int posO = EncontrarVertice(o);
            int posD = EncontrarVertice(d);
            if(posO == -1){
                insertarVertice(o);
                posO = EncontrarVertice(o);
            }
            if(posO == -1){
                insertarVertice(d);
                posD = EncontrarVertice(d);
            }
            matAdy[posO][posD] = 1;          
        }

        bool EsTriconexo(){
            bool retorno = true;
            for (int i = 0; i < largo && retorno; i++){
                for (int j = 0; j < largo && retorno; j++){
                    if (i != j){
                        bool* visitados = InicializarVisitados(i,j);
                        int z = 0;
                        for (z; z != j && z != i; z++);
                        if (!EsConexoDFS(z, visitados)) retorno = false;
                        delete []visitados;
                    }
                }
            }
            return retorno;
        }
        void Imprimir(){
            for (int i = 0; i < largo; i++){
                cout << vertices[i] << endl;
            }
            for (int i = 0; i < largo; i++){
                for (int j = 0; j < largo; j++)
                    cout << matAdy[i][j] << endl;
            }    
        }

    private:

        int* vertices;
        bool* ExistenVertices;
        int largo;
        int cantElementos;
        int** matAdy;

        bool EsConexoDFS(int pos, bool*& visitados){
            dfs(pos,visitados);
            for (int i = 0; i < largo; i++){
                if (visitados[i] == false) return false;
            }
            return true;    
        }
        
        bool* InicializarVisitados(int pos1, int pos2){
            bool* retorno = new bool[largo];
            for (int i = 0; i < largo; i++){
                if (i == pos1 || i == pos2) retorno[i] = true;
                else retorno[i] = false;
            }
            return retorno;
        }

        void dfs(int o,bool*& vis){
            vis[o] = true;
            for (int i = 0; i < largo; i++)
                if(!vis[i] && matAdy[o][i] == 1)
                    dfs(i,vis);
        }

        int EncontrarVertice(int v){
            for (int i = 0; i < largo; i++)
            {
                if(vertices[i] == v && ExistenVertices[i]){
                    return i;
                }
            }
            return -1;
        }
};

int main(){

  //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  ifstream myFile("Pruebas/Ejercicio4/100.in.txt");
  cin.rdbuf(myFile.rdbuf());
  //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  ofstream myFile2("Salidas/Ejercicio4.out.txt");
  cout.rdbuf(myFile2.rdbuf());

    int largo;
    cin >> largo;
    Grafo grafo = Grafo(largo);
    int cantAristas;
    cin >> cantAristas;
    int a1,a2;
    for (int i = 0; i < cantAristas; i++){
        cin >> a1;
        cin >> a2;
        grafo.insertarArista(a1,a2);
    }

    if(grafo.EsTriconexo()){
        cout << 1 << endl;
    }else {
        cout << 0 << endl;
    }

}