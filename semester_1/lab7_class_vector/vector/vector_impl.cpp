#include "vector_impl.h"

Vector::Vector() {}

Vector::Vector(size_t size) : size_(size), arr_(new int[size_]), capacity_(size_) 
{
    for (int i = 0; i < size_; i++) {
        arr_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<char> list)
    : size_(list.size()), arr_(new int[size_]), capacity_(size_) {
    size_t i = 0;
    for (size_t item : list) {
        arr_[i] = item;
        ++i;
    }
}

Vector::Vector(size_t size, int a) : size_(size), arr_(new int[size_]), capacity_(size_) {
    for (int i = 0; i < size_; i++) {
        arr_[i] = a;
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other)
        return *this;
    delete[] arr_;
    size_ = other.size_;
    arr_ = new int[size_];
    for (size_t i = 0; i < size_; ++i) {
        arr_[i] = other.arr_[i];
    }
    return *this;
}

Vector::~Vector() {
    delete[] arr_;
}
void Vector::Swap(Vector& v1) {
    std::swap(size_, v1.size_);
    std::swap(arr_, v1.arr_);
    std::swap(capacity_, v1.capacity_);
}

int& Vector::operator[](size_t index) {
    return arr_[index];
}

const int& Vector::operator[](size_t index) const {
    return arr_[index];
}

int& Vector::at(int n) {
    if (n >= size_)
        throw std::out_of_range("wrong index");
    return arr_[n];
}

const int& Vector::at(int n) const {
    if (n >= size_)
        throw std::out_of_range("wrong index");
    return arr_[n];
}

size_t Vector::Size() {
    return size_;
}

size_t Vector::Capacity() {
    return capacity_;
}

void Vector::PopBack() {
    if (size_ > 0) {
        size_--;
    }
}

void Vector::Clean() {
    size_ = 0;
}

void Vector::PushBack(int n) {
    if (size_ == Capacity()) {
        size_t new_size_ = 2 * size_;
        int* new_arr_ = new int[new_size_];
        for (int i = 0; i < size_; ++i) {
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        capacity_ *= 2;
    }

    ++size_;
    arr_[size_ - 1] = n;
}
void Vector::Reserve(size_t RCapacity) {
    if (RCapacity > Capacity()) {
        int* new_arr_ = new int[RCapacity];
        for (int i = 0; i < size_; ++i) {
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        capacity_ = RCapacity;
    }
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << std::endl << "[";
    for (size_t i = 0; i < v.size_; ++i) {
        out << v[i];
        if (i + 1 < v.size_)
            out << ", ";
    }
    out << "]" << std::endl;
    return out;
}