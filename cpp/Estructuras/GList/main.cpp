#include"main.hpp"

void imprimir_entero(int dato) {
	std::cout << dato << " ";
}

void imprimir_cadena(std::string cad) {
	std::cout << cad << " ";
}

void asd (std::string* cad) {
	cad->append("aa");
}

int filtrar(std::string cad) {
	return cad.length() > 3;
}

void sumar(int *dato) {
	(*dato)++;
}

int main() 
{	

	GList<int> lista = GList<int>();

	lista.agregarFinal(30);
	lista.agregarFinal(40);
	lista.agregarFinal(35);
	lista.agregarFinal(5);
	lista.agregarFinal(7);
	lista.agregarFinal(80);
	lista.agregarFinal(1);
	lista.agregarFinal(2);
	lista.agregarFinal(4);
	lista.agregarFinal(13);
	lista.agregarFinal(11);
	lista.agregarFinal(39);
	lista.agregarFinal(99);
	lista.agregarFinal(55);

	lista.mergeSort();

	lista.recorrer(imprimir_entero);
	lista.destruir();
	return 0;
}
