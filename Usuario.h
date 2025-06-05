#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <utility> // Para pair

using namespace std;

// Enum para géneros que si existe y tenerlos bien seccionados
enum class Genero {
    TERROR,
    ACCION,
    ROMANCE,
    PSICOLOGIA,
    DIVERSION
};

// Enum para niveles de duración, para no tener que usar ints y que sea mas robusto el codigo
enum class Duracion {
    CORTA,    
    MEDIANA,  
    LARGA     
};

class Usuario {
private:
    string nombre;
    string password;
    // El genero y duracion no son strings, porque son parte de un enum ahora
    Genero generoFavorito;
    string formatoPreferido; // pelicula, lbro, etc.
    Duracion duracionPreferida; //string debido a que hicimos el enum para ello
    vector<pair<string, int>> calificaciones; // (nombreElemento osea el titulo del formato, puntuación)

public:
    // Constructor
    Usuario(string nombre, string password, Genero genero, string formato, Duracion duracion);

    // Getters
    string getNombre() const;
    string getPassword() const;
    Genero getGeneroFavorito() const;
    string getFormatoPreferido() const;
    Duracion getDuracionPreferida() const;

    // Setters
    void setNombre(const string& nombre);
    void setPassword(const string& password);
    void setGeneroFavorito(Genero genero);
    void setFormatoPreferido(const string& formato);
    void setDuracionPreferida(Duracion duracion);

    // Métodos para calificaciones
    // Esto mas que nada para que sea la calificacion con el elemento y asi como (Titanic, 5)
    void agregarCalificacion(const string& nombreElemento, int puntuacion);
    const vector<pair<string, int>>& getCalificaciones() const;

    // Mostrar preferencias
    void mostrarPreferencias() const;

    // Métodos estáticos para conversión de enums a strings y viceversa
    static string generoToString(Genero genero);
    
    static string duracionToString(Duracion duracion);
};

#endif