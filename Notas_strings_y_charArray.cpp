#include <iostream>
#include <string.h>
using namespace std;

struct Inscripcion{
    char codMateria[7];
    char nombreYApelllido[26];
};

int main(){
    string codigoMateria="AB123C";
    string nombreYApellidosss="Tiago_Ramirez";
    Inscripcion i;
    
    //String copy: strcpy(array,string.c_str())

    strcpy(i.codMateria,codigoMateria.c_str());
    strcpy(i.nombreYApelllido,nombreYApellidosss.c_str());
    cout<<"------"<<endl;
    cout<<i.codMateria<<endl;
    cout<<i.nombreYApelllido<<endl;

    //String compare: strcmp(array,string)
    
    if(strcmp(i.codMateria,"AB222C")==0){//son iguales
        cout<<"Es la materia AB222C";
    }else{
        if(strcmp(i.codMateria,"AB222C")>0){//La cadena 2 es mayor (esta antes alfabeticamente)
            cout<<"Es una materia menor alfabeticamente a AB222C";
        }
        else{//La cadena 1 es mayor (esta antes alfabeticamente)
            cout<<"Es una materia mayor alfabeticamente a AB222C";
        }
    }
}