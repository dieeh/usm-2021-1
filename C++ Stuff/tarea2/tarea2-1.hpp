#include <iostream>

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

typedef monomio tElemLista; //Definir dependiendo de la tarea

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
            if ((posicion < 0) || (posicion > listSize)) return;
            curr = head;
            pos = 0;
            for (i = 0; i < posicion; i++) {
                curr = curr->sig;
                pos++;
            }
        }

        tElemLista getValue() {
            tElemLista a;
            a = curr->sig->info;
            return a;
        }    

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

        void appendMon(int coef, unsigned int exp){
            monomio a;
            a.exponente = exp;
            a.coeficiente = coef;
            polinomioTotal.append(a);
            cantidad++;
        }

        int coeficiente(unsigned int exponente){
            for (polinomioTotal.moveToStart() ; polinomioTotal.currPos() < cantidad; polinomioTotal.next()) {
                if (polinomioTotal.getValue().exponente == exponente){
                    return polinomioTotal.getValue().coeficiente;
                }
            }
            return 0;
        }
            
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

        void insertMon(int coef, unsigned int exp){
            monomio a;
            a.exponente = exp;
            a.coeficiente = coef;
            polinomioTotal.insert(a);
            cantidad++;
        }
};

