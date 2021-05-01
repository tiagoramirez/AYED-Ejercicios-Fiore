#include <iostream>
using namespace std;

struct Boleto{
    unsigned int num1;
    unsigned int num2;
    unsigned int num3;
    unsigned int num4;
    unsigned int num5;
};

Boleto boletoCreate(){
    Boleto ret;
    unsigned int boleto;
    cout<<"Ingresa numero de boleto: ";
    cin>>boleto;
    ret.num1=boleto/10000;
    ret.num2=(boleto%10000)/1000;
    ret.num3=(boleto%1000)/100;
    ret.num4=(boleto%100)/10;
    ret.num5=boleto%10;
    return ret;
}

bool esBoletoNulo(Boleto b){
    if(b.num1==0 and b.num2==0 and b.num3==0 and b.num4==0 and b.num5==0){
        return true;
    }
    else{
        return false;
    }
}

void calcularBoleto(Boleto b,unsigned int &res1,unsigned int &res2,unsigned int &res3,unsigned int &res4){
    if(b.num1==b.num2 and b.num2==b.num3 and b.num3==b.num4 and b.num4==b.num5){
        res1++;
    }
    else{
        if(b.num1==b.num2 and b.num2==b.num4 and b.num4==b.num5){
            res2++;
        }
        else{
            if((b.num2==b.num3 and b.num2==b.num4 and b.num1==b.num5) or (b.num1==b.num3 and b.num1==b.num5 and b.num2==b.num4)){
                res3++;
            }
            else{
                if(b.num1==b.num5 and b.num2==b.num4){
                    res4++;
                }
            }
        }
    }
}

void mostrarResultados(unsigned int res1,unsigned int res2,unsigned int res3,unsigned int res4){
    cout<<"####################################"<<endl;
    cout<< "Boletos quintuples: "<<res1<<endl;
    cout<< "Boletos cuadruples: "<<res2<<endl;
    cout<< "Boletos triples: "<<res3<<endl;
    cout<< "Boletos dobles: "<<res4<<endl;
}