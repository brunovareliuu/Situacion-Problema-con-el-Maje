#ifndef LIBRO_H
#define LIBRO_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Libro : public Entretenimiento {
private:
    string autor;

public:
    Libro(string t, string g, int d, string a);
    void mostrarInfo() const override;
    string tipo() const override;
};

#endif