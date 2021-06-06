#ifndef STATICSTACK_H
#define STATICSTACK_H

#include <stdlib.h>
#include <iostream>
// #include <stack>
// Will use it in the future to promote compatibility with CPP stack.
// I don't expect my code to be more optimized than the <stack> library.
// But anyways :P

// Defining statickStack

template <typename T>
class staticStack {
private:
    int length = -1;
    int pos = 0;
    T *address = NULL;

public:
    // Default constructor -> Creates null stack.
    staticStack<T> () {
        this->length = -1;
        this->pos = 0;
        this->address = NULL;
    }

    // Length-based constructor.
    staticStack<T> (int length) {
        this->length = length;
        this->pos = 0;
        this->address = (T*)calloc (length, sizeof(T));
    }

    // Destructor: turns the stack null.
    ~staticStack<T> () {
        this->length = -1;
        this->pos = 0;
        this->address = NULL;
    }

    // These are self-explanatory.
    bool isEmpty () {
        return (!pos);
    }

    bool isFull () {
        return (pos == length);
    }

    // Insert element at the top of the stack.
    void push (T insertedElement) {
        // Only able to insert if:
        // 1. Stack exists and.
        // 2. Stack is not full.
        if (this->address && !(this->isFull())) {
            this->address[pos] = insertedElement;
            this->pos++;
        }

        // If requirements are not fulfilled, nothing is done.
    }

    // Removes the top element from the stack (does not return).
    void pop () {
        // Only able to remove if:
        // 1. Stack exists.
        // 2. Stack is not empty.
        if (this->address && !(this->isEmpty()))
            this->pos--;
        
        // If requirements are not fulfilled, nothing is done.
    }

    // Returns the top element in the stack.
    T top () {
        // If the stack is null or empty (pos = 0)
        // This function will cause an interruption.
        // But it is still safer than returning a trash value.
        if (this->address == NULL) {
            printf("Error: can't return top value when stack is null.\n");
            exit(EXIT_FAILURE);
        }   
        if (this->isEmpty()) {
            printf("Error: can't return top value when stack is empty.\n");
            exit(EXIT_FAILURE);
        }

        // I'm almost certain that is not the best way to handle errors...
        // But i need something that causes the function to stop
            
        return (this->address[pos-1]);
    }
};

#endif
