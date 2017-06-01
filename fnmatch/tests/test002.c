#include <stdio.h>
#include <stdlib.h>

#include "fnmatch.h"

int main(int argc, char **argv)
{

    //Test 1
    char *pattern = "/home/*/file.txt";
    char *filepath = "/home/meo/file.txt";
    int match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 2
    pattern = "/root/meo/*/file.txt";
    filepath = "/root/meo/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 3
    pattern = "/root/meo/*";
    filepath = "/root/meo/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 4
    pattern = "/root/";
    filepath = "/root/";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 5 Error, just match absolute path
    pattern = "root";
    filepath = "/root/";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);
    return 0;
}

