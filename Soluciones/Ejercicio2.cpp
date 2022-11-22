#include <iostream>

class Heap {
private:
	int elementos[];
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
		if (pos && elementos[Padre(i)] > elementos[pos])
		{
			swap(elementos[pos], elementos[Padre(pos)]);
			Flotar(Padre(pos));
		}
	}

	void Hundir(int pos) {
		int hijoIzquierdo = HijoIzquierdo(pos);
		int hijoDerecho = HijoDerecho(pos);

		if (hijoIzquierdo < cantElementos && elementos[hijoIzquierdo] < elementos[pos]) {
			swap(elementos[pos], elemetos[hijoIzquierdo]);
			Hundir(hijoIzquierdo);
		}

		if (hijoDerecho < cantElementos && elementos[hijoDerecho] < elementos[pos]) {
			swap(elementos[pos], elementos[hijoDerecho]);
			Hundir(hijoDerecho);
		}
	}

public:
	Heap(int largo) {
		elementos = new int[largo];
		cantElementos = 0;
		capacidad = largo;
	}

	int Tamaño() {
		return cantElementos;
	}

	int Capacidad() {
		return capacidad;
	}

	bool EsVacio() {
		return Tamaño() == 0;
	}

	bool EstaLLeno() {
		return Tamaño() == Capacidad();
	}

	void Insertar(valor) {
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
};

void main() {
	int largo;
	int elemento;
	cin >> largo;
	Heap heap = new Heap(largo);

	for (int i = 0; i <= largo; i++) {
		cin >> elemento;
		heap.Insertar(elemento);
	}

	while (heap.Tamaño() > 0) {
		cout << heap.ObtenerElemento(0);
		heap.EliminarElemento(0);
	}
}