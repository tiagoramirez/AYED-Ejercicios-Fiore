#include <iostream>
using namespace std;

int main(){
    int n,valor[40];
    cout<<"Ingresa la cantidad de valores que va a ingresar: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingresa el valor "<<i<<": "<<endl;
        cin>>valor[i];
    }

    int max=valor[0];
    for(int i=0;i<n;i++){
        if(valor[i]>max){
            max=valor[i];
        }
    }

    int posMax[40],contPos=0;
    for(int i=0;i<n;i++){
        if(valor[i]==max){
            posMax[contPos]=i;
            contPos++;
        }
    }

    cout<<"Valor maximo: "<<max<<endl;
    if(contPos==1){
        cout<<"Posicion: "<<posMax[0]<<endl;
    }
    else{
        cout<<"Posiciones: "<<endl;
        for(int i=0;i<contPos;i++){
        cout<<posMax[i]<<" ";
    }

    return 0;
}