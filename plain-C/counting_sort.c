#include <stdlib.h>
#include <stdio.h>


#define ARRAY_SIZE(X) \
         (sizeof(X)/sizeof(X[0]))

void printArray (int *arr, int start, int end)
{
     for (int i = start; i <= end; i++)
          printf("%d ", arr[i]);

     printf("\n");
}


int count_array(int *out, int *in, int k, int n)
// n - size of <in>  array
// k - size of <out> array
{
    for ( int j = 0; j < k; j++ ) out[j] = 0;
    for ( int i = 0; i < n; i++ ) out[in[i]]++;

    printf(" Count array: ");
    printArray(out,  0, k - 1);

    // Wave-count array
    for ( int j = 1; j < k; j++ ) out[j] += out[j-1];

    printf(" Wave-count array: ");
    printArray(out,  0, k - 1);

    return 0;
}

int output_array (int *out, int *in, int n, int k)
// n - size of <in> and <out> arrays
// k - maximum value of elements of <in> array
{
    int *array = malloc(n+k);

    count_array(array, in, k, n );

    for ( int i = n-1; i >= 0; i-- )
    {
        int out_value = in[i];
        int out_index = --array[out_value];
        out[out_index] = out_value; 
    }

    free(array);
    return 0;
}


