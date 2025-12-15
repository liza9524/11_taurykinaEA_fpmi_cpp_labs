#include "vector_impl.h"

Vector::Vector() : size_(0), capacity_(0), arr_(nullptr) {
}
Vector::Vector(size_t size) : size_(size), arr_(new int[size_]), capacity_(size_) 
{
    for (size_t i = 0; i < size_; i++) {
        arr_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list)
    : size_(list.size()), capacity_(list.size()), arr_(new int[capacity_]) {
    size_t i = 0;
    for (int item : list) {
        arr_[i] = item;
        ++i;
    }
}

Vector::Vector(const Vector& other)
    : size_(other.size_),
      capacity_(other.capacity_),
      arr_(other.capacity_ > 0 ? new int[capacity_] : nullptr) {
    for (size_t i = 0; i < size_; ++i) {
        arr_[i] = other.arr_[i];
    }
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

Vector::~Vector() {
    Clear();
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
int& Vector::At(size_t n) {
    if (n >= size_)
        throw std::out_of_range("Wrong index");
    return arr_[n];
}

const int& Vector::At(size_t n) const {
    if (n >= size_)
        throw std::out_of_range("Wrong index");
    return arr_[n];
}

size_t Vector::Size() const{
    return size_;
}

size_t Vector::Capacity() const{
    return capacity_;
}

void Vector::PopBack() {
    if (size_ > 0) {
        size_--;
    }
}

void Vector::Clear() 
{
        delete[] arr_;
        arr_ = nullptr;
        size_ = 0;
        capacity_ = 0;
}


void Vector::PushBack(int n) 
{
    if (size_ == capacity_) 
    {
        size_t new_capacity = (capacity_ == 0) ? 1 : 2 * capacity_;
        Reserve(new_capacity);
    }
    arr_[size_] = n; 
    ++size_;       

}
void Vector::Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        int* new_arr_ = new int[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        capacity_ = new_capacity;
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