#include"main.h"

void imprimir_entero(int dato) {
	std::cout << dato << " ";
}

void sumar(int *dato) {
	(*dato)++;
}

int filtrar(int dato) {
	return dato > 4;
}

int main() 
{	

	SList lista = SList();

	lista.agregarFinal(10);
	lista.agregarFinal(9);
	lista.agregarFinal(8);
    lista.agregarFinal(7);
	
	SList lista2 = SList();

	lista2.agregarFinal(6);
	lista2.agregarFinal(7);
	lista2.agregarFinal(8);
    lista2.agregarFinal(9);
    lista2.agregarFinal(10);

    lista.recorrer(imprimir_entero);
    puts("");

	lista.bubbleSort();
	lista.recorrer(imprimir_entero);
	//std::cout << std::endl << lista.indice(5);
	lista.destruir();
	lista2.destruir();
	return 0;
}
