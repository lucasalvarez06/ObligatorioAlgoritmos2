#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Conjunto {
    public:
        int* numeros;
        int largo;
        Conjunto(int cant){
            largo = cant;
            numeros = new int[cant];
        }
        ~Conjunto(){
            delete []numeros;
        }

        void Ordenar(){
            for (int i = 0; i < largo; i++) {
                for (int j = i; j < largo; j++) {
                    if(numeros[j] > numeros[i]){
                        int aux = numeros[i];
                        numeros[i] = numeros[j];
                        numeros[j] = aux;
                    }
                }      
            }
        }

        bool SeObtieneNumero(int num){
            Ordenar();
            int i = 0;
            while(i <  largo && num > 0){
                while(num > 0 && num - numeros[i] >= 0){
                    num -= numeros[i];
                }
                i++;
            } 
            return (num == 0);
        }

    private:
    

};

int main(){

    //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    //ifstream myFile("Pruebas/Ejercicio8/10.in.txt");
    //cin.rdbuf(myFile.rdbuf());
    //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    //ofstream myFile2("Salidas/Ejercicio8.out.txt");
    //cout.rdbuf(myFile2.rdbuf());
    
    int largo;
    cin >> largo;
    Conjunto conjunto = Conjunto(largo);
    for (int i = 0; i < largo; i++)
    {
        cin >> conjunto.numeros[i];
    }
    int cota;
    cin >> cota;

    int cantCasos;
    cin >> cantCasos;
    int numero;
    bool retorno;
    for (int i = 0; i < cantCasos; i++)
    {
        cin >> numero;
        retorno = conjunto.SeObtieneNumero(numero);
        if(retorno) cout << 1 << endl;
        else cout << 0 << endl;
      
    }
    
    conjunto.~Conjunto();
    return 0;
}