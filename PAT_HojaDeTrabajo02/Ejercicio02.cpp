
#pragma once
#include "Node.h"

class Ejercicio02 {
public:
    Node<int>* addTwoNumbers(Node<int>* l1, Node<int>* l2);
};


#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    int carry = 0;
    Node<int>* result = nullptr;
    Node<int>* current = nullptr;

    while (l1 || l2 || carry) {
        int x = l1 ? l1->value : 0;
        int y = l2 ? l2->value : 0;
        int _sum = x + y + carry;
        carry = _sum / 10;

        if (!result) {
            result = new Node<int>(_sum);
            current = result;
        }
        else {
            current->next = new Node<int>(_sum);
            current = current->next;
        }

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    return result;
}
