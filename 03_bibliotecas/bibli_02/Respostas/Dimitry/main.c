#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main(int argc, char *argv[]) {
  int option = -1;

  int r1, c1, r2, c2;

  scanf("%d %d", &r1, &c1);
  int matrix1[r1][r1];
  matrix_read(r1, c1, matrix1);

  scanf("%d %d", &r2, &c2);
  int matrix2[r2][c2];
  matrix_read(r2, c2, matrix2);
  
  while (option != 6) {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf(" %d", &option);
    // printf("%d\n", option);
    putchar('\n');

    switch (option) {
      case 1:
        if (!possible_matrix_sum(r1, c1, r2, c2)) {
          printf("Erro: as dimensoes da matriz nao correspondem\n");
        } else {
          int matrix3[r1][c1];
          matrix_add(r1, c1, matrix1, r2, c2, matrix2, matrix3);
          matrix_print(r1, c1, matrix3);
        }
        break;
      case 2:
        if (!possible_matrix_sub(r1, c1, r2, c2)) {
          printf("Erro: as dimensoes da matriz nao correspondem\n");
        } else {
          int matrix3[r1][c1];
          matrix_sub(r1, c1, matrix1, r2, c2, matrix2, matrix3);
          matrix_print(r1, c1, matrix3);
        }
        break;
      case 3:
        if (!possible_matrix_multiply(c1, r2)) {
          printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        } else {
          int matrix3[r1][c2];
          matrix_multiply(r1, c1, matrix1, r2, c2, matrix2, matrix3);
          matrix_print(r1, c2, matrix3);
        }
        break;
      case 4:
        if (1) {
          int scalar, option;
          scanf(" %d %d", &scalar, &option);
          if (option == 1) {
            scalar_multiply(r1, c1, matrix1, scalar);
            matrix_print(r1, c1, matrix1);
         } else if (option == 2) {
            scalar_multiply(r2, c2, matrix2, scalar);
            matrix_print(r2, c2, matrix2);
         }
        }
        break;
      case 5:
        if (1) {
          int matrix3[c1][r1];
          transpose_matrix(r1, c1, matrix1, matrix3);
          int matrix4[c2][r2];
          transpose_matrix(r2, c2, matrix2, matrix4);
          matrix_print(c1, r1, matrix3);
          matrix_print(c2, r2, matrix4);
        }
        break;
      case 6:
        break;
    }
  }

  exit(EXIT_SUCCESS);
}
