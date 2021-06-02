#include <iostream>
#include "Ejercicio_14.hpp"
using namespace std;

int main(){
    int sueldo;
    int k100=0,k50=0,k20=0,k10=0,k5=0,k2=0,k1=0;
    bool seIngresoSueldo=false;
    
    sueldo=ingresaSueldo();

    while (!esSueldoNulo(sueldo)){
        seIngresoSueldo=true;

        calcularSueldo(sueldo,k100,100);
        calcularSueldo(sueldo,k50,50);
        calcularSueldo(sueldo,k20,20);
        calcularSueldo(sueldo,k10,10);
        calcularSueldo(sueldo,k5,5);
        calcularSueldo(sueldo,k2,2);
        calcularSueldo(sueldo,k1,1);
        
        sueldo=ingresaSueldo();
    }
    
    mostrarResultados(seIngresoSueldo,k100,k50,k20,k10,k5,k2,k1);
    return 0;
}