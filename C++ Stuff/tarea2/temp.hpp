//Esto seria algo asi como un TDA de polinomios, para usar dsps
//idealmente se copia y pega al final de tarea2-1.hpp como otra
//clase a utilizar

#include <iostream>
#include <string>

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

class polinomio {
    private:
        monomio* polinomioTotal;
        int cantidad;

    public:
        polinomio(){
            cantidad = 0;
            polinomioTotal = new monomio[cantidad];
        }

        polinomio(int x){
            cantidad = x;
            polinomioTotal = new monomio[cantidad];
        }

        ~polinomio(){
            delete[] polinomioTotal;
            }

        





};