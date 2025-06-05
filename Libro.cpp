#include "Libro.h"
#include <iostream>
using namespace std;

// Constructor que llama al constructor de la clase entretenimiento
Libro::Libro(string t, string g, int d, string a)
    : Entretenimiento(t, g, d), autor(a) {}

void Libro::mostrarInfo() const {
    cout << "- Libro: " << titulo << endl;
    cout << "- Autor: " << autor << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Páginas: " << duracion << endl; // Duración = páginas en este contexto
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Libro::tipo() const {
    return "Libro";
}