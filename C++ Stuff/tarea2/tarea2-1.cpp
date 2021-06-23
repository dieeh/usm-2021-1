#include <iostream>
#include <string>
#include <fstream>
#include "tarea2-1.hpp"

using namespace std;

int main() {
    fstream file;
    string cantidad, aux2;
    int aux, aux3;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    getline(file, cantidad);
    aux = stoi(cantidad);
    
    for (int i = 0; i < aux; i++){
        getline(file, aux2);
        aux3 = stoi(aux2);
        for (int j = 0; j < aux3; j++) {
            
        }
        
    }
    
    

    
    


    return 0;
}