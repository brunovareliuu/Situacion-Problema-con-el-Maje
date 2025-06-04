#ifndef PELICULA_H
#define PELICULA_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Pelicula : public Entretenimiento {
private:
    string director;
    string actorPrincipal;
    int duracionMinutos;
    string clasificacion; // G, PG, PG-13, R, NC-17

public:
    // Constructor
    Pelicula(const string& titulo, const string& genero, int anio, 
             const string& director, const string& actorPrincipal, 
             int duracionMinutos, const string& clasificacion);

    // Implementación de métodos virtuales puros
    void mostrarInfo() const override;
    string getTipo() const override;
    
    // Override del método mostrarDetalles
    void mostrarDetalles() const override;

    // Getters específicos
    string getDirector() const { return director; }
    string getActorPrincipal() const { return actorPrincipal; }
    int getDuracionMinutos() const { return duracionMinutos; }
    string getClasificacion() const { return clasificacion; }
    
    // Setters específicos
    void setDirector(const string& director) { this->director = director; }
    void setActorPrincipal(const string& actorPrincipal) { this->actorPrincipal = actorPrincipal; }
    void setDuracionMinutos(int duracionMinutos) { this->duracionMinutos = duracionMinutos; }
    void setClasificacion(const string& clasificacion) { this->clasificacion = clasificacion; }
    
    // Método para convertir minutos a formato horas:minutos
    string formatearDuracion() const;
};

#endif 