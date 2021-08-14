#include "Funciones_Practica_Arrays.hpp"

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
        system("cls");
        switch (opc){
            case 1:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVector(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    insertarOrdenado(alumnos,lenAlumnos,x,cmpAlAlLEG);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                mostrarArrayAlumnos(alumnos,lenAlumnos);

                system("pause");
                system("cls");
            }
            break;

            case 2:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVector(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    insertarOrdenado(alumnos,lenAlumnos,x,cmpAlAlCODMAT);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                mostrarArrayAlumnos2(alumnos,lenAlumnos);
                system("pause");
                system("cls");
            }
            break;

            case 3:{
                Alumno alumnos[10000];
                int lenAlumnos=0;

                inicializarVector(lenAlumnos);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    insertarOrdenado(alumnos,lenAlumnos,x,cmpAlAlCODMAT);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                string codigoMateria[200];
                int cantInscriptos[200];
                int posCodigoMateria=-1;
                string anterior=alumnos[0].codigoMateria;
                for(int i=0;i<lenAlumnos;i++){
                    if(i==0 or anterior!=alumnos[i].codigoMateria){
                        posCodigoMateria++;
                        cantInscriptos[posCodigoMateria]=1;
                        codigoMateria[posCodigoMateria]=alumnos[i].codigoMateria;
                        anterior=alumnos[i].codigoMateria;
                    }
                    else{
                        cantInscriptos[posCodigoMateria]++;
                    }
                }
                for(int i=0;i<posCodigoMateria+1;i++){
                    cout<<"Materia: "<<codigoMateria[i]<<endl;
                    cout<<"Cantidad de inscripciones: "<<cantInscriptos[i]<<endl;
                }

                system("pause");
                system("cls");
            }
            break;

            case 4:{
                
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
                system("cls");
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
                system("cls");
            }
            break;

            case 0:
            terminar=true;
            break;

            default:
            cout<<"Opcion incorrecta"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout<<"Programa terminado. ";
    system("pause");
    return 0;
}