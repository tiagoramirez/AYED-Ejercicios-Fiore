#include <iostream>
using namespace std;

int main(){
    int leg,legMax1=-1,legMax2=-1;
    double prom=1,max1=-1,max2=-1;
    while(leg!=0){
        cout<<"Ingresa legajo: ";
        cin>>leg;
        if(leg!=0){
            cout<<"Ingresa el promedio del legajo "<<leg<<": ";
            cin>> prom;
            if(prom>max1){
                max2=max1;
                legMax2=legMax1;
                max1=prom;
                legMax1=leg;

            }
            else{
                if(prom>max2){
                    max2=prom;
                    legMax2=leg;
                }
            }
        }
    }
    
    if(max1==-1){
        cout<<"No se ingresaron legajos distintos de 0.";
    }
    else{
        if(max2==-1){
            cout<<"El unico alumno maximo es: "<<legMax1<<endl;
        }
        else{
            cout<<"El alumno maximo es: "<<legMax1<<endl;
            cout<<"El segundo alumno maximo es: "<<legMax2<<endl;

        }
    }

    return 0;
}