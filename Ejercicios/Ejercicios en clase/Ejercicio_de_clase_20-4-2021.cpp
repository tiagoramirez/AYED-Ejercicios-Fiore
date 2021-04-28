#include <iostream>
using namespace std;

int main(){
    unsigned int fecha,dia,mes,anio,fechaNueva;
    cout<<"Ingresa una fecha: ";
    cin>>fecha;

    dia=fecha/1000000;
    mes=(fecha%1000000)/10000;
    anio=fecha%10000;
    fechaNueva=anio*10000+mes*100+dia;
    
    cout <<fechaNueva<<endl;    
    return 0;
}