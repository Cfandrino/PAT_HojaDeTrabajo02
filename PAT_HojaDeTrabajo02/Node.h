// Node.h

#pragma once

template<typename T>
struct Node {
    T value;
    Node* next;

    // Constructor que toma un valor de tipo T
    Node(T val) : value(val), next(nullptr) {}
};
