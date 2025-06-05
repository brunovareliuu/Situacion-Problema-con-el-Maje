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
    int fecha;
    vector<int> calificaciones; //Lo hacemos vector para mas calificaciones

public:
    Entretenimiento(string t, string g, int d, int f = 0);

    void setTitulo(const string t);
    void setGenero(const string g);
    void setDuracion(int d);
    void setFecha(int f);

    string getTitulo() const;
    string getGenero() const;
    int getDuracion() const;
    int getFecha() const;

    void agregarCalificacion(int calificacion);
    
    vector<int> getCalificaciones() const;
    
    float promedioCalificaciones() const;

    // Nuevos métodos para archivos
    virtual string toFileString() const = 0;
    static Entretenimiento* fromFileString(const string& linea, const string& tipo);

    virtual void mostrarInfo() const = 0; // método puro: clase abstracta
    virtual string tipo() const = 0;
};

#endif