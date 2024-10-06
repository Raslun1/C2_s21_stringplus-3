#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void*)0)

typedef long unsigned s21_size_t;

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool hash;
  bool zero;
  bool dot;
  bool to_upper;
  bool is_negative;
  bool change_spec;  // from g to e
  bool star;

  int base;
  int width;
  int pow_e;
  int accuracy;
  int size;

  char precision;
  char length;
  char specificator;

} Flags;

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);
char* s21_strcpy(char* destptr, const char* srcptr);
char* s21_strcat(char* str1, const char* str2);

int s21_sprintf(char* str, const char* format, ...);

const char* get_flags(const char* format, Flags* f);
const char* get_params(const char* format, int* num, va_list* va);
const char* get_length(const char* format, Flags* f);
void specificator_tracking(Flags* f, char** buff, va_list va);

void implementation_of_s_specifiers(char** buff, va_list va, Flags* f);
void implementation_of_c_specifiers(char** buff, va_list va, Flags* f);
void implementation_of_unsigned_specifiers(char** buff, va_list va, Flags* f);
void implementation_of_float_specifiers(char** buff, va_list va, Flags* f);
long double preparation_of_e(long double num, Flags* f);
void preparation_of_g(long double elem, Flags* f);
void implementation_of_address_specifiers(char** buff, va_list va, Flags* f);
void implementation_of_int_specifiers(char** buff, va_list va, Flags* f);
void implementation_of_procent_specifiers(char** buff, Flags* f);

unsigned long long parse_to_unsigned(va_list va, Flags* f);
long long int parse_to_int(va_list va, Flags* f);
long double parse_to_double(va_list va, Flags* f);

void parameters_for_unsigned(unsigned long long elem, char* buff, Flags* f);
void parameters_for_float(char* buff, Flags* f);

int get_s21_size_to_s(char* string, Flags* f);
int get_s21_size_to_unsigned(unsigned long long elem, Flags* f);
int get_s21_size_to_float(long double elem, Flags* f);

int modified_parts_of_float(long double* elem, long double* integer,
                            long double* frac, Flags* f);
void flag_minus(char* buff, Flags* f);
void add_first_space(char* buff, Flags* f);
char convert_num_to_string(long long unsigned int elem, int base);
int get_length_unsigned(unsigned long long elem, Flags* f);
int whole_unsigned_to_string(unsigned long long elem, char* result_buff,
                             int base);
void whole_float_to_string(long double elem, char* buff, Flags* f);
void* toUpper(const char* str);

int s21_sscanf(const char* str, const char* format, ...);
const char* s21_settingFlags(const char* format, Flags* flags);
const char* s21_specifierTracking(const char* str_beginning, const char* str,
                                  const char* format, Flags flags,
                                  va_list* arguments, int* counter);
const char* s21_implementationChar(const char* str, int* counter, char* buffer,
                                   bool flag);
const char* s21_implementationString(const char* str, int* counter, int width,
                                     char* buffer);
const char* s21_implementationInt(const char* str, Flags flags, int* counter,
                                  long long int* buffer);
const char* s21_implementationUnsignedInt(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer);
const char* s21_implementationUnsignedOct(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer);
const char* s21_implementationUnsignedHex(const char* str, Flags flags,
                                          int* counter,
                                          unsigned long long int* buffer);
const char* s21_implementationAddress(const char* str, Flags flags,
                                      int* counter, void* buffer);
const char* s21_implementationN(const char* str_beginning, const char* str,
                                va_list* arguments);

void s21_convertedHex(const char* str, unsigned long long int* result);
const char* s21_implementationSignedInt(const char* str, Flags flags,
                                        int* counter, long long int* buffer);
const char* s21_implementationFloat(const char* str, va_list* arguments,
                                    Flags flags, int* counter);
const char* filling_buffer_of_float(const char* str, long double* temp,
                                    int* counter, int* sign, Flags flags,
                                    va_list* arguments);
const char* find_width_of_float(const char* str, int* total_length,
                                int* integer_part, int* sign, int* counter,
                                Flags flags);
int s21_recalculate(int total_length, Flags flags);
const char* s21_checkRegional(const char* str, long double* temp, int* counter);
bool s21_checkSpace(char symbol);

void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_trim(const char* src, const char* trim_chars);
bool s21_checkTrim(const char* trim_chars, char symbol);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
