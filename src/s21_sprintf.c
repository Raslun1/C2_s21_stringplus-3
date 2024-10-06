#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  Flags f = {0};
  f.base = 10;
  va_list va;
  va_start(va, format);
  char *str_beginning = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      s21_memset(&f, 0, sizeof(Flags));
      f.base = 10;
      format++;
    }
    format = get_flags(format, &f);
    format = get_params(format, &f.width, &va);
    if (*format == '.') {
      format++;
      f.zero = 0;
      f.dot = true;
      format = get_params(format, &f.accuracy, &va);
    }
    format = get_length(format, &f);
    f.specificator = *format++;

    char *buff = s21_NULL;
    specificator_tracking(&f, &buff, va);
    for (int i = 0; i < f.size; i++) {
      *str++ = buff[i];
    }
    free(buff);
    if (f.specificator == 'n') {
      int *ret = va_arg(va, int *);
      *ret = str - str_beginning;
    }
  }
  *str = '\0';
  va_end(va);
  return str - str_beginning;
}

void specificator_tracking(Flags *f, char **buff, va_list va) {
  if (f->specificator == 's') {
    implementation_of_s_specifiers(buff, va, f);
  } else if (f->specificator == 'c') {
    implementation_of_c_specifiers(buff, va, f);
  } else if (f->specificator == 'd' || f->specificator == 'i') {
    implementation_of_int_specifiers(buff, va, f);
  } else if (f->specificator == 'u' || f->specificator == 'o' ||
             f->specificator == 'x' || f->specificator == 'X') {
    implementation_of_unsigned_specifiers(buff, va, f);
  } else if (f->specificator == 'f' || f->specificator == 'e' ||
             f->specificator == 'E' || f->specificator == 'g' ||
             f->specificator == 'G') {
    implementation_of_float_specifiers(buff, va, f);
  } else if (f->specificator == 'p') {
    implementation_of_address_specifiers(buff, va, f);
  } else if (f->specificator == '%') {
    implementation_of_procent_specifiers(buff, f);
  }
  if (f->to_upper) buff = toUpper(*buff);
}

void implementation_of_procent_specifiers(char **buff, Flags *f) {
  f->size = 1;
  *buff = malloc(sizeof(char) * (f->size + 1));
  s21_memset(*buff, '\0', (f->size + 1));
  (*buff)[0] = '%';
}
int get_s21_size_to_s(char *string, Flags *f) {
  int size = 0;
  if (string != s21_NULL) {
    if (!f->dot) f->accuracy = s21_strlen(string);
    if (f->accuracy > (int)s21_strlen(string)) f->accuracy = s21_strlen(string);
    f->width -= f->accuracy;
    if (f->width > 0) size += f->width;
    size += f->accuracy;
  } else {
    f->width = (f->accuracy >= 6) ? f->width - 6 : f->width;
    if (f->accuracy >= 6) {
      size += 6;
    }
    if (f->width > 0) size += f->width;
  }
  return size;
}

void implementation_of_s_specifiers(char **buff, va_list va, Flags *f) {
  char *string = va_arg(va, char *);
  f->size = get_s21_size_to_s(string, f);
  *buff = malloc(sizeof(char) * (f->size + 1));
  s21_memset(*buff, '\0', f->size + 1);
  f->zero = 0;
  if (string != s21_NULL) {
    for (int i = 0; i < f->accuracy; i++) {
      (*buff)[i] = string[i];
    }
    (*buff)[f->accuracy] = '\0';
    flag_minus(*buff, f);
  } else {
    if (f->accuracy >= 6) s21_strcpy(*buff, "(null)");
    flag_minus(*buff, f);
  }
}

void implementation_of_c_specifiers(char **buff, va_list va, Flags *f) {
  char elem = va_arg(va, int);
  f->width--;
  f->size = (f->width > 0 ? f->width : 0) + 1;
  *buff = (char *)malloc(sizeof(char) * (f->size + 1));
  (*buff)[0] = elem;
  (*buff)[1] = '\0';
  f->zero = false;
  flag_minus(*buff, f);
}

