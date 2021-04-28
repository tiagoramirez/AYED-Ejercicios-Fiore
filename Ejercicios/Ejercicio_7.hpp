#include <iostream>
#include <math.h>//Libreria para funcion sqrt y pow (funcionan con double,con float es sqrtf y powf)
using namespace std;

struct Circunferencia{
    int k;
    int h;
    int r;
};

void ingresarCircunferencia(Circunferencia c){
    cout<<"k: ";
    cin>>c.k;
    cout<<"h: ";
    cin>>c.h;
    cout<<"r: ";
    cin>>c.r;
}

Circunferencia circunferenciaCreate(){
    Circunferencia ret;
    ingresarCircunferencia(ret);
    return ret;
}

struct Punto{
  int x;
  int y;  
};

void ingresarPunto(Punto p){
    cout<<"Ingresa x del punto";
    cin>>p.x;
    cout<<"Ingresa y del punto";
    cin>>p.y;
}

Punto puntoCreate(){
    Punto ret;
    ingresarPunto(ret);
    return ret;
}

void calcularDistanciaPuntos(){

}