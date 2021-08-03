#include "test.cpp"

int descuento(int compras[], oferta HT2[], int cant, int B){
    int descuento = 0, contador = 0, q = 0;
    int codigos_usados[cant];
    for (int i = 0; i < cant; i++){
        bool flag = false;
        int cod_oferta;
        for (int f = 0; f < cant; f++){
            if (compras[i] == codigos_usados[f]){
                flag = true;
            }
        }
        if (flag == false){
            for (int j = 0; j < B; j++){
                for (int k = 0; k < 10; k++){
                    if(compras[i] == HT2[j].productos_equivalentes[k]){
                        contador++;
                    }
                }
                if (compras[i] == HT2[j].cod_producto) {
                    contador++;
                    cod_oferta = j;
                }
            }
            codigos_usados[q] = compras[i];
            q++;
            for (int w = 0; w < 10; w++){
                if(HT2[cod_oferta].productos_equivalentes[w] != -1){
                    codigos_usados[q] = HT2[cod_oferta].productos_equivalentes[w];
                    q++;
                }
            }
            
        }
        descuento += ( contador / HT2[cod_oferta].cantidad_descuento ) * HT2[cod_oferta].descuento;
    }
    return descuento;
};