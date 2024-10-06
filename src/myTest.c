#include <check.h>
#include <string.h>

#include "s21_string.h"

#define BUFF_SIZE 4096

/***************************** TEST memchr
 * **************************************************/

START_TEST(test_memchr_1) {
  char s21_str[] = "";
  char s21_c = '\0';
  char str[] = "";
  char c = '\0';
  s21_size_t n = 0;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_2) {
  char s21_str[] = "someIntellectualText";
  char s21_c = '\0';
  char str[] = "someIntellectualText";
  char c = '\0';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_3) {
  char s21_str[] = "hello";
  char s21_c = 'H';
  char str[] = "hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_4) {
  char s21_str[] = "Hello";
  char s21_c = 'H';
  char str[] = "Hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_5) {
  char s21_str[] = "hello";
  char s21_c = 'o';
  char str[] = "hello";
  char c = 'o';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_6) {
  char s21_str[] = "hel3523522lo";
  char s21_c = '2';
  char str[] = "hel3523522lo";
  char c = '2';
  s21_size_t n = 10;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

/***************************** TEST memcmp
 * **************************************************/

START_TEST(test_memcmp_1) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_3) {
  const char str1[] = "123abc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_4) {
  const char str1[] = "012345678901234567890";
  const char str2[] = "012345678901234567891";
  s21_size_t n = 20;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_5) {
  const char str1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory "
      "areas s1 and s2.";
  const char str2[] =
      "The memcmp() function compares the second n bytes (each interpreted as "
      "unsigned char) of the memory "
      "areas s1 and s2.";
  s21_size_t n = 115;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_6) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_7) {
  const char str1[] = "142252552";
  const char str2[] = "142252111";
  s21_size_t n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

/***************************** TEST memcpy
 * **************************************************/

START_TEST(test_memcpy_1) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_2) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_3) {
  char s21_dest[25] = "Hello";
  const char s21_src[] = "zzzzz_world";
  const char src[] = "zzzzz_world";
  char dest[25] = "Hello";
  s21_size_t n = 6;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_4) {
  char s21_dest[25] = "";
  const char s21_src[] = "Hello_world";
  const char src[] = "Hello_world";
  char dest[25] = "";
  s21_size_t n = 12;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_5) {
  char s21_dest[] = "Hello, World!";
  const char s21_src[] = "Good";
  const char src[] = "Good";
  char dest[] = "Hello, World!";
  s21_size_t n = 4;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_6) {
  char s21_dest[] = "6259\250742";
  const char s21_src[] = ".com";
  const char src[] = ".com";
  char dest[] = "6259\250742";
  s21_size_t n = 4;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_7) {
  char s21_dest[] = "Helloy Mir";
  const char s21_src[] = "Manera_krytit_mir";
  const char src[] = "Manera_krytit_mir";
  char dest[] = "Helloy Mir";
  s21_size_t n = 7;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_memcpy_8) {
  char s21_dest[] = "746248268";
  const char s21_src[] = "hello";
  const char src[] = "hello";
  char dest[] = "746248268";
  s21_size_t n = 7;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

/***************************** TEST memset
 * ***************************************************/

START_TEST(s21_memset_1) {
  s21_size_t n1 = 6;
  int c1 = '7';
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(s21_memset_2) {
  s21_size_t n2 = 4;
  int c2 = '4';
  char b2[1024] = " BEST!!";
  char b22[1024] = " BEST!!";
  ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(s21_memset_3) {
  s21_size_t n3 = 6;
  int c3 = '3';
  char b3[1024] = " LUGANO!";
  char b33[1024] = " LUGANO!";
  ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST
START_TEST(memset_aboba_test) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_zero_byte) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_empty) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_sim) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'A';
  s21_size_t n_byte = 3;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_num) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_long_string) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

/***************************** TEST strchr
 * **************************************************/

START_TEST(test_strchr_1) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_2) {
  char str[] = "hellell56o";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// START_TEST(test_strchr_3) {
//   char str[] = "";
//   int c = '\0';

//   ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
// }
// END_TEST

START_TEST(test_strchr_4) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_5) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_6) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_strchr_7) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

/***************************** TEST strcspn
 * *************************************************/

START_TEST(s21_strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(s21_strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(s21_strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(strcspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111"
      "11111111111111111111113";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

/***************************** TEST strerror
 * **************************************************/

START_TEST(s21_strerror_1) {
  int errnum = 0;
  char *result = s21_strerror(errnum);
  char *original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
  // free(original_result);
}

START_TEST(s21_strerror_2) {
  int errnum = 5;
  char *result = s21_strerror(errnum);
  char *original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(s21_strerror_3) {
  int errnum = 8;
  char *result = s21_strerror(errnum);
  char *original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(s21_strerror_4) {
  int errnum = 108;
  char *result = s21_strerror(errnum);
  char *original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(s21_strerror_5) {
  int errnum = -1;
  char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, "Unknown error -1");
  free(result);
}

START_TEST(s21_strerror_6) {
  int errnum = 200;
  char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, "Unknown error 200");
  free(result);
}

START_TEST(s21_strerror_7) {
  int errnum = 300;
  char *result = s21_strerror(errnum);
  ck_assert_str_eq(result, "Unknown error 300");
  free(result);
}

/***************************** TEST strlen
 * **************************************************/

START_TEST(s21_strlen1) {
  char str[] = "hellell56o";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen2) {
  char str[] = "";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen3) {
  char str[] = "1";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

/***************************** TEST strncat
 * **************************************************/

START_TEST(s21_strncat_1) {
  s21_size_t n1 = 2;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_strncat_2) {
  s21_size_t n2 = 2;
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strncat(b2, str_2_2, n2), s21_strncat(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_strncat_3) {
  s21_size_t n3 = 2;
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncat_all_empty) {
  char src[] = "";
  char res[] = "";
  char expected[] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_byte) {
  char src[] = "abosal";
  char res[10] = "";
  char expected[10] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_empty_src) {
  char src[] = "";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_cd_abosa) {
  char src[] = "abosal";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_string) {
  char src[] = "abosal";
  char res[25] = "koleka";
  char expected[25] = "koleka";
  s21_size_t n_byte = 6;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA2) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA3) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA4) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 10;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_char) {
  char src[] = "\0";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

/***************************** TEST strncmp
 * **************************************************/

START_TEST(s21_strncmp1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp2) {
  char str1[] = "Hell";
  char str2[] = "Hello";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp3) {
  char str1[] = "Hello";
  char str2[] = "Hell";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp4) {
  char str1[] = "Hello";
  char str2[] = "Hello, World!";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp5) {
  char str1[] = "Hello";
  char str2[] = "Hell";
  int n = 0;

  for (int i = 0; i <= n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp6) {
  char str1[] = "\0";
  char str2[] = "Hell";
  int n = sizeof(str2);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp7) {
  char str1[] = "\0";
  char str2[] = "\0";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(s21_strncmp8) {
  char str1[] = "Hello!";
  char str2[] = "\0";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

/***************************** TEST strncpy
 * **************************************************/

START_TEST(s21_strncpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_strncpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "1111111111";
  char b22[1024] = "1111111111";
  char str_2_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_strncpy_3) {
  s21_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncpy_empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

/***************************** TEST strpbrk
 * **************************************************/

START_TEST(s21_strpbrk1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk3) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk4) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk5) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk6) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk7) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk8) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

/***************************** TEST strrchr
 * **************************************************/

START_TEST(s21_strrchr1) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr2) {
  char str[] = "hellell556o";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr4) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr5) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr6) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr7) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

/***************************** TEST strstr
 * **************************************************/

