#include "Funciones_Final.hpp"

int main(){
    FILE* archivoCaracteres=fopen("caracteres.dat","wb+");
    string palabraASubir;
    cout<<"Ingresa una palabra: ";
    cin>>palabraASubir;

    for(int i=0;palabraASubir[i]!='\0';i++){
        char c=palabraASubir[i];
        fwrite(&c,sizeof(char),1,archivoCaracteres);
    }
    fclose(archivoCaracteres);

    if(esPalindromo()){
        cout<<"Es palindromo";
    }
    else{
        cout<<"No es palindromo";
    }

    return 0;
}