#include <iostream>
#include <cmath>

using namespace std;


class arr_extensible {
private:
    int k;
    unsigned int sizeB;
    unsigned long tamano;
    int* B;
    
    
public:
    arr_extensible(){
        k = 1;
        sizeB = pow(2, k);
        tamano = sizeB;
        B = new int[tamano];
    }

    arr_extensible(unsigned long n){
        tamano = n;
        sizeB = tamano;
        B = new int[tamano];

        k = 1;
        while ( (pow(2,k) < tamano) ) {
            k++;
        }
        
    }

    arr_extensible(unsigned long n, int v){
        tamano = n;
        sizeB = tamano;
        B = new int[tamano];
        for (unsigned long i = 0; i < n; i++) {
            B[i] = v;
        }
        k = 1;
        while ( (pow(2,k) < tamano) ) {
            k++;
        }
    }

    ~arr_extensible(){
        delete []B;
    }

    bool setValue(unsigned long i, int v){
        if ((i < tamano)) {
            B[i] = v;
            return true;
        }
        if ( (i >= tamano) ) {
            return false;
        }
    }

    int getValue(unsigned long i){
        if ((i < tamano)) {
            return B[i];
        }
        if ( (i >= tamano) ) {
            cerr << "Error de acceso al arreglo" << endl;
            exit(1);
        }
    }

    void append(int v){
        int p = tamano + 1;
        while ( ((unsigned long) sizeB) < p ) {
            k++;
            sizeB = pow(2, k);
        }
        int* Btemp = new int[sizeB];
        for (unsigned long i = 0; i < tamano; i++) {
            Btemp[i] = B[i];
        }
        delete[] B;
        B = new int[sizeB];
        for (unsigned long j = 0; j < sizeB; j++) {
            B[j] = Btemp[j];
        }
        delete[] Btemp;
        B[tamano] = v;
        tamano++;
    }

    void remove(){
        if ( (tamano - 1) <= pow(2, k-1) ) {
            k--;
            sizeB = pow(2, k);
            int* Btemp = new int[sizeB];
            for (unsigned long i = 0; i < (tamano - 1); i++) {
                Btemp[i] = B[i];
            }
            delete[] B;
            B = new int[sizeB];
            for (unsigned long j = 0; j < sizeB; j++) {
                B[j] = Btemp[j];
            }
            delete[] Btemp;
            tamano--;
        }else{
            tamano--;
        }
    }

    unsigned long size(){
        return tamano;
    }

    /*****
     * Funcion de testeo de array, no considerar.
    void arrayCheck(){
        for (int i = 0; i < sizeB; i++) {
            cout << "Arreglo B en la posicion " << i << ":" << B[i] << endl;
        }
        cout << sizeB << endl;
    }
    *****/
};
