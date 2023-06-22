#ifndef __AVL_HPP__
#define __AVL_HPP__

#include<iostream>
#include<queue>

#include"utils.hpp"

template<class tipo>
class AVL {
    typedef void (*VisitFunction)(tipo val);
    public:
        Node<tipo>* root;

        // Constructor.
        AVL();

        // Destructor.
        ~AVL();

        // Checks if data is in tree.
        int search(tipo val);

        // Inserts data in AVL keeping AVL property.
        void insert(tipo val);

        // Prints traversal of tree (preorder, inorder, postorder or BFS).
        void traversal(TraversalType type);

        // Removes data in AVL keeping AVL property.
        void remove(tipo val);

        // Returns the number of nodes in tree
        int nodeQuantity();

        // Returns array with tree data (BFS traversal)
        tipo* BFSArray();
};

template<class tipo>
// Constructor
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
// Destructor
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
// Checks if data is in tree.
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
// Inserts data in AVL keeping AVL property.
void AVL<tipo>::insert(tipo val) {

    root = insertAux(root, val);
    
}

template<typename tipo>
static void traversalAux(Node<tipo>* node, TraversalType type) {

    if (node != nullptr) {
        if (type == PRE)
            std::cout << node->data << " ";
        traversalAux(node->left, type);
        if (type == IN)
            std::cout << node->data << " ";
        traversalAux(node->right, type);
        if (type == POST)
            std::cout << node->data << " ";
    }
}
template<typename tipo>
static void TraversalBFSAux(Node<tipo>* node, tipo* arr) {

    if (node == nullptr)
        return;

    std::queue<Node<tipo>*> queue;
    size_t size = 0;

    queue.push(node);

    while (!queue.empty()) {

        Node<tipo>* currentNode = queue.front();

        if (arr == nullptr)
            std::cout << currentNode->data << " ";
        else
            arr[size++] = currentNode->data;

        queue.pop();

        if (currentNode->left != nullptr)
            queue.push(currentNode->left);
        if (currentNode->right != nullptr)
            queue.push(currentNode->right);
        
    }

}
template<class tipo>
void AVL<tipo>::traversal(TraversalType type) {

    if (type == PRE || type == IN || type == POST)
        traversalAux(root, type);
    else {
        tipo* arr = nullptr;
        TraversalBFSAux(root, arr);
    }
}


template<typename tipo>
static Node<tipo>* removeAux(Node<tipo>* node, tipo val) {

    if (node == nullptr)
        return nullptr;
    
    if (val < node->data)
        node->left = removeAux(node->left, val);
    else if (val > node->data)
        node->right = removeAux(node->right, val);
    else {

        if (node->left == nullptr) {

            Node<tipo>* temp = node->right;
            delete node;
            return temp;
        }

        else if (node->right == nullptr) {

            Node<tipo>* temp = node->left;
            delete node;
            return temp;
        }

        Node<tipo>* temp = deepLeft(node->right);

        node->data = temp->data;
        
        node->right = removeAux(node->right, temp->data);
    }

    node = balance(node);
    return node;
}
template<class tipo>
// Removes data in AVL keeping AVL property.
void AVL<tipo>::remove(tipo val) {
    root = removeAux(root, val);
}

template<typename tipo>
static int nodeQuantityAux(Node<tipo>* node) {

    if (node == nullptr)
        return 0;
    
    return 1 + nodeQuantityAux(node->left) + nodeQuantityAux(node->right);
}
template<class tipo>
// Returns the number of nodes in tree
int AVL<tipo>::nodeQuantity() {

    return nodeQuantityAux(root);
}


template<class tipo>
// Returns array with tree data (BFS traversal)
tipo* AVL<tipo>::BFSArray() {

    int nodes = nodeQuantity();

    tipo *arr = new tipo[nodes]();

    TraversalBFSAux(root, arr);

    return arr;

}


#endif /* __AVL_HPP__ */