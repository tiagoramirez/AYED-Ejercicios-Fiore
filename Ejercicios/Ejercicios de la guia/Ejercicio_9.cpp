#include <iostream>
using namespace std;

int main(){
    int valor1,valor2,valor3;
    int max,med,min;
    cout <<"Ingrese el valor 1: ";
    cin >> valor1;
    cout <<"Ingrese el valor 2: ";
    cin >> valor2;
    cout <<"Ingrese el valor 3: ";
    cin >> valor3;
    
    while(valor1!=0 or valor2!=0 or valor3!=0){
        if(valor1==valor2 and valor3==0){  //Este if lo puse por un bug que tenia(si ingresaba dos numeros iguales y un 0 no funcionaba. Ej>45-45-0)
            max=valor1;
            med=valor2;
            min=valor3;
        }
        else{
            if(valor1>valor2 and valor1>valor3){
                max=valor1;
                if(valor2>valor3){
                    med=valor2;
                    min=valor3;
                }
                else{
                    med=valor3;
                    min=valor2;
                }
            }
            else{
                if(valor2>valor1 and valor2>valor3){
                    max=valor2;
                    if(valor1>valor3){
                        med=valor1;
                        min=valor3;
                    }
                    else{
                        med=valor3;
                        min=valor1;
                    }
                }
                else{
                    max=valor3;
                    if(valor2>valor1){
                        med=valor2;
                        min=valor1;
                    }
                    else{
                        med=valor1;
                        min=valor2;
                    }
                }
            }
        }
        cout<<"#############################"<<endl;
        cout<<min<<"-"<<med<<"-"<<max<<endl;
        cout<<"#############################"<<endl;
        cout<< "Ingresa otro valor 1: ";
        cin >> valor1;
        cout<< "Ingresa otro valor 2: ";
        cin >> valor2;
        cout<< "Ingresa otro valor 3: ";
        cin >> valor3;
    }
    cout<<"Termino el programa.";
    
    return 0;
}