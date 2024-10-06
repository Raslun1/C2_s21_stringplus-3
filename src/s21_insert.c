#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* res = s21_NULL;
  if (src && str) {
    s21_size_t len_src = s21_strlen(src), len_str = s21_strlen(str);
    if (start_index <= len_src) {
      char* buf = malloc((len_src + len_str + 1) * sizeof(char));
      if (buf) {
        s21_strncpy(buf, src, start_index);
        s21_strncpy(buf + start_index, str, len_str);
        s21_strcpy(buf + start_index + len_str, src + start_index);
        res = buf;
      }
    }
  }
  return (void*)res;
}
