CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage -ls21_math
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC+FLAGS) s21_math.a tests.c $(CHECK_FLAGS) -L. -ls21_math

all: clean s21_math.a test

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM

rebuild: clean all

test: s21_math.a
	$(TEST_COMPILE)
	./a.out

gcov_report: s21_math.a test
	rm -f *.g*
	$(CC+FLAGS) s21*.c tests.c s21_math.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

s21_math.a: s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a

s21_math.o:
	$(CC+FLAGS) -c s21*.c

lo:
	for i in `seq 100 $(OP)`;	do ./a.out; done;

check:
	cppcheck *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean
