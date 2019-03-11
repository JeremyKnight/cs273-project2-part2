#ifndef _NODE_H_
#define _NODE_H_
//We need this in order to have NULL defined.
#include <cstdlib>
template <typename Type>

struct Node {
    Type data;
    Node<Type>* next;
    Node<Type>* prev;

    //constructs node
    //input: item: data. next and prev pointers
    Node(const Type& item, Node* next = NULL, Node* prev = NULL) : data(item), next(next), prev(prev){}
};

#endif