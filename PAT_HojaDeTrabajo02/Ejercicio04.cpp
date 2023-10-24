#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue() {

}

void FrontMiddleBackQueue::pushFront(int value) {
    data.push_front(value);
}

void FrontMiddleBackQueue::pushMiddle(int value) {
    int middle = data.size() / 2;
    auto it = data.begin();
    std::advance(it, middle);

    data.insert(it, value);
}

void FrontMiddleBackQueue::pushBack(int value) {
    data.push_back(value);
}

int FrontMiddleBackQueue::popFront() {
    if (data.empty()) {
        return -1;
    }
    int value = data.front();
    data.pop_front();
    return value;
}

int FrontMiddleBackQueue::popMiddle() {
    if (data.empty()) {
        return -1;
    }
    int middle = data.size() / 2;
    auto it = data.begin();
    std::advance(it, middle);
    int value = *it;
    data.erase(it);
    return value;
}

int FrontMiddleBackQueue::popBack() {
    if (data.empty()) {
        return -1;
    }
    int value = data.back();
    data.pop_back();
    return value;

}