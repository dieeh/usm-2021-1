#include <iostream>
#include <string>

using namespace std;

int main()  {
    string s = "23:30";

    int hora2 =  stoi(s.substr(0,2));
    int minutos = stoi(s.substr(3,2));
    
    
    cout << hora2 << endl;
    cout << minutos << endl;
    cout << sizeof(s) << endl;
    cout << s.length() << endl;

    return 0;
}