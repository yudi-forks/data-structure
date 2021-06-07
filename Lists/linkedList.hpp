#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

// Defining LinkedList NODE

template <typename T>
class Node {
private:
    T value;
    Node<T> *next;

public:
    // Constructor with no entry
    // this->value will have trash
    // This implementation is valid because we need NULL on LinkedList
    Node<T> () {
        this->next = NULL;
    }

    // Constructor with T as entry
    Node<T> (T inserted) {
        this->value = inserted;
        this->next = NULL;
    }

    Node<T> *getNext () {
        return (this->next);
    }

    void setNext (Node<T> *desiredNext) {
        this->next = desiredNext;
    }

    T getValue () {
        return (this->value);
    }
};

template <typename T>
class LinkedList {
private:
    int length;
    Node<T> *first;

    Node<T> *accessIndex (int index) {
        Node<T> *iterator = this->first;

        if (index <= length-1) {
            for (int i = 0; i < index; i++)
                iterator = iterator->getNext();
        }
        else
            iterator = NULL;
        
        return (iterator);
    }
public:
    // Default constructor -> Creates null list.
    LinkedList<T> () {
        this->length = 0;
        this->first = NULL;
    }

    // Constructor based on a first value
    LinkedList<T> (T firstValue) {
        this->length = 1;
        this->first = new Node<T> (firstValue);
    }

    // Destructor -> deallocate all nodes and free pointer
    ~LinkedList<T> () {
        if (this->length > 0) {
            Node<T> *iterator = this->first;
            Node<T> *aux;

            while (iterator) {
                aux = iterator;
                iterator = iterator->getNext();
                free(aux);
            }

            this->length = 0;
            this->first = NULL;
        }
    }

    T operator[] (int index) {
        Node<T> *target = this->accessIndex(index);

        return (target->getValue());
    }

    // Add element to the start of the list
    void addToStart (T insertedValue) {
        Node<T> *insertedNode = new Node<T> (insertedValue);
        insertedNode->setNext(this->first);
        
        this->first = insertedNode;
        this->length++;
    }

    // Add element to the end of the list
    void addToEnd (T insertedValue) {
        Node<T> *insertedNode = new Node<T> (insertedValue);
        Node<T> *target = this->accessIndex(this->length-1);

        if (this->length == 0)
            this->first = insertedNode;
        else
            target->setNext(insertedNode);
        
        this->length++;
    }

    // Remove element from the start of the list
    void removeFromStart () {
        Node<T> *aux = this->first;

        if (this->length) {
            this->first = this->first->getNext();
            free(aux);

            this->length--;
        }
    }

    // Remove element from the end of the list
    void removeFromEnd () {
        Node<T> *target = this->accessIndex(this->length-2);

        if (this->length) {
            if (this->length > 1) {
                // Deallocating last node
                free(target->getNext());
                // Setting penultimate node next pointer to NULL
                target->setNext(NULL);
            }
            else {
                // Deallocating the only node in the list
                free(this->first);
                // Redefining first node to NULL
                this->first = NULL;
            }
            
            this->length--;
        }
    }
};

#endif
