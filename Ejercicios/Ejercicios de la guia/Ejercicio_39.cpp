#include <iostream>
using namespace std;

int factorial(int num){
    int ret=1;
    if(num==0){
        return 1;
    }
    else{
        for(int i=num;i>0;i--){
            ret*=i;
        }
        return ret;
    }
}

int main(){
    int vec[20];
    int fact[20];
    int n;
    cout<<"Ingresa la cantidad maxima de numeros que va a ingresar: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int valor;
        cout<<"Ingresa el valor "<<i+1<<": ";
        cin>>valor;
        vec[i]=valor;
    }

    for(int i=0;i<n;i++){
        fact[i]=factorial(vec[i]);
    }

    for(int i=0;i<n;i++){
        cout<<"Numero: "<<vec[i]<<endl;
        cout<<"Factorial: "<<fact[i]<<endl;
    }

    return 0;
}