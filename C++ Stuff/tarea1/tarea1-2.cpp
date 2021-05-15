#include <iostream>
#include "tarea1-2.hpp"

using namespace std;

int main() {

    //Este main tiene el unico proposito de usarlo para testear la class,
    //y usar breakpoints para ver como funcionan los metodos

    char letra;
    cout << "Caso A, B o C: " << endl;
    cin >> letra;

    if (letra == 'A'){
        arr_extensible arreglo;
        arreglo.setValue(0, 3);
        arreglo.getValue(0);
        arreglo.append(67);
        arreglo.arrayCheck();
        arreglo.remove();
        arreglo.size();
        arreglo.~arr_extensible();
        
    }else if (letra == 'B'){
        arr_extensible arreglo(17);
        arreglo.setValue(0, 3);
        arreglo.getValue(0);
        arreglo.append(67);
        arreglo.arrayCheck();
        arreglo.remove();
        arreglo.size();
        arreglo.~arr_extensible();
    }else if (letra == 'C'){
        arr_extensible arreglo(10, 134);
        arreglo.setValue(0, 3);
        arreglo.getValue(0);
        arreglo.append(67);
        arreglo.arrayCheck();
        arreglo.remove();
        arreglo.size();
        arreglo.~arr_extensible();
    }

    return 0;
}