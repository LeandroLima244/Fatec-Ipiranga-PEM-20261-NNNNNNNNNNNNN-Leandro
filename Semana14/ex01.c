/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Calcular a media ponderada de tres    *
 *  notas com seus respectivos pesos, exibindo o resultado com  *
 *  duas casas decimais e o tamanho em bytes de cada tipo usado *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    double n1, n2, n3;
    int    p1, p2, p3;
    double media;

    printf("=== Calculadora de Media Ponderada ===\n\n");

    printf("Digite a nota 1: ");
    scanf("%lf", &n1);
    printf("Digite o peso 1: ");
    scanf("%d", &p1);

    printf("Digite a nota 2: ");
    scanf("%lf", &n2);
    printf("Digite o peso 2: ");
    scanf("%d", &p2);

    printf("Digite a nota 3: ");
    scanf("%lf", &n3);
    printf("Digite o peso 3: ");
    scanf("%d", &p3);

    media = (n1 * p1 + n2 * p2 + n3 * p3) / (double)(p1 + p2 + p3);

    printf("\nMedia Ponderada: %.2f\n", media);

    printf("\n--- Tamanho dos tipos utilizados ---\n");
    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(int)    = %zu bytes\n", sizeof(int));

    return 0;
}

