#include "s21_math.h"

int s21_abs(int x) {
  x < 0 ? x = -x : x;
  return x;
}

long double s21_exp(double x) {
  long double res = 1.0;
  int n = 1;
  double value = x;
  long double add_value = 1.0;
  x == s21_INF    ? res = s21_INF
  : x == -s21_INF ? res = 0.0
  : x != x        ? res = s21_NaN
                  : res;
  if (x != s21_NaN && x != s21_INF && x != -s21_INF) {
    if (x < 0.0) value = -x;
    while (add_value > s21_EPS) {
      add_value *= value / n++;
      res += add_value;
      if (res == s21_INF || res == -s21_INF) {
        break;
      }
    }
    if (x < 0.0) res = 1 / res;
  }
  return res;
}

long double s21_fabs(double x) {
  x < 0.0 ? x = -x : x;
  return x;
}

long double s21_log(double x) {
  double limit_range = 0.0;
  double res = 0.0;
  if (x < 0 || x != x) {
    res = s21_NaN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == 0.0 || x == -s21_INF) {
    res = -s21_INF;
  } else {
    while (x > 1.0) {
      x /= s21_E;
      limit_range++;
    }
    while (x < 0.25) {
      x *= s21_E;
      limit_range--;
    }
    x -= 1.0;
    double series = 1.0;
    double value = x;
    for (int i = 1; i <= 100; i++) {
      res += value * series / i;
      value *= x;
      series = -series;
    }
  }
  return res + limit_range;
}

long double s21_pow(double base, double exp) {
  double res = 0;
  if (base < 0 && base != -s21_INF) {
    base = -base;
  }
  if (base == -s21_INF) {
    res = base;
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0.0;
  if (x != 0) {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = x;
  if (x == x && x != s21_INF && x != -s21_INF && y != 0.0 && y != s21_INF &&
      y != -s21_INF) {
    long double x_mod = s21_fabs(x);
    long double y_mod = s21_fabs(y);
    while (x_mod > y_mod) x_mod -= y_mod;
    if (x < 0) x_mod = -x_mod;
    res = x_mod;
  }
  if (y != y || x != x || x == s21_INF || x == -s21_INF || y == 0.0)
    res = s21_NaN;
  return res;
}

long double s21_floor(double x) {
  int x_integer = x;
  double res = 0.0;
  if (x != x) {
    res = s21_NaN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == -s21_INF) {
    res = -s21_INF;
  } else if (x == -0.0) {
    res = x;
  } else {
    if (x < 0) {
      x_integer -= 1;
    }
    res = x_integer;
  }
  return res;
}

long double s21_ceil(double x) {
  int x_integer = x;
  double rem = x - x_integer;
  if (x < 0) {
    rem = -rem;
  }
  double res = 0.0;
  if (x != x) {
    res = s21_NaN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == -s21_INF) {
    res = -s21_INF;
  } else {
    if (x < 0.0) {
      res = x + rem;
      if (res == 0.0) {
        res = -res;
      }
    } else if (x > 0.0 && x != 0.0) {
      if (rem > 0.0) {
        res = x_integer + 1;
      } else {
        res = x_integer;
      }
    } else if (x == -0.0) {
      res = x;
    }
  }
  return res;
}

long double s21_sin(double x) {
  int x_sign = -1;
  if (x > 0) x_sign = 1;
  x *= x_sign;
  if (x > s21_PI) {
    x -= 2 * s21_PI * s21_floor(x / (2 * s21_PI));
  }
  long double temp = x;
  long double sum = x;
  unsigned int fact = 1;
  while (s21_fabs(temp) > s21_EPS * s21_EPS) {
    temp /= (fact + 1) * (fact + 2);
    fact += 2;
    temp *= -x * x;
    sum += temp;
  }
  return sum * x_sign;
}

long double s21_cos(double x) { return s21_sin(s21_PI / 2 - x); }

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_asin(double x) {
  double res = x, temp = x;
  int n = 1;
  if (x != x || x == s21_INF || x == -s21_INF || x > 1 || x < -1) {
    res = s21_NaN;
  } else {
    if (x == 1) {
      res = s21_PI / 2;
    } else if (x == -1) {
      res = -s21_PI / 2;
    } else {
      while (!(temp >= -s21_EPS && temp <= s21_EPS)) {
        temp = ((temp) * (x * x) * (2 * n - 1) * (2 * n - 1)) /
               ((2 * n + 1) * (2 * n));
        res = res + temp;
        n++;
      }
    }
  }
  return res;
}

long double s21_acos(double x) {
  long double res;
  res = (s21_PI / 2) - s21_asin(x);
  return res;
}

long double s21_atan(double x) {
  long double res = 0;

  if (x == 1) {
    res = s21_PI / 4;
  } else if (x == -1) {
    res = -s21_PI / 4;
  } else if (x != x) {
    res = s21_NaN;
  } else if (x == s21_INF) {
    res = s21_PI / 2;
  } else if (x == -s21_INF) {
    res = -s21_PI / 2;
  } else {
    long double a = x;
    if (s21_fabs(x) > 1) a = 1 / x;
    if (x < 0.0) a = -a;
    int n = 1;
    res = a;
    long double sn = a;
    while (1) {
      sn *= -1.0 * a * a;
      long double temp = sn / (2 * n++ + 1);
      if (s21_fabs(temp) < s21_EPS) {
        break;
      };
      res += temp;
    }
    if (s21_fabs(x) > 1) res = s21_PI / 2 - res;
    if (x < 0) res *= -1;
  }
  return res;
}
