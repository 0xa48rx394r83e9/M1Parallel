#include <stdio.h>
#include "parallel_lib/shared_memory/parallel_for.h"

void print_number(int num)
{
    printf("Number: %d\n", num);
}

int main()
{
    parallel_for(0, 10, print_number);
    return 0;
}