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


// En el archivo de implementación de los servicios

void serviciosDeGestionDeEstacionesDeServicio(RedNacional& red) {
    unsigned short int N;

    // Menú de opciones
    cout << "Ingrese #1 si desea agregar o eliminar surtidor de una E/S" << endl;
    cout << "Ingrese #2 si desea activar o desactivar surtidor de una E/S" << endl;
    cout << "Ingrese #3 si desea consultar el historial de transacciones de cada surtidor de una E/S" << endl;
    cout << "Ingrese #4 si desea reportar la cantidad de litros vendida según la categoría de combustible" << endl;
    cout << "Ingrese #5 si desea simular una venta de combustible" << endl;
    cout << "Ingrese #6 si desea inicializar la capacidad del tanque de suministro" << endl;
    cin >> N;

    // Validar que la opción ingresada esté entre 1 y 6
    while (N <= 0 || N > 6) {
        cout << "Ingrese valor válido:" << endl;
        cin >> N;
    }

    cout << '\n';
    if (N == 1) {
        cout << "Lista de estaciones de servicio:" << endl;
        red.listarEstaciones();
        int codigoEstacion;
        cout << "Ingrese el código de la estación de servicio a gestionar: ";
        cin >> codigoEstacion;
        EstacionDeServicio** estaciones = red.getEstaciones();  // Obtener el puntero a punteros
        EstacionDeServicio* estacionEncontrada = nullptr;

        // Buscar la estación en el arreglo de estaciones
        for (int i = 0; i < red.getNumEstaciones(); ++i) {
            if (estaciones[i]->getCodigoIdentificador() == codigoEstacion) {
                estacionEncontrada = estaciones[i];  // Asignar la estación encontrada
                break;
            }
        }

        // Si no se encuentra la estación, mostrar mensaje de error
        if (!estacionEncontrada) {
            cout << "Estación de servicio no encontrada." << endl;
            return;
        }

        // Listar surtidores de la estación seleccionada
        cout << "Lista de surtidores en la estación con código " << codigoEstacion << ":" << endl;
        estacionEncontrada->listarSurtidores();  // Llamada a la función que lista los surtidores de la estación

        int opcion;
        cout << "Desea: " << endl;
        cout << "1 - Agregar surtidor" << endl;
        cout << "2 - Eliminar surtidor" << endl;
        cin >> opcion;

        if (opcion == 1) {
            // Agregar surtidor
            int codigoSurtidor;
            string modeloMaquina;
            cout << "Ingrese el código del nuevo surtidor: ";
            cin >> codigoSurtidor;
            cout << "Ingrese Modelo de máquina: ";
            cin.ignore();  // Limpiar el buffer de entrada
            getline(cin, modeloMaquina);  // Leer el nombre del modelo
            Surtidor nuevoSurtidor(codigoSurtidor, modeloMaquina);  // Crear el nuevo surtidor
            estacionEncontrada->agregarSurtidor(nuevoSurtidor);  // Llamada a la función de agregar surtidor
            cout << "Surtidor agregado correctamente." << endl;
        }
        else if (opcion == 2) {
            // Eliminar surtidor
            int codigoSurtidor;
            cout << "Ingrese el código del surtidor a eliminar: ";
            cin >> codigoSurtidor;
            // Llamada a la función de eliminar surtidor
            estacionEncontrada->eliminarSurtidor(codigoSurtidor);
        }
        else {
            cout << "Opción no válida." << endl;
        }
    }
    else if (N == 2) {
        // Activar o desactivar surtidor
        // Implementación pendiente
    }
    else if (N == 3) {
        // Consultar historial de transacciones
        // Implementación pendiente
    }
    else if (N == 4) {
        // Reportar cantidad de litros vendidos por categoría
        // Implementación pendiente
    }
    else if (N == 5) {
        // Simular venta
        // Implementación pendiente
    }
    else if (N == 6) {
        // Inicializar capacidad del tanque
        // Implementación pendiente
    }
}


//void sistemaDeVerificacionDeFugas(){
//cout<<"en proceso del goat";
//}

//void simulacionDeVentas() {
//   cout<<"en proceso del goat";
//}
