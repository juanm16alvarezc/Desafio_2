#include <iostream>
using namespace std;
#include "ClaseRedNacional.h"

void serviciosDeGestionDeRed(RedNacional& red) {
    unsigned short int N;
    cout << "Ingrese #1 si desea agregar una estacion de servicio" << endl;
    cout << "Ingrese #2 si desea eliminar una estacion de servicio (solo si no posee surtidores activos)" << endl;
    cout << "Ingrese #3 si desea calcular el monto total de las ventas en cada E/S del país discriminado por categoria del combustible" << endl;
    cout << "Ingrese #4 si desea fijar los precios del combustible para toda la red" << endl;
    cout << ": ";
    cin >> N;

    while (N <= 0 || N > 4) {
        cout << "Ingrese valor válido:" << endl;
        cin >> N;
    }

    cout << '\n';

    if (N == 1) {
        string nombre, gerente, region;
        int codigo;
        double coords[2];
        cout << "Ingrese el nombre de la estacion de servicio: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese el código de la estación: ";
        cin >> codigo;
        cout << "Ingrese el nombre del gerente: ";
        cin.ignore();
        getline(cin, gerente);
        cout << "Ingrese la región (Norte, Centro, Sur): ";
        getline(cin, region);
        cout << "Ingrese las coordenadas GPS (latitud y longitud separadas por espacio): ";
        cin >> coords[0] >> coords[1];
        // Crear la estación de servicio y agregarla a la red
        red.agregarEstacion(nombre, codigo, gerente, region, coords);

        cout << "Estacion de servicio agregada correctamente." << endl;
    }



    else if (N == 2) {
        // Eliminar estacion
        cout << "Las estaciones disponibles son:" << endl;
        red.listarEstaciones();
        int codigo;
        cout << "Ingrese el código de la estación a eliminar: ";
        cin >> codigo;

        // Llamada a la función para eliminar la estación
        red.eliminarEstacion(codigo);
    }
    else if (N == 3) {
        red.calcularVentasPorEstacion();  // Llamada a calcular las ventas discriminadas por tipo de combustible
    }
    else if (N == 4) {
        // Fijar precios para toda la red
    }
}


void serviciosDeGestionDeEstacionesDeServicio(RedNacional& red) {
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
        void simularVenta();
    }
    else if (N == 6) {
    }
}

//void sistemaDeVerificacionDeFugas(){
    //cout<<"en proceso del goat";
//}

//void simulacionDeVentas() {
 //   cout<<"en proceso del goat";
//}
