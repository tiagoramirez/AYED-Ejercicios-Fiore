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
    NodoLista<T>* puntero=raiz;
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

template <typename T>
void liberar(NodoLista<T>*& raiz){
    while(!estaVacia<T>(raiz)){
        pop<T>(raiz);
    }
}

template <typename T>
NodoLista<T>* insertarOrdenado(NodoLista<T>*& raiz, T v, int (*cmpTT)(T,T)){
    NodoLista<T>* puntero=new NodoLista<T>();
    puntero->info=v;
    NodoLista<T>* punteroAct=raiz;
    NodoLista<T>* punteroAnt=NULL;
    while(punteroAct!=NULL && cmpTT(v,punteroAct->info)>0){
        punteroAnt=punteroAct;
        punteroAct=punteroAct->siguiente;
    }
    puntero->siguiente=punteroAct;
    if(punteroAnt==NULL){
        raiz=puntero;
    }
    else{
        punteroAnt->siguiente=puntero;
    }
    return puntero;
}

template <typename T>
NodoLista<T>* agregar(NodoLista<T>*& raiz, T v){
    NodoLista<T>* puntero=new NodoLista<T>();
    puntero->info=v;
    puntero->siguiente=NULL;
    NodoLista<T>* punteroAct=raiz;
    NodoLista<T>* punteroAnt=NULL;
    while(punteroAct!=NULL){
        punteroAnt=punteroAct;
        punteroAct=punteroAct->siguiente;
    }

    if(punteroAnt==NULL){
        raiz=puntero;
    }
    else{
        punteroAnt->siguiente=puntero;
    }
    return puntero;
}

template <typename T,typename K>
void eliminar(NodoLista<T>*& raiz, K v, int (*cmpTK)(T,K)){
    NodoLista<T>* punteroAct=raiz;
    NodoLista<T>* punteroAnt=NULL;
    while(punteroAct!=NULL && cmpTK(punteroAct->info,v)!=0){
        punteroAnt=punteroAct;
        punteroAct=punteroAct->siguiente;
    }
    if(cmpTK(punteroAct->info,v)==0){
        if(punteroAnt==NULL){
            raiz=punteroAct->siguiente;
        }
        else{
            punteroAnt->siguiente=punteroAct->siguiente;
        }
        delete punteroAct;
    }
}

template <typename T>
NodoLista<T>* buscaEInsertaOrdenado(NodoLista<T>*& raiz,T v,bool& enc,int (*cmpTT)(T,T)){
    NodoLista<T>* puntero=buscar<T,T>(raiz,v,cmpTT);
    if(puntero==NULL){
        puntero=insertarOrdenado<T>(raiz,v,cmpTT);
        enc=false;
    }
    else{
        enc=true;
    }
    return puntero;
}

template <typename T>
NodoLista<T>* buscaEInsertaAlPrincipio(NodoLista<T>*& raiz,T v,bool& enc,int (*cmpTT)(T,T)){//agregado por el profesor
    NodoLista<T>* puntero=buscar<T,T>(raiz,v,cmpTT);
    if(puntero==NULL){
        push<T>(raiz,v);
        puntero=raiz;
        enc=false;
    }
    else{
        enc=true;
    }
    return puntero;
}

template <typename T>
void ordenar(NodoLista<T>*& raiz, int (*cmpTT)(T,T)){
    NodoLista<T>* raizAux;
    inicializar<T>(raizAux);
    while(!estaVacia<T>(raiz)){
        T info=pop<T>(raiz);
        insertarOrdenado<T>(raizAux,info,cmpTT);
    }
    raiz=raizAux;
}