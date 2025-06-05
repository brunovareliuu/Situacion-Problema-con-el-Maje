#include "Libro.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor que llama al constructor de la clase entretenimiento
Libro::Libro(string t, string g, int d, string a)
    : Entretenimiento(t, g, d, 0), autor(a) {}

void Libro::mostrarInfo() const {
    cout << "- Libro: " << titulo << endl;
    cout << "- Autor: " << autor << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Páginas: " << duracion << endl; // Duración = páginas en este contexto
    if (fecha > 0) {
        cout << "- Año: " << fecha << endl;
    }
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Libro::tipo() const {
    return "Libro";
}

string Libro::toFileString() const {
    stringstream ss;
    ss << titulo << "|" << genero << "|" << autor << "|" << fecha << "|";
    
    // Añadir calificaciones separadas por comas
    vector<int> cals = getCalificaciones();
    for (size_t i = 0; i < cals.size(); i++) {
        ss << cals[i];
        if (i < cals.size() - 1) ss << ",";
    }
    
    return ss.str();
}

string Libro::getAutor() const {
    return autor;
}