int get_length_unsigned(unsigned long long elem, Flags *f) {
  int length = 0;
  if (elem == 0)
    length += 1;
  else {
    while (elem > 0) {
      elem /= f->base;
      length++;
    }
  }
  return length;
}

int get_s21_size_to_unsigned(unsigned long long elem, Flags *f) {
  int size = 0;
  int length = get_length_unsigned(elem, f);
  size += length;
  if (f->accuracy - length > 0) {
    f->accuracy -= length;
  } else
    f->accuracy = 0;
  size += f->accuracy;
  f->width = f->width - length - f->accuracy;
  if ((f->specificator == 'd' || f->specificator == 'i') &&
      (f->space || f->plus || f->is_negative)) {
    size++;
    f->width--;
  }
  if (elem != 0 && f->specificator == 'o' && f->hash) {
    size += 1;
    f->width--;
  } else if (elem != 0 && (f->specificator == 'x' || f->specificator == 'X') &&
             f->hash) {
    size += 2;
    f->width -= 2;
  }
  if (f->width > 0) size += f->width;
  return size;
}

void implementation_of_int_specifiers(char **buff, va_list va, Flags *f) {
  long long elem = parse_to_int(va, f);
  if (elem < 0) {
    elem = -elem;
    f->is_negative = true;
  }
  if (f->accuracy == 0 && f->dot && elem == 0.0) return;
  f->size = get_s21_size_to_unsigned(elem, f);
  *buff = malloc(sizeof(char) * (f->size + 1));
  whole_unsigned_to_string(elem, *buff, f->base);
  parameters_for_unsigned(elem, *buff, f);
  (*buff)[f->size] = '\0';
}

void implementation_of_unsigned_specifiers(char **buff, va_list va, Flags *f) {
  if (f->specificator == 'o')
    f->base = 8;
  else if (f->specificator == 'x' || f->specificator == 'X')
    f->base = 16;
  if (f->specificator == 'X') f->to_upper = true;
  unsigned long long elem = parse_to_unsigned(va, f);
  f->size = get_s21_size_to_unsigned(elem, f);
  *buff = malloc(sizeof(char) * (f->size + 1));
  whole_unsigned_to_string(elem, *buff, f->base);
  parameters_for_unsigned(elem, *buff, f);
  (*buff)[f->size] = '\0';
  if (f->to_upper) {
    *buff = toUpper(*buff);
  }
}

int get_s21_size_to_float(long double elem, Flags *f) {
  int size = 0;
  int width = 0;
  long double integer = 0, frac = modfl(elem, &integer);
  int count_zero = modified_parts_of_float(&elem, &integer, &frac, f);
  int length_int = get_length_unsigned(integer, f);
  width += length_int;
  if (f->space || f->plus || f->is_negative) {
    width++;
  }
  if (f->accuracy == 0 && f->hash) {
    width++;
  }
  if (f->accuracy != 0) {
    int length_frac = get_length_unsigned(frac, f);
    if (f->specificator == 'g' || f->specificator == 'G' || f->change_spec) {
      char *temp_buff_g = malloc(sizeof(char) * (length_frac + count_zero + 1));
      whole_unsigned_to_string(frac, temp_buff_g, 10);
      for (int j = 0; j < count_zero;
           j++) {  // перегоняю все нули в массив, соотвественно
        for (int i = length_frac; i >= 0;
             i--) {  // все длина length += count_zero
          temp_buff_g[i + 1] = temp_buff_g[i];
        }
        length_frac++;
        temp_buff_g[0] = '0';
      }
      int i = length_frac - 1;
      while (i >= 0 && temp_buff_g[i] == '0') temp_buff_g[i--] = '\0';
      if (f->pow_e != 0) f->specificator = 'e';
      count_zero = 0;
      if (i == -1)
        length_frac = -1;
      else
        length_frac = i + 1;
      free(temp_buff_g);
    }
    width += count_zero + length_frac + 1;
  }
  size = width;
  f->width -= width;
  if (f->width > 0)
    size += f->width;
  else if (f->specificator == 'e' || f->specificator == 'E' || f->change_spec)
    size += 4;
  return size;
}

