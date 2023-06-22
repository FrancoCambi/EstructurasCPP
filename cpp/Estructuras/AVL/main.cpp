#include"main.hpp"

int main(void) {


    AVL<int> avl = AVL<int>();

    avl.insert(3);
    avl.insert(2);
    avl.insert(10);
    avl.insert(11);
    avl.insert(50);
    avl.insert(20);
    avl.insert(35);

    avl.remove(35);
    avl.remove(20);
    avl.remove(50);

    avl.traversal(BFS);


   
}