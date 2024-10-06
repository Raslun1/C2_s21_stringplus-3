#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *p = NULL;
  int match = 0;
  for (size_t i = 0; i < s21_strlen(str1) && !match; i++) {
    for (size_t j = 0; j < s21_strlen(str2) && !match; j++) {
      if (str2[j] == str1[i]) {
        p = (char *)&str1[i];
        match++;
      }
    }
  }
  return p;
}