START_TEST(strstr1) {
  char haystack[] = "";
  char needle[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr2) {
  char haystack[] = "hellello";
  char needle[] = "el";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr3) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr4) {
  char haystack[] = "Some meaningless text";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr5) {
  char haystack[] = "Hello World";
  char needle[] = "World";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr6) {
  char haystack[] = "i need this text";
  char needle[] = "sorry";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr7) {
  char haystack[] = "Hello World";
  char needle[] = "world";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr8) {
  char haystack[] = "Hi";
  char needle[] = "i";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

/***************************** TEST strtok
 * **************************************************/
START_TEST(s21_strtok1) {
  char s21_str[] = "Maecenas++mollis_*_!malesuada massa=======vitae";
  char str[] = "Maecenas++mollis__!malesuada massa=======vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok2) {
  char s21_str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  char str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok3) {
  char s21_str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae";
  char str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae*";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok4) {
  char s21_str[] = "MaecenasmollisMalesuadaMassaVitae";
  char str[] = "MaecenasmollisMalesuadaMassaVitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok6) {
  char s21_str[] = "Maece+*+nasmollis    !malesu     ada=massa___vitae";
  char str[] = "Maece++nasmollis    !malesu     ada=massa___vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok7) {
  char s21_str[] = "!M+*+N***L M=M_F_V*H";
  char str[] = "!M+*+N***L M=M_F_V*H";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(s21_strtok8) {
  char s21_str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  char str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

/******************** Test sprintf c ******************************8*/

START_TEST(test_sprintf_c_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf_c_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/******************** Test sprintf s ******************************8*/

START_TEST(test_sprintf_s_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] =
      "%0.0s %1.0s %2.0s %3.0s %4.0s %5.0s %6.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *string = s21_NULL;
  ck_assert_int_eq(
      sprintf(str1, format, string, string, string, string, string, string,
              string, string, string, string, string, string),
      s21_sprintf(str2, format, string, string, string, string, string, string,
                  string, string, string, string, string, string));
  ck_assert_str_eq(str1, str2);
}

START_TEST(test_sprintf_s_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%*sTEST%-*sTEST%*.*sTEST%.*s";
  char *string1 = "qwer", *string2 = "asdf", *string3 = "zcxv",
       *string4 = "tui";
  int v1 = 2, v2 = 5, v3 = 4, v4 = 6, v5 = 7;
  ck_assert_int_eq(sprintf(str1, format, v1, string1, v2, string2, v3, v4,
                           string3, v5, string4),
                   s21_sprintf(str2, format, v1, string1, v2, string2, v3, v4,
                               string3, v5, string4));
  ck_assert_str_eq(str1, str2);
}

START_TEST(test_sprintf_s_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  const char *format = "%3s Test %5s Test %10s";
  char *string1 = "Wowowow abc", *string2 = "hello, World",
       *string3 = "GOGOGOGO";

  ck_assert_int_eq(sprintf(str1, format, string1, string2, string3),
                   s21_sprintf(str2, format, string1, string2, string3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_4) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  const char *format = "%0s Test %0.s Test %0.0s Test %0s Test %.s";
  char *string1 = "Aabasd", *string2 = "sgslsg AAA", *string3 = "afllsg a!!",
       *string4 = "Hello, world!!", *string5 = "jnfksnks afaf-";

  ck_assert_int_eq(
      sprintf(str1, format, string1, string2, string3, string4, string5),
      s21_sprintf(str2, format, string1, string2, string3, string4, string5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/******************** Test sprintf d || i ******************************8*/

START_TEST(test_sprintf_d_i_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_13) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_i_14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/******************** Test sprintf u || o || x || X
 * ******************************8*/

START_TEST(test_sprintf_u_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/***************************** TEST sprintf p
 * **************************************************/

START_TEST(test_sprintf_p_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = s21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p Test %p Test %p";
  char *ptr1 = "0p7a4", *ptr2 = "0p91832ba43f", *ptr3 = "0p3123";

  ck_assert_int_eq(sprintf(str1, format, ptr1, ptr2, ptr3),
                   s21_sprintf(str2, format, ptr1, ptr2, ptr3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_6) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p GOD %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_7) {
  char str1[100];
  char str2[100];
  char *str3 = "%3p Test %5p Test %12p";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_procent_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%%"), sprintf(str2, "%%"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_procent_2) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_procent_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

/***************************** TEST sprintf f || g || G || e || G
 * **************************************************/

START_TEST(test_sprintf_f_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.10Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf_e_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_13) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

/***************************** TEST sscanf c
 * **************************************************/

START_TEST(test_sscanf_c_1) {
  char *str = "Hello my dear friend, how are you?";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);

  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_2) {
  char *str = "walderhu";
  char buff1, buff2, buff1_s21, buff2_s21;
  sscanf(str, "%c%c", &buff1, &buff2);
  s21_sscanf(str, "%c%c", &buff1_s21, &buff2_s21);
  ck_assert_int_eq(buff1, buff1_s21);
  ck_assert_int_eq(buff2, buff2_s21);
}
END_TEST

START_TEST(test_sscanf_c_3) {
  char *str = "163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_4) {
  char *str = "   163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_5) {
  char *str = "?163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_6) {
  char *str = "___163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_7) {
  char *str = "\t163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_8) {
  char *str = "\r163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_9) {
  char *str = "f163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_10) {
  char *str = "\n163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_c_11) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_sscanf_c_12) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_sscanf_c_13) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(test_sscanf_c_14) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  s21_sscanf(str, format, &c11, &c12, &c13);
  sscanf(str, format, &c21, &c22, &c23);
  // ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(test_sscanf_c_15) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(test_sscanf_c_16) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_17) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_18) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_19) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_20) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_21) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_22) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_23) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_c_24) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_c_25) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

/***************************** TEST sscanf s
 * **************************************************/

START_TEST(test_sscanf_s_1) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_2) {
  char *str = "   hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%4s", original);
  int16_t res2 = s21_sscanf(str, "%4s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_3) {
  char *str = "walderhu\tworld";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_4) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%3s", original);
  int16_t res2 = s21_sscanf(str, "%3s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_5) {
  char *str = "   \t163";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_6) {
  char str[] = "hello walderhu";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  char specifier[] = "%s%s";

  int16_t res1 = sscanf(str, specifier, original1, original2);
  int16_t res2 = s21_sscanf(str, specifier, replica1, replica2);
  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_sscanf_s_7) {
  char str[] = "hello    \twalderhu";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  char specifier[] = "%s%s";

  int16_t res1 = sscanf(str, specifier, original1, original2);
  int16_t res2 = s21_sscanf(str, specifier, replica1, replica2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[0], replica2[0]);
}
END_TEST

START_TEST(test_sscanf_s_8) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_9) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_10) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  int16_t res1 = sscanf(str, "%10s", original);
  int16_t res2 = s21_sscanf(str, "%10s", replica);
  ck_assert_int_eq(res1, res2);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_sscanf_s_11) {
  char *str = "Aboba Floppa Keppa Shleppa Anuroba";

  char s1[strlen(str)];
  char s2[strlen(str)];
  char s3[strlen(str)];
  char s4[strlen(str)];

  char s5[strlen(str)];
  char s6[strlen(str)];
  char s7[strlen(str)];
  char s8[strlen(str)];

  int16_t res1 = s21_sscanf(str, "%s %s %s %s", s1, s2, s3, s4);
  int16_t res2 = sscanf(str, "%s %s %s %s", s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_sscanf_s_12) {
  char *str = "aboba\tshlepa\tasdfasdf\tasdfasdf";

  char s1[strlen(str)];
  char s2[strlen(str)];
  char s3[strlen(str)];
  char s4[strlen(str)];

  char s5[strlen(str)];
  char s6[strlen(str)];
  char s7[strlen(str)];
  char s8[strlen(str)];

  int16_t res1 = s21_sscanf(str, "%s%s%s%s", s1, s2, s3, s4);
  int16_t res2 = sscanf(str, "%s%s%s%s", s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_sscanf_s_13) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_sscanf_s_14) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_sscanf_s_15) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(test_sscanf_s_16) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

/***************************** TEST sscanf d
 * **************************************************/

START_TEST(test_sscanf_d_1) {
  char *str = "163.5";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_2) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_3) {
  char *str = "16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_4) {
  char *str = "16.3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_5) {
  char *str = "\t16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_6) {
  char *str = "       my16 3";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_7) {
  char *str = "\r16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_8) {
  char *str = "0x16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_9) {
  char *str = "432416 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_10) {
  char *str = "136 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_d_11) {
  char format[] = "%hd";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_12) {
  char format[] = "%hd";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_13) {
  char format[] = "%hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_14) {
  char format[] = "%3hd";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_15) {
  char format[] = "%4hd";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_16) {
  char format[] = "%10hd";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_17) {
  char format[] = "%1hd";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  s21_sscanf(str, format, &d1);
  sscanf(str, format, &d2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_18) {
  char format[] = "%3hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_19) {
  char format[] = "%4hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_20) {
  char format[] = "%10hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_21) {
  char format[] = "%1hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_22) {
  char format[] = "%*1hd";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_23) {
  char format[] = "%*hd";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_24) {
  char format[] = "%hhd";
  char str[] = "2147483647";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_25) {
  char format[] = "%hhd";
  char str[] = "+2147483648";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_26) {
  char format[] = "%hhd";
  char str[] = "214743483648";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_27) {
  char format[] = "%hhd";
  char str[] = "-2147483648";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_28) {
  char format[] = "%hhd";
  char str[] = "-2147483649";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_29) {
  char format[] = "%hhd";
  char str[] = "-214748364239";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_30) {
  char format[] = "%hhd";
  char str[] = "-9223372036854775808";
  signed char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_31) {
  char format[] = "%d";
  char str[] = " ";
  signed char p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(p1, p2);
}
END_TEST

START_TEST(test_sscanf_d_32) {
  char format[] = "%d";
  char str[] = "     ";
  signed char p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(p1, p2);
}
END_TEST

START_TEST(test_sscanf_d_33) {
  char format[] = "%d";
  char str[] = "\n";
  signed char p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_d_34) {
  char format[] = "%d";
  char str[] = "\t";
  signed char p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_d_35) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  signed char p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(p1, p2);
}
END_TEST

START_TEST(test_sscanf_d_36) {
  char format[] = "%d";
  char str[] = "123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_37) {
  char format[] = "%d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_38) {
  char format[] = "%d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_39) {
  char format[] = "%3d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_40) {
  char format[] = "%4d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_41) {
  char format[] = "%10d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_42) {
  char format[] = "%1d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_43) {
  char format[] = "%3d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_44) {
  char format[] = "%4d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_45) {
  char format[] = "%10d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_46) {
  char format[] = "%1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_47) {
  char format[] = "%*1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_48) {
  char format[] = "%*d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_49) {
  char format[] = "%d";
  char str[] = "2147483647";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_50) {
  char format[] = "%d";
  char str[] = "+2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_51) {
  char format[] = "%d";
  char str[] = "214743483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_52) {
  char format[] = "%d";
  char str[] = "-2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_53) {
  char format[] = "%d";
  char str[] = "-2147483649";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_54) {
  char format[] = "%d";
  char str[] = "-214748364239";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_55) {
  char format[] = "%d";
  char str[] = "−9223372036854775808";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_56) {
  char format[] = "%d";
  char str[] = "−9223372036854775809";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_57) {
  char format[] = "%d";
  char str[] = "−922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_58) {
  char format[] = "%d";
  char str[] = "9223372036854775807";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_59) {
  char format[] = "%d";
  char str[] = "2737328525285295628";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_60) {
  char format[] = "%d";
  char str[] = "922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_61) {
  char format[] = "%ld";
  char str[] = "123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_62) {
  char format[] = "%ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_63) {
  char format[] = "%ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_64) {
  char format[] = "%3ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_65) {
  char format[] = "%4ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_66) {
  char format[] = "%10ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_67) {
  char format[] = "%1ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_68) {
  char format[] = "%3ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_69) {
  char format[] = "%4ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_70) {
  char format[] = "%10ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_71) {
  char format[] = "%1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_72) {
  char format[] = "%*1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_73) {
  char format[] = "%*ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_74) {
  char format[] = "%ld";
  char str[] = "2147483647";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_75) {
  char format[] = "%ld";
  char str[] = "+2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_76) {
  char format[] = "%ld";
  char str[] = "214743483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_77) {
  char format[] = "%ld";
  char str[] = "-2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_78) {
  char format[] = "%ld";
  char str[] = "-2147483649";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_79) {
  char format[] = "%ld";
  char str[] = "-214748364239";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_80) {
  char format[] = "%ld";
  char str[] = "−9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_81) {
  char format[] = "%ld";
  char str[] = "−9223372036854775809";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_82) {
  char format[] = "%ld";
  char str[] = "−922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_83) {
  char format[] = "%ld";
  char str[] = "9223372036854775807";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_84) {
  char format[] = "%ld";
  char str[] = "9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_85) {
  char format[] = "%ld";
  char str[] = "922337203685477582309";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_86) {
  char format[] = "%lld";
  char str[] = "123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_87) {
  char format[] = "%lld";
  char str[] = "-123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_88) {
  char format[] = "%lld";
  char str[] = "+123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_89) {
  char format[] = "%3lld";
  char str[] = "-123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_90) {
  char format[] = "%4lld";
  char str[] = "-123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_91) {
  char format[] = "%10ld";
  char str[] = "-123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_92) {
  char format[] = "%1ld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_93) {
  char format[] = "%3ld";
  char str[] = "+123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_94) {
  char format[] = "%4ld";
  char str[] = "+123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_95) {
  char format[] = "%10ld";
  char str[] = "+123";
  long long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_96) {
  char format[] = "%1lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_97) {
  char format[] = "%*1lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_98) {
  char format[] = "%*lld";
  char str[] = "123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_99) {
  char format[] = "%ld";
  char str[] = "2147483647";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_100) {
  char format[] = "%ld";
  char str[] = "+2147483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_101) {
  char format[] = "%ld";
  char str[] = "214743483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_102) {
  char format[] = "%ld";
  char str[] = "-2147483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_103) {
  char format[] = "%ld";
  char str[] = "-2147483649";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_104) {
  char format[] = "%ld";
  char str[] = "-214748364239";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_105) {
  char format[] = "%lld";
  char str[] = "−9223372036854775808";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_106) {
  char format[] = "%lld";
  char str[] = "−9223372036854775809";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_107) {
  char format[] = "%lld";
  char str[] = "−922337203685477582309";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_108) {
  char format[] = "%ld";
  char str[] = "9223372036854775807";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_109) {
  char format[] = "%ld";
  char str[] = "9223372036854775808";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_110) {
  char format[] = "%ld";
  char str[] = "922337203685477582309";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_d_111) {
  char format[] = "%d%d";
  char str[] = "153 532";
  int d1 = 0, d11 = 0, d2 = 0, d22 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &d11);
  int16_t res2 = sscanf(str, format, &d2, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(d11, d22);
}

START_TEST(test_sscanf_d_112) {
  char format[] = "%d %d";
  char str[] = "Hello 123 abc 432";
  int d1 = 0, d11 = 0, d2 = 0, d22 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &d11);
  int16_t res2 = sscanf(str, format, &d2, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(d11, d22);
}

START_TEST(test_sscanf_d_113) {
  char format[] = "%10d %10d";
  char str[] = "Hello 123523 abc 4326343";
  int d1 = 0, d11 = 0, d2 = 0, d22 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &d11);
  int16_t res2 = sscanf(str, format, &d2, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(d11, d22);
}

START_TEST(test_sscanf_d_114) {
  char format[] = "%3d%3d";
  char str[] = "Hello 123523 abc 4326343";
  int d1 = 0, d11 = 0, d2 = 0, d22 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &d11);
  int16_t res2 = sscanf(str, format, &d2, &d22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(d11, d22);
}

// /*********************** TEST u||o||x||X********************************/

START_TEST(test_sscanf_u_1) {
  char *str = "0123";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_2) {
  char *str = "123";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_3) {
  char *str = "01239.3";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_4) {
  char *str = "walderhu 163";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_5) {
  char *str = "16 3";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_6) {
  char *str = "1a";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_7) {
  char *str = "0x1a";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_8) {
  char *str = "0x1ABC";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_9) {
  char *str = "01239.3";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_10) {
  char *str = "-123";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%u", &original);
  int16_t res2 = s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_11) {
  char *str = "1234568";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "%3u", &original);
  int16_t res2 = s21_sscanf(str, "%3u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_12) {
  char *str = "-123532";
  unsigned int original = 0, replica = 0;
  int16_t res1 = sscanf(str, "hello %1u", &original);
  int16_t res2 = s21_sscanf(str, "hello %1u", &replica);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_u_13) {
  const char str[] = "1337 233333331 5008 3000";
  const char fstr[] = "%1llu %2llu %5llu %4llu";

  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_u_14) {
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_u_15) {
  unsigned char a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%hhu %hhu %hhu %hhu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_u_16) {
  unsigned long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 -5008 3000";
  const char fstr[] = "%lu %lu %lu %lu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_o_1) {
  char *str = "0123";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_2) {
  char *str = "-123";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_3) {
  char *str = "01239";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_4) {
  char *str = "\t0";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_5) {
  char *str = "01AB";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_6) {
  char *str = "0x1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_7) {
  char *str = "\n0x1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_8) {
  char *str = "     \t0x1a";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_9) {
  char *str = "   3X1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_10) {
  char *str = "\t0X1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_o_11) {
  char format[] = "%hho%hho%hho";
  char str[] = "123 +198 -87";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_12) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +04 -1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_13) {
  char format[] = "%1ho %1ho %1ho";
  char str[] = "123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_14) {
  char format[] = "%2hho %2hho %2hho";
  char str[] = "+04 0123 -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_15) {
  char format[] = "%3hho %3hho %3hho";
  char str[] = "+04 0123 -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_16) {
  char format[] = "%*hho %*hho %*hho";
  char str[] = "0123 +04 -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_17) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_18) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +1564 -1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_19) {
  char format[] = "%1ho %1ho %1ho";
  char str[] = "123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_20) {
  char format[] = "%2ho %2ho %2ho";
  char str[] = "+04 0123 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_21) {
  char format[] = "%3ho %3ho %3ho";
  char str[] = "+04 0123 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_22) {
  char format[] = "%*ho %*ho %*ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_23) {
  char format[] = "%o%o%o";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_24) {
  char format[] = "%o%o%o";
  char str[] = "123 +1564 -1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_25) {
  char format[] = "%1o %1o %1o";
  char str[] = "123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_26) {
  char format[] = "%2o %2o %2o";
  char str[] = "+04 0123 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_27) {
  char format[] = "%3o %3o %3o";
  char str[] = "+04 0123 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_28) {
  char format[] = "%*o %*o %*o";
  char str[] = "+04 0123 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_29) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_30) {
  char format[] = "%lo%lo%lo";
  char str[] = "+04 0123 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_31) {
  char format[] = "%1lo %1lo %1lo";
  char str[] = "123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_32) {
  char format[] = "%2lo %2lo %2lo";
  char str[] = "+04 0123 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_33) {
  char format[] = "%3lo %3lo %3lo";
  char str[] = "+04 0123 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_34) {
  char format[] = "%*lo %*lo %*lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_35) {
  char format[] = "%llo%llo%llo";
  char str[] = "123 +198 -87";
  unsigned long long int d1, d2;
  unsigned long long int q1, q2;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_36) {
  char format[] = "%llo%llo%llo";
  char str[] = "+04 0123 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_37) {
  char format[] = "%1llo %1llo %1llo";
  char str[] = "123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_38) {
  char format[] = "%2llo %2llo %2llo";
  char str[] = "+04 0123 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_39) {
  char format[] = "%3llo %3llo %3llo";
  char str[] = "+04 0123 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_40) {
  char format[] = "%*llo %*llo %*llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_o_41) {
  char format[] = "%llo";
  char str[] = "18446744073709551619";
  unsigned long long int orig = 0, replica = 0;

  int16_t res1 = s21_sscanf(str, format, &replica);
  int16_t res2 = sscanf(str, format, &orig);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(orig, replica);
}
END_TEST

START_TEST(test_sscanf_x_1) {
  char *str = "1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_2) {
  char *str = "1as";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_3) {
  char *str = "1abc3";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_4) {
  char *str = "0";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_5) {
  char *str = "01ab";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_6) {
  char *str = "0x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_7) {
  char *str = "0x1a";
  unsigned int original1 = 0, replica1 = 0;
  unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%x%x", &original1, &original2);
  s21_sscanf(str, "%x%x", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_sscanf_x_8) {
  char *str = "0x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_9) {
  char *str = "   3x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_10) {
  char *str = "\t0X1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_x_11) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_12) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_13) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_x_14) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_15) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_16) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "123a +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_17) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_18) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "123a bc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_19) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_21) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_22) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_23) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_24) {
  const char str[] = "0X";
  const char fstr[] = "%X";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_25) {
  const char str[] = "";
  const char fstr[] = "%X";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_26) {
  unsigned int a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_27) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_28) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_29) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_30) {
  unsigned long long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%llX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_31) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_32) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_x_33) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_x_34) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_35) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_36) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_37) {
  uint32_t a1, a2;
  const char str[] = "f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_38) {
  uint32_t a1, a2;
  const char str[] = "0xfffffffffffffffffff";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_39) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_40) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_41) {
  const char str[] = "";
  const char fstr[] = "%x";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_42) {
  const char str[] = "qF";
  const char fstr[] = "%x";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_x_43) {
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%x";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_44) {
  const char str[] = "ff";
  const char fstr[] = "%hx";
  unsigned short a1 = 0, a2 = 0;
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_45) {
  unsigned long int a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%lx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_46) {
  unsigned long long int a1, a2;
  const char str[] = "faaaaaaaaaaaaf";
  const char fstr[] = "%llx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_47) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_48) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_x_49) {
  const char str[] = "tqwqpl";
  const char fstr[] = "%x";
  unsigned int a1 = 0, a2 = 0;
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_50) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_51) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_52) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_53) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sscanf_x_54) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_55) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_56) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_x_57) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_58) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_59) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_60) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_61) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1abc bc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_62) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_64) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_65) {
  char format[] = "%x%x%x";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_66) {
  char format[] = "%x%x%x";
  char str[] = "12a3 +156B4 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_67) {
  char format[] = "%x%x";
  char str[] = "0 +0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_x_68) {
  char format[] = "%x%x%x";
  char str[] = "0 -0XABC -0X";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_69) {
  char format[] = "%x%x%x";
  char str[] = "0abc4 -0XABC 0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_70) {
  char format[] = "%1x %1x %1x";
  char str[] = "1abc +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_71) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_72) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a123 bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_73) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bCc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_75) {
  char format[] = "%*x %*x %*x";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_76) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_77) {
  char format[] = "%lx%lx%lx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_78) {
  char format[] = "%lx%lx";
  char str[] = "0 +0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_x_79) {
  char format[] = "%lx%lx%lx";
  char str[] = "0 -0XABC -0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_80) {
  char format[] = "%lx%lx%lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_81) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1abc +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_82) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_83) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a123 bc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_84) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bCc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_86) {
  char format[] = "%*lx %*lx %*lx";
  char str[] = "0x123 +04 -372f3";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_87) {
  char format[] = "%llx%llx%llx";
  char str[] = "123 +198 -87";
  unsigned long long int d1, d2;
  unsigned long long int q1, q2;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_88) {
  char format[] = "%llx%llx%llx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_89) {
  char format[] = "%llx%llx";
  char str[] = "0 +0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_x_90) {
  char format[] = "%llx%llx%llx";
  char str[] = "0 -0XABC -0X";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_91) {
  char format[] = "%llx%llx%llx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_92) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1abc +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_93) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1a 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_94) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a123 bc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_95) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a bCc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_97) {
  char format[] = "%*llx %*llx %*llx";
  char str[] = "0x123 +04 -372f3";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_x_98) {
  char format[] = "%10llx %3llx %5llx";
  char str[] = "0x123 7fa123 763ffaa";

  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}

