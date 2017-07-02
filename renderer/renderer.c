#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "renderer.h"

#define MAX_COL 20
#define MAX_ROW 1000

struct _rd {
    uint16_t header_no;
    char *headers[MAX_COL];
    char *formats[MAX_COL];
    uint16_t items_no;
    char *items[MAX_COL * MAX_ROW];
};

rd_t *rd_init(void)
{
    rd_t *rd = (rd_t *)calloc(1, sizeof(rd_t));
    rd->header_no = 0;
    rd->items_no = 0;
}

int main(int argc, char **argv)
{
    return 0;
}
