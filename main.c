#include <stdio.h>
#include "find_biggest_square.c"
#include "read_map.c"

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

