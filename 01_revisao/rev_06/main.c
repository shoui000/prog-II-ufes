#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int limit; char b; int funkos[62];
  scanf("%d ", &limit);

  memset(funkos, 0, 62 * sizeof(int));

  while (1) {
    b = getchar();

    if (b == EOF || b == '\n') {
      break;
    }

    if (b >= '0' && b <= '9') {
      funkos[b-'0']++;
      continue;
    }

    if (b >= 'A' && b <= 'Z') {
      funkos[b-'A'+10]++;
      continue;
    }

    if (b >= 'a' && b <= 'z') {
      funkos[b-'a'+36]++;
      continue;
    }
  }

  int p = 0;
  for (int i = 0; i < 62; i++) {
    if (funkos[i] > limit) {

      if (i >= 0 && i <= 9) {
        putchar('0'+i);
      } else if (i >= 10 && i <= 35) {
        putchar('A'+i-10);
      } else if (i >= 36) {
        putchar('a'+i-36);
      }

      printf(": %d\n", funkos[i]);
      p = 1;
    }
  }

  if (!p) {
    printf("NENHUM\n");
  }

  exit(EXIT_SUCCESS);
}
