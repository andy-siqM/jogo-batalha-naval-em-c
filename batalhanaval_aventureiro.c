// Tabuleiro Completo e Navios Diagonais
// Movimento horizontal: linha fixa, coluna varia
// Movimento vertical: linha varia, coluna fixa
// Movimento diagonal 1 para cima/direita: linha e coluna diminuem simultaneamente
// Movimento diagonal 2 para baixo/direita: linha e coluna aumenta simultaneamente

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10 // Linhas do tabuleiro (Matriz 10x10)
#define COLUNAS 10 // Colunas do tabuleiro (Matriz 10x10)

int main() {

    // Declarar e inicializar o tabuleiro com valor 0
    int tabuleiro[LINHAS][COLUNAS] = {
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

    // Um navio diagonal ocupa posições onde a linha e a coluna aumentam ou diminuem simultaneamente
    // Declaração de 4 navios
    // Navio 1: horizontal, tamanho 3
    int navio1[3] = {3, 3, 3};
    // Navio 2: vertical, tamanho 3
    int navio2[3] = {3, 3, 3};
    // Navio 3: diagonal (para cima), tamanho 3
    int navio3[3] = {3, 3, 3};
    // Navio 4: diagonal (para baixo), tamanho 3
    int navio4[3] = {3, 3, 3};

    // índices para percorrer o tabuleiro e verificar as posições dos navios
    int index_horizon; // coordenada horizontal (varia coluna)
    int index_vertical; // coordenada vertical (varia linha)
    int index_diagonal; // coordenada diagonal (varia linha e coluna simultaneamente)

    // Inicializar entrada com coordenadas escolhidas dentro do código
    int linhaH = 0, colunaH = 0; // navio horizontal se posicina na linha 1 e coluna 1
    int linhaV = 2, colunaV = 5; // navio vertical se posicina na linha 3 e coluna 6
    int linhaD1 = 7, colunaD1 = 7; // navio diagonal para cima se posiciona na linha 8 e coluna 8
    int linhaD2 = 6, colunaD2 = 0; // navio diagonal para baixo se posiciona na linha 7 e coluna 1

    /* Pequena explicação
    Com essas posições, os navios ocupam estas casas, assim não se sobrepondo:
    Horizontal: (0,0), (0,1), (0,2)
    Vertical: (2,5), (3,5), (4,5)
    Diagonal para cima: (8,8), (7,7), (6,6)
    Diagonal para baixo: (6,0), (7,1), (8,2)
    */

    // validar se as coordenadas e o tamanho dos 4 navios são válidos
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

    // verificação do navio diagonal para cima (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaD1 + 3 > 10 || colunaD1 + 3 > 10) {
        printf("Erro! Tamanho do navio diagonal para cima ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação do navio diagonal para baixo (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaD2 + 3 > 10 || colunaD2 + 3 > 10) {
        printf("Erro! Tamanho do navio diagonal para baixo ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação de sobreposição dos navios no tabuleiro
    // comparar as coordenadas que cada navio (incluindo os diagonais) irá ocupar
    for (index_horizon = 0; index_horizon < 3; index_horizon++) {
        for (index_vertical = 0; index_vertical < 3; index_vertical++) {
            for (index_diagonal = 0; index_diagonal < 3; index_diagonal++) {
                if (linhaH == linhaV + index_vertical && colunaH + index_horizon == colunaV) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                // Verificar sobreposição entre navio horizontal e navio diagonal para cima
                } else if (linhaH == linhaD1 - index_diagonal && colunaH + index_horizon == colunaD1 - index_diagonal) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                    // Verificar sobreposição entre navio horizontal e navio diagonal para baixo
                } else if (linhaH == linhaD2 + index_diagonal && colunaH + index_horizon == colunaD2 + index_diagonal) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                }
                // Verificar sobreposição entre navio vertical e navio diagonal para cima
                else if (linhaV + index_vertical == linhaD1 - index_diagonal && colunaV == colunaD1 - index_diagonal) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                }
                // Verificar sobreposição entre navio vertical e navio diagonal para baixo
                else if (linhaV + index_vertical == linhaD2 + index_diagonal && colunaV == colunaD2 + index_diagonal) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                }
                // Verificar sobreposição entre navio diagonal para cima e navio diagonal para baixo
                else if (linhaD1 - index_diagonal == linhaD2 + index_diagonal && colunaD1 - index_diagonal == colunaD2 + index_diagonal) {
                    printf("Erro! Os navios estão se sobrepondo!\n");
                    return 1;
                }
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

    // Posicionar navio diagonal para cima (diminuir simultaneamente o valor da linha e coluna)
    for(index_diagonal = 0; index_diagonal < 3; index_diagonal++) {
        tabuleiro[linhaD1 - index_diagonal][colunaD1 - index_diagonal] = navio3[index_diagonal]; // atribuir valor do navio diagonal para cima à posição correspondente no tabuleiro
    }

    // Posicionar navio diagonal para baixo (aumentar simultaneamente o valor da linha e coluna)
    for(index_diagonal = 0; index_diagonal < 3; index_diagonal++) {
        tabuleiro[linhaD2 + index_diagonal][colunaD2 + index_diagonal] = navio4[index_diagonal]; // atribuir valor do navio diagonal para baixo à posição correspondente no tabuleiro
    }

    // Imprimir o tabuleiro para verificar a posição dos navios
    printf("Tabuleiro com navios posicionados:\n");
    for (index_horizon = 0; index_horizon < LINHAS; index_horizon++) {
        for (index_vertical = 0; index_vertical < COLUNAS; index_vertical++) {
            // imprimir valor da posição do tabuleiro (0 para águas, 3 para navio)
            printf("%d ", tabuleiro[index_horizon][index_vertical]);
        }
        printf("\n"); // espaço de formatação para linhas do tabuleiro
    }

    return 0; // Fim do programa
}