#include "Funciones_permitidas_COLAS.hpp"

struct Alumno{
    char nombre[51];
    int edad;
    int legajo;
};

int main(){
    NodoCola<Alumno>* colaFrente;
    NodoCola<Alumno>* colaFin;

    inicializar<Alumno>(colaFrente);
    inicializar<Alumno>(colaFin);

    FILE* archivo=fopen("alumnos.dat","rb+");
    Alumno reg;
    fread(&reg,sizeof(Alumno),1,archivo);

    while(!feof(archivo)){
        encolar<Alumno>(colaFrente,colaFin,reg);
        fread(&reg,sizeof(Alumno),1,archivo);
    }

    fclose(archivo);

    while(!estaVacia<Alumno>(colaFrente)){
        Alumno alumno=desencolar<Alumno>(colaFrente,colaFin);
        cout<<alumno.nombre<<", "<<alumno.edad<<", " <<alumno.legajo<<endl;
    }
    
    return 0;
}