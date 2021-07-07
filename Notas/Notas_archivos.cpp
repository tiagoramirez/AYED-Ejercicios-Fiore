#include <iostream>
#include <stdio.h>//libreria con funciones para tratar los archivos
using namespace std;

int main(){
    FILE* archivo=fopen("datos.dat","wb+");//sintaxis para abrir archivo
    //wb+ ---> crear un archivo nuevo(si ya tengo archivo, me lo pisa y borra todos los datos), puedo leerlo y escribirlo
    //rb+ ---> leer el archivo o escribirlo
    
    int x=5,y=7;

    //fwrite(& variable,sizeof(da el tamaño del tipo de dato),1,variable donde abri el archivo);
    fwrite(&x,sizeof(int),1,archivo);
    fwrite(&y,sizeof(int),1,archivo);

    //cerrar archivo
    fclose(archivo);
    //-----------------------------Leer sabiendo cuantos elementos hay
    archivo=fopen("datos.dat","rb+");
    
    int a,b;
    //fread(& variable,sizeof(da el tamaño del tipo de dato),1,variable donde abri el archivo);
    fread(&a,sizeof(int),1,archivo);
    fread(&b,sizeof(int),1,archivo);

    cout<<a<<endl;
    cout<<b<<endl;

    fclose(archivo);
    //-----------------------------La unica forma para leer sin saber cuantos elementos hay
    archivo=fopen("datos.dat","rb+");
    int z;
    fread(&z,sizeof(int),1,archivo);
    while(!feof(archivo)){//da false si tiene datos, sino da true;
        cout<<z<<endl;
        fread(&z,sizeof(int),1,archivo);
    }

    fclose(archivo);

    return 0;
}