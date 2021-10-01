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
void ordenar(T arr[], int len, int (*cmpTT)(T,T)){
    T aux;
    for (int i=0;i<len-1;i++){
        for(int x=0;x<len-1;x++){
            if(cmpTT(arr[x],arr[x+1])==1){//veo si el primero es mas grande que el segundo
                aux=arr[x];
                arr[x]=arr[x+1];
                arr[x+1]=aux;
            }
        }
    }
}

template <typename T>
void ordenar2(T arr[], int len, int (*cmpTT)(T,T)){//ordenar optimizado
    T aux;
    bool hayCambio=true;
    int i=0;
    while(hayCambio and i<len-1){
        hayCambio=false;
        for(int x=0;x<len-1-i;x++){
            if(cmpTT(arr[x],arr[x+1])==1){//veo si el primero es mas grande que el segundo
                aux=arr[x];
                arr[x]=arr[x+1];
                arr[x+1]=aux;
                hayCambio=true;
            }
        }
        i++;
    }
}

//Inserta v en un array que esta previamente ordenado y retorna la posicion donde se agrega
template <typename T>
int insertarOrdenado(T arr[], int& len, T v, int (*cmpTT)(T,T)){
    int i=len;
    while(i>0 and cmpTT(v,arr[i-1])==-1){
        arr[i]=arr[i-1];
        i--;
    }
    arr[i]=v;
    len++;
    return i;
}

template<typename T, typename K>
int busquedaBinaria(T a[], int len, K v, int (*cmpTK)(T, K), bool& enc){
    int ret=-1;
    enc=false;
    int ini=0;
    int fin=len-1;
    while(!enc and ini<=fin){
        int medio=(ini+fin)/2;    
        if(cmpTK(a[medio],v)==0){
            ret=medio;
            enc=true;
        }else{
            if(cmpTK(a[medio],v)==1){
                fin=medio-1;
            }
            else{
                ini=medio+1;
            }
        }
    }

    return ret;
}

template <typename T>
int buscaEInsertaOrdenado(T arr[],int& len,T v,bool& enc,int (*cmpTT)(T,T)){
    int pos=busquedaBinaria(arr,len,v,cmpTT,enc);
    if(pos==-1){
        pos=insertarOrdenado(arr,len,v,cmpTT);
    }
    return pos;
}

//agrega al final. No esta en la guia, lo hizo el profesor.
template <typename T>
int buscaYAgrega(T arr[],int& len,T v,bool& enc,int (*cmpTT)(T,T)){
    int pos=buscar(arr,len,v,cmpTT);
    if(pos==-1){
        agregar(arr,len,v);
        pos=len-1;
        enc=false;
    }
    else{
        enc=true;
    }
    return pos;
}