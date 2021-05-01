#include <iostream>
#include "Ejercicio_17.hpp"
using namespace std;

int main(){
    unsigned int res1=0,res2=0,res3=0,diaMax,mesMax,anioMax;
    char sexoMax;
    Persona p=personaCreate();

    while(!esPersonaNula(p)){
        calcularRespuesta1(p,res1);
        calcularRespuesta2(p,res2);
        calcularRespuesta3(p,res3);
        calcularRespuesta4(p,diaMax,mesMax,anioMax,sexoMax);
        p=personaCreate();
    }

    mostrarResultados(res1,res2,res3,sexoMax);

    return 0;
}