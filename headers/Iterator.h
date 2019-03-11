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
        iterator(List<Type>* prnt, Node<Type>* pos): parent(prnt), current(pos) {}
    public:
        //returns the underlying data
        //taken from book
        Type& operator*() const {
            if(current == NULL) {
                throw std::invalid_argument("attempt to dereference end()");
            }
            return current->data;
        }
        
        //moves to the next element in list
        //input: int for postfix (synatx magic)
        //output: pointer of next in list
        //taken from book
        iterator& operator++(int) {
            if(current == NULL) {
                throw std::invalid_argument("attempt to advance past end()");
            }
            current = current->next;
            return *this;
        }

        //checks that this iterator is equal to i
        //intput: iterator to compare
        //output: true if equal, false if not
        bool operator==(iterator i) {
            return current == i.current && parent == i.parent; 
        }
        
        //checks that this iterator is not equal to i
        //intput: iterator to compare
        //output: false if equal, true if not
        bool operator!=(iterator i) {
            return (*this == i) == false; 
        }


};

#endif