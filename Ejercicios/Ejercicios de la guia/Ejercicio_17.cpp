#include <iostream>
#include "Ejercicio_17.hpp"
using namespace std;

int main(){
    unsigned int dia,mes,anio,res1=0,res2=0,res3=0,diaMax,mesMax,anioMax;
    char sexo,sexoMax;
    cout<<"Ingresa dia de nacimiento: ";
    cin>>dia;

    while(dia!=0){
        cout<<"Ingresa mes de nacimiento: ";
        cin>>mes;
        cout<<"Ingresa anio de nacimiento: ";
        cin>>anio;
        cout<<"Ingresa sexo: ";
        cin>>sexo;
        //A:
        if(mes==10){
            res1++;
        }
        //B:
        if((anio==1970 and mes==7 and dia<9) or (anio==1970 and mes<7) or (anio<1970)){
            res2++;
        }
        //C:
        if((anio==1942 and (mes==9 or mes==12) and dia>=21 and sexo=='F') or (anio==1942 and mes>9 and mes<12 and sexo=='F')){
            res3++;
        }
        //D:
        if(anio==anioMax and mes==mesMax and dia<diaMax){
            diaMax=dia;
            sexoMax=sexo;
        }
        else{
            if(anio==anioMax and mes<mesMax){
                diaMax=dia;
                mesMax=mes;
                sexoMax=sexo;
            }
            else{
                if(anio<anioMax){
                    diaMax=dia;
                    mesMax=mes;
                    anioMax=anio;
                    sexoMax=sexo;
                }
            }
        }
        cout<<"Ingresa dia de nacimiento: ";
        cin>>dia;
    }
    cout<<"---RESPUESTAS---"<<endl;
    cout<<"Nacimientos en octubre: "<<res1<<endl;
    cout<<"Nacimientos antes de 09/07/1970: "<<res2<<endl;
    cout<<"Nacimientos de mujeres en la primavera de 1942: "<<res3<<endl;
    cout<<"Sexo de la persona mas vieja: "<<sexoMax<<endl;
    
    return 0;
}