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
