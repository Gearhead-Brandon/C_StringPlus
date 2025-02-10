#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strncat_matches_strncat_with_empty_dest) {
  char dest[10] = "";
  const char *src = "Salam";

  char *s21_result = s21_strncat(dest, src, 5);
  char *strncat_result = strncat(dest, src, 5);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_empty_src) {
  char dest[10] = "Pidor";
  const char *src = "";

  char *s21_result = s21_strncat(dest, src, 5);
  char *strncat_result = strncat(dest, src, 5);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_full_concatenation) {
  char dest[15] = "Hello";
  const char *src = "Kefte";

  char *s21_result = s21_strncat(dest, src, 10);
  char *strncat_result = strncat(dest, src, 10);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_partial_concatenation) {
  char dest[15] = "Kefte";
  const char *src = "World";

  char *s21_result = s21_strncat(dest, src, 3);
  char *strncat_result = strncat(dest, src, 3);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_zero_n) {
  char dest[15] = "Hello";
  const char *src = "Kefte";

  char *s21_result = s21_strncat(dest, src, 0);
  char *strncat_result = strncat(dest, src, 0);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_dest_not_null_terminated) {
  char dest[15] = {'H', 'e', 'l', 'l', 'o'};
  const char *src = "World";

  char *s21_result = s21_strncat(dest, src, 5);
  char *strncat_result = strncat(dest, src, 5);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_src_not_null_terminated) {
  char dest[10] = "Hello";
  const char src[] = {'W', 'o', 'r', 'l', 'd', '\0', 'E', 'x', 't', 'r', 'a'};

  char *s21_result = s21_strncat(dest, src, 10);
  char *strncat_result = strncat(dest, src, 10);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_dest_and_src_same_pointer) {
  char str[15] = "Salam";
  char *dest = str;
  const char *src = str;

  char *s21_result = s21_strncat(dest, src, 5);
  char *strncat_result = strncat(dest, src, 5);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_dest_smaller_than_n) {
  char dest[15] = "Hello";
  const char *src = "Pidor";

  char *s21_result = s21_strncat(dest, src, 10);
  char *strncat_result = strncat(dest, src, 10);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

START_TEST(test_s21_strncat_matches_strncat_with_dest_larger_than_n) {
  char dest[15] = "Pidor";
  const char *src = "World";

  char *s21_result = s21_strncat(dest, src, 3);
  char *strncat_result = strncat(dest, src, 3);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_str_eq(dest, strncat_result);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strncat\033[0m");

  TCase *test_case = tcase_create("strncat");
  tcase_add_test(test_case, test_s21_strncat_matches_strncat_with_empty_dest);
  tcase_add_test(test_case, test_s21_strncat_matches_strncat_with_empty_src);
  tcase_add_test(test_case,
                 test_s21_strncat_matches_strncat_with_full_concatenation);
  tcase_add_test(test_case,
                 test_s21_strncat_matches_strncat_with_partial_concatenation);
  tcase_add_test(test_case, test_s21_strncat_matches_strncat_with_zero_n);
  tcase_add_test(
      test_case,
      test_s21_strncat_matches_strncat_with_dest_not_null_terminated);
  tcase_add_test(test_case,
                 test_s21_strncat_matches_strncat_with_src_not_null_terminated);
  tcase_add_test(
      test_case,
      test_s21_strncat_matches_strncat_with_dest_and_src_same_pointer);
  tcase_add_test(test_case,
                 test_s21_strncat_matches_strncat_with_dest_smaller_than_n);
  tcase_add_test(test_case,
                 test_s21_strncat_matches_strncat_with_dest_larger_than_n);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strncat_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}