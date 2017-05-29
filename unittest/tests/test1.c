#include <stdio.h>
#include <stdlib.h>

void foo();
void bar();
void goo();

int main(int argc, char *argv)
{
    foo();
    bar();
    goo();
}

void foo()
{
    printf("foo\n");
}

void bar()
{
    printf("bar\n");
}

void goo()
{
    printf("goo\n");
}

