/*#include <iostream>
using namespace std;

int main(){
    unsigned int boleto;
    unsigned int num1,num2,num3,num4,num5;
    unsigned int res1=0,res2=0,res3=0,res4=0;
    cout<< "Ingresa un boleto: ";
    cin>>boleto;
    while(boleto!=0){
        num1=boleto/10000;
        num2=(boleto%10000)/1000;
        num3=(boleto%1000)/100;
        num4=(boleto%100)/10;
        num5=boleto%10;
        if(num1==num2 and num2==num3 and num3==num4 and num4==num5){
            res1++;
        }
        else{
            if(num1==num2 and num2==num4 and num4==num5){
                res2++;
            }
            else{
                if((num2==num3 and num2==num4 and num1==num5) or (num1==num3 and num1==num5 and num2==num4)){
                    res3++;
                }
                else{
                    if(num1==num5 and num2==num4){
                        res4++;
                    }
                }
            }
        }
        cout<<"Ingresa otro boleto: ";
        cin >> boleto;
    }
    cout<<"####################################"<<endl;
    cout<< "Boletos quintuples: "<<res1<<endl;
    cout<< "Boletos cuadruples: "<<res2<<endl;
    cout<< "Boletos triples: "<<res3<<endl;
    cout<< "Boletos dobles: "<<res4<<endl;

    return 0;
} */