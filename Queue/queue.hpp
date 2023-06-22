#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include<iostream>
#include<vector>

template<class tipo>
// Queue representation
class Queue {

    private:
        std::vector<tipo> vect;

    public:
        
        // Destructor
        ~Queue();

        // Push data into the queue
        void enqueue(tipo data);

        // Pop data from the queue and return it
        tipo dequeue();

        // Returns top data
        tipo peek();

        // Returns queue size
        size_t size();

        // Returns 1 if queue is empty, 0 otherwise.
        bool isEmpty();

};

template<class tipo>
Queue<tipo>::~Queue() {
    vect.clear();
}

template<class tipo>
void Queue<tipo>::enqueue(tipo data) {
    
    vect.push_back(data);
}

template<class tipo>
tipo Queue<tipo>::dequeue() {

    tipo data = vect.front();
    vect.erase(vect.begin());

    return data;
}

template<class tipo>
tipo Queue<tipo>::peek() {

    return vect.front();
}

template<class tipo>
size_t Queue<tipo>::size() {
    return vect.size();
}

template<class tipo>
bool Queue<tipo>::isEmpty() {
    return vect.empty();
}

#endif /* __QUEUE_HPP__ */
