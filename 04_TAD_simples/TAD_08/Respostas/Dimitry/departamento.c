#include <stdio.h>
#include <math.h>
#include <string.h>
#include "departamento.h"

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor) {
  tDepartamento d;
  strcpy(d.c1, c1);
  strcpy(d.c2, c2);
  strcpy(d.c3, c3);
  strcpy(d.nome, nome);
  d.m1 = m1;
  d.m2 = m2;
  d.m3 = m3;
  strcpy(d.diretor, diretor);
  d.media_geral = (float)calculaMediaGeralDepartamento(d);
  
  return d;
}

void imprimeAtributosDepartamento (tDepartamento depto) {
  printf("ATRIBUTOS:\n");
  printf("departamento => %s\n", depto.nome);
  printf("diretor => %s\n", depto.diretor);
  printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
  printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
  printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
  printf("media geral => %.2f\n", depto.media_geral);
  printf("desvio padrao => %.2f\n", calculaDesvioPadraoDepartamento(depto));
  putchar('\n');
}

int validaMediaDepartamento (int media) {
  return 0 <= media && media <= 10;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto) {
  double desvio = 0;
  desvio += (depto.m1 - depto.media_geral) * (depto.m1 - depto.media_geral);
  desvio += (depto.m2 - depto.media_geral) * (depto.m2 - depto.media_geral);
  desvio += (depto.m3 - depto.media_geral) * (depto.m3 - depto.media_geral);

  return sqrt(desvio / 3.0);
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
  return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
  int swaps;

  do {
    swaps = 0;
    for (int i = 0; i < tamanho-1; i++) {
      if (d[i].media_geral < d[i+1].media_geral) {
        tDepartamento temp = d[i];
        d[i] = d[i+1];
        d[i+1] = temp;
        swaps++;
      }
    }
  } while (swaps);

}