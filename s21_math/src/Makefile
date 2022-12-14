CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

GCOV_target=./coverage
GCOV_info=coverage.info
GCOV_FLAGS:= --coverage
RUN_TEST:=./s21_math_tests
CHECK:=$(shell pkg-config --cflags --libs check)
S21_MATH=-L. s21_math.a

all: test s21_math.a gcov_report

test: s21_math.a
	$(CC) $(CFLAGS) -o s21_math_tests s21_math_tests.c $(CHECK) $(S21_MATH)
	$(RUN_TEST)

s21_math.o:
	gcc -Wall -Wextra -Werror -c s21_math.c

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a
	rm -rf s21_math.o

gcov_report: s21_math.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_math_tests.c -o s21_math_tests $(CHECK) $(S21_MATH)
	$(RUN_TEST)
	lcov -t "s21_math library test" -c -d ./ --output-file $(GCOV_info)
	genhtml $(GCOV_info) --output-directory $(GCOV_target)
	rm -rf *.gcda *.gcno *.info


style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h

clean:
	rm -rf *.o *.a s21_math_tests *.info ./coverage

open:
	open coverage/index.html


rebuild: clean all