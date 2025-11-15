#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Tamanho dos navios
#define AGUA 0      // Representação de água
#define NAVIO_ID 3  // Representação dos navios no tabuleiro

int main() {

    // -----------------------------
    // 1. Declaração do tabuleiro
    // -----------------------------
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------------------------
    // 2. Vetores representando os navios (tamanho 3)
    // -------------------------------------------
    int navioHorizontal[NAVIO] = {NAVIO_ID, NAVIO_ID, NAVIO_ID};
    int navioVertical[NAVIO]   = {NAVIO_ID, NAVIO_ID, NAVIO_ID};

    // ---------------------------------------------
    // 3. Coordenadas iniciais dos navios (fixas)
    // ---------------------------------------------

    // Navio horizontal começando na linha 2, coluna 4
    int linhaH = 2;
    int colunaH = 4;

    // Navio vertical começando na linha 5, coluna 7
    int linhaV = 5;
    int colunaV = 7;

    // ----------------------------------------------------
    // 4. Validação dos navios para evitar ultrapassar bordas
    // ----------------------------------------------------

    // Validação do navio horizontal
    if (colunaH + NAVIO > TAM) {
        printf("Erro: Navio horizontal ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // Validação do navio vertical
    if (linhaV + NAVIO > TAM) {
        printf("Erro: Navio vertical ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // ----------------------------------------------------------
    // 5. Verificação de sobreposição antes de posicionar os navios
    // ----------------------------------------------------------

    // Verifica se já existe outro navio no caminho do horizontal
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 1;
        }
    }

    // Verifica se já existe outro navio no caminho do vertical
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != AGUA) {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 1;
        }
    }

    // --------------------------------------
    // 6. Posicionamento dos navios na matriz
    // --------------------------------------

    // Posiciona navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ---------------------------
    // 7. Exibição do tabuleiro
    // ---------------------------

    printf("\n===== TABULEIRO DE BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
