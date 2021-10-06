#include <iostream>
using namespace std;

struct Alumno{
    string nombre;
    int edad;
};

int main(){
    int x=10;
    
    int* p=NULL;//direccion de memoria vacia

    p=new int();//creo una direccion en el heap
    
    bool* p2=new bool();

    Alumno* p3=new Alumno();

    *p=10;//seteo con el puntero

    *p2=false;//seteo con el puntero

    p3->edad=20;
    p3->nombre="Tiago";


    delete p;//para borrar la variable

    delete p2;

    delete p3;


    return 0;
}