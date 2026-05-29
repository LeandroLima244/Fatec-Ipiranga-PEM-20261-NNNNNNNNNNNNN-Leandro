/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Implementacao do modulo de operacoes  *
 *  com strings — contagem de vogais, inversao in-place e       *
 *  deteccao de palindromo, sem string.h (exceto strlen)        *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <string.h>   /* permitido: apenas strlen */
#include "ex13_stringutil.h"

/* Retorna 1 se o caractere c for vogal (mai. ou min.), 0 caso contrario */
static int ehVogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

/* contaVogais: percorre a string e conta cada vogal encontrada */
int contaVogais(char *s) {
    int count = 0;
    while (*s != '\0') {
        if (ehVogal(*s)) count++;
        s++;
    }
    return count;
}

/* inverteCString: inverte a string in-place usando dois ponteiros
   que se aproximam a partir das extremidades */
void inverteCString(char *s) {
    int n = (int)strlen(s);
    int i = 0, j = n - 1;
    char temp;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

/* ePalindromo: compara os caracteres das extremidades em direcao ao centro
   Retorna 1 se forem todos iguais (palindromo), 0 caso contrario */
int ePalindromo(char *s) {
    int n = (int)strlen(s);
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
