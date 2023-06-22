#ifndef __GLIST_HPP__
#define __GLIST_HPP__

#include<iostream>

// If tipo isn't a pointer, do nothing.
template<typename tipo>
static void deleteData(tipo data) { return; }

// OVERLOAD -> if tipo is a pointer, delete it.
template<typename tipo>
static void deleteData(tipo* data) { delete data; }


template<class tipo>
// Representación de un NODO de una lista simplemente enlazada
// general.
class GNodo {
    public:
        tipo dato;
        GNodo<tipo>* next;

        ~GNodo() {
            deleteData(dato);
        }
	
};

template<class tipo>
// Representación de una lista simplemente enlazada
// general.
class GList {

    private:
	    GNodo<tipo>* head;
        size_t longitud;

        typedef void (*FuncionVisitante) (tipo dato);
        typedef void (*FuncionMap)(tipo* dato);
        typedef int (*FuncionFilter)(tipo dato);

        // Recorre la lista al reverso haciendo recursion sobre nodo
        void recorrerReverseAux(GNodo<tipo>* nodo, FuncionVisitante visit);

	public:

        // Constructor, setea head a null y longitud a 0.
        GList<tipo>() { 

            head = nullptr;
            longitud = 0;
        }

        // Head getter.
        GNodo<tipo>* getHead() { return head; }

        // Head setter.
        void setHead(GNodo<tipo>* nodo) {
            head = nodo;
        }

        // Longitud getter.
        size_t getLongitud() { return longitud; }
        
        // Destruye la lista.
        void destruir();

        // Chequea si la lista es vacia.
        int empty();
        
        // Agrega al final de la lista.
        void agregarFinal(tipo dato);

        // Agrega al inicio de la lista.
        void agregarInicio(tipo dato);

        // Elimina un nodo arrancando desde la pos 0
        void eliminar(size_t pos);

        //Inserta un dato en la lista.
        void insertar(tipo dato, size_t pos);

        // Recorre toda la lista aplicando la funcion a cada dato.
        void recorrer(FuncionVisitante visit);

        // Recorre toda la lista de derecha a izquierda.
        void recorrerReverse(FuncionVisitante visit);

        // Concatena una lista.
        void concatenar(GList<tipo> lista);

        // Mapea una lista con la función dada.
        void map(FuncionMap mapear);

        // Filtra una lista.
        void filter(FuncionFilter filter);

        // Devuelve la posición de la primer ocurrencia del dato en la lista
        int indice(tipo dato);

        // Ordena la lista usando bubbleSort como algoritmo
        void bubbleSort();

        // Devuelve la lista ordenada usando MergeSort como algoritmo
        void mergeSort();

        // Devuelve 1 si el dato esta en la lista, 0 caso contrario
        int contiene(tipo dato);



};

template<class tipo>
// Destruye la lista.
void GList<tipo>::destruir() {
    GNodo<tipo>* nodoAEliminar;
    while (head != nullptr) {
        nodoAEliminar = head;
        head = head->next;
        delete nodoAEliminar;
    }
}

template<class tipo>
// Chequea si la lista es vacia.
int GList<tipo>::empty() {return head == nullptr; }

template<class tipo>
// Agrega al final de la lista.
void GList<tipo>::agregarFinal(tipo dato) {

    GNodo<tipo>* nuevoNodo = new GNodo<tipo>();
    longitud++;

    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;

    if (empty()) {
        head = nuevoNodo;
        return;
    }

    GNodo<tipo>* temp = head;
    for (; temp->next != nullptr; temp = temp->next);
    // Ahora temp apunta al ultimo elemento de la lista

    temp->next = nuevoNodo;
}

template<class tipo>
// Agrega al inicio de la lista.
void GList<tipo>::agregarInicio(tipo dato) {

    GNodo<tipo>* nuevoNodo = new GNodo<tipo>();

    nuevoNodo->dato = dato;
    nuevoNodo->next = head;

    head = nuevoNodo;
    longitud++;
}

template<class tipo>
// Elimina un nodo arrancando desde la pos 0
void GList<tipo>::eliminar(size_t pos) {

    if (pos >= longitud || empty())
        return;

    if (pos == 0) {
        GNodo<tipo> *nodoALiberar = head;
        head = head->next;
        delete nodoALiberar;
        return;
    }

    GNodo<tipo> *temp1 = head;
    GNodo<tipo> *temp2 = head->next;

    int i = 1;
    while (i++ < pos) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    longitud--;
    delete temp2;

}


