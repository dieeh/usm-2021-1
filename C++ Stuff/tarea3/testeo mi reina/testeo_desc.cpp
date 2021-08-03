#include "test.cpp"

int descuento(int compras[], oferta HT2[], int cant, int B){
    int descuento = 0, contador = 0;
    int codigos_usados[cant];
    for (int i = 0; i < cant; i++){
        bool flag = false;
        for (int f = 0; f < cant; f++){
            if (compras[i] == codigos_usados[f]){
                flag = true;
            }
        }
        while (flag = false){
            for (int j = 0; j < B; j++){
                for (int k = 0; k < 10; k++){
                    if(compras[i] == HT2[j].productos_equivalentes[k]){
                        contador++;
                    }
                }
                if (compras[i] == HT2[j].cod_producto) {
                    contador++;
                }
            }
            codigos_usados[i] = compras[i];
            break;
        }
    }
    
};