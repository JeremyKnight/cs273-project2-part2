#include "List.h"

List::List() {
    head = NULL;
    tail = NULL;
}

// List<Type>::List(const List<Type>& list) {

// }

void push_back(Type element) {
    if (head == NULL) {
        head = new Node(element);
        tail = head;
    } else {
        // Node * localTail = tail;
        Node * newTail = new Node(element, NULL, tail);
        tail->next = newTail;
        tail = newTail;
    }
}