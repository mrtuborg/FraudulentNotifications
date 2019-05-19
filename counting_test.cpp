#include <iostream>
#include "MyArray.hpp"
#include "MyQueue.hpp"

int main(int args, char* argv[])
{
    int input[] = { 1, 4, 1, 2, 7, 5, 2 };
    int n = ARRAY_SIZE(input);

/*
    myArray *a = new myArray(input, n);
    a->printArray();
    a->sort(myArray::sort_t::COUNTING_SORT);
    a->printArray();
    delete(a);
*/
    myQueue *b = new myQueue();
    b->addItem(input, n);
    std::cout << "Initial queue" << std::endl;
    b->printQueue();
    b->xchg(b)
    // b->sort(myQueue::sort_t::COUNTING_SORT);
    std::cout << "Sorted queue" << std::endl;
    b->printQueue();
    delete(b);
    return 0;
}
