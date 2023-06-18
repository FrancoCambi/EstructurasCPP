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

	GList<std::string> lista = GList<std::string>();

	lista.agregarFinal("hola");
	lista.agregarFinal("que");
	lista.agregarFinal("tal");

	std::cout << lista.contiene("holas");
	lista.destruir();
	return 0;
}
