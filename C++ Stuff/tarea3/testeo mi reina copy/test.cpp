#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
#define VACIO -1;

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

int descuento(int compras[], oferta HT2[], int cod, int B){
    int desc = 0;
    for (int i = 0; i < B; i++){
        int contador = 0;
        int paradescuento = HT2[i].cantidad_descuento;
        for (int j = 0; j < cod ; j++){
            if (compras[i] == HT2[j].cod_producto){
                contador++;
            };
            for (int k = 0; k < 10; i++){
                if (compras[i] == HT2[j].productos_equivalentes[j] && HT2[j].productos_equivalentes[j] != -1) {
                contador++;
                }
            }
        }
        if (contador >= paradescuento){
            desc += (contador/paradescuento) * HT2[i].descuento;
        }
        compras[i] = VACIO
    }
    return desc;
};


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
    for (int j = 0; j < A; j++){
        file1.read((char*)&of, sizeof(oferta));
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
            descuent = descuento(compras, HT2, stoi(cod), B);
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
    for (int i = 0; i < stoi(clientes); i++) {
        boleta << boleteo[i];
    }
    

    delete[] HT;
    delete[] HT2;
    delete[] boleteo;
    return 0;
}


