#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include <ostream>

class Vector {
private:
    int* data;
    size_t size_;
    size_t capacity_;

public:
    // Конструкторы
    Vector();
    Vector(size_t n);
    Vector(const Vector& other);
    Vector(std::initializer_list<int> list);

    // Оператор присваивания
    Vector& operator=(const Vector& other);

    // Деструктор
    ~Vector();

    // Методы — ТОЛЬКО PascalCase!
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(size_t new_capacity);
    void Swap(Vector& other);

    // Доступ к элементам
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& At(size_t index);
    const int& At(size_t index) const;

    // Информация
    size_t Size() const;
    size_t Capacity() const;
    bool IsEmpty() const;

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

#endif  // VECTOR_IMPL_H