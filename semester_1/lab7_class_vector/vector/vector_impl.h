#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <iostream>
#include <cstddef>
#include <initializer_list>

class Vector {
private:
    int* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    // Конструкторы
    Vector();
    explicit Vector(size_t size);
    Vector(std::initializer_list<int> init_list);
    Vector(const Vector& ot#pragma once

#include <iostream>
#include <stdexcept>

class Vector {
    private:
        size_t size_ = 0;
        size_t capacity_ = 0;
        int* data_ = nullptr;

    public:
        Vector();

        Vector(size_t);

        Vector(const Vector&);

        Vector(std::initializer_list<int>);

        ~Vector();

        Vector& operator=(const Vector&);

        void Swap(Vector&);

        int& operator[](size_t);

        const int& operator[](size_t) const;

        int& At(size_t);

        const int& At(size_t) const;

        size_t Size() const;

        size_t Capacity() const;

        void PushBack(int);

        void PopBack();

        void Clear();

        void Reserve(size_t);

        friend std::ostream& operator<<(std::ostream&, const Vector&);
};

    // Метод Swap
    void Swap(Vector& other) noexcept;

    // Операторы индексирования
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    // Метод At с проверкой границ
    int& At(size_t index);
#pragma once

#include <iostream>
#include <stdexcept>

        class Vector {
    private:
        size_t size_ = 0;
        size_t capacity_ = 0;
        int* data_ = nullptr;

    public:
        Vector();

        Vector(size_t);

        Vector(const Vector&);

        Vector(std::initializer_list<int>);

        ~Vector();

        Vector& operator=(const Vector&);

        void Swap(Vector&);

        int& operator[](size_t);

        const int& operator[](size_t) const;

        int& At(size_t);

        const int& At(size_t) const;

        size_t Size() const;

        size_t Capacity() const;

        void PushBack(int);

        void PopBack();

        void Clear();

        void Reserve(size_t);

        friend std::ostream& operator<<(std::ostream&, const Vector&);
    };
    size_t Capacity() const noexcept;

    // Модификаторы
    void PushBack(int value);
    void PopBack();
    void Clear() noexcept;
    void Reserve(size_t new_capacity);

    // Оператор вывода (друг класса)
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};

// Оператор вывода (объявление)
std::ostream& operator<<(std::ostream& os, const Vector& vec);

#endif