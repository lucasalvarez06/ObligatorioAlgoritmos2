#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


struct MatrizGrafo {
    private:
        int **matriz;
        int largo;
    public:
        MatrizGrafo(int cant){
            largo = cant;
            matriz = new int[cant][cant];
            for (int i = 0; i < cant;i++){
                for(int j = 0; j < cant; j++){
                    matriz[i][j] = 0;
                }
            }
        }

        void InsertarArista(int a1, int a2){
            matriz[a1 - 1][a2 - 1] = 1;
            matriz[a2 - 1][a1 - 1] = 1;
        }

        void EliminarArista(int a1, int a2){
            matriz[a1 - 1][a2 - 1] = 1;
            matriz[a2 - 1][a1 - 1] = 1;
        }

        

}

int main(){

  //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  //ifstream myFile("Pruebas/Ejercicio2/100000.in.txt");
  //cin.rdbuf(myFile.rdbuf());
  //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  //ofstream myFile2("Salidas/Ejercicio2.out.txt");
  //cout.rdbuf(myFile2.rdbuf());

    int largo;
    cin >> largo;
    MatrizGrafo matriz = MatrizGrafo(largo);

    int cantAristas;
    int a1,a2;
    cin >> cantAristas;
    for (int i = 0; i < cantAristas; i++){
        cin >> a1;
        cin >> a2;
        matriz.InsertarArista(a1,a2);
    }

}