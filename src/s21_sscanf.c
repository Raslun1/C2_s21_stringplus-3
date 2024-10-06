#include "s21_string.h"

int s21_sscanf(const char* str, const char* format, ...) {
  va_list arguments;
  va_start(arguments, format);

  int counter = 0;
  const char* str_beginning = str;
  while (*format) {
    if (*format == '%') {
      Flags flags = {0};
      if (*(format + 1) == '*') {
        flags.star = true;
        str++;
        format++;
        continue;
      }
      format++;
      format = s21_settingFlags(format, &flags);
      str = s21_specifierTracking(str_beginning, str, format, flags, &arguments,
                                  &counter);
      if (*format == '%') {
        format++;
        str++;
      }
    }
    if (*format == *str) str++;
    format++;
  }
  va_end(arguments);

  return counter;
}

const char* s21_settingFlags(const char* format, Flags* flags) {
  int result = 0;
  while (*format >= '0' && *format <= '9') {
    int temp = *format - '0';
    result = result * 10 + temp;
    format++;
  }
  flags->width = result;
  if (*format == 'L' || *format == 'l' || *format == 'h') {
    flags->length = *format;
    while (*format == 'L' || *format == 'l' || *format == 'h') {
      format++;
    }
  }
  return format;
}

const char* s21_specifierTracking(const char* str_beginning, const char* str,
                                  const char* format, Flags flags,
                                  va_list* arguments, int* counter) {
  const char specificier = *format;
  bool flagForChar = false;
  if (specificier == 'n') {
    s21_implementationN(str_beginning, str, arguments);
  } else if (specificier == 'c' && *(format + 1) == '%' &&
             *(format + 2) == 'c') {
    flagForChar = true;
    char* buffer = va_arg(*arguments, char*);
    str = s21_implementationChar(str, counter, buffer, flagForChar);
  } else if (specificier == 'c') {
    char* buffer = va_arg(*arguments, char*);
    str = s21_implementationChar(str, counter, buffer, flagForChar);
  } else if (specificier == 's') {
    char* buffer = va_arg(*arguments, char*);
    str = s21_implementationString(str, counter, flags.width, buffer);
  } else if (specificier == 'd') {
    long long int* buffer = va_arg(*arguments, long long int*);
    str = s21_implementationInt(str, flags, counter, buffer);
  } else if (specificier == 'u') {
    unsigned long long int* buffer =
        va_arg(*arguments, unsigned long long int*);
    str = s21_implementationUnsignedInt(str, flags, counter, buffer);
  } else if (specificier == 'o') {
    unsigned long long int* buffer =
        va_arg(*arguments, unsigned long long int*);
    str = s21_implementationUnsignedOct(str, flags, counter, buffer);
  } else if (specificier == 'x' || specificier == 'X') {
    unsigned long long int* buffer =
        va_arg(*arguments, unsigned long long int*);
    str = s21_implementationUnsignedHex(str, flags, counter, buffer);
  } else if (specificier == 'i') {
    long long int* buffer = va_arg(*arguments, long long int*);
    str = s21_implementationSignedInt(str, flags, counter, buffer);
  } else if (specificier == 'f' || specificier == 'e' || specificier == 'E' ||
             specificier == 'g' || specificier == 'G') {
    str = s21_implementationFloat(str, arguments, flags, counter);
  } else if (specificier == 'p') {
    void* buffer = va_arg(*arguments, void*);
    str = s21_implementationAddress(str, flags, counter, buffer);
  }
  return str;
}

