#include <iostream>
#include <string>
#include <fstream>
#include "tarea2-1.hpp"

using namespace std;

struct monomio{
    int exponente;
    int cantidad;
};

int main() {
    fstream file;
    string cantidad;
    int aux;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    getline(file, cantidad);
    aux = stoi(cantidad);

    

    
    


    return 0;
}