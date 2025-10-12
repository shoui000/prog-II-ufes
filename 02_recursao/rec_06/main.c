#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", fibonacci(n));

  exit(EXIT_SUCCESS);
}

int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fibonacci(n-1) + fibonacci(n-2);
}
