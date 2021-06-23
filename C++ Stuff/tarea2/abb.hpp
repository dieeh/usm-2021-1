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

        void clear() {
            void clearHelp(tNodoArbolBin *nodo) {
                if (nodo == NULL) return; 
                clearHelp(nodo->izq); 
                clearHelp(nodo->der); 
                delete nodo; 
            }
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }
        void insert(tElemArbol item) {

        }
        void remove(tElemArbol item) {

        }
        int find(tElemArbol item) {
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
            return findHelp(raiz, item);
        }
        int size() {
            return nElems;
        }
        void inOrden() {
            void inOrdenHelp (tNodoArbolBin *nodo) {
                if (nodo == NULL) return;
                inOrdenHelp (nodo->izq); 
                procesar(nodo->info);
                inOrdenHelp (nodo->der); 
            }
            inOrdenHelp (raiz);
        }
        void preOrden() {
            void preOrdenHelp (tNodoArbolBin *nodo) {
                if (nodo == NULL) return;
                procesar(nodo->info);
                preOrdenHelp (nodo->izq);
                preOrdenHelp (nodo->der);
            }
            preOrdenHelp (raiz);
        }
        void postOrden() {
            void postOrdenHelp (tNodoArbolBin *nodo) {
                if (nodo == NULL) return;
                postOrdenHelp (nodo->izq);
                postOrdenHelp (nodo->der);
                procesar(nodo->info);
            }
            postOrdenHelp (raiz);
        }
}