#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
    int legajo;
    char nombreYApellido[101];
    char codigoMateria[6];
};

void inicializarVectorAlumno(int& len){
    len=0;
}

template <typename T>
void agregar(T arr[], int& len, T v){
    arr[len]=v;
    len++;
}

template <typename T>
void ordenar(T arr[], int len, int (*cmpTT)(T,T)){
    T aux;
    for (int i=0;i<len-1;i++){
        for(int x=0;x<len-1;x++){
            if(cmpTT(arr[x],arr[x+1])==1){//veo si el primero es mas grande que el segundo
                aux=arr[x];
                arr[x]=arr[x+1];
                arr[x+1]=aux;
            }
        }
    }
}

int cmpAlAl(Alumno x, Alumno y){
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

int cmpAlAl2(Alumno x, Alumno y){
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

void mostrarArrayAlumnos2(Alumno alumnos[],int len){
    for(int i=0;i<len;i++){
        cout<<"Codigo de materia: "<<alumnos[i].codigoMateria<<"   ";
        cout<<"Legajo: "<<alumnos[i].legajo<<"   ";
        cout<<"Nombre y Apellido: "<<alumnos[i].nombreYApellido<<endl;
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

int main(){
    int opc;
    bool terminar=false;

    while(!terminar){
        cout<<"Opciones: "<<endl;
        cout<<"1: Punto A"<<endl;
        cout<<"2: Punto B"<<endl;
        cout<<"3: Punto C"<<endl;
        cout<<"4: Punto D"<<endl;
        cout<<"5: Punto E"<<endl;
        cout<<"6: Punto F"<<endl;
        cout<<"8: Crear archivo Alumnos.dat"<<endl;
        cout<<"9: Ver archivo Alumnos.dat"<<endl;
        cout<<"0: Terminar el programa"<<endl;
        cout<<"Ingresa la opcion: ";
        cin>>opc;
        switch (opc){
            case 1:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVectorAlumno(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    agregar(alumnos,lenAlumnos,x);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                ordenar(alumnos,lenAlumnos,cmpAlAl);

                mostrarArrayAlumnos(alumnos,lenAlumnos);

                system("pause");
            }
            break;

            case 2:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVectorAlumno(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    agregar(alumnos,lenAlumnos,x);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                ordenar(alumnos,lenAlumnos,cmpAlAl2);

                mostrarArrayAlumnos2(alumnos,lenAlumnos);
                system("pause");
            }
            break;

            case 3:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVectorAlumno(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    agregar(alumnos,lenAlumnos,x);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);
            }
            break;

            case 8:{
                FILE* f=fopen("Alumnos.dat","wb+");
                Alumno alumno;
                cout<<"Termina el ingreso con un legajo 0"<<endl;
                ingresarAlumno(alumno);

                while(esAlumnoValido(alumno)){
                    fwrite(&alumno,sizeof(Alumno),1,f);
                    ingresarAlumno(alumno);
                }
                fclose(f);

                cout<<"Se termino de ingresar datos"<<endl;

                system("pause");
            }
            break;

            case 9:{
                FILE* f=fopen("Alumnos.dat","rb+");
                Alumno alumno;
                fread(&alumno,sizeof(Alumno),1,f);
                while(!feof(f)){
                    mostrarAlumno(alumno);
                    fread(&alumno,sizeof(Alumno),1,f);
                }
                fclose(f);
                system("pause");
            }
            break;

            case 0:
            terminar=true;
            break;

            default:
            cout<<"Opcion incorrecta"<<endl;
            break;
        }
    }
    cout<<"Programa terminado. ";
    system("pause");
    return 0;
}