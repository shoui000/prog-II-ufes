#include <stdio.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"

// // Estrutura que representa uma biblioteca de livros
// typedef struct {
//     tLivros livros[MAX_LIVROS]; // Array de livros
//     int tamanho; // Número atual de livros na biblioteca
// } tBiblioteca;

tBiblioteca inicializarBiblioteca() {
  tBiblioteca b;
  b.tamanho = 0;

  return b;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
  if (biblioteca.tamanho < MAX_LIVROS) {
    biblioteca.livros[biblioteca.tamanho++] = livro;
    printf("Livro adicionado com sucesso!\n");
  } else {
    printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
  }


  return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo) {
  int pos = -1;
  for (int i = 0; i < biblioteca.tamanho; i++) {
    if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo) == 0) {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    printf("Livro nao encontrado na Biblioteca.\n");
  } else {
    for (int i = pos+1; i < biblioteca.tamanho; i++) {
      biblioteca.livros[i-1] = biblioteca.livros[i];
    }

    biblioteca.tamanho--;

    printf("Livro removido com sucesso!\n");
  }

  return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
  return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
  if (biblioteca.tamanho == 0) {
    printf("A biblioteca esta vazia!\n");
  } else {
    printf("Lista de Livros na Biblioteca:\n");
    for (int i = 0; i < biblioteca.tamanho; i++) {
      imprimeLivro(biblioteca.livros[i]);
    }
  }

  putchar('\n');
}