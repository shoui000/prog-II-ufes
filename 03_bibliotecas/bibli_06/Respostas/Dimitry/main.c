#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "temperature_conversor.h"

int main() {
  float temp;
  char medida, final;
  scanf("%f %c %c", &temp, &medida, &final);

  switch (medida) {
    case 'c':
      switch (final) {
        case 'f':
          temp = convert_temperature(temp, convert_celsius_to_fahrenheit);
          break;
        case 'k':
          temp = convert_temperature(temp, convert_celsius_to_kelvin);
          break;
      }
      break;
    case 'f':
      switch (final) {
        case 'c':
          temp = convert_temperature(temp, convert_fahrenheit_to_celsius);
          break;
        case 'k':
          temp = convert_temperature(temp, convert_fahrenheit_to_kelvin);
          break;
      }
      break;
    case 'k':
      switch (final) {
        case 'c':
          temp = convert_temperature(temp, convert_kelvin_to_celsius);
          break;
        case 'f':
          temp = convert_temperature(temp, convert_kelvin_to_fahrenheit);
          break;
      }
      break;
  }

  printf("Temperature: %.2f%c", temp, final-32);
  if (final != 'k') printf("º");

  exit(EXIT_SUCCESS);
}
