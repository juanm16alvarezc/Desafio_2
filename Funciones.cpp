#include <iostream>
#include "Funciones_Clases.h"
using namespace std;

void serviciosDeGestionDeRed(){
    unsigned short int N;
    cout<<"ingrese #1 si desea agregar una estacion de servicio"<<endl;
    cout<<"ingrese #2 si desea eliminar una estacion de servicio (solo si no posee surtidores activos"<<endl;
    cout<<"ingrese #3 si desea calcular el monto total de las ventas en cada E/S del pais discriminado por categoria del combustible"<<endl;
    cout<<"ingrese #4 si desea fijar los precios del combustible para toda la red"<<endl;
    cout<<": ";
    cin>>N;
    while(N<=0 || N>4){
        cout<<"ingrese valor valido:"<<endl;
        cin>>N;
    }
    cout<<'\n';
    if(N==1){
    }
    else if(N==2){

    }
    else if(N==3){
    }
    else if(N==4){

    }
}
void serviciosDeGestionDeEstacionesDeServicio(){
    unsigned short int N;
    cout<<"ingrese #1 si desea agregar o eliminar surtidor de una E/S"<<endl;
    cout<<"ingrese #2 si desea activar o desactivar surtidor de una E/S"<<endl;
    cout<<"ingrese #3 si desea consultar el historial de transacciones de cada surtidor de una E/S"<<endl;
    cout<<"ingrese #4 si desea reportar la cantidad de litros vendida segun la categoria de combustible"<<endl;
    cout<<"ingrese #5 si desea simular una venta de combustible"<<endl;
    cout<<"ingrese #6 si desea inicializar la capacidad del tanque de suministro"<<endl;
    cin>>N;
    while(N<=0 || N>6){
        cout<<"ingrese valor valido:"<<endl;
        cin>>N;
    }
    cout<<'\n';
    if(N==1){
    }
    else if(N==2){

    }
    else if(N==3){
    }
    else if(N==4){

    }
    else if(N==5){
         simulacionDeVentas();
    }
    else if(N==6){

    }

}

void sistemaDeVerificacionDeFugas(){
    //imprimir estaciones servicio, elegir una, y hacer el calculo si las ve

}

void simulacionDeVentas(){

}
