#ifndef SERIE_H
#define SERIE_H

#include "Entretenimiento.h"

class Serie : public Entretenimiento {
public:
    Serie(string t, string g, int d);

    void mostrarInfo() const override;
    string tipo() const override;
    string toFileString() const override;
};

#endif
