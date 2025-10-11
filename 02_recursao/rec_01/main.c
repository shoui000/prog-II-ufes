#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

void ImprimeInvertido(char *string);

int main() {
  int ret;
  char buffer[MAX_BUFFER_SIZE];

  while (1) {
    ret = scanf("%s", buffer);

    if (ret == -1 || ret == 0) {
      break;
    }

    ImprimeInvertido(buffer);
    putchar(' ');
  }

  exit(EXIT_SUCCESS);
}

void ImprimeInvertido(char *string) {
  if (strlen(string) > 1) {
    ImprimeInvertido(string+1);
  }

  putchar(string[0]);
}
