#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#define MAX_COMMAND 4096

void start_background_system(void);
void background_system_process(void);
void background_system_msg(const char *msg);
#endif //_BACKGROUND_H_