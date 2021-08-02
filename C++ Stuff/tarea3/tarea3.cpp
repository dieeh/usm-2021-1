// ola
#include <fstream>
#include <cmath>
#include <string>
#include <iostream>
#include "tarea3.hpp"

using namespace std;
#define e 0.692363
#define M 1000000
#define N 100000

bool flag = false;
int h(tipoClave k, int Z){
        double h = (Z*((e*k)%1));
        int x = h;
        return x;
}

int h2(int h){
    int cod = h;
    int total = 0;
    while(cod > 0){
        int sumar = 0;
        sumar = cod % 10;
        total += sumar;
    }
    return total;
}

int p(tipoClave k, int t){
    return t*h2(k);
}

int main() {
    int A,B,C,D;
    fstream file1;
    string ruta = "productos.dat";
    file1.open(ruta, ios::in|ios::binary);
    if (!file1.is_open()) {
        cerr << "Error al abrir el archivo '" << ruta << "'" << endl;
        exit(1);
    }
    file1.read((char*)&A, sizeof(int));
    A= (A/0.7);
    typedef producto tipoInfo;
    ranura* HT[A];
    producto i;
    for (int j = 0; j < A; j++){
        file1.read((char*)&i, sizeof(producto));
        hashInsert(HT[j], i.cod_producto, i, A);
    }
    file1.close();
    
    fstream file2;
    string ruta2 = "ofertas.dat";
    file2.open(ruta2, ios::in|ios::binary);
    if (!file2.is_open()) {
        cerr << "Error al abrir el archivo '" << ruta2 << "'" << endl;
        exit(1);
    }
    file1.read((char*)&B, sizeof(int));
    B = (B/0.7);
    typedef oferta tipoInfo;
    ranura* HT2[B];
    oferta g;
    for (int j = 0; j < A; j++){
        file2.read((char*)&g, sizeof(oferta));
        hashInsert(HT2[j], i.cod_producto, i, B);
    }
    file2.close();
    
    return 0;
}
