#include <iostream>
using namespace std;

//El usuario ingresa numeros y finaliza ingresando el 9999.
//Mostrar cantidad de 0, promedio de positivos y suma de negativos.

int main(){
    int num, cont0 = 0, contPos = 0, sumPos = 0, sumNeg = 0;
    double promPos = 0;

    cout<<"Ingresa un numero: ";
    cin>>num;

    while (num!=9999){
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

        cout<<"Ingresa otro numero: ";
        cin>>num;
    }

    promPos = sumPos / (double)contPos;
    cout << "Cantidad de 0: " << cont0 << endl;
    cout << "Promedio positivos: " << promPos << endl;
    cout << "Sumatoria negativos: " << sumNeg << endl;
    return 0;
}