typedef Punto tElemLista;

struct tNodo{
    tElemLista info;
    tNodo* sig;
};

class Punto{
private:
    float x;
    float y;
public:
    Punto(){
        x = 0;
        y = 0;
    }
    
    ~Punto(){}

    float obtenerX(){
        return x;
    }

    float obtenerY(){
        return y;
    }
};


class tLista{
private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
public:
    tLista(){}

    ~tLista(){}

    void clear(){}

    int insert(tElemLista){}

    int erase(){}

    void moveToStart(){}

    void moveToEnd(){}

    void prev(){}

    void next(){}

    void moveToPos(){}


    
};