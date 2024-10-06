#include "s21_string.h"

char *s21_strcat(char *str1, const char *str2) {
  char *strPointer = str1;

  while (*str1) {
    str1++;
  }
  while (*str2) {
    *str1++ = *str2++;
  }

  *str1 = '\0';

  return strPointer;
}