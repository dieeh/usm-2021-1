#include <iostream>
#include <cmath>

using namespace std;


class arr_extensible {
private:
    int k;
    unsigned int sizeB;
    unsigned long tamano;
    int* B;
    
    
public:
    arr_extensible(){
        k=0;
        sizeB = 0;
        tamano = 0;
        B = new int[tamano];
        
        while ( (pow(2,k) < tamano) ) {
            k++;
        }
    }

    arr_extensible(unsigned long n){
        tamano = n;
        sizeB = tamano;
        B = new int[tamano];

        k = 0;
        while ( (pow(2,k) < tamano) ) {
            k++;
        }
        
    }

    arr_extensible(unsigned long n, int v){
        tamano = n;
        sizeB = tamano;
        B = new int[tamano];
        for (unsigned long i = 0; i < n; i++) {
            B[i] = v;
        }
        k = 0;
        while ( (pow(2,k) < tamano) ) {
            k++;
        }
    }

    ~arr_extensible(){
        delete[] B;
    }

    /*****
    *  bool arr_extensible::setValue 
    *****
    *  Esta función asigna el valor entero v a una posición i del arreglo B y retorna
    *  un valor booleano, el cual depende de que la posición este dentro del rango de tamaño 
    *  asignado para el arreglo.
    *****
    *  Input:
    *      unsigned long i: Un entero positivo que indicara la posicion donde se guardará el entero v 
    *      en el arreglo B
    *      int v: Elemento que se guarda en el arreglo en una posición determinada por la variable anterior.
    *****
    *  Returns:
    *      bool, retorna true si i esta dentro del tamaño. Sin embargo si i sobrepasa el tamaño
    *      la operación no tiene ningún efecto sobre el arreglo, y retorna false.
    *****/
    bool setValue(unsigned long i, int v){
        if ((i < tamano)) {
            B[i] = v;
            return true;
        }else{
            return false;
        }
    }
    
    /*****
    *  int arr_extensible::getValue 
    *****
    *  Esta función  retorna el valor entero que se encuentra alojado en la posición i que le solicitemos
    *  al arreglo B. Si esta posición esta fuera del rango del tamaño del arreglo, la operación no tendrá
    *  efecto e imprimirá "Error de acceso al arreglo”
    *****
    *  Input:
    *      unsigned long i: Un entero positivo que indicará la posición en la que se encuentra alojado
    *      un elemento
    *****
    *  Returns:
    *      int, retorna el elemento alojado en la posición solicitada y en dado caso que la posición este
    *      fuera del rango del arreglo, este retornará error.
    *****/
    int getValue(unsigned long i){
        if ( (i >= tamano) ) {
            cerr << "Error de acceso al arreglo" << endl;
            exit(1);
        }else{
            return B[i];
        }
    }

    /*****
    *  void arr_extensible::append
    *****
    *  Esta función agrega un elemento al final del arreglo B y lo hace crecer de ser necesario 
    *  en forma exponencial en base 2 dependiendo del tamaño original.
    *****
    *  Input:
    *      int v: Un entero que será agregado al final del arreglo.
    *****
    *  Returns:
    *      void, no retorna nada, pero "modifica" el arreglo B original.
    *****/
    void append(int v){
        if (tamano + 1 > sizeB) {
            while ( pow(2, k) < (tamano + 1) ) {
                k++;
            }
            sizeB = pow(2, k);
            int* Btemp = new int[sizeB];
            
            for (unsigned int i = 0; i < tamano; i++) {
                Btemp[i] = B[i];
            }
            
            delete[] B;
            B = new int[sizeB];
            
            for (unsigned int j = 0; j < sizeB; j++) {
                B[j] = Btemp[j];
            }
            delete[] Btemp;
            B[tamano] = v;
            tamano++;
        }else{
            B[tamano] = v;
            tamano++;
        }
    }

    /*****
    *  void arr_extensible::remove
    *****
    *  Esta función elimina un elemento al final del arreglo B y lo hace decrecer de ser necesario
    *  en forma exponencial en base 2 dependiendo del tamaño original.
    *****
    *  Input:
    *      No hay parámetros puesto que solo elimina un elemento
    *****
    *  Returns:
    *      void, no retorna nada, pero "modifica" el arreglo B original.
    *****/
    void remove(){
        if ( (tamano - 1) <= pow(2, k-1) && (k != 0) ) {
            k--;
            sizeB = pow(2, k);
            int* Btemp = new int[sizeB];
            for (unsigned int i = 0; i < (tamano - 1); i++) {
                Btemp[i] = B[i];
            }
            delete[] B;
            B = new int[sizeB];
            for (unsigned int j = 0; j < sizeB; j++) {
                B[j] = Btemp[j];
            }
            delete[] Btemp;
            tamano--;
        }else if ( (k == 0) ){
            delete[] B;
            B = new int[1];
        }else{
            tamano--;
        }
    }

    /*****
    *  unsigned long arr_extensible::size
    *****
    *  Esta función nos indica el tamaño actual del arreglo B.
    *****
    *  Input:
    *      No hay parámetros
    *****
    *  Returns:
    *      unsingned long, retorna un entero positivo refieriendose al tamaño del arreglo analizado.
    *****/
    unsigned long size(){
        return tamano;
    }

    
 //Funcion de testeo de array, no considerar.
//    void arrayCheck(){
//        for (unsigned int i = 0; i < sizeB; i++) {
//            cout << "Arreglo B en la posicion " << i << ":" << B[i] << endl;
//        }
//        cout << sizeB << endl;
//    }
    
};
