#include <iostream>
#include "Ejercicio_7.hpp"
using namespace std;

int main(){
    int rtaA=0,rtaB=0,rtaC=0,rtaD=0;
    Circunferencia c1,c2;
    Punto p;
    cout<<"El programa se basa en la formula ((x-k)^2)+((y-h)^2)=r^2, donde:\nk= el centro en x\nh= el centro en y\nr= el radio"<<endl;
    cout<<"################################"<<endl;
    cout<<"Ingresa la primer circunferencia: "<<endl;
    c1=circunferenciaCreate();
    cout<<"Ingresa la segunda circunferencia: "<<endl;
    c2=circunferenciaCreate();
    cout<<"Ingresa un punto..."<<endl;
    p=puntoCreate();
    
    while(p.x!=0.0 or p.y!=0.0){
        if(circunferenciaContienePunto(c1,p) and circunferenciaContienePunto(c2,p)){
            rtaC++;
        }
        else{
            if(circunferenciaContienePunto(c1,p)){
                rtaA++;
            }
            else{
                if(circunferenciaContienePunto(c2,p)){
                    rtaB++;
                }
                else{
                    rtaD++;
                }
            }
        }

        cout<<"Ingresa otro punto..."<<endl;
        p=puntoCreate();
    }

    cout<<"Puntos dentro solamente de la circunferencia 1: "<<rtaA<<endl;
    cout<<"Puntos dentro solamente de la circunferencia 2: "<<rtaB<<endl;
    cout<<"Puntos dentro de las 2 circunferencias: "<<rtaC<<endl;
    cout<<"Puntos fuera de las 2 circunferencias: "<<rtaD<<endl;
    
    return 0;
}