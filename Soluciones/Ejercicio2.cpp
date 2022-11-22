#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Heap {
private:
	int *elementos;
	int cantElementos;
	int capacidad;

	int Padre(int pos) {
		return (pos - 1) / 2;
	}

	int HijoIzquierdo(int pos) {
		return (2 * pos + 1);
	}

	int HijoDerecho(int pos) {
		return (2 * pos + 2);
	}

	void Flotar(int pos) {
		if (pos && elementos[Padre(pos)] > elementos[pos])
		{
			swap(pos, Padre(pos));
			Flotar(Padre(pos));
		}
	}

	void Hundir(int pos) {
		int hijoIzquierdo = HijoIzquierdo(pos);
		int hijoDerecho = HijoDerecho(pos);

		if (hijoIzquierdo < cantElementos && elementos[hijoIzquierdo] < elementos[pos]) {
			swap(pos, hijoIzquierdo);
			Hundir(hijoIzquierdo);
		}

		if (hijoDerecho < cantElementos && elementos[hijoDerecho] < elementos[pos]) {
			swap(pos, hijoDerecho);
			Hundir(hijoDerecho);
		}
	}

	void swap(int pos1, int pos2){
		int aux = elementos[pos1];
		elementos[pos1] = elementos[pos2];
		elementos[pos2] = aux;
	}

public:
	Heap(int largo) {
		elementos = new int[largo];
		cantElementos = 0;
		capacidad = largo;
	}

	int Tamano() {
		return cantElementos;
	}

	int Capacidad() {
		return capacidad;
	}

	bool EsVacio() {
		return Tamano() == 0;
	}

	bool EstaLLeno() {
		return Tamano() == Capacidad();
	}

	void Insertar(int valor) {
		elementos[cantElementos] = valor;
		cantElementos++;

		Flotar(cantElementos - 1);
	}

	int ObtenerElemento(int pos) {
		return elementos[pos];
	}

	void EliminarElemento() {

		elementos[0] = ObtenerElemento(cantElementos - 1);
		cantElementos--;
		Hundir(0);
	}

	~Heap(){
		delete[] elementos;
	}
};

int main() {

  //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  //ifstream myFile("Pruebas/Ejercicio2/100000.in.txt");
  //cin.rdbuf(myFile.rdbuf());
  //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  //ofstream myFile2("Salidas/Ejercicio2.out.txt");
  //cout.rdbuf(myFile2.rdbuf());


	int largo;
	int elemento;
	cin >> largo;
	Heap heap = Heap(largo);

	for (int i = 0; i < largo; i++) {
		cin >> elemento;
		heap.Insertar(elemento);
	}

	while (heap.Tamano() > 0) {
		cout << heap.ObtenerElemento(0) << endl;
		heap.EliminarElemento();
	}
	heap.~Heap();
	return 0;
}