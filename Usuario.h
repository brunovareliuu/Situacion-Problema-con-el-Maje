#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Usuario {
private:
    string nombre;
    string generoFavorito;
    vector<string> preferenciasGeneros;
    map<string, int> historialCalificaciones; // título -> calificación
    int totalCalificaciones;

public:
    // Constructores
    Usuario(const string& nombre, const string& genero);
    Usuario(const string& nombre, const string& genero, const vector<string>& preferencias);

    // Getters y Setters básicos
    void setGeneroFavorito(const string& genero);
    string getGeneroFavorito() const;
    void setNombre(const string& nombre);
    string getNombre() const;
    
    // Métodos para preferencias
    void agregarPreferencia(const string& genero);
    void eliminarPreferencia(const string& genero);
    vector<string> getPreferencias() const;
    bool tienePreferencia(const string& genero) const;
    
    // Métodos para historial de calificaciones
    void agregarCalificacion(const string& titulo, int calificacion);
    int getCalificacion(const string& titulo) const;
    bool haCalificado(const string& titulo) const;
    int getTotalCalificaciones() const;
    
    // Métodos de visualización
    void mostrarPerfil() const;
    void mostrarPreferencias() const;
    void mostrarHistorial() const;
    
    // Método para calcular compatibilidad con géneros
    double calcularCompatibilidad(const string& genero) const;
};

#endif