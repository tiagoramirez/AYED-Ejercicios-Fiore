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
        cout<<"7: Crear archivo Alumnos.dat"<<endl;
        cout<<"8: Ver archivo Alumnos.dat"<<endl;
        cout<<"9: Crear archivo Materias.dat"<<endl;
        cout<<"10: Ver archivo Materias.dat"<<endl;
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
                Materia materias[200];
                int lenMaterias;
                inicializarVector(lenMaterias);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno x;

                fread(&x,sizeof(Alumno),1,f);

                while(!feof(f)){
                    bool enc;
                    Materia elem;
                    strcpy(elem.codigoMateria,x.codigoMateria);
                    buscaEInsertaOrdenado(materias,lenMaterias,elem,enc,cmpMatMat);
                    fread(&x,sizeof(Alumno),1,f);
                }

                fclose(f);

                mostrarMaterias(materias,lenMaterias);
                
                system("pause");
                system("cls");
            }
            break;

            case 3:{
                MateriaEInscriptos materias[200];
                int lenMaterias=0;

                inicializarVector(lenMaterias);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno alumno;

                fread(&alumno,sizeof(Alumno),1,f);
                MateriaEInscriptos elem;

                while(!feof(f)){
                    strcpy(elem.codigoMateria,alumno.codigoMateria);

                    bool enc=false;
                    int pos;
                    pos=buscaEInsertaOrdenado(materias,lenMaterias,elem,enc,cmpMatInscMatInsc);
                    if(enc==true){
                        materias[pos].cantInscriptos++;
                    }
                    fread(&alumno,sizeof(Alumno),1,f);
                }

                fclose(f);

                cout<<"Cod Materia | Cant de inscriptos"<<endl;
                for(int i=0;i<lenMaterias;i++){
                    cout<<materias[i].codigoMateria<<"       | "<<materias[i].cantInscriptos<<endl;
                }

                system("pause");
                system("cls");
            }
            break;

            case 4:{
                MateriaEInscriptos materias[200];
                int lenMaterias=0;

                inicializarVector(lenMaterias);

                FILE* f=fopen("Alumnos.dat","rb+");

                Alumno alumno;

                fread(&alumno,sizeof(Alumno),1,f);
                MateriaEInscriptos elem;

                while(!feof(f)){
                    strcpy(elem.codigoMateria,alumno.codigoMateria);

                    bool enc=false;
                    int pos;
                    pos=buscaEInsertaOrdenado(materias,lenMaterias,elem,enc,cmpMatInscMatInsc);
                    if(enc==true){
                        materias[pos].cantInscriptos++;
                    }
                    fread(&alumno,sizeof(Alumno),1,f);
                }

                fclose(f);

                ordenar(materias,lenMaterias,cmpMatInscMatInsc2);

                cout<<"Cod Materia | Cant de inscriptos"<<endl;
                for(int i=0;i<lenMaterias;i++){
                    cout<<materias[i].codigoMateria<<"       | "<<materias[i].cantInscriptos<<endl;
                }

                system("pause");
                system("cls");
            }
            break;

            case 5:{

            }
            break;

            case 7:{
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

            case 8:{
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

            case 9:{
                FILE* archivo=fopen("Materias.dat","wb+");
                DatosMaterias materia;
                cout<<"Termina el ingreso si pone un codigo vacio"<<endl;
                ingresarMateria(materia);

                while(esMateriaValida){
                    fwrite(&materia,sizeof(DatosMaterias),1,archivo);
                    ingresarMateria(materia);
                }
                fclose(archivo);

                cout<<"Se termino de ingresar datos"<<endl;

                system("pause");
                system("cls");
            }
            break;

            case 10:{
                FILE* archivo=fopen("Materias.dat","rb+");
                DatosMaterias materia;
                fread(&materia,sizeof(DatosMaterias),1,archivo);
                while(!feof(archivo)){
                    mostrarDatosMaterias(materia);
                    fread(&materia,sizeof(DatosMaterias),1,archivo);
                }
                fclose(archivo);
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