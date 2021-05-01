#include <iostream>
using namespace std;

struct Terna{
    int v1;
    int v2;
    int v3;
    int max;
    int med;
    int min;
};

Terna ternaCreate(){
    Terna ret;
    ret.max=0,ret.med=0,ret.min=0;
    cout<<"Ingresa el primer valor: ";
    cin>>ret.v1;
    cout<<"Ingresa el segundo valor: ";
    cin>>ret.v2;
    cout<<"Ingresa el tercer valor: ";
    cin>>ret.v3;
    return ret;
}

bool esTernaNula(Terna t){
    if(t.v1==0 and t.v2==0 and t.v3==0){
        return true;
    }
    else{
        return false;
    }
}

void ordenarTerna(Terna &t){
    if(t.v1==t.v2 and t.v3==0){  //Este if lo puse por un bug que tenia(si ingresaba dos numeros iguales y un 0 no funcionaba. Ej>45-45-0)
        t.max=t.v1;
        t.med=t.v2;
        t.min=t.v3;
    }
    else{
        if(t.v1>t.v2 and t.v1>t.v3){
            t.max=t.v1;
            if(t.v2>t.v3){
                t.med=t.v2;
                t.min=t.v3;
            }
            else{
                t.med=t.v3;
                t.min=t.v2;
            }
        }
        else{
            if(t.v2>t.v1 and t.v2>t.v3){
                t.max=t.v2;
                if(t.v1>t.v3){
                    t.med=t.v1;
                    t.min=t.v3;
                }
                else{
                    t.med=t.v3;
                    t.min=t.v1;
                }
            }
            else{
                t.max=t.v3;
                if(t.v2>t.v1){
                    t.med=t.v2;
                    t.min=t.v1;
                }
                else{
                    t.med=t.v1;
                    t.min=t.v2;
                }
            }
        }
    }
}

void mostrarResultados(Terna t){
    cout<<"#############################"<<endl;
    cout<<t.min<<"-"<<t.med<<"-"<<t.max<<endl;
    cout<<"#############################"<<endl;
}