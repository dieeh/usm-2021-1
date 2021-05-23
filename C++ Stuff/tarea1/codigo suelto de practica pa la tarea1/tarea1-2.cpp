#include <iostream>
#include "tarea1-2.hpp"

using namespace std;

int main() {
    arr_extensible arreglo(9);
    
    arreglo.remove();

    arreglo.getValue(4);
    arreglo.arrayCheck();


    return 0;
}