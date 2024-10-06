#include "s21_string.h"

char *s21_strcpy(char *destptr, const char *srcptr) {
  while (*srcptr) {
    *destptr++ = *srcptr++;
  }
  *destptr = '\0';

  return destptr;
}