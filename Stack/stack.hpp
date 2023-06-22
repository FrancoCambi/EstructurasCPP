#ifndef __STACK_HPP__
#define __STACK_HPP__

#include<iostream>
#include<vector>

template<class tipo>
// Stack representation
class Stack {

    private:
        std::vector<tipo> vect;
        int top;

    public:
        
        // Constructor
        Stack();

        // Destructor
        ~Stack();

        // Push data into the stack
        void push(tipo data);

        // Pop data from the stack and return it
        tipo pop();

        // Returns top data
        tipo peek();

        // Returns stack size
        size_t size();

        // Returns 1 if stack is empty, 0 otherwise.
        bool isEmpty();

};

template<class tipo>
Stack<tipo>::Stack() {
    top = -1;
}

template<class tipo>
Stack<tipo>::~Stack() {
    vect.clear();
}

template<class tipo>
void Stack<tipo>::push(tipo data) {
    
    top++;
    vect.push_back(data);
}

template<class tipo>
tipo Stack<tipo>::pop() {

    tipo data = vect.back();
    vect.pop_back();
    top--;

    return data;
}

template<class tipo>
tipo Stack<tipo>::peek() {

    return vect.back();
}

template<class tipo>
size_t Stack<tipo>::size() {
    return vect.size();
}

template<class tipo>
bool Stack<tipo>::isEmpty() {
    return vect.empty();
}

#endif /* __STACK_HPP__ */
