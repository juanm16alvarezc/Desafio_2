#include "ClaseTanque.h"
#include "ClaseSurtidor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ClaseEstacionDeServicio.h"
#include "ClaseVenta.h"
#include "ClaseRedNacional.h"
using namespace std;

// Método para redimensionar el arreglo de surtidores cuando sea necesario
void EstacionDeServicio::redimensionarSurtidores(int nuevaCapacidad) {
    if (nuevaCapacidad <= 0) {
        cout << "La nueva capacidad debe ser mayor que cero." << endl;
        return; // Salir si la nueva capacidad es inválida
    }

    Surtidor* temp = new Surtidor[nuevaCapacidad]; // Crear nuevo arreglo

    // Copiar los surtidores existentes al nuevo arreglo
    for (int i = 0; i < numSurtidores; i++) {
        temp[i] = surtidores[i]; // Asegúrate de que el constructor por copia funcione correctamente
    }

    //delete[] surtidores; // Liberar la memoria del arreglo anterior
    surtidores = temp; // Reasignar el puntero a la nueva memoria
    capacidadSurtidores = nuevaCapacidad; // Actualizar la capacidad
}

// Generar un valor aleatorio entre un rango
int EstacionDeServicio::generarValorAleatorio(int min, int max) const {
    return rand() % (max - min + 1) + min;
}

EstacionDeServicio::EstacionDeServicio(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords)
    : nombre(nombre), codigoIdentificador(codigo), gerente(gerente), region(region), tanque(), numSurtidores(0), capacidadSurtidores(2) {
    coordenadas[0] = coords[0];
    coordenadas[1] = coords[1];
    surtidores = new Surtidor[capacidadSurtidores];
    numSurtidores=0;
    asignarCapacidadTanque();
    if (region == "Norte") {
        indicePrecios = 0;
    } else if (region == "Centro") {
        indicePrecios = 1;
    } else if (region == "Sur") {
        indicePrecios = 2;
    }
}

EstacionDeServicio::~EstacionDeServicio() {
    delete[] surtidores;
}

// Getters y Setters
string EstacionDeServicio:: getNombre() const { return nombre; }
int EstacionDeServicio:: getCodigoIdentificador() const { return codigoIdentificador; }
string EstacionDeServicio:: getGerente() const { return gerente; }
string EstacionDeServicio:: getRegion() const { return region; }
const double* EstacionDeServicio:: getCoordenadas() const { return coordenadas; }
const Tanque& EstacionDeServicio:: getTanque() const { return tanque; }
Surtidor* EstacionDeServicio:: getSurtidores() const { return surtidores; }
int EstacionDeServicio::getSurtidoresActivos() const {
    int activos = 0;
    for (int i = 0; i < numSurtidores; i++) {
        if (surtidores[i].isActivo()) {
            activos++;
        }
    }
    return activos;
}
int EstacionDeServicio::getIndicePrecios() const {
    return indicePrecios;
}


void EstacionDeServicio:: setNombre(const string& nombre) { this->nombre = nombre; }
void EstacionDeServicio:: setCodigoIdentificador(int codigo) { this->codigoIdentificador = codigo; }
void EstacionDeServicio:: setGerente(const string& gerente) { this->gerente = gerente; }
void EstacionDeServicio:: setRegion(const string& region) { this->region = region; }
void EstacionDeServicio:: setCoordenadas(const double* coords) {
    coordenadas[0] = coords[0];
    coordenadas[1] = coords[1];
}
void EstacionDeServicio:: setTanque(const Tanque& nuevoTanque) { tanque = nuevoTanque; }
void EstacionDeServicio::setIndicePrecios(int indice) {
    indicePrecios = indice;
}
// a. Agregar un surtidor
void EstacionDeServicio::agregarSurtidor(const Surtidor& surtidor) {
    if (numSurtidores >= capacidadSurtidores) { // Cambia a `>=` para asegurar que sea mayor o igual
        redimensionarSurtidores(capacidadSurtidores * 2); // Redimensionar si es necesario
    }
    surtidores[numSurtidores] = surtidor;
    numSurtidores++;
}

