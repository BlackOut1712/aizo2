#include <iostream>
#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList() : size(0), capacity(10) {
    data = new T[capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template <typename T>
void ArrayList<T>::add(const T& element) {
    //This function add given element to the list
    if (size == capacity) {
        resize();
    }
    data[size++] = element;
}

template <typename T>
bool ArrayList<T>::contains(const T& element) const {
    //This function check if list contains given element. If so, returns true.
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
T& ArrayList<T>::get(int index) const {
    //This function returns the element on given index
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
int ArrayList<T>::getSize() const {
    //This function returns the size of the list
    return size;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this != &other) {
        delete[] data; // Free existing memory
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity]; // Allocate new memory
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Copy elements
        }
    }
    return *this;
}

template <typename T>
bool ArrayList<T>::operator==(const ArrayList<T>& other){
    if(size != other.size){
        return false;
    }

    for(int i=0; i<size; i++){
        if(!other.contains(data[i])){
            return false;
        }
    }

    return true;
}


template <typename T>
void ArrayList<T>::remove(int index) {
    //This function removes element on given index from the list, and fixes the list after.
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
void ArrayList<T>::resize() {
    //This function resize the allocated memory for data
    capacity *= 2; // Double the capacity
    T* newData = new T[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <typename T>
void ArrayList<T>::set(int index, const T& element) {
    //This function set the elemnent on the given index to the given value
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    data[index] = element;
}

template <typename T>
void ArrayList<T>::unite(ArrayList<T>& other){
    //This function adds given list to the this list without duplicates
    for (int i = 0; i < other.size; ++i) {
        if (!contains(other.data[i])) {
            add(other.data[i]);
        }
    }
}
