#include <stdio.h>
#include <stdlib.h>

#include "fnmatch.h"

int main(int argc, char **argv)
{

    //Test 1
    char *pattern = "/**/file.txt";
    char *filepath = "/home/file.txt";
    int match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //test 2
    pattern = "/**/file.txt";
    filepath = "/home/meo/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //test 3
    pattern = "/**/file.txt";
    filepath = "/home/meo/file1.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //test 4
    pattern = "/home/**/file.txt";
    filepath = "/home/meo/test/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);

    //test 5
    pattern = "/home/**/test/**/file.txt";
    filepath = "/home/meo/level1/test/computer/hi/file.txt";
    match = fnmatch(pattern, filepath);
    printf("%d\n", match);


    return 0;
}

