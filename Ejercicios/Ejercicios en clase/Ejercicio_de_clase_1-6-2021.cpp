#include <iostream>
using namespace std;
//Realice un programa que realice el factorial de un numero natural y el 0

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

int factorial2(int num){//forma recursiva de hacer el factorial
    int ret;
    if(num==0){
        return 1;
    }
    else{
        ret=num*factorial2(num-1);
    }
}

int main(){
    int num,fact;

    cout<<"Ingresa un numero: ";
    cin>>num;

    while(num>=0){
        fact=factorial(num);
        cout<<"Factorial de "<<num<<": "<<fact<<endl;

        cout<<"Ingresa un numero: ";
        cin>>num;
    }
    
    return 0;
}
