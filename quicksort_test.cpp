#include <iostream>
#include "MyArray.hpp"

int main(int args, char *argv[])
{
    int arr[] = {3,4,3,7,2,8,6,0,9,1,2};
    
    myArray *a = new myArray(arr, ARRAY_SIZE(arr));
    a->printArray();
    a->sort(myArray::sort_t::QUICK_SORT_HOARE);
    a->printArray();
    std::cout << "Median: " << a->median() << std::endl;
    delete(a);

	return 0;
}

