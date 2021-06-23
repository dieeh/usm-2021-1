#include <iostream>

using namespace std;

typedef int tElemArbol; //Definir dependiendo de la tarea
//Falta la funcion procesar

struct tNodoArbolBin{
    tipoElem info;
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
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }
        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return; 
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }
        void insert(tElemArbol item) {

        }
        void remove(tElemArbol item) {

        }
        int find(tElemArbol item) {
            return findHelp(raiz, item);
        }
        int findHelp(tNodoArbolBin *nodo, tipoElem item) {
            if (nodo == NULL) return 0; 
            if (nodo->info == item) return 1; 
            if (item < nodo->info) {
                return findHelp(nodo->izq, item);
            }
            else {
                return findHelp(nodo->der, item);
            }
        }
        int size() {
            return nElems;
        }
        void inOrden() {
            inOrdenHelp (raiz);
        }
        void inOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            inOrdenHelp (nodo->izq); 
            procesar(nodo->info);
            inOrdenHelp (nodo->der); 
        }
        void preOrden() {

        }
        void postOrden() {

        }
}