#include <iostream>
#include "tarea1-2.hpp"

using namespace std;

int main() {
    arr_extensible arreglo;
    arreglo.setValue(0, 23);
    arreglo.append(32);
    cout << "getValue =" << arreglo.getValue(2) << endl;
    arreglo.arrayCheck();
    
    

    return 0;
}