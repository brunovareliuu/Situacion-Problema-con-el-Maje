#ifndef CANCION_H
#define CANCION_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Cancion : public Entretenimiento {
private:
    string artista;

public:
    Cancion(string t, string g, int d, string art);
    void mostrarInfo() const override;
    string tipo() const override;
    string toFileString() const override;
    string getArtista() const;
};

#endif