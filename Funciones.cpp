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
        cout << "Ingrese el codigo de la estacion: ";
        cin >> codigo;
        cout << "Ingrese el nombre del gerente: ";
        cin.ignore();
        getline(cin, gerente);
        cout << "Ingrese la region (Norte, Centro, Sur): ";
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
        cout << "Ingrese el codigo de la estación a eliminar: ";
        cin >> codigo;

        // Llamada a la función para eliminar la estación
        red.eliminarEstacion(codigo);
    }
    else if (N == 3) {
        red.calcularVentasPorEstacion();  // Llamada a calcular las ventas discriminadas por tipo de combustible
    }
    else if (N == 4) {
        string region;
        double precioRegular, precioPremium, precioEcoExtra;

        cout << "Ingrese la region (Norte, Centro, Sur): ";
        cin.ignore();
        getline(cin, region);

        cout << "Ingrese el precio por litro de Regular: ";
        cin >> precioRegular;

        cout << "Ingrese el precio por litro de Premium: ";
        cin >> precioPremium;

        cout << "Ingrese el precio por litro de EcoExtra: ";
        cin >> precioEcoExtra;

        // Llamada a la función de la clase RedNacional para fijar precios
        red.fijarPreciosPorRegion(region, precioRegular, precioPremium, precioEcoExtra);

        cout << "Precios fijados correctamente para la region " << region << "." << endl;
    }
}


// En el archivo de implementación de los servicios

void serviciosDeGestionDeEstacionesDeServicio(RedNacional& red) {
    unsigned short int N;

    // Menú de opciones
    cout << "Ingrese #1 si desea agregar o eliminar surtidor de una E/S" << endl;
    cout << "Ingrese #2 si desea activar o desactivar surtidor de una E/S" << endl;
    cout << "Ingrese #3 si desea consultar el historial de transacciones de cada surtidor de una E/S" << endl;
    cout << "Ingrese #4 si desea reportar la cantidad de litros vendida según la categoria de combustible" << endl;
    cout << "Ingrese #5 si desea simular una venta de combustible" << endl;
    cout << "Ingrese #6 si desea inicializar la capacidad del tanque de suministro" << endl;
    cin >> N;

    // Validar que la opción ingresada esté entre 1 y 6
    while (N <= 0 || N > 6) {
        cout << "Ingrese valor valido:" << endl;
        cin >> N;
    }

    cout << '\n';
    if (N == 1) {
        cout << "Lista de estaciones de servicio:" << endl;
        red.listarEstaciones();
        int codigoEstacion;
        cout << "Ingrese el codigo de la estacion de servicio a gestionar: ";
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
            cout << "Estacion de servicio no encontrada." << endl;
            return;
        }

        // Listar surtidores de la estación seleccionada
        cout << "Lista de surtidores en la estacion con codigo " << codigoEstacion << ":" << endl;
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
            cout << "Ingrese el codigo del nuevo surtidor: ";
            cin >> codigoSurtidor;
            cout << "Ingrese Modelo de maquina: ";
            cin.ignore();
            getline(cin, modeloMaquina);
            Surtidor nuevoSurtidor(codigoSurtidor, modeloMaquina);
            estacionEncontrada->agregarSurtidor(nuevoSurtidor); // agregar surtidor
            cout << "Surtidor agregado correctamente." << endl;
        }
        else if (opcion == 2) {
            // Eliminar surtidor
            int codigoSurtidor;
            cout << "Ingrese el codigo del surtidor a eliminar: ";
            cin >> codigoSurtidor;
            // Llamada a la función de eliminar surtidor
            estacionEncontrada->eliminarSurtidor(codigoSurtidor);
            estacionEncontrada->listarSurtidores();
        }
        else {
            cout << "Opción no valida." << endl;
        }
    }
    else if (N == 2) {
        // Activar o desactivar surtidor
        cout << "Lista de estaciones de servicio:" << endl;
        red.listarEstaciones();  // Listar las estaciones de servicio disponibles
        int codigoEstacion;
        cout << "Ingrese el codigo de la estacion de servicio a gestionar: ";
        cin >> codigoEstacion;

        // Buscar la estación
        EstacionDeServicio** estaciones = red.getEstaciones();
        EstacionDeServicio* estacionEncontrada = nullptr;

        for (int i = 0; i < red.getNumEstaciones(); ++i) {
            if (estaciones[i]->getCodigoIdentificador() == codigoEstacion) {
                estacionEncontrada = estaciones[i];
                break;
            }
        }
        if (!estacionEncontrada) {
            cout << "Estacion de servicio no encontrada." << endl;
            return;
        }

        // Listar surtidores de la estación seleccionada
        cout << "Lista de surtidores en la estación con codigo " << codigoEstacion << ":" << endl;
        estacionEncontrada->listarSurtidores();  // Mostrar la lista de surtidores disponibles

        int codigoSurtidor;
        cout << "Ingrese el codigo del surtidor a activar/desactivar: ";
        cin >> codigoSurtidor;

        bool activar;
        cout << "Ingrese 1 para activar o 0 para desactivar el surtidor: ";
        cin >> activar;

        estacionEncontrada->activarDesactivarSurtidor(codigoSurtidor, activar);
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
    cout << "Las estaciones disponibles son:" << endl;
    red.listarEstaciones();
    int codigo;
    cout << "Ingrese el codigo de la estación para simular la venta: ";
    cin >> codigo;

    // Buscar la estación por el código
    EstacionDeServicio** estaciones = red.getEstaciones();
    for (int i = 0; i < red.getNumEstaciones(); i++) {
        if (estaciones[i]->getCodigoIdentificador() == codigo) {
            estaciones[i]->simularVenta(red);
            break;
        }
    }
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
