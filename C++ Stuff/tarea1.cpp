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

//funcion separar hora
void separarHora(string hora, int &hora2, int &minutos){
    if (hora.length() != 5) {
        cout << "Error en el largo del string hora" << endl;
        exit(1);
    }
    
    hora2 = stoi(hora.substr(0,2));
    minutos = stoi(hora.substr(3,2));
}


//funcion principal
int cantidadPersonas(string hora) { 
    fstream file;
    string s, temp, temp2,temp3,temp4;
    int n, i, j=0;

    int hora2 = 0, minutos = 0;
    separarHora(hora, hora2, minutos);
       
    file.open("asistencia.txt", ios::in);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    while(getline(file, temp)) {
        n++;
    }
    string arr[n];

   while (getline(file, s))
   {   int tempH, tempM;
       file >> temp2; //E
       file >> temp3; //rut
       file >> temp4; //hora
       separarHora(temp4, tempH, tempM);
                
       bool agregar = true;
       for (i = 0; i < n; i++)
       {
            if(arr[i] == temp3) {
                agregar = false;
           }  
       }
        if(agregar == true) {
                arr[j] = temp2;
                j++;
            }
   }
   
    
    file.close();
    return 0;
}









//main
int main()  {
    string hora;
    cin >> hora;
    cout << cantidadPersonas(hora) << endl;

    return 0;
}