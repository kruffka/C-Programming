#ifndef _LOG_H_
#define _LOG_H_

#define MY_LOG(type, str) my_log(type, str, __FILE__, __LINE__)

// type - значение самой type, #type - значение переменной, ##type - имя переменной
#define MY_LOG2(type, str) my_log2(type, #type, str)

typedef enum log_color {
    INFO = 0, // зеленый
    WARNING, // жёлтый
    ERROR, // красный
    DEBUG, // синий
    END
} log_type_e;

void my_print(char *str, char *color);

void my_log(log_type_e type, char *str, char *file, int line);

void my_log2(log_type_e type, char *type_s, char *str);

#endif // _LOG_H_