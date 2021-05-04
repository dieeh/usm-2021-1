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
    string s, temp, temp2,temp3,temp4, ruta;
    int n=0, j=0, k=0, b=0, z =0;

    int hora2 = 0, minutos = 0;
    separarHora(hora, hora2, minutos);
       
    ruta = "C++ Stuff\\asistencia.txt";
    cantidadLineas(ruta, n);
    fileEmp.open(ruta, ios::in);
    if (!fileEmp.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    
    string arrEnt[n], arrSal[n];

    while (getline(fileEmp, s)) { 
        int tempH, tempM;
        bool esta = false, esta2 = false;
        temp2 = s[0]; //E
        char temp_ch = s[0];
        temp3 = s.substr(1,(s.length() - 8)); //rut
        temp4 = s.substr(s.length() - 5, 5); //hora
        separarHora(temp4, tempH, tempM);
        z = 0;
        for (z = 0; z < n; z++)
        {
            if(temp3 == arrEnt[z]) {
                esta = (true);
            }
            if(temp3 == arrSal[z]) {
                esta2 = (true);
            }
        }
        
        if( (tempH <= hora2) && (tempM <= minutos) ) {
            switch (temp_ch)
            {
            case 'E':
                if( (esta == false) ) {
                    arrEnt[j] = temp3;
                    j++;
                    b++;
                }else {
                    continue;
                }
                break;
            
            case 'S':
                if( (esta2 == false) ) {
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

    fileComp.open("C++ Stuff\\flujo-publico.dat", ios::binary);
    if (!fileComp.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    
    
    fileComp.close();
    return b;
}









//main
int main()  {
    string hora = "12:30";
    // cin >> hora;
    cout << cantidadPersonas(hora) << endl;

    return 0;
}