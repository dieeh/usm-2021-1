#include <iostream>

//alo alo alo

using namespace std;

typedef int tElemLista; //Definir dependiendo de la tarea

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
            tNodo* elim;
            tNodo* aux = head;
            while (aux != NULL) {
                elim = aux;
                head = head->sig;
                aux = aux->sig;
                delete elim;
            }
        }

        void clear() {
            tNodo* elim;
            tNodo* aux = head;
            while (aux != NULL) {
                elim = aux;
                head = head->sig;
                aux = aux->sig;
                delete elim;
            }
        }
        int insert(tElemLista item) {
            tNodo* aux = curr->sig;
            curr->sig = new tNodo;
            curr->sig->info = item;
            curr->sig->sig = aux;   
            if (curr == tail) tail = curr->sig;
            listSize++;
            return pos;
            
        }
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
        void moveToStart() {
            curr = head; 
            pos = 0; 
        }
        void moveToEnd() {
            curr = tail;
            pos = listSize -1;
        }
        void next() { 
            if (curr != tail) { 
                curr = curr->sig; 
                pos++; 
            } 
        }
        void prev() {
            tNodo* temp;
            if (curr == head) return;
            temp = head;
            while (temp->sig != curr) temp = temp->sig;
            curr = temp;
            pos--;
        }
        int lenght() {
            return listSize;
        }
        int currPos() {
            return pos;
        }
        void moveToPos(unsigned int posicion) {
            unsigned int i;
            if (posicion < 0 || posicion > listSize) return;
            curr = head;
            pos = 0;
            for (i = 0; i < posicion; i++) {
                curr = curr->sig;
                pos++;
                }
        }
        tElemLista getValue() {
            tElemLista a;
            a = curr->info;
            return a;
        }        
};