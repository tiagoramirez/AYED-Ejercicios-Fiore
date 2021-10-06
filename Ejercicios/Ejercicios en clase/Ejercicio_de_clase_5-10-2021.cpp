#include <iostream>
#include <stdio.h>
using namespace std;

//Nos dan 1 archivo.
//Archivo: legajo, edad, nombre y cantidad de materias aprobadas
//Quiero sumar 1 al legajo si la funcion bool yaCumplioAnios(int fecha) devuelve true

struct Alumno{
    int legajo;
    int edad;
    char nombre[51];
    int fechaNacimiento;
};

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

bool yaCumplioAnios(int fecha){
    return true;
}

int main(){
    FILE* archivo=fopen("alumnos.dat","rb+");
    Alumno reg=read<Alumno>(archivo);

    while(!feof(archivo)){
        if(yaCumplioAnios(reg.fechaNacimiento)){
            reg.edad=reg.edad+1;
            int pos=filePos<Alumno>(archivo);
            seek<Alumno>(archivo,pos-1);
            write<Alumno>(archivo,reg);
        }
        reg=read<Alumno>(archivo);
    }

    fclose(archivo);

    return 0;
}