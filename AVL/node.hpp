#ifndef __NODE_HPP__
#define __NODE_HPP__

#include<iostream>

// If tipo isn't a pointer, do nothing.
template<typename tipo>
static void deleteData(tipo data) { return; }

// OVERLOAD -> if tipo is a pointer, delete it.
template<typename tipo>
static void deleteData(tipo* data) { delete data; }

template<class tipo>
class Node {
    public:
        tipo data;
        Node<tipo>* left;
        Node<tipo>* right;
        int height;

        // CONSTRUCTOR
        Node(tipo _data) {
            data = _data;
            left = right = nullptr;
            height = 0;
        }

        // Destructor
        ~Node() {
            deleteData(data);
        }

};


#endif