/************************************ TEST specifier i
 * *****************************/

START_TEST(test_sscanf_i_1) {
  char *str = "0123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_2) {
  char *str = "-123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_3) {
  char *str = "01239.3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}

START_TEST(test_sscanf_i_4) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_5) {
  char *str = "16 3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_6) {
  char *str = "1a";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_7) {
  char *str = "0x1a";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_8) {
  char *str = "0x1ABC";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_9) {
  char *str = "01239.3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_10) {
  char *str = "-123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_i_11) {
  char format[] = "%hhi%hhi%hhi";
  char str[] = "123 +198 -87";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_12) {
  char format[] = "%hhi %hhi %hhi";
  char str[] = "123 +198 -87";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_13) {
  char format[] = "%1hhi %1hhi %1hhi";
  char str[] = "13 +137 -8";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_14) {
  char format[] = "%2hhi %2hhi %2hhi";
  char str[] = "13 +137 -8";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_15) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
  int d1 = 0, d2 = 0;
  int q1 = 0, q2 = 0;
  int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_16) {
  char format[] = "%30hhi %24hhi %21hhi";
  char str[] = "13 +137 -8";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_17) {
  char format[] = "%hhi %hhi %hhi %hhi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;
  unsigned char w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_i_18) {
  char format[] = "%1hhi %1hhi %1hhi";
  char str[] = "013 +0137 -08";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_19) {
  char format[] = "%2hhi %2hhi %2hhi";
  char str[] = "013 +0137 -08";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_20) {
  char format[] = "%3hhi %3hhi %3hhi";
  char str[] = "013 +0137 -08";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_i_21) {
  char format[] = "%hhi %hhi %hhi %hhi";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1, z2;
  unsigned char w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

/**************************************** TEST sscanf f || e || E || g || G
 * **************************/

START_TEST(test_sscanf_f_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_f_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_f_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_f_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_f_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_f_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_f_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_f_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(test_sscanf_f_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_16) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_f_17) {
  char *str = "3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_18) {
  char *str = "-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_19) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_20) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_21) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_22) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_23) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_24) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_25) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_f_26) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_1) {
  char *str = "3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_2) {
  char *str = "-3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_3) {
  char *str = "     -3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_4) {
  char *str = "\t-3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_5) {
  char *str = "\r-3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_6) {
  char *str = "hell\r-3.1451";
  long double original = 0, replica = 0;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_7) {
  char *str = "hell\r-3.1451";
  long double original = 0, replica = 0;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_8) {
  char *str = "0xhell\r-3.1451";
  long double original = 0, replica = 0;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_9) {
  char *str = "1hell\r-3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_10) {
  char *str = "1,33333 hell\r-3.1451";
  long double original, replica;
  sscanf(str, "%Lf", &original);
  s21_sscanf(str, "%Lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_1) {
  char *str = "3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_2) {
  char *str = "-3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_3) {
  char *str = "     -3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_4) {
  char *str = "\t-3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_5) {
  char *str = "\r-3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_6) {
  char *str = "hell\r-3.1451";
  double original = 0, replica = 0;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_7) {
  char *str = "hell\r-3.1451";
  double original = 0, replica = 0;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_8) {
  char *str = "0xhell\r-3.1451";
  double original = 0, replica = 0;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_9) {
  char *str = "1hell\r-3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lf_10) {
  char *str = "1,33333 hell\r-3.1451";
  double original, replica;
  sscanf(str, "%lf", &original);
  s21_sscanf(str, "%lf", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_sscanf_e_1) {
  char *str = "3.141500e-11";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_2) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_3) {
  char *str = "     -3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_4) {
  char *str = "\t-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_5) {
  char *str = "\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_7) {
  char *str = "3.141500E+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_11) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_sscanf_e_12) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_13) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_14) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_15) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_16) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_17) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_18) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_19) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_e_20) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_sscanf_g_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_11) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_sscanf_g_12) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_13) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_14) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_15) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_16) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_17) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_18) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_19) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_sscanf_g_20) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_percent_1) {
  char str[] = "Привет!%";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%s%d";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_percent_2) {
  char str[] = "Значение: 42%, Символ: %";
  int value1, value2;
  char symbol1, symbol2;

  sscanf(str, "Значение: %d%%, Символ: %c", &value1, &symbol1);
  s21_sscanf(str, "Значение: %d%%, Символ: %c", &value2, &symbol2);
  ck_assert_int_eq(symbol1, symbol2);
}
END_TEST

START_TEST(test_p_1) {
  char addressStr[] = "0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_2) {
  char addressStr[] = "   0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_3) {
  char addressStr[] = "\t0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_4) {
  char addressStr[] = "\r0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_5) {
  char addressStr[] = "des 0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_6) {
  char addressStr[] = "\v0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_8) {
  char addressStr[] = "\n0x7abbbbbbb";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_9) {
  char addressStr[] = "0x7fff5fffffbf20";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}

START_TEST(test_n_1) {
  char *str = "163";
  int digin, n;
  sscanf(str, "%d%n", &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, "%d%n", &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_2) {
  char *str = "163 ";
  int digin, n;
  sscanf(str, "%d %n", &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, "%d %n", &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_3) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_4) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_5) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_6) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d          %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_7) {
  char *str = "163                              ";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_8) {
  char *str = "163\t";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_9) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_10) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_to_upper_1) {
  char *sstr = "hello";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}

