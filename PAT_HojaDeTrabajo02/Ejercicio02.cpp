#include "Node.h" 
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->value : 0;
        int val2 = l2 ? l2->value : 0;
        int sum = val1 + val2 + carry;

        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);

        if (!result) {
            result = newNode;
            current = result;
        }
        else {
            current->next = newNode;
            current = newNode;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return result;
}
