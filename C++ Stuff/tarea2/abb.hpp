#include <iostream>

using namespace std;

typedef int tElemArbol;

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
        /*****
        *   void clearHelp
        *****
        *   Función recursiva que elimina todos los nodos del ABB, dejandolo vacío 
        *****
        *   Input:
                tNodoArbolBin: Puntero a los nodos perteneciente al árbol
        *****
        *   Returns:
                void, Borra todos los subarboles y se elimina a si mismo, dejandolo vacío
        *****/
        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }
        /*****
        *   void insertHelp
        *****
        *   Función que inserta nodos en el árbol, o crea el árbol e insertar nodos
        *****
        *   Input:
                tNodoArbolBin: Un puntero hacía nodos. 
                tElemArbol: Elemento o información que se desea agregar al árbol
                tNodoArbolBin: Puntero hacía el nodo padre (raíz)
        *****
        *   Return: 
               xd 
        *****/
        void insertHelp(tNodoArbolBin *nodo, tElemArbol item, tNodoArbolBin *padre){
            if(nodo==NULL) {
                nodo = new tNodoArbolBin;
                nodo->info = item;                                 
                nodo->padre = padre;
                nElems++;
            }else{                                               
                int valorNodo = nodo->info;                       
                tNodoArbolBin* aux = nodo;
                if(item < valorNodo){                              
                    insertHelp(nodo->izq, item, aux);
                }
                else{                                             
                    insertHelp(nodo->der, item, aux);
                }                
            }
        }
        /*****
        *   void removeHelp
        *****
        *   Función que remueve nodos del árbol, tanto como este no tenga, tenga 1 o tenga 2 hijos.   
        *****
        *   Input:
                tNodoArbolBin: Un puntero hacía nodos. 
                tElemArbol: Elemento o información que se desea agregar al árbol   
        *****
        *   Return:

        *****/
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
                nElems--;
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
                nElems--;
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
        /*****
        *   int findHelp
        *****
        *   Busca un nodo en el ABB, retorna 0 en caso de no encontrar ninguno   .
        *****
        *   Input:
                tNodoArbolBin: Un puntero hacía nodos. 
                tElemArbol: Elemento o información que se desea agregar al árbol.
        *****
        *   Return:
                int, retorna la información que se encuentra en el nodo encontrado.

        *****/
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
        /*****
        *   void inOrdenHelp
        *****
        *   Recorre el ABB de forma in-orden, visitando el hijo izquierdo, procesando el nodo y visitando el hijo derecho.  
        *****
        *   Input:
                tNodoArbolBin: Un puntero hacía nodos. 
                tElemArbol: Elemento o información que se desea agregar al árbol
        *****
        *   Return:
                   
        *****/
        void inOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            inOrdenHelp (nodo->izq); 
            procesar(nodo->info);
            inOrdenHelp (nodo->der); 
        }
        /*****
        *   void preOrdenHelp
        *****
        *   Recorre el ABB de forma pre-orden   
        *****
        *
        *****
        *   
        *****/
        void preOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            procesar(nodo->info);
            preOrdenHelp (nodo->izq);
            preOrdenHelp (nodo->der);
        }
        /*****
        *   void postOrdenHelp   
        *****
        *   Recorre el ABB de forma post-orden  
        *****
        *
        *****
        *   
        *****/
        void postOrdenHelp (tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            postOrdenHelp (nodo->izq);
            postOrdenHelp (nodo->der);
            procesar(nodo->info);
        }
        /*****
        *   tNodoArbolBin* search
        *****
        *   
        *****
        *
        *****
        *   
        *****/
        tNodoArbolBin* search(tNodoArbolBin *nodo, tElemArbol item){
            if (nodo->info == item) return nodo; 
            if (item < nodo->info) {
                search(nodo->izq, item);
            }
            else {
                search(nodo->der, item);
            }
        }
        /*****
        *
        *****
        *   
        *****
        *
        *****
        *   
        *****/
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