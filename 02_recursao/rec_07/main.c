#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);

int main(int argc, char *argv[]) {
  int n;

  scanf("%d", &n);

  printf("%d\n", somaDigitos(n));

  exit(EXIT_SUCCESS);
}

int somaDigitos(int n) {
  if (n < 10) {
    return n;
  }

  return (n % 10) + somaDigitos(n/10);
}
