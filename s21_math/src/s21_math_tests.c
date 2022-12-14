#include "s21_math_tests.h"

START_TEST(s21_abs_test) {
  int test_val = 9;
  ck_assert_int_eq(abs(test_val), s21_abs(test_val));
  test_val = -17;
  ck_assert_int_eq(abs(test_val), s21_abs(test_val));
  test_val = 0;
  ck_assert_int_eq(abs(test_val), s21_abs(test_val));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_double_eq(fabs(9.5), s21_fabs(9.5));
  ck_assert_double_eq(fabs(-17.8), s21_fabs(-17.8));
  ck_assert_double_eq(fabs(0.0), s21_fabs(0.0l));
  ck_assert_double_eq(fabs(s21_INF), s21_fabs(s21_INF));
  ck_assert_double_eq(fabs(-s21_INF), s21_fabs(-s21_INF));
  ck_assert_double_ne(s21_fabs(s21_NaN), s21_fabs(s21_NaN));
  for (double i = -100; i < 100; i += 0.199872) {
    ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), TEST_EPS);
  }
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_double_eq_tol(exp(12.67), s21_exp(12.67), TEST_EPS);
  ck_assert_double_eq_tol(exp(-12.67), s21_exp(-12.67), TEST_EPS);
  ck_assert_double_eq_tol(exp(0), s21_exp(0), TEST_EPS);
  ck_assert_double_eq_tol(exp(7), s21_exp(7), TEST_EPS);
  ck_assert_double_eq_tol(exp(19), s21_exp(19), TEST_EPS);
  ck_assert_double_eq_tol(exp(0.9999), s21_exp(0.9999), TEST_EPS);
  ck_assert_double_eq(exp(s21_INF), s21_exp(s21_INF));
  ck_assert_double_eq(exp(-s21_INF), s21_exp(-s21_INF));
  ck_assert_double_ne(s21_exp(s21_NaN), s21_exp(s21_NaN));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_double_eq_tol(log(12.67), s21_log(12.67), TEST_EPS);
  ck_assert_double_eq(log(0.0), s21_log(0.0));
  ck_assert_double_eq_tol(log(7), s21_log(7), TEST_EPS);
  ck_assert_double_eq_tol(log(69), s21_log(69), TEST_EPS);
  ck_assert_double_eq_tol(log(0.9999), s21_log(0.9999), TEST_EPS);
  ck_assert_double_eq(log(s21_INF), s21_log(s21_INF));
  ck_assert_double_ne(s21_log(-s21_INF), s21_log(-s21_INF));
  ck_assert_double_ne(s21_log(s21_NaN), s21_log(s21_NaN));
  ck_assert_double_ne(s21_log(-7), s21_log(-7));
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_double_eq_tol(pow(12.67, 5), s21_pow(12.67, 5), TEST_EPS);
  ck_assert_double_eq(pow(0.0, 2), s21_pow(0.0, 2));
  ck_assert_double_eq(pow(2, 0), s21_pow(2, 0));
  ck_assert_double_eq_tol(pow(-7, 4), s21_pow(-7, 4), TEST_EPS);
  ck_assert_double_eq_tol(pow(7, -12), s21_pow(7, -12), TEST_EPS);
  ck_assert_double_eq_tol(pow(0.999, 0.45), s21_pow(0.999, 0.45), TEST_EPS);
  ck_assert_double_eq(pow(s21_INF, 5), s21_pow(s21_INF, 5));
  ck_assert_double_eq(pow(-s21_INF, 5), s21_pow(-s21_INF, 5));
  ck_assert_double_eq(pow(5, s21_INF), s21_pow(5, s21_INF));
  ck_assert_double_eq(pow(5, -s21_INF), s21_pow(5, -s21_INF));
  ck_assert_double_ne(s21_pow(5, s21_NaN), s21_pow(5, s21_NaN));
  ck_assert_double_ne(s21_pow(s21_NaN, 5), s21_pow(s21_NaN, 5));
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_double_eq_tol(sqrt(12.67), s21_sqrt(12.67), TEST_EPS);
  ck_assert_double_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_double_eq_tol(sqrt(7), s21_sqrt(7), TEST_EPS);
  ck_assert_double_eq_tol(sqrt(69), s21_sqrt(69), TEST_EPS);
  ck_assert_double_eq_tol(sqrt(0.9999), s21_sqrt(0.9999), TEST_EPS);
  ck_assert_double_eq(sqrt(s21_INF), s21_sqrt(s21_INF));
  ck_assert_double_eq(s21_sqrt(-s21_INF), s21_sqrt(-s21_INF));
  ck_assert_double_ne(s21_sqrt(s21_NaN), s21_sqrt(s21_NaN));
  ck_assert_double_eq_tol(s21_sqrt(-7), s21_sqrt(-7), TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_double_eq_tol(fmod(12.67, 2.3), s21_fmod(12.67, 2.3), TEST_EPS);
  ck_assert_double_eq_tol(fmod(12, 2.3), s21_fmod(12, 2.3), TEST_EPS);
  ck_assert_double_eq_tol(fmod(-12, 2.3), s21_fmod(-12, 2.3), TEST_EPS);
  ck_assert_double_eq_tol(fmod(12.67, 5), s21_fmod(12.67, 5), TEST_EPS);
  ck_assert_double_eq_tol(fmod(389.45, -5), s21_fmod(389.45, -5), TEST_EPS);
  ck_assert_double_eq_tol(fmod(0.0, 5.6), s21_fmod(0.0, 5.6), TEST_EPS);
  ck_assert_double_ne(s21_fmod(0.0, 0.0), s21_fmod(0.0, 0.0));
  ck_assert_double_ne(s21_fmod(12.67, 0.0), s21_fmod(12.67, 0.0));
  ck_assert_double_ne(s21_fmod(s21_INF, 5.6), s21_fmod(s21_INF, 5.6));
  ck_assert_double_eq(fmod(5.6, s21_INF), s21_fmod(5.6, s21_INF));
  ck_assert_double_ne(s21_fmod(-s21_INF, 5.6), s21_fmod(-s21_INF, 5.6));
  ck_assert_double_eq(fmod(5.6, -s21_INF), s21_fmod(5.6, -s21_INF));
  ck_assert_double_ne(s21_fmod(-s21_INF, -s21_INF),
                      s21_fmod(-s21_INF, -s21_INF));
  ck_assert_double_ne(s21_fmod(s21_INF, s21_INF), s21_fmod(s21_INF, s21_INF));
  ck_assert_double_ne(s21_fmod(s21_NaN, 5.6), s21_fmod(s21_NaN, 5.6));
  ck_assert_double_ne(s21_fmod(5.6, s21_NaN), s21_fmod(5.6, s21_NaN));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_double_eq(floor(12.67), s21_floor(12.67));
  ck_assert_double_eq(floor(2.3), s21_floor(2.3));
  ck_assert_double_eq(floor(-389.45), s21_floor(-389.45));
  ck_assert_double_eq(floor(0.0), s21_floor(0.0));
  ck_assert_double_eq(floor(s21_INF), s21_floor(s21_INF));
  ck_assert_double_eq(floor(-s21_INF), s21_floor(-s21_INF));
  ck_assert_double_ne(s21_floor(s21_NaN), s21_floor(s21_NaN));
}
END_TEST

