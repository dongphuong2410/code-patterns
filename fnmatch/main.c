#include <stdio.h>
#include <stdlib.h>

#include "fnmatch.h"

int main(int argc, char **argv)
{

    if (argc < 3) {
        printf("<usage> : fnmatch <pattern> <filepath>\n");
        exit(0);
    }
    char *pattern = argv[1];
    char *filepath = argv[2];

    int match = fnmatch(pattern, filepath);
    printf("%s\n", match ? "Match" : "Not match");
    return 0;
}

