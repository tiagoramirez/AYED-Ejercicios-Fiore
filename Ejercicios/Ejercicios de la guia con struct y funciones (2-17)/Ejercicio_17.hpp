#include <iostream>
using namespace std;

struct Fecha{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;

};

struct Persona{
    Fecha nacimiento;
    char sexo;
};

bool esPersonaNula(Persona p){
    if(p.nacimiento.dia==0){
        return true;
    }
    else{
        return false;
    }
}

Persona personaCreate(){
    Persona ret;
    cout<<"Ingresa dia de nacimiento: ";
    cin>>ret.nacimiento.dia;
    if(esPersonaNula(ret)){
        ret={{0,0,0},'X'};
    }
    else{
        cout<<"Ingresa mes de nacimiento: ";
        cin>>ret.nacimiento.mes;
        cout<<"Ingresa anio de nacimiento: ";
        cin>>ret.nacimiento.anio;
        cout<<"Ingresa sexo: ";
        cin>>ret.sexo;
    }
    return ret;
}

void calcularRespuesta1(Persona p,unsigned int &res1){
    if(p.nacimiento.mes==10){
        res1++;
    }
}

void calcularRespuesta2(Persona p, unsigned int &res2){
    if((p.nacimiento.anio==1970 and p.nacimiento.mes==7 and p.nacimiento.dia<9) or (p.nacimiento.anio==1970 and p.nacimiento.mes<7) or (p.nacimiento.anio<1970)){
        res2++;
    }
}

void calcularRespuesta3(Persona p,unsigned int &res3){
    if((p.nacimiento.anio==1942 and (p.nacimiento.mes==9 or p.nacimiento.mes==12) and p.nacimiento.dia>=21 and p.sexo=='F') or (p.nacimiento.anio==1942 and p.nacimiento.mes>9 and p.nacimiento.mes<12 and p.sexo=='F')){
        res3++;
    }
}

void calcularRespuesta4(Persona p, unsigned int &diaMax, unsigned int &mesMax, unsigned int &anioMax, char &sexoMax){
    if(p.nacimiento.anio==anioMax and p.nacimiento.mes==mesMax and p.nacimiento.dia<diaMax){
        diaMax=p.nacimiento.dia;
        sexoMax=p.sexo;
    }
    else{
        if(p.nacimiento.anio==anioMax and p.nacimiento.mes<mesMax){
            diaMax=p.nacimiento.dia;
            mesMax=p.nacimiento.mes;
            sexoMax=p.sexo;
        }
        else{
            if(p.nacimiento.anio<anioMax){
                diaMax=p.nacimiento.dia;
                mesMax=p.nacimiento.mes;
                anioMax=p.nacimiento.anio;
                sexoMax=p.sexo;
            }
        }
    }
}

void mostrarResultados(unsigned int res1, unsigned int res2, unsigned int res3, char sexoMax){
    cout<<"---RESPUESTAS---"<<endl;
    cout<<"Nacimientos en octubre: "<<res1<<endl;
    cout<<"Nacimientos antes de 09/07/1970: "<<res2<<endl;
    cout<<"Nacimientos de mujeres en la primavera de 1942: "<<res3<<endl;
    cout<<"Sexo de la persona mas vieja: "<<sexoMax<<endl;
}