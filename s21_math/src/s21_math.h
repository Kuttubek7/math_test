#ifndef S21_MATH_S21_MATH_H
#define S21_MATH_S21_MATH_H

#define s21_NaN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_PI 3.14159265358979323846
#define s21_EPS 1e-07
#define s21_E 2.718281828459045

int s21_abs(int x);  // вычисляет абсолютное значение целого числа
long double s21_acos(double x);  // Вычисляет арккосинус. Аргумент для acos
                                 // должен находиться в отрезке [-1,1].
long double s21_asin(double x);  // Вычисляет арксинус. Аргумент для asin должен
                                 // находиться в отрезке [-1,1].
long double s21_atan(double x);  // вычисляет арктангенс.
long double s21_ceil(double x);  // возвращает ближайшее целое число, не меньшее
                                 // заданного значения
long double s21_cos(double x);   // вычисляет косинус
long double s21_exp(
    double x);  // возвращает значение e, возведенное в заданную степень
long double s21_fabs(
    double x);  // вычисляет абсолютное значение числа с плавающей точкой
long double s21_floor(double x);  // возвращает ближайшее целое число, не
                                  // превышающее заданное значение
long double s21_fmod(double x,
                     double y);  // остаток операции деления с плавающей точкой
long double s21_log(double x);  // вычисляет натуральный логарифм
long double s21_pow(double base,
                    double exp);  // возводит число в заданную степень
long double s21_sin(double x);  // вычисляет синус
long double s21_sqrt(double x);  // вычисляет квадратный корень
long double s21_tan(double x);  // вычисляет тангенс

#endif  // S21_MATH_S21_MATH_H
