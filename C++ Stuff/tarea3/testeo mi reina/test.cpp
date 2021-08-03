#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
#define VACIO -2;

struct producto{
    int cod_producto;
    char nombre_producto[31];
    int precio;
};

struct oferta{
    int cod_producto;
    int cantidad_descuento;
    int descuento;
    int productos_equivalentes[10];
};

struct ofertas_activas{
    int cod_producto;
    int cantidad_descuento;
    int cont;
    int descuento;
    int productos_equivalentes[10];
};

int descuento2(int compras[], oferta HT2[], int cant, int B){
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
                        cod_oferta = j;
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
//
//
//int descuento2(int compras[], oferta HT2[], int cod, int B){
//    int desc = 0;
//    for (int i = 0; i < B; i++){
//        int contador = 0;
//        int paradescuento = HT2[i].cantidad_descuento;  
//        for (int j = 0; j < cod ; j++){
//            for (int k = 0; k < 10; k++){
//                if ((compras[j] == HT2[i].cod_producto) || (compras[j] == HT2[i].productos_equivalentes[k])) {
//                    contador++;
//                    compras[j] = VACIO;
//                }
//            }
//        }
//        if (contador >= paradescuento){
//            desc += (contador/paradescuento) * HT2[i].descuento;
//        }
//    }
//    return desc;
//};

int descuento(int compras[], oferta HT2[], int cant, int B, int A){
    ofertas_activas* Carlosteamo = new ofertas_activas[B];
    int cont = 0;
    for (int i = 0; i < B; i++){ 
        for (int j = 0; j < cant ; j++){
            if (compras[j] == HT2[i].cod_producto){
                Carlosteamo[i].cod_producto =  HT2[i].cod_producto;
                Carlosteamo[i].cantidad_descuento =  HT2[i].cantidad_descuento;
                Carlosteamo[i].cont = 0;
                Carlosteamo[i].descuento =  HT2[i].descuento;
                for (int k = 0; k < 10; k++){
                    Carlosteamo[i].productos_equivalentes[k] =  HT2[i].productos_equivalentes[k];
                }
                cont +=1;
                break;
            }   
        }
    }
    int desc_total = 0;
    for (int l = 0; l < cont; l++){
        for (int m = 0; m < cant ; m++){
            for (int n = 0; n < 10 ; n++) {
                if ((compras[m] == Carlosteamo[l].cod_producto) || (compras[m] == Carlosteamo[l].productos_equivalentes[n])) {
                    Carlosteamo[l].cont++;
                    break;
                }
            }
        }
        if (Carlosteamo[l].cont >= Carlosteamo[l].cantidad_descuento){
            desc_total += (Carlosteamo[l].cont/Carlosteamo[l].cantidad_descuento) * Carlosteamo[l].descuento;
        }
    }
    delete[] Carlosteamo;
    return desc_total;
}



int main() {
    fstream file1, file2, file3, boleta;
    int A, B, C;
    file1.open("productos.dat", ios::in|ios::binary);
    if (!file1.is_open()) {
        cerr << "Error al abrir el archivo 'productos.dat'" << endl;
        exit(1);
    }
    file1.read((char*)&A, sizeof(int));
    producto* HT = new producto[A];
    producto prod;
    for (int i = 0; i < A; i++){
        file1.read((char*)&prod, sizeof(producto));
        HT[i] = prod;
    }
    file1.close();
    
    
    file2.open("ofertas.dat", ios::in|ios::binary);
    if (!file2.is_open()) {
        cerr << "Error al abrir el archivo 'ofertas.dat'" << endl;
        exit(1);
    }
    file2.read((char*)&B, sizeof(int));
    oferta* HT2 = new oferta[B];
    oferta of;
    for (int j = 0; j < B; j++){
        file2.read((char*)&of, sizeof(oferta));
        HT2[j] = of;
    }
    file2.close();

    string clientes, cant, cod;
    file3.open("compras.txt", ios::in);
    if (!file3.is_open()) {
        cerr << "Error al abrir el archivo 'compras.txt'" << endl;
        exit(1);
    }
    getline(file3, clientes);
    int* boleteo = new int[stoi(clientes)];
    for (int i = 0; i < stoi(clientes); i++) {
        int total = 0, descuent;
        getline(file3, cant);
        int* compras = new int[stoi(cant)];
        for (int j = 0; j < stoi(cant); j++) {
            getline(file3, cod);
            compras[j] = stoi(cod);
            for (int k = 0; k < A; k++){
                if (stoi(cod) == HT[k].cod_producto){
                    total += HT[k].precio;
                }
            
            }
            //descuent = descuento(compras, HT2, stoi(cant), B, A);
            descuent = descuento2(compras, HT2, stoi(cant), B);
            cout << descuent << endl;
            //if (j == stoi(cant) - 1) {
            //    descuent = descuento(compras, HT2, stoi(cant), B);
            //}
        }
        total -= descuent;
        delete[] compras;
        boleteo[i] = total;
    }
    
    boleta.open("boletas.txt", ios::out);
    if (!boleta.is_open()) {
        cerr << "Error al abrir el archivo 'boleta.txt'" << endl;
        exit(1);
    }
    boleta << clientes;
    boleta << "\n";
    for (int i = 0; i < stoi(clientes); i++) {
        boleta << boleteo[i];
    }
    

    delete[] HT;
    delete[] HT2;
    delete[] boleteo;
    return 0;
}