void implementation_of_float_specifiers(char **buff, va_list va, Flags *f) {
  if (f->accuracy == 0 && !f->dot) {  // самое главное для точности
    f->accuracy = 6;  // теперь если точность 0, то 100% с точкой ".0f"
  }
  if (f->specificator == 'E' || f->specificator == 'G') f->to_upper = true;
  long double elem = parse_to_double(va, f);
  if (elem < 0) {
    elem = -elem;
    f->is_negative = true;
  }
  if (f->specificator == 'g' || f->specificator == 'G')
    preparation_of_g(elem, f);
  if (f->specificator == 'e' || f->specificator == 'E' || f->change_spec)
    elem = preparation_of_e(elem, f);

  f->size = get_s21_size_to_float(elem, f);
  *buff = malloc(sizeof(char) * (f->size + 1));
  s21_memset(*buff, '\0', f->size + 1);
  whole_float_to_string(elem, *buff, f);
  parameters_for_float(*buff, f);
}

void implementation_of_address_specifiers(char **buff, va_list va, Flags *f) {
  unsigned long int ptr = (unsigned long int)va_arg(va, unsigned long int);
  f->hash = 1;
  f->base = 16;
  f->specificator = 'x';
  int length = get_length_unsigned(ptr, f) + 2;
  if (ptr != 0) {
    f->width -= length;
    f->accuracy = 0;
    if (f->width < 0) f->width = 0;
    f->size = length + f->width;
    *buff = malloc(sizeof(char) * (f->size + 1));
    s21_memset(*buff, '\0', f->size + 1);
    whole_unsigned_to_string(ptr, *buff, f->base);
    parameters_for_unsigned(ptr, *buff, f);
  } else {
    f->size = 5;
    *buff = malloc(sizeof(char) * (f->size + 1));
    s21_memset(*buff, '\0', f->size + 1);
    s21_strcpy(*buff, "(nil)");
  }
}

long double preparation_of_e(long double num, Flags *f) {
  long double integer;
  long double frac = modfl(num, &integer);
  int count_zero = 0;
  if ((unsigned long long int)integer > 9) {
    while (count_zero < 20 && (unsigned long long int)integer > 9) {
      integer /= 10;
      num /= 10;
      f->pow_e++;
      count_zero++;
    }
  } else if (floor(frac) == 0 && integer == 0.0) {
    while (count_zero < 20 && floor(frac) == 0) {
      frac *= 10;
      num *= 10;
      f->pow_e--;
      count_zero++;
    }
  }
  if (count_zero == 20) {
    f->pow_e = 0;
  }
  return num;
}

void preparation_of_g(long double elem, Flags *f) {
  long double integer = 0.0, frac = modfl(elem, &integer);
  modified_parts_of_float(&elem, &integer, &frac, f);
  char temp[4096] = {'\0'};
  int length = whole_unsigned_to_string(integer, temp, 10);
  if (integer != 0.0) {
    if (f->accuracy >= length) {
      f->accuracy -= length;
    } else {
      f->change_spec = true;
      if (f->accuracy >= 2)
        f->accuracy -= 1;
      else
        f->accuracy = 0;
    }
  } else if (elem != 0.0) {
    if (f->accuracy == 0) f->accuracy++;
    if (elem < 0.0001) {
      f->change_spec = true;
    }
  }
}

void parameters_for_float(char *buff, Flags *f) {
  flag_minus(buff, f);
  add_first_space(buff, f);
}

