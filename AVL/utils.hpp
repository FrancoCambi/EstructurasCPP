#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include"node.hpp"

typedef enum {
    IN,
    PRE,
    POST,
    BFS
}TraversalType;

template<typename tipo>
// Auxiliar function
// Returns height of node, -1 if node is nullptr
int nodeHeight(Node<tipo>* node) {
    return node == nullptr ? -1 : node->height;
} 

template<typename tipo>
// Auxiliar Function.
// Returns max height between children of node.
int maxHeightChildren(Node<tipo>* node) {
    if (node == nullptr)
        exit(EXIT_FAILURE);

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

template<typename tipo>
// Auxiliar function
// Returns balance factor between children of node.
// (rightChildren height - leftChildren height)
int factor(Node<tipo>* node) {
    if (node == nullptr)
        exit(EXIT_FAILURE);
    
    int factor = nodeHeight(node->right) - nodeHeight(node->left);
    
    return factor;
}

template<typename tipo>
// Auxiliar function
// Simple rotation to the left.
Node<tipo>* leftRotation(Node<tipo>* node) {
    if (node->right == nullptr)
        exit(EXIT_FAILURE);
    
    Node<tipo>* rightChild = node->right;

    node->right = rightChild->left;
    rightChild->left = node;

    node->height = 1 + maxHeightChildren(node);
    rightChild->height = 1 + maxHeightChildren(rightChild);

    return rightChild;
}

template<typename tipo>
// Auxiliar function
// Simple rotation to the right.
Node<tipo>* rightRotation(Node<tipo>* node) {
    if (node->left == nullptr)
        exit(EXIT_FAILURE);
    
    Node<tipo>* leftChild = node->left;

    node->left = leftChild->right;
    leftChild->right = node;

    node->height = 1 + maxHeightChildren(node);
    leftChild->height = 1 + maxHeightChildren(leftChild);

    return leftChild;
}

template<typename tipo>
// Auxiliar function
// Given root of tree, make simple or double rotation 
//in order to make it balanced
Node<tipo>* balance(Node<tipo>* node) {

    if (node == nullptr)
        return nullptr;

    if (factor(node) == -2) {
        if (factor(node->left) == 1)
            node->left = leftRotation(node->left);
        
        node = rightRotation(node);
    }
    else if (factor(node) == 2) {
        if (factor(node->right) == -1)
            node->right = rightRotation(node->right);
        
        node = leftRotation(node);
    }

    node->height = 1 + maxHeightChildren(node);

    return node;
}

template<typename tipo>
// Auxiliar function.
// Returns most to the left node.
Node<tipo>* deepLeft(Node<tipo>* node) {

    Node<tipo>* temp = node;

    while (temp && temp->left != nullptr) 
        temp = temp->left;
    
    return temp;
}

#endif /* __UTILS_HPP__ */