START_TEST(test_to_upper_2) {
  char *sstr = "hello world";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}

START_TEST(test_to_upper_3) {
  char *sstr = "hello world!!";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO WORLD!!");
  free(result);
}

START_TEST(test_to_upper_4) {
  char *sstr = "hello)(%world!!!";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO)(%WORLD!!!");
  free(result);
}

START_TEST(test_to_upper_5) {
  char *sstr = "hellooo";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLOOO");
  free(result);
}

START_TEST(test_to_upper_6) {
  char *sstr = "upperTO";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "UPPERTO");
  free(result);
}

START_TEST(test_to_upper_7) {
  char *sstr = "123upperTO";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "123UPPERTO");
  free(result);
}

START_TEST(test_to_upper_8) {
  char *sstr = "123";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "123");
  free(result);
}

START_TEST(test_to_upper_9) {
  char *sstr = "upper123";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "UPPER123");
  free(result);
}

START_TEST(test_to_upper_10) {
  char *sstr = "098765";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "098765");
  free(result);
}

START_TEST(test_to_upper_11) {
  char *sstr = "1234567890qwertyuiop[]\';lkjhgfdsazxcvbnm,./";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "1234567890QWERTYUIOP[]\';LKJHGFDSAZXCVBNM,./");
  free(result);
}

START_TEST(test_to_upper_12) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_13) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_14) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_15) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_16) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_17) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_18) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_1) {
  char *sstr = "HELLO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello");
  free(result);
}

START_TEST(test_to_lower_2) {
  char *sstr = "HELLOWORLD";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "helloworld");
  free(result);
}

START_TEST(test_to_lower_3) {
  char *sstr = "HELLO WORLD!!!";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello world!!!");
  free(result);
}

START_TEST(test_to_lower_4) {
  char *sstr = "HELLO)(%WORLD!!!";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello)(%world!!!");
  free(result);
}

START_TEST(test_to_lower_5) {
  char *sstr = "hellooo";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hellooo");
  free(result);
}

START_TEST(test_to_lower_6) {
  char *sstr = "lowerTO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "lowerto");
  free(result);
}

START_TEST(test_to_lower_7) {
  char *sstr = "123lowerTO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "123lowerto");
  free(result);
}

START_TEST(test_to_lower_8) {
  char *sstr = "123";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "123");
  free(result);
}

START_TEST(test_to_lower_9) {
  char *sstr = "LOWER123";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "lower123");
  free(result);
}

START_TEST(test_to_lower_10) {
  char *sstr = "098765";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "098765");
  free(result);
}

START_TEST(test_to_lower_11) {
  char *sstr = "1234567890QWERTYUIOP[]\';LKJHGFDSAZXCVBNM,./";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "1234567890qwertyuiop[]\';lkjhgfdsazxcvbnm,./");
  free(result);
}

START_TEST(test_to_lower_12) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_13) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_14) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_15) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_16) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_17) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_18) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

END_TEST

START_TEST(test_trim_1) {
  const char *test_str = "+++Hello World!!!";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_2) {
  const char *test_str = "d29d27";
  const char *trim_chars = "";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "d29d27");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_3) {
  const char *test_str = "5v7,.Di3d dyry.:,5,";
  const char *trim_chars = "5,";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "v7,.Di3d dyry.:");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_4) {
  const char *test_str = "115.:,32ref3d  ";
  const char *trim_chars = " 1.";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "5.:,32ref3d");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_5) {
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(s21_NULL, trim_chars);
  ck_assert_ptr_eq(trimmed, s21_NULL);
}
END_TEST

START_TEST(test_trim_6) {
  const char *test_str = "";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_7) {
  const char *test_str = "Hello World";
  const char *trim_chars = "";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_8) {
  const char *test_str = "   Hello World   ";
  const char *trim_chars = " ";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_9) {
  const char *test_str = "+++!!!";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "");
  free(trimmed);
}
END_TEST

