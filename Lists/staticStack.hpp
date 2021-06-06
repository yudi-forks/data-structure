#ifndef STATICSTACK_H
#define STATICSTACK_H

#include <stdlib.h>
// #include <stack>
// Will use it in the future to promote compatibility with CPP stack
// I don't expect my code to be more optimized than the <stack> library
// But anyways :P

// Defining statickStack

template <typename T>
struct statickStack {
    int length = -1;
    int pos = 0;
    T *address = NULL;

    // Default constructor -> Creates null stack
    statickStack<T> () {
        this->length = -1;
        this->pos = 0;
        this->address = NULL;
    }

    // Length-based constructor
    statickStack<T> (int length) {
        this->pos = 0;
        this->length = length;
    }

    // These are self-explanatory
    bool isEmpty () {
        return (!pos);
    }

    bool isFull () {
        return (pos == length-1);
    }
};

#endif
