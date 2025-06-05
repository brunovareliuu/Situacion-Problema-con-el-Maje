#ifndef PELICULA_H
#define PELICULA_H
#include "Entretenimiento.h"
#include <string>
#include <vector>
using namespace std;

class Pelicula : public Entretenimiento {
public:
    Pelicula(string t, string g, int d);

    void mostrarInfo() const override;
    string tipo() const override;
};

#endif
