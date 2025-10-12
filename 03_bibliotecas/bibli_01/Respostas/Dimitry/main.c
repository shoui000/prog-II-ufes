#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "esfera_utils.h"

int main(int argc, char *argv[]) {
  float r;

  scanf("%f", &r);
  printf("Area: %.2f\nVolume: %.2f\n", calcula_area(r), calcula_volume(r));

  exit(EXIT_SUCCESS);
}
