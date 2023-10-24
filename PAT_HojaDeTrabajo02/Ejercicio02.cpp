
#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    Node<int> dummy(0);  
    Node<int>* p = l1;
    Node<int>* q = l2;
    Node<int>* current = &dummy;
    int carry = 0;

    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->value : 0;
        int y = (q != nullptr) ? q->value : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        current->next = new Node<int>(sum % 10); 
        current = current->next;

        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    if (carry > 0) {
        current->next = new Node<int>(carry); 
    }

    return dummy.next;
}
