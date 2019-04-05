#include <iostream>
#include "quicksort.h"

inline void myArray::xchg(int *x, int *y)
{
    if (x == y) return;

    std::cout << "exchange: " << *x << "," << *y << std::endl;
    *x = *y + *x;
    *y = *x - *y;
    *x = *x - *y;

}

inline void myArray::printArray (int start, int end)
{
    if ((start == -1 ) || (end == -1))
    {
        start = 0;
        end = size -1;
    }

    for (int i = start; i <= end; i++)
          std::cout << arr[i] << " ";

    std::cout << std::endl;
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
        printArray(left, right); 
    } while (true);
    
    return j;
}

int myArray::lomuto_partitionning(int left, int right)
{
	int pivot = arr[right];
    int iter  = left - 1;   // index of smallest element
    
    std::cout << "iter: " << iter << std::endl;
    std::cout << "pivot: " << pivot << std::endl;
    printArray(left, right);

	for (int i = left; i < right; i++)
	{
        if (arr[i] <= pivot) {
            std::cout << arr[i] << " <= " << pivot << std::endl;
            iter++;
            xchg(&arr[i], &arr[iter]);
            printArray(left, right);
            std::cout << "iter: " << iter << std::endl;
        } else std::cout << arr[i] << " > " << pivot << std::endl;
    }

    xchg(&arr[iter + 1], &arr[right]);

    printArray(left, right);
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


int myArray::sort()
{
    return hoare_quicksort(0, size - 1);
}

float myArray::median()
{
    std::cout << "size % 2 = " << size % 2 << std::endl;
    if (size % 2 != 0) return float(arr[(size-1)/2]);
 
    // std::cout << arr[(size-1)/2] << ", " << size % 2 << std::endl;
    return float(arr[(size-1)/2] + arr[(size-1)/2 + 1]) / 2;
}

