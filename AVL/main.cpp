#include"main.hpp"

int main(void) {


    AVL<int> avl = AVL<int>();

    avl.insert(3);
    avl.insert(2);
    avl.insert(10);


    std::cout << avl.root->data << std::endl;
    std::cout << avl.root->left->data << std::endl;
    std::cout << avl.root->right->data << std::endl;
}