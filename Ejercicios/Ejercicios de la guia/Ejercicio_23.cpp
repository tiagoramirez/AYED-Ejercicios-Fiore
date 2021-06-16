#include <iostream>
#include <stdio.h>
using namespace std;

struct Boleta{
    int legajo;
    int codigoMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    char nombreYApellido[25];
};

int main(){
    
    FILE* archivo=fopen("inscripciones.dat","wb+");

    Boleta boleta;
    int contAnt=0;
    cout<<"Ingresa el legajo: ";
    cin>>boleta.legajo;
    while(boleta.legajo!=0){
        cout<<"Ingresa el codigo de materia: ";
        cin>>boleta.codigoMateria;
        cout<<"Ingresa el dia del examen: ";
        cin>>boleta.diaExamen;
        cout<<"Ingresa el mes del examen: ";
        cin>>boleta.mesExamen;
        cout<<"Ingresa el anio del examen: ";
        cin>>boleta.anioExamen;
        cout<<"Ingresa nombre y apellido: ";
        cin>>boleta.nombreYApellido;
        
        fwrite(&boleta,sizeof(Boleta),1,archivo);

        cout<<"Ingresa otro legajo: ";
        cin>>boleta.legajo;
    }

    fclose(archivo);

    cout<<"Contenido del archivo: "<<endl;

    archivo=fopen("inscripciones.dat","rb+");

    Boleta b;
    fread(&b,sizeof(Boleta),1,archivo);
    while(!feof(archivo)){
        cout<<"Legajo: "<<b.legajo<<endl;
        cout<<"Codigo de materia: "<<b.codigoMateria<<endl;
        cout<<"Dia examen: "<<b.diaExamen<<endl;
        cout<<"Mes examen: "<<b.mesExamen<<endl;
        cout<<"Anio examen: "<<b.anioExamen<<endl;
        cout<<"Nombre y Apellido: "<<b.nombreYApellido<<endl;
        contAnt++;
        fread(&b,sizeof(Boleta),1,archivo);
    }

    fclose(archivo);

    cout<<"Agregar mas contenido: "<<endl;
    archivo=fopen("inscripciones.dat","rb+");

    fread(&b,sizeof(Boleta),1,archivo);
    while(!feof(archivo)){
        fread(&b,sizeof(Boleta),1,archivo);
    }

    cout<<"Ingresa legajo: ";
    cin>>boleta.legajo;
    while(boleta.legajo!=0){
        cout<<"Ingresa el codigo de materia: ";
        cin>>boleta.codigoMateria;
        cout<<"Ingresa el dia del examen: ";
        cin>>boleta.diaExamen;
        cout<<"Ingresa el mes del examen: ";
        cin>>boleta.mesExamen;
        cout<<"Ingresa el anio del examen: ";
        cin>>boleta.anioExamen;
        cout<<"Ingresa nombre y apellido: ";
        cin>>boleta.nombreYApellido;
        
        fwrite(&boleta,sizeof(Boleta),1,archivo);

        cout<<"Ingresa otro legajo: ";
        cin>>boleta.legajo;
    }

    fclose(archivo);

    cout<<"Agregados: "<<endl;
    archivo=fopen("inscripciones.dat","rb+");

    fread(&b,sizeof(Boleta),1,archivo);
    for(int i=0;i<contAnt-1;i++){
        fread(&b,sizeof(Boleta),1,archivo);
    }

    fread(&b,sizeof(Boleta),1,archivo);
    while(!feof(archivo)){
        cout<<"Legajo: "<<b.legajo<<endl;
        cout<<"Codigo de materia: "<<b.codigoMateria<<endl;
        cout<<"Dia examen: "<<b.diaExamen<<endl;
        cout<<"Mes examen: "<<b.mesExamen<<endl;
        cout<<"Anio examen: "<<b.anioExamen<<endl;
        cout<<"Nombre y Apellido: "<<b.nombreYApellido<<endl;
        fread(&b,sizeof(Boleta),1,archivo);
    }

    fclose(archivo);

    return 0;
}