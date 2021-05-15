#include <iostream>
#include "tarea1-2.hpp"

using namespace std;

int main() {
    arr_extensible arreglo;
    arreglo.setValue(0, 3);
    arreglo.getValue(0);
    arreglo.append(67);
    arreglo.remove();
    arreglo.size();
    arreglo.~arr_extensible();

    arr_extensible arreglo(17);
    arreglo.setValue(0, 3);
    arreglo.getValue(0);
    arreglo.append(67);
    arreglo.remove();
    arreglo.size();
    arreglo.~arr_extensible();

    arr_extensible arreglo(10, 134);
    arreglo.setValue(0, 3);
    arreglo.getValue(0);
    arreglo.append(67);
    arreglo.remove();
    arreglo.size();
    arreglo.~arr_extensible();

    return 0;
}