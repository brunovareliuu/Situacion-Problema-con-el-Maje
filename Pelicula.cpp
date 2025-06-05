#include "Pelicula.h"
#include <iostream>
using namespace std;

// Constructor que llama al constructor de la clase entretenimiento
Pelicula::Pelicula(string t, string g, int d)
    : Entretenimiento(t, g, d) {}

// Implementamos los métodos virtuales
void Pelicula::mostrarInfo() const {
    cout << "- Película: " << titulo << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " minutos" << endl;
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Pelicula::tipo() const {
    return "Pelicula";
}
