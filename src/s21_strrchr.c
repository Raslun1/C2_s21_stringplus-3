#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;

  while (*str) {
    if (*str == c) {
      result = str;
    }
    str++;
  }

  if (c == '\0') {
    result = (char *)str;
  }

  return (char *)result;
}