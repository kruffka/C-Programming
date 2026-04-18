#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include "example.h"

// Сумма двух целых чисел:
// 1 + 2 = 3
static void test_sum(void **state) {
    (void)state; /* unused */

    // arrange
    int a = 1;
    int b = 2;

    // act
    int func_sum = sum(a, b);
    int real_sum = a + b; // или просто 3

    // assert
    assert_int_equal(func_sum, real_sum);
}

// Целочисленное деление 2 чисел
static void test_divide(void **state) {
    (void)state; /* unused */

    assert_int_equal(divide(5, 2), 5 / 2);
    assert_int_equal(divide(5, 0), 0);
}

// Разные assert'ы (см. документацию cmocka)
static void test_asserts(void **state) {
    (void)state; /* unused */

    // boolean
    assert_true(1);  // 1 == true
    assert_false(0); // 0 == false
    //

    // int
    assert_int_equal(5, 5);
    assert_int_not_equal(1, 5);

    // pointers
    assert_null(NULL);
    assert_non_null(0x1);

    // return code
    enum {
        returnOK,
        returnError,
    };
    int rc = returnOK;
    assert_return_code(rc, returnError);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sum),
        cmocka_unit_test(test_divide),
        cmocka_unit_test(test_asserts),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}