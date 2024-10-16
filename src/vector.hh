#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    unsigned int size;
    unsigned int capacity;
    T* storage;

    void resize() {
        unsigned int newCapacity = 1 + (capacity * 1.5);
        T* newStorage = new T[newCapacity];

        for (unsigned int i = 0; i < size; i++) {
            newStorage[i] = storage[i];
        }

        delete[] storage;
        storage = newStorage;
        capacity = newCapacity;
    }

    void Twista(int a, int b) {
        T auxiliar = storage[a];
        storage[a] = storage[b];
        storage[b] = auxiliar;
    }

    int FindPivote(int inicio, int final) {
        T pivot = storage[final];
        int i = inicio - 1;
        for (int j = inicio; j < final; j++) {
            if (storage[j] < pivot) {
                i++;
                Twista(i, j);
            }
        }
        Twista(i + 1, final);
        return i + 1;
    }

    void StartToSort(int inicio, int fin) {
        if (inicio < fin) {
            int pivote = FindPivote(inicio, fin);
            StartToSort(inicio, pivote - 1);
            StartToSort(pivote + 1, fin);
        }
    }

public:
    Vector() : size(0), capacity(1), storage(new T[capacity]) {}

    ~Vector() {
        delete[] storage;
    }

    Vector(const Vector<T>& vec) {
        size = vec.size;
        capacity = vec.capacity;
        storage = new T[capacity];

        for (unsigned int i = 0; i < size; i++) {
            storage[i] = vec.storage[i];
        }
    }

    unsigned int getSize() const { return size; }
    unsigned int getCapacity() const { return capacity; }

    void push_back(T elem) {
        if (size == capacity) {
            resize();
        }
        storage[size++] = elem;
    }

    void push_front(T elem) {
        if (size == capacity) {
            resize();
        }
        for (unsigned int i = size; i > 0; i--) {
            storage[i] = storage[i - 1];
        }
        storage[0] = elem;
        size++;
    }

    T at(unsigned int index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return storage[index];
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    void pop_front() {
        if (size > 0) {
            for (unsigned int i = 0; i < size - 1; i++) {
                storage[i] = storage[i + 1];
            }
            size--;
        }
    }

    void remove(unsigned int target) {
        if (target >= size) return; 

        for (unsigned int i = target; i < size - 1; i++) {
            storage[i] = storage[i + 1];
        }
        size--;
    }
    
    void insert(const T& elem, unsigned int pos) {
        if (pos > size) return; // Asegura que no se inserte fuera de límites
        push_back(elem);
        for (unsigned int i = size - 1; i > pos; i--) {
            storage[i] = storage[i - 1];
        }
        storage[pos] = elem;
    }

    void QuickSort() {
        StartToSort(0, size - 1);
    }

    void Print() const {
        cout << "{ ";
        for (unsigned int i = 0; i < size; i++) {
            cout << storage[i];
            if (i < size - 1) cout << ", ";
        }
        cout << " }";
    }
};
