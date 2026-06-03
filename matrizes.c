// Exercicios de iniciação em matrizes e vetores em C
#include <stdio.h>
#include <stdlib.h>

int main() {
     int matriz[3][3]; // Declaração de uma matriz 3x3 de inteiros
 
    // Inicialização da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = i + j; // Atribuindo valores à matriz
        }
    }
 
    // Exibindo os elementos da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }
 
    return 0;

}



// // Leia uma matriz e verifique se a soma de cada linha é par ou ímpar
//     int matriz1[3][3] = {
//         {1, 8, 7},
//         {12, 17, 22},
//         {5, 9, 13}
//     };

//     // Realizar a soma de cada linha e verificar se é par ou ímpar
//     for (int i = 0; i < 3; i++) {
//         int soma_linha = 0;
//         for (int j = 0; j < 3; j++) {
//             soma_linha += matriz1[i][j];
//         }
//         if (soma_linha % 2 == 0) {
//             printf("A soma da linha %d é par: %d\n", i + 1, soma_linha);
//         } else {
//             printf("A soma da linha %d é ímpar: %d\n", i + 1, soma_linha);
//         }
//     }
    

//    // Leia 10 inteiros e conte quantos são pares e quantos são ímpares.
//    int inteiros[10] = {5, 10, 14, 20, 25, 30, 35, 40, 48, 57};
//    int pares = 0, impares = 0;

//    // Percorrer vetor e verificar quanto são pares e ímpares
//    for(int i = 0; i < 10; i++) {
//         if (inteiros[i] % 2 == 0) { // se o número for divisível por 2, é par
//             pares++; // incrementa contador de pares
//         } else { // caso contrário, é ímpar
//             impares++; // incrementa contador de ímpares
//         }
//    }

//    // imprimir resultados
//    printf("Quantidade de números pares: %d\n", pares);
//    printf("Quantidade de números ímpares: %d\n", impares);
