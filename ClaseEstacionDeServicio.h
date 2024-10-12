#ifndef CLASEESTACIONDESERVICIO_H
#define CLASEESTACIONDESERVICIO_H

#include <string>
#include "ClaseSurtidor.h"  // Suponiendo que los surtidores están definidos en otro archivo
using namespace std;
class RedNacional;
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
    void redimensionarSurtidores(int nuevaCapacidad);

    // Generar un valor aleatorio entre un rango
    int generarValorAleatorio(int min, int max) const;
    int indicePrecios;
public:
    EstacionDeServicio(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords);
    ~EstacionDeServicio();

    // Getters y Setters
    string getNombre() const;
    int getCodigoIdentificador() const;
    string getGerente() const;
    string getRegion() const;
    const double* getCoordenadas() const;
    const Tanque& getTanque() const;
    Surtidor* getSurtidores() const;
    int getSurtidoresActivos() const;
    int getIndicePrecios() const;


    void listarSurtidores() const;
    void setNombre(const string& nombre);
    void setCodigoIdentificador(int codigo);
    void setGerente(const string& gerente);
    void setRegion(const string& region);
    void setCoordenadas(const double* coords);
    void setTanque(const Tanque& nuevoTanque);
    void setIndicePrecios(int indice);
    // a. Agregar un surtidor
    void agregarSurtidor(const Surtidor& surtidor);

    // b. Eliminar un surtidor (solo si no tiene ventas activas)
    void eliminarSurtidor(int codigoSurtidor);

    // c. Activar o desactivar un surtidor
    void activarDesactivarSurtidor(int codigoSurtidor, bool activar);

    // d. Consultar histórico de transacciones de un surtidor
    void consultarHistoricoTransacciones(int codigoSurtidor) const;

    // e. Reportar cantidad de litros vendidos por cada categoría de combustible
    void reportarLitrosVendidos() const;

    // f. Simular una venta
    void simularVenta();

    // g. Asignar la capacidad del tanque de suministro aleatoriamente entre 100 y 200 litros por categoría
    void asignarCapacidadTanque();

    // Método para calcular las ventas totales en la estación
    void simularVenta(const RedNacional& red);
    void calcularVentas() const ;

};

#endif // CLASEESTACIONDESERVICIO_H
