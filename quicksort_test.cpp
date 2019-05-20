#include <iostream>
#include "MyArray.hpp"
#include "MyQueue.hpp"

int main(int args, char *argv[])
{
    int arr[] = {3,4,3,7,2,8,6,0,9,1,2};
    
    // myArray *a = new myArray(arr, ARRAY_SIZE(arr));
    // a->printArray();
    // a->sort(myArray::sort_t::QUICK_SORT_HOARE);
    // a->printArray();
    // std::cout << "Median: " << a->median() << std::endl;
    // delete(a);
    
    myQueue *b = new myQueue();
    b->addItem(arr, ARRAY_SIZE(arr));
    b->printQueue();
    b->xchg(b->arr[2], b->arr[6]);
    // b->sort(myQueue::sort_t::QUICK_SORT_HOARE);
    b->printQueue();
    b->xchg(b->arr[8], b->arr[9]);
    b->printQueue();
    delete(b);

	return 0;
}

