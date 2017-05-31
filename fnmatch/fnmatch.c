#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "fnmatch.h"

#define MAX_PATH_LEN        256
#define MAX_DIR_LEVEL       13

typedef enum {
    ITEM_INVALID,       //Invalid file/directory name or empty
    ITEM_CHARACTER,     //Normal file/directory name, example root, home, ...
    ITEM_STAR,          //Character *, for example /home/meo/*/
    ITEM_DOUBLE_STAR,   //Double start **, represent directory recursive, for example /home/meo/**/file.txt
    ITEM_MIXED_STAR     //Filename or directory name with wildcards, for example *.txt, test00*.txt ...
} item_t;

typedef struct _pattern {
    uint8_t nitems;                       //a pattern is splitted into items by '/' or '\'
    uint8_t item_pos[MAX_DIR_LEVEL];      //this array store the position of each items
    item_t  item_type[MAX_DIR_LEVEL];     //type of items
    char str[MAX_PATH_LEN];               //String contains pattern
} pattern_t;

int fnmatch(const char *pattern, const char *filename)
{
    return 0;
}
