/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Analisar e manipular um vetor de N    *
 *  inteiros, identificando maior/menor com indices, contando   *
 *  pares/impares, gerando vetor invertido e realizando busca   *
 *  linear                                                      *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

#define N 8

int main(void) {
    int v[N], inv[N];
    int i, maiorIdx, menorIdx;
    int pares = 0, impares = 0;
    int chave, encontrado;

    printf("=== Analise e Manipulacao de Vetor ===\n\n");

    for (i = 0; i < N; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    /* Exibe vetor original */
    printf("\nVetor original: ");
    for (i = 0; i < N; i++) printf("%d ", v[i]);
    printf("\n");

    /* Inicializa indices com o primeiro elemento */
    maiorIdx = 0;
    menorIdx = 0;

    for (i = 0; i < N; i++) {
        if (v[i] > v[maiorIdx]) maiorIdx = i;
        if (v[i] < v[menorIdx]) menorIdx = i;
        if (v[i] % 2 == 0) pares++;
        else                impares++;
    }

    printf("\nMaior valor: %d (indice %d)\n", v[maiorIdx], maiorIdx);
    printf("Menor valor: %d (indice %d)\n", v[menorIdx], menorIdx);
    printf("Pares: %d | Impares: %d\n", pares, impares);

    /* Gera vetor invertido */
    for (i = 0; i < N; i++) inv[i] = v[N - 1 - i];

    printf("\nVetor invertido: ");
    for (i = 0; i < N; i++) printf("%d ", inv[i]);
    printf("\n");

    /* Busca linear */
    printf("\nDigite o valor a buscar: ");
    scanf("%d", &chave);

    encontrado = -1;
    for (i = 0; i < N; i++) {
        if (v[i] == chave) { encontrado = i; break; }
    }

    if (encontrado >= 0) printf("Valor %d encontrado no indice %d.\n", chave, encontrado);
    else                 printf("Valor %d nao encontrado no vetor.\n", chave);

    return 0;
}
