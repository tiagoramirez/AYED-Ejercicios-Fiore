#include <iostream>
using namespace std;

int main(){
    int i, num, cont0 = 0, contPos = 0, sumPos = 0, sumNeg = 0;
    double promPos = 0;
    for (i = 0; i < 167; i++) {
        cout << "Ingrese un numero: ";
        cin >> num;
        if (num == 0) {
            cont0++;
        }
        else{
            if (num > 0) {
                sumPos += num;
                contPos++;
            }
            else{
                sumNeg += num;
            }
        }
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