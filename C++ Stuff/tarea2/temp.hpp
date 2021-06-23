//Esto seria algo asi como un TDA de polinomios, para usar dsps
//idealmente se copia y pega al final de tarea2-1.hpp como otra
//clase a utilizar
#include <iostream>
#include "tarea2-1.hpp"

using namespace std;

struct monomio{
    int coeficiente;
    unsigned int exponente;
};

class polinomio {
    private:
        tLista polinomioTotal;
        int cantidad;

    public:
        polinomio(){
            cantidad = 0;
            tLista polinomioTotal;
        }

        ~polinomio(){
            polinomioTotal.clear();
            }

        void append(monomio x){
            polinomioTotal.append(x);
            cantidad++;
        }

        int coeficiente(unsigned int exponente){
            for (polinomioTotal.moveToStart() ; polinomioTotal.currPos() < cantidad; polinomioTotal.next()) {
                if (polinomioTotal.getValue().exponente == exponente){
                    return polinomioTotal.getValue().coeficiente;
                }
            }
            return 0;
            }
            
        float evaluar(float x){
            float resultado = 0, aux;
            for (int i = 0; i < cantidad; i++){
                aux = x;
                for (int j = 0; j < polinomioTotal[i].exponente; j++) {
                    aux *= x;
                }
                aux *= polinomioTotal[i].coeficiente;
                resultado += aux;
            }
            return resultado;
        }
};