#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *p = NULL;
  int match = 0;
  while (*str != '\0' && !match) {
    if (*str == c) {
      p = (char *)str;
      match++;
    }
    if (c == '\0') {
      p = (char *)str + s21_strlen(str);
      match++;
    }
    str++;
  }
  return p;
}