#include <fstream>
#include <string>
#include <iostream>

using namespace std;

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

int main(){
    int A = 10,B = 3, n;
    fstream f_prod, f_of;
    string s;
    f_prod.open("productos.dat", ios::out | ios::binary);
    if (!f_prod.is_open()) {
        cerr << "Error al abrir el archivo 'productos.dat'" << endl;
        exit(1);
    }
    f_prod.write((char*)&A, sizeof(int));
    producto test1;
    test1.cod_producto = 2;
    s = "Cereal";
    n = s.length();
    for (int i = 0; i < n; i++){
        test1.nombre_producto[i] = s[i];
    }
    test1.precio = 2500;
    f_prod.write((char*)&test1, sizeof(producto));

    producto test2;
    test2.cod_producto = 4;
    s = "Leche";
    n = s.length();
    for (int i = 0; i < n; i++){
        test2.nombre_producto[i] = s[i];
    }
    test2.precio = 800;
    f_prod.write((char*)&test2, sizeof(producto));

    producto test3;
    test3.cod_producto = 6;
    s = "Huevos";
    n = s.length();
    for (int i = 0; i < n; i++){
        test3.nombre_producto[i] = s[i];
    }
    test3.precio = 1500;
    f_prod.write((char*)&test3, sizeof(producto));

    producto test4;
    test4.cod_producto = 8;
    s = "Cafe";
    n = s.length();
    for (int i = 0; i < n; i++){
        test4.nombre_producto[i] = s[i];
    }
    test4.precio = 3000;
    f_prod.write((char*)&test4, sizeof(producto));

    producto test5;
    test5.cod_producto = 10;
    s = "Arroz";
    n = s.length();
    for (int i = 0; i < n; i++){
        test5.nombre_producto[i] = s[i];
    }
    test5.precio = 600;
    f_prod.write((char*)&test5, sizeof(producto));

    producto test6;
    test6.cod_producto = 12;
    s = "Tallarines";
    n = s.length();
    for (int i = 0; i < n; i++){
        test6.nombre_producto[i] = s[i];
    }
    test6.precio = 400;
    f_prod.write((char*)&test6, sizeof(producto));

    producto test7;
    test7.cod_producto = 14;
    s = "Salsa_tomate";
    n = s.length();
    for (int i = 0; i < n; i++){
        test7.nombre_producto[i] = s[i];
    }
    test7.precio = 300;
    f_prod.write((char*)&test7, sizeof(producto));

    producto test8;
    test8.cod_producto = 16;
    s = "Yoghurt";
    n = s.length();
    for (int i = 0; i < n; i++){
        test8.nombre_producto[i] = s[i];
    }
    test8.precio = 350;
    f_prod.write((char*)&test8, sizeof(producto));

    producto test9;
    test9.cod_producto = 18;
    s = "Pan";
    n = s.length();
    for (int i = 0; i < n; i++){
        test9.nombre_producto[i] = s[i];
    }
    test9.precio = 1200;
    f_prod.write((char*)&test9, sizeof(producto));

    producto test10;
    test10.cod_producto = 20;
    s = "Chocolate";
    n = s.length();
    for (int i = 0; i < n; i++){
        test10.nombre_producto[i] = s[i];
    }
    test10.precio = 1500;
    f_prod.write((char*)&test10, sizeof(producto));
    
    f_prod.close();
    


/*


2->Cereal : 2500
4->Leche : 800
6->Huevos : 1500
8->Café : 3000
10->Arroz : 600
12->Tallarines : 400
14->Salsa_Tomates : 300
16->Yoghurt : 350
18->Pan : 1200
20->Chocolate : 1500

Codigo 2 - 3 unidades
Descuento: 300
Equivalentes: {4, 16}

Codigo 4 - 3 unidades
Descuento: 300
Equivalentes: {2, 16}

Codigo 16 - 3 unidades
Descuento : 300
Equivalentes: {2, 4}

1er cliente: 6000
2do cliente: 3300
3er cliente: 11200


3
6
2
4
6
16
16
4
3
10
18
20
10
16
2
8
16
18
16
4
12
16
2




*/

    f_of.open("ofertas.dat", ios::out | ios::binary);
    if (!f_of.is_open()) {
        cerr << "Error al abrir el archivo 'ofertas.dat'" << endl;
        exit(1);
    }
    f_of.write((char*)&B, sizeof(int));
    oferta test11;
    test11.cod_producto = 2;
    test11.cantidad_descuento = 3;
    test11.descuento = 300;
    test11.productos_equivalentes[0] = 4;
    test11.productos_equivalentes[1] = 16;
    for (int i = 2; i < 10; i++){
        test11.productos_equivalentes[i] = -1;
    }
    f_of.write((char*)&test11, sizeof(oferta));

    oferta test12;
    test12.cod_producto = 4;
    test12.cantidad_descuento = 3;
    test12.descuento = 300;
    test12.productos_equivalentes[0] = 2;
    test12.productos_equivalentes[1] = 16;
    for (int i = 2; i < 10; i++){
        test12.productos_equivalentes[i] = -1;
    }
    f_of.write((char*)&test12, sizeof(oferta));

    oferta test13;
    test13.cod_producto = 16;
    test13.cantidad_descuento = 3;
    test13.descuento = 300;
    test13.productos_equivalentes[0] = 2;
    test13.productos_equivalentes[1] = 4;
    for (int i = 2; i < 10; i++){
        test13.productos_equivalentes[i] = -1;
    }
    f_of.write((char*)&test13, sizeof(oferta));

    f_of.close();
    return 0;
}
