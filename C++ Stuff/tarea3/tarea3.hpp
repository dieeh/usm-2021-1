#include <iostream>
#include <cmath>

using namespace std;
#define VACIA -1
#define e 0.692363  //variable arbitraria

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

struct ranuraP{
    tipoClave clave;
    producto info;
};

struct ranuraO{
    tipoClave clave;
    oferta info;
};


int h(tipoClave k, int Z){
    int w;
    long x = (Z-1)*(fmod((e*k),1));
    w = round(x);
    return w; 
}

int h2(int h){
    int total = 0;
    while(h > 0){
        int sumar = 0;
        sumar = h % 10;
        h = h/10;
        total += sumar;
    }
    if (total == 0) return 1;
    return total;
}

int p(int h, int t){
    return t*h2(h);
}

int hashInsertProducto(ranuraP HT[], int k, producto I, int X) {
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(inicio, i)) % X;
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

int hashInsertOferta(ranuraO HT[], int k, oferta I, int X) {
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(inicio, i)) % X;
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

producto hashSearchProducto(ranuraP HT[], tipoClave k, int X){
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
    }
    if (HT[pos].clave == k) return HT[pos].info;
    else {
        producto a;
        a.cod_producto = -1;
        return a;
    }
}

oferta hashSearchOferta(ranuraO HT[], tipoClave k, int X){
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
    }
    if (HT[pos].clave == k) return HT[pos].info;
    else {
        oferta a;
        a.cod_producto = -1;
        return a;
    }
}
