#include <iostream>
#include <string.h>
#include "Funciones_permitidas_ARRAYS.hpp"
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
    eliminar<int>(numeros,len,1);
    //Elimino el 645 usando el buscar
    int pos=buscar<int,int>(numeros,len,645,cmpIntInt);    
    if(pos!=-1){//distinto de -1 significa que lo encuentra, sino no borra nada
        eliminar<int>(numeros,len,pos);
    }
    //Ordeno el vector
    ordenar2<int>(numeros,len,cmpIntInt);
    //Agrego de forma ordenada
    insertarOrdenado<int>(numeros,len,131,cmpIntInt);
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
    //buscar binario
    bool enc;
    pos=busquedaBinaria<int,int>(numeros,len,150,cmpIntInt,enc);
    if(enc){
        cout<<"150 esta en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"No se encontro el numero 150"<<endl;
    }
    //Busca e inserta ordenado
    enc=false;
    pos=buscaEInsertaOrdenado(numeros,len,333,enc,cmpIntInt);
    if(!enc){
        cout<<"Se agrego el numero 333 en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"El numero 333 estaba en la posicion: "<<pos<<endl;
    }
    //Busca y agrega desordenado
    enc=false;
    pos=buscaYAgrega(numeros,len,111,enc,cmpIntInt);
    if(!enc){
        cout<<"Se agrego el numero 111 en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"El numero 111 estaba en la posicion: "<<pos<<endl;
    }
    //muestro valores del vector
    for(int i = 0; i<len;i++){
        cout<<numeros[i]<<endl;
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
    eliminar<Persona>(personas,lenP,1);
    //Elimino a Roman buscandolo por su dni
    pos=buscar<Persona,int>(personas,lenP,91011,cmpPersonaInt);
    if(pos!=-1){
        eliminar<Persona>(personas,lenP,pos);
    }
    //Ordeno el vector
    ordenar2<Persona>(personas,lenP,cmpPersonaPersona);
    //Agrego de forma ordenada
    persona.dni=3556;
    strcpy(persona.nombre,"Camila");
    insertarOrdenado<Persona>(personas,lenP,persona,cmpPersonaPersona);
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
    //buscar binario
    pos=busquedaBinaria<Persona,int>(personas,lenP,461325,cmpPersonaInt,enc);
    if(enc){
        cout<<"DNI 461325 esta en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"No se encontro el dni 461325"<<endl;
    }
    //Busca e inserta ordenado
    persona.dni=3333;
    strcpy(persona.nombre,"Marcos");
    enc=false;
    pos=buscaEInsertaOrdenado(personas,lenP,persona,enc,cmpPersonaPersona);
    if(!enc){
        cout<<"Marcos (3333) se agrego en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"Marcos (3333) estaba en la posicion: "<<pos<<endl;
    }
    //Busca y agrega desordenado
    persona.dni=5678;
    strcpy(persona.nombre,"Jose");
    agregar<Persona>(personas,lenP,persona);
    enc=false;
    pos=buscaYAgrega(personas,lenP,persona,enc,cmpPersonaPersona);
    if(!enc){
        cout<<"Jose (5678) se agrego en la posicion: "<<pos<<endl;
    }
    else{
        cout<<"Jose (5678) estaba en la posicion: "<<pos<<endl;
    }
    //muestro valores del vector
    for(int i = 0; i<lenP;i++){
        cout<<"Nombre: "<<personas[i].nombre<<endl;
        cout<<"DNI:"<<personas[i].dni<<endl;
    }
    return 0;
}