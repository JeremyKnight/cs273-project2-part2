#include "List.h"

template <typename Type>
List<Type>::List() {
    head = NULL;
    tail = NULL;
}

List<Type>::List(const List<Type>& list) {

    List<Type> temp = List();

    while(list->head!=NULL) {

        temp.push_back(list->head.data);
        list.pop_front();
    }
    this->head = temp->head;
    this->tail = temp->tail;
}

template <typename Type>
void List<Type>::push_back(Type element) {
    if (head == NULL) {
        head = new Node<Type>(element);
        tail = head;
    } else {
        // Node * localTail = tail;
        Node<Type> * newTail = new Node<Type>(element, NULL, tail);
        tail->next = newTail;
        tail = newTail;
    }
}

template <typename Type>
void List<Type>::pop_back() {
    Node<Type> * temp = tail->prev;
    delete tail;
    tail = temp;
}

template <typename Type>
void List<Type>::push_front(Type element) { 
    if (tail == NULL) {
        head = new Node<Type>(element);
        tail = head;
    } else {
        // Node * localTail = tail;
        Node<Type> * newHead = new Node<Type>(element, head, NULL);
        head->prev = newHead;
        head = newHead;
    }
}

template <typename Type>
void List<Type>::pop_front() {
    Node<Type> * temp = head->next;
    delete head;
    head = temp;
}

template <typename Type>
void List<Type>::swap(List<Type>& other) {
    this->head = other->head;
    this->tail = other->tail;
}

//iterate() //iterate 

//iterate(Type element) //iterate to element

//iterate(int i, string place) //"end" 
