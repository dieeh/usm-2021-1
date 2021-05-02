#include <iostream>
#include <string>

using namespace std;

struct empleado {
    string nombre;
    double sueldo;
    int edad;
    char turno;
}emp[2];

int main(){
    
    emp[0].nombre = "Juanito Perez";
    emp[0].sueldo = 10000.0;
    emp[0].edad = 97;
    emp[0].turno = 'n';

    emp[1].nombre = "Pablo Jimenez";
    emp[1].sueldo = 12322.0;
    emp[1].edad = 53;
    emp[1].turno = 'd';

    for (int i = 0; i < 2; i++)
    {
        cout << "Nombre: " << emp[i].nombre << endl;
        cout << "Sueldo: $" << emp[i].sueldo << endl;
        cout << "Edad: " << emp[i].edad << endl;
        cout << "Turno: " << emp[i].turno << endl;
        cout << endl;
    }
    return 0;
}