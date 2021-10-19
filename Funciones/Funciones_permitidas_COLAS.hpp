#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
struct NodoCola{
    T info;
    NodoCola* siguiente;
};

template <typename T>
void inicializar(NodoCola<T>*& raiz){
    raiz=NULL;
}

template <typename T>
bool estaVacia(NodoCola<T>* raiz){
    return raiz==NULL;
}

template <typename T>
void encolar(NodoCola<T>*& colaFrente, NodoCola<T>*& colaFin, T v){
    NodoCola<T>* puntero=new NodoCola<T>();
    puntero->info=v;
    puntero->siguiente=NULL;
    if(estaVacia<T>(colaFrente)){
        colaFrente=puntero;
    }
    else{
        colaFin->siguiente=puntero;
    }
    colaFin=puntero;
}

template <typename T>
T desencolar(NodoCola<T>*& colaFrente, NodoCola<T>*& colaFin){
    NodoCola<T>* puntero=colaFrente;
    T info=puntero->info;
    colaFrente=puntero->siguiente;
    if(estaVacia<T>(colaFrente)){
        colaFin=NULL;
    }
    delete puntero;
    return info;
}