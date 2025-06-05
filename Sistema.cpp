#include "Sistema.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Sistema::Sistema() : usuarioActual(nullptr) {}

// Registro de usuario
bool Sistema::registrarUsuario(const string& nombre, const string& password, 
                              const string& genero, const string& formato, 
                              const string& duracion) {
    // Verificar si el usuario ya existe
    for (const auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            cout << "El usuario ya existe.\n";
            return false;
        }
    }
    usuarios.emplace_back(nombre, password, genero, formato, duracion);
    cout << "Bienvenido, te has registrado correctamente.\n";
    return true;
}

// Inicio de sesión
bool Sistema::iniciarSesion(const string& nombre, const string& password) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre && usuario.getPassword() == password) {
            usuarioActual = &usuario;
            cout << "Bienvenido, " << nombre << "!\n";
            return true;
        }
    }
    cout << "Error: Usuario o contraseña incorrectos.\n";
    return false;
}

// Cerrar sesión
void Sistema::cerrarSesion() {
    usuarioActual = nullptr;
    cout << "Sesión cerrada.\n";
}

// Getter del usuario actual
Usuario* Sistema::getUsuarioActual() const {
    return usuarioActual;
}

// Cargar usuarios desde archivo
void Sistema::cargarUsuarios(const string& archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string nombre, password, genero, formato, duracion;
        getline(ss, nombre, ',');
        getline(ss, password, ',');
        getline(ss, genero, ',');
        getline(ss, formato, ',');
        getline(ss, duracion, ',');
        usuarios.emplace_back(nombre, password, genero, formato, duracion);
    }
    file.close();
}

// Guardar usuarios en archivo
void Sistema::guardarUsuarios(const string& archivo) {
    ofstream file(archivo);
    if (!file.is_open()) {
        cout << "Error al guardar el archivo.\n";
        return;
    }

    for (const auto& usuario : usuarios) {
        file << usuario.getNombre() << ","
             << usuario.getPassword() << ","
             << usuario.getGeneroFavorito() << ","
             << usuario.getFormatoPreferido() << ","
             << usuario.getDuracionPreferida() << "\n";
    }
    file.close();
}

// Buscar usuario por nombre
Usuario* Sistema::buscarUsuario(const string& nombre) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            return &usuario;
        }
    }
    return nullptr;
}