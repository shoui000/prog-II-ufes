#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, qtt = 0, x = 0;
  scanf("%d", &n);

  int books[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &books[i]);
  }

  int single_books[n];
  for (int i = 0; i < n; i++) {
    qtt = 0;

    for (int j = 0; j < n; j++) {
      if (books[j] == books[i]) {
        qtt++;
      }
    }

    if (qtt == 1) {
      single_books[x] = books[i];
      x++;
    }
  }

  if (x == 0) {
    printf("NENHUM");
    exit(EXIT_SUCCESS);
  }

  //bubblesort
  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < x-1; i++) {
      if (single_books[i] > single_books[i+1]) {
        single_books[i] ^= single_books[i+1];
        single_books[i+1] ^= single_books[i];
        single_books[i] ^= single_books[i+1];
        swaps++;
      }
    }
  } while (swaps);

  for (int i = 0; i < x; i++) {
    printf("%d ", single_books[i]);
  }

  exit(EXIT_SUCCESS);
}
