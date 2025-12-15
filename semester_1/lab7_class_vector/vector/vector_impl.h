#pragma once
#include <ostream>
class Vector {
private:
    size_t size_;
    size_t capacity_;
    int* arr_;

public:
    Vector();
    Vector(size_t size);
    Vector(std::initializer_list<int> list);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
    void Swap(Vector& v1);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& At(size_t n);
    const int& At(size_t n) const;
    size_t Size() const;
    size_t Capacity() const;
    void PopBack();
    void Clear();
    void PushBack(int n);
    void Reserve(size_t RCapacity);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
};