// b. Eliminar un surtidor (solo si no esta activo)
void EstacionDeServicio::eliminarSurtidor(int codigoSurtidor) {
    int indiceSurtidor = -1;
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i].getCodigo() == codigoSurtidor) {
            indiceSurtidor = i;
            break;
        }
    }
    if (indiceSurtidor == -1) {
        cout << "Error: Surtidor no encontrado." << endl;
        return;
    }
    if (surtidores[indiceSurtidor].isActivo()) {
        cout << "Error: No se puede eliminar un surtidor activo." << endl;
        return;
    }

    // Eliminar el surtidor moviendo los elementos
    for (int i = indiceSurtidor; i < numSurtidores - 1; ++i) {
        surtidores[i] = surtidores[i + 1];
    }
    numSurtidores--;

    cout << "Surtidor eliminado correctamente" << endl;
}

void EstacionDeServicio::activarDesactivarSurtidor(int codigoSurtidor, bool activar) {
    int indiceSurtidor = -1;

    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i].getCodigo() == codigoSurtidor) {
            indiceSurtidor = i;
            break;
        }
    }

    if (indiceSurtidor == -1) {
        cout << "Surtidor no encontrado." << endl;
        return;
    }

    // Si el surtidor está activo y se quiere activar nuevamente o desactivar, simplemente mostrar mensaje
    if (surtidores[indiceSurtidor].isActivo() == activar) {
        cout << "El surtidor ya esta " << (activar ? "activado." : "desactivado.") << endl;
        return;
    }

    surtidores[indiceSurtidor].activarDesactivar(activar);  // Llamada al método para activar o desactivar el surtidor
    cout << "Surtidor " << (activar ? "activado" : "desactivado") << "." << endl;
}


// d. Consultar histórico de transacciones de un surtidor
void EstacionDeServicio:: consultarHistoricoTransacciones(int codigoSurtidor) const {
    if (codigoSurtidor < 0 || codigoSurtidor >= numSurtidores) {
        cout << "Surtidor no encontrado." << endl;
        return;
    }
    surtidores[codigoSurtidor].mostrarHistoricoVentas();
}

// e. Reportar cantidad de litros vendidos por cada categoría de combustible
void EstacionDeServicio:: reportarLitrosVendidos() const {
    double litrosVendidosRegular = 0, litrosVendidosPremium = 0, litrosVendidosEcoExtra = 0;

    // Iterar sobre cada surtidor en la estación
    for (int i = 0; i < numSurtidores; i++) {
        // Iterar sobre cada venta registrada en el surtidor
        for (int j = 0; j < surtidores[i].getNumVentas(); j++) {
            // Acceder a la venta actual
            const Venta& venta = surtidores[i].getVentas()[j];

            // Sumar los litros vendidos según la categoría de combustible
            if (venta.getCategoria() == "Regular") {
                litrosVendidosRegular += venta.getLitrosVendidos();
            } else if (venta.getCategoria() == "Premium") {
                litrosVendidosPremium += venta.getLitrosVendidos();
            } else if (venta.getCategoria() == "EcoExtra") {
                litrosVendidosEcoExtra += venta.getLitrosVendidos();
            }
        }
    }

    // Mostrar los resultados
    cout << "Litros vendidos por categoría:" << endl;
    cout << "Regular: " << litrosVendidosRegular << " litros" << endl;
    cout << "Premium: " << litrosVendidosPremium << " litros" << endl;
    cout << "EcoExtra: " << litrosVendidosEcoExtra << " litros" << endl;
}

