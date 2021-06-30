#include <iostream>
using namespace std;

void inicializarVector(int& lenArr){
    lenArr=0;
}

void agregar(int arr[],int& lenArr,int dato){
    arr[lenArr]=dato;
    lenArr++;
}

int main(){
    int n,valor[40];
    cout<<"Ingresa la cantidad de valores que va a ingresar: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingresa el valor "<<i<<": "<<endl;
        cin>>valor[i];
    }

    int posMax[40];
    int max,len;
    inicializarVector(len);

    for(int i=0;i<n;i++){
        if(i==0 or valor[i]>max){
            max=valor[i];
            inicializarVector(len);
            agregar(posMax,len,i);
        }else{
            if(valor[i]==max){
                agregar(posMax,len,i);
            }
        }
    }

    cout<<"Valor maximo: "<<max<<endl;
    if(len==1){
        cout<<"Posicion: "<<posMax[0]<<endl;
    }
    else{
        cout<<"Posiciones: "<<endl;
        for(int i=0;i<len;i++){
            cout<<posMax[i]<<" ";
        }
    }
    return 0;
}