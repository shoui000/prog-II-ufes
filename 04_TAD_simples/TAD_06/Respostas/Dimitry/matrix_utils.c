#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols) {
	tMatrix m;
	m.cols = cols;
	m.rows = rows;

	return m;
}

tMatrix MatrixRead(tMatrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			scanf("%d", &matrix.data[i][j]);
		}
	}

	return matrix;
}

void MatrixPrint(tMatrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		putchar('|');
		for (int j = 0; j < matrix.cols; j++) {
			printf("%d", matrix.data[i][j]);

			if (j != matrix.cols - 1) {
				putchar(' ');
			}
		}

		putchar('|');
		putchar('\n');
	}
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
	return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
	return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
	return matrix1.cols == matrix2.rows;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
	tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);

	for (int i = 0; i < matrix1.rows; i++) {
		for (int j = 0; j < matrix1.cols; j++) {
			result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
		}
	}

	return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
	tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);

	for (int i = 0; i < matrix1.rows; i++) {
		for (int j = 0; j < matrix2.cols; j++) {
			result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
		}
	}

	return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
	tMatrix result = MatrixCreate(matrix1.rows, matrix2.cols);

	for (int i = 0; i < matrix1.rows; i++) {
		for (int j = 0; j < matrix2.cols; j++) {
			result.data[i][j] = 0;

			for (int x = 0; x < matrix1.cols; x++) {
				result.data[i][j] += matrix1.data[i][x] * matrix2.data[x][j];
			}
		}
	}

	return result;
}

tMatrix TransposeMatrix(tMatrix matrix) {
	tMatrix result = MatrixCreate(matrix.cols, matrix.rows);
	
	for (int i = 0; i < matrix.cols; i++) {
		for (int j = 0; j < matrix.rows; j++) {
			result.data[i][j] = matrix.data[j][i];
		}
	}

	return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			matrix.data[i][j] *= scalar;
		}
	}

	return matrix;
}
