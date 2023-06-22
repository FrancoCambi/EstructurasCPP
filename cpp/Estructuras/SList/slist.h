#ifndef __SLIST_H__
#define __SLIST_H__

#include<iostream>

typedef void (*FuncionVisitante) (int dato);
typedef void (*FuncionMap)(int* dato);
typedef int (*FuncionFilter)(int dato);

// Representación de un NODO de una lista simplemente enlazada
// de enteros.
class SNodo {
    public:
        int dato;
        SNodo* next;
	
};

// Representación de una lista simplemente enlazada
// de enteros.
class SList {
    private:
	    SNodo* head;
        size_t longitud;
	public:
        
        // Constructor, setea head a null y longitud a 0.
        SList() { 

            head = NULL;
            longitud = 0;
        }

        // Head getter.
        SNodo* getHead() { return head; }

        // Longitud getter.
        size_t getLongitud() { return longitud; }
        
        // Destruye la lista.
        void destruir();

        // Chequea si la lista es vacia.
        int empty();

        // Agrega al final de la lista.
        void agregarFinal(int);

        // Agrega al inicio de la lista.
        void agregarInicio(int);

        // Elimina un nodo arrancando desde la pos 0
        void eliminar(size_t);

        // Inserta un dato en la lista.
        void insertar(int, size_t);
        
        // Recorre toda la lista aplicando la funcion a cada dato.
		void recorrer(FuncionVisitante);

        // Concatena una lista.
        void concatenar(SList);

        // Mapea la lista con una funcion dada.
        void map(FuncionMap);

        // Filtra una lista.
        void filter(FuncionFilter);

        // Devuelve la posición de la primera ocurrencia del dato en la lista
        int indice(int);

        // Ordena la lista usando bubbleSort como algoritmo
        void bubbleSort();

        // Devuelve 1 si el dato esta en la lista, 0 caso contrario
        int contiene(int);
};

#endif /* __SLIST_H__ */