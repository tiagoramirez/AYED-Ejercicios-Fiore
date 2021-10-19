#include <iostream>
using namespace std;

//Funciones de la pagina 95 del pdf "Material oficial AYED 2014.pdf"

template <typename T>
void push(Nodo<T>*& p, T v);

template <typename T>
T pop(Nodo<T>*& p);


template <typename T>
struct NodoPila{
    T info;
    NodoPila<T>* siguiente;
};

template <typename T>
void inicializar(NodoPila<T>*& raiz){
    raiz=NULL;
}

template <typename T>
bool estaVacia(NodoPila<T>* raiz){
    return raiz==NULL;
}

template <typename T>
void push(NodoPila<T>*& raiz, T v){
    NodoPila<T>* puntero=new NodoPila();
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

