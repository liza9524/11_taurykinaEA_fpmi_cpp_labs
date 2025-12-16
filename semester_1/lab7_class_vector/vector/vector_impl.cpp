#include "vector_impl.h"
#include <algorithm>

Vector::Vector() {
}
Vector::Vector(size_t size)
    : size_(size), capacity_(size), arr_(size > 0 ? new int[size] : nullptr) {
    for (size_t i = 0; i < size_; ++i) {
        arr_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> init)
    : size_(init.size()),
      capacity_(init.size()),
      arr_(init.size() > 0 ? new int[init.size()] : nullptr) {
    std::copy(init.begin(), init.end(), arr_);
}
Vector::Vector(const Vector& other)
    : size_(other.size_),
      capacity_(other.capacity_),
      arr_(other.size_ > 0 ? new int[other.capacity_] : nullptr) {
    std::copy(other.arr_, other.arr_ + other.size_, arr_);
}
Vector::~Vector() {
    delete[] arr_;
}
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }
    return *this;
}
int& Vector::operator[](size_t index) {
    return arr_[index];
}

const int& Vector::operator[](size_t index) const {
    return arr_[index];
}
int& Vector::At(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return arr_[index];
}
const int& Vector::At(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return arr_[index];
}
void Vector::PushBack(int value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        Reserve(new_capacity);
    }
    arr_[size_++] = value;
}
void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}
void Vector::Clear() {
    size_ = 0;
}
void Vector::Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        int* new_arr = new int[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_arr[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr;
        capacity_ = new_capacity;
    }
}

void Vector::Swap(Vector& other) noexcept {
    std::swap(arr_, other.arr_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}


std::ostream& operator<<(std::ostream& out, const Vector& vec) {
    out << "[";
    for (size_t i = 0; i < vec.Size(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << vec[i];
    }
    out << "]";
    return out;
}