#include <iostream>
#include "MyArray.hpp"


int main(int args, char* argv[])
{
    int input[] = { 1, 4, 1, 2, 7, 5, 2 };
    int n = ARRAY_SIZE(input);

    myArray *a = new myArray(input, n);
    a->printArray();
    a->sort(myArray::sort_t::COUNTING_SORT);
    a->printArray();
    delete(a);
    return 0;
}
