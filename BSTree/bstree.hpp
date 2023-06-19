#ifndef __BSTREE_HPP__
#define __BSTREE_HPP__

#include<iostream>

typedef enum {
    IN,
    PRE,
    POST
}TraversalType;

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

        // Destructor
        ~Node() {
            deleteData(data);
        }
};

template<class tipo>
class BSTree {
    public:
        Node<tipo>* root;

        // Constructor
        BSTree();

        // Destructor
        ~BSTree();

        // Insert node
        void insert(tipo val);

        // Checks if data is in tree
        int search(tipo val);

        // Traverse tree (preorder, inorder or postorder)
        void traversal(TraversalType type);

        // Delete data from BST
        void remove(tipo val);



};

template<class tipo>
BSTree<tipo>::BSTree() { root = nullptr; }

template<typename tipo>
static void BSTreeDeleteAux(Node<tipo>* node) {
    if (node != nullptr) {
        BSTreeDeleteAux(node->left);
        BSTreeDeleteAux(node->right);
        delete node;
    }
}
template<class tipo>
BSTree<tipo>::~BSTree() { 

    BSTreeDeleteAux(root);
}


template<typename tipo>
static Node<tipo>* insertAux(Node<tipo>* node, tipo val) {

    if (node == nullptr) {

        Node<tipo>* newNode = new Node<tipo>();
        newNode->data = val;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    else if (val < node->data) 
        node->left = insertAux(node->left, val);
    else if (val > node->data)
        node->right = insertAux(node->right, val);
    
    return node;
}
template<class tipo>
void BSTree<tipo>::insert(tipo val) {

    root = insertAux(root, val);
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
int BSTree<tipo>::search(tipo val) {
    return searchAux(root, val);
}

template<typename tipo>
static void traversalAux(Node<tipo>* node, TraversalType type) {

    if (node == nullptr) return;

    if (type == PRE)
        std::cout << node->data << " ";
    traversalAux(node->left, type);
    if(type == IN)
        std::cout << node->data << " ";
    traversalAux(node->right, type);
    if (type == POST)
        std::cout << node->data << " ";
}
template<class tipo>
void BSTree<tipo>::traversal(TraversalType type) {
    traversalAux(root, type);
}

template<typename tipo>
static Node<tipo>* deepLeft(Node<tipo>* node) {

    Node<tipo>* temp = node;

    while (temp && temp->left != nullptr) 
        temp = temp->left;
    
    return temp;
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

    return node;
}
template<class tipo>
void BSTree<tipo>::remove(tipo val) {
    root = removeAux(root, val);
}

#endif /* __BTREE_HPP__ */