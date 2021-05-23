#include <iostream>

using namespace std;

int main() {
    int* A;
    A = new int[0];
    A[0] = 1;
    cout << A[0] << endl;

    return 0;
}