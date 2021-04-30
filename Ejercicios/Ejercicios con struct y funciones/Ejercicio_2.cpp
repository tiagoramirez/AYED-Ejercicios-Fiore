#include <iostream>
#include "Ejercicio_2.hpp"
using namespace std;

int main(){
    Triangulo t;
    t = trianguloCreate();
    while(!esTrianguloNulo(t)){
        if (cantLadosIguales(t)==3){
            cout<<"Es un triangulo equilatero."<<endl;
        }
        else{
            if(cantLadosIguales(t)==2){
                cout<<"Es un triangulo isosceles."<<endl;
            }
            else{
                cout<<"Es un triangulo escaleno"<<endl;
            }
        }
        t=trianguloCreate();
    }
    cout<<"El programa termino...";
    return 0;
}