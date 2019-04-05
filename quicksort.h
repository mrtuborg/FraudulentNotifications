#ifndef QUICKSORT_H
#define QUICKSORT_H

#define ARRAY_SIZE(X) \
         (sizeof(X)/sizeof(X[0])) 

class myArray
{
         int *arr;
         int size;
 
         void xchg(int *x, int *y);
         int hoare_partitionning(int left, int right);
         int lomuto_partitionning(int left, int right);
         int hoare_quicksort(int start, int end);
         int lomuto_quicksort(int start, int end);
 
     public:
 
         myArray(int *array, int size): arr(array), size(size) {    }
         int sort();
         float median();
         void printArray(int start = -1, int end = -1);
};

#endif // QUICKSORT_H
