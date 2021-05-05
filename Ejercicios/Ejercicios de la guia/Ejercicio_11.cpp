#include <iostream>
using namespace std;

int main(){
    float num,maxNeg=1,minPos=-1,resultadoC=27;
    bool esPrimerNeg=true, esPrimerPos=true;
    cout <<"Ingresa un numero: ";
    cin >> num;

    while (num!=0){
        if((esPrimerNeg==true and num<0) or (num<0 and num>maxNeg)){
            maxNeg=num;
            esPrimerNeg=false;
        }
        else{
            if((esPrimerPos==true and num>0) or (num>0 and num<minPos)){
                minPos=num;
                esPrimerPos=false;
            }
        }
        if(num>-17.3 and num<26.9 and num<resultadoC){
            resultadoC=num;
        }
    cout <<"Ingresa otro numero: ";
    cin >> num;
    }

    //Resultado A:
    if (maxNeg==1){
        cout << "No hubo numeros negativos."<<endl;
    }
    else{
        cout << "Maximo de negativos: "<<maxNeg<<endl;
    }
    //Resultado B:
    if(minPos==-1){
        cout << "No hubo numeros positivos."<<endl;
    }
    else{
        cout << "Minimo de positivos: "<<minPos<<endl;
    }
    //Resultado C:
    if(resultadoC==27){
        cout<<"No hubo numeros entre -17.3 y 26.9.";
    }
    else{
        cout <<"Minimo entre -17.3 y 26.9: "<<resultadoC;
    }

    return 0;
}