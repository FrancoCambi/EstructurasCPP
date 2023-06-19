#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include<iostream>
#include<vector>

template<class tipo>
// Stack representation
class Queue {

    private:
        std::vector<tipo> arr;

    public:
        
        // Destructor
        ~Queue();

        // Push data into the stack
        void enqueue(tipo data);

        // Pop data from the stack and return it
        tipo dequeue();

        // Returns top data
        tipo peek();

        // Returns stack size
        size_t size();

        // Returns 1 if stack is empty, 0 otherwise.
        bool isEmpty();

};

template<class tipo>
Queue<tipo>::~Queue() {
    arr.clear();
}

template<class tipo>
void Queue<tipo>::enqueue(tipo data) {
    
    arr.push_back(data);
}

template<class tipo>
tipo Queue<tipo>::dequeue() {

    tipo data = arr.front();
    arr.erase(arr.begin());

    return data;
}

template<class tipo>
tipo Queue<tipo>::peek() {

    return arr.front();
}

template<class tipo>
size_t Queue<tipo>::size() {
    return arr.size();
}

template<class tipo>
bool Queue<tipo>::isEmpty() {
    return arr.empty();
}

#endif /* __STACK_HPP__ */
