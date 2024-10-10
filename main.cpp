#include <iostream>
#include "Funciones_.h"
using namespace std;
int main()
{
    unsigned short int n;
    cout<<"Bienvenido al mejor sistema que va a encontrar en su vida"<<endl;
    cout<<"Ingrese un #1 si desea acceder a los servicios de gestion de red."<<endl;
    cout<<"Ingrese un #2 si desea acceder a los servicios de gestion de estaciones de servicio."<<endl;
    cout<<"Ingrese un #3 si desea acceder a la opcion de sistema nacional de verificacion de fugas."<<endl;
    cout<<"ingrese #4 si desea acceder a la opcion de simulacion de ventas."<<endl;
    cout<<": ";
    cin>>n;
    while(n<=0 || n>4){
        cout<<"ingrese valor valido:"<<endl;
        cin>>n;
    }
    if(n==1){
        serviciosDeGestionDeRed();
    }
    else if(n==2){
        serviciosDeGestionDeEstacionesDeServicio();
    }
    else if(n==3){
        sistemaDeVerificacionDeFugas();
    }
    else if(n==4){
        simulacionDeVentas();
    }

}
