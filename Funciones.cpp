#include <iostream>
using namespace std;
#include "ClaseRedNacional.h"
#include "Funciones_.h"

void serviciosDeGestionDeRed(RedNacional& red) {
    unsigned short int N;
    cout << "Ingrese #1 si desea agregar una estacion de servicio" << endl;
    cout << "Ingrese #2 si desea eliminar una estacion de servicio (solo si no posee surtidores activos)" << endl;
    cout << "Ingrese #3 si desea calcular el monto total de las ventas en cada E/S del pais discriminado por categoria del combustible" << endl;
    cout << "Ingrese #4 si desea fijar los precios del combustible para toda la red" << endl;
    cout << ": ";
    cin >> N;

    while (N <= 0 || N > 4) {
        cout << "Ingrese valor valido:" << endl;
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
        cout << "Ingrese el codigo de la estacion a eliminar: ";
        cin >> codigo;

        // eliminar la estacion
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
        red.fijarPreciosPorRegion(region, precioRegular, precioPremium, precioEcoExtra);
        cout << "Precios fijados correctamente para la region " << region << "." << endl;
    }
}


void serviciosDeGestionDeEstacionesDeServicio(RedNacional& red) {
    unsigned short int N;
    cout << "Ingrese #1 si desea agregar o eliminar surtidor de una E/S" << endl;
    cout << "Ingrese #2 si desea activar o desactivar surtidor de una E/S" << endl;
    cout << "Ingrese #3 si desea consultar el historial de transacciones de cada surtidor de una E/S" << endl;
    cout << "Ingrese #4 si desea reportar la cantidad de litros vendida segun la categoria de combustible" << endl;
    cout << "Ingrese #5 si desea simular una venta de combustible" << endl;
    cout << "Ingrese #6 si desea inicializar la capacidad del tanque de suministro" << endl;
    cin >> N;
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
        for (int i = 0; i < red.getNumEstaciones(); ++i) {
            if (estaciones[i]->getCodigoIdentificador() == codigoEstacion) {
                estacionEncontrada = estaciones[i];  // Asignar la estacion encontrada
                break;
            }
        }

        // Si no se encuentra la estacion, mostrar mensaje de error
        if (!estacionEncontrada) {
            cout << "Estacion de servicio no encontrada." << endl;
            return;
        }

        // Listar surtidores de la estación seleccionada
        cout << "Lista de surtidores en la estacion con codigo " << codigoEstacion << ":" << endl;
        estacionEncontrada->listarSurtidores();

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
            estacionEncontrada->agregarSurtidor(codigoSurtidor, modeloMaquina);
        }
        else if (opcion == 2) {
            // Eliminar surtidor
            int codigoSurtidor;
            cout << "Ingrese el codigo del surtidor a eliminar: ";
            cin >> codigoSurtidor;
            estacionEncontrada->eliminarSurtidor(codigoSurtidor);
            estacionEncontrada->listarSurtidores();
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }
    else if (N == 2) {
        cout << "Lista de estaciones de servicio:" << endl;
        red.listarEstaciones();
        int codigoEstacion;
        cout << "Ingrese el codigo de la estacion de servicio a gestionar: ";
        cin >> codigoEstacion;

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
        cout << "Lista de surtidores en la estación con codigo " << codigoEstacion << ":" << endl;
        estacionEncontrada->listarSurtidores();

        int codigoSurtidor;
        cout << "Ingrese el codigo del surtidor a activar/desactivar: ";
        cin >> codigoSurtidor;

        bool activar;
        cout << "Ingrese 1 para activar o 0 para desactivar el surtidor: ";
        cin >> activar;

        estacionEncontrada->activarDesactivarSurtidor(codigoSurtidor, activar);
    }
    else if (N == 3) {
        red.listarEstaciones();
        int codigoEstacion;
        cout << "Ingrese el codigo de la estacion para consultar el historial de transacciones: ";
        cin >> codigoEstacion;

        EstacionDeServicio* estacionSeleccionada = red.buscarEstacionPorCodigo(codigoEstacion);
        if (estacionSeleccionada == nullptr) {
            cout << "Estacion no encontrada." << endl;
            return;
        }
        // Recorrer todos los surtidores de la estación seleccionada y mostrar su historial de transacciones
        cout << "Historial de transacciones para la estacion " << codigoEstacion << ":" << endl;
        for (int i = 0; i < estacionSeleccionada->getNumSurtidores(); i++) {            
            cout << "Surtidor con codigo " << estacionSeleccionada->getSurtidores()[i]->getCodigo() << ":" << endl;
            estacionSeleccionada->consultarHistoricoTransacciones(i);
        }
    }

    else if (N == 4) {

        red.listarEstaciones();
        int codigoEstacion;
        cout << "Ingrese el codigo de la estacion para reportar los litros vendidos: ";
        cin >> codigoEstacion;

        EstacionDeServicio* estacionSeleccionada = red.buscarEstacionPorCodigo(codigoEstacion);
        if (estacionSeleccionada == nullptr) {
            cout << "Estacion no encontrada." << endl;
            return;
        }
        cout << "Reporte de litros vendidos por categoria en la estacion con codigo " << codigoEstacion << ":" << endl;
        estacionSeleccionada->reportarLitrosVendidos();
    }
    else if (N == 5) {
        simulacionDeVentas(red);
    }
    else if (N == 6) {
        cout << "Las capacidades del tanque son inicializadas al momento de crear una estacion de servicio" << endl;

    }
}

void simulacionDeVentas(RedNacional& red){
    cout << "Las estaciones disponibles son:" << endl;
    red.listarEstaciones();
    int codigo;
    cout << "Ingrese el codigo de la estacion para simular la venta: ";
    cin >> codigo;

    EstacionDeServicio* estacionSeleccionada = red.buscarEstacionPorCodigo(codigo);
    estacionSeleccionada->simularVenta(red);

}
void sistemaDeVerificacionDeFugas(RedNacional& red){
    cout << "Las estaciones disponibles son:" << endl;
    red.listarEstaciones();
    int codigo;
    cout << "Ingrese el codigo de la estacion que desee aplicarle uso del metodo de verificacion de fugas ";
    cin >> codigo;
    EstacionDeServicio* estacionSeleccionada = red.buscarEstacionPorCodigo(codigo);
    estacionSeleccionada->verificarFugas();

}