START_TEST(s21_ceil_test) {
  ck_assert_double_eq(ceil(12.67), s21_ceil(12.67));
  ck_assert_double_eq(ceil(2.3), s21_ceil(2.3));
  ck_assert_double_eq(ceil(-389.45), s21_ceil(-389.45));
  ck_assert_double_eq(ceil(0.0), s21_ceil(0.0));
  ck_assert_double_eq(ceil(7.77), s21_ceil(7.77));
  ck_assert_double_eq(ceil(6.0), s21_ceil(6.0));
  ck_assert_double_eq(ceil(-6.0), s21_ceil(-6.0));
  ck_assert_double_eq(ceil(s21_INF), s21_ceil(s21_INF));
  ck_assert_double_eq(ceil(-s21_INF), s21_ceil(-s21_INF));
  ck_assert_double_ne(s21_ceil(s21_NaN), s21_ceil(s21_NaN));
}
END_TEST

START_TEST(s21_sin_test) {
  ck_assert_double_eq_tol(sin(-0.8), s21_sin(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(sin(0.5), s21_sin(0.5), TEST_EPS);
  ck_assert_double_eq_tol(sin(-7.5), s21_sin(-7.5), TEST_EPS);
  ck_assert_double_eq(sin(0.0), s21_sin(0.0));
  ck_assert_double_eq(sin(7.77), s21_sin(7.77));
  ck_assert_double_eq(sin(1.0), s21_sin(1.0));
  ck_assert_double_eq(sin(-1.0), s21_sin(-1.0));
  ck_assert_double_ne(s21_sin(s21_INF), s21_sin(s21_INF));
  ck_assert_double_ne(s21_sin(-s21_INF), s21_sin(-s21_INF));
  ck_assert_double_ne(s21_sin(s21_NaN), s21_sin(s21_NaN));
}
END_TEST

START_TEST(s21_cos_test) {
  ck_assert_double_eq_tol(cos(-0.8), s21_cos(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(cos(0.5), s21_cos(0.5), TEST_EPS);
  ck_assert_double_eq_tol(cos(-7.5), s21_cos(-7.5), TEST_EPS);
  ck_assert_double_eq_tol(cos(0.0), s21_cos(0.0), TEST_EPS);
  ck_assert_double_eq_tol(cos(7.77), s21_cos(7.77), TEST_EPS);
  ck_assert_double_eq_tol(cos(1.0), s21_cos(1.0), TEST_EPS);
  ck_assert_double_eq_tol(cos(-1.0), s21_cos(-1.0), TEST_EPS);
  ck_assert_double_ne(s21_cos(s21_INF), s21_cos(s21_INF));
  ck_assert_double_ne(s21_cos(-s21_INF), s21_cos(-s21_INF));
  ck_assert_double_ne(s21_cos(s21_NaN), s21_cos(s21_NaN));
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_double_eq_tol(tan(-0.8), s21_tan(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(tan(0.5), s21_tan(0.5), TEST_EPS);
  ck_assert_double_eq_tol(tan(-7.5), s21_tan(-7.5), TEST_EPS);
  ck_assert_double_eq_tol(tan(0.0), s21_tan(0.0), TEST_EPS);
  ck_assert_double_eq_tol(tan(7.77), s21_tan(7.77), TEST_EPS);
  ck_assert_double_eq_tol(tan(1.0), s21_tan(1.0), TEST_EPS);
  ck_assert_double_eq_tol(tan(-1.0), s21_tan(-1.0), TEST_EPS);
  ck_assert_double_ne(s21_tan(s21_INF), s21_tan(s21_INF));
  ck_assert_double_ne(s21_tan(-s21_INF), s21_tan(-s21_INF));
  ck_assert_double_ne(s21_tan(s21_NaN), s21_tan(s21_NaN));
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_double_eq_tol(asin(-0.8), s21_asin(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(asin(0.5), s21_asin(0.5), TEST_EPS);
  ck_assert_double_ne(s21_asin(-7.5), s21_asin(-7.5));
  ck_assert_double_eq_tol(asin(0.0), s21_asin(0.0), TEST_EPS);
  ck_assert_double_ne(s21_asin(7.77), s21_asin(7.77));
  ck_assert_double_eq_tol(asin(1.0), s21_asin(1.0), TEST_EPS);
  ck_assert_double_eq_tol(asin(-1.0), s21_asin(-1.0), TEST_EPS);
  ck_assert_double_ne(s21_asin(s21_INF), s21_asin(s21_INF));
  ck_assert_double_ne(s21_asin(-s21_INF), s21_asin(-s21_INF));
  ck_assert_double_ne(s21_asin(s21_NaN), s21_asin(s21_NaN));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_double_eq_tol(acos(-0.8), s21_acos(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(acos(0.5), s21_acos(0.5), TEST_EPS);
  ck_assert_double_ne(s21_acos(-7.5), s21_acos(-7.5));
  ck_assert_double_eq_tol(acos(0.0), s21_acos(0.0), TEST_EPS);
  ck_assert_double_ne(s21_acos(7.77), s21_acos(7.77));
  ck_assert_double_eq_tol(acos(1.0), s21_acos(1.0), TEST_EPS);
  ck_assert_double_eq_tol(acos(-1.0), s21_acos(-1.0), TEST_EPS);
  ck_assert_double_ne(s21_asin(s21_INF), s21_asin(s21_INF));
  ck_assert_double_ne(s21_asin(-s21_INF), s21_asin(-s21_INF));
  ck_assert_double_ne(s21_asin(s21_NaN), s21_asin(s21_NaN));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_double_eq_tol(atan(-0.8), s21_atan(-0.8), TEST_EPS);
  ck_assert_double_eq_tol(atan(0.5), s21_atan(0.5), TEST_EPS);
  ck_assert_double_eq_tol(atan(-7.5), s21_atan(-7.5), TEST_EPS);
  ck_assert_double_eq_tol(atan(0.0), s21_atan(0.0), TEST_EPS);
  ck_assert_double_eq_tol(atan(7.77), s21_atan(7.77), TEST_EPS);
  ck_assert_double_eq_tol(atan(1.0), s21_atan(1.0), TEST_EPS);
  ck_assert_double_eq_tol(atan(-1.0), s21_atan(-1.0), TEST_EPS);
  ck_assert_double_eq_tol(atan(s21_INF), s21_atan(s21_INF), TEST_EPS);
  ck_assert_double_eq_tol(atan(-s21_INF), s21_atan(-s21_INF), TEST_EPS);
  ck_assert_double_ne(s21_atan(s21_NaN), s21_atan(s21_NaN));
}
END_TEST

int main() {
  Suite *suite = suite_create("s21_math library test");
  TCase *tc = tcase_create(" CHECK s21_math ---> ");
  SRunner *sr = srunner_create(suite);
  int nf;
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, s21_abs_test);
  tcase_add_test(tc, s21_fabs_test);
  tcase_add_test(tc, s21_exp_test);
  tcase_add_test(tc, s21_log_test);
  tcase_add_test(tc, s21_pow_test);
  tcase_add_test(tc, s21_sqrt_test);
  tcase_add_test(tc, s21_fmod_test);
  tcase_add_test(tc, s21_floor_test);
  tcase_add_test(tc, s21_ceil_test);
  tcase_add_test(tc, s21_sin_test);
  tcase_add_test(tc, s21_cos_test);
  tcase_add_test(tc, s21_tan_test);
  tcase_add_test(tc, s21_asin_test);
  tcase_add_test(tc, s21_acos_test);
  tcase_add_test(tc, s21_atan_test);

  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