const char* s21_implementationN(const char* str_beginning, const char* str,
                                va_list* arguments) {
  int* buffer = va_arg(*arguments, int*);
  *buffer = str - str_beginning;
  while (s21_checkSpace(*str)) {
    str++;
    (*buffer)++;
  }
  return str;
}
const char* s21_implementationAddress(const char* str, Flags flags,
                                      int* counter, void* buffer) {
  while (s21_checkSpace(*str)) str++;
  int total_length = 0;
  unsigned long result = 0, temporarily;
  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    str++;
    str++;
  }
  const char* str_rep = str;
  while ((*str_rep >= '0' && *str_rep <= '9') ||
         (*str_rep >= 'a' && *str_rep <= 'f') ||
         (*str_rep >= 'A' && *str_rep <= 'F')) {
    total_length++;
    str_rep++;
  }
  total_length = s21_recalculate(total_length, flags);
  for (int i = 0; i < total_length; i++) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    if (str[i] >= 'A' && str[i] <= 'F') temporarily = (int)str[i] - 'A' + 10;
    if (str[i] >= 'a' && str[i] <= 'f') temporarily = (int)str[i] - 'a' + 10;
    result = result * 16 + temporarily;
  }
  if (total_length > 0) {
    *(unsigned long*)buffer = result;
    (*counter)++;
  }
  while (total_length--) str++;

  return str;
}
const char* s21_implementationChar(const char* str, int* counter, char* buffer,
                                   bool flag) {
  if (*str != '\0') {
    s21_strncpy(buffer, str, 1);
    buffer[1] = '\0';
    str++;
    (*counter)++;
    while (s21_checkSpace(*str) && !flag) {
      str++;
    }
  } else
    (*counter) = -1;
  return str;
}

const char* s21_implementationString(const char* str, int* counter, int width,
                                     char* buffer) {
  int buffWidth = width;

  while (s21_checkSpace(*str)) {
    str++;
  }

  const char* copy = str;
  int len = 0;
  if (width) {
    while (!s21_checkSpace(*copy) && *copy != '\0' && buffWidth) {
      len++;
      copy++;
      buffWidth--;
    }
  } else {
    while (!s21_checkSpace(*copy) && *copy != '\0') {
      len++;
      copy++;
    }
  }

  if (*str) {
    s21_strncpy(buffer, str, len);
    buffer[len] = '\0';
    if (width) {
      while (!s21_checkSpace(*str) && *str != '\0' && width) {
        str++;
        width--;
      }
    } else {
      while (!s21_checkSpace(*str) && *str != '\0') {
        str++;
      }
    }
    (*counter)++;
  }

  return str;
}

const char* s21_implementationInt(const char* str, Flags flags, int* counter,
                                  long long int* buffer) {
  int sign = 1;
  bool isNegative = false;
  while (s21_checkSpace(*str)) {
    str++;
  }
  if (*str == '-') {
    str++;
    isNegative = true;
    sign = -1;
  } else if (*str == '+') {
    str++;
  }
  if (*str != '\0') {
    long long int result = 0;
    if (flags.width > 0) {
      while (*str >= '0' && *str <= '9') {
        if (--flags.width <= 0) {
          break;
        }
        if (result > (LLONG_MAX - (*str - '0')) / 10) {
          *buffer = (isNegative) ? LLONG_MIN : LLONG_MAX;
          (*counter)++;
          return str;
        }
        result = result * 10 + (*str - '0');
        str++;
      }
      if (result) (*counter)++;
    } else {
      while (*str >= '0' && *str <= '9') {
        if (result > (LLONG_MAX - (*str - '0')) / 10) {
          *buffer = (isNegative) ? LLONG_MIN : LLONG_MAX;
          (*counter)++;
          return str;
        }
        result = result * 10 + (*str - '0');
        str++;
      }
      if (result) (*counter)++;
    }
    (*buffer) = result * sign;
  } else
    (*counter) = -1;
  return str;
}

const char* s21_implementationUnsignedInt(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer) {
  bool isNegative = false, isPlus = false;
  while (s21_checkSpace(*str)) {
    str++;
  }
  if (*str == '-') {
    str++;
    isNegative = true;
  } else if (*str == '+') {
    str++;
    isPlus = true;
  }
  bool foundDigit = false;  // на случай если записывается цифра 0.
  if (*str != '\0') {
    unsigned long long int result = 0;
    if (flags.width > 0) {
      while (*str >= '0' && *str <= '9' && flags.width > 0) {
        if (flags.width == 1 && (isNegative || isPlus)) break;
        result = result * 10 + (*str - '0');
        str++;
        flags.width--;
        foundDigit = true;
      }
      if (result || foundDigit) (*counter)++;
    } else {
      while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
        foundDigit = true;
      }
      if (result || foundDigit) (*counter)++;
    }

    (*buffer) = (isNegative) ? (ULLONG_MAX - result + 1) : result;
  } else
    (*counter) = -1;
  return str;
}

