#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

struct _cabezalPilaInt; 
typedef struct _cabezalPilaInt* PilaInt;

using namespace std;
struct NodoListaInt {
	public:
		int dato;
		NodoListaInt *sig;
		NodoListaInt() : dato(0), sig(NULL) {}
		NodoListaInt(int d) : dato(d), sig(NULL) {}
	};

	
	struct PilaInt {
		NodoListaInt* tope;
		int largo;
		int suma;
	
		
	PilaInt* crearPilaInt() {
		PilaInt* pila = new PilaInt;
		pila->tope = NULL;
		pila->largo = 0;
		pila->suma = 0;
		return pila;
	}

	void push(PilaInt*& p, int e) {
		NodoListaInt* cabeza = new NodoListaInt;
		cabeza->dato = e;
		cabeza->sig = p->tope;
		p->tope = cabeza;
		p->largo++;
		p->suma = p->suma + e;
	}    

	void pop(PilaInt*& p) {
		NodoListaInt* aBorrar = p->tope;
		p->tope = p->tope->sig;
		delete aBorrar;
		p->largo--;
	}

	int SUMA(PilaInt* p){
		return p->suma; }

	int top(PilaInt* p) {
	return p->tope->dato;
	}
	int restTopReturnSum(PilaInt*& p){
				p->suma = p->suma + p->tope->dato;
				pop(p);
	}
};


int main() {

  //// IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
  //ifstream myFile("Pruebas/Ejercicio2/100000.in.txt");
  //cin.rdbuf(myFile.rdbuf());
  //Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
  //ofstream myFile2("Salidas/Ejercicio2.out.txt");
  //cout.rdbuf(myFile2.rdbuf());

	//cargo la pila

	int largo;
	int elemento;
	cin >> largo;
	PilaInt* pila1 = crearPilaInt(); 
	for (int i = 0; i < largo; i++) {
		cin >> elemento;
		pila1.push(elemento);
	}
	cin >> largo;
	PilaInt* pila2 = crearPilaInt(); 
	for (int i = 0; i < largo; i++) {
		cin >> elemento;
		pila2.push(elemento);
	}
	cin >> largo;
	PilaInt* pila3 = crearPilaInt(); 
	for (int i = 0; i < largo; i++) {
		cin >> elemento;
		pila3.push(elemento);
	}
	int min =0;
	
	int* arraySuma = new int[3];
		
	int nuevo;
	while(!(arraySuma[1]==arraySuma[2]==arraySuma[3])) {
		//CARGO MIN
		if(SUMA(pila1)<SUMA(pila2) && SUMA(pila1)<SUMA(pila3)){
		min = top(pila1);
		}
		if(SUMA(pila2)<SUMA(pila1) && SUMA(pila2)<SUMA(pila3)){
			min = top(pila2);
		}
		if(SUMA(pila3)<SUMA(pila2) && SUMA(pila3)<SUMA(pila1)){
			min = top(pila3);
		}
		//ASIGNO VALOR SUMA A ARRAY
		arraySuma[1]=top(pila1);
		arraySuma[2]=top(pila2);
		arraySuma[3]=top(pila3);

		if(SUMA(pila1)>SUMA(pila2) && SUMA(pila1)>SUMA(pila3)){
			//resto hasta q sea menorigual q el min
			while(SUMA(pila1)<=min){
			nuevo=restTopReturnSum(pila1);
			arraySuma[1]=top(nuevo);
			}
			if(SUMA(pila1)<=min){
				min=SUMA(pila1);
			}
		}
		if(SUMA(pila2)>SUMA(pila1) && SUMA(pila2)>SUMA(pila3)){
			//resto hasta q sea menorigual q el min
			while(SUMA(pila2)<=min){
			nuevo=restTopReturnSum(pila2);
			arraySuma[2]=top(nuevo);
			}
			if(SUMA(pila2)<=min){
				min=SUMA(pila2);
			}
		}
		if(SUMA(pila3)>SUMA(pila2) && SUMA(pila3)>SUMA(pila1)){
			//resto hasta q sea menorigual q el min
			while(SUMA(pila3)<=min){
			nuevo=restTopReturnSum(pila2);
			arraySuma[3]=top(nuevo);
			}
			if(SUMA(pila3)<=min){
				min=SUMA(pila3);
			}
		}
		cout<<min;
	}

	} 
  

  /*Greedy (conjunto de candidatos C): solución S
{}
<

>


S = Ø

while (S no sea una solución y C ≠ Ø) {

x = selección(C)

C = C – {x}

if (S∪{x} es factible)

S = S∪{x}

}

if (S es una solución)

return S;

else

return “No se encontró una solución”*/