//#include <iostream>
#include <cmath>

using namespace std;
#define VACIA -1
#define e 0.692363  //variable arbitraria

typedef int tipoClave;

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

struct ranuraP{
    tipoClave clave;
    producto info;
};

struct ranuraO{
    tipoClave clave;
    oferta info;
};

/*****
*   int h
******
*   La función, respecto a la clave y el tamaño de un arreglo, calcula un posición determinada en donde se insertará un valor.
******
* Input:
*   tipoClave k : Respecto a este valor, generará una posición a insertar en el arreglo.
*   int Z : Entrega el tamaño del arreglo, para que el valor a insertar este dentro del rango de este.
******
* Returns:
*   int, retorna la posición en donde debería insertarse el valor en el arreglo.
*****/
int h(tipoClave k, int Z){
    int w;
    long x = (Z-1)*(fmod((e*k),1));
    w = round(x);
    return w; 
}

/*****
*   int h2
******
*   Es la secuencia para avanzar cada ciertos espacios en el arreglo en caso de que el intento de inserción se realice en donde ya esta ocupado.
******
* Input:
*   int h : Gracias a este parametro, es posible calcular cuanto avanzará.
******
* Returns:
*   int, retorna lo que avanzará en el arreglo.
*****/
int h2(int h){
    int total = 0;
    while(h > 0){
        int sumar = 0;
        sumar = h % 10;
        h = h/10;
        total += sumar;
    }
    if (total == 0) return 1;
    return total;
}
/*****
*   int p
******
*   En caso de que la posición en donde se va a insertar el valor esta ocupada, calcula en funcion de la misma 
*   posición, cuanto debería avanzar en el arreglo para poder encontrar una casilla vacia y así insertarlo.
******
* Input:
*   int h : Es la clave, que a su vez sirve para pasarsela a la función h2, ya que esta la ocupa en sus cálculos.
*   int t : Es el número de intento de inserción,    
*
******
* Returns:
*   int, retorna el valor final que debe avanzar en el arreglo para poder realizar la inserción de manera exitosa.
*****/
int p(int h, int t){
    return t*h2(h);
}

/*****
*   int hashInsertProducto
******
*   Esta funcion hace uso de las funciones hashing para encontrar una ranura libre
*   en el arreglo de hashing de productos e insertar un producto en este.
******
* Input:
*   ranuraO HT[] : Es el arreglo del hashing que contiene los productos.
*   int k : Es el codigo del producto a insertar.
*   producto I : Es el struct del producto que se va a insertar al hashing.
*   int X : Es el tamaño del arreglo del hashing de productos.
******
* Returns:
*   int, retorna 1 si la inserción fue exitosa y 0 si hubo una colisión.
*****/
int hashInsertProducto(ranuraP HT[], int k, producto I, int X) {
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(inicio, i)) % X;
    }
    if (HT[pos].clave == k) {
        return 0;
    }
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1;
    }
}

/*****
*   int hashInsertOferta
******
*   Esta funcion hace uso de las funciones hashing para encontrar una ranura libre
*   en el arreglo de hashing de ofertas e insertar una oferta en este.
******
* Input:
*   ranuraO HT[] : Es el arreglo del hashing que contiene las ofertas.
*   int k : Es el codigo del producto de la oferta a insertar.
*   oferta I : Es el struct de oferta que se va a insertar al hashing.
*   int X : Es el tamaño del arreglo del hashing de ofertas.
******
* Returns:
*   int, retorna 1 si la incersion fue exitosa y 0 si hubo una colisión.
*****/
int hashInsertOferta(ranuraO HT[], int k, oferta I, int X) {
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(inicio, i)) % X;
    }
    if (HT[pos].clave == k) {
        return 0;
    }
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1;
    }
}

/*****
*   producto hashSearchProducto
******
*   Esta función usa las funciones del hashing para buscar en un arreglo
*   algun producto especifico según su código de producto.
******
* Input:
*   ranuraP HT[] : Es el arreglo del hashing que contiene los productos.
*   tipoClave k : Es el codigo del producto que se va a buscar.
*   int X : Es el tamaño del arreglo del hashing de productos
******
* Returns:
*   producto, retorna el producto buscado, en caso de no encontrarlo retorna un producto con codigo -1
*****/
producto hashSearchProducto(ranuraP HT[], tipoClave k, int X){
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
    }
    if (HT[pos].clave == k) return HT[pos].info;
    else {
        producto a;
        a.cod_producto = -1;
        return a;
    }
}

/*****
*   oferta hashSearchOferta
******
*   Esta funcion usa las funciones del hashing para buscar en un arreglo 
*   alguna oferta especifica según su código de producto.
******
* Input:
*   ranuraO HT[] : Es el arreglo del hashing que contiene las ofertas.
*   tipoClave k : Es el codigo de producto de la oferta que se va a buscar.
*   int X : Es el tamaño del arreglo del hashing de ofertas
******
* Returns:
*   oferta, retorna la oferta buscada, en caso de no encontrarla retorna una oferta con codigo -1.
*****/
oferta hashSearchOferta(ranuraO HT[], tipoClave k, int X){
    int inicio, i;
    int pos = inicio = h(k,X);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        pos = (inicio + p(k, i)) % X;
    }
    if (HT[pos].clave == k) return HT[pos].info;
    else {
        oferta a;
        a.cod_producto = -1;
        return a;
    }
}