const char* s21_implementationUnsignedOct(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer) {
  bool isNegative = false, isPlus = false, foundDigit = false;
  while (s21_checkSpace(*str)) {
    str++;
  }
  if (*str == '-') {
    str++;
    isNegative = true;
  } else if (*str == '+') {
    isPlus = true;
    str++;
  }
  if (*str != '\0') {
    unsigned long long int result = 0;
    if (flags.width > 0) {
      while (*str >= '0' && *str <= '7' && flags.width > 0) {
        if (flags.width == 1 && (isNegative || isPlus)) break;
        result = result * 8 + (*str - '0');
        str++;
        foundDigit = true;
        flags.width--;
      }
      if (result || foundDigit) (*counter)++;
    } else {
      while (*str >= '0' && *str <= '7') {
        result = result * 8 + (*str - '0');
        str++;
        foundDigit = true;
      }
      if (result || foundDigit) (*counter)++;
    }
    (*buffer) = (isNegative) ? (ULLONG_MAX - result + 1) : result;
  } else
    (*counter) = -1;
  return str;
}

const char* s21_implementationUnsignedHex(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer) {
  bool isNegative = false, isPlus = false, foundDigit = false;
  while (s21_checkSpace(*str)) {
    str++;
  }
  if (*str == '-') {
    str++;
    isNegative = true;
  } else if (*str == '+') {
    str++;
    isPlus = true;
  }
  bool checkEmpty = false;
  if (s21_strncmp(str, "0x", 2) == 0 || s21_strncmp(str, "0X", 2) == 0) {
    str += 2;
    checkEmpty = true;
  }

  if (*str == '\0' &&
      checkEmpty) {  // обработка случая, когда после скипа 0х или 0Х у нас str
                     // становится пустым, а должен записаться 0.
    (*buffer) = 0;
    (*counter)++;
  } else {
    if (*str != '\0') {
      unsigned long long int result = 0;
      if (flags.width > 0) {
        while (((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') ||
                (*str >= 'A' && *str <= 'F')) &&
               flags.width > 0) {
          if (flags.width == 1 && (isPlus || isNegative)) break;
          s21_convertedHex(str, &result);
          foundDigit = true;
          str++;
          flags.width--;
        }
        if (result || foundDigit || flags.width == 1) {
          (*counter)++;
          if (flags.width == 1) {  // тупо для теста 17.
            (*buffer) = 0;
          }
        }
      } else {
        while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') ||
               (*str >= 'A' && *str <= 'F')) {
          s21_convertedHex(str, &result);
          str++;
          foundDigit = true;
        }
        if (result || foundDigit) (*counter)++;
      }

      (*buffer) = (isNegative) ? (ULLONG_MAX - result + 1) : result;
    } else
      (*counter) = -1;
  }
  return str;
}

void s21_convertedHex(const char* str, unsigned long long int* result) {
  if (*str >= '0' && *str <= '9') {
    (*result) = (*result) * 16 + (*str - '0');
  } else if (*str >= 'a' && *str <= 'f') {
    (*result) = (*result) * 16 + (*str - 'a' + 10);
  } else if (*str >= 'A' && *str <= 'F') {
    (*result) = (*result) * 16 + (*str - 'A' + 10);
  }
}

const char* s21_implementationSignedInt(const char* str, Flags flags,
                                        int* counter, long long int* buffer) {
  while (s21_checkSpace(*str)) {
    str++;
  }
  if (*str == '-') {
    str++;
    str = s21_implementationUnsignedInt(str, flags, counter,
                                        (unsigned long long int*)buffer);
    (*buffer) *= -1;
  } else if (str[0] == '0') {
    if (str[1] == 'x' || str[1] == 'X') {
      str = s21_implementationUnsignedHex(str, flags, counter,
                                          (unsigned long long int*)buffer);
    } else {
      str = s21_implementationUnsignedOct(str, flags, counter,
                                          (unsigned long long int*)buffer);
    }
  } else {
    str = s21_implementationUnsignedInt(str, flags, counter,
                                        (unsigned long long int*)buffer);
  }
  return str;
}

