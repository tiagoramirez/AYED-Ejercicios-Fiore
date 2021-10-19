#include "Funciones_permitidas_PILAS.hpp"

struct Alumno{
    char nombre[51];
    int edad;
    int legajo;
};

int main(){
    NodoPila<Alumno>* raizPila;
    inicializar<Alumno>(raizPila);

    FILE* archivo=fopen("alumnos.dat","rb+");
    Alumno reg;
    fread(&reg,sizeof(Alumno),1,archivo);

    while(!feof(archivo)){
        push<Alumno>(raizPila,reg);
        fread(&reg,sizeof(Alumno),1,archivo);
    }

    fclose(archivo);

    while(!estaVacia<Alumno>(raizPila)){
        Alumno alumno=pop<Alumno>(raizPila);
        cout<<alumno.nombre<<", "<<alumno.edad<<", " <<alumno.legajo<<endl;
    }
    
    return 0;
}