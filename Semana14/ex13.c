/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Cabecalho do modulo de operacoes com  *
 *  strings — contagem de vogais, inversao in-place e deteccao  *
 *  de palindromo, sem string.h (exceto strlen)                 *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

/* Conta vogais (maiusculas e minusculas) na string s */
int contaVogais(char *s);

/* Inverte a string s in-place */
void inverteCString(char *s);

/* Retorna 1 se s for palindromo, 0 caso contrario */
int ePalindromo(char *s);

#endif /* STRINGUTIL_H */
