#include"slist.h"

// Destruye la lista.
void SList::destruir() {

    SNodo* nodoAEliminar;
    while (head != NULL) {
        nodoAEliminar = head;
        head = head->next;
        delete nodoAEliminar;
    }
}

// Chequea si la lista es vacia.
int SList::empty() { return head == NULL; }

// Agrega al final de la lista.
void SList::agregarFinal(int dato) {

	SNodo *nuevoNodo = new SNodo();
	longitud++;

	nuevoNodo->dato = dato;
	nuevoNodo->next = NULL;

	if (empty()) {
		head = nuevoNodo;
		return;
	}

	SNodo* temp = head;
	for (; temp->next != NULL; temp = temp->next);
	// Ahora temp apunta al ultimo elemento de la lista

	temp->next = nuevoNodo;
}

// Elimina un nodo arrancando desde la pos 0
void SList::eliminar(size_t pos) {

	if (pos >= longitud || empty())
		return;

	if (pos == 0) {
		SNodo *nodoALiberar = head;
		head = head->next;
		delete nodoALiberar;
		return;
	}

	SNodo *temp1 = head;
	SNodo *temp2 = head->next;

	int i = 1;
	while (i++ < pos) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	longitud--;
	delete temp2;

}


//Inserta un dato en la lista.
void SList::insertar(int dato, size_t pos) {

	// Si pos se pasa, agregamos al final
	if (pos >= longitud) {
		agregarFinal(dato);
		return;
	}

	// Si pos es 0, agregar al inicio.
	if (pos == 0) {
		agregarInicio(dato);
		return;
	}

	// pos >= 1
	SNodo* nuevoNodo = new SNodo();
	nuevoNodo->dato = dato;

	SNodo* temp1 = head;
	SNodo* temp2 = head->next;

	
	int i = 1;
	while (i++ < pos) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	// temp1 apunta al nodo en pos - 1
	// temp2 apunta al nodo en pos + 1

	temp1->next = nuevoNodo;
	nuevoNodo->next = temp2;
	longitud++;
}

// Agrega al inicio de la lista.
void SList::agregarInicio(int dato) {

	SNodo* nuevoNodo = new SNodo();

	nuevoNodo->dato = dato;
	nuevoNodo->next = head;

	head = nuevoNodo;
	longitud++;
}

// Recorre toda la lista aplicando la funcion a cada dato.
void SList::recorrer(FuncionVisitante visit) {

	SNodo* temp = head;

	while (temp != NULL) {
		visit(temp->dato);
		temp = temp->next;
	}
}

// Concatena una lista.
void SList::concatenar(SList lista) {

	SNodo* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = lista.getHead();
	longitud += lista.getLongitud();
}

// Mapea una lista con la función dada.
void SList::map(FuncionMap mapear) {

	SNodo* temp = head;

	while (temp != NULL) {
		mapear(&(temp->dato));
		temp = temp->next;
	}
	
}

// Filtra una lista.
void SList::filter(FuncionFilter filter) {

	SNodo* temp = head;
	int i = 0, eliminados = 0, datoTemp;

	while (temp != NULL) {
		datoTemp = temp->dato;
		temp = temp->next;
		if (!(filter(datoTemp)))
			eliminar(i++ - eliminados++);
	}
}

// Devuelve la posición de la primer ocurrencia del dato en la lista
int SList::indice(int dato) {

	int indice = -1, i = 0;

	for (SNodo* temp = head; temp != NULL && indice == -1; temp = temp->next, i++)
		if (temp->dato == dato)
			indice = i;

	return indice;
}

// Ordena la lista usando bubbleSort como algoritmo
void SList::bubbleSort() {

	for (SNodo* nodo = head; nodo->next != NULL; nodo = nodo->next) {
		for (SNodo* nodo2 = nodo->next; nodo2 != NULL; nodo2 = nodo2->next)
			if (nodo->dato > nodo2->dato) {
				int temp = nodo->dato;
				nodo->dato = nodo2->dato;
				nodo2->dato = temp;
			}
	}
}

// Devuelve 1 si el dato esta en la lista, 0 caso contrario
int SList::contiene(int dato) {

	int esta = 0;

	for (SNodo* nodo = head; nodo != NULL && esta == 0; nodo = nodo->next) 
		if (nodo->dato == dato)
			esta = 1;
	
	return esta;
}