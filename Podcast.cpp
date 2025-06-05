#include "Podcast.h"
#include <iostream>
using namespace std;

Podcast::Podcast(string t, string g, int d, string p)
    : Entretenimiento(t, g, d), presentador(p) {}

void Podcast::mostrarInfo() const {
    cout << "- Podcast: " << titulo << endl;
    cout << "- Presentador: " << presentador << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración: " << duracion << " minutos" << endl;
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

string Podcast::tipo() const {
    return "Podcast";
}