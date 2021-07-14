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

//Elimina el valor ubicado en la posición pos del array arr, decrementando su longitud len.
template <typename T>
void eliminar(T arr[], int& len, int pos){
    for (int i=pos; i<len-1;i++){//Le puse len-1 porque termina 1 posicion antes
        arr[i]=arr[i+1];
    }
    len--;
}

template <typename T>
void ordenar(T arr[], int len, int (*cmpTK)(T,T)){
    T aux;
    for (int i=0;i<len-1;i++){
        for(int x=0;x<len-1;x++){
            if(cmpTK(arr[x],arr[x+1])==1){//veo si el primero es mas grande que el segundo
                aux=arr[x];
                arr[x]=arr[x+1];
                arr[x+1]=aux;
            }
        }
    }
}