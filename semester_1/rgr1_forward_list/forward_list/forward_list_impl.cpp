#include "forward_list_impl.h"
#include <stdexcept>

ForwardList::ForwardList() : head_(nullptr), size_(0) {
}

ForwardList::~ForwardList() {
    Clear();
}

ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(0) {
    if (rhs.head_ == nullptr)
        return;
    head_ = new Node(rhs.head_->value_);
    Node* current = head_;
    Node* rhs_current = rhs.head_->next_;
    size_ = 1;
    while (rhs_current != nullptr) {
        current->next_ = new Node(rhs_current->value_);
        current = current->next_;
        rhs_current = rhs_current->next_;
        ++size_;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs)
        return *this;
    Clear();
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
        size_ = 0;
        return *this;
    }
    head_ = new Node(rhs.head_->value_);
    Node* current = head_;
    Node* rhs_current = rhs.head_->next_;
    size_ = 1;
    while (rhs_current != nullptr) {
        current->next_ = new Node(rhs_current->value_);
        current = current->next_;
        rhs_current = rhs_current->next_;
        ++size_;
    }
    return *this;
}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushBack(value);  // <-- PushBack сохраняет порядок
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(0) {
    for (int32_t val : init) {
        PushBack(val);  // <-- правильный порядок!
    }
}


void ForwardList::PushFront(int32_t value) {
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    head_ = new_node;
    ++size_;
}

void ForwardList::PushBack(int32_t value) {
    if (head_ == nullptr) {
        PushFront(value);
        return;
    }
    Node* current = head_;
    while (current->next_ != nullptr) {
        current = current->next_;
    }
    current->next_ = new Node(value);
    ++size_;
}

void ForwardList::PopFront() {
    if (head_ == nullptr)
        return;
    Node* temp = head_;
    head_ = head_->next_;
    delete temp;
    --size_;
}

void ForwardList::Clear() {
    while (head_ != nullptr) {
        PopFront();
    }
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}

void ForwardList::Remove(int32_t value) {
    // Remove from head
    while (head_ != nullptr && head_->value_ == value) {
        PopFront();
    }
    if (head_ == nullptr)
        return;
    Node* current = head_;
    while (current->next_ != nullptr) {
        if (current->next_->value_ == value) {
            Node* to_delete = current->next_;
            current->next_ = to_delete->next_;
            delete to_delete;
            --size_;
        } else {
            current = current->next_;
        }
    }
}

void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current->value_;
        if (current->next_ != nullptr) {
            out << " ";
        }
        current = current->next_;
    }
}

int32_t ForwardList::Front() const {
    if (head_ == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return head_->value_;
}

size_t ForwardList::Size() const {
    return size_;
}