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
    int cod;

    cout<<"Ingresa el codigo de materia que quieres consultar: ";
    cin>>cod;

    FILE* archivo = fopen("inscripciones.dat","rb+");
    FILE* archivoRes= fopen("resultados.dat","wb+");

    Boleta b;
    fread(&b,sizeof(Boleta),1,archivo);

    while(!feof(archivo)){
        if(b.codigoMateria==cod){
            fwrite(&b,sizeof(Boleta),1,archivoRes);
        }
        fread(&b,sizeof(Boleta),1,archivo);
    }

    fclose(archivo);
    fclose(archivoRes);

    return 0;
}