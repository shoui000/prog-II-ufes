#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

int main() {
  int dia1, dia2, mes1, mes2, ano1, ano2;
  scanf("%d/%d/%d", &dia1, &mes1, &ano1);
  scanf("%d/%d/%d", &dia2, &mes2, &ano2);

  if (!(verificaDataValida(dia1, mes1, ano1) && verificaDataValida(dia2, mes2, ano2))){
    printf("A primeira e/ou segunda data(s) invalida(s)");
    exit(EXIT_SUCCESS);
  }

  printf("Primeira data: ");
  imprimeDataExtenso(dia1, mes1, ano1);
  printf("Segunda data: ");
  imprimeDataExtenso(dia2, mes2, ano2);

  switch (comparaData(dia1, mes1, ano1, dia2, mes2, ano2)) {
    case -1:
      printf("A primeira data eh mais antiga\n");
      break;
    case 0:
      printf("As datas sao iguais\n");
      break;
    case 1:
      printf("A segunda data eh mais antiga\n");
      break;
  };

  printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));

  exit(EXIT_SUCCESS);
}
