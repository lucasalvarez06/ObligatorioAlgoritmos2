#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ArrayRepetidos{
    
    public:
    int *array;
    int largo;

    ArrayRepetidos(int cant){
        array = new int[cant];
        largo = cant;
    }

    int DevolverIncognita(int cant, int min){
        if (cant != min){
            if(array[(cant/2) + 1] == array[(cant/2)]){
                return DevolverIncognita((cant/2) - 1, min);
            } else if (array[(cant/2) + 1] == array[(cant/2) + 2]){
                return DevolverIncognita(cant, (cant/2) + 3);
            } else return (array[(cant/2) + 1]);

        } else return array[cant];
    }

    ~ArrayRepetidos(){
        delete []array;
    }

    private:

};



int main(){

    //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  //ifstream myFile("Pruebas/Ejercicio6/10.in.txt");
  //cin.rdbuf(myFile.rdbuf());
  //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  //ofstream myFile2("Salidas/Ejercicio6.out.txt");
  //cout.rdbuf(myFile2.rdbuf());

    int largo;
    int elemento;
    cin >> largo;
    ArrayRepetidos arrayDado = ArrayRepetidos(largo);
    for (int i = 0; i < largo; i++){
        cin >> elemento;
        arrayDado.array[i] = elemento;
    }

    int resultado = arrayDado.DevolverIncognita(largo - 1, 0);
    cout << resultado << endl;

    arrayDado.~ArrayRepetidos();
    return 0;
}





