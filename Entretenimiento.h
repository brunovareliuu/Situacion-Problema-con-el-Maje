#ifndef ENTRETENIMIENTO_H
#define ENTRETENIMIENTO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Entretenimiento {
protected:
    string titulo;
    string genero;
    int anio;
    double calificacionPromedio;
    vector<int> calificaciones;
    int totalCalificaciones;

public:
    // Constructor
    Entretenimiento(const string& titulo, const string& genero, int anio);
    
    // Destructor virtual
    virtual ~Entretenimiento() {}
    
    // Métodos virtuales puros (clase abstracta)
    virtual void mostrarInfo() const = 0;
    virtual string getTipo() const = 0;
    
    // Métodos virtuales
    virtual void mostrarDetalles() const;
    
    // Getters
    string getTitulo() const { return titulo; }
    string getGenero() const { return genero; }
    int getAnio() const { return anio; }
    double getCalificacionPromedio() const { return calificacionPromedio; }
    int getTotalCalificaciones() const { return totalCalificaciones; }
    
    // Setters
    void setTitulo(const string& titulo) { this->titulo = titulo; }
    void setGenero(const string& genero) { this->genero = genero; }
    void setAnio(int anio) { this->anio = anio; }
    
    // Métodos para calificaciones
    void agregarCalificacion(int calificacion);
    void calcularCalificacionPromedio();
    
    // Método para validar calificación
    static bool validarCalificacion(int calificacion);
};

#endif
