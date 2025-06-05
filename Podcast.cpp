#include "Podcast.h"
#include <iostream>
#include <sstream>
using namespace std;

Podcast::Podcast(string t, string g, int d, string p)
    : Entretenimiento(t, g, d, 0), presentador(p) {}

void Podcast::mostrarInfo() const {
    cout << "- Podcast: " << titulo << endl;
    cout << "- Presentador: " << presentador << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " minutos" << endl;
    if (fecha > 0) {
        cout << "- Año: " << fecha << endl;
    }
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Podcast::tipo() const {
    return "Podcast";
}

string Podcast::toFileString() const {
    stringstream ss;
    ss << titulo << "|" << genero << "|" << presentador << "|" << fecha << "|";
    
    // Añadir calificaciones separadas por comas
    vector<int> cals = getCalificaciones();
    for (size_t i = 0; i < cals.size(); i++) {
        ss << cals[i];
        if (i < cals.size() - 1) ss << ",";
    }
    
    return ss.str();
}

string Podcast::getPresentador() const {
    return presentador;
}