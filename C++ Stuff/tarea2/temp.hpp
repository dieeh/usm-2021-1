//Esto seria algo asi como un TDA de polinomios, para usar dsps
//idealmente se copia y pega al final de tarea2-1.hpp como otra
//clase a utilizar


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
        polinomio(int x){
            cantidad = x;
            polinomioTotal = new monomio[cantidad];
        }

        ~polinomio(){
            delete[] polinomioTotal;
            }

        int coeficiente(unsigned int exponente){
            for (int i = 0; i < cantidad; i++) {
                if (polinomioTotal[i].exponente == exponente){
                    return polinomioTotal[i].coeficiente;
                }
            }
            return 0;
            }
            
        float evaluar(float x){
            float resultado = 0, aux;
            for (int i = 0; i < cantidad; i++){
                aux = x;
                for (int j = 0; i < polinomioTotal[i].exponente; j++) {
                    aux *= x;
                }
                resultado += aux;
            }
            return resultado;
        }
};