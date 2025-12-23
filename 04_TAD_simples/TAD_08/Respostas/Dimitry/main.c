#include <stdio.h>
#include "departamento.h"

int main() {
  int qtdDepartamentos;

  scanf("%d\n", &qtdDepartamentos);

  tDepartamento dptos[qtdDepartamentos];

  char nome[STRING_MAX];
  char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
  int m1, m2, m3;
  char diretor[STRING_MAX];

  for (int i = 0; i < qtdDepartamentos; i++) {
    scanf("%s\n", nome);
    scanf("%s\n", diretor);
    scanf("%s\n%s\n%s\n", c1, c2, c3);
    scanf("%d %d %d\n", &m1, &m2, &m3);

    dptos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
  }

  ordenaPorMediaDepartamentos(dptos, qtdDepartamentos);

  for (int i = 0; i < qtdDepartamentos; i++) {
    imprimeAtributosDepartamento(dptos[i]);
  }

  return 0;
}