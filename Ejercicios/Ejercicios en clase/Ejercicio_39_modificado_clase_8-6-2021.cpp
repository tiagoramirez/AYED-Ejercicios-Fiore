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

struct NroYFactorial{
    int numero;
    int factorial;
};

int main(){
    NroYFactorial fact[20];
    int n;
    cout<<"Ingresa la cantidad maxima de numeros que va a ingresar: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingresa el valor "<<i+1<<": ";
        cin>>fact[i].numero;
        fact[i].factorial=factorial(fact[i].numero);
    }

    for(int i=0;i<n;i++){
        cout<<"Numero: "<<fact[i].numero<<endl;
        cout<<"Factorial: "<<fact[i].factorial<<endl;
    }

    return 0;
}