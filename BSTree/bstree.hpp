#ifndef __BSTREE_HPP__
#define __BSTREE_HPP__

#include<iostream>
#include<queue>

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
// Tree node class representation.
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
// Binary search tree class representation.
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

        // Returns how many nodes are in the tree.
        int nodeQuantity();

        // Returns an array containing tree data using BFS traversal.
        tipo* BFSArray();

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

template<typename tipo>
int nodeQuantityAux(Node<tipo>* node) {

    if (node == nullptr)
        return 0;
    
    return 1 + nodeQuantityAux(node->left) + nodeQuantityAux(node->right);
}
template<class tipo>
int BSTree<tipo>::nodeQuantity() {

    return nodeQuantityAux(root);
}

template<typename tipo>
void BFSArrayAux(Node<tipo>* node, tipo* arr) {

    if (node == nullptr)
        return;

    std::queue<Node<tipo>*> queue;
    size_t size = 0;

    queue.push(node);

    while (!queue.empty()) {

        Node<tipo>* currentNode = queue.front();

        arr[size++] = currentNode->data;

        queue.pop();

        if (currentNode->left != nullptr)
            queue.push(currentNode->left);
        if (currentNode->right != nullptr)
            queue.push(currentNode->right);
        
    }

}
template<class tipo>
tipo* BSTree<tipo>::BFSArray() {

    int nodes = nodeQuantity();

    tipo *arr = new tipo[nodes]();

    BFSArrayAux(root, arr);

    return arr;

}



#endif /* __BTREE_HPP__ */