#include  <iostream >
#include  <fstream >
using  namespace  std;

struct FlujoNeto {
    int hora;
    int minuto;
    int personas;
};

int  main() {
    FlujoNeto  fn[1] = {{15 ,57 , 10}};
    ofstream  out;
    out.open("flujo-publico2.dat",ios:: binary);
    if(!out.is_open ()) {
        cerr  << "Error: no se pudo  abrir  el  archivo  arch.dat" << endl;
        exit (1);
    }
    out.write((char*)fn, sizeof(FlujoNeto));
    
    out.close();
    return  0;
}