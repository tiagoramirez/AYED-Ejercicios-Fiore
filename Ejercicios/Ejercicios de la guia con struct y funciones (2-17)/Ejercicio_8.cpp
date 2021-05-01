#include <iostream>
#include "Ejercicio_8.hpp"
using namespace std;

int main(){
    Boleto b;
    unsigned int res1=0,res2=0,res3=0,res4=0;
    b=boletoCreate();

    while(!esBoletoNulo(b)){
        calcularBoleto(b,res1,res2,res3,res4);
        b=boletoCreate();    
    }
    
    mostrarResultados(res1,res2,res3,res4);

    return 0;
}