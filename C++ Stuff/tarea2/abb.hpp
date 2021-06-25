#include <iostream>

using namespace std;

typedef int tElemArbol; //Definir dependiendo de la tarea

//Falta la funcion procesar
//No le encuentro un uso a la funcion tdvia asi que se deja como está
//en volá en la implementacion le encuentro el uso

//remove casos 1 y 2 terminados, falta el remove de nodo con 2 hijos

struct tNodoArbolBin{
    tElemArbol info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
    tNodoArbolBin* padre;
};

class tABB {
    private:
        tNodoArbolBin *raiz; 
        int nElems;

        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return; 
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }

        void insertHelp(tNodoArbolBin *nodo, tElemArbol item, tNodoArbolBin *padre){
            if(nodo==NULL) {
                nodo = new tNodoArbolBin;
                nodo->info = item;                    //Si el arbol está vacio creamos un nodo como raiz
                nodo->padre = padre;
                nElems++;
            }else{                                                 //Si el arbol tiene un nodo o más
                int valorNodo = nodo->info;                       //Obtenemos el valor de la raiz
                tNodoArbolBin* aux = nodo;
                if(item < valorNodo){                             //Si el nodo es menor a la raiz, lo insertamos en el lado izquierdo
                    insertHelp(nodo->izq, item, aux);
                }
                else{                                             //Si el nodo es mayor a la raiz, lo insertamos en el lado derecho
                    insertHelp(nodo->der, item, aux);
                }                
            }
        }

        void removeHelp(tNodoArbolBin *nodo, tElemArbol item) {
            int caso;
            if(find(item) == 0) return;
            tNodoArbolBin* aux = search(nodo, item);
            if (aux->der == NULL && aux->izq == NULL) caso = 1;
            if ((aux->der != NULL && aux->izq == NULL) || (aux->der == NULL && aux->izq != NULL) ) caso = 2;
            if (aux->der != NULL && aux->izq != NULL) caso = 3;
            switch (caso) {
            case 1: //nodo sin hijos
                delete aux;
                break;
            case 2: //nodo con 1 hijo
                if(aux->padre->der == aux){
                    if (aux->der == NULL) {
                        aux->padre->der = aux->izq;
                        aux->izq->padre = aux->padre;
                    }else{
                        aux->padre->der = aux->der;
                        aux->der->padre = aux->padre;
                    }
                }else{
                    if (aux->der == NULL) {
                        aux->padre->izq = aux->izq;
                        aux->izq->padre = aux->padre;
                    }else{
                        aux->padre->izq = aux->der;
                        aux->der->padre = aux->padre;
                    }
                }
                delete aux;
                break;
            case 3: //nodo con 2 hijos
                bool sucesorAntecesor;
                int k = 1;
                while (sucesorAntecesor == false) {
                    if(find(item - k)) sucesorAntecesor = true;
                    else{
                        k++;
                    }
                }
                tElemArbol aux2 = item - k;
                tNodoArbolBin* aux3 = search(nodo, aux2);
                aux->info = aux3->info;
                removeHelp(aux3, aux2);
                break;
            }
        }

        int findHelp(tNodoArbolBin *nodo, tElemArbol item) {
            if (nodo == NULL) return 0; 
            if (nodo->info == item) return 1; 
            if (item < nodo->info) {
                return findHelp(nodo->izq, item);
            }
            else {
                return findHelp(nodo->der, item);
            }
        }

        void inOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            inOrdenHelp (nodo->izq); 
            procesar(nodo->info);
            inOrdenHelp (nodo->der); 
        }

        void preOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            procesar(nodo->info);
            preOrdenHelp (nodo->izq);
            preOrdenHelp (nodo->der);
        }

        void postOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            postOrdenHelp (nodo->izq);
            postOrdenHelp (nodo->der);
            procesar(nodo->info);
        }

        tNodoArbolBin* search(tNodoArbolBin *nodo, tElemArbol item){
            if (nodo->info == item) return nodo; 
            if (item < nodo->info) {
                search(nodo->izq, item);
            }
            else {
                search(nodo->der, item);
            }
        }

        void procesar(tElemArbol item) {}

    public:
        tABB() {
            raiz = NULL;
            nElems = 0; 
        }

        ~tABB() {
            clearHelp(raiz);
        }

        void clear() {
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }

        void insert(tElemArbol item) {
            insertHelp(raiz, item, NULL); 
        } 

        void remove(tElemArbol item){
            removeHelp(raiz, item);
        }

        int find(tElemArbol item) {
            return findHelp(raiz, item);
        }

        int size() {
            return nElems;
        }

        void inOrden() {
            inOrdenHelp (raiz);
        }

        void preOrden() {
            preOrdenHelp (raiz);
        }

        void postOrden() {
            postOrdenHelp (raiz);
        }
};