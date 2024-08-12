#include <stdio.h>
#include <stdlib.h>

// Declaración global de las variables
char obstacleChar = 'X'; // Puedes cambiar 'X' por cualquier otro caracter
char fillChar = '#';

typedef struct {
    int x, y, size;
} Square;

char** readMap(FILE *fp, int *rows, int *cols) {
    char emptyChar, obstacleChar = 'X', fillChar = '#'; // Definición de obstacleChar y fillChar
    fscanf(fp, "%d %c", rows, &emptyChar);

    // Alocar memoria para la matriz
    char **map = (char **)malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        map[i] = (char *)malloc(*cols * sizeof(char));
    }

    // Leer el mapa del archivo
    for (int i = 0; i < *rows; i++) {
        fscanf(fp, "%s", map[i]);
    }

    return map;
}

int min(int a, int b) {
    return a < b ? a : b;
}

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
    // Implementación para rellenar el cuadrado
}

void printMap(char **map, int rows, int cols) {
    // Implementación para imprimir el mapa
}

int main() {
    FILE *fp = fopen("map", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int rows, cols;
    char **map = readMap(fp, &rows, &cols);

    // Encontrar el cuadrado más grande
    Square biggestSquare = findBiggestSquare(map, rows, cols);

    // Rellenar el cuadrado más grande
    fillSquare(map, biggestSquare, fillChar);

    // Imprimir el mapa resultante
    printMap(map, rows, cols);

    // Liberar la memoria
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
    fclose(fp);

    return 0;
}
