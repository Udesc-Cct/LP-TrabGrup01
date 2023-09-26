#include <stdio.h>

#define MAXLIN 3
#define MAXCOL 3

void MostarrMatriz(int pMatriz[MAXLIN][MAXCOL])
{
    // Imprimir linhas superiores
    printf("+");
    for (int c = 0; c < MAXCOL; c++) {
        printf("-");
    }
    printf("+\n");

    // Imprimir elementos da matriz
    for (int l = 0; l < MAXLIN; l++) {
        printf("|");
        for (int c = 0; c < MAXCOL; c++) {
            printf("%d", pMatriz[l][c]);
        }
        printf("|\n");
    }

    // Imprimir linha inferior
    printf("+");
    for (int c = 0; c < MAXCOL; c++) {
        printf("-");
    }
    printf("+\n");
}

int main(int argc, char *argv[]) {
    int Matriz[MAXLIN][MAXCOL] = {1,1,1,1,1,1,1,1,1};
    MostarrMatriz(Matriz);
	return 0;
}
