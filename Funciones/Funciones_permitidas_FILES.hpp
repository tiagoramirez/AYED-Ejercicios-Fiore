#include <iostream>
#include <stdio.h>
using namespace std;

//Funciones de la pagina 96 del pdf "Material oficial AYED 2014.pdf"

template <typename T>
T read(FILE* f){
    T x;
    fread(&x,sizeof(T),1,f);
    return x;
}

template <typename T>
void write(FILE* f, T v){
    fwrite(&v,sizeof(T),1,f);
}

template <typename T>
long filePos(FILE* f){
    long res=ftell(f);
    return res/sizeof(T);
}

template <typename T>
void seek(FILE* f, int n){
    int posicionLogica=n-1;
    int posicionFisica=posicionLogica*sizeof(T);
    fseek(f,posicionFisica,SEEK_SET);
}

template <typename T>
long fileSize(FILE* f){
    int aux=filePos<T>(f);
    fseek(f,0,SEEK_END);
    int res=filePos<T>(f);
    seek<T>(f,aux+1);
    return res;
}

template <typename T, typename K>
int busquedaBinaria(FILE* f, K v, int (*cmpTK)(T,K)){
    int aux=filePos<T>(f);
    fseek(f,0,SEEK_SET);
    int ret=-1;
    bool enc=false;
    int ini=0;
    int fin=fileSize<T>(f);
    while(!enc and ini<=fin){
        int medio=(ini+fin)/2;
        seek<T>(f,medio);
        T valorFile=read<T>(f);
        if(cmpTK(valorFile,v)==0){
            ret=medio;
            enc=true;
        }else{
            if(cmpTK(valorFile,v)==1){
                fin=medio-1;
            }
            else{
                ini=medio+1;
            }
        }
    }
    seek<T>(f,aux+1);
    return ret;
}