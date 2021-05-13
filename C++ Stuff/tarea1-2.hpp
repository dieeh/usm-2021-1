#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class arr_extensible {
private:
    int k;
    unsigned long tamaño;
    int* B = new int[tamaño];
    
    
public:
    arr_extensible();

    arr_extensible(unsigned long n){
        tamaño = n;
    };

    arr_extensible(unsigned long n, int v){
        tamaño = n;
        for (int i = 0; i < n; i++) {
            B[i] = v;
            
        }
    };

    ~arr_extensible(){
        delete[] B;
    };

    bool setValue(unsigned long i, int v){
        if ( (0<=i < tamaño)) {
            B[i] = v;
            return true;
        }
        if ( (i >= tamaño) ) {
            return false;
        }
    };

    int getValue(unsigned long i){
        if ( (0<=i < tamaño)) {
            return B[i];
        }
        if ( (i >= tamaño) ) {
            cerr << "Error de acceso al arreglo" << endl;
            exit(1);
        }
    };

    void append(int v){
        k=0;
        while ( ((unsigned long) pow(2,k)) < tamaño ) {
            k++;
        }
        int l = pow(2,k);
        int* Btemp = new int[l];
        for (int i = 0; i < tamaño; i++) {
            Btemp[i] = B[i];
        }
        delete[] B;
        int* B = new int[tamaño];
        for (int j = 0; j < tamaño; j++) {
            B[j] = Btemp[j];
        }
        delete[] Btemp;
        
    };

    void remove(){
        
    };

    unsigned long size(){
        
    };
};


