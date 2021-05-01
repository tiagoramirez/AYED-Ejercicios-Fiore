#include <iostream>
#include "Ejercicio_16.hpp"
using namespace std;

int main(){
    unsigned int legMax1=0,legMax2=0;
    double max1=0,max2=0;
    
    Alumno a;
    a=alumnoCreate();
    while(!esAlumnoNulo(a)){
        calcularAlumnosMax(a,max1,max2,legMax1,legMax2);
        a=alumnoCreate();
    }
    mostrarResultados(legMax1,legMax2);
    return 0;
}