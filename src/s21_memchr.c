#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  const char *new_str = (const char *)str;
  void *p = NULL;
  int match = 0;
  for (size_t i = 0; i < n && !match; i++) {
    if (new_str[i] == c) {
      p = (void *)&new_str[i];
      match++;
    }
  }
  return p;
}
