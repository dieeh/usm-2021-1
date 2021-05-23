#include  <iostream >
#include  <fstream >
using  namespace  std;

struct FlujoNeto {
    int hora;
    int minuto;
    int personas;
};

int  main() {
    FlujoNeto  fn[5] = {{05 ,03, 10} ,{12 ,20, 10} ,{12 ,40, -15}, {16 ,30, 10}, {20 ,30, 15}};
    ofstream  out;
    out.open("flujo-publico.dat",ios:: binary);
    if(!out.is_open ()) {
        cerr  << "Error: no se pudo  abrir  el  archivo  arch.dat" << endl;
        exit (1);
    }
    out.write((char*)fn, 5* sizeof(FlujoNeto));
    
    out.close();
    return  0;
}