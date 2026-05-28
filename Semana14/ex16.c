/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Implementar busca recursiva e soma    *
 *  recursiva por divisao do vetor sobre um array de 12 inteiros*
 *  aleatorios, exibindo chamadas recursivas e profundidade max *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12

/* Contadores globais */
static int chamadasBusca = 0;
static int profBusca = 0;
static int maxProfBusca = 0;

static int chamadasSoma = 0;
static int profSoma = 0;
static int maxProfSoma = 0;

/*
 * buscaRec: busca recursiva linear no vetor v de tamanho n pela chave.
 * Caso base: n == 0 (vetor vazio) — retorna -1 (nao encontrado).
 * Passo recursivo: compara o primeiro elemento; se nao for a chave,
 *                  busca no restante do vetor e ajusta o indice.
 * Retorno: indice da primeira ocorrencia ou -1.
 */
int buscaRec(int *v, int n, int chave) {
    chamadasBusca++;
    profBusca++;
    if (profBusca > maxProfBusca) maxProfBusca = profBusca;

    /* Caso base: vetor esgotado */
    if (n == 0) {
        profBusca--;
        return -1;
    }

    /* Verifica o elemento atual */
    if (*v == chave) {
        profBusca--;
        return 0;
    }

    /* Passo recursivo: busca no restante, avanando um elemento */
    int idx = buscaRec(v + 1, n - 1, chave);
    profBusca--;

    if (idx == -1) return -1;
    return idx + 1;   /* ajusta o indice para o vetor original */
}

/*
 * somaRec: calcula a soma dos elementos de v[ini..fim] por divisao do intervalo.
 * Caso base: ini == fim — retorna o unico elemento.
 * Passo recursivo: divide o intervalo ao meio e soma as duas metades recursivamente.
 * Retorno: soma total dos elementos no intervalo.
 */
int somaRec(int *v, int ini, int fim) {
    chamadasSoma++;
    profSoma++;
    if (profSoma > maxProfSoma) maxProfSoma = profSoma;

    int resultado;

    /* Caso base: intervalo com um unico elemento */
    if (ini == fim) {
        resultado = v[ini];
        profSoma--;
        return resultado;
    }

    /* Passo recursivo: divide ao meio e soma cada metade */
    int meio = (ini + fim) / 2;
    int esq = somaRec(v, ini, meio);
    int dir = somaRec(v, meio + 1, fim);
    resultado = esq + dir;

    profSoma--;
    return resultado;
}

int main(void) {
    int v[TAM];
    int i, chave, idx, soma;

    srand((unsigned)time(NULL));

    printf("=== Busca Recursiva e Soma por Divisao do Vetor ===\n\n");

    /* Gera vetor de 12 inteiros aleatorios entre 1 e 50 */
    printf("Vetor gerado: ");
    for (i = 0; i < TAM; i++) {
        v[i] = rand() % 50 + 1;
        printf("%d ", v[i]);
    }
    printf("\n");

    /* --- somaRec --- */
    soma = somaRec(v, 0, TAM - 1);
    printf("\nSoma total (somaRec): %d\n", soma);
    printf("  Chamadas recursivas: %d | Profundidade maxima: %d\n",
           chamadasSoma, maxProfSoma);

    /* --- buscaRec --- */
    printf("\nDigite um valor para buscar no vetor: ");
    scanf("%d", &chave);

    idx = buscaRec(v, TAM, chave);

    if (idx >= 0)
        printf("Valor %d encontrado no indice %d.\n", chave, idx);
    else
        printf("Valor %d nao encontrado no vetor.\n", chave);

    printf("  Chamadas recursivas: %d | Profundidade maxima: %d\n",
           chamadasBusca, maxProfBusca);

    return 0;
}
