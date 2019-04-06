#include <iostream>
#include "MyArray.hpp"

inline void myArray::xchg(int *x, int *y)
{
    if (x == y) return;

    std::cout << "exchange: " << *x << "," << *y << std::endl;
    *x = *y + *x;
    *y = *x - *y;
    *x = *x - *y;

}

void myArray::printArray (void *in, int start, int end)
{
    if ((start == -1 ) || (end == -1))
    {
        start = 0;
        end = size -1;
    }

    for (int i = start; i <= end; i++)
          std::cout << ((int*)in)[i] << " ";

    std::cout << std::endl;
}

void myArray::printArray()
{
     printArray(arr);
}

int myArray::hoare_partitionning(int left, int right)
{
    int i = left  - 1;
    int j = right + 1;
    int pivot = arr[(i + j) / 2];

    std::cout << "pivot = " << pivot << std::endl;
    std::cout << "i,j = " << i << "," << j << std::endl;

    do {
        do {
            i++;
            std::cout << arr[i] << std::endl;
        } while (arr[i] < pivot);
        std::cout << "i = " << i << std::endl;
        
        do {
            j--;
            std::cout << arr[j] << std::endl;
        } while (arr[j] > pivot);
        std::cout << "j = " << j << std::endl;

        if (  i >= j ) break;
        
        xchg(&arr[i], &arr[j]);
        printArray(arr, left, right); 
    } while (true);
    
    return j;
}

int myArray::lomuto_partitionning(int left, int right)
{
	int pivot = arr[right];
    int iter  = left - 1;   // index of smallest element
    
    std::cout << "iter: " << iter << std::endl;
    std::cout << "pivot: " << pivot << std::endl;
    printArray(arr, left, right);

	for (int i = left; i < right; i++)
	{
        if (arr[i] <= pivot) {
            std::cout << arr[i] << " <= " << pivot << std::endl;
            iter++;
            xchg(&arr[i], &arr[iter]);
            printArray(arr, left, right);
            std::cout << "iter: " << iter << std::endl;
        } else std::cout << arr[i] << " > " << pivot << std::endl;
    }

    xchg(&arr[iter + 1], &arr[right]);

    printArray(arr, left, right);
    std::cout << "========" << iter + 1 << "==========" << std::endl;

    return iter + 1;
}

int myArray::lomuto_quicksort(int start, int end)
{
    if (start < end) {
        std::cout << "partitioning: [ " << start << "," << end << " ]"<< std::endl;
        int pi = lomuto_partitionning (start, end);
        std::cout << "left: [[[ " << start << "," << pi - 1 << " ]]]" << std::endl;
        lomuto_quicksort(start,     pi - 1);
        std::cout << "right: [[[ " << pi + 1 << "," << end << " ]]]" << std::endl;
        lomuto_quicksort(pi + 1, end);
    }

    return 0;
}

int myArray::hoare_quicksort(int start, int end)
 {
     if (start < end) {
         std::cout << "partitioning: [ " << start << "," << end << " ]"<< std::endl;
         int pi = hoare_partitionning (start, end);
         std::cout << "left: [[[ " << start << "," << pi << " ]]]" << std::endl;
         hoare_quicksort(start,     pi);
         std::cout << "right: [[[ " << pi + 1 << "," << end << " ]]]" << std::endl;
         hoare_quicksort(pi + 1, end);
     }

     return 0;
 }

int myArray::count_array(int *out, int k)
{
    for ( int j = 0; j < k;    j++ ) out[j] = 0;
    for ( int i = 0; i < size; i++ ) out[arr[i]]++;

    printf(" Count array: ");
    printArray(out,  0, k - 1);

    // Wave-count array
    for ( int j = 1; j < k; j++ ) out[j] += out[j-1];

    printf(" Wave-count array: ");
    printArray(out,  0, k - 1);

    return 0;

}

int myArray::findMax(int *in, int sz)
{
    int max = in[0];
    for (int i = 1; i < sz; i++) if (in[i] > max) max = in[i];

    return max;
}

int myArray::counting_sort(int start, int end)
{
    int k = findMax(arr, size) + 1;
    std::cout << "k = " << k << std::endl;
    int n = end - start + 1;
    int *output = new int[n];
    int *count  = new int[n+k];

    count_array(count, k);

    for ( int i = n-1; i >= 0; i-- )
    {
        int out_value = arr[i];
        int out_index = --count[out_value];
        output[out_index] = out_value;
    }

    std::memcpy(arr + start, output, n * sizeof(int));

    delete[](output);
    delete[](count);

    return 0;
}

int myArray::sort(myArray::sort_t type)
{
    int result = 0;
    switch (type)
    {
        case QUICK_SORT_HOARE:
            result = hoare_quicksort(0, size - 1);
            break;

        case QUICK_SORT_LOMUTO:
            result = lomuto_quicksort(0, size - 1);
            break;

        case COUNTING_SORT:
            result = counting_sort(0, size - 1);
            break;
    }
        
    return result;
}

float myArray::median()
{
    std::cout << "size % 2 = " << size % 2 << std::endl;
    if (size % 2 != 0) return float(arr[(size-1)/2]);
 
    // std::cout << arr[(size-1)/2] << ", " << size % 2 << std::endl;
    return float(arr[(size-1)/2] + arr[(size-1)/2 + 1]) / 2;
}

