//Arbol Balancedado c++
#include <stdio.h>
#include <iostream>
using namespace std;

//Estructura del arbol
struct Nodo
{
	int dato;

	Nodo* izquierda;
	Nodo* derecha;

	int altura;
};

//funcion de altura del arbol
int obtenerAltura(Nodo* nodo) {
	if (nodo == nullptr) {
		return 0;
	}

	return nodo->altura;
}

//funcion obtener el maximo de enteros
int maximo(int a, int b) {
	return (a > b) ? a : b;
}

//funcion crear nodo
Nodo* crearNodo(int dato) {
	Nodo* nodo = new Nodo();
	nodo->dato = dato;
	nodo->izquierda = nullptr;
	nodo->derecha = nullptr;
	nodo->altura = 1;//cada vez que cree uno nuevo
	return nodo;
}

//--->  ->>>> ->>>
// <----- -----> el nodo se va a mover e ir actualizando las alturas y datos
//rotar al mayor
Nodo* rotarDerecha(Nodo* nodo) {
	Nodo* temp = nodo->izquierda;
	Nodo* temp2 = nodo->derecha;

	//proceso de rotar los datos
	temp->derecha = nodo;
	nodo->izquierda = temp2;

	//actualizar la altura con base a los datos anteriors
	nodo->altura = maximo(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;
	temp->altura = maximo(obtenerAltura(temp->izquierda), obtenerAltura(temp->derecha)) + 1;

	//Devuelv
	return temp;
}
//rotar al menor
Nodo* rotarIzquierda(Nodo* nodo) {
	Nodo* temp = nodo->derecha;
	Nodo* temp2 = nodo->izquierda;

	//proceso de rotar los datos
	temp->izquierda = nodo;
	nodo->derecha = temp2;

	//actualizar la altura con base a los datos anteriors
	nodo->altura = maximo(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;
	temp->altura = maximo(obtenerAltura(temp->izquierda), obtenerAltura(temp->derecha)) + 1;

	//Devuelv
	return temp;
}

//funcion del balanceo
int obtenerBalance(Nodo* nodo) {
	if (nodo == nullptr) {
		return 0;
	}

	return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}


//Funcion de insertar los datos en el arbol
Nodo* insertarNodo(Nodo* nodo, int dato) {

	//	if (raiz == NULL) {
	//		return crearNodo(dato);
	//	}
	// /actualizacion de codigo
	if (nodo == nullptr) {
		return crearNodo(dato);
	}	 
	//
	//	if (dato < raiz->dato) {
	//		raiz->izquierda = insertar(raiz->izquierda, dato);
	//	}
	// actualizacion de codigo
	
	if (dato < nodo->dato) {
		nodo->izquierda = insertarNodo(nodo->izquierda, dato);
	}
	//	else if (dato > raiz->dato) {
	//		raiz->derecha = insertar(raiz->derecha, dato);
	//	}
	//actualizacion de codigo
	else if (dato > nodo->dato) {
		nodo->derecha = insertarNodo(nodo->derecha, dato);
	}
	else {
		//datos duplicados cualquier funcion para simplificar
		return nodo;
	}

	//funcion de altura
	nodo->altura = 1 + maximo(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

	///mandamos a calcular el balanceo
	int balance = obtenerBalance(nodo);

	//que el brazo menor o izquierdo esta desbalanceado
	if (balance > 1 && dato < nodo->izquierda->dato) {
		//envias los datos para que se balancee hacia el lado derecho o lado mayor
		return rotarDerecha(nodo);
	}

	//que el brazo mayor o derecha esta desbalanceado
	if (balance < -1 && dato > nodo->derecha->dato) {
		//envias los datos para que se balancee hacia el lado derecho o lado mayor
		return rotarIzquierda(nodo);
	}

	//caso que en el menor-mayor o izquierda-derecha este desequilibrado
	if (balance > 1 && dato > nodo->izquierda->dato) {
		nodo->izquierda = rotarIzquierda(nodo->izquierda);
		return rotarDerecha(nodo);
	}

	//caso que en el mayor-menor o derecha-izquierda este desequilibrado
	if (balance < -1 && dato < nodo->derecha->dato) {
		nodo->derecha = rotarDerecha(nodo->derecha);
		return rotarIzquierda(nodo);
	}

	//devuelve el nodo
	return nodo;

}

void recorridoInOrden(Nodo* nodo) {
	if (nodo != nullptr) {
		//menor
		recorridoInOrden(nodo->izquierda);
		cout << nodo->dato << " ";
		//mayor
		recorridoInOrden(nodo->derecha);
	}
}


int main() {
	Nodo* raiz = nullptr;

	raiz = insertarNodo(raiz, 25);
	raiz = insertarNodo(raiz, 18);
	raiz = insertarNodo(raiz, 12);
	raiz = insertarNodo(raiz, 8);
	raiz = insertarNodo(raiz, 3);
	raiz = insertarNodo(raiz, 10);

	cout << "arbol balanceado";

	recorridoInOrden(raiz);

	cout << endl;

	return 0;

}
