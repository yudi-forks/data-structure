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
    // Calling LinkedList default constructor: null stack.
    DynamicStack () {
        LinkedList<T> noArgument;
        listStack = noArgument;
    }

    // Calling LinkedList constructor w/argument: stack with one value.
    DynamicStack (T firstValue) {
        LinkedList<T> oneArgument (firstValue);
        listStack = oneArgument;
    }

    // Calling LinkedList destructor: turning the stack null.
    ~DynamicStack () {
        listStack.~LinkedList();
    }

    // Calling push function, adding element to start of the list (stack).
    void push (T insertedElement) {
        listStack.addToStart (insertedElement);
    }

    // Calling pop function, removing element from start of the list (stack).
    void pop () {
        listStack.removeFromStart ();
    }

    // Calling top function, returning element from start of the list (stack).
    T top () {
        if (listStack.getLength() == 0) {
            printf("Error: can't return top value when stack is empty.\n");
            exit(EXIT_FAILURE);
        }

        return (listStack[0]);
    }
};


#endif
