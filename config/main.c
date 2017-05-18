#include <stdio.h>
#include <stdlib.h>

#include "config.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage : main <config_file>\n");
        exit(0);
    }
    config_t *c = cfg_init(argv[1]);

    printf("filename : %s\n", cfg_get_str(c, "filename"));
    printf("max file : %d\n", cfg_get_int(c, "max_file"));

    cfg_close(c);
    return 0;
}