// f. Simular una venta
void EstacionDeServicio::simularVenta(const RedNacional& red) {
    // Verificar que haya surtidores activos
    if (getSurtidoresActivos() == 0) {
        cout << "Error: No hay surtidores activos para realizar una venta." << endl;
        return;
    }

    // Seleccionar aleatoriamente un surtidor activo
    int surtidorSeleccionado = -1;
    do {
        int indice = rand() % numSurtidores;
        if (surtidores[indice].isActivo()) {
            surtidorSeleccionado = indice;
        }
    } while (surtidorSeleccionado == -1);

    // Generar una cantidad aleatoria de litros a vender (entre 3 y 20)
    int litrosVendidos = 3 + rand() % 18;
    string categoria;
    int categoriaIndex = rand() % 3;
    switch (categoriaIndex) {
    case 0: categoria = "Regular"; break;
    case 1: categoria = "Premium"; break;
    case 2: categoria = "EcoExtra"; break;
    }

    // Obtener el precio del combustible basado en la categoría y la región
    int precioPorLitro = red.getPrecio(indicePrecios, categoriaIndex);
    // Calcular el monto total de la venta
    int montoTotal = litrosVendidos * precioPorLitro;

    // Simular método de pago y documento
    string metodoPago = "Efectivo";  // Esto puede hacerse aleatorio
    string numeroDocumento = "123456";  // Documento simulado
    // Registrar la venta en el surtidor seleccionado
    tanque.reducirGasolina(litrosVendidos,categoria);
    surtidores[surtidorSeleccionado].registrarVenta(litrosVendidos, montoTotal, metodoPago, numeroDocumento, categoria);


    cout << "Venta realizada en el surtidor " << surtidores[surtidorSeleccionado].getCodigo() << endl;
    Venta* ventassurtidor= surtidores[surtidorSeleccionado].getVentas();
    int numeroventas=surtidores[surtidorSeleccionado].getNumVentas()-1;
    ventassurtidor[numeroventas].mostrarInfo();
}
// g. Asignar la capacidad del tanque de suministro aleatoriamente entre 100 y 200 litros por categoría
void EstacionDeServicio:: asignarCapacidadTanque() {
    tanque.asignarCapacidad(generarValorAleatorio(100, 200), "Regular");
    tanque.asignarCapacidad(generarValorAleatorio(100, 200), "Premium");
    tanque.asignarCapacidad(generarValorAleatorio(100, 200), "EcoExtra");
}

// Método para calcular las ventas totales en la estación
void EstacionDeServicio::calcularVentas() const {
    double totalVentasRegular = 0;
    double totalVentasPremium = 0;
    double totalVentasEcoExtra = 0;

    // Iterar sobre los surtidores
    for (int i = 0; i < numSurtidores; i++) {
        // Iterar sobre las ventas de cada surtidor
        for (int j = 0; j < surtidores[i].getNumVentas(); j++) {
            const Venta& venta = surtidores[i].getVentas()[j];  // Acceder a cada venta

            // Discriminar por la categoría de combustible
            if (venta.getCategoria() == "Regular") {
                totalVentasRegular += venta.getMontoTotal();  // Sumar al total de Regular
            } else if (venta.getCategoria() == "Premium") {
                totalVentasPremium += venta.getMontoTotal();  // Sumar al total de Premium
            } else if (venta.getCategoria() == "EcoExtra") {
                totalVentasEcoExtra += venta.getMontoTotal();  // Sumar al total de EcoExtra
            }
        }
    }

    // Mostrar los resultados discriminados por categoría
    cout << "Ventas totales por categoría:" << endl;
    cout << "Regular: " << totalVentasRegular << " unidades monetarias" << endl;
    cout << "Premium: " << totalVentasPremium << " unidades monetarias" << endl;
    cout << "EcoExtra: " << totalVentasEcoExtra << " unidades monetarias" << endl;
}
void EstacionDeServicio::listarSurtidores() const {
    if (numSurtidores == 0) {
        cout << "No hay surtidores en esta estaciOn." << endl;
        return;
    }
    cout << "Lista de surtidores en esta estacion:" << endl;
    for (int i = 0; i < numSurtidores; ++i) {
        cout << "Codigo: " << surtidores[i].getCodigo() << ", Modelo: " << surtidores[i].getModelo() << ", Activo: " << (surtidores[i].isActivo() ? "Si" : "No") << endl;
    }
}
