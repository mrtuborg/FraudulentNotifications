#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

#include <cstddef>
#include <vector>

class myQueue
{
    public:
        typedef enum {
            QUICK_SORT_HOARE,
            QUICK_SORT_LOMUTO,
            COUNTING_SORT
        } sort_t;

        typedef struct queue_node_s {
            int value;

            size_t index;
            queue_node_s* next;
            queue_node_s* prev;
        } queue_node_t;

    private:
         queue_node_t *head;
         queue_node_t *tail;

         
         size_t size;
 
        myQueue::queue_node_t *getNodeByIndex(int index);

         
          int findMax(queue_node_t *in);
         void printQueue(void *in, int start = -1, int end = -1);
         void printDequeue(void *in, int start = -1, int end = -1);

         // Quick sort: O(n^2) .. O(n*log(n))
         int hoare_partitionning(int left, int right);
         int lomuto_partitionning(int left, int right);
         int hoare_quicksort(int start, int end);
         int lomuto_quicksort(int start, int end);
         
         // Counting sort: O(n+k)
         int count_array(int *out, int k);
         int counting_sort(int start, int end);
 
     public:
        std::vector<queue_node_t *> arr;
         myQueue();
         ~myQueue();

         void xchg(queue_node_t *x, queue_node_t *y);
         int addItem(int val);
         int addItem(int* array, size_t size);

         queue_node_t* getPrevious(queue_node_t *node);
         int deleteItem(queue_node_t *node, queue_node_t *prev_node = NULL);
         int rc_deleteList(queue_node_t *node);
         int it_deleteList(queue_node_t *node);

         int sort(sort_t type);
         float median();
         void printQueue();
         void printDequeue();
};

#endif // MYARRAY_HPP
