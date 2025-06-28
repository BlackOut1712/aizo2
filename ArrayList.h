#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <typename T>
class ArrayList{
    public:
        ArrayList();
        ArrayList(const ArrayList<T>& other); 
        ~ArrayList();

        void add(const T& element);
        bool contains(const T& element) const;
        T& get(int index) const;
        int getSize() const;
        int isEmpty() const { return size == 0; }
        void unite(ArrayList<T>& other);
        void set(int index, const T& element);
        ArrayList<T>& operator=(const ArrayList<T>& other);
        bool operator==(const ArrayList<T>& other);

        void remove(int index);

    private:
        T* data; // Pointer to the array of elements
        int size; // Current size of the list
        int capacity; // Current capacity of the list

        void resize(); // Resize the array when needed
};

#include "ArrayList.tpp"

#endif