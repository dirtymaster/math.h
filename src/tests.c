#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_ceil_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = -0;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = 0.000001;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = -0.000001;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = -0.999999;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = 12.123456;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
    value = -31.654321;
    ck_assert_ldouble_eq_tol(s21_ceil(value), ceill(value), 1e-7);
}
END_TEST

START_TEST(s21_floor_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = -0;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = 0.000001;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = -0.000001;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = -0.999999;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = 12.123456;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
    value = -31.654321;
    ck_assert_ldouble_eq_tol(s21_floor(value), floorl(value), 1e-7);
}
END_TEST

START_TEST(s21_tan_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_tan(value), tanl(value), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001) {
        ck_assert_ldouble_eq_tol(s21_tan(i), tanl(i), 1e-7);
    }
}
END_TEST

START_TEST(s21_cos_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e76);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_cos(value), cosl(value), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001) {
        ck_assert_ldouble_eq_tol(s21_cos(i), cosl(i), 1e-7);
    }
}
END_TEST

START_TEST(s21_sin_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_sin(value), sinl(value), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001) {
        ck_assert_ldouble_eq_tol(s21_sin(i), sinl(i), 1e-7);
    }
}
END_TEST

START_TEST(s21_abs_f) {
    int value = 0;
    ck_assert_int_eq(s21_abs(value), abs(value));
    value = 1;
    ck_assert_int_eq(s21_abs(value), abs(value));
    value = 123456;
    ck_assert_int_eq(s21_abs(value), abs(value));
    value = -654321;
    ck_assert_int_eq(s21_abs(value), abs(value));
    value = 2147483647;
    ck_assert_int_eq(s21_abs(value), abs(value));
    value = -2147483647;
    ck_assert_int_eq(s21_abs(value), abs(value));
    for (int i = -100; i < 100; i++) ck_assert_int_eq(s21_abs(i), abs(i));
}
END_TEST

START_TEST(s21_atan_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = -1;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = -0.654321;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_atan(value), atanl(value), 1e-7);
    for (double i = -1; i <= 1; i += 0.01) {
        ck_assert_ldouble_eq_tol(s21_atan(i), atanl(i), 1e-7);
    }
}
END_TEST

START_TEST(s21_acos_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_acos(value), acosl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_acos(value), acosl(value), 1e-7);
    value = -1;
    ck_assert_ldouble_eq_tol(s21_acos(value), acosl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_acos(value), acosl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_acos(value), acosl(value), 1e-7);
    value = -50;
    ck_assert_int_eq(s21_acos(value) == NAN, acosl(value) == NAN);
    value = 50;
    ck_assert_int_eq(s21_acos(value) == NAN, acosl(value) == NAN);
}
END_TEST

START_TEST(s21_asin_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_asin(value), asinl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_asin(value), asinl(value), 1e-7);
    value = -1;
    ck_assert_ldouble_eq_tol(s21_asin(value), asinl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_asin(value), asinl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_asin(value), asinl(value), 1e-7);
    value = -50;
    ck_assert_int_eq(s21_asin(value) == NAN, asinl(value) == NAN);
}
END_TEST

START_TEST(s21_fmod_f) {
    ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                             1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1),
                             fmod(36677.546546, 4.1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(23.456, -4.355), fmod(23.456, -4.355),
                             1e-7);
}
END_TEST

START_TEST(s21_exp_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    value = -0.654321;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq(s21_exp(value), expl(value));
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_exp(value), expl(value), 1e-7);
    for (double i = -10; i < 10; i++)
        ck_assert_ldouble_eq_tol(s21_exp(i), expl(i), 1e-7);
}
END_TEST

START_TEST(s21_log_f) {
    double value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_log(value), logl(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_log(value), logl(value), 1e-7);
    value = 1.999999;
    ck_assert_ldouble_eq_tol(s21_log(value), logl(value), 1e-7);
    value = 2;
    ck_assert_ldouble_eq_tol(s21_log(value), logl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_log(value), logl(value), 1e-7);
    value = -50;
    ck_assert_int_eq(s21_log(value) == NAN, logl(value) == NAN);
    value = 0;
    ck_assert_int_eq(s21_log(value) == -INFINITY, logl(value) == -INFINITY);
}
END_TEST

START_TEST(s21_sqrt_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_sqrt(value), sqrtl(value), 1e-7);
    value = 16.;
    ck_assert_ldouble_eq_tol(s21_sqrt(value), sqrtl(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_sqrt(value), sqrtl(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_sqrt(value), sqrtl(value), 1e-7);
    value = 0.999999;
    ck_assert_ldouble_eq(s21_sqrt(value), sqrtl(value));
    value = -50;
    ck_assert_int_eq(s21_sqrt(value) == NAN, sqrtl(value) == NAN);
    for (double i = 0; i <= 1000; i++)
        ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrtl(i), 1e-7);
}
END_TEST

