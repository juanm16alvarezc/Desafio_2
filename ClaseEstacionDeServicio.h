#ifndef CLASEESTACIONDESERVICIO_H
#define CLASEESTACIONDESERVICIO_H

#include <string>
#include "ClaseSurtidor.h"
#include "ClaseTanque.h"
using namespace std;
class RedNacional;
class EstacionDeServicio {
private:
    string nombre;
    int codigoIdentificador;
    string gerente;
    string region;
    double coordenadas[2];  // Coordenadas GPS

    Tanque tanque;  // Un unico tanque para la estación
    Surtidor** surtidores;  // Arreglo dinamico a puntero de surtidores
    int numSurtidores;
    int capacidadSurtidores;

    // Metodo para redimensionar el arreglo de surtidores cuando sea necesario
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
    Surtidor** getSurtidores() const;
    int getSurtidoresActivos() const;
    int getIndicePrecios() const;
    int getNumSurtidores() const;

    void listarSurtidores() const;
    void setNombre( string& nombre);
    void setCodigoIdentificador(int codigo);
    void setGerente( string& gerente);
    void setRegion( string& region);
    void setCoordenadas( double* coords);
    void setTanque( Tanque& nuevoTanque);
    void setIndicePrecios(int indice);
    //Agregar un surtidor
    void agregarSurtidor(int cod, string mod);

    //Eliminar un surtidor (solo si no tiene ventas activas)
    void eliminarSurtidor(int codigoSurtidor);

    //Activar o desactivar un surtidor
    void activarDesactivarSurtidor(int codigoSurtidor, bool activar);

    //Consultar histórico de transacciones de un surtidor
    void consultarHistoricoTransacciones(int codigoSurtidor) const;

    //Reportar cantidad de litros vendidos por cada categoría de combustible
    void reportarLitrosVendidos() const;

    // Simular una venta
    void simularVenta();

    //  Asignar la capacidad del tanque de suministro aleatoriamente entre 100 y 200 litros por categoría
    void asignarCapacidadTanque();

    // Método para calcular las ventas totales en la estación
    void simularVenta(const RedNacional& red);
    void calcularVentas() const ;
    void verificarFugas() const;
};

#endif // CLASEESTACIONDESERVICIO_H
