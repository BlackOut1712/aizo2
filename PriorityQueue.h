#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <iostream>

template <typename T>
class PriorityQueue {
    public:
        PriorityQueue();
        ~PriorityQueue();

        void add(T element);
        T extractMIN();
        int getIndex(T element);
        bool isEmpty() const { return size == 0; }
        void print() const;
        void update(int index, T element);

    private:
        T* data; // Pointer to the array of elements
        int size; // Current size of the queue
        int capacity; // Maximum capacity of the queue

        void buildHeap();
        void heapify(int index);
        void heapify_up(int index);
        void remove();
        void resize();
       

};

#include "PriorityQueue.tpp"

#endif