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

        void appendMon(int coef, unsigned int exp){
            monomio a;
            a.exponente = exp;
            a.coeficiente = coef;
            polinomioTotal.append(a);
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
            for (polinomioTotal.moveToStart() ; polinomioTotal.currPos() < cantidad; polinomioTotal.next()){
                aux = x;
                for (int j = 0; j < polinomioTotal.getValue().exponente; j++) {
                    aux *= x;
                }
                aux *= polinomioTotal.getValue().coeficiente;
                resultado += aux;
            }
            return resultado;
        }
};