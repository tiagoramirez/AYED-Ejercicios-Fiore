#include <iostream>
using namespace std;

int ingresaSueldo(){
    int ret;
    cout<<"Ingresa sueldo: ";
    cin >> ret;
    return ret;
}

bool esSueldoNulo(int sueldo){
    if(sueldo==0){
        return true;
    }
    else{
        return false;
    }
}

void mostrarResultados(bool seIngresoSueldo,int k100,int k50, int k20, int k10, int k5, int k2, int k1){
    if(seIngresoSueldo){
        cout<<"Cantidad de 100 = "<<k100<<endl;
        cout<<"Cantidad de 50 = "<<k50<<endl;
        cout<<"Cantidad de 20 = "<<k20<<endl;
        cout<<"Cantidad de 10 = "<<k10<<endl;
        cout<<"Cantidad de 5 = "<<k5<<endl;
        cout<<"Cantidad de 2 = "<<k2<<endl;
        cout<<"Cantidad de 1 = "<<k1<<endl;
    }
    else{
        cout<<"No se ingresaron resultados."<<endl;
    }
}

void calcularSueldo(int &sueldo,int &cantidad,int billete){
    int cant=sueldo/billete;
    cantidad+=cant;
    sueldo-=cant*billete;
}