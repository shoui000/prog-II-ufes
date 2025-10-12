#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int palindromo(char *string, int tamanho);

int main(int argc, char *argv[]) {
  int ret;
  char buffer[MAX_BUFFER_SIZE];

  while (1) {
    ret = scanf("%s", buffer);

    if (ret == -1 || ret == 0) {
      break;
    }

    if (palindromo(buffer, strlen(buffer))) {
      printf("SIM\n");
    } else {
      printf("NAO\n");
    }
  }

  exit(EXIT_SUCCESS);
}

int palindromo(char *string, int tamanho) {
  if (string[0] != string[tamanho-1]) {
    return 0;
  }

  if (tamanho <= 2) {
    return string[0] == string[tamanho-1];
  }

  return palindromo(string+1, tamanho-2);
}
