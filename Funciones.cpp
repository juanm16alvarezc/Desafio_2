#include <iostream>
using namespace std;
#include "ClaseEstacionDeServicio.h"


void serviciosDeGestionDeRed() {
    unsigned short int N;
    cout << "Ingrese #1 si desea agregar una estación de servicio" << endl;
    cout << "Ingrese #2 si desea eliminar una estación de servicio (solo si no posee surtidores activos)" << endl;
    cout << "Ingrese #3 si desea calcular el monto total de las ventas en cada E/S del país discriminado por categoría del combustible" << endl;
    cout << "Ingrese #4 si desea fijar los precios del combustible para toda la red" << endl;
    cout << ": ";
    cin >> N;
    while (N <= 0 || N > 4) {
        cout << "Ingrese valor válido:" << endl;
        cin >> N;
    }

    cout << '\n';
    if (N == 1) {

    } else if (N == 2) {

    } else if (N == 3) {

    } else if (N == 4) {
    }
}

void serviciosDeGestionDeEstacionesDeServicio() {
    unsigned short int N;
    cout << "Ingrese #1 si desea agregar o eliminar surtidor de una E/S" << endl;
    cout << "Ingrese #2 si desea activar o desactivar surtidor de una E/S" << endl;
    cout << "Ingrese #3 si desea consultar el historial de transacciones de cada surtidor de una E/S" << endl;
    cout << "Ingrese #4 si desea reportar la cantidad de litros vendida según la categoría de combustible" << endl;
    cout << "Ingrese #5 si desea simular una venta de combustible" << endl;
    cout << "Ingrese #6 si desea inicializar la capacidad del tanque de suministro" << endl;
    cin >> N;

    while (N <= 0 || N > 6) {
        cout << "Ingrese valor válido:" << endl;
        cin >> N;
    }

    cout << '\n';

    if (N == 1) {

    }
    else if (N == 2){
    }
    else if (N == 3) {
    }
    else if (N == 4) {
    }
    else if (N == 5) {
        // Simular venta
        simularVenta();
    }
    else if (N == 6) {
    }
}

void sistemaDeVerificacionDeFugas(){
    cout<<"en proceso del goat";
}

void simulacionDeVentas() {
    cout<<"en proceso del goat";
}
