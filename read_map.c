#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, size;
} Square;

char** readMap(FILE *fp, int *rows, int *cols) {
    char emptyChar, obstacleChar, fillChar;
    fscanf(fp, "%d %c %c %c", rows, &emptyChar, &obstacleChar, &fillChar);

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

// int main() {
//     FILE *fp = fopen("map", "r"); // Abre el archivo mapa
//     if (fp == NULL) {
//         printf("Error al abrir el archivo.\n");
//         return 1;
//     }

//     int rows, cols;
//     char **map = readMap(fp, &rows, &cols);

//     // Imprimir el mapa (opcional, para verificar)
//     for (int i = 0; i < rows; i++) {
//         printf("%s\n", map[i]);
//     }

//     // Liberar la memoria asignada
//     for (int i = 0; i < rows; i++) {
//         free(map[i]);
//     }
//     free(map);

//     fclose(fp);
//     return 0;
// }

