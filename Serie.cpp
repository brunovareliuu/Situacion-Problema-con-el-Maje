#include "Serie.h"
#include <iostream>
using namespace std;

// Constructor que llama al constructor de la clase base Entretenimiento
Serie::Serie(string t, string g, int d)
    : Entretenimiento(t, g, d) {}

// Implementación del método mostrarInfo()
void Serie::mostrarInfo() const {
    cout << "- Serie: " << titulo << endl;
    cout << "- Género: " << genero << endl;
    cout << "- Duración por episodio: " << duracion << " minutos" << endl;
    cout << "- Calificación promedio: " << promedioCalificaciones() << endl;
}

// Implementación del método tipo()
string Serie::tipo() const {
    return "Serie";
}