#include <string>
#include "Entretenimiento.h"
#include <vector>
#include <numeric>
#include <sstream>
#include "Libro.h"
#include "Cancion.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Podcast.h"
using namespace std;

// Constructor
Entretenimiento::Entretenimiento(string t, string g, int d, int f)
    : titulo(t), genero(g), duracion(d), fecha(f) {}

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

void Entretenimiento::setFecha(int f) {
    fecha = f;
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

int Entretenimiento::getFecha() const {
    return fecha;
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

// Método estático para crear elementos desde string de archivo
Entretenimiento* Entretenimiento::fromFileString(const string& linea, const string& tipo) {
    if (linea.empty() || linea.length() < 5) return nullptr;
    
    // Dividir la línea por |
    vector<string> partes;
    stringstream ss(linea);
    string parte;
    
    while (getline(ss, parte, '|')) {
        partes.push_back(parte);
    }
    
    // Verificar que tenemos al menos 4 partes (título, género, autor, año)
    if (partes.size() < 4) return nullptr;
    
    string titulo = partes[0];
    string genero = partes[1];
    string autor = partes[2];
    int anio;
    vector<int> calificaciones;
    
    try {
        anio = stoi(partes[3]);
        // Si hay calificaciones, cargarlas
        if (partes.size() >= 5 && !partes[4].empty()) {
            stringstream calStream(partes[4]);
            string cal;
            while (getline(calStream, cal, ',')) {
                if (!cal.empty()) {
                    calificaciones.push_back(stoi(cal));
                }
            }
        }
    } catch (...) {
        return nullptr; // Saltar líneas con datos inválidos
    }
    
    Entretenimiento* elemento = nullptr;
    
    if (tipo == "Libro") {
        elemento = new Libro(titulo, genero, 0, autor);
    } else if (tipo == "Cancion") {
        elemento = new Cancion(titulo, genero, 0, autor);
    } else if (tipo == "Pelicula") {
        elemento = new Pelicula(titulo, genero, 0);
    } else if (tipo == "Serie") {
        elemento = new Serie(titulo, genero, 0);
    } else if (tipo == "Podcast") {
        elemento = new Podcast(titulo, genero, 0, autor);
    }
    
    if (elemento) {
        elemento->setFecha(anio);
        // Agregar las calificaciones cargadas
        for (int cal : calificaciones) {
            elemento->agregarCalificacion(cal);
        }
    }
    
    return elemento;
}