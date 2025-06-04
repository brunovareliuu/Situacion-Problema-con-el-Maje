#ifndef SERIE_H
#define SERIE_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Serie : public Entretenimiento {
private:
    string creador;
    int temporadas;
    int episodiosTotales;
    string plataforma;
    bool enEmision;

public:
    // Constructor
    Serie(const string& titulo, const string& genero, int anio, 
          const string& creador, int temporadas, int episodiosTotales, 
          const string& plataforma, bool enEmision);

    // Implementación de métodos virtuales puros
    void mostrarInfo() const override;
    string getTipo() const override;
    
    // Override del método mostrarDetalles
    void mostrarDetalles() const override;

    // Getters específicos
    string getCreador() const { return creador; }
    int getTemporadas() const { return temporadas; }
    int getEpisodiosTotales() const { return episodiosTotales; }
    string getPlataforma() const { return plataforma; }
    bool getEnEmision() const { return enEmision; }
    
    // Setters específicos
    void setCreador(const string& creador) { this->creador = creador; }
    void setTemporadas(int temporadas) { this->temporadas = temporadas; }
    void setEpisodiosTotales(int episodiosTotales) { this->episodiosTotales = episodiosTotales; }
    void setPlataforma(const string& plataforma) { this->plataforma = plataforma; }
    void setEnEmision(bool enEmision) { this->enEmision = enEmision; }
    
    // Método para obtener estado de emisión
    string getEstadoEmision() const;
};

#endif 