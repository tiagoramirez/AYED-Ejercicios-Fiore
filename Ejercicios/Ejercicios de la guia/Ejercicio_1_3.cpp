#include <iostream>
using namespace std;

int main(){
    int num, numAnt, sumPos=0, contPos=0, cont0=0, sumNeg=0;
    double promPos;
    cout << "El programa finaliza cuando ingresa un numero igual al anterior\nIngresa un numero: ";
    cin >> num;
    numAnt= num-1;
    while (num!=numAnt){
        numAnt=num;
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
        cout << "Ingrese otro numero: ";
        cin >> num;
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