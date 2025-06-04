#include "Serie.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Serie::Serie(const string& titulo, const string& genero, int anio, 
             const string& creador, int temporadas, int episodiosTotales, 
             const string& plataforma, bool enEmision)
    : Entretenimiento(titulo, genero, anio), creador(creador), 
      temporadas(temporadas), episodiosTotales(episodiosTotales), 
      plataforma(plataforma), enEmision(enEmision) {}

// Implementación de mostrarInfo (versión resumida)
void Serie::mostrarInfo() const {
    cout << "📺 " << titulo << " (" << anio << ") - " 
         << genero << " | " << fixed << setprecision(1) 
         << calificacionPromedio << "⭐ | " << temporadas << " temp. | " 
         << getEstadoEmision() << endl;
}

// Implementación de getTipo
string Serie::getTipo() const {
    return "Serie";
}

// Override de mostrarDetalles con información específica de serie
void Serie::mostrarDetalles() const {
    cout << "\n📺 =========== SERIE ===========\n";
    cout << "Título: " << titulo << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Creador: " << creador << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Episodios totales: " << episodiosTotales << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Estado: " << getEstadoEmision() << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) 
         << calificacionPromedio << "/5.0 ⭐" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "==============================\n" << endl;
}

// Método para obtener estado de emisión
string Serie::getEstadoEmision() const {
    return enEmision ? "En emisión" : "Finalizada";
} 