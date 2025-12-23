#include <stdio.h>
#include "matrix_utils.h"

int main() {
    int option = -1;

    int r, c;
    scanf("%d %d", &r, &c);
    tMatrix matrix1 = MatrixCreate(r, c);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &r, &c);
    tMatrix matrix2 = MatrixCreate(r, c);
    matrix2 = MatrixRead(matrix2);

    while (option != 6) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");
        scanf(" %d", &option);
        putchar('\n');

        switch (option) {
        case 1:
            if (!PossibleMatrixSum(matrix1, matrix2)) {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            } else {
                MatrixPrint(MatrixAdd(matrix1, matrix2));
            }
            break;
        case 2:
            if (!PossibleMatrixSub(matrix1, matrix2)) {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            } else {
                MatrixPrint(MatrixSub(matrix1, matrix2));
            }
            break;
        case 3:
            if (!PossibleMatrixMultiply(matrix1, matrix2)) {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            } else {
                MatrixPrint(MatrixMultiply(matrix1, matrix2));
            }
            break;
        case 4:
            int scalar, option;
            scanf(" %d %d", &scalar, &option);
            if (option == 1) {
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            } else if (option == 2) {
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
            break;
        case 5:
            MatrixPrint(TransposeMatrix(matrix1));
            MatrixPrint(TransposeMatrix(matrix2));
            break;
        case 6:
            break;
        }
    }

    return 0;
}
