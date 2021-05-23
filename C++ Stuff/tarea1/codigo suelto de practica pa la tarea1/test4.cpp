#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct FlujoNeto {
int hora;
int minuto;
int personas;
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

//funcion separarLineas
void cantidadLineas(string path, int &n){
    fstream fileTemp;
    string temporal;
    fileTemp.open(path, ios::in);
    if (!fileTemp.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    while(getline(fileTemp, temporal)) {
        n++;
    }
    fileTemp.close();
}


//funcion principal
int cantidadPersonas(string hora) { 
    fstream fileEmp, fileComp;
    string lineaArch, temp2, tempRut, tempHora, ruta;
    int n=0, j=0, k=0, ContadorEmpleados=0, z=0;

    int hora2 = 0, minutos = 0;
    separarHora(hora, hora2, minutos);
       
    ruta = "asistencia.txt";
    cantidadLineas(ruta, n);
    fileEmp.open(ruta, ios::in);
    if (!fileEmp.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    
    string ArregloEntradas[n], ArregloSalidas[n];

    while (getline(fileEmp, lineaArch)) { 
        int tempH, tempM;
        bool esta = false, esta2 = false;
        temp2 = lineaArch[0]; //Entrada o Salida
        char temp_ch = lineaArch[0];
        tempRut = lineaArch.substr(1,(lineaArch.length() - 8)); //Rut
        tempHora = lineaArch.substr(lineaArch.length() - 5, 5); //Hora
        separarHora(tempHora, tempH, tempM);
        z = 0;
        for (z = 0; z < n; z++)
        {
            if(tempRut == ArregloEntradas[z]) {
                esta = (true);
            }
            if(tempRut == ArregloSalidas[z]) {
                esta2 = (true);
            }
        }
        
        if( (tempH <= hora2) && (tempM <= minutos) ) {
            switch (temp_ch)
            {
            case 'E':
                if( (esta == false) ) {
                    ArregloEntradas[j] = tempRut;
                    j++;
                    ContadorEmpleados++;
                }else {
                    continue;
                }
                break;
            
            case 'S':
                if( (esta2 == false) ) {
                    ArregloSalidas[k] = tempRut;
                    k++;
                    ContadorEmpleados--;
                }else {
                    continue;
                }
                break;
            }
        }
    }
    fileEmp.close();

    //fileComp.open("C++ Stuff\\flujo-publico.dat", ios::binary);
    //if (!fileComp.is_open()) {
    //    cout << "Error al abrir el archivo" << endl;
    //    exit(1);
    //}
    
    
    //fileComp.close();
    return ContadorEmpleados;
}









//main
int main()  {
    string hora = "12:30";
    // cin >> hora;
    cout << cantidadPersonas(hora) << endl;

    return 0;
}