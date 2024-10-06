#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src,
                 s21_size_t n) {  // void - копирование данных любого типа
  char *cdest = (char *)dest;  // создаем временные указатели
  const char *csrc = (const char *)src;  // const - не меняем.
  for (s21_size_t i = 0; i < n; i++) {
    cdest[i] = csrc[i];
  }
  return dest;
}
