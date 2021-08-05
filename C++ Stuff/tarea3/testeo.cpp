#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    //int a = (int) 12.9578;
    //double b = 15.49;
    //int f = round(b);
    //int c = b;
    //cout << f << " - " << b << " - " << c << endl; 
    double e = 0.692363;
    int k = 12, z = 4;
    float p = fmod(14.857,1); //0.857

    int x = (z-1)*((e*k));

    cout << p << endl;

    //int A,B,C;
    //fstream file1, file2, file3, boleta;
    //string ruta = "productos.dat";
    //file1.open(ruta, ios::in|ios::binary);
    //if (!file1.is_open()) {
    //    cerr << "Error al abrir el archivo '" << ruta << "'" << endl;
    //    exit(1);
    //}
    //file1.read((char*)&A, sizeof(int));
    //A = (A/0.7);
    //typedef producto tipoInfo;
    //ranura* HT = new ranura[A];
    //producto i;
    //for (int j = 0; j < A; j++){
    //    file1.read((char*)&i, sizeof(producto));
    //    hashInsert(&HT[j], i.cod_producto, i, A);
    //}
    //file1.close();
    //
    //
    //string ruta2 = "ofertas.dat";
    //file2.open(ruta2, ios::in|ios::binary);
    //if (!file2.is_open()) {
    //    cerr << "Error al abrir el archivo '" << ruta2 << "'" << endl;
    //    exit(1);
    //}
    //file2.read((char*)&B, sizeof(int));
    //B = (B/0.7);
    //typedef oferta tipoInfo;
    //ranura* HT2 = new ranura[B];
    //oferta g;
    //for (int j = 0; j < B; j++){
    //    file2.read((char*)&g, sizeof(oferta));
    //    hashInsert(&HT2[j], g.cod_producto, g, B);
    //}
    //file2.close();
    //
    //
    //string ruta3 = "compras.txt", r, u, Q; //ascii
    //file3.open(ruta3, ios::in);
    //if (!file3.is_open()) {
    //    cerr << "Error al abrir el archivo '" << ruta3 << "'" << endl;
    //    exit(1);
    //}
    //getline(file3, Q);
    //C = stoi(Q);
    //boleta.open("boleta.txt", ios::out);
    //if (!boleta.is_open()) {
    //    cerr << "Error al abrir el archivo 'boleta.txt'" << endl;
    //    exit(1);
    //}
    //boleta << Q;
    //
    //for (int k = 0; k < C; k++){
    //    getline(file3, r);
    //    int HT3[stoi(r)];
    //    int total = 0;
    //    for (int l = 0; l < stoi(r); l++){
    //        getline(file3, u);
    //        HT3[l] = stoi(u);
    //        producto cliente = hashSearch(&HT[A], stoi(u), A);
    //        total += cliente.precio;
    //    }
    //    boleta << total;
    //}
    //boleta.close();
    //file3.close();

    //delete[] HT;
    //delete[] HT2;

    return 0;
}