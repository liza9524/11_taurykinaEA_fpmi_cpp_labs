#pragma once
#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <stdexcept>
#include <algorithm>
    class Vector {
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* arr_ = nullptr;

public:
    Vector();
    explicit Vector(size_t size);
    Vector(std::initializer_list<int> init);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& At(size_t index);
    const int& At(size_t index) const;
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(size_t new_capacity);
    void Swap(Vector& other) noexcept;
};
std::ostream& operator<<(std::ostream& out, const Vector& vec);