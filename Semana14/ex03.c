/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Calcular o IMC de uma pessoa e        *
 *  classificar o resultado usando if encadeado, com tratamento *
 *  de entradas invalidas                                       *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    double peso, altura, imc;

    printf("=== Classificador de IMC ===\n\n");
    printf("Digite o peso (kg): ");
    scanf("%lf", &peso);
    printf("Digite a altura (m): ");
    scanf("%lf", &altura);

    /* Validacao: peso e altura devem ser positivos */
    if (peso <= 0 || altura <= 0) {
        printf("Erro: peso e altura devem ser valores positivos.\n");
        return 1;
    }

    imc = peso / (altura * altura);

    printf("\nIMC calculado: %.2f\n", imc);
    printf("Classificacao: ");

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc < 25.0) {
        printf("Peso normal\n");
    } else if (imc < 30.0) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }

    return 0;
}
