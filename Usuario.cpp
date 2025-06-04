#include "Usuario.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Constructor básico
Usuario::Usuario(const string& nombre, const string& genero) 
    : nombre(nombre), generoFavorito(genero), totalCalificaciones(0) {
    preferenciasGeneros.push_back(genero);
}

// Constructor con preferencias
Usuario::Usuario(const string& nombre, const string& genero, const vector<string>& preferencias) 
    : nombre(nombre), generoFavorito(genero), preferenciasGeneros(preferencias), totalCalificaciones(0) {}

// Getters y Setters
void Usuario::setGeneroFavorito(const string& genero) {
    this->generoFavorito = genero;
}

string Usuario::getGeneroFavorito() const {
    return generoFavorito;
}

void Usuario::setNombre(const string& nombre) {
    this->nombre = nombre;
}

string Usuario::getNombre() const {
    return nombre;
}

// Métodos para preferencias
void Usuario::agregarPreferencia(const string& genero) {
    if (!tienePreferencia(genero)) {
        preferenciasGeneros.push_back(genero);
    }
}

void Usuario::eliminarPreferencia(const string& genero) {
    preferenciasGeneros.erase(
        remove(preferenciasGeneros.begin(), preferenciasGeneros.end(), genero), 
        preferenciasGeneros.end()
    );
}

vector<string> Usuario::getPreferencias() const {
    return preferenciasGeneros;
}

bool Usuario::tienePreferencia(const string& genero) const {
    return find(preferenciasGeneros.begin(), preferenciasGeneros.end(), genero) != preferenciasGeneros.end();
}

// Métodos para historial de calificaciones
void Usuario::agregarCalificacion(const string& titulo, int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) {
        if (!haCalificado(titulo)) {
            totalCalificaciones++;
        }
        historialCalificaciones[titulo] = calificacion;
    }
}

int Usuario::getCalificacion(const string& titulo) const {
    auto it = historialCalificaciones.find(titulo);
    return (it != historialCalificaciones.end()) ? it->second : 0;
}

bool Usuario::haCalificado(const string& titulo) const {
    return historialCalificaciones.find(titulo) != historialCalificaciones.end();
}

int Usuario::getTotalCalificaciones() const {
    return totalCalificaciones;
}

// Métodos de visualización
void Usuario::mostrarPerfil() const {
    cout << "\n=== PERFIL DE USUARIO ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Género favorito: " << generoFavorito << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "========================\n" << endl;
}

void Usuario::mostrarPreferencias() const {
    cout << "\n=== PREFERENCIAS DE GÉNEROS ===" << endl;
    if (preferenciasGeneros.empty()) {
        cout << "No tienes preferencias configuradas." << endl;
    } else {
        for (size_t i = 0; i < preferenciasGeneros.size(); ++i) {
            cout << (i + 1) << ". " << preferenciasGeneros[i] << endl;
        }
    }
    cout << "==============================\n" << endl;
}

void Usuario::mostrarHistorial() const {
    cout << "\n=== HISTORIAL DE CALIFICACIONES ===" << endl;
    if (historialCalificaciones.empty()) {
        cout << "No has calificado ningún contenido aún." << endl;
    } else {
        for (const auto& par : historialCalificaciones) {
            cout << "• " << par.first << " - " << par.second << "/5 estrellas" << endl;
        }
    }
    cout << "==================================\n" << endl;
}

// Calcular compatibilidad con un género (0-1)
double Usuario::calcularCompatibilidad(const string& genero) const {
    if (genero == generoFavorito) return 1.0;
    if (tienePreferencia(genero)) return 0.8;
    return 0.3; // Compatibilidad base
}