// ola
#include <fstream>
#include <cmath>
#include <string>
#include <iostream>
#include "tarea3.hpp"

using namespace std;
#define e 0.692363
#define M1 1000000
#define M2 100000

int hM1(tipoClave k){
    int h = (M1*((e*k)%1));
    return h;
}

int hM2(tipoClave k){
    int h = (M2*((e*k)%1));
    return h;
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

int p(tipoClave k, int i){
    return i*h2(k);
}

int main() {
    ranura HT[M];


    return 0;
}
