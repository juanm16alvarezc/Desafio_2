#ifndef CLASEREDNACIONAL_H
#define CLASEREDNACIONAL_H

#include <string>
#include "ClaseEstacionDeServicio.h"  // Suponiendo que la clase EstacionDeServicio está en otro archivo

using namespace std;

class RedNacional {
private:
    EstacionDeServicio** estaciones;  // Arreglo dinamico o de punteros a estaciones
    int numEstaciones;               // # de estaciones registradas
    int capacidad;                   // Capacidad del arreglo dinamico de estaciones
    double precios[3][3];            // Precios (Norte, Centro, Sur) y tipo de combustible (Regular, Premium, EcoExtra)
    void redimensionar(int nuevaCapacidad);

    // Método para obtener el índice de la región
    int getIndiceRegion(const string& region) const;

public:
    // Constructor y Destructor
    RedNacional();
    ~RedNacional();

    // a. Agregar estación
    void listarEstaciones() const;
    void agregarEstacion(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords);
    double getPrecio(int indiceRegion, int indiceCategoria) const;
    // b. Eliminar estación
    void eliminarEstacion(int codigo);

    // c. Calcular ventas por estación
    void calcularVentasPorEstacion() const;

    // d. Fijar precios por región
    void fijarPreciosPorRegion(const string& region, double precioRegular, double precioPremium, double precioEcoExtra);
    int getNumEstaciones() const ;
    EstacionDeServicio** getEstaciones()const;
};

#endif // CLASEREDNACIONAL_H
