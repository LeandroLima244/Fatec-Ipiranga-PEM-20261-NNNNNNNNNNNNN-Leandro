/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Demonstrar aritmetica de ponteiros    *
 *  sobre um vetor de 6 inteiros, percorrendo-o sem notacao de  *
 *  indice, exibindo enderecos, somando e dobrando os elementos *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

#define TAM 6

int main(void) {
    int v[TAM] = {10, 20, 30, 40, 50, 60};
    int *p = v;   /* p aponta para o primeiro elemento */
    int soma = 0;
    int i;

    printf("=== Aritmetica de Ponteiros sobre um Vetor ===\n\n");

    /* --- Impressao de elementos e enderecos usando aritmetica de ponteiros --- */
    printf("Elemento | Endereco (hex)  | Diferenca para anterior\n");
    printf("---------|-----------------|------------------------\n");
    for (i = 0; i < TAM; i++) {
        /* *(p+i) acessa o elemento na posicao i sem usar [] */
        if (i == 0) {
            printf("   %3d   | %p  |          ---\n", *(p + i), (void *)(p + i));
        } else {
            /* Diferenca entre enderecos consecutivos deve ser sizeof(int) */
            printf("   %3d   | %p  | %td bytes\n",
                   *(p + i), (void *)(p + i),
                   (p + i) - (p + i - 1));
        }
        soma += *(p + i);
    }

    printf("\nSoma dos elementos: %d\n", soma);
    printf("sizeof(int) = %zu bytes\n", sizeof(int));

    /* --- Dobra cada elemento in-place via desreferenciacao --- */
    printf("\nDobrando cada elemento in-place...\n");
    for (i = 0; i < TAM; i++) {
        *(p + i) *= 2;   /* desreferencia e modifica diretamente */
    }

    printf("Vetor apos dobrar: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}
