#include <iostream>
using namespace std;

int main(){
    unsigned int sueldo,min,tipoPago1,tipoPago2,tipoPago3,tipoPago4,tipoPago5,tipoPago6,tipoPago7;
    unsigned int cant100,cant50,cant20,cant10,cant5,cant2,cant1;
    unsigned int sueldoAux;//Variables para reiniciar
    cout<<"Ingresa el sueldo: ";
    cin >> sueldo;
    sueldoAux=sueldo;
    while (sueldo!=0){
        //Con billetes de 100:
        cant100=sueldoAux/100;
        sueldoAux-=cant100*100;
        cant50=sueldoAux/50;
        sueldoAux-=cant50*50;
        cant20=sueldoAux/20;
        sueldoAux-=cant20*20;
        cant10=sueldoAux/10;
        sueldoAux-=cant10*10;
        cant5=sueldoAux/5;
        sueldoAux-=cant5*5;
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago1=cant100+cant50+cant20+cant10+cant5+cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 50:
        cant50=sueldoAux/50;
        sueldoAux-=cant50*50;
        cant20=sueldoAux/20;
        sueldoAux-=cant20*20;
        cant10=sueldoAux/10;
        sueldoAux-=cant10*10;
        cant5=sueldoAux/5;
        sueldoAux-=cant5*5;
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago2=cant50+cant20+cant10+cant5+cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 20:
        cant20=sueldoAux/20;
        sueldoAux-=cant20*20;
        cant10=sueldoAux/10;
        sueldoAux-=cant10*10;
        cant5=sueldoAux/5;
        sueldoAux-=cant5*5;
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago3=cant20+cant10+cant5+cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 10:
        cant10=sueldoAux/10;
        sueldoAux-=cant10*10;
        cant5=sueldoAux/5;
        sueldoAux-=cant5*5;
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago4=cant10+cant5+cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 5:
        cant5=sueldoAux/5;
        sueldoAux-=cant5*5;
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago5=cant5+cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 2:
        cant2=sueldoAux/2;
        sueldoAux-=cant2*2;
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago6=cant2+cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //Con billetes de 1:
        cant1=sueldoAux/1;
        sueldoAux-=cant1;
        tipoPago7=cant1;//termino el pago con billetes de 100
        sueldoAux=sueldo;//reinicio variable
        //-----Veo cual es el minimo-------------------------------
        min=tipoPago1;
        if(tipoPago2<min){
            min=tipoPago2;
        }
        if(tipoPago3<min){
        min=tipoPago3;
        }
        if(tipoPago4<min){
            min=tipoPago4;
        }
        if(tipoPago5<min){
            min=tipoPago5;
        }
        if(tipoPago6<min){
            min=tipoPago6;
        }
        if(tipoPago7<min){
            min=tipoPago7;
        }
        cout<<"tipopago1: "<<tipoPago1<<endl;
        cout<<"tipopago2: "<<tipoPago2<<endl;
        cout<<"tipopago3: "<<tipoPago3<<endl;
        cout<<"tipopago4: "<<tipoPago4<<endl;
        cout<<"tipopago5: "<<tipoPago5<<endl;
        cout<<"tipopago6: "<<tipoPago6<<endl;
        cout<<"tipopago7: "<<tipoPago7<<endl;
        cout<<"min: "<<min<<endl;
        //------------Despues de ver cual es el minimo---------
        cant100=0,cant50=0,cant20=0,cant10=0,cant5=0,cant2=0,cant1=0;
        sueldoAux=sueldo;
        if(min==tipoPago1){
            cant100=sueldoAux/100;
            sueldoAux-=cant100*100;
            cant50=sueldoAux/50;
            sueldoAux-=cant50*50;
            cant20=sueldoAux/20;
            sueldoAux-=cant20*20;
            cant10=sueldoAux/10;
            sueldoAux-=cant10*10;
            cant5=sueldoAux/5;
            sueldoAux-=cant5*5;
            cant2=sueldoAux/2;
            sueldoAux-=cant2*2;
            cant1=sueldoAux/1;
        }
        else{
            if(min==tipoPago2){
                cant50=sueldoAux/50;
                sueldoAux-=cant50*50;
                cant20=sueldoAux/20;
                sueldoAux-=cant20*20;
                cant10=sueldoAux/10;
                sueldoAux-=cant10*10;
                cant5=sueldoAux/5;
                sueldoAux-=cant5*5;
                cant2=sueldoAux/2;
                sueldoAux-=cant2*2;
                cant1=sueldoAux/1;
            }
            else{
                if(min==tipoPago3){
                    cant20=sueldoAux/20;
                    sueldoAux-=cant20*20;
                    cant10=sueldoAux/10;
                    sueldoAux-=cant10*10;
                    cant5=sueldoAux/5;
                    sueldoAux-=cant5*5;
                    cant2=sueldoAux/2;
                    sueldoAux-=cant2*2;
                    cant1=sueldoAux/1;
                }
                else{
                    if(min==tipoPago4){
                        cant10=sueldoAux/10;
                        sueldoAux-=cant10*10;
                        cant5=sueldoAux/5;
                        sueldoAux-=cant5*5;
                        cant2=sueldoAux/2;
                        sueldoAux-=cant2*2;
                        cant1=sueldoAux/1;
                    }
                    else{
                        if(min==tipoPago5){
                            cant5=sueldoAux/5;
                            sueldoAux-=cant5*5;
                            cant2=sueldoAux/2;
                            sueldoAux-=cant2*2;
                            cant1=sueldoAux/1;
                        }
                        else{
                            if(min==tipoPago6){
                                cant2=sueldoAux/2;
                                sueldoAux-=cant2*2;
                                cant1=sueldoAux/1;
                            }
                            else{
                                cant1=sueldoAux/1;
                            }
                        }
                    }
                }
            }
        }
        cout <<"************************************"<<endl;
        cout<<"Pagar con: "<<endl;
        cout<<cant100<<" billetes de 100."<<endl;
        cout<<cant50<<" billetes de 50."<<endl;
        cout<<cant20<<" billetes de 20."<<endl;
        cout<<cant10<<" billetes de 10."<<endl;
        cout<<cant5<<" billetes de 5."<<endl;
        cout<<cant2<<" billetes de 2."<<endl;
        cout<<cant1<<" billetes de 1."<<endl;
        cout <<"************************************"<<endl;
        cout<<"Ingresa el sueldo: ";
        cin >> sueldo;
        sueldoAux=sueldo;
    }

    return 0;
}