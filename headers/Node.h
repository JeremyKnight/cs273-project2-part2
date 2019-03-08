#ifndef _NODE_H_
#define _NODE_H_
//We need this in order to have NULL defined.
#include <cstdlib>
template <typename Type>

struct Node {
    Type data;
    Node<Type>* next;
    Node<Type>* prev;

    Node(const Type& item, Node* next = NULL, Node* prev = NULL) : data(item), next(next), data(item), prev(prev){}
    //Node<Type>& operator =(const Node<Type>& other);
};

#endif