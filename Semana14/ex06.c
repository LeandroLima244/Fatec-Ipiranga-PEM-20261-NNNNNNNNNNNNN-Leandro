/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Aplicar a Conjectura de Collatz,      *
 *  imprimindo cada termo da sequencia ate atingir 1 e          *
 *  contabilizando o numero de passos, com validacao de entrada *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    long long n;
    int passos = 0;

    printf("=== Sequencia de Collatz ===\n\n");

    /* Controle de entrada: rejeita valores <= 0 */
    do {
        printf("Digite um inteiro positivo: ");
        scanf("%lld", &n);
        if (n <= 0) {
            printf("Entrada invalida. O valor deve ser maior que zero.\n");
        }
    } while (n <= 0);

    printf("\nSequencia: %lld", n);

    /* while: continua enquanto n nao chegar a 1 */
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;          /* n par: divide por 2 */
        } else {
            n = 3 * n + 1;      /* n impar: multiplica por 3 e soma 1 */
        }
        printf(" -> %lld", n);
        passos++;
    }

    printf("\n\nNumero de passos: %d\n", passos);
    return 0;
}
