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

        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return; 
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }

        void insertHelp(tNodoArbolBin *nodo, tElemArbol item){
            if(nodo==NULL) nodo->info = item;                     //Si el arbol está vacio creamos un nodo como raiz
            else{                                                 //Si el arbol tiene un nodo o más
                int valorNodo = nodo->info;                       //Obtenemos el valor de la raiz
                if(item < valorNodo){                             //Si el nodo es menor a la raiz, lo insertamos en el lado izquierdo
                    insertHelp(nodo->izq, item);
                }
                else{                                             //Si el nodo es mayor a la raiz, lo insertamos en el lado derecho
                    insertHelp(nodo->der, item);
                }                
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

        void insert(tElemArbol item) {
            insertHelp(raiz, item); 
        } 

        void remove(tElemArbol item) {}

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