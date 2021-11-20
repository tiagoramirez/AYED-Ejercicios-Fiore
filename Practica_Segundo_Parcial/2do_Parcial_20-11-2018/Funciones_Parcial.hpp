#include <iostream>
#include <string.h>
using namespace std;

// Punto 1:

template <typename T>
struct Nodo{
    T info;
    Nodo<T>* siguiente;
};

struct Like{
    int idUsuario;
    char nombreUsuario[251];
    int idFanPage;
    char codigoPost[11];
};

struct Usuario{
    int idUsuario;
    int cantidadLikesAFanpage=0;
    char nombreUsuario[251];
};

struct FanPage{
    int cantidadLikes=0;
    Nodo<Usuario>* usuarios=NULL;
};

// Punto 2:

template <typename T>
T pop(Nodo<T>*& raiz){
    Nodo<T>* puntero=raiz;
    T info=puntero->info;
    raiz=puntero->siguiente;
    delete puntero;
    return info;
}

template <typename T>
void liberar(Nodo<T>*& raiz){
    while(raiz!=NULL){
        pop<T>(raiz);
    }
}

// Punto 3:

template <typename T, typename K>
Nodo<T>* buscar(Nodo<T>* raiz, K v, int (*cmpTK)(T,K)){
    Nodo<T>* punteroAux=raiz;
    Nodo<T>* punteroANodoEncontrado=NULL;
    while(punteroAux!=NULL && punteroANodoEncontrado==NULL){
        if(cmpTK(punteroAux->info,v)==0){
            punteroANodoEncontrado=punteroAux;
        }
        punteroAux=punteroAux->siguiente;
    }
    return punteroANodoEncontrado;
}

template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& raiz, T v, int (*cmpTT)(T,T)){
    Nodo<T>* puntero=new Nodo<T>();
    puntero->info=v;
    Nodo<T>* punteroAct=raiz;
    Nodo<T>* punteroAnt=NULL;
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
Nodo<T>* buscaEInsertaOrdenado(Nodo<T>*& raiz,T v,bool& enc,int (*cmpTT)(T,T)){
    Nodo<T>* puntero=buscar<T,T>(raiz,v,cmpTT);
    if(puntero==NULL){
        puntero=insertarOrdenado<T>(raiz,v,cmpTT);
        enc=false;
    }
    else{
        enc=true;
    }
    return puntero;
}

int cmpUsuUsu(Usuario x,Usuario y){
    return x.idUsuario-y.idUsuario;
}

void CargarLikes(Nodo<Like>*& raizPilaLikes,FanPage fanpages[]){
    while (raizPilaLikes!=NULL){
        Like like=pop<Like>(raizPilaLikes);

        Usuario usuarioACargar;
        usuarioACargar.idUsuario=like.idUsuario;
        usuarioACargar.cantidadLikesAFanpage=1;
        strcpy(usuarioACargar.nombreUsuario,like.nombreUsuario);

        bool enc;
        Nodo<Usuario>* pos=buscaEInsertaOrdenado<Usuario>(fanpages[like.idFanPage-1].usuarios,usuarioACargar,enc,cmpUsuUsu);
        
        fanpages[like.idFanPage-1].cantidadLikes++;

        if(enc){
            pos->info.cantidadLikesAFanpage++;
        }
    }
}

// Punto 4:

int contarUsuarios(Nodo<Usuario>* raizListaUsuarios){
    int ret=0;
    Nodo<Usuario>* pAux=raizListaUsuarios;
    while (pAux!=NULL)
    {
        ret++;
        pAux=pAux->siguiente;
    }
    return ret;
}

// Punto 5:

void mostrarCantidades(FanPage fanpages[]){
    for(int i=0;i<500;i++){
        int cantidadUsuarios=contarUsuarios(fanpages[i].usuarios);
        cout<<"Id Fanpage "<<i+1<<" --- "<<"Cantidad de usuarios: "<<cantidadUsuarios<<endl;
        liberar<Usuario>(fanpages[i].usuarios);
    }
}