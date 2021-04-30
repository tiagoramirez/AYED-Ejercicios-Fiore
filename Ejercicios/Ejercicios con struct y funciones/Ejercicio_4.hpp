#include <iostream>
using namespace std;

void ingresarValores(int &a,int &b){
    cout<<"Ingresa el primer numero: ";
    cin >>a;
    cout<<"Ingresa el segundo numero: ";
    cin >>b;
}


int multiplicarValores(int a, int b){
    int ret=0;
    for(int i=b;i!=0;i--){
        ret+=a;
    }
    return ret;
}