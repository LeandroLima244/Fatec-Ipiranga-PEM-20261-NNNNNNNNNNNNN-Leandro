/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Testar o modulo de operacoes com      *
 *  strings (contaVogais, inverteCString, ePalindromo) com ao   *
 *  menos dois casos por funcao                                 *
 *  Compilar com: gcc ex13.c ex13_stringutil.c -o ex13          *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>
#include "ex13_stringutil.h"

int main(void) {
    char s1[] = "Programacao";
    char s2[] = "FATEC Ipiranga";
    char s3[] = "arara";
    char s4[] = "desenvolvimento";
    char s5[] = "radar";
    char s6[] = "OpenSource";

    printf("=== Biblioteca de Operacoes com Strings ===\n\n");

    /* --- contaVogais --- */
    printf("-- contaVogais --\n");
    printf("  \"%s\" -> %d vogal(is)\n", s1, contaVogais(s1));
    printf("  \"%s\" -> %d vogal(is)\n", s2, contaVogais(s2));

    /* --- inverteCString --- */
    printf("\n-- inverteCString --\n");
    printf("  Antes : \"%s\"", s3);
    inverteCString(s3);
    printf("  |  Depois: \"%s\"\n", s3);

    printf("  Antes : \"%s\"", s4);
    inverteCString(s4);
    printf("  |  Depois: \"%s\"\n", s4);

    /* --- ePalindromo --- */
    printf("\n-- ePalindromo --\n");
    printf("  \"%s\" -> %s\n", s5, ePalindromo(s5) ? "palindromo" : "nao e palindromo");
    printf("  \"%s\" -> %s\n", s6, ePalindromo(s6) ? "palindromo" : "nao e palindromo");

    return 0;
}
