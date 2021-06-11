#include <iostream>

using namespace std;

struct tNodo {
    int contenido;
    tNodo* sig;
};

class list {
    private:
    tNodo* head;
    tNodo* curr;
    tNodo* tail;
    int lenght;
    public:

    list() {
        head=curr=tail= new tNodo;
        
    }
};

