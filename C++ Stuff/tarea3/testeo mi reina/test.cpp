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

int descuento2(int compras[], oferta ofertas[], int c_compras, int c_ofertas){
    int descuento = 0, contador = 0, q = 0;
    int codigos_usados[c_compras];
    bool flag = false;
    for (int i = 0; i < c_ofertas; i++) {
        for (int j = 0; j < c_compras; j++){
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
        for (int m = 0; m < 10; m++){
            if(ofertas[i].productos_equivalentes[m] != -1){
                codigos_usados[q] = ofertas[i].productos_equivalentes[m];
                q++;
            }
        }
        descuento += (contador / ofertas[i].cantidad_descuento)*ofertas[i].descuento;
        contador = 0;
    }
    return descuento;
}
//

int main() {
    fstream file1, file2, file3, boleta;
    int A, B;
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
        }
        descuent = descuento2(compras, HT2, stoi(cant), B);
        cout << descuent << endl;
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


