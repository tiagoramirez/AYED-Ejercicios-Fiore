#include <iostream>
using namespace std;

int main(){
    unsigned int numeroEquipo,cantEquipos,cantPartidos,contEquipAct=1,minPuntos,contMin=0;//Declaro las variables
    unsigned int puntosEquipo=0,contPartAct=1;//Pongo las variables que se que las tengo que reiniciar (es algo que se me ocurrio hacer con el tiempo)
    char res;
    bool esPrimerEqu=true;
    int minEquipo=-1;
    cout << "Ingresa la cantidad de equipos que hay en el torneo: ";
    cin >> cantEquipos;
    cantPartidos=cantEquipos-1;//cantidad de partidos que va a tener 1 solo equipo
    
    
    while(contEquipAct<=cantEquipos){
        cout << "Ingresa numero de equipo: ";
        cin >> numeroEquipo;
        while(contPartAct<=cantPartidos){
            cout << "Ingresa el resultado del partido numero "<<contPartAct<<" del equipo: ";
            cin >> res;
            if(res=='G'){
                puntosEquipo+=3;
            }
            else{
                if(res=='E'){
                    puntosEquipo++;
                }
            }
            
            contPartAct++;
        }

        if (esPrimerEqu==true or puntosEquipo<minPuntos){
            minEquipo=numeroEquipo;
            minPuntos=puntosEquipo;
            esPrimerEqu=false;
            contMin=1;
        }
        else{
            if(puntosEquipo==minPuntos){
                contMin++;
            }
        }
        cout<<"/////////////////////////////////////////////////////////////////////////"<<endl;
        cout<<"El equipo numero "<<numeroEquipo<<" tiene "<<puntosEquipo<<" puntos."<<endl;
        cout<<"/////////////////////////////////////////////////////////////////////////"<<endl;

        puntosEquipo=0;
        contPartAct=1;//reinicio las variables
        contEquipAct++;
    }

    //Esto es para emprolijar nada mas :D
    if(contMin==1){
        cout<<"###################""####################################################"<<endl;
        cout<<"El unico equipo que menos puntos tuvo fue "<<minEquipo<<"."<<endl;
        cout<<"#######################################################################"<<endl;
    }
    else{
        cout<<"###################""####################################################"<<endl;
        cout<<"Uno de los "<<contMin<<" equipos que menos puntos tuvo fue "<<minEquipo<<"."<<endl;
        cout<<"#######################################################################"<<endl;
    }
    

    return 0;
}