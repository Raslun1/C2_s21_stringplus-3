#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t index = 0;
  const char *pointerStr = str1;

  while (index != s21_strlen(str1) &&
         s21_strchr(str2, *pointerStr++) == s21_NULL) {
    index++;
  }
  return index;
}