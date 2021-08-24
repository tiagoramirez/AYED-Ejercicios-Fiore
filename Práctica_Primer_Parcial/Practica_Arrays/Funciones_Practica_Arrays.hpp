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
    int cantInscriptos=1;
};

struct Materia{
    char codigoMateria[6];
};

struct DatosMaterias{
    char codigoMateria[6];
    char nombreMateria[51];
};

void inicializarVector (int& len){
    len=0;
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

template <typename T>
void ordenar(T arr[], int len, int (*cmpTT)(T,T)){//ordenar optimizado
    T aux;
    bool hayCambio=true;
    int i=0;
    while(hayCambio and i<len-1){
        hayCambio=false;
        for(int x=0;x<len-1-i;x++){
            if(cmpTT(arr[x],arr[x+1])==1){//veo si el primero es mas grande que el segundo
                aux=arr[x];
                arr[x]=arr[x+1];
                arr[x+1]=aux;
                hayCambio=true;
            }
        }
        i++;
    }
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

int cmpMatInscMatInsc2(MateriaEInscriptos x, MateriaEInscriptos y){
    if(x.cantInscriptos==y.cantInscriptos){
        return 0;
    }
    else{
        if(x.cantInscriptos>y.cantInscriptos){
            return -1;
        }
        else{
            return 1;
        }
    }
}

int cmpMatInscMatInsc(MateriaEInscriptos x, MateriaEInscriptos y){
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

void mostrarDatosMaterias(DatosMaterias x){
    cout<<"Codigo de materia: "<<x.codigoMateria<<"   ";
    cout<<"Nombre de materia: "<<x.nombreMateria<<endl;
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

void ingresarMateria(DatosMaterias &x){
    cout<<"Ingresa codigo de materia: ";
    cin>>x.codigoMateria;
    if(x.codigoMateria[0]!='\0'){
        cout<<"Ingresa el nombre de la materia: ";
        cin>>x.nombreMateria;
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

bool esMateriaValida(DatosMaterias x){
    if(x.codigoMateria[0]=='\0'){
        return false;
    }
    else{
        return true;
    }
}