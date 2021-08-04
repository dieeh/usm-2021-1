#include "test.cpp"

int descuento2(int compras[], oferta HT2[], int cant, int B){
    int descuento = 0, contador = 0, q = 0;
    int codigos_usados[cant];
    for (int i = 0; i < cant; i++){
        bool flag = false, flag2 = false ,flag3 = false, flag4 = false;
        int cod_oferta = 0, aux_compra = compras[i];
        for (int f = 0; f < cant; f++){
            if (compras[i] == codigos_usados[f]){
                flag3 = true;
            }
        }
        if (flag3 == true) continue;
        if (flag == false){
            for (int j = 0; j < B; j++){
                for (int k = 0; k < 10; k++){
                    if(compras[i] == HT2[j].productos_equivalentes[k]){
                        contador++;
                        cod_oferta = j;
                        flag2 = true;
                    }
                }
                if (compras[i] == HT2[j].cod_producto) {
                    contador++;
                    cod_oferta = j;
                }
            }
            for (int w = 0; w < 10; w++){
                int aux_prod = HT2[cod_oferta].productos_equivalentes[w];
                if(HT2[cod_oferta].productos_equivalentes[w] != -1 && flag2 == true){
                    codigos_usados[q] = HT2[cod_oferta].productos_equivalentes[w];
                    q++;
                }
            }
        }
        descuento += ( contador / HT2[cod_oferta].cantidad_descuento ) * HT2[cod_oferta].descuento;
    }
    return descuento;
}


int descuento2(int compras[], oferta ofertas[], int c_compras, int c_ofertas){
    int descuento = 0, contador = 0, q = 0;
    int codigos_usados[c_compras];
    bool flag = false;
    for (int i = 0; i < c_ofertas; i++) {
        for (int j = 0; j < c_compras; i++){
            if (ofertas[i].cod_producto == codigos_usados[j] ){
                flag = true;
            }
        }
        if (flag == true) continue;
        for (int k = 0; k < c_compras; k++){
            if(compras[k] == ofertas[i].cod_producto) contador++;
            for (int l = 0; l < 10; l++) {
                if(compras[k] == ofertas[i].productos_equivalentes[l]) contador++;
            }
        }
        codigos_usados[q] = ofertas[i].cod_producto;
        q++;
        descuento += (contador / ofertas[i].cantidad_descuento)*ofertas[i].descuento;
    }
    return descuento;
}