#include <iostream>
#include <string>
#include <fstream>
#include "tarea2-1.hpp"

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

int main() {
    fstream file;
    string cantidad, aux2;
    int aux;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    getline(file, cantidad);
    aux = stoi(cantidad);
    
    for (int i = 0; i < aux; i++){
        getline(file, aux2);
        
    }
    
    

    
    


    return 0;
}