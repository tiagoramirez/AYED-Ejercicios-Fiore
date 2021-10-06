#include <iostream>
#include <stdio.h>
using namespace std;

//Nos dan 2 archivos.
//Archivo 1: legajo, edad, nombre y cantidad de materias aprobadas
//Archivo 2: legajo, materia y nota
//Quiero actualizar el archivo 1 con las materias que aparezcan aprobadas en el archivo 2

struct Alumno{
    int legajo;
    int edad;
    char nombre[51];
    int cantidadMateriasAprobadas;
};

struct AlumnoVec{
    int legajo;
    int posLogicaArchivo;
    int cantidadMateriasAprobadas;
};

struct Examen{
    int legajo;
    char materia[51];
    int nota;
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

void inicializarVector (int& len){
    len=0;
}

template <typename T>
int insertarOrdenado(T arr[], int& len, T v, int (*cmpTT)(T,T)){
    int i=len;
    while(i>0 and cmpTT(v,arr[i-1])==-1){
        arr[i]=arr[i-1];
        i--;
    }
    arr[i]=v;
    len++;
    return i;
}

template<typename T, typename K>
int busquedaBinaria(T a[], int len, K v, int (*cmpTK)(T, K), bool& enc){
    int ret=-1;
    enc=false;
    int ini=0;
    int fin=len-1;
    while(!enc and ini<=fin){
        int medio=(ini+fin)/2;    
        if(cmpTK(a[medio],v)==0){
            ret=medio;
            enc=true;
        }else{
            if(cmpTK(a[medio],v)==1){
                fin=medio-1;
            }
            else{
                ini=medio+1;
            }
        }
    }
    return ret;
}

int cmpAlVecAlVec(AlumnoVec x,AlumnoVec y){
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

int cmpAlVecExamen(AlumnoVec x,Examen y){
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

int main(){
    FILE* archivoA=fopen("Alumnos.dat","rb+");
    Alumno regA=read<Alumno>(archivoA);

    AlumnoVec alumnos[10000];
    int lenAlumnos;
    inicializarVector(lenAlumnos);

    while(!feof(archivoA)){
        AlumnoVec elem;
        elem.legajo=regA.legajo;
        elem.posLogicaArchivo=filePos<Alumno>(archivoA)-1;
        elem.cantidadMateriasAprobadas=regA.cantidadMateriasAprobadas;
        insertarOrdenado<AlumnoVec>(alumnos,lenAlumnos,elem,cmpAlVecAlVec);
        
        regA=read<Alumno>(archivoA);
    }

    fclose(archivoA);

    FILE* archivoE=fopen("Examenes.dat","rb+");

    Examen regE=read<Examen>(archivoE);

    while(!feof(archivoE)){
        if(regE.nota>=6){
            bool enc;
            int pos=busquedaBinaria<AlumnoVec,Examen>(alumnos,lenAlumnos,regE,cmpAlVecExamen,enc);
            alumnos[pos].cantidadMateriasAprobadas++;
        }

        regE=read<Examen>(archivoE);
    }

    fclose(archivoE);

    archivoA=fopen("Alumnos.dat","rb+");

    for(int i=0;i<lenAlumnos;i++){
        seek<Alumno>(archivoA,alumnos[i].posLogicaArchivo);
        Alumno regAActualizar=read<Alumno>(archivoA);
        regAActualizar.cantidadMateriasAprobadas=alumnos[i].cantidadMateriasAprobadas;
        seek<Alumno>(archivoA,alumnos[i].posLogicaArchivo);
        write(archivoA,regAActualizar);
    }
    
    fclose(archivoA);

    return 0;
}