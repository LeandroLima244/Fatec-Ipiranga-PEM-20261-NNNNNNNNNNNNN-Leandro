/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Gerar a tabuada completa de 1 a 10   *
 *  usando laco externo for e interno while, com controle       *
 *  do-while para repetir ou encerrar conforme entrada do       *
 *  usuario                                                     *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    int i, j;
    char resp;

    printf("=== Tabuada Interativa ===\n");

    /* do-while controla se o usuario quer ver mais tabuadas */
    do {
        /* Laco externo: for percorre cada tabuada de 1 a 10 */
        for (i = 1; i <= 10; i++) {
            printf("\n--- Tabuada do %d ---\n", i);

            j = 1;
            /* Laco interno: while exibe cada linha da tabuada */
            while (j <= 10) {
                printf("%2d x %2d = %3d\n", i, j, i * j);
                j++;
            }

            /* Ao final de cada tabuada, pergunta se continua */
            if (i < 10) {
                printf("\nContinuar para a proxima tabuada? (S/N): ");
                scanf(" %c", &resp);
                if (resp == 'N' || resp == 'n') {
                    printf("Encerrando...\n");
                    return 0;
                }
            }
        }

        printf("\nDeseja reiniciar todas as tabuadas? (S/N): ");
        scanf(" %c", &resp);

    } while (resp == 'S' || resp == 's');

    printf("Programa encerrado.\n");
    return 0;
}
