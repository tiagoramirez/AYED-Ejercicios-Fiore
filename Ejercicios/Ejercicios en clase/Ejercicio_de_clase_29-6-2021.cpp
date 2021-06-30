#include <iostream>
#include <stdio.h>
using namespace std;

//Leyendo un archivo numeros.dat que contiene en cada registro un numero entero diferente, tomarlos y guardarlos en un array
//Se sabe que el archivo tiene como maximo 200 numeros.

void inicializarVector(int& len){
    len=0;
}

void agregar(int numeros[], int& len, int numero){
    numeros[len]=numero;
    len++;
}

int main(){
    FILE* archivo = fopen("numeros.dat","rb+");

    int numero;
    int numeros[200];
    int len;
    inicializarVector(len);

    fread(&numero,sizeof(int),1,archivo);
    while(!feof(archivo)){
        agregar(numeros,len,numero);
        fread(&numero,sizeof(int),1,archivo);
    }

    fclose(archivo);

    return 0;
}