#include "Cancion.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Cancion::Cancion(const string& titulo, const string& genero, int anio, 
                 const string& artista, const string& album, int duracionSegundos, 
                 const string& discografia, bool esSimple)
    : Entretenimiento(titulo, genero, anio), artista(artista), 
      album(album), duracionSegundos(duracionSegundos), 
      discografia(discografia), esSimple(esSimple) {}

// Implementación de mostrarInfo (versión resumida)
void Cancion::mostrarInfo() const {
    cout << "🎵 " << titulo << " - " << artista << " (" << anio << ") | " 
         << genero << " | " << fixed << setprecision(1) 
         << calificacionPromedio << "⭐ | " << formatearDuracion() 
         << " | " << getTipoCancion() << endl;
}

// Implementación de getTipo
string Cancion::getTipo() const {
    return "Cancion";
}

// Override de mostrarDetalles con información específica de canción
void Cancion::mostrarDetalles() const {
    cout << "\n🎵 ========== CANCIÓN ==========\n";
    cout << "Título: " << titulo << endl;
    cout << "Artista: " << artista << endl;
    cout << "Álbum: " << album << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Duración: " << formatearDuracion() << endl;
    cout << "Discografía: " << discografia << endl;
    cout << "Tipo: " << getTipoCancion() << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) 
         << calificacionPromedio << "/5.0 ⭐" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "==============================\n" << endl;
}

// Método para formatear duración en minutos:segundos
string Cancion::formatearDuracion() const {
    int minutos = duracionSegundos / 60;
    int segundos = duracionSegundos % 60;
    
    string segs = (segundos < 10) ? "0" + to_string(segundos) : to_string(segundos);
    return to_string(minutos) + ":" + segs;
}

// Método para obtener tipo de canción
string Cancion::getTipoCancion() const {
    return esSimple ? "Simple" : "Álbum";
} 