int modified_parts_of_float(long double *elem, long double *integer,
                            long double *frac, Flags *f) {
  if (*frac + 0.00000000000001 >= 1) {
    *frac = 0;
    *integer = *integer + 1;
  }
  long double temp_frac = *frac;
  int count_zero = 0;
  if (round(temp_frac) == 0) {
    for (count_zero = 0;
         (long long int)temp_frac < 1 && count_zero < f->accuracy;
         count_zero++) {
      temp_frac *= 10;
    }
    count_zero--;
  }
  if (f->specificator == 'g' || f->specificator == 'G' || f->change_spec)
    *frac = temp_frac / 10;
  *frac = *frac * pow(10, f->accuracy);
  *frac = round(*frac);
  if ((unsigned long long int)(*frac) % 10 == 0 && f->accuracy == 1 &&
      *frac != 0) {  // костыль для %.1%f
    *integer = *integer + 1;
    *frac = *frac - 10;
  }
  if (f->accuracy == 0) {
    *integer = round(*elem);
  }
  return count_zero;
}

void whole_float_to_string(long double elem, char *buff, Flags *f) {
  long double integer;
  long double frac = modfl(elem, &integer);

  int count_zero = modified_parts_of_float(&elem, &integer, &frac, f);

  char str_int[8000] = {'\0'}, str_frac[8000] = {'\0'};

  whole_unsigned_to_string(integer, str_int, 10);
  s21_strcat(buff, str_int);
  if (f->accuracy == 0 && f->hash) {
    s21_strcat(buff, ".");
  }
  whole_unsigned_to_string(frac, str_frac, 10);
  if (f->accuracy != 0) {
    while (count_zero > 0) {
      for (int i = s21_strlen(str_frac); i >= 0; i--) {
        str_frac[i + 1] = str_frac[i];
      }
      str_frac[0] = '0';
      count_zero--;
    }
    if (f->specificator == 'g' || f->specificator == 'G' || f->change_spec) {
      int i = s21_strlen(str_frac) - 1;
      while (str_frac[i] == '0') str_frac[i--] = '\0';
      if (f->pow_e != 0) f->specificator = 'e';
    }
    if (s21_strlen(str_frac) != 0) s21_strcat(buff, ".");
    s21_strcat(buff, str_frac);
  }
  if (f->specificator == 'e' || f->specificator == 'E' || f->change_spec) {
    f->width -= 4;
    char result[4] = "e";
    result[1] = f->pow_e >= 0 ? '+' : '-';

    if (f->pow_e < 0) f->pow_e = -f->pow_e;
    char result_e[3];
    if (f->pow_e < 10) result[2] = '0';
    whole_unsigned_to_string(f->pow_e, result_e, 10);
    s21_strcat(result, result_e);
    s21_strcat(buff, result);
  }
}

char convert_num_to_string(long long unsigned int elem, int base) {
  return "0123456789abcdef"[elem % base];
}

int whole_unsigned_to_string(unsigned long long elem, char *result_buff,
                             int base) {
  char inter[22] = {'\0'};
  char *last = s21_NULL;
  unsigned long long tmp_digit = elem;
  if (elem == 0) {
    inter[21] = '\0';
    inter[20] = '0';
    last = &inter[20];
  } else {
    int i = 21;
    while (tmp_digit != 0) {
      i--;
      inter[i] = convert_num_to_string(tmp_digit, base);
      tmp_digit /= base;
    }
    inter[21] = '\0';
    last = &inter[i];
  }
  s21_strcpy(result_buff, last);
  return s21_strlen(result_buff);
}

void parameters_for_unsigned(unsigned long long elem, char *buff, Flags *f) {
  int length = s21_strlen(buff);
  int index = 0;
  if (f->dot) f->zero = false;
  char *buff_zero = malloc(sizeof(char) * (f->accuracy + 3 + length));
  if (elem != 0 && f->hash &&
      (f->specificator == 'o' || f->specificator == 'x' ||
       f->specificator == 'X')) {
    buff_zero[index++] = '0';
    if (f->specificator != 'o') {
      buff_zero[index++] = 'x';
    }
  }
  for (; f->accuracy > 0; f->accuracy--) {
    buff_zero[index++] = '0';
  }
  buff_zero[index] = '\0';
  s21_strcat(buff_zero, buff);
  s21_strcpy(buff, buff_zero);
  free(buff_zero);
  if (f->zero) {
    flag_minus(buff, f);
    if (f->specificator == 'd' || f->specificator == 'i')
      add_first_space(buff, f);
  } else {
    if (f->specificator == 'd' || f->specificator == 'i')
      add_first_space(buff, f);
    flag_minus(buff, f);
  }
}

