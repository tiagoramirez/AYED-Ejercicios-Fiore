#include <iostream>
#include "Ejercicio_2.hpp"
using namespace std;

int main(){
    Triangulo t;
    int cantEqu=0,cantEsc=0,cantIso=0;
    t = trianguloCreate();
    while(!esTrianguloNulo(t)){
        calcularTriangulo(t,cantEqu,cantIso,cantEsc);
        t=trianguloCreate();
    }
    mostrarResultados(cantEqu,cantIso,cantEsc);
    return 0;
}