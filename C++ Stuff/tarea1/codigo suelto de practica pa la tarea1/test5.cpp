#include  <iostream >
#include  <fstream >
using  namespace  std;

bool compararHoras(int hora1, int minuto1, int hora2, int minuto2) {
    if ( hora2 > hora1) {
        return true;
    }
    if ((hora2 == hora1) && (minuto2 > minuto1)) {
        return true;
    }else{
        return false;
    }

}

int main() {
    

    return 0;
}