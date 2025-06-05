#include "Cancion.h"
#include <iostream>
#include <sstream>
using namespace std;

Cancion::Cancion(string t, string g, int d, string art)
    : Entretenimiento(t, g, d, 0), artista(art) {}

void Cancion::mostrarInfo() const {
    cout << "- Canción: " << titulo << endl;
    cout << "- Artista: " << artista << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " segundos" << endl;
    if (fecha > 0) {
        cout << "- Año: " << fecha << endl;
    }
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Cancion::tipo() const {
    return "Cancion";
}

string Cancion::toFileString() const {
    stringstream ss;
    ss << titulo << "|" << genero << "|" << artista << "|" << fecha << "|";
    
    // Añadir calificaciones separadas por comas
    vector<int> cals = getCalificaciones();
    for (size_t i = 0; i < cals.size(); i++) {
        ss << cals[i];
        if (i < cals.size() - 1) ss << ",";
    }
    
    return ss.str();
}

string Cancion::getArtista() const {
    return artista;
}