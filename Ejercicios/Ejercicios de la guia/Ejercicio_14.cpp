#include <iostream>
using namespace std;

int main(){
    int sueldo,cant100,cant50,cant20,cant10,cant5,cant2,cant1;
    int k100=0,k50=0,k20=0,k10=0,k5=0,k2=0,k1=0;
    bool seIngresoResultado=false;
    cout<<"Ingresa el sueldo: ";
    cin >> sueldo;

    while (sueldo!=0){

        seIngresoResultado=true;

        cant100=sueldo/100;
        k100+=cant100;
        sueldo-=cant100*100;

        cant50=sueldo/50;
        k50+=cant50;
        sueldo-=cant50*50;

        cant20=sueldo/20;
        k20+=cant20;
        sueldo-=cant20*20;

        cant10=sueldo/10;
        k10+=cant10;
        sueldo-=cant10*10;

        cant5=sueldo/5;
        k5+=cant5;
        sueldo-=cant5*5;

        cant2=sueldo/2;
        k2+=cant2;
        sueldo-=cant2*2;

        cant1=sueldo/1;
        k1+=cant1;
        sueldo-=cant1;
        
        cout<<"Ingresa otro sueldo: ";
        cin >> sueldo;
    }
    
    if(seIngresoResultado=true){
        cout<<"Cantidad de 100 = "<<k100<<endl;
        cout<<"Cantidad de 50 = "<<k50<<endl;
        cout<<"Cantidad de 20 = "<<k20<<endl;
        cout<<"Cantidad de 10 = "<<k10<<endl;
        cout<<"Cantidad de 5 = "<<k5<<endl;
        cout<<"Cantidad de 2 = "<<k2<<endl;
        cout<<"Cantidad de 1 = "<<k1<<endl;
    }
    else{
        cout<<"No se ingresaron resultados."<<endl;
    }
    return 0;
}