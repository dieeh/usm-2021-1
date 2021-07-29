// ola
#include <fstream>
#include <cmath>
#include <string>
#include <iostream>
#include "tarea3.hpp"

using namespace std;

int h(tipoClave k){
    string x = to_string(k);
    int dig = x.lenght;
    int mod = dig % 2;
    if (dig <= 6)
        return k;
    else {
        if (mod = 1) {dig += 1;}
        x = to_string(num);
        string y;
        int lugar = dig/2;
        for (int i = lugar - 3; i < lugar + 3; i++){
            int k = 0;
            y[k] = x[i];
            k++;
            }
        int h = stoi(y);
        return h;
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
