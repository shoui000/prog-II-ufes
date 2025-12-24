#include <stdio.h>
#include "biblioteca.h"
#include "livro.h"

int main() {
  tBiblioteca b = inicializarBiblioteca();

  int n, option;
  char buffer[100];
  scanf("%d\n", &n);

  printf("Lista de operacoes:\n");
  printf("1 - Cadastrar livros.\n");
  printf("2 - Remover livros.\n");
  printf("3 - Listar todos os livros cadastrados.\n\n");

  for (int i = 0; i < n; i++) {
    scanf("%d\n", &option);

    if (option == 1) {
      b = adicionarLivroNaBiblioteca(b, lerLivro());
    } else if (option == 2) {
      scanf("%s\n", buffer);
      b = removerLivroDaBiblioteca(b, buffer);
    } else if (option == 3) {
      listarLivrosDaBiblioteca(b);
    } else {
      printf("Operacao invalida!\n");
      break;
    }
  }

  return 0;
}