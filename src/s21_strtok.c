#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *prev = 0;
  if (str) prev = str;
  char *result = NULL;
  if (prev && *prev && delim && *delim) {
    char *c = prev;
    while (s21_strchr(delim, *c)) ++c;  // !!!!!!!!!!s21_strchr
    if (!*c)
      result = 0;
    else {
      result = c;
      while (*c && (s21_strchr(delim, *c) == 0)) ++c;  //!!!!!!!! s21_strchr
      if (!*c)
        prev = c;
      else {
        *c = 0;
        prev = c + 1;
      }
    }
  }
  return result;
}