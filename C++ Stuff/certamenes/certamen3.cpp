#include "tda_c3.hpp"
#include <iostream>

using namespace std;

//usando lista de adyacencia
struct contador{
    tVertice v;
    int grado_s = 0;
    int grado_e = 0;
};

tVertice* Saturados(tGrafo *G, int &size){
    int cant_vert = nVertex(G), q=0;
    tVertice arr[cant_vert];
    tVertice aux, auxmenor= 0;
    contador cont[cant_vert];
    for (aux = 0; aux < cant_vert; aux++) {
        if(G[aux]->sig != NULL){
            cont[aux].grado_s +=1;
            cont[G[aux]->sig].grado_e +=1;
        }
    }
    for (int i = 0; i < cant_vert; i++){
        if (cont[i].grado_s - cont[i].grado_e < 0){
            arr[q] = cont[i].v;
            q++;
        }
    }
    tVertice aux2[q];
    for (int j = 0; j < q; j++){
        arr[j] = aux2[j];
    }
    return aux2;
}


int main(){
    return 0;
}