#include <iostream>
using namespace std;

struct Alumno{
    string nombre;
    int edad;
};

void incrementarEdad(Alumno* punteroAlumno){
    //(*punteroAlumno).edad++;
    punteroAlumno->edad++;
}

int main(){
    int x=10;
    cout<<x<<endl;//muestra el valor de x
    cout<<&x<<endl;//muestra la direccion de memoria de x

    int* direccionMemoriaDeX;//creo un puntero de un valor tipo int
    direccionMemoriaDeX=&x;//le seteo la direccion de memoria de x

    //direccionMemoriaDeX=11; <--- eso es incorrecto porque estoy cambiando la direccion de memoria
    
    *direccionMemoriaDeX=11;//seteo x en 11;
    
    cout<<x<<endl;

    cout<<direccionMemoriaDeX<<endl;//muestra la direccion del puntero

    cout<<*direccionMemoriaDeX<<endl;//muestro el valor del puntero
    
    Alumno al={"Tiago",20};
    incrementarEdad(&al);
    cout<<al.edad<<endl;

    return 0;
}