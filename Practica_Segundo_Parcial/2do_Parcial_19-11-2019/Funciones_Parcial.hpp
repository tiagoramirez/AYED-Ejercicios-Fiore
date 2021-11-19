#include <iostream>
#include <stdio.h>
using namespace std;

//Punto 1
template <typename T>
struct NodoLista{
    T info;
    NodoLista<T>* siguiente;
};

struct Libro{
    char codigo[6];
    char autor[51];
    char titulo[101];
};

struct Usuario{
    int id;
    char nombre[51];
    unsigned cantidadIntercambios;
    NodoLista<Libro>* raizListaLibros;
};

struct Intercambio{
    int id1;
    char codigoLibro1[6];
    int id2;
    char codigoLibro2[6];
};


//Punto 2

void push(NodoLista<Libro>*& raiz, Libro v){
    NodoLista<Libro>* puntero=new NodoLista<Libro>();
    puntero->info=v;
    puntero->siguiente=raiz;
    raiz=puntero;
}

NodoLista<Usuario>* buscar(NodoLista<Usuario>* raiz, int v){
    NodoLista<Usuario>* punteroAux=raiz;
    NodoLista<Usuario>* punteroANodoEncontrado=NULL;
    while(punteroAux!=NULL && punteroANodoEncontrado==NULL){
        if(punteroAux->info.id==v){
            punteroANodoEncontrado=punteroAux;
        }
        punteroAux=punteroAux->siguiente;
    }
    return punteroANodoEncontrado;
}

//Punto 3

Libro eliminar(NodoLista<Libro>*& raizListaLibro, char* codigoLibro){
    Libro l;
    return l;
}

void intercambiarLibros(NodoLista<Libro>*& raizListaLibros1,NodoLista<Libro>*& raizListaLibros2, char codigoLibro1[],char codigoLibro2[]){
    Libro l1;
    l1=eliminar(raizListaLibros1,codigoLibro1);
    Libro l2;
    l2=eliminar(raizListaLibros2,codigoLibro2);
    push(raizListaLibros1,l2);
    push(raizListaLibros2,l1);
}

//Punto 4

void aplicarIntercambios(NodoLista<Usuario>* raizListaUsuario){
    FILE* archivoIntercambios=fopen("intercambios.dat","rb+");

    Intercambio intercambio;
    fread(&intercambio,sizeof(Intercambio),1,archivoIntercambios);

    while(!feof(archivoIntercambios)){

        NodoLista<Usuario>* ptr1=buscar(raizListaUsuario,intercambio.id1);
        ptr1->info.cantidadIntercambios++;
        NodoLista<Usuario>* ptr2=buscar(raizListaUsuario,intercambio.id2);
        ptr2->info.cantidadIntercambios++;

        intercambiarLibros(ptr1->info.raizListaLibros,ptr2->info.raizListaLibros,intercambio.codigoLibro1,intercambio.codigoLibro2);

        fread(&intercambio,sizeof(Intercambio),1,archivoIntercambios);
    }

    fclose(archivoIntercambios);
}