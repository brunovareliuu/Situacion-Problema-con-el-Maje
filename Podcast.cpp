#include "Podcast.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Podcast::Podcast(const string& titulo, const string& genero, int anio, 
                 const string& anfitrion, int duracionMinutos, int numeroEpisodio, 
                 const string& plataforma, bool esExplicito)
    : Entretenimiento(titulo, genero, anio), anfitrion(anfitrion), 
      duracionMinutos(duracionMinutos), numeroEpisodio(numeroEpisodio), 
      plataforma(plataforma), esExplicito(esExplicito) {}

// Implementación de mostrarInfo (versión resumida)
void Podcast::mostrarInfo() const {
    cout << "🎙️ " << titulo << " #" << numeroEpisodio << " - " << anfitrion 
         << " (" << anio << ") | " << genero << " | " << fixed << setprecision(1) 
         << calificacionPromedio << "⭐ | " << formatearDuracion() 
         << " | " << getClasificacion() << endl;
}

// Implementación de getTipo
string Podcast::getTipo() const {
    return "Podcast";
}

// Override de mostrarDetalles con información específica de podcast
void Podcast::mostrarDetalles() const {
    cout << "\n🎙️ ========== PODCAST ==========\n";
    cout << "Título: " << titulo << endl;
    cout << "Anfitrión: " << anfitrion << endl;
    cout << "Episodio #: " << numeroEpisodio << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Duración: " << formatearDuracion() << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Clasificación: " << getClasificacion() << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) 
         << calificacionPromedio << "/5.0 ⭐" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "==============================\n" << endl;
}

// Método para formatear duración en horas:minutos
string Podcast::formatearDuracion() const {
    int horas = duracionMinutos / 60;
    int mins = duracionMinutos % 60;
    
    if (horas > 0) {
        return to_string(horas) + "h " + to_string(mins) + "min";
    } else {
        return to_string(mins) + "min";
    }
}

// Método para obtener clasificación
string Podcast::getClasificacion() const {
    return esExplicito ? "Explícito" : "Apto para todos";
} 