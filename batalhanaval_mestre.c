// Jogo Batalha Naval com matriz 10x10 
// Adição de lógica para implementar habilidades especiais com áreas de efeito distintas
// Cada habilidade é armazenada em uma matriz separada, representando apenas a visualização da área de efeito da habilidade no tabuleiro.
// 1. Cone: Uma matriz que represente uma área em forma de cone, com o ponto de origem no topo e expandindo-se em direção à base.
// 2. Cruz: Uma matriz que represente uma área em forma de cruz, com o ponto de origem no centro. 
// 3. Octaedro: Uma matriz que represente a vista frontal de um octaedro (igual a um losango, com o ponto de origem no centro e expandindo-se igualmente em todas as direções).
// 4. As matrizes de habilidade devem indicar quais posições são afetadas pela habilidade com o valor 1, e quais não são afetadas com o valor 0. 
// Tamanho razoável para as matrizes de habilidade: 5x5

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10 // Linhas do tabuleiro (Matriz 10x10)
#define COLUNAS 10 // Colunas do tabuleiro (Matriz 10x10)
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)
#define TAM_NAVIO 3 // Tamanho dos navios (3 posições)

 // Declarar funções para inicializar 3 matrizes de habilidade (cone, cruz e octaedro)
 // Posições afetadas pela habilidade: 1, não-afetadas: 0 

 // Criando a função para inicializar a matriz de habilidade do cone
 // Cone: ponto de origem no topo, expandindo-se em direção à base
 // Movimento: (0,2), (1,1), (1,2), (1,3), (2,0), (2,1), (2,2), (2,3), (2,4)
 void criarCone(int habilidade_cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 0 && j == 2) { // Ponto de origem do cone (topo)
                habilidade_cone[i][j] = 1; // área afetada
            } else if (i == 1 && (j >= 1 && j <= 3)) { // Segunda linha do cone
                habilidade_cone[i][j] = 1; // área afetada
            } else if (i == 2 && (j >= 0 && j <= 4)) { // Terceira linha do cone
                habilidade_cone[i][j] = 1; // área afetada
            } else {
                habilidade_cone[i][j] = 0; // Não afetado
            }
        }
    }
}

 // Criando a função para inicializar a matriz de habilidade da cruz
 // Cruz: ponto de origem no centro, expandindo-se em forma de cruz pela matriz
 // Movimento: (0,2), (1,2), (2,0), (2,1), (2,2), (2,3), (2,4), (3,2), (4,2)
 void criarCruz(int habilidade_cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) { // Linhas e colunas centrais formam a cruz
                habilidade_cruz[i][j] = 1; // área afetada
            } else {
                habilidade_cruz[i][j] = 0; // Não afetado
            }
        }
    }
 }

 // Criando a função para inicializar a matriz de habilidade do octaedro
 // Octaedro: ponto de origem no centro, expandindo-se igualmente em todas as direções
 // Movimento: (2,2), (1,1), (1,2), (1,3), (0,2)
 void criarOctaedro(int habilidade_octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
   // Desenho em forma de losango: posições cuja soma das distâncias
   // (Manhattan) ao centro (2,2) é menor ou igual a 2 serão afetadas.
   for (int i = 0; i < TAM_HABILIDADE; i++) {
       for (int j = 0; j < TAM_HABILIDADE; j++) {
           int dist = abs(i - 2) + abs(j - 2); // retorna a soma das distâncias (Manhattan) do ponto (i,j) ao centro (2,2)
           if (dist <= 2) { // Verificar se a posição está dentro do losango definido pela distância Manhattan
               habilidade_octaedro[i][j] = 1; // área afetada (losango)
           } else {
               habilidade_octaedro[i][j] = 0; // Não afetado
           }
       }
   }
 }

 // Verificar se posição das habilidades está dentro dos limites do tabuleiro
int dentroLimite(int linha, int coluna) {
    return (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS);
}

