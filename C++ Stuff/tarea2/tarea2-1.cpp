#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "tarea2-1.hpp"

using namespace std;

int main() {
    fstream file, output2;
    string cantidad, aux2, tempA, tempB, aux4;
    int aux, aux3, aux5;
    polinomio* arreglo;

    file.open("entradaPolinomio.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file >> cantidad;
    aux = stoi(cantidad);
    
    arreglo = new polinomio[aux];

    for (int i = 0; i < aux; i++){
        file >> aux2;
        aux3 = stoi(aux2);
        for (int j = 0; j < aux3; j++){
            file >> tempA; //exponente
            file >> tempB; //coeficiente
            unsigned int auxA = stoul(tempA);
            int auxB = stoi(tempB);
            arreglo[i].appendMon(auxB, auxA);
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
            output.append(aux2 + "\n");
        }
        if (aux4 == "EVALUAR"){
            file >> tempA;
            file >> tempB;
            aux5 = stoi(tempA);
            float aux6 = stof(tempB);
            aux2 = to_string(arreglo[aux5].evaluar(aux6));
            for (int k = 0; k < aux2.length(); k++) {
                if(aux2[k] == '.'){
                    aux2 = aux2.substr(0, k+3);
                }
            }
            output.append(aux2 + "\n");
        }
        
    }
    file.close();
    output2.open("salidaPolinomios.txt", ios::out);
    output2 << output;
    output2.close();
    return 0;
}