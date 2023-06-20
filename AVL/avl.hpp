#ifndef __AVL_HPP__
#define __AVL_HPP__

#include<iostream>
#include<queue>
#include"utils.hpp"

typedef enum {
    IN,
    PRE,
    POST
}TraversalType;

template<class tipo>
class AVL {
    public:
        Node<tipo>* root;

        // Constructor
        AVL();

        // Destructor
        ~AVL();

        // Checks if data is in tree.
        int search(tipo val);

        // Inserts data in AVL keeping AVL property
        void insert(tipo val);


};

template<class tipo>
AVL<tipo>::AVL() { root = nullptr; }

template<typename tipo>
static void AVLDeleteAux(Node<tipo>* node) {
    if (node != nullptr) {
        AVLDeleteAux(node->left);
        AVLDeleteAux(node->right);
        delete node;
    }
}
template<class tipo>
AVL<tipo>::~AVL() { 

    AVLDeleteAux(root);
}

template<typename tipo>
static int searchAux(Node<tipo>* node, tipo val) {  

    if (node == nullptr)
        return 0;
    
    else if (val == node->data)
        return 1;
    
    else if (val < node->data)
        return searchAux(node->left, val);
    
    else
        return searchAux(node->right, val);
}
template<class tipo>
int AVL<tipo>::search(tipo val) {
    return searchAux(root, val);
}

template<typename tipo>
static Node<tipo>* insertAux(Node<tipo>* node, tipo val) {

    if (node == nullptr) {
        Node<tipo>* newNode = new Node<tipo>(val);
        return newNode;
    }

    else if (val < node->data) { // left subtree
        node->left = insertAux(node->left, val);
        node = balance(node);
        node->height = 1 + maxHeightChildren(node);
        return node;
    }

    else if (val > node->data) { // right subtree
        node->right = insertAux(node->right, val);
        node = balance(node);
        node->height = 1 + maxHeightChildren(node);
        return node;
    }
    else
        return node;

}
template<class tipo>
void AVL<tipo>::insert(tipo val) {

    root = insertAux(root, val);
    
}

#endif /* __AVL_HPP__ */