#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  char *result = calloc(s21_strlen(str) + 1, sizeof(char));

  s21_strncpy(result, str, sizeof(char));

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    result[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
  }
  return (void *)result;
}
