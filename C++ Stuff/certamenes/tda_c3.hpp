typedef int tVertice;

struct parVertices{
    tVertice vertice1;
    tVertice vertice2;
};

struct tGrafo{
    tVertice* V;
    parVertices* A;
};

void initGraph(tGrafo *G, int n){}; //inicializa el grafo

void destroyGraph(tGrafo *G){}; //libera la memoria usada por el grafo

int nVertex(tGrafo *G){}; //retorna numero de vertices

int nEdges(tGrafo *G){}; //retorna numero de arcos

tVertice first(tGrafo *G, tVertice v){};  //devuelve el primer vecino del vertice v

tVertice next(tGrafo *G, tVertice v, tVertice w){}; //devuelve el menor vecino menor que w

void setEdge(tGrafo *G, tVertice v1, tVertice v2, int peso){}; //agrega un nuevo arco

void deleteEdge(tGrafo *G, tVertice v1, tVertice v2){}; //borra un arco

int isEdge(tGrafo *G, tVertice v1, tVertice v2){}; //indica si existe un arco entre los vertices

int weight(tGrafo *G, tVertice v1, tVertice v2){}; //devuelve el peso del arco entre v1 y v2

int getMark(tGrafo *G, tVertice v){}; //obtiene la marca asignada

void setMark(tGrafo *G, tVertice v, int marca){}; //marca un vertice