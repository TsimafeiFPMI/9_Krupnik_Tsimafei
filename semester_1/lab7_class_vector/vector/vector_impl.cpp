#include "vector_impl.h"

Vector::Vector() : data(nullptr), size_(0), capacity_(0) {
}

Vector::Vector(size_t n) : size_(n), capacity_(n) {
    if (n > 0) {
        data = new int[n]();
    } else {
        data = nullptr;
    }
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

Vector::Vector(std::initializer_list<int> list) : size_(list.size()), capacity_(list.size()) {
    if (capacity_ > 0) {
        data = new int[capacity_];
        size_t i = 0;
        for (int val : list) {
            data[i++] = val;
        }
    } else {
        data = nullptr;
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other)
        return *this;
    delete[] data;
    size_ = other.size_;
    capacity_ = other.capacity_;
    if (capacity_ > 0) {
        data = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
    return *this;
}

Vector::~Vector() {
    delete[] data;
}

void Vector::PushBack(int value) {
    if (size_ >= capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }
    data[size_] = value;
    ++size_;
}

void Vector::PopBack() {
    if (size_ > 0)
        --size_;
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity <= capacity_)
        return;
    int* new_data = new int[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity_ = new_capacity;
}

void Vector::Swap(Vector& other) {
    std::swap(data, other.data);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

int& Vector::operator[](size_t index) {
    return data[index];
}

const int& Vector::operator[](size_t index) const {
    return data[index];
}

int& Vector::At(size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

bool Vector::IsEmpty() const {
    return size_ == 0;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.Size(); ++i) {
        if (i > 0)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}