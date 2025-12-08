#pragma once
#include <ostream>
class Vector {
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* arr_ = nullptr;

public:
    Vector();
    Vector(size_t size);
    Vector(std::initializer_list<char> list);
    Vector(size_t size, int a);
    Vector& operator=(const Vector& other);
    ~Vector();
    void Swap(Vector& v1);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& at(int n);
    const int& at(int n) const;
    size_t Size();
    size_t Capacity();
    void PopBack();
    void Clean();
    void PushBack(int n);
    void Reserve(size_t RCapacity);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
};
