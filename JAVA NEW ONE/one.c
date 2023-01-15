#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
    static char *data[4] = {"sun", "mon", "tue", "wed"};
    typedef char *(*pointer)[4];
    static pointer p1 = &data;
    static pointer p2 = &data;
    static pointer p3 = &data;

    char *(*(*array[4]))[4] = {&p1, &р2, &р3};
    char *(*(*(*ptr)[4]))[4] = &array;
    p2 += 1;
    p3 += 2;
    printf("%s", (***ptr[0]) [2]);
}