template<class tipo>
//Inserta un dato en la lista.
void GList<tipo>::insertar(tipo dato, size_t pos) {

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
    GNodo<tipo>* nuevoNodo = new GNodo<tipo>();
    nuevoNodo->dato = dato;

    GNodo<tipo>* temp1 = head;
    GNodo<tipo>* temp2 = head->next;

    
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

template<class tipo>
// Recorre toda la lista aplicando la funcion a cada dato.
void GList<tipo>::recorrer(FuncionVisitante visit) {

    GNodo<tipo>* temp = head;
    while (temp != nullptr) {
        visit(temp->dato);
        temp = temp->next;
    }

}

template<class tipo>
void GList<tipo>::recorrerReverseAux(GNodo<tipo>* nodo, FuncionVisitante visit) {

    if (nodo == nullptr)
        return;

    recorrerReverseAux(nodo->next, visit);
    visit(nodo->dato);
}   

template<class tipo>
// Recorre toda la lista de derecha a izquierda.
void GList<tipo>::recorrerReverse(FuncionVisitante visit) {
    
    GNodo<tipo>* temp = head;

    recorrerReverseAux(temp, visit);
}

template<class tipo>
// Concatena una lista.
void GList<tipo>::concatenar(GList<tipo> lista) {

    GNodo<tipo>* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = lista.getHead();
    longitud += lista.getLongitud();
}

template<class tipo>
// Mapea una lista con la función dada.
void GList<tipo>::map(FuncionMap mapear) {

    GNodo<tipo>* temp = head;

    while (temp != nullptr) {
        mapear(&(temp->dato));
        temp = temp->next;
    }
    
}

template<class tipo>
// Filtra una lista.
void GList<tipo>::filter(FuncionFilter filter) {

    GNodo<tipo>* temp = head;
    int i = 0, eliminados = 0;
    tipo datoTemp;

    while (temp != nullptr) {
        datoTemp = temp->dato;
        temp = temp->next;
        if (!(filter(datoTemp)))
            eliminar(i++ - eliminados++);
    }
}

template<class tipo>
// Devuelve la posición de la primer ocurrencia del dato en la lista
int GList<tipo>::indice(tipo dato) {

    int indice = -1, i = 0;

    for (GNodo<tipo>* temp = head; temp != nullptr && indice == -1; temp = temp->next, i++)
        if (temp->dato == dato)
            indice = i;

    return indice;
}

template<class tipo>
// Ordena la lista usando bubbleSort como algoritmo
void GList<tipo>::bubbleSort() {

    for (GNodo<tipo>* nodo = head; nodo->next != nullptr; nodo = nodo->next) {
        for (GNodo<tipo>* nodo2 = nodo->next; nodo2 != nullptr; nodo2 = nodo2->next)
            if (nodo->dato > nodo2->dato) {
                tipo temp = nodo->dato;
                nodo->dato = nodo2->dato;
                nodo2->dato = temp;
            }
    }
}

template<class tipo>
// Devuelve 1 si el dato esta en la lista, 0 caso contrario
int GList<tipo>::contiene(tipo dato) {

    int esta = 0;

    for (GNodo<tipo>* nodo = head; nodo != nullptr && esta == 0; nodo = nodo->next) 
        if (nodo->dato == dato)
            esta = 1;
    
    return esta;
}

template<typename tipo>
static GNodo<tipo>* mezclar(GNodo<tipo>* nodo1, GNodo<tipo>* nodo2) {

    GNodo<tipo>* listaResultado;

    if (nodo1 == nullptr)
        return nodo2;
    else if (nodo2 == nullptr)
        return nodo1;
    
    if (nodo1->dato <= nodo2->dato) {
        listaResultado = nodo1;
        listaResultado->next = mezclar(nodo1->next, nodo2);
    }
    else {
        listaResultado = nodo2;
        listaResultado->next = mezclar(nodo1, nodo2->next);
    }

    return listaResultado;
}
template<typename tipo>
static GNodo<tipo>* mergeSortAux(GNodo<tipo>* lista, unsigned int longitud) {

    GNodo<tipo>* nodoResultado;

    if (lista == nullptr || lista->next == nullptr)
        return lista;

    GNodo<tipo>* temp1 = lista, *temp2, *temp3;
    int cont = 0;

    // Iteramos temp2 hasta que llegue a ser el ultimo nodo de la primer mitad (de temp1)
    for (temp2 = lista; temp2 != NULL && cont < longitud / 2; temp2 = temp2->next, cont++);

    // Desenlazamos temp1 de temp2 para tener las dos mitades por separado
    temp3 = temp2->next; // temp3 es el primer nodo de la segunda mitad
    temp2->next = nullptr; // desenlace de la primera mitad

    temp1 = mergeSortAux(temp1, cont);
    temp3 = mergeSortAux(temp3, longitud - cont);

    nodoResultado = mezclar(temp1, temp3);

    return nodoResultado;

}
template<class tipo>
void GList<tipo>::mergeSort()  {

    head = mergeSortAux(head, longitud);

}
#endif /* __GLIST_H__ */