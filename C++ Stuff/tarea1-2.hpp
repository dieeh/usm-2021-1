class arr_extensible {
private:
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

    void append(int v);

    void remove();

    unsigned long size();
};


