#include <iostream>
using namespace std;

int main(){
    int l1, l2, l3;
    cout<<"Ingresa un triangulo...";
    cout << "Ingresa un lado: ";
    cin >> l1;
    cout << "Ingresa otro lado: ";
    cin >> l2;
    cout << "Ingresa otro lado: ";
    cin >> l3;
    while(l1!=0 and l2!=0 and l3!=0){
        if (l1 == l2 and l1 == l3) {
            cout << "Es un triangulo equilatero";
        }
        else{
            if (l1 != l2 and l1 != l3 and l2 != l3) {
                cout << "Es un triangulo escaleno";
            }
            else {
                cout << "Es un triangulo isosceles";
            }
        }
        cout<<"Ingresa otro triangulo..."<<endl;
        cout << "Ingresa un lado: ";
        cin >> l1;
        cout << "Ingresa otro lado: ";
        cin >> l2;
        cout << "Ingresa otro lado: ";
        cin >> l3;
    }
    cout<<"El programa termino...";
    return 0;
}