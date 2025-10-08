#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float x1, y1, r1;
  float x2, y2, r2;

  scanf("%f %f %f", &x1, &y1, &r1);
  scanf("%f %f %f", &x2, &y2, &r2);

  float distancia = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

  if (distancia <= (r1+r2)*(r1+r2)) {
    printf("ACERTOU");
  } else {
    printf("ERROU");
  }

  exit(EXIT_SUCCESS);
}
