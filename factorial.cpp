#include <stdio.h>


//factorial version iterativo
int factorial(int n) {
	
	int resultado = 1;

	if (n < 0) {
		printf("El factorial no es valido ");
		return -1;
	}	
	//iterativo
	for (int i = 2; i <= n; i++) {
		resultado *= i;
	}

	return resultado;	
}

//factorial version recursiva
int factorialrecursiva(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorialrecursiva(n - 1);
}



int main() {
	int n = 8;

	int resultado = factorial(8);
	if (resultado != -1) {
		printf("El factorial de %d:", n);
		printf("Es %d:", resultado);
	}


	int resultadofactorial = factorialrecursiva(8);
	printf("Es %d:", resultadofactorial);
}
