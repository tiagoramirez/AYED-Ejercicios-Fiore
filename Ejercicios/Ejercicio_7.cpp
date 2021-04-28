#include <iostream>
#include <math.h>//Libreria para funcion sqrt y pow (funcionan con double,con float es sqrtf y powf)
#include "Ejercicio_7.hpp"
using namespace std;

int main(){
    Circunferencia c1,c2;
    Punto p;
    cout<<"El programa se va a basar en la formula ((x-k)^2)+((y-h)^2)=r^2, donde:\nk= el centro en x\nh= el centro en y\nr= el radio"<<endl;
    cout<<"################################"<<endl;
    cout<<"Ingresa la primer circunferencia: "<<endl;
    c1=circunferenciaCreate();
    cout<<"Ingresa la segunda circunferencia: "<<endl;
    c2=circunferenciaCreate();
    cout<<"Ingresa un punto..."<<endl;
    p=puntoCreate();
    while(p.x!=0 or p.y!=0){

    }


    return 0;
}