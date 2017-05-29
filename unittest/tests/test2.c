#include <stdio.h>
#include <stdlib.h>

void foo();
void bar();
void goo();

int main(int argc, char *argv)
{
    goo();
    bar();
    foo();
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

