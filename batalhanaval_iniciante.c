// Utilizar arrays em C para representar um tabuleiro simplificado e posicionar dois navios nele: um na vertical e outro na horizontal. 
// matriz (array bidimensional) de tamanho 10x10 para representar o tabuleiro do Batalha Naval
// Verificação completa de sobreposição dos navios e limites do tabuleiro antes de posicioná-los.
// Posicionamento e impressão do tabuleiro com loops aninhados for

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // declarar e inicializar tabuleiro com valor 0
    // Matriz 10 x 10 (tamanho é 10)
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Declaração dos navios
    // Navio 1 está em posição horizontal e o Navio 2 em vertical
    // Tamanho do navio é 3
    int navio1[3] = {3, 3, 3}; 
    int navio2[3] = {3, 3, 3};

    // índices para percorrer o tabuleiro e verificar as posições dos navios
    int index_horizon; // coordenada horizontal (varia coluna)
    int index_vertical; // coordenada vertical (varia linha)

    // Inicializar entrada com coordenadas escolhidas
    int linhaH = 4, colunaH = 0; // navio horizontal se posicina na linha 5 e coluna 1
    int linhaV = 5, colunaV = 1; // navio vertical se posicina na linha 6 e coluna 2

    // validar se as coordenadas e o tamanho dos navios são válidos
    // verificação do navio horizontal (se posição + tamanho do navio é maior que tamanho do tabuleiro?)
    if (colunaH + 3 > 10) {
        printf("Erro! Tamanho do navio em horizontal ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação do navio vertical (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaV + 3 > 10) {
        printf("Erro! Tamanho do navio em vertical ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação de sobreposição dos navios no tabuleiro
    // comparar as coordenadas que cada navio irá ocupar
    for (index_horizon = 0; index_horizon < 3; index_horizon++) {
        for (index_vertical = 0; index_vertical < 3; index_vertical++) {
            if (linhaH == linhaV + index_vertical && colunaH + index_horizon == colunaV) {
                printf("Erro! Os navios estão se sobrepondo!\n");
                return 1;
            }
        }
    }

    // Após verificações de limite e de sobreposição, posicionar os navios no tabuleiro
    // Posicionar navio horizontal (apenas mudar valor da coluna)
    for(index_horizon = 0; index_horizon < 3; index_horizon++) {
        tabuleiro[linhaH][colunaH + index_horizon] = navio1[index_horizon]; // atribuir valor do navio horizontal à posição correspondente no tabuleiro
    }

    // Posicionar navio vertical (apenas mudar valor da linha)
    for(index_vertical = 0; index_vertical < 3; index_vertical++) {
        tabuleiro[linhaV + index_vertical][colunaV] = navio2[index_vertical]; // atribuir valor do navio vertical à posição correspondente no tabuleiro
    }

    // Imprimir o tabuleiro para verificar a posição dos navios
    // Percorrer com dois loops aninhados para acessar cada posição do tabuleiro
    for(index_horizon = 0; index_horizon < 10; index_horizon++) {
        for(index_vertical = 0; index_vertical < 10; index_vertical++) {
            printf("%d ", tabuleiro[index_horizon][index_vertical]); // imprimir valor da posição do tabuleiro
        }
        printf("\n"); // nova linha após imprimir cada linha do tabuleiro
    }
    return 0;
}