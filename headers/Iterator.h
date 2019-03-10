#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "List.h"
#include <stdexcept>

template<typename ListType>
class List;

template <typename NodeType>
class Node;

template <class Type>
class iterator {
    friend class List<Type>;
    private:
        List<Type>* parent;
        Node<Type>* current;
        //typename List<Type>::Node* pos;
        iterator(List<Type>* prnt, Node<Type>* pos): parent(prnt), current(pos) {}
    public:
        //taken from book
        Type& operator*() const {
            if(current == NULL) {
                throw std::invalid_argument("attempt to dereference end()");
            }
            return current->data;
        }

        //taken from book
        iterator& operator++(int) {
            if(current == NULL) {
                throw std::invalid_argument("attempt to advance past end()");
            }
            current = current->next;
            return *this;
        }

        bool operator==(iterator i) {
            return current == i.current && parent == i.parent; 
        }

        bool operator!=(iterator i) {
            return (*this == i) == false; 
        }


};

#endif