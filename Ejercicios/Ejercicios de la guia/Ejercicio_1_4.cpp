#include <iostream>
using namespace std;

int main(){
    int i=0, num, cont0 = 0, contPos = 0, sumPos = 0, sumNeg = 0,cant;
    double promPos = 0;
    cout << "Ingresa la cantidad de numeros que quiere ingresar: ";
    cin >> cant;
    while(i < cant and cont0<=4) {
        cout << "Ingrese un numero: ";
        cin >> num;
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
        i++;
    }
    
    if (contPos==0){
        cout<<"No se ingresaron valores positivos."<<endl;
    }
    else{
        promPos = sumPos / (double)contPos;
        cout << "Cantidad de 0: " << cont0 << endl;
    }
    cout << "Promedio positivos: " << promPos << endl;
    cout << "Sumatoria negativos: " << sumNeg << endl;
    return 0;
}