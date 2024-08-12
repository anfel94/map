
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, size;
} Square;

extern char emptyChar, obstacleChar, fillChar;

int min(int a, int b);
Square findBiggestSquare(char **map, int rows, int cols);
void fillSquare(char **map, Square square, char fillChar);
void printMap(char **map, int rows, int cols);

#endif

Square findBiggestSquare(char **map, int rows, int cols) {
    Square biggestSquare = {0, 0, 0};

    // Matriz para almacenar el tamaño del cuadrado máximo que termina en cada celda
    int **dp = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int *)calloc(cols, sizeof(int));
    }

    // Calcular los tamaños de los cuadrados máximos
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == obstacleChar) {
                dp[i][j] = 0;
            } else {
                // Calcular el tamaño del cuadrado máximo basado en las celdas anteriores
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));

                // Actualizar el cuadrado más grande si es necesario
                if (dp[i][j] > biggestSquare.size) {
                    biggestSquare.x = j - dp[i][j] + 1;
                    biggestSquare.y = i - dp[i][j] + 1;
                    biggestSquare.size = dp[i][j];
                }
            }
        }
    }

    // Liberar la memoria de la matriz dp
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return biggestSquare;
}

void fillSquare(char **map, Square square, char fillChar) {
    // ... (implementación para rellenar el cuadrado)
}

void printMap(char **map, int rows, int cols) {
    // ... (implementación para imprimir el mapa)
}
