#include <iostream>
#include "Ejercicio01.h"
#include "Ejercicio02.h"
#include "Ejercicio03.h"
#include "Node.h"

int main() {
    // Ejercicio 01: Rotaci�n de lista
    Ejercicio01 e01;

    // Crear una lista para probar la rotaci�n (debes construir la lista seg�n tus necesidades)
    Node<char>* head = new Node<char>('a');
    head->next = new Node<char>('b');
    head->next->next = new Node<char>('c');
    head->next->next->next = new Node<char>('d');
    head->next->next->next->next = new Node<char>('e');
    int k = 2;

    Node<char>* rotatedList = e01.rotateRight(head, k);

    std::cout << "Resultado de la rotaci�n de lista:" << std::endl;
    while (rotatedList) {
        std::cout << rotatedList->value << " -> ";
        rotatedList = rotatedList->next;
    }
    std::cout << "nullptr" << std::endl;

    // Ejercicio 02: Suma de n�meros en listas enlazadas
    Ejercicio02 e02;

    // Crear dos listas para probar la suma (debes construir las listas seg�n tus necesidades)
    Node<int>* l1 = new Node<int>(2);
    l1->next = new Node<int>(4);
    l1->next->next = new Node<int>(3);

    Node<int>* l2 = new Node<int>(5);
    l2->next = new Node<int>(6);
    l2->next->next = new Node<int>(4);

    Node<int>* sumList = e02.addTwoNumbers(l1, l2);

    std::cout << "Resultado de la suma de n�meros en listas enlazadas:" << std::endl;
    while (sumList) {
        std::cout << sumList->value;
        if (sumList->next) {
            std::cout << " -> ";
        }
        sumList = sumList->next;
    }
    std::cout << std::endl;

    // Ejercicio 03: Evaluaci�n de expresiones aritm�ticas
    Ejercicio03 e03;

    std::string expression = "3+2*2";
    int result = e03.calculate(expression);
    std::cout << "Resultado de la evaluaci�n de expresi�n: " << result << std::endl;

    return 0;
}
