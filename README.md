#include <stdio.h>
#include <stdbool.h>

// Função para exibir o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < TAM - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Função para verificar vitória
bool verificarVitoria(char tabuleiro[TAM][TAM], char jogador) {

    // Verificar linhas
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] == jogador &&
            tabuleiro[i][1] == jogador &&
            tabuleiro[i][2] == jogador) {
            return true;
        }
    }

    // Verificar colunas
    for (int j = 0; j < TAM; j++) {
        if (tabuleiro[0][j] == jogador &&
            tabuleiro[1][j] == jogador &&
            tabuleiro[2][j] == jogador) {
            return true;
        }
    }

    // Verificar diagonal principal
    if (tabuleiro[0][0] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][2] == jogador) {
        return true;
    }

    // Verificar diagonal secundária
    if (tabuleiro[0][2] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][0] == jogador) {
        return true;
    }

    return false;
}

// Função para verificar se ainda existem espaços vazios
bool haEspacosVazios(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

int main() {

    char tabuleiro[TAM][TAM];
    char jogador_atual = 'X';
    bool vencedor = false;
    char vazio = ' ';
    int linha, coluna;

    // Inicialização do tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = vazio;
        }
    }

    // Laço principal do jogo
    while (haEspacosVazios(tabuleiro) && !vencedor) {

        mostrarTabuleiro(tabuleiro);

        printf("Jogador %c, digite a linha (0-2): ", jogador_atual);
        scanf("%d", &linha);

        printf("Jogador %c, digite a coluna (0-2): ", jogador_atual);
        scanf("%d", &coluna);

        // Validação da jogada
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Coordenadas invalidas! Tente novamente.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != vazio) {
            printf("Posicao ja ocupada! Escolha outra.\n");
            continue;
        }

        // Atualizar tabuleiro
        tabuleiro[linha][coluna] = jogador_atual;

        // Verificar vitória
        if (verificarVitoria(tabuleiro, jogador_atual)) {
            vencedor = true;
        } else {
            // Alternar jogador
            if (jogador_atual == 'X') {
                jogador_atual = 'O';
            } else {
                jogador_atual = 'X';
            }
        }
    }

    // Mostrar tabuleiro final
    mostrarTabuleiro(tabuleiro);

    // Resultado final
    if (vencedor) {
        printf("O jogador %c venceu!\n", jogador_atual);
    } else {
        printf("O jogo terminou em empate.\n");
    }

    return 0;
}apt-get install build-essential gdb