int main(void) {
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Declaração de uma matriz 10x10 de inteiros com valor inicial 0 (representando água)
    int habilidade_cone[TAM_HABILIDADE][TAM_HABILIDADE]; // Matriz para a habilidade do cone
    int habilidade_cruz[TAM_HABILIDADE][TAM_HABILIDADE]; // Matriz para a habilidade da cruz
    int habilidade_octaedro[TAM_HABILIDADE][TAM_HABILIDADE]; // Matriz para a habilidade do octaedro

    // Inicializando as 3 matrizes de habilidade
    criarCone(habilidade_cone);
    criarCruz(habilidade_cruz);
    criarOctaedro(habilidade_octaedro);

// Parte de criação e inicialização dos navios e posicionamento no tabuleiro
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

    // Inicializar entrada com coordenadas escolhidas dentro do código
    int linhaH = 0, colunaH = 0; // navio horizontal se posicina na linha 1 e coluna 1
    int linhaV = 2, colunaV = 5; // navio vertical se posicina na linha 3 e coluna 6
    int linhaD1 = 7, colunaD1 = 7; // navio diagonal para cima se posiciona na linha 8 e coluna 8
    int linhaD2 = 6, colunaD2 = 0; // navio diagonal para baixo se posiciona na linha 7 e coluna 1

    // validar se as coordenadas e o tamanho dos 4 navios são válidos
    // verificação do navio horizontal (se posição + tamanho do navio é maior que tamanho do tabuleiro?)
    if (colunaH + TAM_NAVIO > COLUNAS) {
        printf("Erro! Tamanho do navio em horizontal ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação do navio vertical (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaV + TAM_NAVIO > LINHAS) {
        printf("Erro! Tamanho do navio em vertical ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação do navio diagonal para cima (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaD1 - (TAM_NAVIO - 1) < 0 || colunaD1 - (TAM_NAVIO - 1) < 0) {
        printf("Erro! Tamanho do navio diagonal para cima ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação do navio diagonal para baixo (se posição + tamanho > tamanho do tabuleiro?)
    if (linhaD2 + (TAM_NAVIO - 1) >= LINHAS || colunaD2 + (TAM_NAVIO - 1) >= COLUNAS) {
        printf("Erro! Tamanho do navio diagonal para baixo ultrapassa limite do tabuleiro!\n");
        return 1; // informar erro e encerrar programa
    }

    // verificação de sobreposição dos navios no tabuleiro
    // comparar as coordenadas que cada navio (incluindo os diagonais) irá ocupar
    for (int k = 0; k < TAM_NAVIO; k++) {
            if (tabuleiro[linhaH][colunaH + k] !=0 || // Verificar sobreposição do navio horizontal
                tabuleiro[linhaV + k][colunaV] !=0 || // Verificar sobreposição do navio vertical
                tabuleiro[linhaD1 - k][colunaD1 - k] !=0 || // Verificar sobreposição do navio diagonal para cima
                tabuleiro[linhaD2 + k][colunaD2 + k] !=0) { // Verificar sobreposição do navio diagonal para baixo
                printf("Erro! Os navios estão se sobrepondo!\n");
                return 1; // informar erro e encerrar programa
            }
    
    }

    // Posicionar os navios no tabuleiro após as verificações de limite e sobreposição
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[linhaH][colunaH + k] = navio1[k]; // Posicionar navio horizontal 
        tabuleiro[linhaV + k][colunaV] = navio2[k]; // Posicionar navio vertical
        tabuleiro[linhaD1 - k][colunaD1 - k] = navio3[k]; // Posicionar navio diagonal para cima
        tabuleiro[linhaD2 + k][colunaD2 + k] = navio4[k]; // Posicionar navio diagonal para baixo
    }

    // Posicionar as matrizes de habilidade no tabuleiro para visualização
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade_cone[i][j] == 1) {
                tabuleiro[i][j] = 5; // Usar valor 5 para representar área de efeito do cone
            }
            if (habilidade_cruz[i][j] == 1) {
                tabuleiro[i][j] = 5; // Usar valor 5 para representar área de efeito da cruz
            }
            if (habilidade_octaedro[i][j] == 1) {
                tabuleiro[i][j] = 5; // Usar valor 5 para representar área de efeito do octaedro
            }
        }
    }

    // Exibir o tabuleiro com os navios e as áreas de efeito das habilidades
    printf("Tabuleiro com navios e áreas de efeito das habilidades:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da posição no tabuleiro
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    return 0; // Encerrar o programa
}