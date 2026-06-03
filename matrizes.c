// Exercicios de iniciação em matrizes e vetores em C
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 5
// mais prática complexa de matriz com loops e condicionais
int main() {
     int matriz[LINHAS][COLUNAS]; // Declaração de uma matriz 5x5 de inteiros
     int target = 5; // Valor alvo a ser encontrado na matriz
     int soma = 1; // Variável para armazenar a soma dos elementos da matriz, iniciada com 1 para evitar multiplicação por zero
     int found = 0; // Variável de controlepara indicar se o elemento alvo foi encontrado
     // 0 para False, 1 para True
 
    // Inicialização da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = soma; // Atribuindo valores à matriz
            soma++; // Incrementa a variável soma para o próximo elemento da matriz
            printf("%d ", matriz[i][j]); // Imprime o valor atribuído
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }
 
    // Busca condicional do elemento alvo
    // Utilizamos dois loops for aninhados para percorrer todas as posições da matriz
    for (int i = 0; i < LINHAS; i++) { // Loop externo itera sobre as linhas da matriz
        for (int j = 0; j < COLUNAS; j++) { // Loop interno itera sobre as colunas da matriz
            if (matriz[i][j] == target) { // verificar se o valor do elemento atual é igual ao valor alvo (target)
                printf("Elemento %d encontrado na posição (%d, %d)\n", target, i, j); // se verdade, imprime a posição do elemento na matriz
                found = 1; // definimos a variável found como 1 (True) para indicar que o valor foi encontrado
                break; // utilizamos break para sair do loop interno
            }
        }
    // Após o break do loop interno, utilizamos outro if (found) para sair do loop externo, interrompendo a busca assim que o valor é encontrado.
        if (found) break; 
    }
 
    if (!found) { // caso elemento não seja encontrado, a variável found é atribuída com 0 (False)
        printf("Elemento %d não encontrado na matriz\n", target); // imprime mensagem ao usuário sobre a operação não sucedida.
    }

    return 0; // Encerra o programa com código de saída 0, indicando que a execução foi bem-sucedida.

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
