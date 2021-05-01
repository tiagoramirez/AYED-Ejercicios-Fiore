#include <iostream>
#include "Ejercicio_9.hpp"
using namespace std;

int main(){
    Terna t;
    t=ternaCreate();

    while(!esTernaNula(t)){
        ordenarTerna(t);
        mostrarResultados(t);
        t=ternaCreate();
    }

    cout<<"Termino el programa...";
    return 0;
}