#include <iostream>
#include <math.h>//Libreria para funcion sqrt y pow (funcionan con double,con float es sqrtf y powf)
using namespace std;

//Estructura y funciones de circunferencia
struct Circunferencia{
    double k;
    double h;
    double r;
};

void ingresarCircunferencia(Circunferencia &c){
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

//Estructura y funciones de punto
struct Punto{
    double x;
    double y;  
};

void ingresarPunto(Punto &p){
    cout<<"Ingresa x del punto: ";
    cin>>p.x;
    cout<<"Ingresa y del punto: ";
    cin>>p.y;
}

Punto puntoCreate(){
    Punto ret;
    ingresarPunto(ret);
    return ret;
}

//Funciones
double calcularDistanciaPuntos(Circunferencia c,Punto p){
    double ret;
    ret=pow(p.x-c.k,2)+pow(p.y-c.h,2);//hago ((x-k)^2)+((y-h)^2)
    ret=sqrt(ret);//despues le hago la raiz cuadrada
    return ret;
}

bool circunferenciaContienePunto(Circunferencia c,Punto p){
    double distanciaCircPunt=calcularDistanciaPuntos(c,p);
    if(distanciaCircPunt<c.r){
        return true;
    }
    else{
        if(distanciaCircPunt==c.r){
            return true;
        }
        else{
            return false;
        }
    }
}