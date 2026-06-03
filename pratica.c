// Matriz com loop
#include <stdio.h>
#define LINHAS 5 // constante para configurar o número de linhas da matriz (5x5)
#define COLUNAS 5 // constante para configurar o número de colunas da matriz (5x5)
int main() {
// usar constantes para fixar valor da variável linhas e colunas da matriz
	int matriz [LINHAS][COLUNAS];
	int soma = 0; // variável para formar os elementos da matriz
	
	// laço para percorrer elementos da matriz
	for (int i = 0; i < LINHAS; i++) {
		for (int j = 0; j < COLUNAS; j++) {
			soma++; // formar elementos de 1 a 1
			matriz[i][j] = soma; // atribuir valor ao elemento da matriz
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
