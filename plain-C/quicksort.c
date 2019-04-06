#include <stdio.h>

#define ARRAY_SIZE(X) \
        (sizeof(X)/sizeof(X[0])) 

void xchg(int *x, int *y)
{
    if (x == y) return;

    printf("exchange: %d, %d\n",*x ,*y);
    *x = *y + *x;
    *y = *x - *y;
    *x = *x - *y;

}

void printArray (int *arr, int start, int end)
{
     for (int i = start; i <= end; i++)
          printf("%d ", arr[i]);

     printf("\n");
}

int hoare_partitionning(int *arr, int left, int right)
{
    int i = left  - 1;
    int j = right + 1;
    int pivot = arr[(i + j) / 2];

    do {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (  i >= j ) break;
        
        xchg(&arr[i], &arr[j]);
    
    } while (1);
    
    return j;
}

int lomuto_partitionning(int *arr, int left, int right)
{
	int pivot = arr[right];
    int iter  = left - 1;   // index of smallest element
    
    printf("iter:  %d\n", iter);
    printf("pivot: %d\n", pivot);
    printArray(arr, left, right);

	for (int i = left; i < right; i++)
	{
        if (arr[i] <= pivot) {
            iter++;
            xchg(&arr[i], &arr[iter]);
            printArray(arr, left, right);
        } 
    }

    xchg(&arr[iter + 1], &arr[right]);

    printArray(arr, left, right);
    printf("======== %d ==========\n", iter + 1);

    return iter + 1;
}

int quicksort(int *arr, int start, int end)
{
    if (start < end) {
        printf("partitioning: [ %d, %d ]\n", start, end);
        int pi = hoare_partitionning (arr, start, end);
        printf("left:  [[[ %d, %d ]]]\n", start, pi - 1);
        quicksort(arr, start,     pi - 1);
        printf("right: [[[ %d, %d ]]]\n", pi + 1, end);
        quicksort(arr, pi + 1, end);
    }

    return 0;
}


int main(int args, char *argv[])
{
    int arr[] = {3,4,3,7,2,8,6,0,9,1};
    quicksort(arr, 0, ARRAY_SIZE(arr) - 1);

    printArray(arr, 0, 9);
	return 0;
}

