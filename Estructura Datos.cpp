// Las listas?
//
#include <iostream>
//Palabra reservada
class Lista {
    //creamos nuestro atributo donde almacena los datos(un arreglo)
private:
    int arregloNumeros[5];

    //constructor o inicializador con datos
public:
    Lista() {
        arregloNumeros[0] = 6;
        arregloNumeros[1] = 98;
        arregloNumeros[2] = 3551;
        arregloNumeros[3] = 854;
        arregloNumeros[4] = 615516;
    }

    //Metodo de lectura o impresion
    void imprimirLista() const {
        std::cout << "Elementos de arreglo \n";
        for (int i = 0; i < 5; i++) {
            std::cout << arregloNumeros[i] << "\n";
        }
    }
};
int main()
{
    
    std::cout << "Lista es un arreglo\n";

  //  int arregloNumeros[5] = { 1,3,6,5,9 };
     

    //for (int i = 0; i < 5; i++) {
    //    std::cout << arregloNumeros[i] << "\n";
    //}

    Lista miLista;

    miLista.imprimirLista();

    
    return 0;
}


//// Estructura Datos.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//#include <iostream>
////Palabra reservada
//class Operaciones {
//    public: 
//        int suma(int a, int b) {
//            return a + b;
//        }
//
//        double suma(double a, double b) {
//            return a + b;
//        }
//            
//        //restar
//        //multiplicar
//        //dividir
//        //convertir en mayuscula
//        //contador de letras
//        //potencia de dos numeros ejemplo 3 ^ 9
//};
//int main()
//{
//    //Poliformismo con sobrecarga. Funcion SUMA
//    std::cout << "Operaciones!\n";
//
//    //Instancia del objeto, clase, 
//    Operaciones operador;
//
//    std::cout << operador.suma(8.1, 1.2) << std::endl; // a quien llama?
//    std::cout << operador.suma(8, 1) << std::endl; // a quien llama?
//    std::cout << operador.suma(8, 1) << std::endl; // a quien llama?
//    
//    return 0;
//}
// 
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//
