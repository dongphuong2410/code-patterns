#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "logger.h"

void _log_to_console(const char *message, va_list args);
void _log_to_file(const char *message, va_list args);

void (*log_fc)(const char *message, va_list args);

void log_init(output_t output, ...)
{
    switch (output) {
        case OUT_CONSOLE:
            log_fc = _log_to_console;
            break;
        case OUT_TEXTFILE:
            log_fc = _log_to_file;
            break;
    }
}

void log_close(void)
{
}

void writelog(level_t level, const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_fc(message, args);
    va_end(args);
}

void _log_to_console(const char *message, va_list args)
{
    vprintf(message, args);
}

void _log_to_file(const char *message, va_list args)
{
    printf("Log to file\n");
}
