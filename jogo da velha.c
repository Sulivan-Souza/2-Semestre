#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int check_win(char mark) {
    int i, j;
    // Verifique as linhas
    for (i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
    }
    // Verifique as colunas
    for (j = 0; j < 3; j++) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            return 1;
        }
    }
    // Verifique as diagonais
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }
    return 0;
    
    // verifique empate
    if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
        printf("Empate!\n");
        display_board();
        return 0;
    }
}

int main() {
    int player = 1;
    int linhas, col;
    char mark;
    do {
        display_board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, escolha a linha (1-3) e  coluna (1-3) para colocar um %c: ", player, (player == 1) ? 'X' : 'O');
        scanf("%d %d", &linhas, &col);
        linhas--;
        col--;
        if (board[linhas][col] == ' ') {
            mark = (player == 1) ? 'X' : 'O';
            board[linhas][col] = mark;
            if (check_win(mark)) {
                printf("\nPlayer %d ganhou!\n", player);
                display_board();
                return 0;
            }
            player++;
        } else {
            printf("Esse espaço já está ocupado!\n");
        }
    } while (1);
    return 0;
}
