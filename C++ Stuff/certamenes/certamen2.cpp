#include <iostream>
#include "tda_c2.hpp"

using namespace std;

tLista filtrarPuntos(tLista L, Punto supIzq, Punto infDer){
    tLista aux;
    L.moveToStart();
    for (int i = 0; i < L.lenght(); i++){
        if ( (L.getValue().obtenerX() >= supIzq.obtenerX()) && (L.getValue().obtenerX() <= infDer.obtenerX()) ) {
            if ( (L.getValue().obtenerY() <= supIzq.obtenerY()) && (L.getValue().obtenerY() >= infDer.obtenerY()) ) {
                aux.append( L.getValue() );
                L.next();                
            }            
        }
        L.next();
    }
    return aux;
}