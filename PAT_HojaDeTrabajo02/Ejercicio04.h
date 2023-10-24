
#pragma once

#include <list>

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int value) {
        data_.emplace_front(value);
        if (front_ptr_ == middle_ptr_) {
            middle_ptr_ = std::next(middle_ptr_);
        }
        if (front_ptr_ == end_ptr_) {
            end_ptr_ = std::next(end_ptr_);
        }
    }

    void pushMiddle(int value) {
        data_.insert(middle_ptr_, value);
        if (front_ptr_ == middle_ptr_) {
            front_ptr_ = std::prev(front_ptr_);
        }
        if (middle_ptr_ == end_ptr_) {
            end_ptr_ = std::next(end_ptr_);
        }
    }

    void pushBack(int value) {
        data_.emplace_back(value);
        if (middle_ptr_ == end_ptr_) {
            middle_ptr_ = std::prev(middle_ptr_);
        }
        if (front_ptr_ == end_ptr_) {
            front_ptr_ = std::prev(front_ptr_);
        }
    }

    int popFront() {
        if (data_.empty()) {
            return -1;
        }
        int value = data_.front();
        data_.pop_front();
        if (front_ptr_ == middle_ptr_) {
            middle_ptr_ = std::next(middle_ptr_);
        }
        if (front_ptr_ == end_ptr_) {
            end_ptr_ = std::next(end_ptr_);
        }
        return value;
    }

    int popMiddle() {
        if (data_.empty()) {
            return -1;
        }
        auto it = middle_ptr_;
        if (front_ptr_ == middle_ptr_) {
            middle_ptr_ = std::next(middle_ptr_);
        }
        if (middle_ptr_ == end_ptr_) {
            end_ptr_ = std::next(end_ptr_);
        }
        int value = *it;
        data_.erase(it);
        return value;
    }

    int popBack() {
        if (data_.empty()) {
            return -1;
        }
        int value = data_.back();
        data_.pop_back();
        if (middle_ptr_ == end_ptr_) {
            middle_ptr_ = std::prev(middle_ptr_);
        }
        if (front_ptr_ == end_ptr_) {
            front_ptr_ = std::prev(front_ptr_);
        }
        return value;
    }

private:
    std::list<int> data_;
    std::list<int>::iterator front_ptr_ = data_.begin();
    std::list<int>::iterator middle_ptr_ = data_.begin();
    std::list<int>::iterator end_ptr_ = data_.begin();
};
