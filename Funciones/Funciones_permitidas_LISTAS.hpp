#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
struct NodoLista{
    T info;
    NodoLista<T>* siguiente;
};

template <typename T>
void inicializar(NodoLista<T>*& raiz){
    raiz=NULL;
}

template <typename T>
bool estaVacia(NodoLista<T>*& raiz){
    return raiz==NULL;
}

template <typename T>
void push(NodoLista<T>*& raiz, T v){
    NodoLista<T>* puntero=new NodoLista<T>();
    puntero->info=v;
    puntero->siguiente=raiz;
    raiz=puntero;
}

template <typename T>
T pop(NodoLista<T>*& raiz){
    NodoPila<T>* puntero=raiz;
    T info=puntero->info;
    raiz=puntero->siguiente;
    delete puntero;
    return info;
}

template <typename T, typename K>
NodoLista<T>* buscar(NodoLista<T>* raiz, K v, int (*cmpTK)(T,K)){
    NodoLista<T>* punteroAux=raiz;
    NodoLista<T>* punteroANodoEncontrado=NULL;
    while(punteroAux!=NULL && punteroANodoEncontrado==NULL){
        if(cmpTK(punteroAux->info,v)==0){
            punteroANodoEncontrado=punteroAux;
        }
        punteroAux=punteroAux->siguiente;
    }
    return punteroANodoEncontrado;
}

template <typename T, typename K>
void eliminar(NodoLista<T>*& p, K v, int (*criterio)(T,K));

template <typename T>
T eliminarPrimerNodo(NodoLista<T>*& p);

template <typename T>
NodoLista<T>* insertarOrdenado(NodoLista<T>*& p, T v, int (*criterio)(T,T));

template <typename T>
void ordenar(NodoLista<T>*& p, int (*criterio)(T,T));

template <typename T>
NodoLista<T>* buscaEInsertaOrdenado(NodoLista<T>*& p,T v,bool& enc,int (*criterio)(T,T));