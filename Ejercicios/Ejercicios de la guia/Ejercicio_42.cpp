#include <iostream>
using namespace std;

int main(){
    int n,valor[40];
    cout<<"Ingresa la cantidad de valores que va a ingresar: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingresa el valor "<<i<<endl;
        cin>>valor[i];
    }

    int max=valor[0];
    for(int i=0;i<n;i++){
        if(valor[0]>max){
            max=valor[0];
        }
    }


    return 0;
}