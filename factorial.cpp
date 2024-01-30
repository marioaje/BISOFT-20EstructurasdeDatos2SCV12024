
#include <stdio.h>


//factorial version iterativo
int factorial(int n) {
	
	int resultado = 1;

	if (n < 0) {
		printf("El factorial no es valido ");
		return -1;
	}
	
	
	for (int i = 2; i <= n; i++) {
		resultado *= i;
	}

	return resultado;

	
}

int main() {
	int n = 8;

	int resultado = factorial(8);
	if (resultado != -1) {
		printf("El factorial de:", n);
		printf("Es:", resultado);
	}

}
