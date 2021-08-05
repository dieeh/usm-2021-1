#include <fstream>
#include <cmath>
#include <string>
#include <iostream>
#include "tarea3.hpp"

using namespace std;
#define e 0.692363
#define VACIA -1


int descuento1(int compras[], ranuraO ofertas[], int c_compras, int c_ofertas){
    int descuento = 0, contador = 0, q = 0;
    int codigos_usados[c_compras];
    bool flag = false;
    for (int i = 0; i < c_ofertas; i++) {
        for (int j = 0; j < c_compras; j++){
            if (ofertas[i].info.cod_producto == codigos_usados[j] ){
                flag = true;
            }
        }
        if (flag == true) continue;
        for (int k = 0; k < c_compras; k++){
            if(compras[k] == ofertas[i].info.cod_producto) contador++;
            for (int l = 0; l < 10; l++) {
                if(compras[k] == ofertas[i].info.productos_equivalentes[l]) contador++;
            }
        }
        codigos_usados[q] = ofertas[i].info.cod_producto;
        q++;
        for (int m = 0; m < 10; m++){
            if(ofertas[i].info.productos_equivalentes[m] != -1){
                codigos_usados[q] = ofertas[i].info.productos_equivalentes[m];
                q++;
            }
        }
        descuento += (contador / ofertas[i].info.cantidad_descuento)*ofertas[i].info.descuento;
        contador = 0;
    }
    return descuento;
}

int main() {
    fstream f_prod, f_of, f_comp, f_bol;
    string clientes, cant_comp, clave;
    int A, B, a, b, i, j, k;
    f_prod.open("productos.dat", ios::in | ios::binary);
    if (!f_prod.is_open()) {
        cerr << "Error al abrir el archivo 'productos.dat'" << endl;
        exit(1);
    }
    f_prod.read((char*)&a, sizeof(int));
    A = round(a/0.7);
    ranuraP* HT = new ranuraP[A];
    for (int i = 0; i < A; i++){
        HT[i].clave = VACIA;
    }
    producto producto_hash;
    for (i = 0; i < a; i++) {
        f_prod.read((char*)&producto_hash, sizeof(producto));
        hashInsertProducto(HT, producto_hash.cod_producto, producto_hash, A);
    }
    f_prod.close();

    f_of.open("ofertas.dat", ios::in | ios::binary);
    if(!f_of.is_open()){
        cerr << "Error al abrir el archivo 'ofertas.dat'" << endl;
        exit(1);
    }
    f_of.read((char*)&b, sizeof(int));
    B = round(b/0.7);
    ranuraO* HT2 = new ranuraO[B];
    for (j = 0; j < B; j++){
        HT2[j].clave = VACIA;
    }
    oferta oferta_hash;
    for (j = 0; j < b; j++){
        f_of.read((char*)&oferta_hash, sizeof(oferta));
        hashInsertOferta(HT2, oferta_hash.cod_producto, oferta_hash, B);
    }
    f_of.close();
    
    f_comp.open("compras.txt", ios::in);
    if(!f_comp.is_open()){
        cerr << "Error al abrir el archivo 'compras.txt'" << endl;
        exit(1);
    }
    getline(f_comp, clientes);
    int Nclientes = stoi(clientes);
    int* boletas = new int[Nclientes];
    for (k = 0; k < Nclientes; k++){
        int total = 0, descuento;
        getline(f_comp, cant_comp);
        int Ncompras = stoi(cant_comp);
        int* compras_client = new int[Ncompras];
        for (i = 0; i < Ncompras; i++){
            getline(f_comp, clave);
            int codigo = stoi(clave);
            compras_client[i] = codigo;
            total += hashSearchProducto(HT, codigo, A).precio;
        }
        descuento = descuento1(compras_client, HT2, Ncompras, B );
        total-= descuento;
        delete[] compras_client;
        boletas[k] = total;
    }
    f_comp.close();

    f_bol.open("boletas.txt", ios::out);
    if (!f_bol.is_open()) {
        cerr << "Error al abrir el archivo 'boletas.txt'" << endl;
        exit(1);
    }
    f_bol << clientes;
    f_bol << "\n";
    for (int j = 0; j < Nclientes; j++) {
        f_bol << boletas[j];
        f_bol << "\n";
    }
    f_bol.close();


    delete[] HT;
    delete[] HT2;
    delete[] boletas;
    return 0;
}