START_TEST(test_trim_11) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_12) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_13) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_14) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_15) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_16) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_17) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_18) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_19) {
  char s1[] = " wtf ";
  char *s3 = s21_NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_20) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_9) {
  char s1[] = "wtf";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_10) {
  char s1[] = "";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_11) {
  const char *src = "Hello, World!";
  const char *str = "beautiful ";
  s21_size_t start_index = 7;

  const char *expected = "Hello, beautiful World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_12) {
  const char *src = "World!";
  const char *str = "Hello, ";
  s21_size_t start_index = 0;

  const char *expected = "Hello, World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_13) {
  const char *src = "Hello, ";
  const char *str = "World!";
  s21_size_t start_index = 7;

  const char *expected = "Hello, World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_14) {
  const char *src = "";
  const char *str = "Hello";
  s21_size_t start_index = 0;

  const char *expected = "Hello";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_15) {
  const char *src = "Hello";
  const char *str = "";
  s21_size_t start_index = 3;

  const char *expected = "Hello";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_16) {
  const char *src = "Hello";
  const char *str = "";
  s21_size_t start_index = 10;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_insert_17) {
  const char *src = "Hello";
  const char *str = "World";
  s21_size_t start_index = -1;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

  /***************************** TEST memchr
   * **************************************************/
  tcase_add_test(tcase_core, test_memchr_1);
  tcase_add_test(tcase_core, test_memchr_2);
  tcase_add_test(tcase_core, test_memchr_3);
  tcase_add_test(tcase_core, test_memchr_4);
  tcase_add_test(tcase_core, test_memchr_5);
  tcase_add_test(tcase_core, test_memchr_6);

  /***************************** TEST memcmp
   * **************************************************/
  tcase_add_test(tcase_core, test_memcmp_1);
  tcase_add_test(tcase_core, test_memcmp_2);
  tcase_add_test(tcase_core, test_memcmp_3);
  tcase_add_test(tcase_core, test_memcmp_4);
  tcase_add_test(tcase_core, test_memcmp_5);
  tcase_add_test(tcase_core, test_memcmp_6);
  tcase_add_test(tcase_core, test_memcmp_7);

  /***************************** TEST memcpy
   * **************************************************/

  tcase_add_test(tcase_core, test_memcpy_1);
  tcase_add_test(tcase_core, test_memcpy_2);
  tcase_add_test(tcase_core, test_memcpy_3);
  tcase_add_test(tcase_core, test_memcpy_4);
  tcase_add_test(tcase_core, test_memcpy_5);
  tcase_add_test(tcase_core, test_memcpy_6);
  tcase_add_test(tcase_core, test_memcpy_7);
  tcase_add_test(tcase_core, test_memcpy_8);

  /***************************** TEST memset
   * **************************************************/
  tcase_add_test(tcase_core, s21_memset_1);
  tcase_add_test(tcase_core, s21_memset_2);
  tcase_add_test(tcase_core, s21_memset_3);
  tcase_add_test(tcase_core, memset_aboba_test);
  tcase_add_test(tcase_core, memset_zero_byte);
  tcase_add_test(tcase_core, memset_empty);
  tcase_add_test(tcase_core, memset_replace_on_register_sim);
  tcase_add_test(tcase_core, memset_replace_on_register_num);
  tcase_add_test(tcase_core, memset_long_string);

  /***************************** TEST strchr
   * **************************************************/

  tcase_add_test(tcase_core, test_strchr_1);
  tcase_add_test(tcase_core, test_strchr_2);
  // tcase_add_test(tcase_core, test_strchr_3);
  tcase_add_test(tcase_core, test_strchr_4);
  tcase_add_test(tcase_core, test_strchr_5);
  tcase_add_test(tcase_core, test_strchr_6);
  tcase_add_test(tcase_core, test_strchr_7);

  /***************************** TEST strcspn
   * **************************************************/

  tcase_add_test(tcase_core, s21_strcspn_1);
  tcase_add_test(tcase_core, s21_strcspn_2);
  tcase_add_test(tcase_core, s21_strcspn_3);
  tcase_add_test(tcase_core, strcspn_empty);
  tcase_add_test(tcase_core, strcspn_gora_);
  tcase_add_test(tcase_core, strcspn__gora);
  tcase_add_test(tcase_core, strcspn_any_register);
  tcase_add_test(tcase_core, strcspn_num_num);
  tcase_add_test(tcase_core, strcspn_long_num_num);
  tcase_add_test(tcase_core, strcspn_num_long_num);
  tcase_add_test(tcase_core, strcspn_any_num);
  tcase_add_test(tcase_core, strcspn_num_with_letter);
  tcase_add_test(tcase_core, strcspn_num_with_letter2);
  tcase_add_test(tcase_core, strcspn_basic_test);
  tcase_add_test(tcase_core, strcspn_any_sim);
  tcase_add_test(tcase_core, strcspn_upper_letter);
  tcase_add_test(tcase_core, strcspn_lower_letter);
  tcase_add_test(tcase_core, strcspn_not_uniq_sim);

  /***************************** TEST strerror
   * **************************************************/

  tcase_add_test(tcase_core, s21_strerror_1);
  tcase_add_test(tcase_core, s21_strerror_2);
  tcase_add_test(tcase_core, s21_strerror_3);
  tcase_add_test(tcase_core, s21_strerror_4);
  tcase_add_test(tcase_core, s21_strerror_5);
  tcase_add_test(tcase_core, s21_strerror_6);
  tcase_add_test(tcase_core, s21_strerror_7);

  /***************************** TEST strlen
   * **************************************************/

  tcase_add_test(tcase_core, s21_strlen1);
  tcase_add_test(tcase_core, s21_strlen2);
  tcase_add_test(tcase_core, s21_strlen3);

  /***************************** TEST strncat
   * **************************************************/

  tcase_add_test(tcase_core, s21_strncat_1);
  tcase_add_test(tcase_core, s21_strncat_2);
  tcase_add_test(tcase_core, s21_strncat_3);
  tcase_add_test(tcase_core, strncat_all_empty);
  tcase_add_test(tcase_core, strncat_zero_byte);
  tcase_add_test(tcase_core, strncat_empty_src);
  tcase_add_test(tcase_core, strncat_cd_abosa);
  tcase_add_test(tcase_core, strncat_string);
  tcase_add_test(tcase_core, strncat_BIGFLOPPA);
  tcase_add_test(tcase_core, strncat_BIGFLOPPA2);
  tcase_add_test(tcase_core, strncat_BIGFLOPPA3);
  tcase_add_test(tcase_core, strncat_BIGFLOPPA4);
  tcase_add_test(tcase_core, strncat_zero_char);

  /***************************** TEST strncmp
   * **************************************************/

  tcase_add_test(tcase_core, s21_strncmp1);
  tcase_add_test(tcase_core, s21_strncmp2);
  tcase_add_test(tcase_core, s21_strncmp3);
  tcase_add_test(tcase_core, s21_strncmp4);
  tcase_add_test(tcase_core, s21_strncmp5);
  tcase_add_test(tcase_core, s21_strncmp6);
  tcase_add_test(tcase_core, s21_strncmp7);
  tcase_add_test(tcase_core, s21_strncmp8);

  /***************************** TEST strncpy
   * **************************************************/

  tcase_add_test(tcase_core, s21_strncpy_1);
  tcase_add_test(tcase_core, s21_strncpy_2);
  tcase_add_test(tcase_core, s21_strncpy_3);
  tcase_add_test(tcase_core, strncpy_empty);
  tcase_add_test(tcase_core, strncpy_zero_byte);
  tcase_add_test(tcase_core, strncpy_empty_src);
  tcase_add_test(tcase_core, strncpy_one_byte);
  tcase_add_test(tcase_core, strncpy_two_byte);
  tcase_add_test(tcase_core, strncpy_string);

  /***************************** TEST strpbrk
   * **************************************************/

  tcase_add_test(tcase_core, s21_strpbrk1);
  tcase_add_test(tcase_core, s21_strpbrk2);
  tcase_add_test(tcase_core, s21_strpbrk3);
  tcase_add_test(tcase_core, s21_strpbrk4);
  tcase_add_test(tcase_core, s21_strpbrk5);
  tcase_add_test(tcase_core, s21_strpbrk6);
  tcase_add_test(tcase_core, s21_strpbrk7);
  tcase_add_test(tcase_core, s21_strpbrk8);

  /***************************** TEST strrchr
   * **************************************************/

  tcase_add_test(tcase_core, s21_strrchr1);
  tcase_add_test(tcase_core, s21_strrchr2);
  tcase_add_test(tcase_core, s21_strrchr4);
  tcase_add_test(tcase_core, s21_strrchr5);
  tcase_add_test(tcase_core, s21_strrchr6);
  tcase_add_test(tcase_core, s21_strrchr7);

  /***************************** TEST strstr
   * **************************************************/

  tcase_add_test(tcase_core, strstr1);
  tcase_add_test(tcase_core, strstr2);
  tcase_add_test(tcase_core, strstr3);
  tcase_add_test(tcase_core, strstr4);
  tcase_add_test(tcase_core, strstr5);
  tcase_add_test(tcase_core, strstr6);
  tcase_add_test(tcase_core, strstr7);
  tcase_add_test(tcase_core, strstr8);

  /***************************** TEST strtok
   * **************************************************/

  tcase_add_test(tcase_core, s21_strtok1);
  tcase_add_test(tcase_core, s21_strtok2);
  tcase_add_test(tcase_core, s21_strtok3);
  tcase_add_test(tcase_core, s21_strtok4);
  tcase_add_test(tcase_core, s21_strtok6);
  tcase_add_test(tcase_core, s21_strtok7);
  tcase_add_test(tcase_core, s21_strtok8);

  /***************************** TEST sprintf c
   * **************************************************/
  tcase_add_test(tcase_core, test_sprintf_c_1);
  tcase_add_test(tcase_core, test_sprintf_c_2);
  tcase_add_test(tcase_core, test_sprintf_c_3);
  tcase_add_test(tcase_core, test_sprintf_c_4);
  tcase_add_test(tcase_core, test_sprintf_c_5);
  tcase_add_test(tcase_core, test_sprintf_c_6);
  tcase_add_test(tcase_core, test_sprintf_c_7);
  tcase_add_test(tcase_core, test_sprintf_c_8);
  tcase_add_test(tcase_core, test_sprintf_c_9);

  /***************************** TEST sprintf s
   * **************************************************/
  tcase_add_test(tcase_core, test_sprintf_s_1);
  tcase_add_test(tcase_core, test_sprintf_s_2);
  tcase_add_test(tcase_core, test_sprintf_s_3);
  tcase_add_test(tcase_core, test_sprintf_s_4);
  tcase_add_test(tcase_core, test_sprintf_s_5);
  tcase_add_test(tcase_core, test_sprintf_s_6);
  tcase_add_test(tcase_core, test_sprintf_s_7);
  tcase_add_test(tcase_core, test_sprintf_s_8);

  /***************************** TEST sprintf d || i
   * **************************************************/

  tcase_add_test(tcase_core, test_sprintf_d_i_1);
  tcase_add_test(tcase_core, test_sprintf_d_i_2);
  tcase_add_test(tcase_core, test_sprintf_d_i_3);
  tcase_add_test(tcase_core, test_sprintf_d_i_4);
  tcase_add_test(tcase_core, test_sprintf_d_i_5);
  tcase_add_test(tcase_core, test_sprintf_d_i_6);
  tcase_add_test(tcase_core, test_sprintf_d_i_7);
  tcase_add_test(tcase_core, test_sprintf_d_i_8);
  tcase_add_test(tcase_core, test_sprintf_d_i_9);
  tcase_add_test(tcase_core, test_sprintf_d_i_10);
  tcase_add_test(tcase_core, test_sprintf_d_i_11);
  tcase_add_test(tcase_core, test_sprintf_d_i_12);
  tcase_add_test(tcase_core, test_sprintf_d_i_13);
  tcase_add_test(tcase_core, test_sprintf_d_i_14);

  /***************************** TEST sprintf u || o || x || X
   * **************************************************/
  tcase_add_test(tcase_core, test_sprintf_u_1);
  tcase_add_test(tcase_core, test_sprintf_u_2);
  tcase_add_test(tcase_core, test_sprintf_u_3);
  tcase_add_test(tcase_core, test_sprintf_u_4);
  tcase_add_test(tcase_core, test_sprintf_u_5);
  tcase_add_test(tcase_core, test_sprintf_u_6);
  tcase_add_test(tcase_core, test_sprintf_u_7);
  tcase_add_test(tcase_core, test_sprintf_u_8);
  tcase_add_test(tcase_core, test_sprintf_u_9);

  tcase_add_test(tcase_core, test_sprintf_o_1);
  tcase_add_test(tcase_core, test_sprintf_o_2);
  tcase_add_test(tcase_core, test_sprintf_o_3);
  tcase_add_test(tcase_core, test_sprintf_o_4);
  tcase_add_test(tcase_core, test_sprintf_o_5);
  tcase_add_test(tcase_core, test_sprintf_o_6);
  tcase_add_test(tcase_core, test_sprintf_o_7);
  tcase_add_test(tcase_core, test_sprintf_o_8);
  tcase_add_test(tcase_core, test_sprintf_o_9);

  tcase_add_test(tcase_core, test_sprintf_x_1);
  tcase_add_test(tcase_core, test_sprintf_x_2);
  tcase_add_test(tcase_core, test_sprintf_x_3);
  tcase_add_test(tcase_core, test_sprintf_x_4);
  tcase_add_test(tcase_core, test_sprintf_x_5);
  tcase_add_test(tcase_core, test_sprintf_x_6);
  tcase_add_test(tcase_core, test_sprintf_x_7);
  tcase_add_test(tcase_core, test_sprintf_x_8);
  tcase_add_test(tcase_core, test_sprintf_x_9);
  tcase_add_test(tcase_core, test_sprintf_x_10);
  tcase_add_test(tcase_core, test_sprintf_x_11);

  /***************************** TEST sprintf p
   * **************************************************/
  tcase_add_test(tcase_core, test_sprintf_p_1);
  tcase_add_test(tcase_core, test_sprintf_p_2);
  tcase_add_test(tcase_core, test_sprintf_p_3);
  tcase_add_test(tcase_core, test_sprintf_p_4);
  tcase_add_test(tcase_core, test_sprintf_p_5);
  tcase_add_test(tcase_core, test_sprintf_p_6);
  tcase_add_test(tcase_core, test_sprintf_p_7);
  tcase_add_test(tcase_core, test_sprintf_p_8);

  /***************************** TEST sprintf percent
   * **************************************************/
  tcase_add_test(tcase_core, test_sprintf_procent_1);
  tcase_add_test(tcase_core, test_sprintf_procent_2);
  tcase_add_test(tcase_core, test_sprintf_procent_3);

  /***************************** TEST sprintf f || g || G || e || G
   * **************************************************/

  tcase_add_test(tcase_core, test_sprintf_f_1);
  tcase_add_test(tcase_core, test_sprintf_f_2);
  tcase_add_test(tcase_core, test_sprintf_f_3);
  tcase_add_test(tcase_core, test_sprintf_f_4);
  tcase_add_test(tcase_core, test_sprintf_f_5);
  tcase_add_test(tcase_core, test_sprintf_f_6);
  tcase_add_test(tcase_core, test_sprintf_f_7);
  tcase_add_test(tcase_core, test_sprintf_f_8);
  tcase_add_test(tcase_core, test_sprintf_f_9);
  tcase_add_test(tcase_core, test_sprintf_f_10);
  tcase_add_test(tcase_core, test_sprintf_f_11);

  tcase_add_test(tcase_core, test_sprintf_e_1);
  tcase_add_test(tcase_core, test_sprintf_e_2);
  tcase_add_test(tcase_core, test_sprintf_e_3);
  tcase_add_test(tcase_core, test_sprintf_e_4);
  tcase_add_test(tcase_core, test_sprintf_e_5);
  tcase_add_test(tcase_core, test_sprintf_e_6);
  tcase_add_test(tcase_core, test_sprintf_e_7);
  tcase_add_test(tcase_core, test_sprintf_e_8);
  tcase_add_test(tcase_core, test_sprintf_e_9);

  tcase_add_test(tcase_core, test_sprintf_g_1);
  tcase_add_test(tcase_core, test_sprintf_g_2);
  tcase_add_test(tcase_core, test_sprintf_g_3);
  tcase_add_test(tcase_core, test_sprintf_g_4);
  tcase_add_test(tcase_core, test_sprintf_g_5);
  tcase_add_test(tcase_core, test_sprintf_g_6);
  tcase_add_test(tcase_core, test_sprintf_g_7);
  tcase_add_test(tcase_core, test_sprintf_g_8);
  tcase_add_test(tcase_core, test_sprintf_g_9);
  tcase_add_test(tcase_core, test_sprintf_g_10);
  tcase_add_test(tcase_core, test_sprintf_g_11);
  tcase_add_test(tcase_core, test_sprintf_g_12);
  tcase_add_test(tcase_core, test_sprintf_g_13);
  tcase_add_test(tcase_core, test_sprintf_g_14);

  /***************************** TEST sscanf c
   * **************************************************/
  tcase_add_test(tcase_core, test_sscanf_c_1);
  tcase_add_test(tcase_core, test_sscanf_c_2);
  tcase_add_test(tcase_core, test_sscanf_c_3);
  tcase_add_test(tcase_core, test_sscanf_c_4);
  tcase_add_test(tcase_core, test_sscanf_c_5);
  tcase_add_test(tcase_core, test_sscanf_c_6);
  tcase_add_test(tcase_core, test_sscanf_c_7);
  tcase_add_test(tcase_core, test_sscanf_c_8);
  tcase_add_test(tcase_core, test_sscanf_c_9);
  tcase_add_test(tcase_core, test_sscanf_c_10);
  tcase_add_test(tcase_core, test_sscanf_c_11);
  tcase_add_test(tcase_core, test_sscanf_c_12);
  tcase_add_test(tcase_core, test_sscanf_c_13);
  tcase_add_test(tcase_core, test_sscanf_c_14);
  tcase_add_test(tcase_core, test_sscanf_c_15);
  tcase_add_test(tcase_core, test_sscanf_c_16);
  tcase_add_test(tcase_core, test_sscanf_c_17);
  tcase_add_test(tcase_core, test_sscanf_c_18);
  tcase_add_test(tcase_core, test_sscanf_c_19);
  tcase_add_test(tcase_core, test_sscanf_c_20);
  tcase_add_test(tcase_core, test_sscanf_c_21);
  tcase_add_test(tcase_core, test_sscanf_c_22);
  tcase_add_test(tcase_core, test_sscanf_c_23);
  tcase_add_test(tcase_core, test_sscanf_c_24);
  tcase_add_test(tcase_core, test_sscanf_c_25);

  /***************************** TEST sscanf c
   * **************************************************/
  tcase_add_test(tcase_core, test_sscanf_s_1);
  tcase_add_test(tcase_core, test_sscanf_s_2);
  tcase_add_test(tcase_core, test_sscanf_s_3);
  tcase_add_test(tcase_core, test_sscanf_s_4);
  tcase_add_test(tcase_core, test_sscanf_s_5);
  tcase_add_test(tcase_core, test_sscanf_s_6);
  tcase_add_test(tcase_core, test_sscanf_s_7);
  tcase_add_test(tcase_core, test_sscanf_s_8);
  tcase_add_test(tcase_core, test_sscanf_s_9);
  tcase_add_test(tcase_core, test_sscanf_s_10);
  tcase_add_test(tcase_core, test_sscanf_s_11);
  tcase_add_test(tcase_core, test_sscanf_s_12);
  tcase_add_test(tcase_core, test_sscanf_s_13);
  tcase_add_test(tcase_core, test_sscanf_s_14);
  tcase_add_test(tcase_core, test_sscanf_s_15);
  tcase_add_test(tcase_core, test_sscanf_s_16);

  /***************************** TEST sscanf c
   * **************************************************/
  tcase_add_test(tcase_core, test_sscanf_d_1);
  tcase_add_test(tcase_core, test_sscanf_d_2);
  tcase_add_test(tcase_core, test_sscanf_d_3);
  tcase_add_test(tcase_core, test_sscanf_d_4);
  tcase_add_test(tcase_core, test_sscanf_d_5);
  tcase_add_test(tcase_core, test_sscanf_d_6);
  tcase_add_test(tcase_core, test_sscanf_d_7);
  tcase_add_test(tcase_core, test_sscanf_d_8);
  tcase_add_test(tcase_core, test_sscanf_d_9);
  tcase_add_test(tcase_core, test_sscanf_d_10);
  tcase_add_test(tcase_core, test_sscanf_d_11);
  tcase_add_test(tcase_core, test_sscanf_d_12);
  tcase_add_test(tcase_core, test_sscanf_d_13);
  tcase_add_test(tcase_core, test_sscanf_d_14);
  tcase_add_test(tcase_core, test_sscanf_d_15);
  tcase_add_test(tcase_core, test_sscanf_d_16);
  tcase_add_test(tcase_core, test_sscanf_d_17);
  tcase_add_test(tcase_core, test_sscanf_d_18);
  tcase_add_test(tcase_core, test_sscanf_d_19);
  tcase_add_test(tcase_core, test_sscanf_d_20);
  tcase_add_test(tcase_core, test_sscanf_d_21);
  tcase_add_test(tcase_core, test_sscanf_d_22);
  tcase_add_test(tcase_core, test_sscanf_d_23);
  tcase_add_test(tcase_core, test_sscanf_d_24);
  tcase_add_test(tcase_core, test_sscanf_d_25);
  tcase_add_test(tcase_core, test_sscanf_d_26);
  tcase_add_test(tcase_core, test_sscanf_d_27);
  tcase_add_test(tcase_core, test_sscanf_d_28);
  tcase_add_test(tcase_core, test_sscanf_d_29);
  tcase_add_test(tcase_core, test_sscanf_d_30);
  tcase_add_test(tcase_core, test_sscanf_d_31);
  tcase_add_test(tcase_core, test_sscanf_d_32);
  tcase_add_test(tcase_core, test_sscanf_d_33);
  tcase_add_test(tcase_core, test_sscanf_d_34);
  tcase_add_test(tcase_core, test_sscanf_d_35);
  tcase_add_test(tcase_core, test_sscanf_d_36);
  tcase_add_test(tcase_core, test_sscanf_d_37);
  tcase_add_test(tcase_core, test_sscanf_d_38);
  tcase_add_test(tcase_core, test_sscanf_d_39);
  tcase_add_test(tcase_core, test_sscanf_d_40);
  tcase_add_test(tcase_core, test_sscanf_d_41);
  tcase_add_test(tcase_core, test_sscanf_d_42);
  tcase_add_test(tcase_core, test_sscanf_d_43);
  tcase_add_test(tcase_core, test_sscanf_d_44);
  tcase_add_test(tcase_core, test_sscanf_d_45);
  tcase_add_test(tcase_core, test_sscanf_d_46);
  tcase_add_test(tcase_core, test_sscanf_d_47);
  tcase_add_test(tcase_core, test_sscanf_d_48);
  tcase_add_test(tcase_core, test_sscanf_d_49);
  tcase_add_test(tcase_core, test_sscanf_d_50);
  tcase_add_test(tcase_core, test_sscanf_d_51);
  tcase_add_test(tcase_core, test_sscanf_d_52);
  tcase_add_test(tcase_core, test_sscanf_d_53);
  tcase_add_test(tcase_core, test_sscanf_d_54);
  tcase_add_test(tcase_core, test_sscanf_d_55);
  tcase_add_test(tcase_core, test_sscanf_d_56);
  tcase_add_test(tcase_core, test_sscanf_d_57);
  tcase_add_test(tcase_core, test_sscanf_d_58);
  tcase_add_test(tcase_core, test_sscanf_d_59);
  tcase_add_test(tcase_core, test_sscanf_d_60);
  tcase_add_test(tcase_core, test_sscanf_d_61);
  tcase_add_test(tcase_core, test_sscanf_d_62);
  tcase_add_test(tcase_core, test_sscanf_d_63);
  tcase_add_test(tcase_core, test_sscanf_d_64);
  tcase_add_test(tcase_core, test_sscanf_d_65);
  tcase_add_test(tcase_core, test_sscanf_d_66);
  tcase_add_test(tcase_core, test_sscanf_d_67);
  tcase_add_test(tcase_core, test_sscanf_d_68);
  tcase_add_test(tcase_core, test_sscanf_d_69);
  tcase_add_test(tcase_core, test_sscanf_d_70);
  tcase_add_test(tcase_core, test_sscanf_d_71);
  tcase_add_test(tcase_core, test_sscanf_d_72);
  tcase_add_test(tcase_core, test_sscanf_d_73);
  tcase_add_test(tcase_core, test_sscanf_d_74);
  tcase_add_test(tcase_core, test_sscanf_d_75);
  tcase_add_test(tcase_core, test_sscanf_d_76);
  tcase_add_test(tcase_core, test_sscanf_d_77);
  tcase_add_test(tcase_core, test_sscanf_d_78);
  tcase_add_test(tcase_core, test_sscanf_d_79);
  tcase_add_test(tcase_core, test_sscanf_d_80);
  tcase_add_test(tcase_core, test_sscanf_d_81);
  tcase_add_test(tcase_core, test_sscanf_d_82);
  tcase_add_test(tcase_core, test_sscanf_d_83);
  tcase_add_test(tcase_core, test_sscanf_d_84);
  tcase_add_test(tcase_core, test_sscanf_d_85);
  tcase_add_test(tcase_core, test_sscanf_d_86);
  tcase_add_test(tcase_core, test_sscanf_d_87);
  tcase_add_test(tcase_core, test_sscanf_d_88);
  tcase_add_test(tcase_core, test_sscanf_d_89);
  tcase_add_test(tcase_core, test_sscanf_d_90);
  tcase_add_test(tcase_core, test_sscanf_d_91);
  tcase_add_test(tcase_core, test_sscanf_d_92);
  tcase_add_test(tcase_core, test_sscanf_d_93);
  tcase_add_test(tcase_core, test_sscanf_d_94);
  tcase_add_test(tcase_core, test_sscanf_d_95);
  tcase_add_test(tcase_core, test_sscanf_d_96);
  tcase_add_test(tcase_core, test_sscanf_d_97);
  tcase_add_test(tcase_core, test_sscanf_d_98);
  tcase_add_test(tcase_core, test_sscanf_d_99);
  tcase_add_test(tcase_core, test_sscanf_d_100);
  tcase_add_test(tcase_core, test_sscanf_d_101);
  tcase_add_test(tcase_core, test_sscanf_d_102);
  tcase_add_test(tcase_core, test_sscanf_d_103);
  tcase_add_test(tcase_core, test_sscanf_d_104);
  tcase_add_test(tcase_core, test_sscanf_d_105);
  tcase_add_test(tcase_core, test_sscanf_d_106);
  tcase_add_test(tcase_core, test_sscanf_d_107);
  tcase_add_test(tcase_core, test_sscanf_d_108);
  tcase_add_test(tcase_core, test_sscanf_d_109);
  tcase_add_test(tcase_core, test_sscanf_d_110);
  tcase_add_test(tcase_core, test_sscanf_d_111);
  tcase_add_test(tcase_core, test_sscanf_d_112);
  tcase_add_test(tcase_core, test_sscanf_d_113);
  tcase_add_test(tcase_core, test_sscanf_d_114);

  // /***************************** TEST sscanf u||o||x||X
  // *******************************/
  tcase_add_test(tcase_core, test_sscanf_u_1);
  tcase_add_test(tcase_core, test_sscanf_u_2);
  tcase_add_test(tcase_core, test_sscanf_u_3);
  tcase_add_test(tcase_core, test_sscanf_u_4);
  tcase_add_test(tcase_core, test_sscanf_u_5);
  tcase_add_test(tcase_core, test_sscanf_u_6);
  tcase_add_test(tcase_core, test_sscanf_u_7);
  tcase_add_test(tcase_core, test_sscanf_u_8);
  tcase_add_test(tcase_core, test_sscanf_u_9);
  tcase_add_test(tcase_core, test_sscanf_u_10);
  tcase_add_test(tcase_core, test_sscanf_u_11);
  tcase_add_test(tcase_core, test_sscanf_u_12);
  tcase_add_test(tcase_core, test_sscanf_u_13);
  tcase_add_test(tcase_core, test_sscanf_u_14);
  tcase_add_test(tcase_core, test_sscanf_u_15);
  tcase_add_test(tcase_core, test_sscanf_u_16);

  tcase_add_test(tcase_core, test_sscanf_o_1);
  tcase_add_test(tcase_core, test_sscanf_o_2);
  tcase_add_test(tcase_core, test_sscanf_o_3);
  tcase_add_test(tcase_core, test_sscanf_o_4);
  tcase_add_test(tcase_core, test_sscanf_o_5);
  tcase_add_test(tcase_core, test_sscanf_o_6);
  tcase_add_test(tcase_core, test_sscanf_o_7);
  tcase_add_test(tcase_core, test_sscanf_o_8);
  tcase_add_test(tcase_core, test_sscanf_o_9);
  tcase_add_test(tcase_core, test_sscanf_o_10);
  tcase_add_test(tcase_core, test_sscanf_o_11);
  tcase_add_test(tcase_core, test_sscanf_o_12);
  tcase_add_test(tcase_core, test_sscanf_o_13);
  tcase_add_test(tcase_core, test_sscanf_o_14);
  tcase_add_test(tcase_core, test_sscanf_o_15);
  tcase_add_test(tcase_core, test_sscanf_o_16);
  tcase_add_test(tcase_core, test_sscanf_o_17);
  tcase_add_test(tcase_core, test_sscanf_o_18);
  tcase_add_test(tcase_core, test_sscanf_o_19);
  tcase_add_test(tcase_core, test_sscanf_o_20);
  tcase_add_test(tcase_core, test_sscanf_o_21);
  tcase_add_test(tcase_core, test_sscanf_o_22);
  tcase_add_test(tcase_core, test_sscanf_o_23);
  tcase_add_test(tcase_core, test_sscanf_o_24);
  tcase_add_test(tcase_core, test_sscanf_o_25);
  tcase_add_test(tcase_core, test_sscanf_o_26);
  tcase_add_test(tcase_core, test_sscanf_o_27);
  tcase_add_test(tcase_core, test_sscanf_o_28);
  tcase_add_test(tcase_core, test_sscanf_o_29);
  tcase_add_test(tcase_core, test_sscanf_o_30);
  tcase_add_test(tcase_core, test_sscanf_o_31);
  tcase_add_test(tcase_core, test_sscanf_o_32);
  tcase_add_test(tcase_core, test_sscanf_o_33);
  tcase_add_test(tcase_core, test_sscanf_o_34);
  tcase_add_test(tcase_core, test_sscanf_o_35);
  tcase_add_test(tcase_core, test_sscanf_o_36);
  tcase_add_test(tcase_core, test_sscanf_o_37);
  tcase_add_test(tcase_core, test_sscanf_o_38);
  tcase_add_test(tcase_core, test_sscanf_o_39);
  tcase_add_test(tcase_core, test_sscanf_o_40);
  tcase_add_test(tcase_core, test_sscanf_o_41);

  tcase_add_test(tcase_core, test_sscanf_x_1);
  tcase_add_test(tcase_core, test_sscanf_x_2);
  tcase_add_test(tcase_core, test_sscanf_x_3);
  tcase_add_test(tcase_core, test_sscanf_x_4);
  tcase_add_test(tcase_core, test_sscanf_x_5);
  tcase_add_test(tcase_core, test_sscanf_x_6);
  tcase_add_test(tcase_core, test_sscanf_x_7);
  tcase_add_test(tcase_core, test_sscanf_x_8);
  tcase_add_test(tcase_core, test_sscanf_x_9);
  tcase_add_test(tcase_core, test_sscanf_x_10);
  tcase_add_test(tcase_core, test_sscanf_x_11);
  tcase_add_test(tcase_core, test_sscanf_x_12);
  tcase_add_test(tcase_core, test_sscanf_x_13);
  tcase_add_test(tcase_core, test_sscanf_x_14);
  tcase_add_test(tcase_core, test_sscanf_x_15);
  tcase_add_test(tcase_core, test_sscanf_x_16);
  tcase_add_test(tcase_core, test_sscanf_x_17);
  tcase_add_test(tcase_core, test_sscanf_x_18);
  tcase_add_test(tcase_core, test_sscanf_x_19);
  tcase_add_test(tcase_core, test_sscanf_x_21);
  tcase_add_test(tcase_core, test_sscanf_x_22);
  tcase_add_test(tcase_core, test_sscanf_x_23);
  tcase_add_test(tcase_core, test_sscanf_x_24);
  tcase_add_test(tcase_core, test_sscanf_x_25);
  tcase_add_test(tcase_core, test_sscanf_x_26);
  tcase_add_test(tcase_core, test_sscanf_x_27);
  tcase_add_test(tcase_core, test_sscanf_x_28);
  tcase_add_test(tcase_core, test_sscanf_x_29);
  tcase_add_test(tcase_core, test_sscanf_x_30);
  tcase_add_test(tcase_core, test_sscanf_x_31);
  tcase_add_test(tcase_core, test_sscanf_x_32);
  tcase_add_test(tcase_core, test_sscanf_x_33);
  tcase_add_test(tcase_core, test_sscanf_x_34);
  tcase_add_test(tcase_core, test_sscanf_x_35);
  tcase_add_test(tcase_core, test_sscanf_x_36);
  tcase_add_test(tcase_core, test_sscanf_x_37);
  tcase_add_test(tcase_core, test_sscanf_x_38);
  tcase_add_test(tcase_core, test_sscanf_x_39);
  tcase_add_test(tcase_core, test_sscanf_x_40);
  tcase_add_test(tcase_core, test_sscanf_x_41);
  tcase_add_test(tcase_core, test_sscanf_x_42);
  tcase_add_test(tcase_core, test_sscanf_x_43);
  tcase_add_test(tcase_core, test_sscanf_x_44);
  tcase_add_test(tcase_core, test_sscanf_x_45);
  tcase_add_test(tcase_core, test_sscanf_x_46);
  tcase_add_test(tcase_core, test_sscanf_x_47);
  tcase_add_test(tcase_core, test_sscanf_x_48);
  tcase_add_test(tcase_core, test_sscanf_x_49);
  tcase_add_test(tcase_core, test_sscanf_x_50);
  tcase_add_test(tcase_core, test_sscanf_x_51);
  tcase_add_test(tcase_core, test_sscanf_x_52);
  tcase_add_test(tcase_core, test_sscanf_x_53);
  tcase_add_test(tcase_core, test_sscanf_x_54);
  tcase_add_test(tcase_core, test_sscanf_x_55);
  tcase_add_test(tcase_core, test_sscanf_x_56);
  tcase_add_test(tcase_core, test_sscanf_x_57);
  tcase_add_test(tcase_core, test_sscanf_x_58);
  tcase_add_test(tcase_core, test_sscanf_x_59);
  tcase_add_test(tcase_core, test_sscanf_x_60);
  tcase_add_test(tcase_core, test_sscanf_x_61);
  tcase_add_test(tcase_core, test_sscanf_x_62);
  tcase_add_test(tcase_core, test_sscanf_x_64);
  tcase_add_test(tcase_core, test_sscanf_x_65);
  tcase_add_test(tcase_core, test_sscanf_x_66);
  tcase_add_test(tcase_core, test_sscanf_x_67);
  tcase_add_test(tcase_core, test_sscanf_x_68);
  tcase_add_test(tcase_core, test_sscanf_x_69);
  tcase_add_test(tcase_core, test_sscanf_x_70);
  tcase_add_test(tcase_core, test_sscanf_x_71);
  tcase_add_test(tcase_core, test_sscanf_x_72);
  tcase_add_test(tcase_core, test_sscanf_x_73);
  tcase_add_test(tcase_core, test_sscanf_x_75);
  tcase_add_test(tcase_core, test_sscanf_x_76);
  tcase_add_test(tcase_core, test_sscanf_x_77);
  tcase_add_test(tcase_core, test_sscanf_x_78);
  tcase_add_test(tcase_core, test_sscanf_x_79);
  tcase_add_test(tcase_core, test_sscanf_x_80);
  tcase_add_test(tcase_core, test_sscanf_x_81);
  tcase_add_test(tcase_core, test_sscanf_x_82);
  tcase_add_test(tcase_core, test_sscanf_x_83);
  tcase_add_test(tcase_core, test_sscanf_x_84);
  tcase_add_test(tcase_core, test_sscanf_x_86);
  tcase_add_test(tcase_core, test_sscanf_x_87);
  tcase_add_test(tcase_core, test_sscanf_x_88);
  tcase_add_test(tcase_core, test_sscanf_x_89);
  tcase_add_test(tcase_core, test_sscanf_x_90);
  tcase_add_test(tcase_core, test_sscanf_x_91);
  tcase_add_test(tcase_core, test_sscanf_x_92);
  tcase_add_test(tcase_core, test_sscanf_x_93);
  tcase_add_test(tcase_core, test_sscanf_x_94);
  tcase_add_test(tcase_core, test_sscanf_x_95);
  tcase_add_test(tcase_core, test_sscanf_x_97);
  tcase_add_test(tcase_core, test_sscanf_x_98);

  // /***************************** TEST sscanf i
  // *******************************/

  tcase_add_test(tcase_core, test_sscanf_i_1);
  tcase_add_test(tcase_core, test_sscanf_i_2);
  tcase_add_test(tcase_core, test_sscanf_i_3);
  tcase_add_test(tcase_core, test_sscanf_i_4);
  tcase_add_test(tcase_core, test_sscanf_i_5);
  tcase_add_test(tcase_core, test_sscanf_i_6);
  tcase_add_test(tcase_core, test_sscanf_i_7);
  tcase_add_test(tcase_core, test_sscanf_i_8);
  tcase_add_test(tcase_core, test_sscanf_i_9);
  tcase_add_test(tcase_core, test_sscanf_i_10);
  tcase_add_test(tcase_core, test_sscanf_i_11);
  tcase_add_test(tcase_core, test_sscanf_i_12);
  tcase_add_test(tcase_core, test_sscanf_i_13);
  tcase_add_test(tcase_core, test_sscanf_i_14);
  tcase_add_test(tcase_core, test_sscanf_i_15);
  tcase_add_test(tcase_core, test_sscanf_i_16);
  tcase_add_test(tcase_core, test_sscanf_i_17);
  tcase_add_test(tcase_core, test_sscanf_i_18);
  tcase_add_test(tcase_core, test_sscanf_i_19);
  tcase_add_test(tcase_core, test_sscanf_i_20);
  tcase_add_test(tcase_core, test_sscanf_i_21);

  // /***************************** TEST sscanf f || e || E || g || G
  // *******************************/

  tcase_add_test(tcase_core, test_sscanf_f_1);
  tcase_add_test(tcase_core, test_sscanf_f_2);
  tcase_add_test(tcase_core, test_sscanf_f_3);
  tcase_add_test(tcase_core, test_sscanf_f_4);
  tcase_add_test(tcase_core, test_sscanf_f_5);
  tcase_add_test(tcase_core, test_sscanf_f_6);
  tcase_add_test(tcase_core, test_sscanf_f_7);
  tcase_add_test(tcase_core, test_sscanf_f_8);
  tcase_add_test(tcase_core, test_sscanf_f_9);
  tcase_add_test(tcase_core, test_sscanf_f_11);
  tcase_add_test(tcase_core, test_sscanf_f_12);
  tcase_add_test(tcase_core, test_sscanf_f_13);
  tcase_add_test(tcase_core, test_sscanf_f_14);
  tcase_add_test(tcase_core, test_sscanf_f_15);
  tcase_add_test(tcase_core, test_sscanf_f_16);
  tcase_add_test(tcase_core, test_sscanf_f_17);
  tcase_add_test(tcase_core, test_sscanf_f_18);
  tcase_add_test(tcase_core, test_sscanf_f_19);
  tcase_add_test(tcase_core, test_sscanf_f_20);
  tcase_add_test(tcase_core, test_sscanf_f_21);
  tcase_add_test(tcase_core, test_sscanf_f_22);
  tcase_add_test(tcase_core, test_sscanf_f_23);
  tcase_add_test(tcase_core, test_sscanf_f_24);
  tcase_add_test(tcase_core, test_sscanf_f_25);
  tcase_add_test(tcase_core, test_sscanf_f_26);

  tcase_add_test(tcase_core, test_Lf_1);
  tcase_add_test(tcase_core, test_Lf_2);
  tcase_add_test(tcase_core, test_Lf_3);
  tcase_add_test(tcase_core, test_Lf_4);
  tcase_add_test(tcase_core, test_Lf_5);
  tcase_add_test(tcase_core, test_Lf_6);
  tcase_add_test(tcase_core, test_Lf_7);
  tcase_add_test(tcase_core, test_Lf_8);
  tcase_add_test(tcase_core, test_Lf_9);
  tcase_add_test(tcase_core, test_Lf_10);

  tcase_add_test(tcase_core, test_lf_1);
  tcase_add_test(tcase_core, test_lf_2);
  tcase_add_test(tcase_core, test_lf_3);
  tcase_add_test(tcase_core, test_lf_4);
  tcase_add_test(tcase_core, test_lf_5);
  tcase_add_test(tcase_core, test_lf_6);
  tcase_add_test(tcase_core, test_lf_7);
  tcase_add_test(tcase_core, test_lf_8);
  tcase_add_test(tcase_core, test_lf_9);
  tcase_add_test(tcase_core, test_lf_10);

  tcase_add_test(tcase_core, test_sscanf_e_1);
  tcase_add_test(tcase_core, test_sscanf_e_2);
  tcase_add_test(tcase_core, test_sscanf_e_3);
  tcase_add_test(tcase_core, test_sscanf_e_4);
  tcase_add_test(tcase_core, test_sscanf_e_5);
  tcase_add_test(tcase_core, test_sscanf_e_6);
  tcase_add_test(tcase_core, test_sscanf_e_7);
  tcase_add_test(tcase_core, test_sscanf_e_8);
  tcase_add_test(tcase_core, test_sscanf_e_9);
  tcase_add_test(tcase_core, test_sscanf_e_10);
  tcase_add_test(tcase_core, test_sscanf_e_11);
  tcase_add_test(tcase_core, test_sscanf_e_12);
  tcase_add_test(tcase_core, test_sscanf_e_13);
  tcase_add_test(tcase_core, test_sscanf_e_14);
  tcase_add_test(tcase_core, test_sscanf_e_15);
  tcase_add_test(tcase_core, test_sscanf_e_16);
  tcase_add_test(tcase_core, test_sscanf_e_17);
  tcase_add_test(tcase_core, test_sscanf_e_18);
  tcase_add_test(tcase_core, test_sscanf_e_19);
  tcase_add_test(tcase_core, test_sscanf_e_20);

  tcase_add_test(tcase_core, test_sscanf_g_1);
  tcase_add_test(tcase_core, test_sscanf_g_2);
  tcase_add_test(tcase_core, test_sscanf_g_3);
  tcase_add_test(tcase_core, test_sscanf_g_4);
  tcase_add_test(tcase_core, test_sscanf_g_5);
  tcase_add_test(tcase_core, test_sscanf_g_6);
  tcase_add_test(tcase_core, test_sscanf_g_7);
  tcase_add_test(tcase_core, test_sscanf_g_8);
  tcase_add_test(tcase_core, test_sscanf_g_9);
  tcase_add_test(tcase_core, test_sscanf_g_10);
  tcase_add_test(tcase_core, test_sscanf_g_11);
  tcase_add_test(tcase_core, test_sscanf_g_12);
  tcase_add_test(tcase_core, test_sscanf_g_13);
  tcase_add_test(tcase_core, test_sscanf_g_14);
  tcase_add_test(tcase_core, test_sscanf_g_15);
  tcase_add_test(tcase_core, test_sscanf_g_16);
  tcase_add_test(tcase_core, test_sscanf_g_17);
  tcase_add_test(tcase_core, test_sscanf_g_18);
  tcase_add_test(tcase_core, test_sscanf_g_19);
  tcase_add_test(tcase_core, test_sscanf_g_20);

  // /***************************** TEST sscanf % / p/ n
  // *******************************/
  tcase_add_test(tcase_core, test_percent_1);
  tcase_add_test(tcase_core, test_percent_2);

  tcase_add_test(tcase_core, test_p_1);
  tcase_add_test(tcase_core, test_p_2);
  tcase_add_test(tcase_core, test_p_3);
  tcase_add_test(tcase_core, test_p_4);
  tcase_add_test(tcase_core, test_p_5);
  tcase_add_test(tcase_core, test_p_6);
  tcase_add_test(tcase_core, test_p_8);
  tcase_add_test(tcase_core, test_p_9);
  tcase_add_test(tcase_core, test_n_1);
  tcase_add_test(tcase_core, test_n_2);
  tcase_add_test(tcase_core, test_n_3);
  tcase_add_test(tcase_core, test_n_4);
  tcase_add_test(tcase_core, test_n_5);
  tcase_add_test(tcase_core, test_n_6);
  tcase_add_test(tcase_core, test_n_7);
  tcase_add_test(tcase_core, test_n_8);
  tcase_add_test(tcase_core, test_n_9);
  tcase_add_test(tcase_core, test_n_10);

  // /***************************** TEST to_upper || to_lower || insert || trim
  // *******************************/

  tcase_add_test(tcase_core, test_to_upper_1);
  tcase_add_test(tcase_core, test_to_upper_2);
  tcase_add_test(tcase_core, test_to_upper_3);
  tcase_add_test(tcase_core, test_to_upper_4);
  tcase_add_test(tcase_core, test_to_upper_5);
  tcase_add_test(tcase_core, test_to_upper_6);
  tcase_add_test(tcase_core, test_to_upper_7);
  tcase_add_test(tcase_core, test_to_upper_8);
  tcase_add_test(tcase_core, test_to_upper_9);
  tcase_add_test(tcase_core, test_to_upper_10);
  tcase_add_test(tcase_core, test_to_upper_11);
  tcase_add_test(tcase_core, test_to_upper_12);
  tcase_add_test(tcase_core, test_to_upper_13);
  tcase_add_test(tcase_core, test_to_upper_14);
  tcase_add_test(tcase_core, test_to_upper_15);
  tcase_add_test(tcase_core, test_to_upper_16);
  tcase_add_test(tcase_core, test_to_upper_17);
  tcase_add_test(tcase_core, test_to_upper_18);

  tcase_add_test(tcase_core, test_to_lower_1);
  tcase_add_test(tcase_core, test_to_lower_2);
  tcase_add_test(tcase_core, test_to_lower_3);
  tcase_add_test(tcase_core, test_to_lower_4);
  tcase_add_test(tcase_core, test_to_lower_5);
  tcase_add_test(tcase_core, test_to_lower_6);
  tcase_add_test(tcase_core, test_to_lower_7);
  tcase_add_test(tcase_core, test_to_lower_8);
  tcase_add_test(tcase_core, test_to_lower_9);
  tcase_add_test(tcase_core, test_to_lower_10);
  tcase_add_test(tcase_core, test_to_lower_11);
  tcase_add_test(tcase_core, test_to_lower_12);
  tcase_add_test(tcase_core, test_to_lower_13);
  tcase_add_test(tcase_core, test_to_lower_14);
  tcase_add_test(tcase_core, test_to_lower_15);
  tcase_add_test(tcase_core, test_to_lower_16);
  tcase_add_test(tcase_core, test_to_lower_17);
  tcase_add_test(tcase_core, test_to_lower_18);

  tcase_add_test(tcase_core, test_trim_1);
  tcase_add_test(tcase_core, test_trim_2);
  tcase_add_test(tcase_core, test_trim_3);
  tcase_add_test(tcase_core, test_trim_4);
  tcase_add_test(tcase_core, test_trim_5);
  tcase_add_test(tcase_core, test_trim_6);
  tcase_add_test(tcase_core, test_trim_7);
  tcase_add_test(tcase_core, test_trim_8);
  tcase_add_test(tcase_core, test_trim_9);
  tcase_add_test(tcase_core, test_trim_11);
  tcase_add_test(tcase_core, test_trim_12);
  tcase_add_test(tcase_core, test_trim_13);
  tcase_add_test(tcase_core, test_trim_14);
  tcase_add_test(tcase_core, test_trim_15);
  tcase_add_test(tcase_core, test_trim_16);
  tcase_add_test(tcase_core, test_trim_17);
  tcase_add_test(tcase_core, test_trim_18);
  tcase_add_test(tcase_core, test_trim_19);
  tcase_add_test(tcase_core, test_trim_20);

  tcase_add_test(tcase_core, test_insert_1);
  tcase_add_test(tcase_core, test_insert_2);
  tcase_add_test(tcase_core, test_insert_3);
  tcase_add_test(tcase_core, test_insert_4);
  tcase_add_test(tcase_core, test_insert_5);
  tcase_add_test(tcase_core, test_insert_6);
  tcase_add_test(tcase_core, test_insert_7);
  tcase_add_test(tcase_core, test_insert_8);
  tcase_add_test(tcase_core, test_insert_9);
  tcase_add_test(tcase_core, test_insert_10);
  tcase_add_test(tcase_core, test_insert_11);
  tcase_add_test(tcase_core, test_insert_12);
  tcase_add_test(tcase_core, test_insert_13);
  tcase_add_test(tcase_core, test_insert_14);
  tcase_add_test(tcase_core, test_insert_15);
  tcase_add_test(tcase_core, test_insert_16);
  tcase_add_test(tcase_core, test_insert_17);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count == 0) ? 0 : 1;
}