#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = str1, *s2 = str2;
  int bit = 0;

  for (s21_size_t i = 0; i < n && bit == 0; i++) {
    bit = (int)s1[i] - (int)s2[i];
  }
  return bit;
}
