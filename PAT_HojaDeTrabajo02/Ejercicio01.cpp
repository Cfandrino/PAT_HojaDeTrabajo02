#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    int length = 1;
    Node<char>* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k %= length;

    if (k == 0) {
        return head;
    }

    if (k >= length) {
        k = k % length;
    }

    int newHeadPos = length - k;
    Node<char>* newHead = head;
    for (int i = 1; i < newHeadPos; i++) {
        newHead = newHead->next;
    }

    tail->next = head;

    head = newHead->next;

    newHead->next = nullptr;

    return head;
}
