#include <stdio.h>


//fibonacci version iterativa
void fibonnaci(int n) {
	int a = 0, b = 1, siguienteTermino;

	printf("Secuencia de fibbonancci \n");

	for (int i = 0; i < n; i++) {
		printf("%d ", a);
		siguienteTermino = a + b;
		a = b;
		b = siguienteTermino;
	}

	printf("\n");


}

//version recursiva
int fibonnacirecursiva(int n) {
	if (n <= 1)
		return n;
	else
		return fibonnacirecursiva(n - 1) + fibonnacirecursiva(n - 2);
}

int main() {
	int n = 8;
	fibonnaci(n);


	printf("Secuencia de fibbonancci recursiva \n");
	for (int i = 0; i < n; i++) {
		printf("\n %d", fibonnacirecursiva(i));
	}
	
}
