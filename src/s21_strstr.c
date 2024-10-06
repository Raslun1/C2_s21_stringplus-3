#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == 0 || needle == 0) {
    return 0;
  }
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) {
    return (char *)haystack;
  }
  if (haystack_len < needle_len) {
    return 0;
  }
  while (*haystack != '\0') {
    if (*haystack == *needle) {
      const char *h = haystack, *n = needle;
      int found = 1;
      while (*n != '\0') {
        if (*h != *n) {
          found = 0;
          break;
        }
        ++h;
        ++n;
      }
      if (found) {
        return (char *)haystack;
      }
    }
    ++haystack;
  }
  return 0;
}
