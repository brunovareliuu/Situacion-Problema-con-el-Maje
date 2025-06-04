#include <iostream>
#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string genero;
public:
    Usuario(const string& nombre, const string& genero) : nombre(nombre), genero(genero) {}

    void setGenero(string genero);
    string getGenero();

    void setNombre(string nombre);
    string getNombre();
    
    void mostrarPerfil();
};