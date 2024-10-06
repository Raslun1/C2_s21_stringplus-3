#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  size_t len_dest = s21_strlen(dest), len_src = s21_strlen(src);
  if (len_src > n) {
    for (size_t i = 0; i < n; i++) {
      dest[i + len_dest] = src[i];
    }
    dest[n + len_dest] = '\0';
  } else {
    for (size_t i = 0; i < len_src; i++) {
      dest[i + len_dest] = src[i];
    }
    dest[len_src + len_dest] = '\0';
  }
  return dest;
}