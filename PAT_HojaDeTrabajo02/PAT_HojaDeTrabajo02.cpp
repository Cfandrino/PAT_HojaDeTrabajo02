#include <iostream>
#include "Ejercicio01.h"
#include "Ejercicio02.h"
#include "Ejercicio03.h"
#include "Ejercicio04.h"
#include "Node.h"

int main() {

    Ejercicio01 e01;


    Node<char>* head = new Node<char>('a');
    head->next = new Node<char>('b');
    head->next->next = new Node<char>('c');
    head->next->next->next = new Node<char>('d');
    head->next->next->next->next = new Node<char>('e');
    int k = 2;

    Node<char>* rotatedList = e01.rotateRight(head, k);

    std::cout << "Resultado de la rotación de lista:" << std::endl;
    while (rotatedList) {
        std::cout << rotatedList->value << " -> ";
        rotatedList = rotatedList->next;
    }
    std::cout << "nullptr" << std::endl;


    Ejercicio02 e02;


    Node<int>* l1 = new Node<int>(2);
    l1->next = new Node<int>(4);
    l1->next->next = new Node<int>(3);

    Node<int>* l2 = new Node<int>(5);
    l2->next = new Node<int>(6);
    l2->next->next = new Node<int>(4);

    Node<int>* sumList = e02.addTwoNumbers(l1, l2);

    std::cout << "Resultado de la suma de números en listas enlazadas:" << std::endl;
    while (sumList) {
        std::cout << sumList->value;
        if (sumList->next) {
            std::cout << " -> ";
        }
        sumList = sumList->next;
    }
    std::cout << std::endl;

    Ejercicio03 e03;

    std::string expression = "3+2*2";
    int result = e03.calculate(expression);
    std::cout << "Resultado de la evaluación de expresión: " << result << std::endl;

    return 0;
    Ejercicio04 e04;

    FrontMiddleBackQueue queue;


    queue.pushFront(1);
    queue.pushMiddle(2);
    queue.pushBack(3);


    std::cout << "Contenido de la cola: ";
    std::cout << queue.popFront() << " ";
    std::cout << queue.popMiddle() << " ";
    std::cout << queue.popBack() << " ";
    std::cout << std::endl;

    return 0;
}