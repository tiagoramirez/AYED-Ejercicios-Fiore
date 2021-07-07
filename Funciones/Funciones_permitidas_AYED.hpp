#include <iostream>
using namespace std;

//Funciones de la pagina 93 del pdf "Material oficial AYED 2014.pdf"

void inicializarVector (int& len){
    len=0;
}

template <typename T>
void agregar(T arr[], int& len, T v){
    arr[len]=v;
    len++;
}

//retorna la posicion, o -1 si no lo tiene
template <typename T, typename K> 
int buscar(T arr[], int len, K v, int (*cmpTK)(T,K)){
    int pos=-1;
    int i=0;
    while(pos==-1 and i<len){
        if(cmpTK(arr[i],v)==0){//veo si son iguales los valores
            pos=i;
        }
        i++;
    }
    return pos;
}