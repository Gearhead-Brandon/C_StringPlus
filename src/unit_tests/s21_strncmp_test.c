#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strncmp_matches_strncmp_with_equal_strings) {
  const char *str1 = "SALAM";
  const char *str2 = "SALAM";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_different_strings) {
  const char *str1 = "SALAM";
  const char *str2 = "Verte";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_prefix_match) {
  const char *str1 = "SALAM";
  const char *str2 = "SALAM, Verter";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 1;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_with_zero) {
  const char *str1 = "HELLO";
  const char *str2 = "hello";
  s21_size_t n = 0;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_null_terminator_in_str1) {
  const char *str1 = "Salam\0Pidor";
  const char *str2 = "Pidor";
  s21_size_t n = 10;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_null_terminator_in_str2) {
  const char *str1 = "Salam";
  const char *str2 = "Salam\0Popal";
  s21_size_t n = 10;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_same_length) {
  const char *str1 = "Salam";
  const char *str2 = "Zaiba";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_longer_str1) {
  const char *str1 = "Auf Kefteme!!";
  const char *str2 = "Auf!";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_longer_str2) {
  const char *str1 = "Salam";
  const char *str2 = "Verte, Salam!";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_negative_result) {
  const char *str1 = "Hello";
  const char *str2 = "Help";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_positive_result) {
  const char *str1 = "Help";
  const char *str2 = "Hello";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(str1, str2, n);
  int strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_result, strncmp_result);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strncmp\033[0m");

  TCase *test_case = tcase_create("strncmp");
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_equal_strings);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_different_strings);
  tcase_add_test(test_case, test_s21_strncmp_matches_strncmp_with_prefix_match);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_empty_strings);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_null_terminator_in_str1);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_null_terminator_in_str2);
  tcase_add_test(test_case, test_s21_strncmp_matches_strncmp_with_same_length);
  tcase_add_test(test_case, test_s21_strncmp_matches_strncmp_with_longer_str1);
  tcase_add_test(test_case, test_s21_strncmp_matches_strncmp_with_longer_str2);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_negative_result);
  tcase_add_test(test_case, test_s21_strncmp_with_zero);
  tcase_add_test(test_case,
                 test_s21_strncmp_matches_strncmp_with_positive_result);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strncmp_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}