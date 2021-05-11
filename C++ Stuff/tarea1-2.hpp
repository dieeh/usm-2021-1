#include <cmath>

class arr_extensible {
private:
    int k;
    unsigned long tamaño;
    int* Arr = new int[tamaño];
    
    
public:
    arr_extensible();

    arr_extensible(unsigned long n){
        tamaño = n;
    };

    arr_extensible(unsigned long n, int v){
        tamaño = n;
        for (int i = 0; i < n; i++) {
            Arr[i] = v;
            
        }
    };

    ~arr_extensible(){
        delete[] Arr;
    };

    bool setValue(unsigned long i, int v){
        if ( (0<=i < tamaño)) {
            Arr[i] = v;
            return true;
        }
        if ( (i >= tamaño) ) {
            return false;
        }
    };

    int getValue(unsigned long i){
        if ( (0<=i < tamaño)) {
            return Arr[i];
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
            Btemp[i] = Arr[i];
        }
        delete[] Arr;
        int* Arr = new int[tamaño];
        for (int j = 0; j < tamaño; j++)
        {
            Arr[j] = Btemp[j];
        }
        delete[] Btemp;
        
    };

    void remove(){
        
    };

    unsigned long size(){
        
    };
};


