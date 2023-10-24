#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    // Contar la longitud de la lista
    int length = 1;
    Node<char>* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Ajustar k para asegurarse de que est� dentro de la longitud de la lista
    k %= length;

    // Si k es igual a 0, no se necesita rotaci�n
    if (k == 0) {
        return head;
    }

    // Encontrar el nuevo nodo de la cabeza despu�s de la rotaci�n
    int newHeadPos = length - k;
    Node<char>* newHead = head;
    for (int i = 1; i < newHeadPos; i++) {
        newHead = newHead->next;
    }

    // Conectar el �ltimo nodo con el nodo original de la cabeza
    tail->next = head;

    // Actualizar la cabeza
    head = newHead->next;

    // Desconectar el nodo que ahora est� en la posici�n k
    newHead->next = nullptr;

    return head;
}
