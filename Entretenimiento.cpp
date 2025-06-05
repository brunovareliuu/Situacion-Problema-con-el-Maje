#include <string>
#include "Entretenimiento.h"
#include <vector>
#include <numeric>
using namespace std;

// Constructor
Entretenimiento::Entretenimiento(string t, string g, int d)
    : titulo(t), genero(g), duracion(d) {}

// Setters
void Entretenimiento::setTitulo(const string& t) {
    titulo = t;
}

void Entretenimiento::setGenero(const string& g) {
    genero = g;
}

void Entretenimiento::setDuracion(int d) {
    duracion = d;
}

// Getters
string Entretenimiento::getTitulo() const {
    return titulo;
}

string Entretenimiento::getGenero() const {
    return genero;
}

int Entretenimiento::getDuracion() const {
    return duracion;
}

vector<int> Entretenimiento::getCalificaciones() const {
    return calificaciones;
}

// Método para agregar una nueva calificación
void Entretenimiento::agregarCalificacion(int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) { //La ponemos en el rango
        calificaciones.push_back(calificacion); //Pusback es ponerlo al final del vector calificaciones
    }
    // Aquí podrías lanzar una excepción si quieres manejar errores más adelante
}

// Método para calcular el promedio de calificaciones
float Entretenimiento::promedioCalificaciones() const {
    if (calificaciones.empty()) {
        return 0.0f; //la f es para poner que es float
    }

    //Lo ponemos en float para que no de enteroes en el promedio
    float suma = 0;
    float contador = 0;

    for (int i = 0; i < calificaciones.size(); i++) {
        suma += calificaciones[i];
        contador++;
    }
    float promedio = suma / contador;
    return promedio;
}