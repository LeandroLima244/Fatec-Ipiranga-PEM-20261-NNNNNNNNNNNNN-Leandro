/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Implementar recursivamente a solucao  *
 *  da Torre de Hanoi para N discos (1<=N<=10), exibindo cada   *
 *  movimento e verificando se o total coincide com 2^N - 1     *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

/* Contador global de movimentos */
static int totalMovimentos = 0;

/*
 * hanoi: resolve recursivamente a Torre de Hanoi para n discos.
 * Parametros:
 *   n       — numero de discos a mover
 *   origem  — pino de origem
 *   destino — pino de destino
 *   auxiliar — pino auxiliar
 */
void hanoi(int n, char origem, char destino, char auxiliar) {
    /* Caso base: apenas um disco — move diretamente */
    if (n == 1) {
        printf("Mova disco 1 de [%c] para [%c]\n", origem, destino);
        totalMovimentos++;
        return;
    }

    /* Passo recursivo 1: move os (n-1) discos superiores de origem para auxiliar */
    hanoi(n - 1, origem, auxiliar, destino);

    /* Move o disco n (maior do grupo atual) de origem para destino */
    printf("Mova disco %d de [%c] para [%c]\n", n, origem, destino);
    totalMovimentos++;

    /* Passo recursivo 2: move os (n-1) discos de auxiliar para destino */
    hanoi(n - 1, auxiliar, destino, origem);
}

/* Calcula 2^n sem usar pow() */
static int potencia2(int n) {
    int resultado = 1, i;
    for (i = 0; i < n; i++) resultado *= 2;
    return resultado;
}

int main(void) {
    int n;

    printf("=== Torre de Hanoi — Solucao Recursiva ===\n\n");

    do {
        printf("Digite o numero de discos (1 a 10): ");
        scanf("%d", &n);
        if (n < 1 || n > 10) printf("Valor invalido. Digite entre 1 e 10.\n");
    } while (n < 1 || n > 10);

    printf("\nMovimentos:\n");
    hanoi(n, 'A', 'C', 'B');

    int esperado = potencia2(n) - 1;
    printf("\nTotal de movimentos realizados : %d\n", totalMovimentos);
    printf("Valor esperado (2^%d - 1)       : %d\n", n, esperado);
    printf("Verificacao: %s\n",
           totalMovimentos == esperado ? "CORRETO" : "DIVERGENCIA DETECTADA");

    return 0;
}
