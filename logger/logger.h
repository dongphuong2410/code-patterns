#ifndef __LOGGER_H__
#define __LOGGER_H__

typedef enum {
    LV_FATAL,
    LV_ERROR,
    LV_WARN,
    LV_INFO,
    LV_DEBUG
} level_t;

typedef enum {
    OUT_CONSOLE,
    OUT_TEXTFILE
} output_t;

void log_init(output_t output, ...);
void log_close(void);
void writelog(level_t level, const char *message, ...);

#endif
