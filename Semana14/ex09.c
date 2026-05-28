/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Realizar a multiplicacao de duas      *
 *  matrizes 3x3 de inteiros e exibir as tres matrizes (A, B   *
 *  e C = A x B) com colunas alinhadas                         *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

#define L 3
#define C 3

void exibeMatriz(const char *nome, int m[L][C]) {
    int i, j;
    printf("\nMatriz %s:\n", nome);
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int A[L][C], B[L][C], Res[L][C];
    int i, j, k;

    printf("=== Multiplicacao de Matrizes 3x3 ===\n");

    printf("\nDigite os valores da Matriz A (3x3):\n");
    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }

    printf("\nDigite os valores da Matriz B (3x3):\n");
    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }

    /* Produto matricial C = A x B
       C[i][j] = soma de A[i][k] * B[k][j] para k de 0 a 2
       - i percorre as linhas de A (e de C)
       - j percorre as colunas de B (e de C)
       - k percorre as colunas de A / linhas de B (indice de contracao) */
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            Res[i][j] = 0;
            for (k = 0; k < C; k++) {
                Res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    exibeMatriz("A", A);
    exibeMatriz("B", B);
    exibeMatriz("C = A x B", Res);

    return 0;
}
