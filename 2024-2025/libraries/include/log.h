#ifndef _LOG_H_
#define _LOG_H_

#define MY_LOG(type, str) my_log(type, str, __FILE__, __LINE__)

// type - значение самой type, #type - значение переменной в виде строки, a##b - конкатенация двух значений
#define MY_LOG2(type, str) my_log2(type, #type, str)

#define LOG_I(str) my_log3(INFO, "INFO", str)
#define LOG_D(str) my_log3(DEBUG, "DEBUG", str)
#define LOG_E(str) my_log3(ERROR, "ERROR", str)

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

int log_init(char *filepath, log_type_e log_level);

void log_deinit(void);

#endif // _LOG_H_