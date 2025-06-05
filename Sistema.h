#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"
#include <vector>
#include <string>

using namespace std;

class Sistema {
private:
    vector<Usuario> usuarios;
    Usuario* usuarioActual; // Puntero al usuario loggeado (y despues a nada si es que no hay usuario)

public:
    // Constructor
    Sistema();

    // Gestión de usuarios
    // El bool es para ver si es verdadero que se registro o que esta dentro del sistema
    // Si es falso, no se registro o no se loggeo
    bool registrarUsuario(const string& nombre, const string& password, const string& genero, 
                         const string& formato, const string& duracion);
    bool iniciarSesion(const string& nombre, const string& password);
    void cerrarSesion();
    // El pointer al usuario actual
    Usuario* getUsuarioActual() const;

    // Archivos para guardar y cargar usuarios
    void cargarUsuarios(const string& archivo);
    void guardarUsuarios(const string& archivo);

    // Búsqueda para calificaciones y preferencias del usuario
    Usuario* buscarUsuario(const string& nombre);
};

#endif