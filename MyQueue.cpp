#include <iostream>
#include "MyQueue.hpp"

myQueue::myQueue()
{
    head = new queue_node_t();
    tail = new queue_node_t();

    head->next = tail;
    head->prev = NULL;

    tail->prev = head;
    tail->next = NULL;

    size = 0;
}

myQueue::~myQueue()
{
    std::cout << "destructor" << std::endl;
    it_deleteList(head);
}


int myQueue::addItem(int val)
{
    queue_node_t *node = new queue_node_t();
    node->value = val;

    queue_node_t *old_tail_prev = tail->prev;
    tail->prev = node;
    node->prev = old_tail_prev;

    old_tail_prev->next = node;
    node->next = tail;
    
    node->index = size;
    arr.push_back(node);
    size++;

    return 0;
}

int myQueue::addItem(int* array, size_t size)
{
    for (int i = 0; i < size; i++) addItem(array[i]);
    return 0;
}

myQueue::queue_node_t* myQueue::getPrevious(queue_node_t *node)
{
    queue_node_t *prev_node = head;
    do {
         prev_node = prev_node->next;
    } while ((prev_node->next != node) && (prev_node->next != NULL));

    return prev_node;
}

int myQueue::deleteItem(queue_node_t *node, queue_node_t *prev_node)
{
    if (node == NULL) return -1;
    if (prev_node == NULL) prev_node = getPrevious(node);

    arr.erase(arr.begin() + node->index);
    prev_node->next = node->next;
    return 0;
}

int myQueue::rc_deleteList(queue_node_t *node)
{
    if (node->next != NULL) rc_deleteList(node->next);

    arr.erase(arr.begin() + node->index);
    delete(node);

    return 0;
}

int myQueue::it_deleteList(queue_node_t *node)
{
    queue_node_t *remaining;
    do {
        remaining = node->next;
        arr.erase(arr.begin());
        std::cout << "arr.erase: " << "[" << node->index << "] = " << node->value << std::endl;
        delete(node);

        node = remaining;
    } while ( node != NULL && arr.size() > 0);

    return 0;
}

inline void myQueue::xchg(queue_node_t *x, queue_node_t *y)
{
    if (x == y) return;

    std::cout << "exchange: " << "[" << x->index << "] = " << x->value
                            << ", [" << y->index << "] = " << y->value
                            << std::endl;

    /* With values only:
     * x->value = y->value + x->value;
     * y->value = x->value - y->value;
     * x->value = x->value - y->value;
     */

    /* With pointers: */
    // arr[x->index] = y;
    // arr[y->index] = x;

    queue_node_t *z;
    queue_node_t *yprev = y->prev;
    queue_node_t *ynext = y->next;
    queue_node_t *xprev = x->prev;
    queue_node_t *xnext = x->next;

    std::cout << "head: " << head << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    std::cout << "x[" << x->prev->next->index << "]: " << x->prev->next->value << std::endl;
    std::cout << "y[" << y->prev->next->index << "]: " << y->prev->next->value << std::endl;

    std::cout << "x->next: " << x->next << ", x->prev: " << x->prev << std::endl;
    std::cout << "y->next: " << y->next << ", y->prev: " << y->prev << std::endl;

    /* yprev->next = x; +
    x->prev = yprev;
    x->next = ynext; +
    ynext->prev = x;

    xprev->next = y; +
    y->prev = xprev; +
    y->next = xnext;
    xnext->prev= y; */
    
    z = x;
    x = y;
    y = z;

    y->prev = yprev;
    y->next = ynext;
    x->prev = xprev;
    x->next = xnext;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    std::cout << "x[" << x->prev->next->index << "]: " << x->prev->next->value << std::endl;
    std::cout << "y[" << y->prev->next->index << "]: " << y->prev->next->value << std::endl;

    std::cout << "x->next: " << x->next << ", x->prev: " << x->prev << std::endl;
    std::cout << "y->next: " << y->next << ", y->prev: " << y->prev << std::endl;

}

void myQueue::printDequeue (void *in, int start, int end)
{
    if ((start == -1 ) || (end == -1))
    {
        start = 0;
        end = size -1;
    }

    for (int i = start; i <= end; i++)
        std::cout << arr[i]->value << " ";

    std::cout << std::endl;
}

void myQueue::printDequeue()
{
     printDequeue(head);
}

void myQueue::printQueue (void *in, int start, int end)
{
    if ((start == -1 ) || (end == -1))
    {
        start = 0;
        end = size -1;
    }

    myQueue::queue_node_t *node = (myQueue::queue_node_t *)in;

    for (int i = start; i <= end && node->next; i++, node = node->next)
    {
        std::cout << "[" << node->index << "]: " << node->value << " " << std::endl;
        if (node == node->next) std::cout << "Infinite loop detected!!!" << std::endl;
    }

    std::cout << std::endl;
}

void myQueue::printQueue()
{
     printQueue(head->next);
}


int myQueue::hoare_partitionning(int left, int right)
{
    int i = left  - 1;
    int j = right + 1;
    int pivot = arr[(i + j) / 2]->value;

    std::cout << "pivot = [" << (i + j) / 2 << "]: " << pivot << std::endl;
    std::cout << "i,j = " << i << "," << j << std::endl;

    do {
        do {
            i++;
            // std::cout << arr[i]->value << std::endl;
        } while (i < j && arr[i]->value < pivot);
        // std::cout << "i = " << i << std::endl;
        
        do {
            j--;
            // std::cout << arr[j]->value << std::endl;
        } while (j > i && arr[j]->value > pivot);
        // std::cout << "j = " << j << std::endl;

        if (  i >= j ) break;
        
        xchg(arr[i], arr[j]);
        printQueue(head->next, left, right); 
    } while (true);
    
    printQueue(head->next, left, right);

    return j;
}

int myQueue::lomuto_partitionning(int left, int right)
{
	int pivot = arr[right]->value;
    int iter  = left - 1;   // index of smallest element
    
    std::cout << "iter: " << iter << std::endl;
    std::cout << "pivot: " << pivot << std::endl;
    printQueue(head, left, right);

	for (int i = left; i < right; i++)
	{
        if (arr[i]->value <= pivot) {
            std::cout << arr[i]->value << " <= " << pivot << std::endl;
            iter++;
            xchg(arr[i], arr[iter]);
            printQueue(head, left, right);
            std::cout << "iter: " << iter << std::endl;
        } else std::cout << arr[i]->value << " > " << pivot << std::endl;
    }

    xchg(arr[iter + 1], arr[right]);

    printQueue(head, left, right);
    std::cout << "========" << iter + 1 << "==========" << std::endl;

    return iter + 1;
}

int myQueue::lomuto_quicksort(int start, int end)
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

int myQueue::hoare_quicksort(int start, int end)
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

/* int myArray::count_array(int *out, int k)
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

} */

/* int myArray::findMax(int *in, int sz)
{
    int max = in[0];
    for (int i = 1; i < sz; i++) if (in[i] > max) max = in[i];

    return max;
} */

/* int myArray::counting_sort(int start, int end)
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
} */

int myQueue::sort(myQueue::sort_t type)
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
            // result = counting_sort(0, size - 1);
            break;
    }
        
    return result;
}

/* float myArray::median()
{
    std::cout << "size % 2 = " << size % 2 << std::endl;
    if (size % 2 != 0) return float(arr[(size-1)/2]);
 
    // std::cout << arr[(size-1)/2] << ", " << size % 2 << std::endl;
    return float(arr[(size-1)/2] + arr[(size-1)/2 + 1]) / 2;
} */

