#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    int carry = 0;
    Node<int>* result = new Node<int>();
    Node<int>* current = result;

    while (l1 || l2) {
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int _sum = x + y + carry;
        carry = _sum / 10;

        current->data = _sum % 10;

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }

        if (l1 || l2) {

            current->next = new Node<int>();
            current = current->next;
        }
    }

    if (carry) {

        current->next = new Node<int>(carry);
    }

    return result;
}