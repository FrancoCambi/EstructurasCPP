#ifndef __STACK_HPP__
#define __STACK_HPP__

#include<iostream>
#include<vector>

template<class tipo>
// Stack representation
class Stack {

    private:
        std::vector<tipo> arr;
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
    arr.clear();
}

template<class tipo>
void Stack<tipo>::push(tipo data) {
    
    top++;
    arr.push_back(data);
}

template<class tipo>
tipo Stack<tipo>::pop() {

    tipo data = arr.back();
    arr.pop_back();
    top--;

    return data;
}

template<class tipo>
tipo Stack<tipo>::peek() {

    return arr.back();
}

template<class tipo>
size_t Stack<tipo>::size() {
    return arr.size();
}

template<class tipo>
bool Stack<tipo>::isEmpty() {
    return arr.empty();
}

#endif /* __STACK_HPP__ */
