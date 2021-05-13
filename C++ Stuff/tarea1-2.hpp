#include <iostream>
#include <cmath>

using namespace std;


class arr_extensible {
private:
    int k;
    int sizeB;
    unsigned long tamano;
    int* B;
    
    
public:
    arr_extensible(){
        k = 1;
        sizeB = pow(2, k);
        tamano = sizeB;
        B = new int[tamano];
    };

    arr_extensible(unsigned long n){
        tamano = n;
        B = new int[tamano];
    };

    arr_extensible(unsigned long n, int v){
        tamano = n;
        B = new int[tamano];
        for (unsigned long i = 0; i < n; i++) {
            B[i] = v;
            
        }
    };

    ~arr_extensible(){
        delete []B;
    };

    bool setValue(unsigned long i, int v){
        if ( (i < tamano)) {
            B[i] = v;
            return true;
        }
        if ( (i >= tamano) ) {
            return false;
        }
    };

    int getValue(unsigned long i){
        if ( (i < tamano)) {
            return B[i];
        }
        if ( (i >= tamano) ) {
            cerr << "Error de acceso al arreglo" << endl;
            exit(1);
        }
    };

    void append(int v){
        int p = tamano + 1;
        while ( ((unsigned long) sizeB) < p ) {
            sizeB = pow(2, k);
            k++;
        }
        int l = sizeB;
        int* Btemp = new int[l];
        for (unsigned long i = 0; i < tamano; i++) {
            Btemp[i] = B[i];
        }
        delete[] B;
        B = new int[tamano];
        for (unsigned long j = 0; j < tamano; j++) {
            B[j] = Btemp[j];
        }
        delete[] Btemp;
        B[tamano] = v;
    };

    void remove(){
        
    };

    unsigned long size(){
        return tamano;
    };

    void arrayCheck(){
        for (int i = 0; i < sizeB; i++) {
            cout << B[i] << endl;
        }
        
    };
};


