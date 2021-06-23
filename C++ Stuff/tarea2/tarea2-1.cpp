#include <iostream>
#include <string>
#include <fstream>
#include "tarea2-1.hpp"

using namespace std;

int main() {
    fstream file;
    string cantidad, aux2, tempA, tempB, aux4;
    int aux, aux3, aux5;
    polinomio* arreglo;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    getline(file, cantidad);
    aux = stoi(cantidad);
    
    arreglo = new polinomio[aux];

    for (int i = 0; i < aux; i++){
        getline(file, aux2);
        aux3 = stoi(aux2);
        for (int j = 0; j < aux3; j++){
            file >> tempA;
            file >> tempB;
            arreglo[i].append(stoi(tempA), stoi(tempB));
        }
        
    }
    string output;
    while (file >> aux4) {
        if (aux4 == "COEFICIENTE"){
            file >> tempA;
            file >> tempB;
            aux5 = stoi(tempA);
            aux3 = stoi(tempB);
            aux2 = to_string(arreglo[aux5].coeficiente(aux3));
            output.append(aux2 + " ");
        }
        if (aux4 == "EVALUAR"){
            file >> tempA;
            file >> tempB;
            aux5 = stoi(tempA);
            float aux6 = stoi(tempB);
            aux2 = to_string(arreglo[aux5].evaluar(aux6));
            output.append(aux2 + " ");
        }
        
    }
    cout << output << endl;
    return 0;
}