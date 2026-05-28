/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Converter uma distancia em            *
 *  centimetros para metros, quilometros e milhas, com          *
 *  validacao de entrada para valores negativos                 *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    /* int: suficiente para valores ate 2.147.483.647 cm conforme enunciado */
    int cm;

    /* float: precisao de ~7 digitos; adequado para metros */
    float metros;

    /* double: precisao de ~15 digitos; necessario para km e milhas
       pois a divisao por 100000 e posterior multiplicacao podem
       perder precisao com float */
    double km, milhas;

    printf("=== Conversor de Unidades ===\n\n");
    printf("Digite a distancia em centimetros (int): ");
    scanf("%d", &cm);

    /* Validacao: rejeita valores negativos ou zero sem encerrar abruptamente */
    if (cm <= 0) {
        printf("Erro: a distancia deve ser um valor positivo.\n");
        return 1;
    }

    metros = (float)cm / 100.0f;
    km     = (double)cm / 100000.0;
    milhas = km / 1.60934;

    printf("\nResultados:\n");
    printf("  %d cm = %.2f metros\n",  cm, metros);
    printf("  %d cm = %.5f km\n",      cm, km);
    printf("  %d cm = %.5f milhas\n",  cm, milhas);

    printf("\n--- Tamanho dos tipos utilizados ---\n");
    printf("sizeof(int)    = %zu bytes\n", sizeof(int));
    printf("sizeof(float)  = %zu bytes\n", sizeof(float));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));

    return 0;
}

