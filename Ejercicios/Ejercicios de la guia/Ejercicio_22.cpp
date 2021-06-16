#include <iostream>
#include <stdio.h>
using namespace std;

struct Boleta{
    int legajo;
    int codigoMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    char nombreYApellido[25];
};

int main(){

    FILE* archivoT=fopen("inscripciones_Totales.dat","rb+");
    FILE* archivoAct=fopen("inscripciones.dat","rb+");

    Boleta b;
    fread(&b,sizeof(Boleta),1,archivoT);
    while(!feof(archivoT)){ //Voy hasta el final del archivo
        fread(&b,sizeof(Boleta),1,archivoT);
    }

    Boleta b2;
    fread(&b2,sizeof(Boleta),1,archivoAct);
    while (!feof(archivoAct)){
        fwrite(&b2,sizeof(Boleta),1,archivoT);
        fread(&b2,sizeof(Boleta),1,archivoAct);
    }
    
    fclose(archivoT);
    fclose(archivoAct);

    return 0;
}