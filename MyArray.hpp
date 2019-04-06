#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <cstddef>

#define ARRAY_SIZE(X) \
         (sizeof(X)/sizeof(X[0])) 

class myArray
{
    public:
        typedef enum {
            QUICK_SORT_HOARE,
            QUICK_SORT_LOMUTO,
            COUNTING_SORT
        } sort_t;

    private:
         int *arr;
         int size;
 
         void xchg(int *x, int *y);
          int findMax(int *in, int sz);
         void printArray(void *in, int start = -1, int end = -1);

         // Quick sort: O(n^2) .. O(n*log(n))
         int hoare_partitionning(int left, int right);
         int lomuto_partitionning(int left, int right);
         int hoare_quicksort(int start, int end);
         int lomuto_quicksort(int start, int end);
         
         // Counting sort: O(n+k)
         int count_array(int *out, int k);
         int counting_sort(int start, int end);
 
     public:
 
         myArray(int *array, int size): arr(array), size(size) {    }
         int sort(sort_t type);
         float median();
         void printArray();
};

#endif // MYARRAY_HPP
