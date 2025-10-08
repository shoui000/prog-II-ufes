#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n = 0, x = 1;
  scanf("%d", &n);

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j <= i; j++) {
      printf("%d ", x++);
    }

    putchar('\n');
  }

  exit(EXIT_SUCCESS);
}
