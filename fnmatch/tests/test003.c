#include <stdio.h>
#include <stdlib.h>

#include "fnmatch.h"

int main(int argc, char **argv)
{

    //Test 1
    char *pattern = "/home/*eo/file.txt";
    char *filepath = "/home/meo/file.txt";
    int match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 2
    pattern = "/root/meo/file.*";
    filepath = "/root/meo/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 3
    pattern = "/root/meo/*.exe";
    filepath = "/root/meo/file.exe";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 4
    pattern = "/root/m*o/file.exe";
    filepath = "/root/meo/file.exe";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //Test 5
    pattern = "/root/meo/file.*ee";
    filepath = "/root/meo/file.exe";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);


    return 0;
}

