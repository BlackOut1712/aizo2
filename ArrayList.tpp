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
    if (size == capacity) {
        resize();
    }
    data[size++] = element;
}

template <typename T>
bool ArrayList<T>::contains(const T& element) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
T& ArrayList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
int ArrayList<T>::getSize() const {
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
void ArrayList<T>::remove(int index) {
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
    capacity *= 2; // Double the capacity
    T* newData = new T[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

