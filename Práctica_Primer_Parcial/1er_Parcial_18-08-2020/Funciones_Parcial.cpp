#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// Inicio Punto 1

struct Usuario{
    int idUsuario;
    char nombreUsuario[101];
};

struct Llamada{
    int idUsuario;
    float duracionLLamada;
};

struct UsuarioTotales{
    int idUsuario;
    float totalMinutos=0;
    char nombreUsuario[101];
    unsigned cantTotalLLamadas=0;
    float totalAbonar=0;
};

// Fin Punto 1

// Inicio Punto 2

void agregar(UsuarioTotales arr[], int& len, UsuarioTotales v){
    arr[len]=v;
    len++;
}

int buscar(UsuarioTotales arr[], int len, int idUsuario){
    int pos=-1;
    int i=0;
    while(pos==-1 and i<len){
        if(arr[i].idUsuario==idUsuario){//veo si son iguales los valores
            pos=i;
        }
        i++;
    }
    return pos;
}

// Fin Punto 2

// Inicio Punto 3

void cargarUsuarios(UsuarioTotales arr[],int& len){
    FILE* archivo=fopen("Usuarios.dat","rb+");
    Usuario elem;
    fread(&elem,sizeof(Usuario),1,archivo);
    while(!feof(archivo)){
        arr[len].idUsuario=elem.idUsuario;
        strcpy(elem.nombreUsuario,arr[len].nombreUsuario);
        len++;
        fread(&elem,sizeof(Usuario),1,archivo);
    }
    fclose(archivo);
}

// Fin Punto 3

// Inicio Punto 4

float obtenerPrecio(float minutos);

void cargarLLamadas(UsuarioTotales arr[], int len){
    FILE* archivo=fopen("Llamadas.dat","rb+");
    Llamada elem;
    fread(&elem,sizeof(Llamada),1,archivo);
    int pos;
    while(!feof(archivo)){
        pos=buscar(arr,len,elem.idUsuario);
        arr[pos].cantTotalLLamadas++;
        arr[pos].totalMinutos+=elem.duracionLLamada;
        arr[pos].totalAbonar+=obtenerPrecio(elem.duracionLLamada);
    }
    fclose(archivo);
}

// Fin Punto 4

// Inicio Punto 5

void mostrarLlamadas(UsuarioTotales arr[], int len){
    for(int i=0;i<len;i++){
        if(arr[i].cantTotalLLamadas!=0){
            cout<<"Id de Usuario " <<arr[i].idUsuario<<" debe abonar "<<arr[i].totalAbonar<<endl;
        }
    }
}

// Fin Punto 5