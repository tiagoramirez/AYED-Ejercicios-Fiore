#include <iostream>
using namespace std;

struct Triangulo{
    int l1;
    int l2;
    int l3;
};

void ingresaLados(Triangulo &t){
    cout<<"Ingresa el lado 1: ";
    cin>>t.l1;
    cout<<"Ingresa el lado 2: ";
    cin>>t.l2;
    cout<<"Ingresa el lado 3: ";
    cin>>t.l3;
}

Triangulo trianguloCreate(){
    Triangulo ret;
    ingresaLados(ret);
    return ret;
}

int cantLadosIguales(Triangulo t){
    if (t.l1 == t.l2 and t.l1 == t.l3) {
        return 3;
    }
    else{
        if (t.l1 != t.l2 and t.l1 != t.l3 and t.l2 != t.l3) {
            return 0;
        }
        else {
            return 2;
        }
    }
}

bool esTrianguloNulo(Triangulo t){
    if(t.l1==0 or t.l2==0 or t.l3==0){
        return true;
    }
    else{
        return false;
    }
}