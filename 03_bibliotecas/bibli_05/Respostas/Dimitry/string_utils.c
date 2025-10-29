#include "string_utils.h"

int string_length(char *str) {
  int i = 0;
  while (str[i] != '\0') i++;

  return i;
}

void string_copy(char *src, char *dest) {
  for (int i = 0; i < string_length(src); i++) {
    dest[i] = src[i];
  }

  dest[string_length(src)] = '\0';
}

void string_upper(char *str) {
  for (int i = 0; i < string_length(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
  }
}

void string_lower(char *str) {
  for (int i = 0; i < string_length(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
  }
}

void string_reverse(char *str) {
  int len = string_length(str);
  for (int i = 0; i < len/2; i++) {
    str[i] ^= str[len-i-1];
    str[len-i-1] ^= str[i];
    str[i] ^= str[len-i-1];
  }
}
