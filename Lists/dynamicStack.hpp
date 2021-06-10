#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

// Using Linked List as a way to implement dynamicStack
#include "linkedList.hpp"

// Defining DynamicStack

template <typename T>
class DynamicStack {
private:
    LinkedList<T> listStack;
    // Probably not the best way to do class heritage :p

public:
    DynamicStack () {
        LinkedList<T> noArgument;
        listStack = noArgument;
    }

    DynamicStack (T firstValue) {
        LinkedList<T> oneArgument (firstValue);
        listStack = oneArgument;
    }

    void push (T insertedElement) {
        listStack.addToStart (insertedElement);
    }

    void pop () {
        listStack.removeFromStart ();
    }

    T top () {
        if (listStack.getLength() == 0) {
            printf("Error: can't return top value when stack is empty.\n");
            exit(EXIT_FAILURE);
        }

        return (listStack[0]);
    }
};


#endif
