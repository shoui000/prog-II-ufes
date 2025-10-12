#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int SomaElementosPares(int* vet, int numElementos);

int main(int argc, char *argv[]) {
  int n;

  scanf("%d", &n);

  int size;
  for (int i = 0; i < n; i++) {
    scanf("%d", &size);

    int array[size];
    for (int j = 0; j < size; j++) {
      scanf("%d", &array[j]);
    }

    printf("%d\n", SomaElementosPares(array, size));
  }

  exit(EXIT_SUCCESS);
}

int SomaElementosPares(int* vet, int numElementos) {
  if (numElementos == 1) {
    return (vet[0]%2 == 0) ? vet[0] : 0;
  }

  int ret = 0;

  if (vet[0]%2 == 0) {
    ret += vet[0];
  }

  ret += SomaElementosPares(vet+1, numElementos-1);

  return ret;
}
