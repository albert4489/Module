#include <check.h>
#include "../src/lib.h"

// Тест для функції isOperator
START_TEST(test_isOperator)
{
    ck_assert_int_eq(isOperator('+'), 1);
    ck_assert_int_eq(isOperator('-'), 1);
    ck_assert_int_eq(isOperator('*'), 1);
    ck_assert_int_eq(isOperator('/'), 1);
    ck_assert_int_eq(isOperator('%'), 1);
    ck_assert_int_eq(isOperator('^'), 1);
    ck_assert_int_eq(isOperator('a'), 0); // Перевірка символу, який не є оператором
}
END_TEST

// Тест для функції getPriority
START_TEST(test_getPriority)
{
    ck_assert_int_eq(getPriority('+'), 1);
    ck_assert_int_eq(getPriority('-'), 1);
    ck_assert_int_eq(getPriority('*'), 2);
    ck_assert_int_eq(getPriority('/'), 2);
    ck_assert_int_eq(getPriority('%'), 2);
    ck_assert_int_eq(getPriority('^'), 3);
    ck_assert_int_eq(getPriority('a'), 0); // Перевірка символу, який не є оператором
}
END_TEST

// Тест для функції primeperation
START_TEST(test_primeoperation)
{
    ck_assert_int_eq(primeoperation(2, 3, '+'), 5);
    ck_assert_int_eq(primeoperation(5, 2, '-'), 3);
    ck_assert_int_eq(primeoperation(4, 5, '*'), 20);
    ck_assert_int_eq(primeoperation(10, 2, '/'), 5);
    ck_assert_int_eq(primeoperation(10, 3, '%'), 1);
    ck_assert_int_eq(primeoperation(2, 3, '^'), 8);
    ck_assert_int_eq(primeoperation(2, 3, 'a'), 0); // Перевірка невідомого оператора
}
END_TEST

// Тест для функції calculator
START_TEST(test_calculator)
{
    char formula[] = "(4+8)*(6-5)/((3-2)*(2+2))";
    int result = calculator(formula);
    ck_assert_int_eq(result, 3);
}
END_TEST

Suite *lib_suite(void)
{
    Suite *suite;
    TCase *tcase;

    suite = suite_create("Library");

    // Додавання тестових випадків для кожної функції
    tcase = tcase_create("isOperator");
    tcase_add_test(tcase, test_isOperator);
    suite_add_tcase(suite, tcase);

    tcase = tcase_create("getPriority");
    tcase_add_test(tcase, test_getPriority);
    suite_add_tcase(suite, tcase);

    tcase = tcase_create("primeoperation");
    tcase_add_test(tcase, test_primeoperation);
    suite_add_tcase(suite, tcase);

    tcase = tcase_create("calculator");
    tcase_add_test(tcase, test_calculator);
    suite_add_tcase(suite, tcase);

    return suite;
}

int main(void)
{
    int number_failed;
    Suite *suite;
    SRunner *runner;

    suite = lib_suite();
    runner = srunner_create(suite);
    srunner_run_all(runner, CK_VERBOSE);
	number_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
