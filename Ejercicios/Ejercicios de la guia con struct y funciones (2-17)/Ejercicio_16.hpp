#include <iostream>
using namespace std;

struct Alumno{
    unsigned int leg;
    double prom;
};

bool esAlumnoNulo(Alumno a){
    if(a.leg==0){
        return true;
    }
    else{
        return false;
    }
}

Alumno alumnoCreate(){
    Alumno ret;
    cout<<"Ingresa el legajo: ";
    cin>>ret.leg;
    if(esAlumnoNulo(ret)){
        ret.prom=0;
    }
    else{
        cout<<"Ingresa el promedio: ";
        cin>>ret.prom;
    }    
    return ret;
}

void calcularAlumnosMax(Alumno a,double &max1,double &max2,unsigned int &legMax1, unsigned int &legMax2){
    if(a.prom>max1){
        max2=max1;
        legMax2=legMax1;
        max1=a.prom;
        legMax1=a.leg;

    }
    else{
        if(a.prom>max2){
            max2=a.prom;
            legMax2=a.leg;
        }
    }
}

void mostrarResultados(unsigned int legMax1, unsigned int legMax2){
    cout<<"El alumno maximo es: "<<legMax1<<endl;
    cout<<"El segundo alumno maximo es: "<<legMax2<<endl;
}