START_TEST(s21_pow_f) {
    ck_assert_ldouble_eq_tol(s21_pow(0, 0.), pow(0, 0.), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 0.), pow(2.6, 0.), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(1, 2.6), pow(1, 2.6), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(0., 2.6), pow(0., 2.6), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-7);
    ck_assert_ldouble_eq(s21_pow(-2.6, -INFINITY), pow(-2.6, -INFINITY));
    ck_assert_ldouble_eq(s21_pow(-2.6, INFINITY), pow(-2.6, INFINITY));
    ck_assert_ldouble_eq(s21_pow(-1, INFINITY), pow(-1, INFINITY));
    ck_assert_ldouble_eq(s21_pow(-0.123456, INFINITY), pow(-0.123456, INFINITY));
    ck_assert_int_eq(s21_pow(-2.6, 3.45) == NAN, pow(-2.6, 3.45) == NAN);
    ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-2, 0), pow(-2, 0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(3.0, -14.0), pow(3.0, -14.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 1e-7);
    ck_assert_ldouble_eq(s21_pow(123456, -654321), pow(123456, -654321));
}
END_TEST

START_TEST(s21_fabs_f) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = -0.654321;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    for (double i = -100; i < 100; i += 0.1)
        ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), 1e-7);
}
END_TEST

Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("Func Check");

    TCase *tc_ceil;
    TCase *tc_floor;
    TCase *tc_tan;
    TCase *tc_cos;
    TCase *tc_sin;
    TCase *tc_abs;
    TCase *tc_atan;
    TCase *tc_acos;
    TCase *tc_asin;
    TCase *tc_fmod;
    TCase *tc_exp;
    TCase *tc_log;
    TCase *tc_sqrt;
    TCase *tc_pow;
    TCase *tc_fabs;

    tc_fabs = tcase_create("Fabs func");
    suite_add_tcase(s, tc_fabs);
    tcase_add_test(tc_fabs, s21_fabs_f);

    tc_pow = tcase_create("Pow func");
    suite_add_tcase(s, tc_pow);
    tcase_add_test(tc_pow, s21_pow_f);

    tc_sqrt = tcase_create("Sqrt func");
    suite_add_tcase(s, tc_sqrt);
    tcase_add_test(tc_sqrt, s21_sqrt_f);

    tc_log = tcase_create("Log func");
    suite_add_tcase(s, tc_log);
    tcase_add_test(tc_log, s21_log_f);

    tc_exp = tcase_create("Exp func");
    suite_add_tcase(s, tc_exp);
    tcase_add_test(tc_exp, s21_exp_f);

    tc_fmod = tcase_create("Fmod func");
    suite_add_tcase(s, tc_fmod);
    tcase_add_test(tc_fmod, s21_fmod_f);

    tc_asin = tcase_create("Asin func");
    suite_add_tcase(s, tc_asin);
    tcase_add_test(tc_asin, s21_asin_f);

    tc_acos = tcase_create("Acos func");
    suite_add_tcase(s, tc_acos);
    tcase_add_test(tc_acos, s21_acos_f);

    tc_atan = tcase_create("Atan func");
    suite_add_tcase(s, tc_atan);
    tcase_add_test(tc_atan, s21_atan_f);

    tc_abs = tcase_create("Abs func");
    suite_add_tcase(s, tc_abs);
    tcase_add_test(tc_abs, s21_abs_f);

    tc_sin = tcase_create("Sin func");
    suite_add_tcase(s, tc_sin);
    tcase_add_test(tc_sin, s21_sin_f);

    tc_cos = tcase_create("Cos func");
    suite_add_tcase(s, tc_cos);
    tcase_add_test(tc_cos, s21_cos_f);

    tc_tan = tcase_create("Tan func");
    suite_add_tcase(s, tc_tan);
    tcase_add_test(tc_tan, s21_tan_f);

    tc_floor = tcase_create("Floor func");
    suite_add_tcase(s, tc_floor);
    tcase_add_test(tc_floor, s21_floor_f);

    tc_ceil = tcase_create("Ceil func");
    suite_add_tcase(s, tc_ceil);
    tcase_add_test(tc_ceil, s21_ceil_f);

    return s;
}

int main(void) {
    Suite *s;
    SRunner *sr;

    s = lib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    srunner_free(sr);
    return 0;
}
