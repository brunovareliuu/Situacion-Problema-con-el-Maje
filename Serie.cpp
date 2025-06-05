#include "Serie.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor que llama al constructor de la clase base Entretenimiento
Serie::Serie(string t, string g, int d)
    : Entretenimiento(t, g, d, 0) {}

// Implementación del método mostrarInfo()
void Serie::mostrarInfo() const {
    cout << "- Serie: " << titulo << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración por episodio: " << duracion << " minutos" << endl;
    if (fecha > 0) {
        cout << "- Año: " << fecha << endl;
    }
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

// Implementación del método tipo()
string Serie::tipo() const {
    return "Serie";
}

string Serie::toFileString() const {
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