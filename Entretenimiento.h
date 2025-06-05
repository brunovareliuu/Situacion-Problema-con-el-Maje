#ifndef ENTRETENIMIENTO_H
#define ENTRETENIMIENTO_H

#include <string>
#include <vector>
using namespace std;

class Entretenimiento {
protected:
    string titulo;
    string genero;
    int duracion;
    vector<int> calificaciones; //Lo hacemos vector para mas calificaciones

public:
    Entretenimiento(string t, string g, int d);

    void setTitulo(const string& t);
    void setGenero(const string& g);
    void setDuracion(int d);

    string getTitulo() const;
    string getGenero() const;
    int getDuracion() const;

    void agregarCalificacion(int calificacion);
    
    vector<int> getCalificaciones() const;
    
    float promedioCalificaciones() const;

    virtual void mostrarInfo() const = 0; // método puro: clase abstracta
    virtual string tipo() const = 0;
};

#endif