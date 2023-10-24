
#pragma once

#include "Node.h"

class Ejercicio02 {
public:
    Node<int>* addTwoNumbers(Node<int>* l1, Node<int>* l2) {
        int carry = 0; 
        Node<int>* result = nullptr;
        Node<int>** it = &result;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->value;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->value;
                l2 = l2->next;
            }

            carry = sum / 10;
            *it = new Node<int>{ sum % 10 };
            it = &((*it)->next);
        }

        return result;
    }
};
