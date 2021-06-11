#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct FlujoNeto {
int hora;
int minuto;
int personas;
};

/*****
 *  void separarHora
 *****
 *  Esta funcion separa un string con una hora en formato hh:mm 
 *  y lo transforma en 2 int que contienen la hora y los minutos,
 *  los cuales se actualizan fuera de la funcion puesto que son parametros
 *  por referencia.
 *****
 *  Input:
 *      string hora : Un string de 5 caracteres que contiene una hora en formato hh:mm
 *      int hora2 : Un int que se pasa por referencia a la funcion, que tendra la hora del string
 *      int minutos : Un int que se pasa por referencia a la funcion, que tendra los minutos del string
 *****
 *  Returns:
 *      void, no retorna nada, puesto que solo actualiza los parametros que se le entregan por referencia.
 *****/
void separarHora(string hora, int &hora2, int &minutos) {
    if (hora.length() != 5) {
        cerr << "Error en el largo del string hora" << endl;
        exit(1);
    }
    
    hora2 = stoi(hora.substr(0,2));
    minutos = stoi(hora.substr(3,2));
}


/*****
 *  bool compararHoras
 *****
 *  Esta funcion compara 2 horas en el formato hora1:minuto1 y 
 *  hora2:minuto2, y retorna true o false dependiendo si hora1:minuto1 
 *  es mayor, menor o igual que hora2:minuto2.
 *****
 *  Input:
 *      int hora1 : Un int que contiene la hora en un formato de 0 a 23.
 *      int minuto1 : Un int que contiene los minutos en un formato de 0 a 59.
 *      int hora2 : Un int que contiene la hora en un formato de 0 a 23.
 *      int minuto2 : Un int que contiene los minutos en un formato de 0 a 59.
 *****
 *  Returns:
 *      bool, retorna 'true' si hora1:minuto1 es menor o igual que hora2:minuto2,
 *      y retorna 'false' si hora1:minuto1 es mayor que hora2:minuto2
*****/
bool compararHoras(int hora1, int minuto1, int hora2, int minuto2) {
    if ( hora2 > hora1) {
        return true;
    }
    if ((hora2 == hora1) && (minuto2 >= minuto1)) {
        return true;
    }else{
        return false;
    }
}


/*****
 *  void cantidadLineas
 *****
 *  Esta funcion cuenta la cantidad de lineas que tiene un archivo ASCII.
 *****
 *  Input:
 *      string path : Un string que contiene la ruta al archivo ASCII que se deba leer.
 *      int n : Un int que se pasa por referencia a la funcion, que tendra la cantidad de lineas del archivo.
 *****
 *  Returns:
 *      void, no retorna nada, puesto que solo actualiza los parametros que se le entregan por referencia.
 *****/
void cantidadLineas(string path, int &n) {
    fstream fileTemp;
    string temporal;
    n = 0;
    fileTemp.open(path, ios::in);
    if (!fileTemp.is_open()) {
        cerr << "Error al abrir el archivo '" << path << "'" << endl;
        exit(1);
    }
    while(getline(fileTemp, temporal)) {
        n++;
    }
    fileTemp.close();
}


/*****
 *  int cantidadPersonas
 *****
 *  Esta funcion cuenta la cantidad de personas que se encuentra en el supermercado leyendo
 *  los archivos 'asistencia.txt' y 'flujo-publico.dat'.
 *****
 *  Input:
 *      string hora : Un string de 5 caracteres que contiene una hora en formato hh:mm
 *****
 *  Returns:
 *      int, retorna la suma de las variables locales ContadorEmpleados y ContadorPersonas.
 *****/
int cantidadPersonas(string hora) { 
    fstream fileEmp, fileComp;
    string lineaArch, tempRut, tempHora, ruta, ruta2;
    int n=0, j=0, k=0, z=0, ContadorEmpleados=0, ContadorPersonas=0;

    int hora2 = 0, minutos = 0;
    separarHora(hora, hora2, minutos);
    if ( ((0 > hora2) || (hora2 > 23)) || ((0 > minutos) || (minutos > 59)) )
    {
        cerr << "Error en la hora ingresada" << endl;
        exit(1);
    }
    
       
    ruta = "asistencia2.txt";
    cantidadLineas(ruta, n);
    fileEmp.open(ruta, ios::in);
    if (!fileEmp.is_open()) {
        cerr << "Error al abrir el archivo '" << ruta << "'" << endl;
        exit(1);
    }
    
    string* ArregloEntradas = new string[n];
    string* ArregloSalidas = new string[n];

    while (getline(fileEmp, lineaArch)) { 
        int tempH, tempM;
        bool esta = false, esta2 = false, salida= false;
        char temp_ch = lineaArch[0]; //Entrada o Salida
        tempRut = lineaArch.substr(1,(lineaArch.length() - 7)); //Rut
        tempHora = lineaArch.substr(lineaArch.length() - 5, 5); //Hora
        separarHora(tempHora, tempH, tempM);
        z = 0;
        for (z = 0; z < n; z++) {
            if(tempRut == ArregloEntradas[z]) {
                esta = (true);
            }
            if(tempRut == ArregloSalidas[z]) {
                esta2 = (true);
            }
        }
        
        if( (compararHoras(tempH, tempM, hora2, minutos) == true) ) {
            switch (temp_ch) {
            case 'E': //Entrada
                if( (esta == false) ) {
                    ArregloEntradas[j] = tempRut;
                    j++;
                    ContadorEmpleados++;
                }else {
                    continue;
                }
                break;
            
            case 'S': //Salida
                if( (esta2 == false) ) {
                    ArregloSalidas[k] = tempRut;
                    k++;
                    ContadorEmpleados--;
                    salida = true;
                }else {
                    continue;
                }
                break;
            }
        }
        int contador1 = 0, contador2 = 0;
        
        //Borrado de elementos de los arrays de entrada y salida
        if ( (salida == true)) {  
            for (contador1 = 0; contador1 < k; contador1++) {
            for (contador2 = 0; contador2 < j; contador2++) {
                if ( ArregloSalidas[contador1] == ArregloEntradas[contador2] ) {
                    ArregloEntradas[contador2] = "a";
                    ArregloSalidas[contador1] = "b";
                    salida = false;
                    break;
                }   
            }
        }
        }
    }

    delete[] ArregloEntradas;
    delete[] ArregloSalidas;
    fileEmp.close();

    ruta2 = "flujo-publico.dat";
    fileComp.open(ruta2, ios::in|ios::binary);
    
    if (!fileComp.is_open()) {
        cerr << "Error al abrir el archivo '" << ruta2 << "'" << endl;
        exit(1);
    }

    FlujoNeto fn;
    while (fileComp.read((char*)&fn, sizeof(FlujoNeto)))
        if( (compararHoras(fn.hora, fn.minuto, hora2, minutos) == true) ){
            ContadorPersonas += fn.personas;
        }
    fileComp.close();    
    
    
    return (ContadorEmpleados + ContadorPersonas);
}


int main()  {
    string hora;
    cin >> hora;
    cout << cantidadPersonas(hora) << endl;

    //string test[18] = {"08:00", "08:04", "08:30", "09:00", "10:00", "12:00", "12:15", "12:16", "12:30", "13:30", "14:30", "15:50", "16:00", "17:10", "17:15", "18:00", "18:15", "20:00"};
    //for (int i = 0; i < 18; i++)
    //{
    //    cout << test[i] << ": " << cantidadPersonas(test[i]) << endl;
    //}
    

    return 0;
}
