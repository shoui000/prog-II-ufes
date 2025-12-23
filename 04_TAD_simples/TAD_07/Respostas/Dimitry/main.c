#include <stdio.h>

#include "data.h"

int main() {
  int dia, mes, ano;
  scanf("%d/%d/%d", &dia, &mes, &ano);

  tData d1 = CriaData(dia, mes, ano);

  scanf("%d/%d/%d", &dia, &mes, &ano);

  tData d2 = CriaData(dia, mes, ano);

  if (!(VerificaDataValida(d1) && VerificaDataValida(d2))) {
    printf("A primeira e/ou segunda data(s) invalida(s)\n");
    return 1;
  }

  printf("Primeira data: ");
  ImprimeDataExtenso(d1);

  printf("Segunda data: ");
  ImprimeDataExtenso(d2);

  switch (ComparaData(d1, d2)) {
    case -1:
      printf("A primeira data eh mais antiga\n");
      break;
    case 0:
      printf("As datas sao iguais\n");
      break;
    case 1:
      printf("A segunda data eh mais antiga\n");
      break;
  }

  printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(d1, d2));

  return 0;
}
