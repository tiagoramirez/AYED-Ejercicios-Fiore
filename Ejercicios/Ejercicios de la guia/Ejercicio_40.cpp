#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int vec[25];

    for(int i=0;i<n;i++){
        int valor;
        cin>>valor;
        vec[i]=valor;
    }

    int suma=0;

    for(int i=0;i<n;i++){
        suma+=vec[i];
    }

    if(suma>=0){
        for(int i=0;i<n;i++){
            if(i%2==0){
                cout<<vec[i];
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(i%2!=0){
                cout<<vec[i];
            }
        }
    }

    return 0;
}