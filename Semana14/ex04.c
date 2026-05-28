/*-------------------------------------------------------------*
 *  FATEC Ipiranga                                              *
 *  Disciplina: Programacao Estruturada e Modular               *
 *           Prof. Verissimo                                    *
 * -------------------------------------------------------------*
 *  Objetivo do Programa: Validar se tres valores formam um     *
 *  triangulo e, se valido, classificar quanto aos lados e      *
 *  quanto aos angulos usando if encadeado                      *
 *  Data - 14/05/2026                                           *
 *  Autor: Leandro Lima Medeiros ; 2040482522013                *
 * -------------------------------------------------------------*/

#include <stdio.h>

int main(void) {
    double a, b, c;

    printf("=== Validador e Classificador de Triangulo ===\n\n");
    printf("Digite o lado a: ");
    scanf("%lf", &a);
    printf("Digite o lado b: ");
    scanf("%lf", &b);
    printf("Digite o lado c: ");
    scanf("%lf", &c);

    /* Verificacao da desigualdade triangular:
       cada lado deve ser menor que a soma dos outros dois */
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Erro: os lados devem ser positivos.\n");
        return 1;
    }

    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Os valores NAO formam um triangulo valido.\n");
        return 0;
    }

    printf("\nTriangulo valido!\n");

    /* --- Classificacao quanto aos LADOS --- */
    printf("\nClassificacao quanto aos lados: ");
    if (a == b && b == c) {
        /* Todos os lados iguais */
        printf("Equilatero\n");
    } else if (a == b || a == c || b == c) {
        /* Exatamente dois lados iguais */
        printf("Isosceles\n");
    } else {
        /* Todos os lados diferentes */
        printf("Escaleno\n");
    }

    /* --- Classificacao quanto aos ANGULOS ---
       Usamos a relacao entre quadrados dos lados para determinar o maior angulo.
       Ordena para que 'c' seja o maior lado (maior angulo oposto). */
    double maior, x, y;
    if (a >= b && a >= c) { maior = a; x = b; y = c; }
    else if (b >= a && b >= c) { maior = b; x = a; y = c; }
    else { maior = c; x = a; y = b; }

    printf("Classificacao quanto aos angulos: ");
    if (maior * maior == x * x + y * y) {
        /* Quadrado do maior lado igual a soma dos quadrados dos outros dois */
        printf("Retangulo\n");
    } else if (maior * maior > x * x + y * y) {
        /* Quadrado do maior lado maior que a soma: angulo obtuso */
        printf("Obtusangulo\n");
    } else {
        /* Quadrado do maior lado menor que a soma: todos os angulos agudos */
        printf("Acutangulo\n");
    }

    return 0;
}
