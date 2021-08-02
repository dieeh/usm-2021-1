#include <iostream>

using namespace std;
#define M 1000000
#define VACIA -1

typedef int tipoClave;

struct tipoInfo{
    int cod_producto;
    char nombre_producto[31];
    int precio;
}producto;

struct tipoInfo{
    int cod_producto;
    int cantidad_descuento;
    int descuento;
    int productos_equivalentes[10];
}oferta;

struct ranura{
    tipoClave clave;
    tipoInfo info;
};

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % M;
    }
    if (HT[pos].clave == k) {
        return 0;
    }
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1;
    }
}

tipoClave hashSearch(ranura HT[], tipoClave k){
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % M;
    }
    if (HT[pos].clave == k) return HT[pos].clave;
    else {
        return VACIA;
    }
}
