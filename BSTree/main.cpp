#include"main.hpp"

int main(void) {


    BSTree<int> bt = BSTree<int>();

    /*int *a = new int;
    int *b = new int;
    int *c = new int;

    *a = 3;
    *b = 2;
    *c = 5;*/

    int e = 7, d = 5, f = 4;

    bt.insert(20);
    bt.insert(15);
    bt.insert(10);
    bt.insert(9);
    bt.insert(8);
    bt.insert(11);
    bt.insert(13);
    bt.insert(25);

    bt.remove(20);

    bt.traversal(IN);
    
}