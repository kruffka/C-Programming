#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

// Заголовок функций для работы с count_lines_in_file
int count_lines_in_file(const char *filename);

/* Требование: Необходимо подсчитать количество строк в файле
* Тесты:
*   1. Дано: не валидный "NULL" путь до файла -> вернуть код ошибки -1
*   2. Дано: валидный путь до файла, но файла не удалось открыть -> вернуть код ошибки -2
*   3. Дано: валидный путь до файла, файл создан и его удалось открыть.
*            Количество строк в файле 10 -> вернуть количество строк в файле = 10
*   4. Дано: валидный путь до файла, файл создан и его удалось открыть.
*            Количество строк в файле 4 -> вернуть количество строк в файле = 4
*   5. Дано: валидный путь до файла, файл создан и его удалось открыть. 
*            Количество строк в файле 0 -> вернуть количество строк в файле = 0
*/
static void test_file1(void **state) {
    (void)state;

    char *filename = NULL;
    assert_int_equal(count_lines_in_file(filename), -1);
}

static void test_file2(void **state) {
    (void)state;

    char *filename = "/tmp/qqqqqqq"; // будем надеяться что такого файла нет
    assert_int_equal(count_lines_in_file(filename), -2);
}

static void test_file3(void **state) {
    (void)state;

    char *filename = "./file_10.txt";
    assert_int_equal(count_lines_in_file(filename), 10);
}

static void test_file4(void **state) {
    (void)state;

    char *filename = "./file_4.txt";
    assert_int_equal(count_lines_in_file(filename), 4);
}

static void test_file5(void **state) {
    (void)state;

    char *filename = "./empty.txt";
    assert_int_equal(count_lines_in_file(filename), 0);
}

int main(void) {

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_file1),
        cmocka_unit_test(test_file2),
        cmocka_unit_test(test_file3),
        cmocka_unit_test(test_file4),
        cmocka_unit_test(test_file5),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}