#include <iostream>

using namespace std;
#define M 1000000
#define N 100000
#define VACIA -1

typedef int tipoClave;

struct producto{
    int cod_producto;
    char nombre_producto[31];
    int precio;
};


struct oferta{
    int cod_producto;
    int cantidad_descuento;
    int descuento;
    int productos_equivalentes[10];
};

typedef producto tipoInfo;
typedef oferta tipoInfo;

struct ranura{
    tipoClave clave;
    tipoInfo info;
};

int h(tipoClave k, int Z){
    int x = (((int)(e*k)%1)*Z);
    return x;
}

int h2(int h){
    int total = 0;
    while(h > 0){
        int sumar = 0;
        sumar = h % 10;
        total += sumar;
    }
    return total;
}

int p(tipoClave k, int t){
    return t*h2(k);
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I, int X) {
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
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

tipoInfo hashSearch(ranura HT[], tipoClave k, int X){
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
    }
    if (HT[pos].clave == k) return HT[pos].info;
    else {
        tipoInfo a;
        a.cod_producto = -1;
        return a;
    }
}
