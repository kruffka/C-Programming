#ifndef _LOG_H_
#define _LOG_H_

#define MY_LOG(type, str) my_log(type, str, __FILE__, __LINE__)

// type - значение самой type, #type - значение переменной в виде строки, a##b - конкатенация двух значений
#define MY_LOG2(type, str) my_log2(type, #type, str)

#define MY_LOG3(type, str) my_log3(type, #type, str)

typedef enum log_color {
    INFO = 0, // зеленый
    WARNING, // жёлтый
    ERROR, // красный
    DEBUG, // синий
    END
} log_type_e;

void my_print(char *str, char *color);

int my_log(log_type_e type, char *str, char *file, int line);

int my_log2(log_type_e type, char *type_s, char *str);

int my_log3(log_type_e type, char *type_s, char *str);

int log_init(char *filepath);

void log_deinit(void);

#endif // _LOG_H_