#include "ClaseTanque.h"        // Para la clase Tanque
#include "ClaseSurtidor.h"      // Para la clase Surtidor       // Para la clase Venta
#include <iostream>             // Para las operaciones de entrada/salida
#include <cstdlib>              // Para funciones como rand()
#include <ctime>                // Para la manipulación de fecha y hora

using namespace std;

class EstacionDeServicio {
private:
    string nombre;
    int codigoIdentificador;
    string gerente;
    string region;
    double coordenadas[2];  // Coordenadas GPS

    Tanque tanque;  // Un único tanque para la estación
    Surtidor* surtidores;  // Arreglo dinámico de surtidores
    int numSurtidores;
    int capacidadSurtidores;

    // Método para redimensionar el arreglo de surtidores cuando sea necesario
    void redimensionarSurtidores(int nuevaCapacidad) {
        Surtidor* temp = new Surtidor[nuevaCapacidad];
        for (int i = 0; i < numSurtidores; i++) {
            temp[i] = surtidores[i];
        }
        delete[] surtidores;
        surtidores = temp;
        capacidadSurtidores = nuevaCapacidad;
    }

    // Generar un valor aleatorio entre un rango
    int generarValorAleatorio(int min, int max) const {
        return rand() % (max - min + 1) + min;
    }

public:
    EstacionDeServicio(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords, const Tanque& tanque)
        : nombre(nombre), codigoIdentificador(codigo), gerente(gerente), region(region), tanque(tanque), numSurtidores(0), capacidadSurtidores(2) {
        coordenadas[0] = coords[0];
        coordenadas[1] = coords[1];
        surtidores = new Surtidor[capacidadSurtidores];
    }

    ~EstacionDeServicio() {
        delete[] surtidores;
    }

    // Getters y Setters
    string getNombre() const { return nombre; }
    int getCodigoIdentificador() const { return codigoIdentificador; }
    string getGerente() const { return gerente; }
    string getRegion() const { return region; }
    const double* getCoordenadas() const { return coordenadas; }
    const Tanque& getTanque() const { return tanque; }
    Surtidor* getSurtidores() const { return surtidores; }
    int getSurtidoresActivos() const {
        int activos = 0;
        for (int i = 0; i < numSurtidores; i++) {
            if (surtidores[i].isActivo()) {
                activos++;
            }
        }
        return activos;
    }

    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setCodigoIdentificador(int codigo) { this->codigoIdentificador = codigo; }
    void setGerente(const string& gerente) { this->gerente = gerente; }
    void setRegion(const string& region) { this->region = region; }
    void setCoordenadas(const double* coords) {
        coordenadas[0] = coords[0];
        coordenadas[1] = coords[1];
    }
    void setTanque(const Tanque& nuevoTanque) { tanque = nuevoTanque; }

    // a. Agregar un surtidor
    void agregarSurtidor(const Surtidor& surtidor) {
        if (numSurtidores == capacidadSurtidores) {
            redimensionarSurtidores(capacidadSurtidores * 2);
        }
        surtidores[numSurtidores] = surtidor;
        numSurtidores++;
    }

    // b. Eliminar un surtidor (solo si no tiene ventas activas)
    void eliminarSurtidor(int codigoSurtidor) {
        if (codigoSurtidor < 0 || codigoSurtidor >= numSurtidores) {
            cout << "Surtidor no encontrado." << endl;
            return;
        }

        if (surtidores[codigoSurtidor].isActivo()) {
            cout << "No se puede eliminar, el surtidor está activo." << endl;
            return;
        }

        // Mover los surtidores después del que se eliminó
        for (int i = codigoSurtidor; i < numSurtidores - 1; i++) {
            surtidores[i] = surtidores[i + 1];
        }
        numSurtidores--;
    }

    void activarDesactivarSurtidor(int codigoSurtidor, bool activar) {
        if (codigoSurtidor < 0 || codigoSurtidor >= numSurtidores) {
            cout << "Surtidor no encontrado." << endl;
            return;
        }
        surtidores[codigoSurtidor].activarDesactivar(activar);  // Llamada directa al método público
        cout << "Surtidor " << (activar ? "activado" : "desactivado") << "." << endl;
    }

    // d. Consultar histórico de transacciones de un surtidor
    void consultarHistoricoTransacciones(int codigoSurtidor) const {
        if (codigoSurtidor < 0 || codigoSurtidor >= numSurtidores) {
            cout << "Surtidor no encontrado." << endl;
            return;
        }
        surtidores[codigoSurtidor].mostrarHistoricoVentas();
    }

    // e. Reportar cantidad de litros vendidos por cada categoría de combustible
    void reportarLitrosVendidos() const {
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
    void simularVenta() {
        if (numSurtidores == 0) {
            cout << "No hay surtidores activos." << endl;
            return;
        }

        // Selección aleatoria de surtidor activo
        int surtidorSeleccionado;
        do {
            surtidorSeleccionado = rand() % numSurtidores;
        } while (!surtidores[surtidorSeleccionado].isActivo());

        // Simulando una venta
        int litrosVendidos = generarValorAleatorio(3, 20);  // Entre 3 y 20 litros
        cout << "Venta simulada: " << litrosVendidos << " litros de combustible." << endl;

        surtidores[surtidorSeleccionado].registrarVenta(litrosVendidos);

        // Reducir la gasolina en el tanque correspondiente
        string categoriaVenta = surtidores[surtidorSeleccionado].getVentas()[surtidores[surtidorSeleccionado].getNumVentas() - 1].getCategoria();
        tanque.reducirGasolina(litrosVendidos, categoriaVenta);
    }

    // g. Asignar la capacidad del tanque de suministro aleatoriamente entre 100 y 200 litros por categoría
    void asignarCapacidadTanque() {
        tanque.asignarCapacidad(generarValorAleatorio(100, 200), "Regular");
        tanque.asignarCapacidad(generarValorAleatorio(100, 200), "Premium");
        tanque.asignarCapacidad(generarValorAleatorio(100, 200), "EcoExtra");
    }

    // Método para calcular las ventas totales en la estación
    double calcularVentas() const {
        double totalVentas = 0;
        for (int i = 0; i < numSurtidores; i++) {
            totalVentas += surtidores[i].getVentas();
        }
        return totalVentas;
    }
};
