#include "Usuario.h"
#include <iostream>
#include <stdexcept>  // Para excepciones
#include <algorithm>  // Para transformar cadenas a minúsculas

using namespace std;

// Constructor 
Usuario::Usuario(string nombre, string password, Genero genero, string formato, Duracion duracion)
    : nombre(nombre), password(password), generoFavorito(genero),
      formatoPreferido(formato), duracionPreferida(duracion) {
}

// Getters
string Usuario::getNombre() const { return nombre; }
string Usuario::getPassword() const { return password; }
Genero Usuario::getGeneroFavorito() const { return generoFavorito; }
string Usuario::getFormatoPreferido() const { return formatoPreferido; }
Duracion Usuario::getDuracionPreferida() const { return duracionPreferida; }

// Setters
void Usuario::setNombre(const string& nombre) { this->nombre = nombre; }
void Usuario::setPassword(const string& password) { this->password = password; }
void Usuario::setGeneroFavorito(Genero genero) { generoFavorito = genero; }
void Usuario::setFormatoPreferido(const string& formato) { formatoPreferido = formato; }
void Usuario::setDuracionPreferida(Duracion duracion) { duracionPreferida = duracion; }

// Método para agregar calificaciones con el nombre del elemento
void Usuario::agregarCalificacion(const string& nombreElemento, int puntuacion) {
    // Validar rango
    if (puntuacion < 1 || puntuacion > 5) {
        cout << "La calificación debe estar entre 1 y 5" << endl;
    }

    // Agregar la nueva calificación
    calificaciones.emplace_back(nombreElemento, puntuacion);
}

// Getter para obtener todas las calificaciones
const vector<pair<string, int>>& Usuario::getCalificaciones() const {
    return calificaciones;
}

// Método para mostrar las preferencias del usuario
void Usuario::mostrarPreferencias() const {
    cout << "Preferencias de " << nombre << endl;
    cout << "Género favorito: " << generoToString(generoFavorito) << endl;
    cout << "Formato preferido: " << formatoPreferido << endl;
    cout << "Duración preferida: " << duracionToString(duracionPreferida) << endl;
    
    // Mostrar la calificacion abajo pero asegurarnos que esta calificada
    if (!calificaciones.empty()) {
        cout << "\nCalificaciones:" << endl;
        for (const auto& [elemento, puntuacion] : calificaciones) {
            cout << "( " << elemento << ": " << puntuacion << "/5 )" << endl;
        }
    } else {
        cout << "Aún no has calificado nada" << endl;
    }
}

// Conversión de Genero a string
string Usuario::generoToString(Genero genero) {
    switch (genero) {
        case Genero::TERROR:     return "Terror";
        case Genero::ACCION:     return "Acción";
        case Genero::ROMANCE:    return "Romance";
        case Genero::PSICOLOGIA: return "Psicología";
        case Genero::DIVERSION:  return "Diversión";
        default:                 return "No Asignado";
    }
}

// Conversión de Duracion a string
string Usuario::duracionToString(Duracion duracion) {
    switch (duracion) {
        case Duracion::CORTA:   return "Corta (< 30 min)";
        case Duracion::MEDIANA: return "Mediana (30-90 min)";
        case Duracion::LARGA:   return "Larga (> 90 min)";
        default:                return "Duración desconocida";
    }
}