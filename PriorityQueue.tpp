#include <iostream>
#include "PriorityQueue.h"

template <typename T>
void PriorityQueue<T>::add(T element) {
    /* This function adds an element to the priority queue.
     * It first checks if the queue is full, and if so, it resizes the array.
     * Then it adds the new element at the end of the array and calls heapify_up
     * to maintain the heap property.
     * Parameters:
     * element: The element to add to the queue
    */
    if (this->size == this->capacity) {
        resize();
    }

    this->data[size] = element;
    heapify_up(size); 
    size++;
}

template <typename T>
void PriorityQueue<T>::buildHeap() {
    /* This function builds the heap from the current data in the queue.
     * It starts from the last non-leaf node and calls heapify on each node
     * to ensure that the heap property is maintained.
     * 
     * Probably not necessary tho.
    */
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(i);
    }
}

template <typename T>
T PriorityQueue<T>::extractMIN() {
    /* This function extracts the minimum element from the priority queue.
     * It first checks if the queue is empty, and if so, it returns a default value of T.
     * Then it stores the minimum element (the root of the heap), removes it,
     * and rebuilds the heap to maintain the heap property.
     * Returns:
     * The minimum element from the queue
    */
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return T(); // Return default value of T
    }

    T minElement = this->data[0];
    remove();
    return minElement; // Return the minimum element
}

template <typename T>
int PriorityQueue<T>::getIndex(T element){
    /*  This function finds and returns the index of given element.
    *   If given element is not within the data, it returns -1. 
    */
    for(int i=0; i<size; i++){
        if(data[i]==element){
            return i;
        }
    }
    return -1;
}

template <typename T>
void PriorityQueue<T>::heapify(int index) {
    /* This function ensures that the heap property is maintained by moving the element at index down the heap
     * until it is in the correct position. It's used when removing the root element from the heap.
     * Parameters:
     * index: The index of the element to move down
    */
    int left = 2 * index + 1;  // Left child index
    int right = 2 * index + 2; // Right child index
    int smallest = index;      // Index of the smallest (future root) element

    if (left < size && data[left] < data[smallest]) {
        smallest = left;
    }
    if (right < size && data[right] < data[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        T temp = data[index];
        data[index] = data[smallest];
        data[smallest] = temp;

        heapify(smallest);
    }
}

template <typename T>
void PriorityQueue<T>::heapify_up(int index) {
    /* This function ensures that the heap property is maintained by moving the element at index up the heap
     * until it is in the correct position. It's used when adding a new element to the heap.
     * Parameters:
     * index: The index of the element to move up
    */
    while (index > 0) {
        int parent = (index - 1) / 2; // Parent index
        if (data[index] < data[parent]) {
            T temp = data[index];
            data[index] = data[parent];
            data[parent] = temp;
            index = parent; // Move up to the parent's index
        } else {
            break; // The heap property is satisfied
        }
    }
}

template <typename Edge>
void PriorityQueue<Edge>::print() const{
    /* This function prints the edges in the priority queue in a level-order traversal.
     * It is useful for debugging and visualizing the structure of the heap.
    */
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Edge from " << data[i].getSource() << " to " 
                  << data[i].getDestination() << " with weight " 
                  << data[i].getWeight() << std::endl;
    }
    std::cout << "end" << std::endl;
}

template <typename T>
PriorityQueue<T>::PriorityQueue() : size(0), capacity(10) {
    this->data = new T[capacity];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] this->data;
}

template <typename T>
void PriorityQueue<T>::remove() {
    /* This function removes the root element (minimum element) from the priority queue.
     * It replaces the root with the last element in the heap, decreases the size,
     * and calls heapify to maintain the heap property.
     */
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    this->data[0] = this->data[size - 1];
    size--;
    heapify(0); 
}

template <typename T>
void PriorityQueue<T>::resize() {
    /* This function resizes the internal array to double its current capacity. */
    T* newData = new T[capacity * 2];
    for (int i = 0; i < size; ++i) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
    this->capacity *= 2;
}

template <typename T>
void PriorityQueue<T>::update(int index, T element){
    /* This function updates the element with given index
    and ensure that the heap property are maintained
    */
    data[index] = element;
    heapify(0);
}