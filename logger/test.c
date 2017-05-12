#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

int main(int argc, char **argv)
{
    //Test log to console
    log_init(OUT_CONSOLE);
    writelog(LV_FATAL, "Log message is here %d", 1);
    writelog(LV_ERROR, "Log message is here %d", 2);
    writelog(LV_WARN, "Log message is here %d", 3);
    writelog(LV_INFO, "Log message is here %d", 4);
    writelog(LV_DEBUG, "Log message is here %d", 5);
    log_close();

    log_init(OUT_TEXTFILE, "log.out");
    writelog(LV_FATAL, "Log message is here %d", 1);
    writelog(LV_ERROR, "Log message is here %d", 2);
    writelog(LV_WARN, "Log message is here %d", 3);
    writelog(LV_INFO, "Log message is here %d", 4);
    writelog(LV_DEBUG, "Log message is here %d", 5);
    log_close();

    return 0;
}

