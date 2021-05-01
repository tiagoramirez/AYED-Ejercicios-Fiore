#include <iostream>
using namespace std;

int main(){
    int a, b,res=0;
    cout<<"Ingresa el numero A: ";
    cin>>a;
    cout<<"Ingresa el numero B: ";
    cin>>b;
    for(int i=0;i<b;i++){
        res+=a;
    }
    cout <<"Resultado: "<<res;
    return 0;
}