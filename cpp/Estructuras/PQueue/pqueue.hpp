#ifndef __PQUEUE_HPP__
#define __PQUEUE_HPP__

#include<iostream>
#include<vector>
#include"data.hpp"

template<class tipo>
// Priority queue class representation.
class PQueue {

    private:
        std::vector<Data<tipo>> vect;

    public:
        
        // Destructor
        ~PQueue();

        // Push data into the pqueue
        void enqueue(tipo val, unsigned int prio);

        // Pop data from the qpueue and return it
        tipo dequeue();

        // Returns top data
        tipo peek();

        // Returns pqueue size
        unsigned int size();

        // Returns 1 if pqueue is empty, 0 otherwise.
        bool isEmpty();

};

template<class tipo>
PQueue<tipo>::~PQueue() {
    vect.clear();
}

template<class tipo>
void PQueue<tipo>::enqueue(tipo val, unsigned int prio) {
    
    Data<tipo> data = Data<tipo>(val, prio);
    vect.push_back(data);

    unsigned int len = vect.size();
    int i;

    for (i = len - 1; i > 0 && vect.at(i).getPriority() > vect.at(i - 1).getPriority(); i--) {
        
        Data<tipo> temp = vect.at(i);
        vect.at(i) = vect.at(i - 1);
        vect.at(i - 1) = temp;
    }
}

template<class tipo>
tipo PQueue<tipo>::dequeue() {

    Data<tipo> data = vect.front();
    vect.erase(vect.begin());

    return data.getData();
}

template<class tipo>
tipo PQueue<tipo>::peek() {

    return vect.front().getData();
}

template<class tipo>
unsigned int PQueue<tipo>::size() {
    return vect.size();
}

template<class tipo>
bool PQueue<tipo>::isEmpty() {
    return vect.empty();
}

#endif /* __PQUEUE_HPP__ */
