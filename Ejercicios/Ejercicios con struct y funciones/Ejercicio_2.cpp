#include <iostream>
#include "Ejercicio_2.hpp"
using namespace std;

int main(){
    Triangulo t;
    t = trianguloCreate();
    while(!esTrianguloNulo(t)){
        calcularTriangulo(t);
        t=trianguloCreate();
    }
    cout<<"El programa termino...";
    return 0;
}