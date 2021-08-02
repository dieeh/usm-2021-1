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

bool flag = false;

int h(tipoClave k){
    if (flag == false){
        double h = (M2*((e*k)%1));
        int x = h;
        return x;
    }
    else {
        double h = (M1*((e*k)%1));
        int x = h;
        return x;
    }
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
