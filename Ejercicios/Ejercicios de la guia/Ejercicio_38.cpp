#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Ingresa la cantidad maxima de numeros que va a ingresar: ";
    cin>>n;
    int numeros[30];

    for(int i=0;i<n;i++){
        int valor;
        cout<<"Ingresa el valor "<<i+1<<": ";
        cin>>valor;
        numeros[i]=valor;
    }

    if(numeros[n-1]<10){
        for(int i=0;i<n;i++){
            if(numeros[i]<0){
                cout<<numeros[i]<<endl;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(numeros[i]>=0){
                cout<<numeros[i]<<endl;
            }
        }
    }

    return 0;
}