#ifndef PODCAST_H
#define PODCAST_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Podcast : public Entretenimiento {
private:
    string anfitrion;
    int duracionMinutos;
    int numeroEpisodio;
    string plataforma;
    bool esExplicito;

public:
    // Constructor
    Podcast(const string& titulo, const string& genero, int anio, 
            const string& anfitrion, int duracionMinutos, int numeroEpisodio, 
            const string& plataforma, bool esExplicito);

    // Implementación de métodos virtuales puros
    void mostrarInfo() const override;
    string getTipo() const override;
    
    // Override del método mostrarDetalles
    void mostrarDetalles() const override;

    // Getters específicos
    string getAnfitrion() const { return anfitrion; }
    int getDuracionMinutos() const { return duracionMinutos; }
    int getNumeroEpisodio() const { return numeroEpisodio; }
    string getPlataforma() const { return plataforma; }
    bool getEsExplicito() const { return esExplicito; }
    
    // Setters específicos
    void setAnfitrion(const string& anfitrion) { this->anfitrion = anfitrion; }
    void setDuracionMinutos(int duracionMinutos) { this->duracionMinutos = duracionMinutos; }
    void setNumeroEpisodio(int numeroEpisodio) { this->numeroEpisodio = numeroEpisodio; }
    void setPlataforma(const string& plataforma) { this->plataforma = plataforma; }
    void setEsExplicito(bool esExplicito) { this->esExplicito = esExplicito; }
    
    // Métodos auxiliares
    string formatearDuracion() const;
    string getClasificacion() const;
};

#endif 