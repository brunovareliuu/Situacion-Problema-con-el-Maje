#ifndef PODCAST_H
#define PODCAST_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Podcast : public Entretenimiento {
private:
    string presentador;

public:
    Podcast(string t, string g, int d, string p);
    void mostrarInfo() const override;
    string tipo() const override;
    string toFileString() const override;
    string getPresentador() const;
};

#endif