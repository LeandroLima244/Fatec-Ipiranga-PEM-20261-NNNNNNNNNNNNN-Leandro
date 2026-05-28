/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Implementar funcoes com passagem      *
 *  exclusivamente por ponteiro: troca de variaveis, busca de   *
 *  minimo e maximo em vetor, e normalizacao de vetor float     *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

#define TAM 5

/* Troca os valores de duas variaveis inteiras via ponteiro */
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Retorna o menor e o maior elemento do vetor v de tamanho n
   Os resultados sao escritos nas posicoes apontadas por min e max */
void minMax(int *v, int n, int *min, int *max) {
    int i;
    *min = *v;
    *max = *v;
    for (i = 1; i < n; i++) {
        if (*(v + i) < *min) *min = *(v + i);
        if (*(v + i) > *max) *max = *(v + i);
    }
}

/* Normaliza o vetor v de tamanho n para o intervalo [0, 1]
   dividindo cada elemento pelo maior valor do vetor */
void normalizaVetor(float *v, int n) {
    int i;
    float maior = *v;
    for (i = 1; i < n; i++) {
        if (*(v + i) > maior) maior = *(v + i);
    }
    if (maior == 0.0f) return;  /* evita divisao por zero */
    for (i = 0; i < n; i++) {
        *(v + i) /= maior;
    }
}

int main(void) {
    printf("=== Funcoes com Passagem por Ponteiro ===\n\n");

    /* --- Teste de troca --- */
    int x = 7, y = 42;
    printf("-- troca --\n");
    printf("Antes : x = %d, y = %d\n", x, y);
    troca(&x, &y);
    printf("Depois: x = %d, y = %d\n\n", x, y);

    /* --- Teste de minMax --- */
    int v[TAM] = {15, 3, 99, 42, 7};
    int vmin, vmax;
    int i;

    printf("-- minMax --\n");
    printf("Vetor: ");
    for (i = 0; i < TAM; i++) printf("%d ", v[i]);
    printf("\n");
    minMax(v, TAM, &vmin, &vmax);
    printf("Minimo: %d | Maximo: %d\n\n", vmin, vmax);

    /* --- Teste de normalizaVetor --- */
    float fv[TAM] = {10.0f, 5.0f, 20.0f, 15.0f, 2.5f};
    printf("-- normalizaVetor --\n");
    printf("Antes : ");
    for (i = 0; i < TAM; i++) printf("%.2f ", fv[i]);
    printf("\n");
    normalizaVetor(fv, TAM);
    printf("Depois: ");
    for (i = 0; i < TAM; i++) printf("%.4f ", fv[i]);
    printf("\n");

    return 0;
}
