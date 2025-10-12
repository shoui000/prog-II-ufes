#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main(int argc, char *argv[]) {
  int n;

  scanf("%d", &n);

  int size, number;
  for (int i = 0; i < n; i++) {
    scanf("%d", &number);
    scanf("%d", &size);

    int array[size];
    for (int j = 0; j < size; j++) {
      scanf("%d", &array[j]);
    }

    printf("%d\n", ContaOcorrencias(array, size, number));
  }

  exit(EXIT_SUCCESS);
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
  if (numElementos == 0) {
    return vet[0] == numeroProcurado;
  }

  return ( vet[0] == numeroProcurado ) + ContaOcorrencias(vet+1, numElementos-1, numeroProcurado);
}
