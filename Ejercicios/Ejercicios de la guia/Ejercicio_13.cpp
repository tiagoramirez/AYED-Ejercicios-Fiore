#include <iostream>
using namespace std;

int main(){
    int dia=1,mes=1,hora=0,diaMax=1,mesMax=1,horaMax=0;
    double temp=1,tempMax=-300;

    for (int i=0;i<8640;i++){
        cout<<"Ingresa la temperatura del dia y mes "<<dia<<"/"<<mes<<" en la hora "<<hora<<": "<<endl;
        cin>>temp;

        if(temp>tempMax){
            diaMax=dia;
            mesMax=mes;
            horaMax=hora;
            tempMax=temp;
        }
        
        if(hora==23){
            hora=-1;
            dia++;
        }

        if(dia==31){
            dia=1;
            mes++;
        }

        hora++;
    }
    cout<<"El dia y mes max fue el "<<diaMax<<"/"<<mesMax<<" en la hora "<<horaMax<<" con la temperatura: "<<tempMax<<endl;

    return 0;
}