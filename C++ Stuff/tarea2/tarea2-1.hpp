#include <iostream>

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

typedef monomio tElemLista; 

struct tNodo{
    tElemLista info; 
    tNodo* sig;
};

class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;
        unsigned int listSize;
        unsigned int pos;
    public:
        tLista() {
            head = tail = curr = new tNodo;
            head->sig = NULL;
            listSize = 0;
            pos = 0;
        }

        ~tLista () {
            //clear();
            tNodo* elim;
            tNodo* aux = head;
            while (aux != NULL) {
                elim = aux;
                head = head->sig;
                aux = aux->sig;
                delete elim;
            }
        }

        /*****
        * void tLista::clear
        ******
        * Esta función reinicializa la lista, dejandola como vacía nuevamente y borrando toda la información que tenia guardada antes
        ******
        * Input:
        *   No tiene parametros, solo actualiza la estructura
        ******
        * Returns:
        *   void, no retorna nada, puesto que elimina todo
        *****/
        void clear() {
            tNodo* elim;
            tNodo* aux = head;
            while (aux != NULL) {
                elim = aux;
                head = head->sig;
                aux = aux->sig;
                delete elim;
            }
            listSize = 0;
            pos = 0;
        }
        
        /*****
        * int tLista::insert
        ******
        * Esta función inserta información a la lista en la posición que se encuentra el current
        ******
        * Input:
        *   tElemLista: El elemento o información que se desea agregar a la lista
        ******
        * Returns:
        *   int, retorna la posición en la lista donde se se inserto el elemento
        *****/
        int insert(tElemLista item) {
            tNodo* aux = curr->sig;
            curr->sig = new tNodo;
            curr->sig->info = item;
            curr->sig->sig = aux;   
            if (curr == tail) tail = curr->sig;
            listSize++;
            return pos;
        }

        /*****
        * int tLista::append
        ******
        * Esta función inserta información a la lista pero en la ultima posición, es decir, agrega elementos en la cola
        ******
        * Input:
        *   tElemLista: El elemento o información que se desea agregar a la lista
        ******
        * Returns:
        *   int, retorna la posición en la lista donde se se inserto el elemento
        *****/
        int append(tElemLista item) {
            while (curr != tail) {
                curr = curr->sig;
                pos++;
            }
            curr->sig = new tNodo;
            curr->sig->info = item;
            curr->sig->sig = NULL;
            tail = curr->sig;
            listSize++;
            return pos;   
        }

        /*****
        * tElemLista tLista::erase
        ******
        * Esta función borra el elemento que se encuentra en la posición current
        ******
        * Input:
        *   No tiene parametros, solo actualiza la estructura
        ******
        * Returns:
        *   tElemLista, retorna la información del elemento eliminado
        *****/
        tElemLista erase() {
            tElemLista a;
            if (curr == tail) {
                tNodo* aux = NULL;
                a = curr->info;
                delete curr->sig;
                curr->sig = aux;
                return a;
            }
            else {
                tNodo* aux = curr->sig;
                delete curr->sig;
                curr->sig = aux;
                return a;
            }
        }

        /*****
        * void tLista::moveToStart
        ******
        * Esta función lleva el current al inicio de la lista, es decir, a la cabeza.
        ******
        * Input:
        *   No tiene parametros, solo cambia la posición de nuestro indicador
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo mueve el indicador 
        *****/
        void moveToStart() {
            curr = head; 
            pos = 0; 
        }

        /*****
        * void tLista::moveToEnd
        ******
        * Esta función lleva el current al final de la lista, es decir, a la cola.
        ******
        * Input:
        *   No tiene parametros, solo cambia la posición de nuestro indicador
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo mueve el indicador 
        *****/
        void moveToEnd() {
            curr = tail;
            pos = listSize -1;
        }

        /*****
        * void tLista::next
        ******
        * Esta función lleva el current al siguiente elemento en la lista, nuestro indicador apunta al siguiente.
        ******
        * Input:
        *   No tiene parametros, solo cambia la posición de nuestro indicador
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo mueve el indicador 
        *****/
        void next() { 
            if (curr != tail) { 
                curr = curr->sig; 
                pos++; 
            } 
        }

        /*****
        * void tLista::prev
        ******
        * Esta función lleva el current al elemento anterior en la lista, nuestro indicador apunta uno atras.
        ******
        * Input:
        *   No tiene parametros, solo cambia la posición de nuestro indicador
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo mueve el indicador 
        *****/
        void prev() {
            tNodo* temp;
            if (curr == head) return;
            temp = head;
            while (temp->sig != curr) temp = temp->sig;
            curr = temp;
            pos--;
        }

        /*****
        * int tLista::lenght
        ******
        * Esta función nos entrega el total de elementos que hay en la lista.
        ******
        * Input:
        *   No tiene parametros, solo nos entrega información de la lista
        ******
        * Returns:
        *   int, retorna el número de elementos de la lista
        *****/
        int lenght() {
            return listSize;
        }

        /*****
        * int tLista::currPos
        ******
        * Esta función nos indica en que posición se encuentra nuestro indicador
        ******
        * Input:
        *   No tiene parametros, solo nos entrega información de la lista
        ******
        * Returns:
        *   int, retorna la posición del current
        *****/
        int currPos() {
            return pos;
        }

        /*****
        * void tLista::moveToPos
        ******
        * Esta función lleva el current a una posición requerida
        ******
        * Input:
        *   unsigned int posicion: La posición a la que queremos desplazar el indicador
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo mueve el indicador 
        *****/
        void moveToPos(unsigned int posicion) {
            unsigned int i;
            if ((posicion < 0) || (posicion > listSize)) return;
            curr = head;
            pos = 0;
            for (i = 0; i < posicion; i++) {
                curr = curr->sig;
                pos++;
            }
        }

        /*****
        * tElemLista tLista::getValue
        ******
        * Esta función nos entrega la información que esta apuntando el indicador actual
        ******
        * Input:
        *   No tiene parametros, solo nos entrega información de la lista
        ******
        * Returns:
        *   tElemLista, retorna la información del elemento actual
        *****/
        tElemLista getValue() {
            tElemLista a;
            a = curr->sig->info;
            return a;
        }    

        /*****
        * void tLista::sort
        ******
        * Esta función ordena los elementos de la lista, en este caso, según su exponente de mayor a menor
        ******
        * Input:
        *   No tiene parametros, solo actualiza la estructura
        ******
        * Returns:
        *   void, no retorna nada, puesto que solo ordena los elementos de la lista
        *****/
        void sort(){
            tNodo *aux, *aux2;
            tElemLista aux3;
            for (int i = 0; i < lenght(); i++) {
                for (moveToStart() ; currPos() < lenght(); next()) {
                    aux = curr; //actual
                    next();
                    aux2 = curr; //siguiente
                    prev();
                    if (aux->info.exponente < aux2->info.exponente){
                        aux3 = aux->info;
                        aux->info = aux2->info;
                        aux2->info = aux3;
                    }
                }
            }
            
        }    
};

class polinomio {
    private:
        tLista polinomioTotal;
        int cantidad;

    public:
        polinomio(){
            cantidad = 0;
            tLista polinomioTotal;
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
            polinomioTotal.append(a);
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
            for (polinomioTotal.moveToStart() ; polinomioTotal.currPos() < cantidad; polinomioTotal.next()) {
                if (polinomioTotal.getValue().exponente == exponente){
                    return polinomioTotal.getValue().coeficiente;
                }
            }
            return 0;
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
            int aux4;
            unsigned int aux3 = polinomioTotal.getValue().exponente;
            polinomioTotal.sort();
            for (polinomioTotal.moveToStart() ; aux3 >= 0; polinomioTotal.next()){
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

