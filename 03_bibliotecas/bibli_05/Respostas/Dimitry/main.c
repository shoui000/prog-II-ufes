#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "string_utils.h"

#define MAX_BUFFER_SIZE 100

int main() {
  int option;
  char str[MAX_BUFFER_SIZE];
  char buffer[MAX_BUFFER_SIZE];
  scanf("%[^\n]", str);

  string_copy(str, buffer);
  do {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf(" %d", &option);
    putchar('\n');

    if (option == 1) {
      printf("Tamanho da string: %d\n", string_length(str));
    } else if (option == 2) {
      string_copy(str, buffer);
      printf("String copiada: %s\n", buffer);
    } else if (option == 3) {
      string_upper(buffer);
      printf("String convertida para maiusculas: %s\n", buffer);
    } else if (option == 4) {
      string_lower(buffer);
      printf("String convertida para minusculas: %s\n", buffer);
    } else if (option == 5) {
      string_reverse(buffer);
      printf("String invertida: %s\n", buffer);
    } else if (option == 6) break;

    putchar('\n');

  } while (option != 6);

  exit(EXIT_SUCCESS);
}
