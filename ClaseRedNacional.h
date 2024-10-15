#ifndef CLASEREDNACIONAL_H
#define CLASEREDNACIONAL_H

#include <string>
#include "ClaseEstacionDeServicio.h"

using namespace std;

class RedNacional {
private:
    EstacionDeServicio** estaciones;  // Arreglo dinamico o de punteros a estaciones
    int numEstaciones;               // # de estaciones registradas
    int capacidad;                   // Capacidad del arreglo dinamico de estaciones
    double precios[3][3];            // Precios (Norte, Centro, Sur) y tipo de combustible (Regular, Premium, EcoExtra)
    void redimensionar(int nuevaCapacidad);

    // indice region para precios
    int getIndiceRegion(const string& region) const;
    unsigned int contCodigoES;

public:
    // Constructor y Destructor
    RedNacional();
    ~RedNacional();

    EstacionDeServicio* buscarEstacionPorCodigo(int codigo) const;
    void listarEstaciones() const;
    void agregarEstacion(const string& nombre, const string& gerente, const string& region, const double* coords);
    double getPrecio(int indiceRegion, int indiceCategoria) const;
    // b. Eliminar estación
    void eliminarEstacion(int codigo);

    void calcularVentasPorEstacion() const;

    void fijarPreciosPorRegion(const string& region, double precioRegular, double precioPremium, double precioEcoExtra);
    int getNumEstaciones() const ;
    EstacionDeServicio** getEstaciones()const;
};

#endif // CLASEREDNACIONAL_H
