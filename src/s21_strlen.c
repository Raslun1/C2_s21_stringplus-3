#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int index = 0;
  while (str[index++]) {
    ;
  }
  return index - 1;
}