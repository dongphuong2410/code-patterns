#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

int main(int argc, char **argv)
{
    //Test log to console
    log_init(OUT_CONSOLE);
    writelog(LV_DEBUG, "This line should be display %d\n", 0);
    return 0;
}
