#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class arr_extensible {
private:
    int k = 0;
    unsigned long tamaño;
    int* Arr = new int[tamaño];
    
public:
    arr_extensible();

    arr_extensible(unsigned long n){
        tamaño = n;
    }

    arr_extensible(unsigned long n, int v){
        tamaño = n;
        for (int i = 0; i < n; i++) {
            Arr[i] = v;
            
        }
    }

    ~arr_extensible(){
        delete[] Arr;
    }

    bool setValue(unsigned long i, int v){
        if ( (0<=i < tamaño)) {
            Arr[i] = v;
            return true;
        }
        if ( (i >= tamaño) ) {
            return false;
        }
    }

    int getValue(unsigned long i){
        if ( (0<=i < tamaño)) {
            return Arr[i];
        }
        if ( (i >= tamaño) ) {
            cerr << "Error de acceso al arreglo" << endl;
            exit(1);
        }
    }

    void append(int v){
        k=0;
        while ( ((unsigned long) pow(2,k)) < tamaño ) {
            k++;
        }
        int l = pow(2,k);
        int* B = new int[l];
            for (int i = 0; i < tamaño; i++) {
                B[i] = Arr[i];
            }
            delete [] Arr;  
            B[tamaño] = v;
    
        if (((unsigned long) pow(2,k)) == tamaño){
            l = pow(2,k+1);
            int* Btemp = new int[l];
            for (int i = 0; i < l; i++) {
                Btemp[i] = B[i];
            }
            delete[] B;
            Btemp[tamaño] = v;
            return Btemp;
        }  
        return B;
    }

    void remove(){
        k=0;
        while ( ((unsigned long) pow(2,k)) <= tamaño ) {
            k++;
        }
        k--;
        int l = pow(2,k);
        int* B = new int[l];
            for (int i = 0; i < l; i++) {
                B[i] = Arr[i];
            }
    }

    unsigned long size(){
        
    }
};