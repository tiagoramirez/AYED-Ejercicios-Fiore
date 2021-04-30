#include <iostream>
#include "Ejercicio_4.hpp"
using namespace std;

int main(){
    int num1,num2;
    ingresarValores(num1,num2);
    cout<<num1<<" * "<<num2<<" = "<<multiplicarValores(num1,num2);
    return 0;
}