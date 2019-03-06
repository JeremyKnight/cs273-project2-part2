#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
#include "Iterator.h"

template <class Type>
class List {
    private:
    Node<Type>* head;
    Node<Type>* tail;
    public:
        List();
        List(Type data);
        List(const List<Type>& list);
        ~List();

        List<Type>&  operator =(const List<Type>& other);

        int size();

        void push_back(Type element);
        void pop_back();
        void push_front(Type element);
        void pop_front();

        //void swap(list<Type>& other);

        iterator<Type> begin();
        iterator<Type> end();
        iterator<Type> insert(iterator<Type> position, const Type& value);
        iterator<Type> erase(iterator<Type> position);
};

#endif