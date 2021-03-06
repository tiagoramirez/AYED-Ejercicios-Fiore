#include "Funciones_permitidas_FILES.hpp"

struct Persona{
    int dni;
    char nombre[20];
    int edad;
};

int cmpDniPersona(Persona p, int dni){
    if(dni==p.dni){
        return 0;
    }
    else{
        if(p.dni>dni){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    // int x;
    // cout<<"Ingresa un valor: ";
    // cin>>x;

    // FILE* archivoNuevoInt=fopen("Numeros.dat","wb+");

    // while(x!=0){
    //     write(archivoNuevoInt,x);
    //     cout<<"Ingresa otro valor: ";
    //     cin>>x;
    // }

    // fclose(archivoNuevoInt);

    // FILE* archivoVerInt=fopen("Numeros.dat","rb+");

    // cout<<"Ingresaste: "<<endl;
    // int res;
    // res=read<int>(archivoVerInt);

    // while(!feof(archivoVerInt)){
    //     cout<<res<<" esta en la posicion del archivo: " <<filePos<int>(archivoVerInt)<<endl;
    //     cout<<"El archivo tiene "<<fileSize<int>(archivoVerInt)<<" registros"<<endl;//esto es para probar que no modifica la posicion actual del archivo
    //     res=read<int>(archivoVerInt);
    // }

    // fclose(archivoVerInt);

    // Persona p;

    // FILE* archivoNuevoPersona=fopen("Personas.dat","wb+");
    // cout<<"Ingresa dni: ";
    // cin>>p.dni;

    // while(p.dni!=0){
    //     cout<<"Ingresa nombre: ";
    //     cin>>p.nombre;
    //     cout<<"Ingresa edad: ";
    //     cin>>p.edad;
    //     write<Persona>(archivoNuevoPersona,p);
    //     cout<<"Ingresa otro dni: ";
    //     cin>>p.dni;
    // }
    
    // fclose(archivoNuevoPersona);

    FILE* archivoVerPersona=fopen("Personas.dat","rb+");

    cout<<"Ingresaste: "<<endl;
    Persona persona;
    persona=read<Persona>(archivoVerPersona);

    while(!feof(archivoVerPersona)){
        cout<<persona.dni<<" - "<<persona.nombre<<" - "<<persona.edad<<" esta en la posicion del archivo: " <<filePos<Persona>(archivoVerPersona)-1<<endl;
        persona=read<Persona>(archivoVerPersona);
    }

    cout<<"Persona en la posicion 3: ";
    seek<Persona>(archivoVerPersona,3);
    persona=read<Persona>(archivoVerPersona);
    cout<<persona.dni<<" - "<<persona.nombre<<" - "<<persona.edad<<endl;

    cout<<"El dni 54345123 esta en la posicion: "<<busquedaBinaria<Persona,int>(archivoVerPersona,54345123,cmpDniPersona)<<endl;

    fclose(archivoVerPersona);

    return 0;
}