/*#include <iostream>
using namespace std;

int main(){
    int i, num, cont0 = 0, contPos = 0, sumPos = 0, sumNeg = 0,cant;
    double promPos = 0;
    cout << "Ingresa la cantidad de numeros que quiere ingresar: ";
    cin >> cant;
    for (i = 0; i < cant and cont0<=4 and promPos<=6; i++) {
        cout << "Ingrese un numero: ";
        cin >> num;
        if (num == 0) {
            cont0++;
        }
        if (num > 0) {
            sumPos += num;
            contPos++;
            promPos = sumPos / (double)contPos;
        }
        if (num < 0) {
            sumNeg += num;
        }
    }
    cout << "Cantidad de 0: " << cont0 << endl;
    cout << "Promedio positivos: " << promPos << endl;
    cout << "Sumatoria negativos: " << sumNeg << endl;
}*/