#include <stdio.h>

#define TAM 4

/* Exibe o tabuleiro formatado como grade */
void exibeTabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("\nTabuleiro:\n");
    printf("+----+----+----+----+\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("| %2d ", tab[i][j]);
        }
        printf("|\n");
        printf("+----+----+----+----+\n");
    }
}

/* Verifica se pares estao em posicoes simetricas em relacao a diagonal principal
   Simetrico em relacao a diagonal: tab[i][j] == tab[j][i] para cada par */
void verificaSimetria(int tab[TAM][TAM]) {
    int i, j, simetrico = 1;
    for (i = 0; i < TAM; i++) {
        for (j = i + 1; j < TAM; j++) {
            if (tab[i][j] != tab[j][i]) {
                simetrico = 0;
                break;
            }
        }
        if (!simetrico) break;
    }
    if (simetrico)
        printf("\nOs pares SAO simetricos em relacao a diagonal principal.\n");
    else
        printf("\nOs pares NAO sao simetricos em relacao a diagonal principal.\n");
}

/* Calcula e exibe diagonal principal (i == j) e diagonal secundaria (i + j == TAM-1) */
void calculaDiagonais(int tab[TAM][TAM]) {
    int i, somaPrinc = 0, somaSecund = 0;
    printf("\nDiagonal principal: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tab[i][i]);
        somaPrinc += tab[i][i];
    }
    printf("(soma = %d)\n", somaPrinc);

    printf("Diagonal secundaria: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tab[i][TAM - 1 - i]);
        somaSecund += tab[i][TAM - 1 - i];
    }
    printf("(soma = %d)\n", somaSecund);
}

int main(void) {
    /* Tabuleiro hardcoded: 8 simbolos (1-8), cada um aparece exatamente duas vezes */
    int tabuleiro[TAM][TAM] = {
        {1, 2, 3, 4},
        {2, 5, 6, 3},
        {7, 6, 5, 8},
        {4, 7, 8, 1}
    };

    printf("=== Jogo da Memoria — Analise de Tabuleiro ===\n");

    exibeTabuleiro(tabuleiro);
    verificaSimetria(tabuleiro);
    calculaDiagonais(tabuleiro);

    return 0;
}
