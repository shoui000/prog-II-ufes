#include "utils.h"

void LeIntervalo(int *m, int *n) {
  scanf("%d %d", m, n);
}

int EhPrimo(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }

  return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
  for (int i = m; i <= n; i++) {
    if (EhPrimo(i)) {
      *menor = i;
      break;
    }
  }

  for (int i = n; i >= m; i--) {
    if (EhPrimo(i)) {
      *maior = i;
      break;
    }
  }
}
