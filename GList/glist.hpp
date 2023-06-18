#ifndef __GLIST_HPP__
#define __GLIST_HPP__

#include<iostream>

template<class tipo>
// Representación de un NODO de una lista simplemente enlazada
// general.
class GNodo {
    public:
        tipo dato;
        GNodo<tipo>* next;
	
};

template<class tipo>
// Representación de una lista simplemente enlazada
// general.
class GList {

    private:
	    GNodo<tipo>* head;
        size_t longitud;
	public:

        typedef void (*FuncionVisitante) (tipo dato);
        typedef void (*FuncionMap)(tipo* dato);
        typedef int (*FuncionFilter)(tipo dato);

        // Constructor, setea head a null y longitud a 0.
        GList<tipo>() { 

            head = nullptr;
            longitud = 0;
        }

        // Head getter.
        GNodo<tipo>* getHead() { return head; }

        // Longitud getter.
        size_t getLongitud() { return longitud; }
        
        // Destruye la lista.
        void destruir() {
            GNodo<tipo>* nodoAEliminar;
            while (head != nullptr) {
                nodoAEliminar = head;
                head = head->next;
                delete nodoAEliminar;
            }
        }

        // Chequea si la lista es vacia.
        int empty() {return head == nullptr; }
        
        // Agrega al final de la lista.
        void agregarFinal(tipo dato) {

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

        // Agrega al inicio de la lista.
        void agregarInicio(tipo dato) {

            GNodo<tipo>* nuevoNodo = new GNodo<tipo>();

            nuevoNodo->dato = dato;
            nuevoNodo->next = head;

            head = nuevoNodo;
            longitud++;
        }

        // Elimina un nodo arrancando desde la pos 0
        void eliminar(size_t pos) {

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


        //Inserta un dato en la lista.
        void insertar(tipo dato, size_t pos) {

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
                
        // Recorre toda la lista aplicando la funcion a cada dato.
        void recorrer(FuncionVisitante visit) {

            GNodo<tipo>* temp = head;

            while (temp != nullptr) {
                visit(temp->dato);
                temp = temp->next;
            }
        }

        // Concatena una lista.
        void concatenar(GList<tipo> lista) {

            GNodo<tipo>* temp = head;

            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = lista.getHead();
            longitud += lista.getLongitud();
        }

        // Mapea una lista con la función dada.
        void map(FuncionMap mapear) {

            GNodo<tipo>* temp = head;

            while (temp != nullptr) {
                mapear(&(temp->dato));
                temp = temp->next;
            }
            
        }

        // Filtra una lista.
        void filter(FuncionFilter filter) {

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

        // Devuelve la posición de la primer ocurrencia del dato en la lista
        int indice(tipo dato) {

            int indice = -1, i = 0;

            for (GNodo<tipo>* temp = head; temp != nullptr && indice == -1; temp = temp->next, i++)
                if (temp->dato == dato)
                    indice = i;

            return indice;
        }

        // Ordena la lista usando bubbleSort como algoritmo
        void bubbleSort() {

            for (GNodo<tipo>* nodo = head; nodo->next != nullptr; nodo = nodo->next) {
                for (GNodo<tipo>* nodo2 = nodo->next; nodo2 != nullptr; nodo2 = nodo2->next)
                    if (nodo->dato > nodo2->dato) {
                        tipo temp = nodo->dato;
                        nodo->dato = nodo2->dato;
                        nodo2->dato = temp;
                    }
            }
        }

        // Devuelve 1 si el dato esta en la lista, 0 caso contrario
        int contiene(tipo dato) {

            int esta = 0;

            for (GNodo<tipo>* nodo = head; nodo != nullptr && esta == 0; nodo = nodo->next) 
                if (nodo->dato == dato)
                    esta = 1;
            
            return esta;
        }

};

#endif /* __GLIST_H__ */