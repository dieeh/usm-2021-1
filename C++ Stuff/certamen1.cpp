#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct transaccion {
    int codigo_prod;
    int cantidad;
};

struct vendedor {
    int id;
    char nombre[31];
    transaccion ventas[1000];
    int n_ventas;
};

vendedor* vendeProducto(string FileName, int cod, int k, int &sizeArr) {
    fstream fp;
    int a, s = 0;
    vendedor* Vendedores;
    vendedor* retorno;
    vendedor temp;

    fp.open(FileName, ios::in | ios::binary);
    if (!fp.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    
    fp.read((char*)&a, sizeof(int));
    Vendedores = new vendedor[a];

    
    for (int i = 0; i < a; i++) {
        int contadorVentas = 0;
        fp.read((char*)&temp, sizeof(vendedor));
        for (int j = 0; j < temp.n_ventas; j++) {
            if ((temp.ventas[j].codigo_prod) == cod ) {
                contadorVentas += temp.ventas[j].cantidad;
            } 
        }
        if (contadorVentas >= k) {
            Vendedores[s] = temp;
            s++;
        }
    }
    sizeArr = s;
    fp.close();

    retorno = new vendedor[s];
    for (int l = 0; l < s; l++) {
        Vendedores[l] = retorno[l];
    }
    
    delete[] Vendedores;

    return retorno;
}

int main() {
    int size_arr, codigo, cantidad;
    string ruta;
    vendedor* arreglo;

    cout << "Nombre del archivo:" << endl;
    cin >> ruta;
    cout << "Codigo del producto:" << endl;
    cin >> codigo;
    cout << "Cantidad del producto" << endl;
    cin >> cantidad;

    arreglo = vendeProducto(ruta, codigo, cantidad, size_arr);

    return 0;
}