#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// Inicio Punto 1

struct Venta{
    int codE;
    char idSuc[3];
    unsigned int cantidadVendida;
    int fecha;
};

struct Electro{
    int codE;
    char nombre[51];
    char descripcion[501];
    float precio;
};

struct ElectroAgg{
    int codE;
    unsigned int cantidadTotalVendida;
};

// Fin Punto 1

// Inicio Punto 2

// Uso busqueda binaria porque es el mas performante que puedo elegir. Esto es asi porque al ir dividiendo el vector en varias partes, haciendose cada vez mas chico, tengo menos lugar donde buscar.
// Podemos usar busqueda binaria porque el array esta ordenado por el campo que quiero buscar. Y la estructura permite acceso directo a sus elementos.
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

int cmpElectroCodigo(Electro electrodomestico, int codigoElectrodomestico){
    if(electrodomestico.codE==codigoElectrodomestico){
        return 0;
    }
    else{
        if(electrodomestico.codE>codigoElectrodomestico){
            return 1;
        }
        else{
            return -1;
        }
    }
}

float obtenerPrecioElectro(Electro electrodomesticos[],int codElectro){
    bool enc;
    int pos=busquedaBinaria<Electro,int>(electrodomesticos,500,codElectro,cmpElectroCodigo,enc);
    return electrodomesticos[pos].precio;
}

// Fin Punto 2

// Inicio Punto 3

void ordenar(ElectroAgg electrodomesticos[], int len){
    ElectroAgg aux;
    bool hayCambio=true;
    int i=0;
    while(hayCambio and i<len-1){
        hayCambio=false;
        for(int x=0;x<len-1-i;x++){
            if(electrodomesticos[x].codE>electrodomesticos[x+1].codE){
                aux=electrodomesticos[x];
                electrodomesticos[x]=electrodomesticos[x+1];
                electrodomesticos[x+1]=aux;
                hayCambio=true;
            }
        }
        i++;
    }
}

// Fin Punto 3

// Inicio Punto 4

template <typename T>
int buscaEInsertaOrdenado(T arr[],int& len,T v,bool& enc,int (*cmpTT)(T,T)){
    int pos=busquedaBinaria(arr,len,v,cmpTT,enc);
    if(pos==-1){
        pos=insertarOrdenado(arr,len,v,cmpTT);
    }
    return pos;
}

int cmpElectroAgg(ElectroAgg x,ElectroAgg y){
    if(x.codE==y.codE){
        return 0;
    }
    else{
        if(x.codE>y.codE){
            return 1;
        }
        else{
            return -1;
        }
    }
}

void cargarVentasAgrupadasPorElectro(ElectroAgg vecE[],int& len, char nombreArchivo[]){
    FILE* archivo=fopen(nombreArchivo,"rb+");
    Venta regVenta;
    fread(&regVenta,sizeof(Venta),1,archivo);

    while(!feof(archivo)){
        ElectroAgg elem;
        elem.codE=regVenta.codE;
        elem.cantidadTotalVendida=0;
        bool enc;
        int pos=buscaEInsertaOrdenado(vecE,len,elem,enc,cmpElectroAgg);
        vecE[pos].cantidadTotalVendida+=regVenta.cantidadVendida;
        fread(&regVenta,sizeof(Venta),1,archivo);
    }

    fclose(archivo);
    ordenar(vecE,len);
}

// Fin Punto 4

// Inicio Punto 5

void mostrarReporte(ElectroAgg vecE[],int len, Electro electrodomesticos[]){
    cout<<"Ventas Mensuales"<<endl;
    cout<<"Codigo de electrodomestico    |    Cantidad total por electro"<<endl;
    for(int i=0;i<len;i++){
        if(obtenerPrecioElectro(electrodomesticos,vecE[i].codE)>5000){
            cout<<vecE[i].codE<<"    |    "<<vecE[i].cantidadTotalVendida<<endl;
        }
    }
}

// Fin Punto 5