#include <iostream>
using namespace std;

int main(){
    float num,maxNeg=-320000000000000000,minPos=320000000000000000,resultadoC=777;//Pongo numeros muy chicos y muy grandes
    cout <<"Ingresa un numero: ";
    cin >> num;

    while (num!=0){
        if(num<0 and num>maxNeg){
            maxNeg=num;
        }
        else{
            if(num>0 and num<minPos){
                minPos=num;
            }
        }
        if(num>-17.3 and num<26.9 and num<resultadoC){
            resultadoC=num;
        }
    cout <<"Ingresa otro numero: ";
    cin >> num;
    }

    //Resultado A:
    if (maxNeg==-320000000000000000){
        cout << "No hubo numeros negativos."<<endl;
    }
    else{
        cout << "Maximo de negativos: "<<maxNeg<<endl;
    }
    //Resultado B:
    if(minPos==320000000000000000){
        cout << "No hubo numeros positivos."<<endl;
    }
    else{
        cout << "Minimo de positivos: "<<minPos<<endl;
    }
    //Resultado C:
    if(resultadoC==777){
        cout<<"No hubo numeros entre -17.3 y 26.9.";
    }
    else{
        cout <<"Minimo entre -17.3 y 26.9: "<<resultadoC;
    }

    return 0;
}