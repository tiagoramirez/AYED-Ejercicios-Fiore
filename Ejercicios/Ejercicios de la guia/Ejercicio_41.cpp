#include <iostream>
using namespace std;

void rellenarArray(int a[],int b[],bool esPosicionPar,int cantidadDeElementos){
    if(esPosicionPar){
        for(int i=0;i<cantidadDeElementos;i++){
            if(i%2==0){
                a[i]=b[i];
            }
        }
    }
    else{
        for(int i=0;i<cantidadDeElementos;i++){
            if(i%2!=0){
                a[i]=b[i];
            }
        }
    }
    
}

int main(){
    
    int n;
    int uno[30];
    int dos[30];
    int tres[30];

    cout<<"Ingresa la cantidad de valores a ingresar por cada conjunto: ";
    cin>> n;

    cout<<"Conjunto 1!"<<endl;
    
    for(int i=0; i<n;i++){
        cout<<"Ingresa el valor "<<i<<": ";
        cin>>uno[i];
    }

    cout<<"Conjunto 2!"<<endl;

    for(int i=0; i<n;i++){
        cout<<"Ingresa el valor "<<i<<": ";
        cin>>dos[i];
    }

    rellenarArray(tres,dos,false,n);
    rellenarArray(tres,uno,true,n);

    cout<<"Conjunto 3:"<<endl;

    for(int i=0;i<n;i++){
        cout<<tres[i]<<endl;
    }

    return 0;
}