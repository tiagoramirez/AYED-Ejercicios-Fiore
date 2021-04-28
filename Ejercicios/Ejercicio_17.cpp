#include <iostream>
using namespace std;

int main(){ //Lo voy a encarar desde 1/1/1922-1/1/2021 (otras fechas pueden tener bugs, la consigna no era clara tampoco)
    unsigned int dia,mes,anio,res1=0,res2=0,res3=0,diaMax,mesMax,anioMax,variableAntiBug=0;
    char sexo,sexoMax;

    cout<<"Ingrese el dia: ";
    cin>>dia;

    while(dia!=0){
        cout<<"Ingrese el mes: ";
        cin>>mes;
        cout<<"Ingrese el anio: ";
        cin>>anio;
        cout<<"Ingrese el sexo: ";
        cin>>sexo;
        //A:
        if(mes==10){
            res1++;
        }
        //B:
        if(anio==70 and mes==7 and dia<9){//Para el mes 7 del año 1970
            res2++;
        }
        else{
            if(anio==70 and mes<7){//Para antes del mes 7 del año 1970
                res2++;
            }
            else{
                if(anio<70 and anio>=22){//Para antes de 1970
                    res2++;
                }
            }
        }
        //C:
        if(anio==42 and (mes==9 or mes==12) and dia>=21 and sexo=='F'){//tomo primavera desde 21/9 a 21/12
            res3++;
        }
        else{
            if(anio==42 and mes>9 and mes<12 and sexo=='F'){
                res3++;
            }
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
                if(anio<anioMax and anio>=variableAntiBug){
                    diaMax=dia;
                    mesMax=mes;
                    anioMax=anio;
                    sexoMax=sexo;
                }
            }
        }
        //arreglo un bug:
        if(anioMax>=22 and anioMax<99){
            variableAntiBug=22;
        }
        cout<<"por ahora la persona mas vieja= "<<diaMax<<"/"<<mesMax<<"/"<<anioMax<<endl;
        cout<<"Ingrese otro dia: ";
        cin>>dia;
    }
    cout<<"Nacimientos en octubre: "<<res1<<endl;
    cout<<"Nacimientos antes de 09/06/1970: "<<res2<<endl;
    cout<<"Nacimientos de mujeres en la primavera de 1942: "<<res3<<endl;
    cout<<"Sexo de la persona mas vieja: "<<sexoMax<<endl;
    return 0;
}