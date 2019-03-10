#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
#include "Iterator.h"
#include <assert.h>
#include <iostream>
#include <stdexcept>

using std::string;
using std::cout;

template <class Type>
class List {
    private:
        Node<Type>* head;
        Node<Type>* tail;
        int len=0;

    public:
        /**
         * constuctor for list
         * creates an empty list with head and tail pointers as null
         **/

        
        List() {
            head = NULL;
            tail = NULL;
        }

        /**
         * constructor for list
         * constructs new deep copy of list
         **/
        
        List(const List<Type>& list) {

           
            head = NULL;
            tail = NULL;
            Node<Type>* temp = list.head;
            while(temp!=NULL) {
                push_back(temp->data);
                temp = temp->next;
           }

        }
      
        ~List() {
            while(this->size()!=0) {
                this->pop_front();
            }
        }
   
        void push_back(Type element) {
            if (head == NULL) {
                head = new Node<Type>(element);
                tail = head;
                
            } else {
                // Node * localTail = tail;
                Node<Type> * newTail = new Node<Type>(element, NULL, tail);
                tail->next = newTail;
                tail = newTail;
            }
            len++;
        }

        
        void pop_back() {
            if(tail == NULL) 
                throw std::invalid_argument("tail is NULL");
            Node<Type> * temp = tail->prev;
            temp->next = NULL;
            delete tail;
            tail = temp;
            len--;
        }

        
        void push_front(Type element) { 
            if (tail == NULL) {
                head = new Node<Type>(element);
                tail = head;
            } else {
                // Node * localTail = tail;
                Node<Type> * newHead = new Node<Type>(element, head, NULL);
                head->prev = newHead;
                head = newHead;
            }
            len++;
        }

        
        void pop_front() {
            if(head == NULL) 
                throw std::invalid_argument("head is NULL");
            Node<Type> * temp = head->next;
            delete head;
            head = temp;
            len--;
        }

        
        void swap(List<Type>& other) {
            
            this->head = other->head;
            this->tail = other->tail;
            this->len = other->len;
        }

        
        int size() {
            return len;
        }

        
        List<Type>& operator= (const List<Type>& other) {
            List<Type> temp(other);
            swap(temp);
            return *this;
        }

        
        iterator<Type> begin() {
            iterator<Type> i(this, this->head);
            return i;
        }

        
        iterator<Type> end() {
            iterator<Type> i(this, this->tail->next);
            return i;
        }

        
        iterator<Type> insert(iterator<Type> position, const Type& value) {

            if( position.current == this->head) { //beginning 
                this->push_front(value);
                //retrun new iterator at head
                iterator<Type> newIt = iterator<Type>(this, this->head);
                return newIt;
                
            } else if( position.current == this->tail ) { // end
                this->push_back(value);
                iterator<Type> newIt = iterator<Type>(this, this->tail);
                return newIt;
            } else { 
                Node<Type>* newNode = new Node<Type>(value,position.current->prev, position.current);
                
                position.current->prev = newNode;
                position.current->prev->next = newNode;

                iterator<Type> newIt = iterator<Type>(this, newNode);
                return newIt;
                len++;
            }
            
        }

        //returns iterator after the one erased
        
        iterator<Type> erase(iterator<Type> position) {
            if(position.current == this->head) {
                cout << "from postion current is head" << std::endl;
                this->pop_front();
            } else if(position.current == this->tail) {
                cout << "from postion current is tail" << std::endl;

                this->pop_back();
            } else {
                /*
                Node<Type>* newNode = new Node<Type>(value,position.current->prev, position.current);
                
                position.current->prev = newNode;
                position.current->prev->next = newNode;
                */
                //cout << "position: " << position.current->data << " tail: " << this->tail->data;
                position.current->prev->next = position.current->next;
                position.current->next->prev = position.current->prev;
                //cout << "from btween tail, and head" << std::endl;
                delete position.current;

                len--;
                iterator<Type> newIt = iterator<Type>(this, position.current->next);
                return newIt;
                
            }
        }
};

#endif

