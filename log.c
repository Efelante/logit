#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <stdarg.h>

#include "log.h"

static int logfd = -1;

static int log_init(void)
{
	int fd = open("./log.txt", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	if (-1 == fd)
	{
		perror("log_init");
		return -1;
	}
	
}

void log_write(uint8_t level, const char *fmt_string, ...)
{
#define BUF_SIZE 100
	char log_message[BUF_SIZE];
	va_list arg_list;

	if (level <= MAX_LEVEL)
	{
		if (-1 == logfd)
		{
			logfd = log_init();
		}
		va_start(arg_list, fmt_string);
		vsnprintf(log_message, BUF_SIZE, fmt_string, arg_list);
		write(logfd, log_message, strlen(log_message)+1);
		va_end(arg_list);
	}
}

