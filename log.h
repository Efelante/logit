#ifndef _LOG_H
#define _LOG_H

/* 
 * LOG_DISABLE - disable logging
 */

#include <stdio.h>

#define MAX_LEVEL 5

#undef PDEBUG
#undef PDEBUGSTRING

void log_write(unsigned char level, const char *fmt_string, ...);

#ifndef LOG_DISABLE 

#define PDEBUG(fmt, ...) printf("USER: " fmt , __VA_ARGS__)
#define PDEBUGSTRING(str) printf("USER: " str)
#define log log_write

#else

#define PDEBUG(fmt, ...)
#define PDEBUGSTRING(str)
#define log_empty(level, fmt_string, ...) 
#define log log_empty 

#endif

#endif	/* LOG */
