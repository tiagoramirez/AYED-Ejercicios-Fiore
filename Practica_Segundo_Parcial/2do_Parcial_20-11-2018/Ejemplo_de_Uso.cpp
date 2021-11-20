#include "Funciones_Parcial.hpp"

template <typename T>
void push(Nodo<T>*& raiz, T v){
    Nodo<T>* puntero=new Nodo<T>();
    puntero->info=v;
    puntero->siguiente=raiz;
    raiz=puntero;
}

int main(){
    Like l1={23,"Tiago",2,'A'};
    Like l2={2,"Roman",3,'A'};
    Like l3={5,"Juan",7,'A'};
    Like l4={7,"Mara",9,'A'};
    Like l5={1,"Saul",11,'A'};
    Like l6={80,"Pepito",22,'A'};
    Like l7={20,"PapaNoel",11,'B'};
    Nodo<Like>* raizPilaLikes=NULL;
    push<Like>(raizPilaLikes,l1);
    push<Like>(raizPilaLikes,l2);
    push<Like>(raizPilaLikes,l3);
    push<Like>(raizPilaLikes,l4);
    push<Like>(raizPilaLikes,l5);
    push<Like>(raizPilaLikes,l6);
    push<Like>(raizPilaLikes,l7);

    FanPage fanpages[500];
    CargarLikes(raizPilaLikes,fanpages);
    mostrarCantidades(fanpages);
}