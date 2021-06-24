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
    FILE* archivo=fopen("inscripciones.dat","rb+");
    Boleta b;

    fread(&b,sizeof(Boleta),1,archivo);
    while(!feof(archivo)){
        cout<<"Legajo:"<<b.legajo<<endl;
        cout<<"Codigo de materia:"<<b.codigoMateria<<endl;
        cout<<"Dia del examen:"<<b.diaExamen<<endl;
        cout<<"Mes del examen:"<<b.mesExamen<<endl;
        cout<<"Anio del examen:"<<b.anioExamen<<endl;
        cout<<"Nombre y apellido:"<<b.nombreYApellido<<endl;
        fread(&b,sizeof(Boleta),1,archivo);    
    }
    
    fclose(archivo);
}