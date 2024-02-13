//Arbol en B

#include <stdio.h>
#include <iostream>
#include <vector>
 
using namespace std;

const int MGlobal = 10;//Orden del Arbol B adicional debe ser par


//   0-1-2-3
struct Node {
	vector<int> keys;//Llaves o claves para el nodo.
	//Los hijos o punteros a los hijos
	vector<Node*> children;


	Node() {
		//Orden del Arbol B- 1
		keys.reserve(MGlobal - 1);//reservar un espacio para la llave o clave
		children.reserve(MGlobal);// reserva todos los espacios del puntero para el hijo
	}

	bool isLeaf() const {
		return children.empty();//verifica que si el hijo esta vacio o sin datos
	}


};


class BTree {
	private: Node* raiz;

		   void insertarNoLLeno(Node* nodo, int clave) {
			   int cantidadelementos = nodo->keys.size() - 1;

			   //permite insertar datos si la hoja o el nodo estuviera en orden o vacio
			   if (nodo->isLeaf()) {
				   //inserta la key o llave
				   while (cantidadelementos >= 0 && clave < nodo->keys[cantidadelementos]) {
					   nodo->keys[cantidadelementos + 1] = nodo->keys[cantidadelementos];
					   cantidadelementos--;
				   }
				   nodo->keys[cantidadelementos + 1] = clave;
			   }
			   else {
				   //Encontera el hijo donde caer o insertar la llave
				   while (cantidadelementos >= 0 && clave < nodo->keys[cantidadelementos])
					   cantidadelementos--;

				   //verficamos que el dato este dentro del vector
				   if (nodo->children[cantidadelementos + 1]->children.size()  == MGlobal-1) {
					   dividirHijos(nodo, cantidadelementos + 1, nodo->children[cantidadelementos + 1]);

					   if(clave > nodo->keys[cantidadelementos+1]){
						   cantidadelementos++;
					   }
				   }

				   //recuerden que clave pueden cambiarse el tipo de dato a un array, a una clase, aun string
				   insertarNoLLeno(nodo->children[cantidadelementos + 1], clave);

			   }



			}

		   void dividirHijos(Node* padre, int indice, Node* hijo) {
			   Node* nuevoNodo = new Node();

			   nuevoNodo->keys.resize(MGlobal / 2 - 1);

			   padre->keys.insert    (padre->keys.begin() + indice, hijo->keys[MGlobal / 2 - 1]);
			   //======
			   nuevoNodo->keys.assign(hijo->keys.begin() + MGlobal / 2, hijo->keys.end());

			   hijo->keys.resize(MGlobal / 2 - 1);

			   //permite insertar si tiene campo
			   if (!hijo->isLeaf()) {
				   nuevoNodo->children.assign(hijo->children.begin() + MGlobal / 2, hijo->children.end());
				   hijo->children.resize(MGlobal / 2);
			   }

			   padre->children.insert(padre->children.begin() + indice + 1, nuevoNodo);

		   }


	public: BTree() : raiz(nullptr){}


		  //ingresa o inserta datos claves
		  void insertar(int clave) {
			  if (raiz == nullptr) {
				  raiz = new Node();
				  raiz->keys.push_back(clave);
			  }
			  else {
				  if (raiz->keys.size() == MGlobal - 1) {
					  Node* nuevoNodo = new Node();
					  nuevoNodo->children.push_back(raiz);
					  raiz = nuevoNodo;
					  dividirHijos(raiz, 0, raiz->children[0]);
				  }
				  insertarNoLLeno(raiz, clave);
			  }
		  }


		  void mostrar(Node* nodo) {
			  if (nodo != nullptr) {
				  for (int i = 0; i < nodo->keys.size(); ++i) {
					  cout << nodo->keys[i] << " --- ";
				  }
				  cout << endl;

				  for (int i = 0; i < nodo->children.size(); ++i) {
					  cout << nodo->children[i] << " --- ";
				  }


			  }
		  }


		  void mostrar() {
			  mostrar(raiz);
		  }
};

int main() {
	BTree ArbolB;

	ArbolB.insertar(10);
	ArbolB.insertar(111);
	ArbolB.insertar(22);
	ArbolB.insertar(33);
	ArbolB.insertar(4);
	ArbolB.insertar(8);

	ArbolB.insertar(45);
	ArbolB.insertar(65);
	ArbolB.insertar(11);
	ArbolB.insertar(77);
	ArbolB.insertar(89);
	ArbolB.insertar(98);
	ArbolB.insertar(1);

	cout << "Arbol B \n";

	ArbolB.mostrar();

	return 0;



}
