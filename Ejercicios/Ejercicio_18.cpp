/*#include <iostream>
using namespace std;

//Quice usar funciones porque en toda la guia no lo habia utilizado y en 2 ejercicios pasamos a archivos

string charToString(char x){//Convertir char a string;
    string ret="";
    ret=ret+x;
    return ret;
}

string multiplicarString(string s,int mult){
    string ret=s;
    for(int i=1;i!=mult;i++){
        ret+=s;
    }
    return ret;
}

int main(){
    string mostrar;
    cout<<"Rectangulo de 12x40: "<<endl;
    for(int alto=0;alto!=12;alto++){
        if(alto==0 or alto==12-1){
            mostrar=multiplicarString(charToString('-'),40);
            cout<<mostrar<<endl;
        }
        else{
            mostrar=charToString('*')+multiplicarString(charToString(' '),38)+charToString('*');
            cout<<mostrar<<endl;
        }
    }
    unsigned int alto, ancho;
    cout<<"Ingresa lado: ";
    cin>>alto;
    cout<<"Ingresa ancho: ";
    cin>>ancho;
    for(int i=0;i!=alto;i++){
        if(i==0 or i==alto-1){
            mostrar=multiplicarString(charToString('-'),ancho);
            cout<<mostrar<<endl;
        }
        else{
            mostrar=charToString('*')+multiplicarString(charToString(' '),ancho-2)+charToString('*');
            cout<<mostrar<<endl;
        }
    }
    return 0;
}*/