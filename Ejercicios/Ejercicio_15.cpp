/*#include <iostream>
using namespace std;

int main(){
    int num=1,cantSublote=0,maxSublote=-1,max=-1,posMax=-1;
    double promSublote;
    int sumNum=0,cantNum=0,posNum=0;//Valores a reiniciar

    while(num!=-1){
        cout<<"Ingresa el primer valor del sublote: ";
        cin>>num;
        while(num!=0 and num!=-1){
            //A:
            sumNum+=num;
            cantNum++;
            //C:
            if(num>max){
                max=num;
                maxSublote=cantSublote+1;
                posMax=posNum;
            }
            posNum++;
            cout<<"Ingresa otro numero al sublote: ";
            cin>>num;
        }
        //A: compruebo si se ingresaron numeros en el lote
        if(cantNum==0){
            cout<<"El promedio de este sublote es 0."<<endl;
        }
        else{
            promSublote=(double)sumNum/cantNum;
            cout<<"El promedio de este sublote fue: "<<promSublote<<endl;
        }
        //Reinicio variables
        sumNum=0;
        cantNum=0;
        posNum=0;
        //B:
        cantSublote++;
    }
    cout<<"Total de sublotes: "<<cantSublote<<endl;
    cout<<"El valor maximo "<<max<<" estaba en el sublote "<<maxSublote<<" en la posicion "<<posMax<<" (empezando por la posicion 0)."<<endl;
    return 0;
}*/