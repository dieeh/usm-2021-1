typedef int tVertice;

struct tGrafo{
    
};

void initGraph(tGrafo *G, int n){};

void destroyGraph(tGrafo *G){};

int nVertex(tGrafo *G){};

int nEdges(tGrafo *G){};

tVertice first(tGrafo *G, tVertice v){};

tVertice next(tGrafo *G, tVertice v, tVertice w){};

void setEdge(tGrafo *G, tVertice v1, tVertice v2, int peso){};

void deleteEdge(tGrafo *G, tVertice v1, tVertice v2){};

int isEdge(tGrafo *G, tVertice v1, tVertice v2){};

int weight(tGrafo *G, tVertice v1, tVertice v2){};

int getMark(tGrafo *G, tVertice v){};

void setMark(tGrafo *G, tVertice v, int marca){};