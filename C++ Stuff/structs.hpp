#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct FlujoNeto {
int hora;
int minuto;
int personas;
};

struct Empleado {
string rut;
int entradas;
int salidas;
};