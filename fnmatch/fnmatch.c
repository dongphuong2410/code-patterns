#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "fnmatch.h"

#define MAX_PATH_LEN        256
#define MAX_DIR_LEVEL       13

#define ITEM_LEN(splits, idx) (splits->item_pos[idx + 1] - splits->item_pos[idx])
#define ITEM(splits, idx) (splits->str + splits->item_pos[idx])
#define ITEM_TYPE(splits, idx) (splits->item_type[idx])

typedef enum {
    ITEM_INVALID,       //Invalid file/directory name or empty
    ITEM_CHARACTER,     //Normal file/directory name, example root, home, ...
    ITEM_STAR,          //Character *, for example /home/meo/*/
    ITEM_DOUBLE_STAR,   //Double start **, represent directory recursive, for example /home/meo/**/file.txt
    ITEM_MIXED_STAR     //Filename or directory name with wildcards, for example *.txt, test00*.txt ...
} item_t;

typedef struct _splits {
    uint8_t nitems;                       //a pattern is splitted into items by '/' or '\'
    uint8_t item_pos[MAX_DIR_LEVEL];      //this array store the position of each items
    item_t  item_type[MAX_DIR_LEVEL];     //type of items
    char str[MAX_PATH_LEN];               //String contains pattern
} itemlist_t;

typedef enum {
    MATCH,
    NOT_MATCH,
    ERROR
} status_t;

/**
  * @brief Process the full path : split the directory name into items, identify each item type (*, ** or chars ...)
  * @param str String pattern
  * @param is_pattern True if this is a pattern
  * @return Return pattern struct if success, return NULL if error
  */
itemlist_t *_translate(const char *str, uint8_t is_pattern);

/**
  * @brief Matching a filepath (splits) against a pattern
  * @return 1 if matched, 0 if not matched
  */
int _match(itemlist_t *pattern, itemlist_t *filepath);

/**
  * @brief Matching a split of filepath (at fidx position) against a split of pattern (at pidx position)
  * @return 1 if match, 0 if not match
  */
int _match_item(itemlist_t *pattern, uint8_t pidx, itemlist_t *filepath, uint8_t fidx);

/**
  * @brief Find item type of a directory/file name
  * @param str Full filepath path
  * @param start : first index of the item
  * @param end : last index of the item
  */
item_t _find_item_type(const char *str, uint8_t start, uint8_t end);

int fnmatch(const char *str_pattern, const char *str_filepath)
{
    status_t status;
    itemlist_t *pattern = _translate(str_pattern, 1);
    itemlist_t *filepath = _translate(str_filepath, 0);
    if (!pattern || !filepath) {
        return -1;
    }
    int match = _match(pattern, filepath);

    free(pattern);
    free(filepath);
    if (match)
        return 0;
    else
        return 1;
}

itemlist_t *_translate(const char *str, uint8_t is_pattern)
{
    const char *strPtr = str;
    itemlist_t *pattern = (itemlist_t *)calloc(1, sizeof(itemlist_t));
    char ch;

    if (*strPtr != '/' && *strPtr != '\\') {
        fprintf(stderr, "Translate Error : Work only with absolute path\n");
        goto error;
    }
    const char *last_slash = strPtr;
    char *destPtr = pattern->str;
    strPtr++;

    int cnt = 0;
    while (*strPtr) {
        ch = *strPtr;
        if (ch == '/' || ch == '\\') {      //Meet the slash
            if (strPtr - last_slash == 1) {
                goto error;
            }
            else {
                last_slash =strPtr;
            }
        }
        else if (strPtr - last_slash == 1) {   //Meet first character of one item
            pattern->item_pos[pattern->nitems] = destPtr - pattern->str;
            *destPtr++ = ch;
            pattern->nitems++;
        }   //In the middle of one item
        else {
            *destPtr++ = ch;
        }
        strPtr++;
    }
    //Mark end of pattern
    pattern->item_pos[pattern->nitems] = destPtr - pattern->str;

    if (is_pattern) {
        //Identify item types
        int i, j;
        for (i = 0; i < pattern->nitems; i++) {
            pattern->item_type[i] = _find_item_type(pattern->str, pattern->item_pos[i], pattern->item_pos[i + 1]);
        }
    }
    goto done;
error:
    free(pattern);
    pattern = NULL;
done:
    return pattern;
}

item_t _find_item_type(const char *str, uint8_t start, uint8_t end)
{
    int len = end - start;
    if (len == 1 && str[start] == '*') {
        return ITEM_STAR;
    }
    else if (len == 2 && str[start] == '*' && str[start + 1] == '*') {
        return ITEM_DOUBLE_STAR;
    }
    else {
        int i;
        for (i = start; i < end; i++) {
            if (str[i] == '*') {
                return ITEM_MIXED_STAR;
            }
        }
    }
    return ITEM_CHARACTER;
}

int _match(itemlist_t *pattern, itemlist_t *filepath)
{
    int match = 1;
    int pidx = 0;
    int fidx = 0;
    while (fidx < filepath->nitems) {
        if (pidx >= pattern->nitems) {
            match = 0;
            break;
        }
        if (!_match_item(pattern, pidx, filepath, fidx)) {
            match = 0;
            break;
        }
        fidx++;
        pidx++;
    }
    if (pidx < pattern->nitems) {
        match = 0;
    }
    return match;
}

int _match_item(itemlist_t *pattern, uint8_t pidx, itemlist_t *filepath, uint8_t fidx)
{
    item_t type = ITEM_TYPE(pattern, pidx);
    if (type == ITEM_CHARACTER) {
        int plen = ITEM_LEN(pattern, pidx);
        int flen = ITEM_LEN(filepath, fidx);
        if (plen == flen) {
            int cmp = strncmp(ITEM(pattern, pidx), ITEM(pattern, fidx), plen);
            if (!cmp)
                return 1;
        }
    }
    else if (type == ITEM_STAR) {
    }
    return 0;
}
