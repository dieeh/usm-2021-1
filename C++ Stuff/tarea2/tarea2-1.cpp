#include <iostream>
#include <string>
#include <fstream>
#include "tarea2-1.hpp"

using namespace std;

int main() {
    fstream file;
    int cantidad;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    
    
    


    return 0;
}