#include <iostream>
using namespace std;

int main(){
    int l1, l2, l3,cantEqu=0,cantEsc=0,cantIso=0;
    cout<<"Ingresa un triangulo...";
    cout << "Ingresa un lado: ";
    cin >> l1;
    cout << "Ingresa otro lado: ";
    cin >> l2;
    cout << "Ingresa otro lado: ";
    cin >> l3;
    while(l1!=0 and l2!=0 and l3!=0){
        if (l1 == l2 and l1 == l3) {
            cantEqu++;
        }
        else{
            if (l1 != l2 and l1 != l3 and l2 != l3) {
                cantEsc++;
            }
            else {
                cantIso++;
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
    cout<<"Cantidad de triangulos equilateros: "<<cantEqu<<endl;
    cout<<"Cantidad de triangulos isosceles: "<<cantIso<<endl;
    cout<<"Cantidad de triangulos escalenos: "<<cantEsc<<endl;
    return 0;
}