#include "Funciones_Final.hpp"

template <typename T>
bool estaVacia(NodoLista<T>*& raiz){
    return raiz==NULL;
}

template <typename T>
T pop(NodoLista<T>*& raiz){
    NodoLista<T>* puntero=raiz;
    T info=puntero->info;
    raiz=puntero->siguiente;
    delete puntero;
    return info;
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

int main(){
    NodoLista<char>* raizLista1;
    NodoLista<char>* raizLista2;

    inicializar<char>(raizLista1);
    inicializar<char>(raizLista2);

    agregar<char>(raizLista1,'A');
    agregar<char>(raizLista1,'B');
    agregar<char>(raizLista1,'C');
    agregar<char>(raizLista1,'I');
    agregar<char>(raizLista1,'J');
    agregar<char>(raizLista1,'T');

    agregar<char>(raizLista2,'A');
    agregar<char>(raizLista2,'B');
    agregar<char>(raizLista2,'C');
    agregar<char>(raizLista2,'D');
    agregar<char>(raizLista2,'E');
    agregar<char>(raizLista2,'J');
    agregar<char>(raizLista2,'K');
    agregar<char>(raizLista2,'T');

    cout<<"Interseccion: "<<endl;

    NodoLista<char>* resultado= interseccion<char>(raizLista1,raizLista2);

    while(!estaVacia(resultado)){
        cout<<pop<char>(resultado)<<endl;
    }

    cout<<"Union: "<<endl;

    NodoLista<char>* resultado2= unionElementos<char>(raizLista1,raizLista2);

    while(!estaVacia(resultado2)){
        cout<<pop<char>(resultado2)<<endl;
    }

    cout<<"XOR: "<<endl;

    NodoLista<char>* resultado3= unionExclusiva<char>(raizLista1,raizLista2);

    while(!estaVacia(resultado3)){
        cout<<pop<char>(resultado3)<<endl;
    }

    return 0;
}