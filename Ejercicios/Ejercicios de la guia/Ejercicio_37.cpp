#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Ingresa la cantidad de pares que queres: ";
    cin>>n;

    int numPares[25];

    for(int i=0;i<=n-1;i++){
        numPares[i]=i*2;
    }
    
    for(int i=0;i<=n-1;i++){
        cout<<numPares[i]<<endl;
    }

    return 0;
}