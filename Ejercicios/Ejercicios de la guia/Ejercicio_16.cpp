#include <iostream>
using namespace std;

int main(){
    unsigned int leg,legMax1=0,legMax2=0;
    double prom=1,max1=0,max2=0;
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
    cout<<"El alumno maximo es: "<<legMax1<<endl;
    cout<<"El segundo alumno maximo es: "<<legMax2<<endl;
    return 0;
}