#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Verifica diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    
    return 0;  // Sem vencedor
}

int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;  // Há espaço vazio
    return 1;  // Empate
}

void makeMove(char player) {
    int choice;
    printf("Jogador %c, escolha uma posição (1-9): ", player);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Movimento inválido! Tente novamente.\n");
        makeMove(player);
    } else {
        board[row][col] = player;
    }
}

int main() {
    char player = 'X';
    int game_over = 0;

    while (!game_over) {
        displayBoard();
        makeMove(player);

        if (checkWin()) {
            displayBoard();
            printf("Jogador %c venceu!\n", player);
            game_over = 1;
        } else if (checkDraw()) {
            displayBoard();
            printf("Empate!\n");
            game_over = 1;
        }

        // Alterna o jogador
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
