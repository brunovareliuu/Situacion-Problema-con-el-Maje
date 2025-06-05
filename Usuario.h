#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <utility> // Para pair

using namespace std;

class Usuario {
private:
    string nombre;
    string password;
    string generoFavorito;  
    string formatoPreferido; 
    string duracionPreferida; 
    vector<pair<string, int>> calificaciones; // (nombreElemento, puntuación)

public:
    // Constructor
    Usuario(string nombre, string password, string genero, string formato, string duracion);

    // Getters (const para seguridad)
    string getNombre() const;
    string getPassword() const;
    string getGeneroFavorito() const;
    string getFormatoPreferido() const;
    string getDuracionPreferida() const;

    // Setters
    void setNombre(const string& nombre);
    void setPassword(const string& password);
    void setGeneroFavorito(const string& genero);
    void setFormatoPreferido(const string& formato);
    void setDuracionPreferida(const string& duracion);

    // Métodos para calificaciones, lo de pair para mostrar tambien el nombre del elemento
    void agregarCalificacion(const string& nombreElemento, int puntuacion);
    const vector<pair<string, int>>& getCalificaciones() const;

    // Mostrar preferencias
    void mostrarPreferencias() const;
};

#endif