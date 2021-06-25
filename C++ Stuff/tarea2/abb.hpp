#include <iostream>

using namespace std;

typedef int tElemArbol; //Definir dependiendo de la tarea
//Falta la funcion procesar

struct tNodoArbolBin{
    tElemArbol info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

class tABB {
    private:
        tNodoArbolBin *raiz; 
        int nElems; 
    public:
        tABB() {
            raiz = NULL;
            nElems = 0; 
        }

        ~tABB() {
            clear();
        }

        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return; 
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }

        void clear() {
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }

        void insert(tElemArbol item) {
            if(raiz==NULL) raiz->info = item;                     //Si el arbol está vacio creamos un nodo como raiz
            else{                                                 //Si el arbol tiene un nodo o más
                int valorRaiz = raiz->info;                       //Obtenemos el valor de la raiz
                if(item < valorRaiz){                             //Si el nodo es menor a la raiz, lo insertamos en el lado izquierdo
                    insert(raiz->izq->info, item);
                }
                else{                                             //Si el nodo es mayor a la raiz, lo insertamos en el lado derecho
                    insert(raiz->der->info, item);
                }                
            }
        }

        void remove(tElemArbol item) {

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

        int find(tElemArbol item) {
            return findHelp(raiz, item);
        }

        int size() {
            return nElems;
        }
        
        void inOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            inOrdenHelp (nodo->izq); 
            procesar(nodo->info);
            inOrdenHelp (nodo->der); 
        }

        void inOrden() {
            inOrdenHelp (raiz);
        }

        void preOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            procesar(nodo->info);
            preOrdenHelp (nodo->izq);
            preOrdenHelp (nodo->der);
        }

        void preOrden() {
            preOrdenHelp (raiz);
        }

        void postOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            postOrdenHelp (nodo->izq);
            postOrdenHelp (nodo->der);
            procesar(nodo->info);
        }

        void postOrden() {
            postOrdenHelp (raiz);
        }
};