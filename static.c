#include <stdio.h>

static int count = 0;

void increment() {
    count++;
}

int main() {

    printf("count = %d\n", count);
    increment();
    printf("count = %d\n", count);
    increment();
    printf("count = %d\n", count);

    return 0;
}