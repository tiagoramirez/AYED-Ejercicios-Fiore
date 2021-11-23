#include <iostream>
#include <stdio.h>
using namespace std;

// Punto 1:

template <typename T>
struct NodoPila{
    T info;
    NodoPila<T>* siguiente;
};

const int cantidadCaracteresMaximo=100;

// Punto 2:

template <typename T>
void push(NodoPila<T>*& raiz, T v){
    NodoPila<T>* puntero=new NodoPila<T>();
    puntero->info=v;
    puntero->siguiente=raiz;
    raiz=puntero;
}

template <typename T>
T pop(NodoPila<T>*& raiz){
    NodoPila<T>* puntero=raiz;
    T info=puntero->info;
    raiz=puntero->siguiente;
    delete puntero;
    return info;
}

// Punto 3:

void agregarAFIFO(char vector[],char c,int& indice){
    vector[indice]=c;
    indice++;
}

// Punto 4:

char suprimirDeFIFO(char vector[],int& indice){
    char ret=vector[indice];
    indice++;
    return ret;
}

// Punto 5:

void ingresarCaracteres(char vector[],int& indiceVector,NodoPila<char>*& raizPila){
    FILE* archivo=fopen("caracteres.dat","rb+");
    char caracterLeido;
    fread(&caracterLeido,sizeof(char),1,archivo);
    while(!feof(archivo)){
        if(caracterLeido!=' '){
            push<char>(raizPila,caracterLeido);
           agregarAFIFO(vector,caracterLeido,indiceVector);
        }
        fread(&caracterLeido,sizeof(char),1,archivo);
    }
    fclose(archivo);
}

// Punto 6:

bool esPalindromo(){
    
    NodoPila<char>* raizPilaCaracteres=NULL;

    char vectorCaracteres[cantidadCaracteresMaximo];
    int len=0;
    
    ingresarCaracteres(vectorCaracteres,len,raizPilaCaracteres);

    bool esPalindromo=true;

    int i=0;
    while(raizPilaCaracteres!=NULL){
        char caracterRaiz=pop(raizPilaCaracteres);
        char caracterVector=suprimirDeFIFO(vectorCaracteres,i);
        if(caracterRaiz!=caracterVector){
            esPalindromo=false;
        }
    }
    return esPalindromo;
}