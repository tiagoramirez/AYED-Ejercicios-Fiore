#include "Funciones_permitidas_LISTAS.hpp"
#include <string.h>

struct Alumno{
    char nombre[51];
    int edad;
    int legajo;
};

struct Materia{
    int legajo;
    char codigoMateria[5+1];
    char nombreMateria[50+1];
};

struct AlumnoMat{
    char nombre[51];
    int legajo;
    int cantidadMaterias;
};

int cmpAlAl(AlumnoMat x,AlumnoMat y){
    if(x.legajo==y.legajo){
        return 0;
    }
    else{
        if(x.legajo>y.legajo){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int cmpAlLeg(AlumnoMat x,int leg){
    if(x.legajo==leg){
        return 0;
    }
    else{
        if(x.legajo>leg){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int cmpAlAl2(AlumnoMat x, AlumnoMat y){
    if(x.cantidadMaterias==y.cantidadMaterias){
        return 0;
    }
    else{
        if(x.cantidadMaterias>y.cantidadMaterias){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    NodoLista<AlumnoMat>* raiz;
    inicializar(raiz);

    FILE* archivoAlumnos=fopen("alumnos.dat","rb+");
    Alumno alumno;
    fread(&alumno,sizeof(Alumno),1,archivoAlumnos);
    while(!feof){
        AlumnoMat alumnoASubir;
        alumnoASubir.legajo=alumno.legajo;
        strcpy(alumno.nombre,alumnoASubir.nombre);
        alumnoASubir.cantidadMaterias=0;

        insertarOrdenado<AlumnoMat>(raiz,alumnoASubir,cmpAlAl);
        fread(&alumno,sizeof(Alumno),1,archivoAlumnos);
    }

    fclose(archivoAlumnos);


    FILE* archivoMaterias=fopen("materias.dat","rb+");
    Materia materia;
    fread(&materia,sizeof(Materia),1,archivoMaterias);
    while(!feof){
        NodoLista<AlumnoMat>* puntero=buscar<AlumnoMat,int>(raiz,materia.legajo,cmpAlLeg);
        puntero->info.cantidadMaterias++;

        fread(&materia,sizeof(Materia),1,archivoMaterias);
    }

    fclose(archivoMaterias);

    NodoLista<AlumnoMat>* punteroAux=raiz;
    cout<<"Alumnos"<<endl;
    cout<<"Legajo | Nombre | Cantidad"<<endl;
    while(punteroAux!=NULL){
        cout<<punteroAux->info.legajo<<"|"<<punteroAux->info.nombre<<"|"<<punteroAux->info.cantidadMaterias<<endl;
        punteroAux=punteroAux->siguiente;
    }

    ordenar<AlumnoMat>(raiz,cmpAlAl2);

    NodoLista<AlumnoMat>* punteroAux=raiz;
    cout<<"Alumnos"<<endl;
    cout<<"Legajo | Nombre | Cantidad"<<endl;
    while(punteroAux!=NULL){
        cout<<punteroAux->info.legajo<<"|"<<punteroAux->info.nombre<<"|"<<punteroAux->info.cantidadMaterias<<endl;
        punteroAux=punteroAux->siguiente;
    }

    liberar<AlumnoMat>(raiz);

    return 0;
}