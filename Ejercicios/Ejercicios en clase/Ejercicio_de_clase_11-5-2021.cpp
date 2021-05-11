#include <iostream>
using namespace std;

//Ejercicio 12 modificado
//Ingresado un conjunto de valores terminado con 0, calcular su maximo
//y la cantidad de veces que se repite
//Ejemplo:
//nros: 1 5 7 7 7 15 4 15 15 3 9 7 15 2
//max=15
//repeticiones=4

int main(){
    int valor, max=0,contRepeticiones=1;
    bool esPrimerValor=true;

    cout<<"Ingresa un valor: ";
    cin >>valor;

    while(valor!=0){
        if(valor==max){
            contRepeticiones++;
        }
        
        if(esPrimerValor==true or valor>max){
            esPrimerValor=false;
            max=valor;
            contRepeticiones=1;
        }

        cout<<"Ingresa otro valor: ";
        cin >>valor;
    }

    if(esPrimerValor==false){
        cout<<"Maximo: "<<max<<endl;
        cout<<"Repeticiones: "<<contRepeticiones<<endl;
    }
    else{
        cout<<"No se ingresaron valores distintos de 0."<<endl;
    }
    
    return 0;
}