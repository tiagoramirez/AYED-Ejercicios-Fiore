#include <iostream>
#include <string.h>
#include "Funciones_permitidas_AYED.hpp"
using namespace std;

struct Persona{
    int dni;
    char nombre[26];
};

int cmpIntInt(int x, int y){//funcion comparar int con int
    if(x==y){
        return 0;
    }
    else{
        if(x>y){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int cmpPersonaInt(Persona persona, int x){//funcion comparar persona con int
    if(persona.dni==x){
        return 0;
    }
    else{
        if(persona.dni>x){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int cmpPersonaPersona(Persona p1, Persona p2){
    if(p1.dni==p2.dni){
        return 0;
    }
    else{
        if(p1.dni>p2.dni){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    //----------Ejemplo de uso de funciones permitidas con tipo de dato int----------
    int numeros[10];
    int len;
    //Inicializo vector
    inicializarVector(len);
    //Agrego valores al vector
    agregar<int>(numeros,len,150);
    agregar<int>(numeros,len,23);
    agregar<int>(numeros,len,432);
    agregar<int>(numeros,len,645);
    agregar<int>(numeros,len,143);
    agregar<int>(numeros,len,123);
    agregar<int>(numeros,len,12);
    //Elimino el 23 pasandole su posicion
    eliminar(numeros,len,2);
    //Elimino el 645 usando el buscar
    int pos=buscar<int,int>(numeros,len,645,cmpIntInt);    
    if(pos!=-1){//distinto de -1 significa que lo encuentra, sino no borra nada
        eliminar(numeros,len,pos);
    }
    //Ordeno el vector
    ordenar<int>(numeros,len,cmpIntInt);
    //muestro valores del vector
    for(int i = 0; i<len;i++){
        cout<<numeros[i]<<endl;
    }
    //busco algun valor
    pos=buscar<int,int>(numeros,len,143,cmpIntInt);
    if(pos!=-1){
        cout<<"143 esta en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"No se encontro el numero 143"<<endl;
    }
    
    //----------Ejemplo de uso de funciones permitidas con tipo de dato Persona----------
    Persona personas[10];
    int lenP;
    //Inicializo vector
    inicializarVector(lenP);
    //Agrego valores al vector
    Persona persona;
    persona.dni=1234;
    strcpy(persona.nombre,"Adrian");
    agregar<Persona>(personas,lenP,persona);
    persona.dni=5678;
    strcpy(persona.nombre,"Jose");
    agregar<Persona>(personas,lenP,persona);
    persona.dni=91011;
    strcpy(persona.nombre,"Roman");
    agregar<Persona>(personas,lenP,persona);
    persona.dni=4949;
    strcpy(persona.nombre,"Raul");
    agregar<Persona>(personas,lenP,persona);
    persona.dni=2858;
    strcpy(persona.nombre,"Pedro");
    agregar<Persona>(personas,lenP,persona);
    persona.dni=461325;
    strcpy(persona.nombre,"Sofia");
    agregar<Persona>(personas,lenP,persona);
    //Elimino a jose pasandole su posicion
    eliminar(personas,lenP,1);
    //Elimino a Roman buscandolo
    pos=buscar<Persona,int>(personas,lenP,91011,cmpPersonaInt);
    if(pos!=-1){
        eliminar(personas,lenP,pos);
    }
    //Ordeno el vector
    ordenar<Persona>(personas,lenP,cmpPersonaPersona);
    //muestro valores del vector
    for(int i = 0; i<lenP;i++){
        cout<<"Nombre: "<<personas[i].nombre<<endl;
        cout<<"DNI:"<<personas[i].dni<<endl;
    }
    //busco algun valor
    pos=buscar<Persona,int>(personas,lenP,4949,cmpPersonaInt);
    if(pos!=-1){
        cout<<"DNI 4949 esta en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"No se encontro el dni 4949"<<endl;
    }

    return 0;
}