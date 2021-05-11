#include <iostream>
#include "Ejercicio_16.hpp"
using namespace std;

int main(){
    int legMax1=-1,legMax2=-1;
    double max1=-1,max2=-1;
    
    Alumno a;
    a=alumnoCreate();
    while(!esAlumnoNulo(a)){
        calcularAlumnosMax(a,max1,max2,legMax1,legMax2);
        a=alumnoCreate();
    }
    mostrarResultados(max1,max2,legMax1,legMax2);
    return 0;
}