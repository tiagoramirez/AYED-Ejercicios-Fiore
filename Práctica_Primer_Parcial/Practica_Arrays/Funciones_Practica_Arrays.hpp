#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Alumno{
    int legajo;
    char nombreYApellido[101];
    char codigoMateria[6];
};

struct MateriaEInscriptos{
    char codigoMateria[6];
    int cantInscriptos;
};

struct Materia{
    char codigoMateria[6];
};

void inicializarVector (int& len){
    len=0;
}

//Elimina el valor ubicado en la posición pos del array arr, decrementando su longitud len.
template <typename T>
void eliminar(T arr[], int& len, int pos){
    for (int i=pos; i<len-1;i++){//Le puse len-1 porque termina 1 posicion antes
        arr[i]=arr[i+1];
    }
    len--;
}

//Inserta v en un array que esta previamente ordenado y retorna la posicion donde se agrega
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

template <typename T>
int buscaEInsertaOrdenado(T arr[],int& len,T v,bool& enc,int (*cmpTT)(T,T)){
    int pos=busquedaBinaria(arr,len,v,cmpTT,enc);
    if(pos==-1){
        pos=insertarOrdenado(arr,len,v,cmpTT);
    }
    return pos;
}

int cmpAlAlLEG(Alumno x, Alumno y){//Compara alumnos por legajo
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

int cmpMatMat(Materia x, Materia y){
    string primero="";
    string segundo="";
    for(int i=0;x.codigoMateria[i]!='\0';i++){
        primero+=x.codigoMateria[i];
    }
    for(int i=0;y.codigoMateria[i]!='\0';i++){
        segundo+=y.codigoMateria[i];
    }
    if(primero==segundo){
        return 0;
    }
    else{
        if(primero>segundo){
            return 1;
        }
        else{
            return -1;
        }
    }
    
}

int cmpAlAlCODMAT(Alumno x, Alumno y){//Compara alumnos por codigo de materia
    string primero="";
    string segundo="";
    for(int i=0;x.codigoMateria[i]!='\0';i++){
        primero+=x.codigoMateria[i];
    }
    for(int i=0;y.codigoMateria[i]!='\0';i++){
        segundo+=y.codigoMateria[i];
    }
    if(primero==segundo){
        return 0;
    }
    else{
        if(primero>segundo){
            return 1;
        }
        else{
            return -1;
        }
    }
    
}

void mostrarArrayAlumnos(Alumno alumnos[],int len){
    for(int i=0;i<len;i++){
        cout<<"Legajo: "<<alumnos[i].legajo<<"   ";
        cout<<"Nombre y Apellido: "<<alumnos[i].nombreYApellido<<"   ";
        cout<<"Codigo de materia: "<<alumnos[i].codigoMateria<<endl;
    }
}

void mostrarMaterias(Materia x[],int len){
    for(int i=0;i<len;i++){
        cout<<x[i].codigoMateria<<endl;
    }
}

void mostrarAlumno(Alumno x){
    cout<<"Legajo: "<<x.legajo<<"   ";
    cout<<"Nombre y Apellido: "<<x.nombreYApellido<<"   ";
    cout<<"Codigo de materia: "<<x.codigoMateria<<endl;    
}

void ingresarAlumno(Alumno &x){
    cout<<"Ingresa legajo: ";
    cin>>x.legajo;
    if(x.legajo!=0){
        cout<<"Ingresa nombre y apellido: ";
        cin>>x.nombreYApellido;
        cout<<"Ingresa codigo de materia: ";
        cin>>x.codigoMateria;
    }
}

bool esAlumnoValido(Alumno x){
    if(x.legajo==0){
        return false;
    }
    else{
        return true;
    }
}

void mostrarArrayMateriaEInscriptos(MateriaEInscriptos x[],int len){
    for(int i=0;i<len;i++){
        cout<<"Materia "<<x[i].codigoMateria<<" tiene "<<x[i].cantInscriptos<<" inscriptos."<<endl;
    }
}