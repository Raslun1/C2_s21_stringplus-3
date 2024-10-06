#include "s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* result = s21_NULL;

  if (src == s21_NULL && trim_chars == s21_NULL) {
    return s21_NULL;
  } else {
    if (src != s21_NULL && trim_chars != s21_NULL) {
      const char *first = src, *last = src + s21_strlen(src) - 1;
      while (first <= last && s21_checkTrim(trim_chars, *first)) {
        first++;
      }
      while (last >= first && s21_checkTrim(trim_chars, *last)) {
        last--;
      }
      int length = last - first + 1;
      result = calloc(length + 1, 1);
      if (result != s21_NULL) {
        s21_strncpy(result, first, length);
        result[length] = '\0';
      }
    } else if (src != s21_NULL && trim_chars == s21_NULL) {
      result = calloc(s21_strlen(src) + 1, 1);
      s21_strncpy(result, src, (int)s21_strlen(src));
      result[(int)s21_strlen(src)] = '\0';
    }
  }
  return (void*)result;
}

bool s21_checkTrim(const char* trim_chars, char symbol) {
  bool found = false;
  while (*trim_chars) {
    if (symbol == *trim_chars) {
      found = true;
    }
    trim_chars++;
  }
  return found;
}
