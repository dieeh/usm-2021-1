#include <iostream>

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

typedef monomio tElemArbol; //Definir dependiendo de la tarea

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
        *   void tABB::clearHelp
        *****
        *   Función recursiva que elimina todos los nodos del ABB, dejandolo vacío 
        *****
        *   Input:
        *       tNodoArbolBin: Puntero a los nodos perteneciente al árbol
        *****
        *   Returns:
        *       void, No retorna ya que borra todos los subarboles y se elimina a si mismo, dejandolo vacío
        *****/
        void clearHelp(tNodoArbolBin *nodo) {
            if (nodo == NULL) return;
            clearHelp(nodo->izq); 
            clearHelp(nodo->der); 
            delete nodo; 
        }

        /*****
        *   void tABB::insertHelp
        *****
        *   Función que inserta nodos en el árbol, o crea el árbol e insertar nodos
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *       tElemArbol: Elemento o información que se desea agregar al árbol
        *       tNodoArbolBin: Puntero hacía el nodo padre (raíz)
        *****
        *   Return: 
        *      No retorna nada, ya que solo agrega nodos al árbol
        *****/
        void insertHelp(tNodoArbolBin *nodo, tElemArbol item, tNodoArbolBin *padre){
            if(nodo==NULL) {
                nodo = new tNodoArbolBin;
                nodo->info = item;                                 
                nodo->padre = padre;
                nElems++;
            }else{                                               
                int valorNodo = nodo->info.exponente;                       
                tNodoArbolBin* aux = nodo;
                if(item.exponente < valorNodo){                              
                    insertHelp(nodo->izq, item, aux);
                }
                else{                                             
                    insertHelp(nodo->der, item, aux);
                }                
            }
        }

        /*****
        *   void tABB::removeHelp
        *****
        *   Función que remueve nodos del árbol, tanto como este no tenga, tenga 1 o tenga 2 hijos.   
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *       tElemArbol: Elemento o información que se desea agregar al árbol   
        *****
        *   Return:
        *       No retorna, ya que solo elimina nodos, subarboles o árboles
        *****/
        void removeHelp(tNodoArbolBin *nodo, tElemArbol item) {
            int caso;
            if(find(item.exponente) == 0) return;                                                                                
            tNodoArbolBin* aux = searchHelp(nodo, item.exponente);
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
                    if(find(item.exponente - k)) sucesorAntecesor = true;
                    else{
                        k++;
                    }
                }
                tElemArbol aux2;
                aux2.exponente = item.exponente - k;
                tNodoArbolBin* aux3 = searchHelp(nodo, aux2.exponente);
                aux->info = aux3->info;
                removeHelp(aux3, aux2);
                break;
            }
        }

        /*****
        *   int tABB::findHelp
        *****
        *   Busca un nodo en el ABB, retorna 0 en caso de no encontrar ninguno   .
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *       tElemArbol: Elemento o información que se desea agregar al árbol.
        *****
        *   Return:
        *       int, retorna la información que se encuentra en el nodo encontrado.
        * 
        *****/
        int findHelp(tNodoArbolBin *nodo, unsigned int exponente) {
            if (nodo == NULL) return 0;                                        
            if (nodo->info.exponente == exponente) return 1;                                  
            if (exponente < nodo->info.exponente) {
                return findHelp(nodo->izq, exponente);
            }
            else {
                return findHelp(nodo->der, exponente);
            }
        }

        /*****
        *   void tABB::inOrdenHelp
        *****
        *   Recorre el ABB de forma in-orden, visitando el hijo izquierdo, visita el nodo y visitando el hijo derecho.  
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *****
        *   Return:
        *       No retorna, solo recorre el árbol
        *          
        *****/
        void inOrdenHelp (tNodoArbolBin *nodo, tElemArbol* arreglo, int &cantidad) {
            if (nodo == NULL) return;
            inOrdenHelp (nodo->izq, arreglo, cantidad); 
            procesar(nodo->info, arreglo, cantidad);
            inOrdenHelp (nodo->der, arreglo, cantidad); 
        }

        /*****
        *   void tABB::preOrdenHelp
        *****
        *   Recorre el ABB de forma pre-orden, visitando el nodo actual, visita el hijo izquierdo y visita el hijo derecho   
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *****
        *   Return:
        *       No retorna, solo recorre el árbol
        *****/
        void preOrdenHelp (tNodoArbolBin *nodo, tElemArbol* arreglo, int &cantidad) {
            if (nodo == NULL) return;
            procesar(nodo->info, arreglo, cantidad);
            preOrdenHelp (nodo->izq, arreglo, cantidad);
            preOrdenHelp (nodo->der, arreglo, cantidad);
        }

        /*****
        *   void tABB::postOrdenHelp   
        *****
        *   Recorre el ABB de forma post-orden, visita el hijo izquierdo, visita el hijo derecho y visita el nodo actual  
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos. 
        *****
        *   Return:
        *       No retorna, solo recorre el árbol
        *****/
        void postOrdenHelp (tNodoArbolBin *nodo, tElemArbol* arreglo, int &cantidad) {
            if (nodo == NULL) return;
            postOrdenHelp (nodo->izq, arreglo, cantidad);
            postOrdenHelp (nodo->der, arreglo, cantidad);
            procesar(nodo->info, arreglo, cantidad);
        }

        /*****
        *   tNodoArbolBin* tABB::searchHelp
        *****
        *   Esta función busca un elemento en el arbol 
        *   y retorna el nodo al que pertence
        *****
        *   Input:
        *       tNodoArbolBin: Un puntero hacía nodos
        *       tElemArbol: Elemento o información que se desea agregar al árbol
        *****
        *   Return:
        *       Retorna un puntero hacía el nodo encontrado
        *****/
        tNodoArbolBin* searchHelp(tNodoArbolBin *nodo, unsigned int exponente){
            if (nodo->info.exponente == exponente) return nodo; 
            if (exponente < nodo->info.exponente) {
                searchHelp(nodo->izq, exponente);
            }
            else {
                searchHelp(nodo->der, exponente);
            }
        }

        /*****
        *   void tABB::procesar
        *****
        *   Esta función no se utiliza, por ahora.
        *****
        *   Input:
        *       tElemArbol: Elemento o información que se desea agregar al árbol
        *****
        *   Return:
        *       No retorna nada, por ahora.
        *****/
        void procesar(tElemArbol item, tElemArbol* arreglo, int& cantidad) {
            arreglo[cantidad] = item;
            cantidad++;
        }

    public:
        tABB() {
            raiz = NULL;
            nElems = 0; 
        }

        ~tABB() {
            clearHelp(raiz);
        }

        /*****
        *   void tABB::clear
        *****
        *   Función que llama a la función clearHelp
        *****
        *   Input:
        *       No posee input
        *****
        *   Returns:
        *       No retorna ya que borra todos los subarboles y se elimina a si mismo, dejandolo vacío
        *****/
        void clear() {
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }

        /*****
        *   void tABB::insert
        *****
        *   Función que llama a la función insertHelp
        *****
        *   Input:
        *       tElemArbol: Elemento o información que se desea agregar al árbol        
        *****
        *   Returns:
        *       No retorna
        *****/
        void insert(tElemArbol item) {
            insertHelp(raiz, item, NULL); 
        }

        /*****
        *   void tABB::remove
        *****
        *   Función que llama a la función removeHelp
        *****
        *   Input:
        *       tElemArbol: Elemento o información que se desea agregar al árbol        
        *****
        *   Returns:
        *       No retorna
        *****/
        void remove(tElemArbol item){
            removeHelp(raiz, item);
        }

        /*****
        *   int tABB::find
        *****
        *   Función que llama a la función findtHelp
        *****
        *   Input:
        *       tElemArbol: Elemento o información que se desea agregar al árbol        
        *****
        *   Returns:
        *       int, retorna la información que se encuontró en findHelp
        *****/
        int find(unsigned int exponente) {
            return findHelp(raiz, exponente);
        }

        /*****
        *   tNodoArbolBin* tABB::searchHelp
        *****
        *   Esta función busca un elemento en el arbol 
        *   y retorna el nodo al que pertence
        *****
        *   Input:
        *       unsigned int item: Elemento que se desea buscar en el árbol
        *****
        *   Return:
        *       Retorna un puntero hacía el nodo encontrado
        *****/
        tNodoArbolBin* search(unsigned int item){
            return searchHelp(raiz, item);
        }

        /*****
        *   int tABB::size
        *****
        *   Función que retorna la cantidad de elementos pertenecientes al árbol
        *****
        *   Input:
        *       No posee inputs        
        *****
        *   Returns:
        *       int, Retorna la cantidad de elementos que hay en el ABB
        *****/
        int size() {
            return nElems;
        }

        /*****
        *   void tABB::inOrden
        *****
        *   Función que llama a la función inOrdenHelp
        *****
        *   Input:
        *       No posee inputs      
        *****
        *   Returns:
        *       No retorna, solo recorre el ABB de formar in-orden
        *****/
        void inOrden(tElemArbol* arreglo, int& cantidad) {
            inOrdenHelp (raiz, arreglo, cantidad);
        }

        /*****
        *   void tABB::preOrden
        *****
        *   Función que llama a la función preOrdenHelp
        *****
        *   Input:
        *       No posee inputs      
        *****
        *   Returns:
        *       No retorna, solo recorre el ABB de formar pre-orden
        *****/
        void preOrden(tElemArbol* arreglo, int &cantidad) {
            preOrdenHelp (raiz, arreglo, cantidad);
        }
        
        /*****
        *   void tABB::postOrden
        *****
        *   Función que llama a la función postOrdenHelp
        *****
        *   Input:
        *       No posee inputs      
        *****
        *   Returns:
        *       No retorna, solo recorre el ABB de formar post-orden
        *****/
        void postOrden(tElemArbol* arreglo, int &cantidad) {
            postOrdenHelp (raiz, arreglo, cantidad);
        }
};

