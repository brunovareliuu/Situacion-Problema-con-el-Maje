#include "Usuario.h"
#include <iostream>
#include <algorithm> // Para transform()

using namespace std;

// Constructor
Usuario::Usuario(string nombre, string password, string genero, string formato, string duracion)
    : nombre(nombre), password(password), generoFavorito(genero),
      formatoPreferido(formato), duracionPreferida(duracion) {}

// Getters
string Usuario::getNombre() const { return nombre; }
string Usuario::getPassword() const { return password; }
string Usuario::getGeneroFavorito() const { return generoFavorito; }
string Usuario::getFormatoPreferido() const { return formatoPreferido; }
string Usuario::getDuracionPreferida() const { return duracionPreferida; }

// Setters
void Usuario::setNombre(const string& nombre) { this->nombre = nombre; }
void Usuario::setPassword(const string& password) { this->password = password; }
void Usuario::setGeneroFavorito(const string& genero) { generoFavorito = genero; }
void Usuario::setFormatoPreferido(const string& formato) { formatoPreferido = formato; }
void Usuario::setDuracionPreferida(const string& duracion) { duracionPreferida = duracion; }

// Agregar calificación con validación básica
void Usuario::agregarCalificacion(const string& nombreElemento, int puntuacion) {
    if (puntuacion < 1 || puntuacion > 5) {
        cout << "La calificación debe ser entre 1 y 5.";
        return;
    }
    calificaciones.emplace_back(nombreElemento, puntuacion);
}

// Getter de calificaciones con el pair
const vector<pair<string, int>>& Usuario::getCalificaciones() const {
    return calificaciones;
}

// Mostrar preferencias
void Usuario::mostrarPreferencias() const {
    cout << "Preferencias de " << nombre << endl;
    cout << "Género favorito: " << generoFavorito << endl;
    cout << "Formato preferido: " << formatoPreferido << endl;
    cout << "Duración preferida: " << duracionPreferida << endl;

    // Mostrar calificaciones que ha dado el usuario
    cout << "Tus Calificaciones" << endl;
    if (!calificaciones.empty()) {
        cout << "\nCalificaciones:" << endl;
        for (const auto& [elemento, puntuacion] : calificaciones) {
            cout << "- " << elemento << ": " << puntuacion << "/5" << endl;
        }
    } else {
        cout << "\nAún no has calificado ningun elemento." << endl;
    }
}