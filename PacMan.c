#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

char map[HEIGHT][WIDTH] = {
    "###################",
    "#........#........#",
    "#.###.###.###.###.#",
    "#.................#",
    "#.###.#.###.#.###.#",
    "#.....#.....#.....#",
    "#.###.#.###.#.###.#",
    "#.................#",
    "#.###.###.###.###.#",
    "###################",
};

int pacmanX = 1, pacmanY = 1;
int score = 0;

void drawMap() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == pacmanY && j == pacmanX) {
                printf("P");  // Pac-Man
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void movePacman(int dx, int dy) {
    int newX = pacmanX + dx;
    int newY = pacmanY + dy;

    if (map[newY][newX] != '#') {  // Check for wall
        pacmanX = newX;
        pacmanY = newY;

        if (map[pacmanY][pacmanX] == '.') {  // Collect dot
            score++;
            map[pacmanY][pacmanX] = ' ';  // Remove dot
        }
    }
}

int main() {
    char input;

    while (1) {
        drawMap();

        if (_kbhit()) {  // Check for keyboard input
            input = _getch();
            switch (input) {
                case 'w': movePacman(0, -1); break;  // Up
                case 's': movePacman(0, 1); break;   // Down
                case 'a': movePacman(-1, 0); break;  // Left
                case 'd': movePacman(1, 0); break;   // Right
                case 'q': return 0;  // Quit
            }
        }

        Sleep(100);  // Control game speed
    }

    return 0;
}