void add_first_space(char *buff, Flags *f) {
  int length = s21_strlen(buff);
  char *temp_buff = (char *)malloc((length + 3) * sizeof(char));
  if (f->space) {
    temp_buff[0] = f->is_negative ? '-' : ' ';
    temp_buff[1] = '\0';
  } else if (f->plus) {
    temp_buff[0] = f->is_negative ? '-' : '+';
    temp_buff[1] = '\0';
  } else if (f->is_negative) {
    temp_buff[0] = '-';
    temp_buff[1] = '\0';
  } else
    temp_buff[0] = '\0';
  temp_buff[1] = '\0';
  s21_strcat(temp_buff, buff);
  s21_strcpy(buff, temp_buff);
  free(temp_buff);
}

void flag_minus(char *buff, Flags *f) {
  if (f->width > 0) {
    char *temp_buff = malloc(sizeof(char) * (f->size + 1));
    int index = 0;
    for (int i = 0; i < f->width; i++) {
      if (f->zero)
        temp_buff[index++] = '0';
      else
        temp_buff[index++] = ' ';
    }
    temp_buff[index] = '\0';
    if (!f->minus) {
      s21_strcat(temp_buff, buff);
      s21_strcpy(buff, temp_buff);
    } else
      s21_strcat(buff, temp_buff);
    free(temp_buff);
  }
}

long long int parse_to_int(va_list va, Flags *f) {
  long long int elem = 0;
  if (f->length == 'L')
    elem = va_arg(va, long long int);
  else if (f->length == 'l')
    elem = (long int)va_arg(va, long int);
  else if (f->length == 'h')
    elem = (short int)va_arg(va, int);
  else
    elem = va_arg(va, int);
  return elem;
}

long double parse_to_double(va_list va, Flags *f) {
  long double elem = 0;
  if (f->length == 'L')
    elem = va_arg(va, long double);
  else
    elem = (double)va_arg(va, double);
  return elem;
}

unsigned long long parse_to_unsigned(va_list va, Flags *f) {
  unsigned long long elem = 0;
  if (f->length == 'L')
    elem = (unsigned long long int)va_arg(va, unsigned long long int);
  else if (f->length == 'l') {
    elem = (unsigned long int)va_arg(va, unsigned long int);
  } else if (f->length == 'h')
    elem = (unsigned short int)va_arg(va, unsigned int);
  else
    elem = (unsigned int)va_arg(va, unsigned int);
  return elem;
}

const char *get_flags(const char *format, Flags *f) {
  while (format) {
    if (*format == '-')
      f->minus = true;
    else if (*format == '+')
      f->plus = true;
    else if (*format == ' ')
      f->space = true;

    else if (*format == '#')
      f->hash = true;
    else if (*format == '0')
      f->zero = true;
    else
      break;
    format++;
  }

  f->space = (f->space && !f->plus);
  f->zero = (f->zero && !f->minus);
  return format;
}

const char *get_params(const char *format, int *num, va_list *va) {
  if (*format == '*') {
    *num = va_arg(*va, int);
    format++;
  } else {
    while (*format >= '0' && *format <= '9') {
      *num *= 10;
      *num += *format - '0';
      format++;
    }
  }
  return format;
}

const char *get_length(const char *format, Flags *f) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
    case 'L':
      f->length = 'L';
      format++;
      break;
  }
  return format;
}

void *toUpper(const char *str) {
  if (str == s21_NULL) return s21_NULL;

  char *copyStr = (char *)str;
  s21_size_t lengthStr = s21_strlen(str);
  if (copyStr) {
    for (; lengthStr--; ++copyStr) {
      if (*copyStr >= 'a' && *copyStr <= 'z') {
        *copyStr = *copyStr - 32;
      }
    }
  }

  return (void *)str;
}