class polinomio {
    private:
        tABB polinomioTotal;
        int cantidad;

    public:
        polinomio(){
            cantidad = 0;
            tABB polinomioTotal;
        }

        ~polinomio(){
            polinomioTotal.clear();
        }

        /*****
        * void polinomio::appendMon
        ******
        * Esta función va agregando monomios a una lista, a cada posición de la lista le asigna 2 campos, un exponente y un coeficiente, incrementando el tamaño de la lista
        ******
        * Input:
        *   int coef: Es el campo que indica el coeficiente del monomio, es información relevante que se guarda en la lista
        *   unsigned int exp: Es el campo que indica el exponente del monomio, es información relevante que se guarda en la lista
        ******
        * Returns:
        *   void, no retorna nada, pero agrega información a la estructura
        *****/
        void appendMon(int coef, unsigned int exp){
            monomio a;
            a.exponente = exp;
            a.coeficiente = coef;
            polinomioTotal.insert(a);
            cantidad++;
        }

        /*****
        * void polinomio::coeficiente 
        ******
        * Esta función busca entre los monomios guardados en una lista, alguno que tenga un exponente dado
        ******
        * Input:
        *   unsigned int exponente: Es el exponente del monomio que se requiere encontrar
        ******
        * Returns:
        *   int, retorna el coeficiente del monomio encontrado
        *****/
        int coeficiente(unsigned int exponente){
            if (polinomioTotal.find(exponente) != 0){
                return polinomioTotal.search(exponente)->info.coeficiente;
            }else{
                return 0;
            }
        }

        /*****
        * float polinomio::evaluar
        ******
        * Esta función evalua un número en el polinomio guardado en una lista
        ******
        * Input:
        *   float x: Es el valor de x que se desea evaluar
        ******
        * Returns:
        *   float, retorna el valor final despúes de evaluar en toda la lista o polinomio
        *****/
        float evaluar(float x){
            float resultado = 0, aux;
            tElemArbol A[polinomioTotal.size()];
            int aux4, cantidad = 0;
            polinomioTotal.inOrden(A, cantidad);

            unsigned int aux3 = A[cantidad].exponente;
            for (unsigned int i = aux3; aux3 >= 0; i--) {
                aux4 = coeficiente(aux3);
                aux = aux4 + resultado;
                if (aux3 == 0){
                    resultado = aux;
                    return resultado;
                }else{
                    resultado = aux * x;
                    aux3--;
                }
            }
        }
};


