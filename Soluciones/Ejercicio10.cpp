#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ArrayNumeros{
    public:
    int *array;
    int largo;

    ArrayNumeros(int cant){
        array = new int[largo];
        largo = cant;
    }

    ~ArrayNumeros(){
        delete []array;
    }

    void QuickSort(int min, int max){
        int pivot = pivot = array[ (min + max) /2 ]; 
        int auxMin = min;
        int auxMax = max;
        while (auxMin <= auxMax){
            while( (array[auxMin] < pivot) && (auxMin <= max) )
            { 
                auxMin++;
            } 
    
            while( (array[auxMax] > pivot) && (auxMax >= min) )
            { 
                auxMax--;
            } 
    
            if(auxMin <= auxMax )
            { 
                swap(auxMin, auxMax); 
                auxMin++;  auxMax--; 
            }   
        }
    
        if( min < auxMax ) QuickSort(min, auxMax); 
        if( auxMin < max ) QuickSort( auxMin, max ); 

    }

    void swap(int pos1, int pos2){
        int aux = array[pos1];
        array[pos1] = array[pos2];
        array[pos1] = aux;
    }

    int ObtenerMaxInt(){
        int retorno = 0;
        for (int i = 0; i < largo; i++){
            retorno = retorno + (array[i] * (Potencia(10, i)));
        }
        return retorno;
    }

    int Potencia(int numero, int exponente){
        if (exponente == 0) return 1;
        else return (numero * Potencia(numero, exponente - 1));
    }

    private:
};

int main(){
    //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    //ifstream myFile("Pruebas/Ejercicio10/9.in.txt");
    //cin.rdbuf(myFile.rdbuf());
    //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    //ofstream myFile2("Salidas/Ejercicio10.out.txt");
    //cout.rdbuf(myFile2.rdbuf());

    int largo;
    int elemento;
    cin >> largo;
    ArrayNumeros arrayDado = ArrayNumeros(largo);
    for (int i = 0; i < largo; i++){
        cin >> elemento;
        arrayDado.array[i] = elemento;
    }

    arrayDado.QuickSort(0,largo - 1);

    int resultado = arrayDado.ObtenerMaxInt();
    cout << resultado << endl;

    arrayDado.~ArrayNumeros();


    return 0;
}