#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "List.h"

template<typename ListType>
class List;

template <typename NodeType>
class Node;

template <class Type>
class iterator {
    friend class List<Type>;
    private:
        List<Type>* parent;
        List<Type>* current;
        typename List<Type>::Node* pos;
        iterator(List<Type>* prnt, Node<Type>* pos): parent(prnt), current(pos) {}
};

#endif