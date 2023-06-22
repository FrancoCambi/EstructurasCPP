#include"main.hpp"

void imprimir_entero(int data) {
    std::cout << data << " ";
}

int main(void) {


    BSTree<int> bt = BSTree<int>();

    /*int *a = new int;
    int *b = new int;
    int *c = new int;

    *a = 3;
    *b = 2;
    *c = 5;*/

    int e = 7, d = 5, f = 4;

    bt.insert(15);
    bt.insert(12);
    bt.insert(17);
    bt.insert(11);
    bt.insert(13);
    bt.insert(16);
    bt.insert(18);


    GList<int> lista = bt.depthList(-2);


    lista.recorrer(imprimir_entero);
    
}