#include <iostream>
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
void push(NodoLista<T>*& raiz, T v){
    NodoLista<T>* puntero=new NodoLista<T>();
    puntero->info=v;
    puntero->siguiente=raiz;
    raiz=puntero;
}

template <typename T>
NodoLista<T>* interseccion(NodoLista<T>* raiz1,NodoLista<T>* raiz2){
    NodoLista<T>* pAux1=raiz1;
    NodoLista<T>* pAux2=raiz2;
    NodoLista<T>* raizRet;
    inicializar<T>(raizRet);
    while (pAux1!= NULL && pAux2!=NULL)
    {
        if(pAux1->info==pAux2->info){
            push(raizRet,pAux1->info);
            pAux1=pAux1->siguiente;
            pAux2=pAux2->siguiente;
        }
        else{
            if(pAux1->info<pAux2->info){
                pAux1=pAux1->siguiente;
            }
            else{
                if(pAux1->info>pAux2->info){
                    pAux2=pAux2->siguiente;
                }
            }
        }
    }
    return raizRet;
}

template <typename T>
NodoLista<T>* unionElementos(NodoLista<T>* listaA, NodoLista<T>* listaB) {
	NodoLista<T>* listaResultado;
	inicializar(listaResultado);

	NodoLista<T>* pAuxA = listaA;
	NodoLista<T>* pAuxB = listaB;

	while(pAuxA != NULL && pAuxB != NULL) {
		if (pAuxA -> info < pAuxB -> info) {
			push(listaResultado, pAuxA -> info);
			pAuxA = pAuxA -> siguiente;
		} else if (pAuxA -> info > pAuxB -> info) {
			push(listaResultado, pAuxB -> info);
			pAuxB = pAuxB -> siguiente;
		} else {
			push(listaResultado, pAuxA -> info);
			pAuxA = pAuxA -> siguiente;
			pAuxB = pAuxB -> siguiente;
		}
	}

	if(pAuxA != NULL) {
		while (pAuxA != NULL) {
			push(listaResultado, pAuxA -> info);
			pAuxA = pAuxA -> siguiente;
		}
	} else {
		while (pAuxB != NULL) {
			push(listaResultado, pAuxB -> info);
			pAuxB = pAuxB -> siguiente;
		}
	}

	return listaResultado;
}

// XOR
template <typename T>
NodoLista<T>* unionExclusiva(NodoLista<T>* listaA, NodoLista<T>* listaB) {
	NodoLista<T>* listaResultado;
	inicializar(listaResultado);

	NodoLista<T>* pAuxA = listaA;
	NodoLista<T>* pAuxB = listaB;

	while(pAuxA != NULL && pAuxB != NULL) {
		if (pAuxA -> info < pAuxB -> info) {
			push(listaResultado, pAuxA -> info);
			pAuxA = pAuxA -> siguiente;
		} else if (pAuxA -> info > pAuxB -> info) {
			push(listaResultado, pAuxB -> info);
			pAuxB = pAuxB -> siguiente;
		} else {
			pAuxA = pAuxA -> siguiente;
			pAuxB = pAuxB -> siguiente;
		}
	}

	if(pAuxA != NULL) {
		while (pAuxA != NULL) {
			push(listaResultado, pAuxA -> info);
			pAuxA = pAuxA -> siguiente;
		}
	} else {
		while (pAuxB != NULL) {
			push(listaResultado, pAuxB -> info);
			pAuxB = pAuxB -> siguiente;
		}
	}

	return listaResultado;
}
