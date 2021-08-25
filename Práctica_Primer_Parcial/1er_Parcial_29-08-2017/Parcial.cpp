#include "Funciones_Parcial.hpp"

void copiarStringACharArr(string x,char y[]){
    for(int i=0;i!='\0';i++){
        y[i]=x[i];
    }
}

int main(){
    bool continuar=true;
    while (continuar){
        cout<<"Opciones: "<<endl;
        cout<<"1: Crear archivo ventas.dat"<<endl;
        cout<<"2: Ver archivo ventas.dat"<<endl;
        cout<<"3: Resultado parcial"<<endl;
        cout<<"0: Terminar"<<endl;
        cout<<"Ingresa la opcion: ";
        int opc;
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:{
                FILE* archivo=fopen("ventas.dat","wb+");
                Venta dato;
                cout<<"Termina el ingreso poniendo codigo 0"<<endl;
                cout<<"Ingresa codigo de electrodomestico: ";
                cin>>dato.codE;
                while(dato.codE!=0){
                    cout<<"Ingresa id de sucursal: ";
                    cin>>dato.idSuc;
                    cout<<"Ingresa cantidad vendida: ";
                    cin>>dato.cantidadVendida;
                    cout<<"Ingresa fecha (aaaammdd): ";
                    cin>>dato.fecha;
                    fwrite(&dato,sizeof(Venta),1,archivo);
                    cout<<"Ingresa codigo de electrodomestico: ";
                    cin>>dato.codE;
                }
                cout<<"Terminaste el ingreso"<<endl;
                fclose(archivo);

                system("pause");
                system("cls");
            }
            break;

            case 2:{
                FILE* archivo=fopen("ventas.dat","rb+");
                Venta dato;
                fread(&dato,sizeof(Venta),1,archivo);

                while(!feof(archivo)){
                    cout<<"Codigo de electrodomestico: "<<dato.codE<<"     Id de sucursal: "<<dato.idSuc<<"     Cantidad vendida: "<<dato.cantidadVendida<<"     Fecha: "<<dato.fecha<<endl;
                    fread(&dato,sizeof(Venta),1,archivo);
                }

                cout<<"Terminaste la lectura del archivo"<<endl;
                fclose(archivo);

                system("pause");
                system("cls");
            }
            break;

            case 3:{
                Electro electrodomesticos[4];
                electrodomesticos[0].codE=15;
                copiarStringACharArr("TV",electrodomesticos[0].nombre);
                copiarStringACharArr("Television",electrodomesticos[0].descripcion);
                electrodomesticos[0].precio=50000;

                electrodomesticos[1].codE=20;
                copiarStringACharArr("Heladera",electrodomesticos[1].nombre);
                copiarStringACharArr("Heladera_Negra",electrodomesticos[1].descripcion);
                electrodomesticos[1].precio=100000;

                electrodomesticos[2].codE=29;
                copiarStringACharArr("PS5",electrodomesticos[2].nombre);
                copiarStringACharArr("Consola_PlayStation5",electrodomesticos[2].descripcion);
                electrodomesticos[2].precio=150000;

                electrodomesticos[3].codE=48;
                copiarStringACharArr("Micro",electrodomesticos[3].nombre);
                copiarStringACharArr("Microondas_blanco",electrodomesticos[3].descripcion);
                electrodomesticos[3].precio=3000;

                ElectroAgg vecE[500];
                int lenVecE=0;
                cargarVentasAgrupadasPorElectro(vecE,lenVecE,"ventas.dat");
                mostrarReporte(vecE,lenVecE,electrodomesticos);

                system("pause");
                system("cls");
            }
            break;

            case 0:continuar=false;
            break;
            
            default:{
                cout<<"Opcion incorrecta"<<endl;
                system("pause");
                system("cls");
            }
            break;
        }
    }
    cout<<"Programa terminado"<<endl;
    system("pause");
    system("cls");
    return 0;
}