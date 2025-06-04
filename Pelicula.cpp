#include "Pelicula.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Pelicula::Pelicula(const string& titulo, const string& genero, int anio, 
                   const string& director, const string& actorPrincipal, 
                   int duracionMinutos, const string& clasificacion)
    : Entretenimiento(titulo, genero, anio), director(director), 
      actorPrincipal(actorPrincipal), duracionMinutos(duracionMinutos), 
      clasificacion(clasificacion) {}

// Implementación de mostrarInfo (versión resumida)
void Pelicula::mostrarInfo() const {
    cout << "🎬 " << titulo << " (" << anio << ") - " 
         << genero << " | " << fixed << setprecision(1) 
         << calificacionPromedio << "⭐ | " << formatearDuracion() << endl;
}

// Implementación de getTipo
string Pelicula::getTipo() const {
    return "Pelicula";
}

// Override de mostrarDetalles con información específica de película
void Pelicula::mostrarDetalles() const {
    cout << "\n🎬 ========== PELÍCULA ==========\n";
    cout << "Título: " << titulo << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Director: " << director << endl;
    cout << "Actor Principal: " << actorPrincipal << endl;
    cout << "Duración: " << formatearDuracion() << endl;
    cout << "Clasificación: " << clasificacion << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) 
         << calificacionPromedio << "/5.0 ⭐" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "================================\n" << endl;
}

// Método para formatear duración en horas:minutos
string Pelicula::formatearDuracion() const {
    int horas = duracionMinutos / 60;
    int mins = duracionMinutos % 60;
    
    if (horas > 0) {
        return to_string(horas) + "h " + to_string(mins) + "min";
    } else {
        return to_string(mins) + "min";
    }
} 