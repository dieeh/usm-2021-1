#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
int cantidadPersonas(string horaF2) { 
    fstream fileEmp, fileComp;
    string s, temp, temp2,temp3,temp4;
    int n, j=0, k=0, b=0;

    int hora2 = 0, minutos = 0;
    separarHora(horaF2, hora2, minutos);
       
    fileEmp.open("asistencia.txt", ios::in);
    if (!fileEmp.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    while(getline(fileEmp, temp)) {
        n++;
    }
    string arrEnt[n], arrSal[n];

    while (getline(fileEmp, s)) { 
        int tempH, tempM, b;
        bool esta = false, esta2 = false;
        fileEmp >> temp2; //E
        char temp_ch = s[0];
        fileEmp >> temp3; //rut
        fileEmp >> temp4; //hora
        separarHora(temp4, tempH, tempM);
        for (int z = 0; z < n; z++)
        {
            if(temp3 == arrEnt[z]) {
                esta = (true);
            }
            if(temp3 == arrSal[z]) {
                esta2 = (true);
            }
        }
        
        if(tempH <= hora2 && tempM <= minutos) {
            switch (temp_ch)
            {
            case 'E':
                if( (esta = false) ) {
                    arrEnt[j] = temp3;
                    j++;
                    b++;
                }else {
                    continue;
                }
                break;
            
            case 'S':
                if( (esta2 = false) ) {
                    arrSal[k] = temp3;
                    k++;
                    b--;
                }else {
                    continue;
                }
                break;
            }
        }
    }
    fileEmp.close();

    fileComp.open("flujo-publico.dat", ios::binary);

    
    fileComp.close();
    return b;
}









//main
int main()  {
    string hora;
    cin >> hora;
    cout << cantidadPersonas(hora) << endl;

    return 0;
}