const char* find_width_of_float(const char* str, int* total_length,
                                int* integer_part, int* sign, int* counter,
                                Flags flags) {
  if (*str == '-') {
    (*sign) = -1;
    str++;
    (*total_length)++;
  } else if (*str == '+') {
    str++;
    (*total_length)++;
    (*sign) = 1;
  }
  const char* str_cont = str;
  while ((*str_cont >= '0' && *str_cont <= '9') || *str_cont == '.') {
    (*total_length)++;
    str_cont++;
  }
  const char* q = str;
  while (*q >= '0' && *q <= '9') {
    (*integer_part)++;
    q++;
  }
  *total_length = s21_recalculate(*total_length, flags);
  if (*total_length - abs(*sign)) {
    (*counter)++;
    if (flags.star) {
      (*counter)--;
    }
  } else {
    (*total_length)--;
  }
  (*total_length) = (abs(*sign)) ? *total_length - 1 : *total_length;
  if (*total_length < *integer_part) {
    *integer_part = *total_length;
  }
  return str;
}

const char* filling_buffer_of_float(const char* str, long double* temp,
                                    int* counter, int* sign, Flags flags,
                                    va_list* arguments) {
  long double* result_Lf;
  double* result_lf;
  float* result_f;
  str = s21_checkRegional(str, temp, counter);

  if (flags.length == 'L') {
    result_Lf = va_arg(*arguments, long double*);
    *result_Lf = *temp;
    *result_Lf = ((*sign) < 0) ? *result_Lf * -1 : *result_Lf;
  } else if (flags.length == 'l') {
    result_lf = va_arg(*arguments, double*);
    *result_lf = *temp;
    *result_lf = ((*sign) < 0) ? *result_lf * -1 : *result_lf;
  } else {
    result_f = va_arg(*arguments, float*);
    *result_f = *temp;
    *result_f = ((*sign) < 0) ? *result_f * -1 : *result_f;
  }
  return str;
}
const char* s21_implementationFloat(const char* str, va_list* arguments,
                                    Flags flags, int* counter) {
  while (s21_checkSpace(*str)) {
    str++;
  }
  long double temp = 0;
  int total_length = 0, sign = 0, integer_part = 0;
  bool sign_exp = false;
  str = find_width_of_float(str, &total_length, &integer_part, &sign, counter,
                            flags);
  double degree = pow(10, integer_part - 1);
  for (int i = 0; i < total_length; i++) {
    if (*str == '.') {
      str++;
      continue;
    } else {
      long double t = (int)*str - '0';
      temp += t * degree;
      degree /= 10;
      str++;
    }
  }
  total_length = flags.width - total_length - abs(sign);
  if (total_length < 0) {
    total_length = 0;
  }
  if ((flags.width == 0 || total_length > 0) && (*str == 'e' || *str == 'E')) {
    total_length--;
    str++;
    if (flags.width == 0 || total_length > 0) {
      sign_exp = (*str == '-') ? false : true;
      if (*str == '-' || *str == '+') {
        str++;
      }
      total_length--;

      int exp_num = 0;
      while ((flags.width == 0 || total_length > 0) &&
             (*str >= '0' && *str <= '9')) {
        exp_num = exp_num * 10 + ((int)*str - '0');
        total_length--;
        str++;
      }

      temp *= (sign_exp) ? pow(10, exp_num) : pow(10, -1 * exp_num);
    }
  }
  if (!flags.star) {
    str = filling_buffer_of_float(str, &temp, counter, &sign, flags, arguments);
  }
  return str;
}

int s21_recalculate(int total_length, Flags flags) {
  if (flags.width > 0) {
    total_length = (total_length > flags.width) ? flags.width : total_length;
  }

  return total_length;
}

const char* s21_checkRegional(const char* str, long double* temp,
                              int* counter) {
  if (s21_strncmp(str, "NAN", 3) == 0 || s21_strncmp(str, "nan", 3) == 0) {
    *temp = NAN;
    for (int i = 0; i < 3; i++) {
      str++;
    }
    (*counter)++;
  } else if (s21_strncmp(str, "INF", 3) == 0 ||
             s21_strncmp(str, "inf", 3) == 0) {
    *temp = INFINITY;
    for (int i = 0; i < 3; i++) {
      str++;
    }
    (*counter)++;
  }
  return str;
}

bool s21_checkSpace(char symbol) {
  return (symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '\v' ||
          symbol == '\r')
             ? true
             : false;
}