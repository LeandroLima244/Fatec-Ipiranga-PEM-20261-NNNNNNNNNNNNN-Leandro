/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Calcular estatisticas de um vetor de  *
 *  10 floats em uma unica passagem: media, maior, menor e soma *
 *  dos valores acima da media, sem bibliotecas externas        *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

#define TAM 10

int main(void) {
    float v[TAM];
    float soma = 0.0f, media;
    float maior, menor;
    float somaAcimaDaMedia = 0.0f;
    int i;

    printf("=== Estatisticas de Vetor ===\n\n");

    for (i = 0; i < TAM; i++) {
        printf("Elemento v[%d]: ", i);
        scanf("%f", &v[i]);
        soma += v[i];
    }

    media = soma / TAM;
    maior = v[0];
    menor = v[0];

    /* Unica passagem: calcula maior, menor e soma acima da media */
    for (i = 0; i < TAM; i++) {
        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
        if (v[i] > media) somaAcimaDaMedia += v[i];
    }

    printf("\n--- Resultados ---\n");
    printf("Media aritmetica        : %.2f\n", media);
    printf("Maior valor             : %.2f\n", maior);
    printf("Menor valor             : %.2f\n", menor);
    printf("Soma dos acima da media : %.2f\n", somaAcimaDaMedia);

    return 0;
}
