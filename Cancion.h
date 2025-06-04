#ifndef CANCION_H
#define CANCION_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Cancion : public Entretenimiento {
private:
    string artista;
    string album;
    int duracionSegundos;
    string discografia;
    bool esSimple;

public:
    // Constructor
    Cancion(const string& titulo, const string& genero, int anio, 
            const string& artista, const string& album, int duracionSegundos, 
            const string& discografia, bool esSimple);

    // Implementación de métodos virtuales puros
    void mostrarInfo() const override;
    string getTipo() const override;
    
    // Override del método mostrarDetalles
    void mostrarDetalles() const override;

    // Getters específicos
    string getArtista() const { return artista; }
    string getAlbum() const { return album; }
    int getDuracionSegundos() const { return duracionSegundos; }
    string getDiscografia() const { return discografia; }
    bool getEsSimple() const { return esSimple; }
    
    // Setters específicos
    void setArtista(const string& artista) { this->artista = artista; }
    void setAlbum(const string& album) { this->album = album; }
    void setDuracionSegundos(int duracionSegundos) { this->duracionSegundos = duracionSegundos; }
    void setDiscografia(const string& discografia) { this->discografia = discografia; }
    void setEsSimple(bool esSimple) { this->esSimple = esSimple; }
    
    // Métodos auxiliares
    string formatearDuracion() const;
    string getTipoCancion() const;
};

#endif 