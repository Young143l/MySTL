#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>

template <typename T>
class vector {
   private:
    T* data;
    size_t _size;
    size_t _capacity;
    const size_t mincap = 10;

   public:
    vector();
    vector(size_t size);
    vector(size_t size, T value);
    vector(const vector<T>& other);

    ~vector();

    T* begin() const;
    T* end() const;

    void push_back(T value);
    void pop_back();
    void clear();
    size_t size() const;
    T& operator[](size_t index) const;
    vector<T>& operator=(const vector<T>& other);
};

template <typename T>
vector<T>::vector() {
    this->_size = 0;
    this->_capacity = this->mincap;
    data = new T[this->_capacity]{};
}

template <typename T>
vector<T>::vector(size_t size) {
    this->_size = size;
    this->_capacity = (size / this->mincap + 1) * this->mincap;
    data = new T[_capacity]{};
}

template <typename T>
vector<T>::vector(size_t size, T value) {
    this->_size = size;
    this->_capacity = (size / this->mincap + 1) * this->mincap;
    this->data = new T[_capacity]{};
    for (size_t i = 0; i < _size; i++) {
        data[i] = value;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    this->_size = other._size;
    if (other._capacity > this->mincap) {
        this->_capacity = other._capacity;
    } else {
        this->_capacity = mincap;
    }
    if (this->data) {
        delete[] this->data;
    }
    this->data = new T[this->_capacity]{};
    for (size_t i = 0; i < this->_size; i++) {
        this->data[i] = other.data[i];
    }
}

template <typename T>
vector<T>::~vector() {
    delete[] this->data;
}

template <typename T>
T* vector<T>::begin() const{
    return this->data;
}

template <typename T>
T* vector<T>::end() const{
    return this->data+this->_size;
}

template <typename T>
size_t vector<T>::size() const {
    return this->_size;
}
template <typename T>
void vector<T>::push_back(T value) {
    if (this->_size >= this->_capacity -1) {
        T* newdata = new T[this->_capacity + this->mincap];
        for (size_t i = 0; i < this->_size; i++) {
            newdata[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newdata;
    }
    this->data[this->_size++] = value;
}

template <typename T>
void vector<T>::pop_back() {
    if (this->_size <= 0) {
        return;
    }
    this->_size--;
}

template <typename T>
void vector<T>::clear() {
    this->_size = 0;
    this->_capacity = this->mincap;
    delete[] this->data;
    this->data = new T[_capacity]{};
}

template <typename T>
T& vector<T>::operator[](size_t index) const {
    // if(!(index>=0&&index<this->_size)){

    // }
    return this->data[index];
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        this->_size = other._size;
        if (other._capacity > this->mincap) {
            this->_capacity = other._capacity;
        } else {
            this->_capacity = mincap;
        }
        if (this->data) {
            delete[] this->data;
        }
        this->data = new T[this->_capacity]{};
        for (size_t i = 0; i < this->_size; i++) {
            this->data[i] = other.data[i];
        }
    }
    return *this;
}

#endif
