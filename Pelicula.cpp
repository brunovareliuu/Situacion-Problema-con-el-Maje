#include "Pelicula.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor que llama al constructor de la clase entretenimiento
Pelicula::Pelicula(string t, string g, int d)
    : Entretenimiento(t, g, d, 0) {}

// Implementamos los métodos virtuales
void Pelicula::mostrarInfo() const {
    cout << "- Película: " << titulo << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " minutos" << endl;
    if (fecha > 0) {
        cout << "- Año: " << fecha << endl;
    }
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Pelicula::tipo() const {
    return "Pelicula";
}

string Pelicula::toFileString() const {
    stringstream ss;
    ss << titulo << "|" << genero << "||" << fecha << "|";
    
    // Añadir calificaciones separadas por comas
    vector<int> cals = getCalificaciones();
    for (size_t i = 0; i < cals.size(); i++) {
        ss << cals[i];
        if (i < cals.size() - 1) ss << ",";
    }
    
    return ss.str();
}
