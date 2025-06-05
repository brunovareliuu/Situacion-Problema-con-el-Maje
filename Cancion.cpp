#include "Cancion.h"
#include <iostream>
using namespace std;

Cancion::Cancion(string t, string g, int d, string art)
    : Entretenimiento(t, g, d), artista(art) {}

void Cancion::mostrarInfo() const {
    cout << "- Canción: " << titulo << endl;
    cout << "- Artista: " << artista << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " segundos" << endl;
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Cancion::tipo() const {
    return "Cancion";
}