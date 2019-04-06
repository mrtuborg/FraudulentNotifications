#include <stdlib.h>
#include <stdio.h>


#define ARRAY_SIZE(X) \
         (sizeof(X)/sizeof(X[0]))

int main(int args, char* argv[])
{
    int input[] = { 1, 4, 1, 2, 7, 5, 2 };
    int n = ARRAY_SIZE(input);
    int k = 10;

    int *output = malloc(n);

    printArray(input,  0, n - 1);
    output_array(output, input, n, k);
    printArray(output, 0, n - 1);

    free(output);
    return 0;
}
