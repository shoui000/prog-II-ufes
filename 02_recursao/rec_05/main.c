#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  printf("%d\n", fatorial(n));

  exit(EXIT_SUCCESS);
}

int fatorial(int n) {
  if (n <= 1) {
    return 1;
  }

  return n * fatorial(n-1);
}
