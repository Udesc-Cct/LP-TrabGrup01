#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define MAXLIN 10
#define MAXCOL 10

int contador = 0;

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void MostarMatriz(int pMatriz[MAXLIN][MAXCOL])
{
    // Imprimir linhas superiores
    printf("---------- MATRIZ ---------\n\n");
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

void preencherComZeros(int matriz[MAXLIN][MAXCOL], int linhas, int colunas) {
    int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }
}

int buscarValor(int pMatriz[MAXLIN][MAXCOL], int valor) {
    int conjuntosEncontrados = 0;

    for (int l = 0; l < contador; l++) {
        for (int c = 0; c < MAXCOL; c++) {
            if (pMatriz[l][c] == valor) {
                printf("�ndice do conjunto que cont�m o valor %d: %d\n", valor, l);
                conjuntosEncontrados++;
                break;
            }
        }
    }

    return conjuntosEncontrados;
}

void criarNovoConjunto(int pMatriz[MAXLIN][MAXCOL]) {
    if (contador < MAXLIN) {
        contador++;
        printf("Novo conjunto criado com sucesso.\n");
    } else {
        printf("N�o � poss�vel criar um novo conjunto. Limite m�ximo de conjuntos atingido.\n");
    }
}

void inserirDadosConjunto(int pMatriz[MAXLIN][MAXCOL]) {
    int indice;
    printf("Informe o �ndice do conjunto (0 a %d) para inserir os dados: ", contador - 1);
    scanf("%d", &indice);

    if (indice >= 0 && indice < contador) {
        int proximoIndice = 0;
        int valor;
        int quantidadeInserida = 0;

        while (proximoIndice < MAXCOL) {
            printf("Informe o valor a ser inserido (0 para encerrar): ");
            scanf("%d", &valor);

            if (valor == 0 || quantidadeInserida == MAXCOL) {
                break;
            }

            // Verificar se o valor j� foi inserido previamente
            int valorRepetido = 0;
            for (int c = 0; c < proximoIndice; c++) {
                if (pMatriz[indice][c] == valor) {
                    valorRepetido = 1;
                    break;
                }
            }

            if (!valorRepetido) {
                pMatriz[indice][proximoIndice] = valor;
                proximoIndice++;
                quantidadeInserida++;
            } else {
                printf("Valor j� foi inserido anteriormente. Insira um valor diferente.\n");
            }
        }

        printf("Dados inseridos com sucesso no conjunto %d.\n", indice);
    } else {
        printf("�ndice inv�lido. Insira um �ndice v�lido.\n");
    }
}

void removerConjunto(int pMatriz[MAXLIN][MAXCOL]) {
    int indice;
    printf("Informe o �ndice do conjunto (0 a %d) para remover: ", contador - 1);
    scanf("%d", &indice);

    if (indice >= 0 && indice < contador) {
        // Mover conjuntos abaixo para cima
        for (int l = indice; l < contador - 1; l++) {
            for (int c = 0; c < MAXCOL; c++) {
                pMatriz[l][c] = pMatriz[l + 1][c];
            }
        }

        // Zerar a �ltima linha (conjunto removido)
        for (int c = 0; c < MAXCOL; c++) {
            pMatriz[contador - 1][c] = 0;
        }

        contador--;
        printf("Conjunto removido com sucesso.\n");
    } else {
        printf("�ndice inv�lido. Insira um �ndice v�lido.\n");
    }
}

void uniaoConjuntos(int pMatriz[MAXLIN][MAXCOL]) {
    int indice1, indice2;
    printf("Informe os �ndices dos conjuntos para realizar a uni�o:\n");
    printf("Conjunto 1: ");
    scanf("%d", &indice1);
    printf("Conjunto 2: ");
    scanf("%d", &indice2);

    if (indice1 >= 0 && indice1 < contador && indice2 >= 0 && indice2 < contador) {
        // Criar novo conjunto na matriz
        if (contador < MAXLIN) {
            contador++;
            for (int c = 0; c < MAXCOL; c++) {
                pMatriz[contador - 1][c] = 0;
            }
        } else {
            printf("N�o � poss�vel criar um novo conjunto. Limite m�ximo de conjuntos atingido.\n");
            return;
        }

        // Realizar a uni�o dos conjuntos
        int novoIndice = contador - 1;
        for (int c = 0; c < MAXCOL; c++) {
            pMatriz[novoIndice][c] = pMatriz[indice1][c] | pMatriz[indice2][c];
        }

        printf("Uni�o realizada com sucesso. Novo conjunto criado no �ndice %d.\n", novoIndice);
    } else {
        printf("�ndices inv�lidos. Insira �ndices v�lidos.\n");
    }
}
int main() {
    int matriz[MAXLIN][MAXCOL]={0};  // Inicializar matriz com zeros
    preencherComZeros(matriz,MAXLIN,MAXCOL);
    int opcao;
    do {
        clearScreen();
        MostarMatriz(matriz);
        printf("\n");
        printf("---------- MENU ----------\n");
        printf("1. Mostrar matriz\n");
        printf("2. Buscar valor\n");
        printf("3. Criar novo conjunto\n");
        printf("4. Inserir dados em um conjunto\n");
        printf("5. Remover conjunto\n");
        printf("6. Unir conjuntos\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                MostarMatriz(matriz);
                break;
            case 2:
                // Implementar chamada da fun��o buscarValor
                break;
            case 3:
                // Implementar chamada da fun��o criarNovoConjunto
                break;
            case 4:
                // Implementar chamada da fun��o inserirDadosConjunto
                break;
            case 5:
                // Implementar chamada da fun��o removerConjunto
                break;
            case 6:
                // Implementar chamada da fun��o uniaoConjuntos
                break;
            case 9:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Escolha uma op��o v�lida.\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}
