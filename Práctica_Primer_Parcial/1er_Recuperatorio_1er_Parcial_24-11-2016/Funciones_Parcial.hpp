#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


// Inicio Punto 1

struct Aerolinea{
    char codigoAerolinea[7];
    char nombreAerolinea[51];
};

struct AerolineasYVentas{
    char codigoAerolinea[7];
    char nombreAerolinea[51];
    int cantidadPasajesVendidos=0;
};

// Fin Punto 1

// Inicio Punto 2

// Podemos usar busqueda binaria solo si el array esta ordenado por el campo que quiero buscar y la estructura tiene que permitir acceso directo a sus elementos.
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

// Fin Punto 2

// Inicio Punto 3

bool obtenerSiguienteAerolinea(Aerolinea& aerolinea){}

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

int cmpAeroAero(AerolineasYVentas x,AerolineasYVentas y){
    string primero="";
    string segundo="";
    for(int i=0;x.codigoAerolinea[i]!='\0';i++){
        primero+=x.codigoAerolinea[i];
    }
    for(int i=0;y.codigoAerolinea[i]!='\0';i++){
        segundo+=y.codigoAerolinea[i];
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

void cargarAerolineas(AerolineasYVentas aerolineas[],int &len){
    Aerolinea elemAConvertir;
    bool enc=obtenerSiguienteAerolinea(elemAConvertir);
    AerolineasYVentas elem;
    strcpy(elemAConvertir.codigoAerolinea,elem.codigoAerolinea);
    strcpy(elemAConvertir.nombreAerolinea,elem.nombreAerolinea);
    while(enc){
        insertarOrdenado(aerolineas,len,elem,cmpAeroAero);
        bool enc=obtenerSiguienteAerolinea(elemAConvertir);
        strcpy(elemAConvertir.codigoAerolinea,elem.codigoAerolinea);
        strcpy(elemAConvertir.nombreAerolinea,elem.nombreAerolinea);
    }
}

// Fin Punto 3

// Inicio Punto 4

int cmpAeroCodigoAero(AerolineasYVentas x,char y[]){
    string primero="";
    string segundo="";
    for(int i=0;x.codigoAerolinea[i]!='\0';i++){
        primero+=x.codigoAerolinea[i];
    }
    for(int i=0;y[i]!='\0';i++){
        segundo+=y[i];
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

void cargarPasajes(AerolineasYVentas aerolineas[],int len){
    char codigoAerolinea[7];
    cout<<"Ingresa codigo de aerolinea: ";
    cin >>codigoAerolinea;
    char codigoPasaje[11];
    cout<<"Ingresa el codigo del pasaje: ";
    cin>>codigoPasaje;
    while(codigoAerolinea[0]!='\0'){
        bool enc;
        int pos;
        //Uso busqueda binaria porque aerolineas esta ordenado por codigo de aerolinea que es el campo que voy a estar utilizando para buscar
        pos=busquedaBinaria(aerolineas,len,codigoAerolinea,cmpAeroCodigoAero,enc);
        aerolineas[pos].cantidadPasajesVendidos++;
        cout<<"Ingresa codigo de aerolinea: ";
        cin >>codigoAerolinea;
        cout<<"Ingresa el codigo del pasaje: ";
        cin>>codigoPasaje;
    }
}

// Fin Punto 4

// Inicio Punto 5

int minVuelosVendidos(AerolineasYVentas aerolineas[],int len,char codigoAerolineaMin[]){
    int min;
    int posMin;
    bool esPrimero=true;
    for(int i=0;i<len;i++){
        if(aerolineas[i].cantidadPasajesVendidos<min or esPrimero){
            min=aerolineas[i].cantidadPasajesVendidos;
            posMin=i;
            esPrimero=false;
        }
    }
    strcpy(aerolineas[posMin].codigoAerolinea,codigoAerolineaMin);
    return posMin;
}

// Fin Punto 5