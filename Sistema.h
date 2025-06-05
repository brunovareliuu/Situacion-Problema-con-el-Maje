#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"
#include "Entretenimiento.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Sistema {
private:
    vector<Usuario> usuarios;
    vector<Entretenimiento*> elementos;
    Usuario* usuarioActual;

public:
    // Constructor y Destructor
    Sistema();
    ~Sistema();
    
    // Gestión de usuarios
    bool registrarUsuario(const string& nombre, const string& password, 
                         const string& genero, const string& formato, 
                         const string& duracion);
    bool iniciarSesion(const string& nombre, const string& password);
    void cerrarSesion();
    Usuario* getUsuarioActual() const;
    Usuario* buscarUsuario(const string& nombre);

    // Gestión de archivos para usuarios
    void cargarUsuarios(const string& archivo);
    void guardarUsuarios(const string& archivo);

    // Gestión de archivos para entretenimiento
    void cargarDatosDesdeArchivos();
    void guardarDatosEnArchivos();
    void cargarElementos(const string& nombreArchivo, const string& tipo);
    void guardarElementosPorTipo(const string& nombreArchivo, const string& tipo);

    // Gestión de entretenimiento
    void agregarElemento(Entretenimiento* elemento);
    vector<Entretenimiento*> getElementos() const;
    void mostrarElementos() const;
    Entretenimiento* buscarElemento(const string& titulo) const;

    // Gestión de calificaciones
    bool actualizarCalificacion(const string& usuario, const string& elemento, 
                               int nuevaCalif);
    void mostrarRecomendaciones() const;
    void mostrarTop10(const string& tipo = "") const;
};

#endif