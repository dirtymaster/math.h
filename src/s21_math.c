#include "s21_math.h"

int s21_abs(int x) {
    if (x < 0) x *= -1;
    return x;
}

long double s21_fabs(double x) {
    if (x < 0) x *= -1;
    return x;
}

long double s21_exp(double x) {
    long double result = 1, temp = 1;
    long double i = 1;
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(result) > s21_EPS) {
        result *= x / i;
        i += 1;
        temp += result;
        if (temp > s21_MAX_double) {
            temp = s21_INF;
            break;
        }
    }
    temp = flag == 1 ? temp > s21_MAX_double ? 0 : 1. / temp : temp;
    return temp = temp > s21_MAX_double ? s21_INF : temp;
}

long double s21_fmod(double x, double y) {
    return (x && y) || y != 0 ? (x / y - (int)(x / y)) * y : s21_NAN;
}

double reduce_modulus(double x) {
    if (x > 2 * s21_PI || x < -2 * s21_PI) {
        x = s21_fmod(x, 2 * s21_PI);
    }
    return x;
}

long double s21_sin(double x) {
    x = reduce_modulus(x);
    long double res = 0, pow = x, fact = 1;
    // for (int i = 0; i < 1000; i++) {  // Числом 1000 задается точность
    // вычислений
    for (int i = 0; s21_fabs(pow / fact) > s21_EPS; i++) {
        res += pow / fact;
        pow *= -1 * x * x;
        fact *= (2 * (i + 1)) * (2 * (i + 1) + 1);
    }

    return res;
}

long double s21_cos(double x) {
    x = reduce_modulus(x);
    return s21_sin(s21_PI / 2 + x);
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_asin(double x) {
    double tmp = x;
    double result = x;
    if (x < -1 || x > 1) {
        result = s21_NAN;
    } else if (x == -1 || x == 1) {
        result = s21_PI / 2 * x;
    } else {
        for (long double count = 1; count < 10000000; count++) {
            tmp *= ((x * x) * (2 * count - 1) * (2 * count - 1)) /
                   ((2 * count) * (2 * count + 1));
            result += tmp;
        }
    }
    return result;
}

long double s21_acos(double x) {
    long double res;
    if (x < -1 || x > 1) {
        res = s21_NAN;
    } else if (x == -1 || x == 1) {
        res = s21_PI * (1 - x) / 2;
    } else {
        res = s21_PI / 2. - s21_asin(x);
    }
    return res;
}

long double atan_1_1(double x) {
    long double result = x, temp = x, i = 1;
    while (s21_fabs(result) > s21_EPS) {
        result = -1 * result * x * x * (2 * i - 1) / (2 * i + 1);
        i += 1;
        temp += result;
    }
    return temp;
}

long double s21_atan(double x) {
    long double temp = 0;
    if (x < 1 && x > -1 && x != 0) {
        temp = atan_1_1(x);
    } else if (x == 0) {
        temp = 0;
    } else if (x == 1) {
        temp = s21_PI / 4;
    } else if (x == -1) {
        temp = -s21_PI / 4;
    } else if (x > 1) {
        temp = s21_PI / 2 - atan_1_1(1 / x);
    } else if (x < -1) {
        temp = -s21_PI / 2 - atan_1_1(1 / x);
    }
    return temp;
}

void translate(double x, struct special *SPECIAL) {
    long double i = 1;
    int e = 0;
    SPECIAL->sign = x < 0 ? -1 : 1;
    x *= SPECIAL->sign;
    while (x >= 10) {
        x /= 10.;
        i *= 10;
        e++;
    }
    SPECIAL->mantisa = x;
    SPECIAL->pow = i;
    SPECIAL->e = e;
}

long double log_0_2(double x) {
    x--;
    long double result = x, temp = x;
    long double i = 2;
    while (s21_fabs(result) > s21_EPS) {
        result *= -x * (i - 1) / i;
        i += 1;
        temp += result;
    }
    return temp;
}

long double s21_log(double x) {
    long double res;

    if (x > 0 && x < 2) {
        res = log_0_2(x);
    } else if (x < 0) {
        res = s21_NAN;
    } else if (x == 0) {
        res = -s21_INF;
    } else {
        struct special SPECIAL;
        translate(x, &SPECIAL);
        x = SPECIAL.mantisa * SPECIAL.sign / 10;
        res = log_0_2(x) + (SPECIAL.e + 1) * s21_ln10;
    }
    return res;
}

long double s21_pow(double base, double exp) {
    long double number;
    if (base < 0) {
        if ((long int)exp == exp) {
            if (exp > 0) {
                number = base;
                for (long int i = 0; i < (long int)exp - 1; i++) {
                    number *= base;
                }
            } else if (exp == 0) {
                number = 1;
            } else {
                number = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    number /= base;
                }
            }
        } else {
            if (exp == -s21_INF || exp == s21_INF) {
                if (base * (-1) < 1) {
                    number = 0;
                } else if (base * (-1) == 1) {
                    number = 1;
                } else {
                    if (exp == -s21_INF) {
                        number = 0;
                    } else {
                        number = s21_INF;
                    }
                }
            } else {
                number = -s21_NAN;
            }
        }
    } else if (base == 0) {
        if (exp == 0) {
            number = 1;
        } else {
            number = 0;
        }
    } else if (base == 1) {
        number = 1;
    } else {
        if ((long int)exp == exp) {
            if (exp > 0) {
                number = base;
                for (long int i = 0; i < (long int)exp - 1; i++) {
                    number *= base;
                }
            } else if (exp == 0) {
                number = 1;
            } else {
                number = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    number /= base;
                }
            }
        } else {
            number = s21_exp(exp * (double)s21_log(base));
        }
    }
    return number;
}

long double s21_sqrt(double x) {
    long double result = 4, temp = 0;
    if (x < 0) {
        result = -s21_NAN;
    } else {
        while (s21_fabs(result - temp) > s21_EPS) {
            temp = result;
            result = (temp + x / temp) / 2;
        }
    }
    return result;
}

long double s21_floor(double x) {
    if (x < 0) x -= 0.9999999;
    int answer = (int)x;
    return answer;
}

long double s21_ceil(double x) {
    int xi = (int)x;
    double temp = x - xi;
    if (temp > 0.0) x += 0.9999999;
    return (int)x;
}
