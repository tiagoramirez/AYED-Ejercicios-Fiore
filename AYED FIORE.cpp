#include <iostream>
using namespace std;

int main(){
    int i, num, cont0 = 0, contPos = 0, sumPos = 0, sumNeg = 0;
    double promPos = 0;
    cout << "Ingrese un numero: ";
    cin >> num;
    for (i = 1; i < 10; i++) {
        if (num == 0) {
            cont0++;
        }
        if (num > 0) {
            sumPos += num;
            contPos++;
        }
        if (num < 0) {
            sumNeg += num;
        }
        cout << "Ingrese un numero: ";
        cin >> num;
    }
    promPos = sumPos / (double)contPos;

    cout << "Cantidad de 0: " << cont0 << endl;
    cout << "Promedio positivos: " << promPos << endl;
    cout << "Sumatoria negativos: " << sumNeg << endl;
}