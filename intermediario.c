#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Tamanho fixo dos navios
#define AGUA 0      // Representação de água
#define NAVIO_ID 3  // Representação das partes dos navios

// -------------------------------------------------------------
// Função auxiliar para verificar sobreposição no tabuleiro
// Retorna 1 se houver sobreposição, 0 se estiver livre
// -------------------------------------------------------------
int haSobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] != AGUA;
}

int main() {

    // --------------------------
    // 1. Declaração do tabuleiro
    // --------------------------
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -----------------------------------------------------------
    // 2. Representação dos navios (tamanho 3)
    // -----------------------------------------------------------
    int navio1[NAVIO] = {NAVIO_ID, NAVIO_ID, NAVIO_ID}; // horizontal/vertical
    int navio2[NAVIO] = {NAVIO_ID, NAVIO_ID, NAVIO_ID}; // horizontal/vertical
    int navio3[NAVIO] = {NAVIO_ID, NAVIO_ID, NAVIO_ID}; // diagonal /
    int navio4[NAVIO] = {NAVIO_ID, NAVIO_ID, NAVIO_ID}; // diagonal \

    // ------------------------------------------------------------
    // 3. Coordenadas iniciais dos navios
    // (Fixas conforme requisitos)
    // ------------------------------------------------------------

    // Navio horizontal (tamanho 3)
    int hLinha = 2, hColuna = 1;

    // Navio vertical
    int vLinha = 4, vColuna = 7;

    // Navio diagonal DESCENDO PARA A DIREITA (\)
    int d1Linha = 0, d1Coluna = 0;

    // Navio diagonal DESCENDO PARA A ESQUERDA (/)
    int d2Linha = 7, d2Coluna = 5;

    // ------------------------------------------------------------
    // 4. Validação de limites e sobreposição (horizontal)
    // ------------------------------------------------------------
    if (hColuna + NAVIO > TAM) {
        printf("Erro: Navio horizontal ultrapassa bordas!\n");
        return 1;
    }

    for (int i = 0; i < NAVIO; i++) {
        if (haSobreposicao(tabuleiro, hLinha, hColuna + i)) {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }

    // Posiciona navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[hLinha][hColuna + i] = navio1[i];
    }

    // ------------------------------------------------------------
    // 5. Validação de limites e sobreposição (vertical)
    // ------------------------------------------------------------
    if (vLinha + NAVIO > TAM) {
        printf("Erro: Navio vertical ultrapassa bordas!\n");
        return 1;
    }

    for (int i = 0; i < NAVIO; i++) {
        if (haSobreposicao(tabuleiro, vLinha + i, vColuna)) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[vLinha + i][vColuna] = navio2[i];
    }

    // ------------------------------------------------------------
    // 6. Validação e posicionamento do navio diagonal (\)
    //    Linha e coluna aumentam simultaneamente
    // ------------------------------------------------------------
    if (d1Linha + NAVIO > TAM || d1Coluna + NAVIO > TAM) {
        printf("Erro: Navio diagonal \\ ultrapassa bordas!\n");
        return 1;
    }

    for (int i = 0; i < NAVIO; i++) {
        if (haSobreposicao(tabuleiro, d1Linha + i, d1Coluna + i)) {
            printf("Erro: Sobreposição no navio diagonal \\ !\n");
            return 1;
        }
    }

    // Posiciona o navio diagonal \
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[d1Linha + i][d1Coluna + i] = navio3[i];
    }

    // ------------------------------------------------------------
    // 7. Validação e posicionamento do navio diagonal (/)
    //    Linha aumenta e coluna diminui simultaneamente
    // ------------------------------------------------------------
    if (d2Linha + NAVIO > TAM || d2Coluna - (NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal / ultrapassa bordas!\n");
        return 1;
    }

    for (int i = 0; i < NAVIO; i++) {
        if (haSobreposicao(tabuleiro, d2Linha + i, d2Coluna - i)) {
            printf("Erro: Sobreposição no navio diagonal / !\n");
            return 1;
        }
    }

    // Posiciona o navio diagonal /
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[d2Linha + i][d2Coluna - i] = navio4[i];
    }

    // ------------------------------------------------------------
    // 8. Exibir o tabuleiro completo
    // ------------------------------------------------------------
    printf("\n===== TABULEIRO DE BATALHA NAVAL (COM DIAGONAIS) =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
