#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

int main() {
  int dia, mes, ano;
  scanf("%d/%d/%d", &dia, &mes, &ano);

  if (verificaDataValida(dia, mes, ano)) {
    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    printf("O ano informado ");
    if (!verificaBissexto(ano)) {
      printf("nao ");
    }
    printf("eh bissexto\n");

    printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);
  } else {
    printf("A data informada eh invalida\n");
  }

  exit(EXIT_SUCCESS);
}
