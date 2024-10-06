#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *result = NULL;

  if (errnum >= BEG && errnum <= END) {
    result = (char *)arrayErrorMessages[errnum];
  } else {
    char numStr[10000];
    s21_sprintf(numStr, " %d", errnum);
    result = (char *)malloc(sizeof(char) *
                            (s21_strlen(ERROR) + s21_strlen(numStr) + 1));
    s21_memset(result, '\0', s21_strlen(ERROR) + s21_strlen(numStr) + 1);
    s21_strcpy(result, ERROR);
    s21_strcat(result, numStr);
  }

  return result;
}